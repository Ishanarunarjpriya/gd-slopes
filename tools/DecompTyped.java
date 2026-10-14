import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.Function.FunctionUpdateType;
import java.io.*;
import java.nio.file.*;
import java.util.*;
public class DecompTyped extends GhidraScript {
  DataTypeManager dtm;
  StructureDataType ccpoint, ccrect;
  Structure goS, poS, glS;
  DataType resolveField(String t, int size) {
    if (t.equals("double")) return DoubleDataType.dataType;
    if (t.equals("float")) return FloatDataType.dataType;
    if (t.equals("int") || t.endsWith("Type") || t.equals("ZLayer") || t.equals("GhostType") || t.equals("ShipStreak") || t.equals("PlayerButton")) return size==4 ? IntegerDataType.dataType : new ArrayDataType(ByteDataType.dataType,size,1);
    if (t.equals("unsigned int")) return UnsignedIntegerDataType.dataType;
    if (t.equals("short")) return ShortDataType.dataType;
    if (t.equals("bool")) return BooleanDataType.dataType;
    if (t.equals("uint8_t") || t.equals("unsigned char")) return ByteDataType.dataType;
    if (t.equals("cocos2d::CCPoint")) return ccpoint;
    if (t.equals("GameObject*")) return new PointerDataType(goS);
    if (t.equals("PlayerObject*")) return new PointerDataType(poS);
    if (t.endsWith("*")) return PointerDataType.dataType;
    return new ArrayDataType(ByteDataType.dataType,size,1);
  }
  void fill(Structure st, String file) throws Exception {
    for (String l : Files.readAllLines(Paths.get(file))) {
      String[] p = l.split(" ");
      int off = Integer.decode(p[0]); int size = Integer.parseInt(p[1]);
      String name = p[p.length-1];
      String type = String.join(" ", Arrays.copyOfRange(p,2,p.length-1));
      if (off + size > st.getLength()) continue;
      DataType dt = resolveField(type,size);
      if (dt.getLength() != size) dt = new ArrayDataType(ByteDataType.dataType,size,1);
      try { st.replaceAtOffset(off, dt, size, name, type); } catch (Exception e) { println("skip "+name+" "+e); }
    }
  }
  DataType argType(String t) {
    t = t.trim().replace("virtual ","").replace("&","*");
    if (t.equals("float")) return FloatDataType.dataType;
    if (t.equals("double")) return DoubleDataType.dataType;
    if (t.equals("bool")) return BooleanDataType.dataType;
    if (t.equals("int")) return IntegerDataType.dataType;
    if (t.equals("cocos2d::CCRect")) return ccrect;
    if (t.equals("cocos2d::CCPoint")) return ccpoint;
    if (t.equals("GameObject*")) return new PointerDataType(goS);
    if (t.equals("PlayerObject*")) return new PointerDataType(poS);
    if (t.endsWith("*")) return PointerDataType.dataType;
    if (t.equals("void")) return VoidDataType.dataType;
    return IntegerDataType.dataType;
  }
  public void run() throws Exception {
    String[] a = getScriptArgs();
    String dir = a[0];
    dtm = currentProgram.getDataTypeManager();
    long base = currentProgram.getImageBase().getOffset();
    ccpoint = new StructureDataType("CCPoint",0); ccpoint.add(FloatDataType.dataType,"x",null); ccpoint.add(FloatDataType.dataType,"y",null);
    ccrect = new StructureDataType("CCRect",0); ccrect.add(ccpoint,"origin",null); ccrect.add(FloatDataType.dataType,"width",null); ccrect.add(FloatDataType.dataType,"height",null);
    StructureDataType go = new StructureDataType("GameObject",0x548);
    StructureDataType po = new StructureDataType("PlayerObject",0xbe8);
    StructureDataType gl = new StructureDataType("GJBaseGameLayer",0x10);
    int tx = currentProgram.startTransaction("types");
    goS = (Structure) dtm.addDataType(go, DataTypeConflictHandler.REPLACE_HANDLER);
    poS = (Structure) dtm.addDataType(po, DataTypeConflictHandler.REPLACE_HANDLER);
    glS = (Structure) dtm.addDataType(gl, DataTypeConflictHandler.REPLACE_HANDLER);
    goS.replaceAtOffset(0, PointerDataType.dataType, 8, "vtable", null);
    fill(goS, dir+"/go_layout.txt");
    poS.replaceAtOffset(0, goS, 0x548, "GameObject", "base");
    fill(poS, dir+"/po_layout.txt");
    Map<Long,String> names = new HashMap<>();
    for (String l : Files.readAllLines(Paths.get(dir+"/names.txt"))) {
      String[] p = l.split(" ",2);
      long off = Long.decode(p[0]);
      names.put(off,p[1]);
      try { createLabel(toAddr(base+off), p[1].replace("::","__"), true, SourceType.USER_DEFINED); } catch(Exception e){}
    }
    List<Function> fns = new ArrayList<>();
    for (String l : Files.readAllLines(Paths.get(dir+"/targets.txt"))) {
      String[] p = l.split("\\|",-1);
      long off = Long.decode(p[0]);
      Address ad = toAddr(base+off);
      disassemble(ad);
      Function f = getFunctionAt(ad);
      if (f == null) f = createFunction(ad, p[1]+"__"+p[3]);
      if (f == null) { println("no func "+p[0]); continue; }
      try { f.setName(p[1]+"::"+p[3], SourceType.USER_DEFINED); } catch (Exception e) {}
      List<Variable> params = new ArrayList<>();
      DataType thisT = p[1].equals("PlayerObject") ? new PointerDataType(poS) : p[1].equals("GameObject") ? new PointerDataType(goS) : new PointerDataType(glS);
      if (!p[5].equals("1")) params.add(new ParameterImpl("this", thisT, currentProgram));
      if (!p[4].isEmpty()) {
        int depth=0; StringBuilder cur=new StringBuilder(); List<String> parts=new ArrayList<>();
        for (char c : p[4].toCharArray()) { if (c=='<') depth++; if (c=='>') depth--; if (c==',' && depth==0) { parts.add(cur.toString()); cur=new StringBuilder(); } else cur.append(c); }
        parts.add(cur.toString());
        for (String part : parts) {
          part = part.trim(); int sp = part.lastIndexOf(' ');
          String t = part.substring(0,sp).trim(), n = part.substring(sp+1).trim();
          if (n.startsWith("*")) { t += "*"; n = n.substring(1); }
          params.add(new ParameterImpl(n, argType(t), currentProgram));
        }
      }
      f.replaceParameters(FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS, true, SourceType.USER_DEFINED, params.toArray(new Variable[0]));
      f.setReturnType(argType(p[2]), SourceType.USER_DEFINED);
      fns.add(f);
    }
    currentProgram.endTransaction(tx, true);
    DecompInterface di = new DecompInterface();
    DecompileOptions opts = new DecompileOptions();
    di.setOptions(opts);
    di.openProgram(currentProgram);
    PrintWriter w = new PrintWriter(new FileWriter(a[1]));
    for (Function f : fns) {
      DecompileResults r = di.decompileFunction(f, 300, monitor);
      w.println("// ==== " + f.getName() + " @ 0x" + Long.toHexString(f.getEntryPoint().getOffset()-base));
      w.println(r.getDecompiledFunction()==null ? "// FAILED: "+r.getErrorMessage() : r.getDecompiledFunction().getC());
    }
    w.close();
  }
}

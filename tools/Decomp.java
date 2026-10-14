import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.util.*;
public class Decomp extends GhidraScript {
  public void run() throws Exception {
    String[] a = getScriptArgs();
    long base = currentProgram.getImageBase().getOffset();
    Map<Long,String> names = new HashMap<>();
    for (String l : java.nio.file.Files.readAllLines(new File(a[0]).toPath())) {
      String[] p = l.split(" ",2);
      long off = Long.decode(p[0]);
      names.put(off, p[1]);
      Address ad = toAddr(base+off);
      try { createLabel(ad, p[1].replace("::","__"), true, SourceType.USER_DEFINED); } catch(Exception e){}
    }
    DecompInterface di = new DecompInterface();
    di.openProgram(currentProgram);
    PrintWriter w = new PrintWriter(new FileWriter(a[2]));
    for (String t : a[1].split(",")) {
      long off = Long.decode(t);
      Address ad = toAddr(base+off);
      disassemble(ad);
      Function f = getFunctionAt(ad);
      if (f == null) f = createFunction(ad, names.getOrDefault(off,"f_"+t).replace("::","__"));
      if (f == null) { w.println("// no func "+t); continue; }
      DecompileResults r = di.decompileFunction(f, 120, monitor);
      w.println("// ==== "+t+" "+names.get(off));
      w.println(r.getDecompiledFunction()==null ? r.getErrorMessage() : r.getDecompiledFunction().getC());
    }
    w.close();
  }
}

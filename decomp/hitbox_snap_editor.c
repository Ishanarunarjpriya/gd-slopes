// ==== GameObject::getObjectRectPointer @ 0x4eca68

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

undefined * GameObject__getObjectRectPointer(GameObject *this)

{
  if (this->m_isObjectRectDirty == true) {
    getObjectRect/*virtual+0x520*/(this);
  }
  return this->m_objectRect;
}


// ==== GameObject::getObjectRect @ 0x4ecaa4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

undefined * GameObject__getObjectRect(GameObject *this)

{
  undefined *puVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001004ecab4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  puVar1 = (undefined *)
           virtual_0x530(this->m_spriteWidthScale,this->m_spriteHeightScale);
  return puVar1;
}


// ==== GameObject::getObjectRect @ 0x4ecab8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

CCRect GameObject__getObjectRect(GameObject *this,float width,float height)

{
  undefined8 uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  CCRect CVar5;
  undefined1 auStack_40 [8];
  float fStack_38;
  float fStack_34;
  undefined1 auStack_30 [8];
  undefined8 uStack_28;
  
  fVar2 = this->m_scaleX;
  if (this->m_isMirroredByScale == true) {
    fVar2 = ABS(fVar2);
    fVar3 = this->m_height;
    fVar4 = ABS(this->m_scaleY);
  }
  else {
    fVar3 = this->m_height;
    fVar4 = this->m_scaleY;
  }
  func_0x00010022d8ac(this->m_width * fVar2,fVar3 * fVar4,&uStack_28);
  uStack_28 = CONCAT44((float)((ulong)uStack_28 >> 0x20) * height,(float)uStack_28 * width);
  uVar1 = GameObject__getBoxOffset(this);
  CCPoint__CCPoint_copy(auStack_30,uVar1);
  if (this->m_isRotationAligned == true) {
    uStack_28 = NEON_rev64(uStack_28,4);
  }
  getRealPosition/*virtual+0x540*/(auStack_40,this);
  CCPoint__operator_plus(&fStack_38,auStack_40,auStack_30);
  fVar2 = fStack_34 - uStack_28._4_4_ * 0.5;
  CVar5.origin.x = (float)CCRect__CCRect(fStack_38 - (float)uStack_28 * 0.5);
  CVar5.origin.y = fVar2;
  CVar5.height = uStack_28._4_4_;
  CVar5.width = (float)uStack_28;
  return CVar5;
}


// ==== GameObject::getObjectRect2 @ 0x4ecca0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

undefined * GameObject__getObjectRect2(GameObject *this,float width,float height)

{
  undefined1 auStack_30 [16];
  
  if (this->m_isObjectRectDirty == true) {
    this->m_isObjectRectDirty = false;
    if (this->m_shouldUseOuterOb == true) {
      if (this->m_isOrientedBoxDirty == true) {
        width = (float)virtual_0x610(this);
      }
      OBB2D__getBoundingRect(auStack_30,width,*(undefined8 *)this->m_orientedBox);
    }
    else {
      virtual_0x528(auStack_30,this);
    }
    CCRect__operator_assign(this->m_objectRect,auStack_30);
  }
  return this->m_objectRect;
}


// ==== GameObject::getObjectRectDirty @ 0x1a1e3c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

bool GameObject__getObjectRectDirty(GameObject *this)

{
  return this->m_isObjectRectDirty;
}


// ==== GameObject::setObjectRectDirty @ 0x1a1e44

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void GameObject__setObjectRectDirty(GameObject *this,bool dirty)

{
  this->m_isObjectRectDirty = dirty;
  return;
}


// ==== GameObject::getOrientedBox @ 0x4f8dc0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

undefined * GameObject__getOrientedBox(GameObject *this)

{
  undefined *puVar1;
  
  puVar1 = *(undefined **)this->m_orientedBox;
  if ((puVar1 == (undefined *)0x0) || (this->m_isOrientedBoxDirty == true)) {
    this->m_shouldUseOuterOb = true;
    virtual_0x610();
    getObjectRect/*virtual+0x520*/(this);
    puVar1 = *(undefined **)this->m_orientedBox;
  }
  return puVar1;
}


// ==== GameObject::calculateOrientedBox @ 0x4f8e1c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void GameObject__calculateOrientedBox(GameObject *this)

{
  this->m_shouldUseOuterOb = true;
  virtual_0x610();
                    /* WARNING: Could not recover jumptable at 0x0001004f8e54. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  getObjectRect/*virtual+0x520*/(this);
  return;
}


// ==== GameObject::updateOrientedBox @ 0x4f8e58

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void GameObject__updateOrientedBox(GameObject *this)

{
  undefined8 uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  undefined1 auStack_40 [8];
  undefined1 auStack_38 [8];
  
  if (*(long *)this->m_orientedBox != 0) {
    if (this->m_isOrientedBoxDirty == true) {
      getRealPosition/*virtual+0x540*/(auStack_40);
      uVar1 = GameObject__getBoxOffset(this);
      CCPoint__operator_plus(auStack_38,auStack_40,uVar1);
      uVar1 = *(undefined8 *)this->m_orientedBox;
      CCPoint__CCPoint_copy(auStack_40,auStack_38);
      fVar2 = this->m_width;
      fVar5 = this->m_spriteWidthScale;
      fVar6 = this->m_scaleX;
      fVar3 = this->m_height;
      fVar7 = this->m_spriteHeightScale;
      fVar8 = this->m_scaleY;
      fVar4 = (float)virtual_0x618(this);
      OBB2D__calculateWithCenter(fVar2 * fVar5 * fVar6,fVar3 * fVar7 * fVar8,fVar4 * -0.017453292,uVar1,
                          auStack_40);
      this->m_isOrientedBoxDirty = false;
    }
    return;
  }
  getRealPosition/*virtual+0x540*/(auStack_40);
  uVar1 = GameObject__getBoxOffset(this);
  CCPoint__operator_plus(auStack_38,auStack_40,uVar1);
  CCPoint__CCPoint_copy(auStack_40,auStack_38);
  fVar2 = this->m_width;
  fVar5 = this->m_spriteWidthScale;
  fVar6 = this->m_scaleX;
  fVar3 = this->m_height;
  fVar7 = this->m_spriteHeightScale;
  fVar8 = this->m_scaleY;
  fVar4 = (float)virtual_0x618(this);
  uVar1 = OBB2D__create(fVar2 * fVar5 * fVar6,fVar3 * fVar7 * fVar8,fVar4 * -0.017453292,
                              auStack_40);
  *(undefined8 *)this->m_orientedBox = uVar1;
  CCObject__retain();
  return;
}


// ==== PlayerObject::checkSnapJumpToObject @ 0x382fbc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PlayerObject__checkSnapJumpToObject(PlayerObject *this,GameObject *object)

{
  float fVar1;
  int iVar2;
  long *plVar3;
  float *pfVar4;
  long lVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  double dVar9;
  double dVar10;
  float fVar11;
  double dVar12;
  undefined1 auStack_48 [8];
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  
  if (object == (GameObject *)0x0) {
    return;
  }
  plVar3 = *(long **)this->m_objectSnappedTo;
  if (((plVar3 == (long *)0x0) || (*(int *)((long)plVar3 + 0x394) == object->m_uniqueID)) ||
     (iVar2 = (**(code **)(*plVar3 + 0x6f8))(), iVar2 != 0)) goto LAB_1003832d8;
  (**(code **)(**(long **)this->m_objectSnappedTo + 0x540))(&fStack_38);
  getRealPosition/*virtual+0x540*/(&fStack_40,object);
  fVar7 = this->m_playerSpeed;
  if (fVar7 == 0.9) {
    fVar11 = 1.0;
    fVar7 = 120.0;
    fVar6 = 150.0;
    fVar8 = 90.0;
    if (this->m_vehicleSize != 1.0) {
      fVar7 = 90.0;
    }
    fVar1 = 90.0;
    if (1.0 < ABS(fStack_40 - (fVar7 + fStack_38))) goto LAB_1003831c0;
LAB_100383190:
    fVar8 = fVar1;
    fVar7 = -1.0;
    if (this->m_isUpsideDown == false) {
      fVar7 = 1.0;
    }
    if (fVar11 < ABS(fStack_3c - (fStack_34 + fVar7 * 30.0))) goto LAB_1003831c0;
  }
  else {
    fVar11 = 1.0;
    if (fVar7 == 0.7) {
      fVar7 = 90.0;
      fVar8 = 60.0;
      fVar6 = 120.0;
      fVar11 = 1.0;
    }
    else if (fVar7 == 1.1) {
      fVar11 = 2.0;
      if (this->m_vehicleSize == 1.0) {
        fVar7 = 150.0;
      }
      else {
        fVar7 = 90.0;
      }
      fVar8 = 120.0;
      fVar6 = 195.0;
    }
    else if (fVar7 == 1.3) {
      fVar11 = 2.0;
      if (this->m_vehicleSize == 1.0) {
        fVar7 = 180.0;
      }
      else {
        fVar7 = 90.0;
      }
      fVar8 = 135.0;
      fVar6 = 225.0;
    }
    else {
      fVar7 = 120.0;
      fVar8 = 90.0;
      fVar6 = 150.0;
    }
    fVar1 = fVar8;
    if (ABS(fStack_40 - (fVar7 + fStack_38)) <= fVar11) goto LAB_100383190;
LAB_1003831c0:
    if (ABS(fStack_40 - (fVar6 + fStack_38)) <= fVar11) {
      fVar7 = -1.0;
      if (this->m_isUpsideDown == false) {
        fVar7 = 1.0;
      }
      if (ABS(fStack_3c - (fStack_34 + fVar7 * -30.0)) <= fVar11) goto LAB_100383244;
    }
    if (fVar11 < ABS(fStack_40 - (fVar8 + fStack_38))) goto LAB_1003832d8;
    fVar7 = -1.0;
    if (this->m_isUpsideDown == false) {
      fVar7 = 1.0;
    }
    if (fVar11 < ABS(fStack_3c - (fStack_34 + fVar7 * 60.0))) goto LAB_1003832d8;
  }
LAB_100383244:
  pfVar4 = (float *)getPosition/*virtual+0xc0*/(object);
  dVar12 = this->m_snapDistance + (double)*pfVar4;
  pfVar4 = (float *)getPosition/*virtual+0xc0*/(this);
  dVar9 = (double)*pfVar4;
  dVar10 = (double)fVar11;
  if (dVar10 < ABS(dVar12 - dVar9)) {
    if (dVar12 <= dVar9) {
      dVar12 = dVar9 - dVar10;
    }
    else {
      dVar12 = dVar10 + dVar9;
    }
  }
  lVar5 = getPosition/*virtual+0xc0*/(this);
  CCPoint__CCPoint((float)dVar12,*(undefined4 *)(lVar5 + 4),auStack_48);
  setPosition/*virtual+0xb8*/(this,auStack_48);
LAB_1003832d8:
  *(GameObject **)this->m_objectSnappedTo = object;
  pfVar4 = (float *)getPosition/*virtual+0xc0*/(this);
  fVar7 = *pfVar4;
  pfVar4 = (float *)getPosition/*virtual+0xc0*/(object);
  this->m_snapDistance = (double)(fVar7 - *pfVar4);
  return;
}


// ==== LevelEditorLayer::rotationForSlopeNearObject @ 0xc65fc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float LevelEditorLayer__rotationForSlopeNearObject(GJBaseGameLayer *this,GameObject *object)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  GameObject *this_00;
  uint uVar5;
  float fVar6;
  undefined1 auStack_60 [16];
  undefined1 auStack_50 [16];
  
  GameObject__updateStartPos(object);
  virtual_0x528(auStack_50,0x3f800000,0x3f800000,object);
  CCRect__CCRect_copy(auStack_60,auStack_50);
  uVar4 = LevelEditorLayer__objectsInRect(this,auStack_60,1);
  iVar2 = CCArray__count();
  if (iVar2 != 0) {
    uVar5 = 0;
    do {
      this_00 = (GameObject *)CCArray__objectAtIndex(uVar4,uVar5);
      iVar2 = virtual_0x6f8();
      if (iVar2 == 0x19) {
        GameObject__determineSlopeDirection(this_00);
        fVar6 = GameObject__getSlopeAngle(this_00);
        uVar5 = -(int)(fVar6 * 57.29578);
        if (this_00->m_slopeUphill == false) {
          uVar5 = (int)(fVar6 * 57.29578);
        }
        bVar1 = GameObject__slopeFloorTop(this_00);
        if (((bVar1) && (iVar2 = virtual_0x588(object), iVar2 == 0)) ||
           ((bVar1 = GameObject__slopeFloorTop(this_00), !bVar1 &&
            (iVar2 = virtual_0x588(object), iVar2 != 0)))) {
          if ((int)uVar5 < 1) {
            uVar5 = ((0xb4 - uVar5) / 0x168) * 0x168 - (0xb4 - uVar5);
          }
          else {
            uVar5 = (uVar5 + 0xb4) % 0x168;
          }
        }
        return (float)(int)uVar5;
      }
      uVar5 = uVar5 + 1;
      uVar3 = CCArray__count(uVar4);
    } while (uVar5 < uVar3);
  }
  return -1.0;
}



// ==== PlayerObject::collidedWithSlope @ 0x37dd60

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PlayerObject__collidedWithSlope(PlayerObject *this,float dt,GameObject *object,bool skipPre)

{
  int iVar1;
  float *pfVar2;
  bool bVar3;
  byte bVar4;
  ulong uVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  int iVar11;
  uint uVar12;
  undefined8 uVar13;
  long lVar14;
  undefined4 *puVar15;
  char cVar16;
  byte bVar17;
  byte bVar18;
  ulong uVar19;
  ulong uVar20;
  ulong uVar21;
  long *plVar22;
  ulong uVar23;
  bool bVar24;
  byte bVar25;
  byte bVar26;
  byte bVar27;
  undefined2 uVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  float fVar32;
  float fVar33;
  float fVar34;
  double dVar35;
  double dVar36;
  double dVar37;
  undefined8 in_d1;
  double dVar38;
  undefined8 in_d2;
  double dVar39;
  undefined4 in_s3;
  undefined4 in_s4;
  float fVar40;
  float fVar41;
  float fVar42;
  CCRect rect;
  float fStack_100;
  float fStack_fc;
  float fStack_f8;
  float fStack_f4;
  float fStack_f0;
  float fStack_ec;
  float *apfStack_e8 [2];
  float fStack_d8;
  float fStack_d4;
  float fStack_d0;
  float fStack_cc;
  undefined4 uStack_c8;
  float fStack_c4;
  float fStack_c0;
  float fStack_bc;
  float fStack_b8;
  float fStack_b4;
  float fStack_b0;
  float fStack_ac;
  
  if (this->m_isSideways == true) {
    CCRect__CCRect_copy(&stack0xffffffffffffffb0,0x1008b88b0);
    rect.origin.x = (float)in_d1;
    rect.origin.y = (float)in_d2;
    rect.height = (float)in_s4;
    rect.width = (float)in_s3;
    PlayerObject__handleRotatedCollisionInternal
              (this,dt,object,rect,SUB81(&stack0xffffffffffffffb0,0),false,skipPre);
    return;
  }
  if ((!skipPre) && (bVar9 = PlayerObject__preSlopeCollision(this,dt,object), bVar9)) {
    return;
  }
  uVar13 = getObjectRect/*virtual+0x520*/(this);
  CCRect__CCRect_copy(&fStack_b8,uVar13);
  uVar13 = getObjectRect/*virtual+0x520*/(object);
  CCRect__CCRect_copy(&uStack_c8,uVar13);
  bVar25 = object->m_slopeUphill;
  if (this->m_isPlatformer == true) {
    if (0.0 <= this->m_platformerXVelocity) goto LAB_10037e494;
LAB_10037e4a8:
    bVar9 = true;
  }
  else {
    if (this->m_isGoingLeft == true) goto LAB_10037e4a8;
LAB_10037e494:
    bVar9 = false;
    bVar25 = bVar25 ^ 1;
  }
  bVar10 = GameObject__slopeFloorTop(object);
  getRealPosition/*virtual+0x540*/(apfStack_e8,object);
  uVar13 = GameObject__getLastPosition(object);
  CCPoint__operator_minus(&fStack_d0,apfStack_e8,uVar13);
  bVar7 = this->m_isSideways;
  fVar34 = fStack_d0;
  if (bVar7 == false) {
    fVar34 = fStack_cc;
    fStack_cc = fStack_d0;
  }
  dVar35 = this->m_speedMultiplier * (double)this->m_playerSpeed;
  bVar6 = this->m_isUpsideDown;
  if ((double)fStack_cc <= dVar35 * (double)dt) {
    bVar26 = 0;
    bVar25 = bVar25 ^ bVar6 != bVar7;
    cVar16 = this->m_wasOnSlope;
    if ((bool)cVar16 == true) goto LAB_10037e578;
LAB_10037e544:
    fVar41 = fStack_bc / (float)((double)fStack_c0 / dVar35);
  }
  else {
    bVar26 = bVar25 ^ bVar6;
    bVar25 = bVar25 ^ 1 ^ bVar6 != bVar7;
    cVar16 = this->m_wasOnSlope;
    if ((bool)cVar16 != true) goto LAB_10037e544;
LAB_10037e578:
    fVar42 = -this->m_slopeVelocity;
    if ((bVar6 & 1U) == 0) {
      fVar42 = this->m_slopeVelocity;
    }
    if ((((0.0 < fVar42 & bVar25) == 1) && (this->m_isCurrentSlopeTop == bVar10)) &&
       (this->m_isCurrentSlopeTop == bVar6)) {
      return;
    }
    fVar41 = fStack_bc / (float)((double)fStack_c0 / dVar35);
    if ((0.0 < fVar42) && ((double)fVar41 < this->m_currentSlopeYVelocity)) {
      return;
    }
  }
  fVar42 = 4.0;
  if ((bVar25 & 1) == 0) {
    fVar42 = 0.0;
  }
  if (cVar16 == '\0') {
    fVar42 = (float)(bVar25 & 1);
  }
  uVar13 = GameObject__getLastPosition(object);
  getRealPosition/*virtual+0x540*/(apfStack_e8,object);
  CCPoint__operator_minus(&fStack_d8,uVar13,apfStack_e8);
  pfVar2 = &fStack_d8;
  if (this->m_isSideways == false) {
    pfVar2 = &fStack_d4;
  }
  fVar29 = *pfVar2;
  bVar7 = this->m_isUpsideDown;
  if (((bVar7 & 1U) != 0) || (fVar29 <= 0.0)) {
    bVar17 = 0;
    if (fVar29 < 0.0) {
      bVar17 = bVar7;
    }
    if ((skipPre) || (bVar17 != 0)) goto LAB_10037e654;
  }
  else {
    bVar17 = 1;
LAB_10037e654:
    fVar40 = 10.0;
    if (this->m_isPlatformer == false) {
      fVar40 = 5.0;
    }
    fVar33 = fVar40 * dt;
    if (ABS(fVar29) <= fVar40 * dt) {
      fVar33 = ABS(fVar29);
    }
    fVar42 = fVar42 + fVar33;
  }
  fVar40 = fStack_ac * 0.5;
  fVar29 = (float)_cosf((float)this->m_slopeRotation);
  fVar40 = fVar40 / fVar29;
  lVar14 = getPosition/*virtual+0xc0*/(this);
  fVar29 = fVar42 + fVar40 + *(float *)(lVar14 + 4);
  if (bVar7 == false) {
    fVar29 = (*(float *)(lVar14 + 4) - fVar40) - fVar42;
  }
  if (this->m_wasOnSlope == true) {
    if ((this->m_isUpsideDown & 1U) == 0) {
      if (fStack_c4 + fStack_bc < fVar29) {
        return;
      }
    }
    else if (fVar29 < fStack_c4) {
      return;
    }
  }
  else {
    CCRect__CCRect(uStack_c8,fStack_c4 + 1.0,fStack_c0,fStack_bc + -2.0,apfStack_e8);
    iVar11 = CCRect__intersectsRect(&fStack_b8,apfStack_e8);
    if (iVar11 == 0) {
      return;
    }
  }
  uVar13 = getPosition/*virtual+0xc0*/(this);
  CCPoint__CCPoint_copy(&fStack_f0,uVar13);
  fVar29 = (float)CCRect__getMinY(&uStack_c8);
  fVar30 = (float)CCRect__getMaxY(&uStack_c8);
  fVar31 = GameObject__getSlopeAngle(object);
  fVar40 = fStack_ac;
  fVar32 = (float)_cosf();
  fVar33 = 0.0;
  if ((this->m_wasOnSlope == true) && (this->m_collidingWithSlopeId != object->m_uniqueID)) {
    if (this->m_isCurrentSlopeTop == bVar10) {
      bVar27 = 0;
    }
    else {
      fVar33 = 0.0;
      if ((this->m_isPlatformer & 1U) == 0) {
        fVar33 = this->m_vehicleSize * 20.0;
      }
      bVar27 = 1;
    }
  }
  else {
    bVar27 = 0;
  }
  fVar40 = (fVar40 / fVar32) * 0.5;
  dVar36 = GameObject__slopeYPos(object,fStack_f0);
  if (bVar10) {
    fVar32 = fVar33 + (fVar29 - fStack_ac * 0.5);
    fVar33 = fVar33 + ((float)dVar36 - fVar40);
    bVar7 = fVar33 <= fVar32;
    if (fVar32 < fVar33) {
      fVar32 = fVar33;
    }
    bVar6 = fVar30 <= fVar32;
    fVar29 = fVar30;
    if (!bVar6) {
      fVar29 = fVar32;
    }
    if (this->m_isUpsideDown == false) goto LAB_10037e838;
LAB_10037e8c0:
    if ((bVar27 == 0 && ((bVar25 ^ 1) & 1) == 0) && ((this->m_isOnSlope & 1U) == 0)) {
      if ((this->m_maybeIsBoosted & 1U) == 0) {
        if ((this->m_isShip & 1U) != 0) goto LAB_10037ea40;
      }
      else {
        if ((this->m_isShip & 1U) != 0) {
LAB_10037ea40:
          bVar18 = this->m_jumpBuffered ^ 1;
          goto LAB_10037e8d8;
        }
        if ((((this->m_isBird & 1U) == 0) && ((this->m_isDart & 1U) == 0)) &&
           ((this->m_isSwing & 1U) == 0)) goto LAB_10037e8d4;
      }
      bVar18 = 1;
    }
    else {
LAB_10037e8d4:
      bVar18 = 0;
    }
LAB_10037e8d8:
    if ((bVar25 & 1) == 0) {
      bVar18 = bVar17 | bVar18 | skipPre & (bVar25 ^ 1);
    }
    bVar8 = fStack_ec < fVar29;
    if (!bVar10) {
      if (bVar8 || ((bVar18 ^ 1) & 1) != 0) {
LAB_10037e9d8:
        bVar17 = this->m_jumpBuffered;
        goto joined_r0x00010037e9dc;
      }
      if (fVar42 + fVar29 <= fStack_ec) {
LAB_10037e9d4:
        bVar8 = false;
        goto LAB_10037e9d8;
      }
      if (this->m_isBird != true) {
LAB_10037ea14:
        bVar8 = true;
        bVar17 = this->m_jumpBuffered;
        goto joined_r0x00010037e9dc;
      }
      bVar8 = this->m_yVelocity <= 0.0;
      if ((this->m_jumpBuffered & 1U) == 0) goto LAB_10037ea20;
LAB_10037e9e0:
      if ((((this->m_isShip & 1U) == 0) && ((this->m_isBird & 1U) == 0)) &&
         ((this->m_isDart & 1U) == 0)) {
        bVar17 = this->m_isSwing;
        if ((bVar17 & bVar25 & 1) == 0) goto LAB_10037ea60;
LAB_10037ea04:
        if ((this->m_isPlatformer & 1U) == 0) goto LAB_10037ea88;
        bVar17 = 1;
LAB_10037ea68:
        bVar17 = bVar27 & bVar17 ^ 1;
        bVar3 = true;
      }
      else {
        bVar17 = 1;
        if ((bVar25 & 1) != 0) goto LAB_10037ea04;
LAB_10037ea60:
        if ((bVar17 & 1) != 0) {
          bVar17 = this->m_isPlatformer;
          goto LAB_10037ea68;
        }
LAB_10037ea88:
        bVar3 = false;
        bVar17 = 0;
      }
      bVar18 = 0;
      bVar24 = false;
      uVar12 = 0;
      if (!bVar8) goto LAB_10037ec60;
LAB_10037eaa0:
      bVar18 = 0;
      bVar24 = false;
      bVar4 = object->m_slopeIsHazard;
      goto joined_r0x00010037eaa4;
    }
    bVar8 = fStack_ec != fVar29 && !bVar8;
    if (bVar8 || ((bVar18 ^ 1) & 1) != 0) goto LAB_10037e9d8;
    if (fStack_ec <= fVar29 - fVar42) goto LAB_10037e9d4;
    if (this->m_isBird != true) goto LAB_10037ea14;
    bVar8 = 0.0 <= this->m_yVelocity;
    bVar17 = this->m_jumpBuffered;
joined_r0x00010037e9dc:
    if ((bVar17 & 1) != 0) goto LAB_10037e9e0;
LAB_10037ea20:
    bVar3 = false;
    bVar18 = 0;
    bVar17 = 0;
    bVar24 = false;
    uVar12 = 0;
    if (bVar8) goto LAB_10037eaa0;
LAB_10037ec60:
    cVar16 = this->m_isSideways;
  }
  else {
    fVar30 = (fVar30 + fStack_ac * 0.5) - fVar33;
    fVar33 = (fVar40 + (float)dVar36) - fVar33;
    bVar7 = fVar30 <= fVar33;
    if (!bVar7) {
      fVar30 = fVar33;
    }
    bVar6 = fVar30 <= fVar29;
    if (fVar29 < fVar30) {
      fVar29 = fVar30;
    }
    if ((this->m_isUpsideDown & 1U) == 0) goto LAB_10037e8c0;
LAB_10037e838:
    fVar33 = 0.0;
    if ((bVar25 & 1) == 0) {
      if ((((this->m_isShip & 1U) != 0) || ((this->m_isBird & 1U) != 0)) ||
         (((this->m_isDart & 1U) != 0 || (this->m_isSwing == true)))) {
        fVar33 = fVar42;
        if ((this->m_jumpBuffered == true) && (fVar33 = 2.0, this->m_wasOnSlope == false)) {
          fVar33 = 1.0;
        }
        goto LAB_10037e888;
      }
      if (bVar27 == 0) goto LAB_10037eab4;
LAB_10037e88c:
      bVar17 = 1;
    }
    else {
LAB_10037e888:
      fVar42 = fVar33;
      if (bVar27 != 0) goto LAB_10037e88c;
LAB_10037eab4:
      bVar17 = bVar25;
      if ((((this->m_isShip & 1U) == 0) && ((this->m_isBird & 1U) == 0)) &&
         ((this->m_isDart & 1U) == 0)) {
        bVar17 = this->m_isSwing & bVar25;
      }
      if (((bVar17 & 1) != 0) && (this->m_isPlatformer != true)) goto LAB_10037e88c;
      bVar17 = this->m_isOnSlope;
    }
    bVar8 = fStack_ec < fVar29;
    if (fStack_ec >= fVar29 && (bVar17 & 1) == 0) {
      bVar8 = fStack_ec < fVar29 + fVar42;
    }
    bVar3 = fVar29 < fStack_ec;
    if (fVar29 >= fStack_ec && (bVar17 & 1) == 0) {
      bVar3 = fVar29 - fVar42 < fStack_ec;
    }
    if (bVar10) {
      bVar8 = bVar3;
    }
    if ((this->m_jumpBuffered & 1U) == 0) {
      bVar3 = this->m_isShip;
      bVar18 = bVar25;
      if (this->m_isPlatformer == true) {
joined_r0x00010037eba0:
        bVar17 = 0;
        if ((bVar3 & 1U) == 0) {
LAB_10037eba4:
          bVar18 = bVar25;
          if ((this->m_isBird & 1U) == 0) goto LAB_10037ebac;
        }
      }
      else {
        if ((((bVar3 & 1U) != 0) || ((this->m_isBird & 1U) != 0)) ||
           (((this->m_isDart & 1U) != 0 || ((this->m_isSwing & 1U) != 0)))) {
          if ((bVar25 & 1) != 0) goto LAB_10037eb88;
          bVar18 = 0;
          goto joined_r0x00010037eba0;
        }
        if ((this->m_isBall & bVar25 & 1) != 0) {
LAB_10037eb88:
          bVar17 = this->m_wasOnSlope;
          if ((bVar3 & 1U) != 0) goto joined_r0x00010037eb40;
          goto LAB_10037eba4;
        }
        bVar17 = 0;
        if ((this->m_isBird & 1U) != 0) goto joined_r0x00010037eb40;
LAB_10037ebac:
        bVar18 = bVar25;
        if ((this->m_isDart & 1U) == 0) {
          bVar18 = this->m_isSwing & bVar25;
        }
      }
    }
    else {
      bVar17 = 0;
      bVar18 = 0;
    }
joined_r0x00010037eb40:
    if (bVar8) {
      if (((((((this->m_isShip & 1U) == 0) && ((this->m_isBird & 1U) == 0)) &&
            ((this->m_isDart & 1U) == 0)) &&
           (((this->m_isSwing & 1U) == 0 && ((this->m_isBall & 1U) == 0)))) &&
          ((this->m_isPlatformer & 1U) == 0)) && (this->m_stateHitHead < 1)) {
        if (((this->m_gameModeChangedTime != 0.0) &&
            (this->m_totalTime - this->m_gameModeChangedTime < 0.10000000149011612)) ||
           ((this->m_lastFlipTime != 0.0 &&
            (this->m_totalTime - this->m_lastFlipTime < 0.10000000149011612)))) {
          puVar15 = (undefined4 *)getPosition/*virtual+0xc0*/(this);
          CCPoint__CCPoint(*puVar15,fVar29,apfStack_e8);
          setPosition/*virtual+0xb8*/(this,apfStack_e8);
          dVar35 = this->m_yVelocity;
          if ((this->m_isUpsideDown & 1U) == 0) {
            dVar36 = -2.0;
            if (dVar35 <= -2.0) goto LAB_10037f854;
          }
          else {
            dVar36 = 2.0;
            if (2.0 <= dVar35) {
LAB_10037f854:
              dVar36 = dVar35;
            }
          }
          dVar35 = (double)(int)dVar36;
          if (dVar36 != dVar35) {
            dVar36 = (double)(long)((dVar36 - dVar35) * 1000.0) / 1000.0 + dVar35;
          }
          this->m_yVelocity = dVar36;
LAB_10037f88c:
          this->m_isOnGround = false;
          this->m_isOnGround2 = false;
          return;
        }
        if (bVar10) {
          if (fStack_ec + -2.0 <= fVar29) goto LAB_10037f88c;
        }
        else if (fVar29 <= fStack_ec + 2.0) goto LAB_10037f88c;
        if ((this->m_ignoreDamage & 1U) == 0) goto LAB_10037ec14;
      }
      bVar3 = false;
      bVar24 = true;
      bVar4 = object->m_slopeIsHazard;
joined_r0x00010037eaa4:
      if ((((bVar4 & 1) != 0) ||
          ((((bVar27 != 0 || ((this->m_isDart == true && (this->m_stateDartSlide < 1)))) &&
            ((this->m_isPlatformer & 1U) == 0)) && (this->m_stateHitHead < 1)))) &&
         ((this->m_ignoreDamage & 1U) == 0)) {
LAB_10037ec14:
        if ((this->m_maybeCanRunIntoBlocks & 1U) != 0) {
          this->m_maybeIsColliding = true;
          return;
        }
        lVar14 = GameManager__sharedState();
        (**(code **)(**(long **)(lVar14 + 0x1f8) + 0x4f8))(*(long **)(lVar14 + 0x1f8),this,0);
        return;
      }
      uVar12 = 1;
      goto LAB_10037ec60;
    }
    uVar12 = 0;
    bVar3 = false;
    bVar24 = true;
    cVar16 = this->m_isSideways;
  }
  if ((cVar16 == '\x01') && (uVar20 = *(ulong *)(this->m_rotateObjectsRelated + 8), uVar20 != 0)) {
    fVar42 = (float)object->m_uniqueID;
    uVar19 = (ulong)(int)fVar42;
    uVar13 = CONCAT17(POPCOUNT((char)(uVar20 >> 0x38)),
                      CONCAT16(POPCOUNT((char)(uVar20 >> 0x30)),
                               CONCAT15(POPCOUNT((char)(uVar20 >> 0x28)),
                                        CONCAT14(POPCOUNT((char)(uVar20 >> 0x20)),
                                                 CONCAT13(POPCOUNT((char)(uVar20 >> 0x18)),
                                                          CONCAT12(POPCOUNT((char)(uVar20 >> 0x10)),
                                                                   CONCAT11(POPCOUNT((char)(uVar20 
                                                  >> 8)),POPCOUNT((char)uVar20))))))));
    uVar28 = NEON_uaddlv(uVar13,1);
    uVar23 = CONCAT62((int6)((ulong)uVar13 >> 0x10),uVar28) & 0xffffffff;
    if (uVar23 < 2) {
      uVar21 = uVar20 - 1 & uVar19;
    }
    else {
      uVar21 = uVar19;
      if (uVar20 <= uVar19) {
        uVar21 = 0;
        if (uVar20 != 0) {
          uVar21 = uVar19 / uVar20;
        }
        uVar21 = uVar19 - uVar21 * uVar20;
      }
    }
    plVar22 = *(long **)(*(long *)this->m_rotateObjectsRelated + uVar21 * 8);
    if ((plVar22 != (long *)0x0) && (plVar22 = (long *)*plVar22, plVar22 != (long *)0x0)) {
      if (uVar23 < 2) {
        do {
          if (plVar22[1] == uVar19) {
            if (*(float *)(plVar22 + 2) == fVar42) goto LAB_10037ee80;
          }
          else if ((plVar22[1] & uVar20 - 1) != uVar21) break;
          plVar22 = (long *)*plVar22;
        } while (plVar22 != (long *)0x0);
      }
      else {
        do {
          uVar23 = plVar22[1];
          if (uVar23 == uVar19) {
            if (*(float *)(plVar22 + 2) == fVar42) goto LAB_10037ee80;
          }
          else {
            if (uVar20 <= uVar23) {
              uVar5 = 0;
              if (uVar20 != 0) {
                uVar5 = uVar23 / uVar20;
              }
              uVar23 = uVar23 - uVar5 * uVar20;
            }
            if (uVar23 != uVar21) break;
          }
          plVar22 = (long *)*plVar22;
        } while (plVar22 != (long *)0x0);
      }
    }
  }
  fVar42 = fVar29;
  if (this->m_wasOnSlope == true) goto LAB_10037edb8;
LAB_10037ef04:
  if ((uVar12 & this->m_isPlatformer) == 1) {
    CCRect__CCRect(fStack_b8 + -2.0,fStack_b4 + -10.0,fStack_b0 + 4.0,fStack_ac + 20.0,
                        apfStack_e8);
    uVar12 = CCRect__intersectsRect(&uStack_c8,apfStack_e8);
  }
LAB_10037ef58:
  if ((((bVar25 & 1) != 0) && (this->m_isDart == true)) && (this->m_jumpBuffered == true)) {
    uVar12 = this->m_isUpsideDown != bVar10 & uVar12;
  }
  if (uVar12 == 0) {
    return;
  }
  *(GameObject **)this->m_currentSlope = object;
  fVar34 = GameObject__getSlopeAngle(object);
  this->m_slopeAngleRadians = fVar34;
  *(undefined8 *)this->m_currentPotentialSlope = *(undefined8 *)this->m_currentSlope;
  fStack_f8 = (float)object->m_uniqueID;
  apfStack_e8[0] = &fStack_f8;
  lVar14 = unordered_map_int_GameObject__emplace(this->m_potentialSlopeMap,&fStack_f8,&UNK_10072382e,apfStack_e8,
                               &fStack_100);
  *(GameObject **)(lVar14 + 0x18) = object;
  this->unk_584 = (double)(fVar40 + fStack_ac * -0.5);
  this->m_isCurrentSlopeTop = bVar10;
  this->m_unk3d0 = (double)fVar29;
  this->m_blackOrbRelated = (double)fVar42;
  this->m_collidingWithSlopeId = object->m_uniqueID;
  iVar11 = 1;
  if (this->m_isUpsideDown != false) {
    iVar11 = -1;
  }
  this->m_slopeFlipGravityRelated = (bool)(bVar25 & 1);
  dVar36 = this->m_slopeRotation;
  this->m_unk3e0 = bVar7;
  this->m_unk3e1 = bVar6;
  iVar1 = -iVar11;
  if ((bool)(bVar25 & 1) != false) {
    iVar1 = iVar11;
  }
  iVar11 = -iVar1;
  if ((double)fStack_cc <= dVar35 * (double)dt) {
    iVar11 = iVar1;
  }
  iVar1 = -iVar11;
  if (!bVar9) {
    iVar1 = iVar11;
  }
  iVar11 = -iVar1;
  if (this->m_isSideways == false) {
    iVar11 = iVar1;
  }
  this->m_slopeRotation = (double)(fVar31 * 57.29578 * (float)iVar11 * 0.017453292);
  uVar13 = getPosition/*virtual+0xc0*/(this);
  CCPoint__CCPoint_copy(apfStack_e8,uVar13);
  puVar15 = (undefined4 *)getPosition/*virtual+0xc0*/(this);
  CCPoint__CCPoint(*puVar15,fVar29,&fStack_f8);
  setPosition/*virtual+0xb8*/(this,&fStack_f8);
  this->m_isOnSlope = true;
  if ((this->m_wasOnSlope & 1U) == 0) {
    this->m_slopeStartTime = this->m_totalTime;
    this->m_yVelocityBeforeSlope = this->m_yVelocity;
  }
  this->m_maybeUpsideDownSlope = bVar24;
  if ((bVar17 & 1) == 0) {
    if (bVar24 == false) {
      dVar35 = this->m_yVelocity;
      fVar34 = (float)dVar35;
      PlayerObject__hitGround(this,object,false);
      bVar9 = fVar34 < -5.0;
      if (this->m_isUpsideDown == false) {
        bVar9 = 5.0 < fVar34;
      }
      if (bVar9) {
        dVar38 = (double)fVar34;
        dVar35 = (double)(int)dVar35;
        if (dVar35 != dVar38) {
          dVar38 = (double)(long)((dVar38 - dVar35) * 1000.0) / 1000.0 + dVar35;
        }
        this->m_yVelocity = dVar38;
      }
      if (((this->m_isPlatformer == true) && (40.0 < ABS(this->m_slopeAngleRadians * 57.29578))) &&
         ((fVar34 < -5.0 && (0.0 < this->m_platformerXVelocity)))) {
        this->m_platformerXVelocity = this->m_platformerXVelocity * 0.5;
      }
      lVar14 = getObjectRect/*virtual+0x520*/(this);
      fVar42 = *(float *)(lVar14 + 0xc);
      getObjectRect/*virtual+0x520*/(this);
      lVar14 = getPosition/*virtual+0xc0*/(this);
      fVar34 = -1.0;
      if (this->m_isUpsideDown == false) {
        fVar34 = 1.0;
      }
      iVar11 = object->m_uniqueID;
      dVar38 = this->m_collidedBottomMaxY;
      dVar35 = (double)(*(float *)(lVar14 + 4) + fVar34 * fVar42 * -0.5);
      if (dVar38 != 0.0) {
        if ((this->m_isUpsideDown & 1U) == 0) {
          if (dVar35 <= dVar38) {
            dVar35 = dVar38;
          }
        }
        else if (dVar38 == dVar35 || dVar35 > dVar38) {
          dVar35 = dVar38;
        }
      }
      this->m_collidedBottomMaxY = dVar35;
      if ((iVar11 != 0) && (this->m_lastCollisionBottom != iVar11)) {
        this->m_lastCollisionBottom = iVar11;
        if (*(long *)this->m_collisionLogBottom != 0) {
          CCDictionary__setObject(*(long *)this->m_collisionLogBottom,
                              *(undefined8 *)this->m_maybeLastGroundObject,(long)iVar11);
        }
      }
      *(GameObject **)this->m_currentSlope2 = object;
      fVar34 = GameObject__getSlopeAngle(object);
      this->m_slopeAngle = fVar34;
      bVar17 = *(byte *)(*(long *)this->m_currentSlope2 + 0x438);
      this->m_slopeSlidingMaybeRotated = (bool)bVar17;
      if (this->m_isSideways == true) {
        bVar17 = bVar17 ^ 1;
        this->m_slopeSlidingMaybeRotated = (bool)bVar17;
      }
      if ((bVar17 != 0) && (1.0 <= fVar34)) {
        this->m_maybeSlidingTime = 3;
      }
      uVar13 = GameObject__getLastPosition(object);
      CCPoint__CCPoint_copy(&fStack_f8,uVar13);
      getRealPosition/*virtual+0x540*/(&fStack_100,object);
      if ((fStack_100 != fStack_f8) || (fStack_fc != fStack_f4)) {
        fVar34 = fStack_f8;
        if (this->m_isUpsideDown == false) {
          fStack_100 = fStack_fc;
          fVar34 = fStack_f4;
        }
        bVar9 = fVar34 != fStack_100 && fVar34 >= fStack_100;
        if (this->m_isUpsideDown == false) {
          bVar9 = fVar34 < fStack_100;
        }
        if (bVar9) {
          this->m_groundYVelocity = (double)((fStack_100 - fVar34) / dt);
        }
      }
    }
    else {
      dVar38 = this->m_yVelocity;
      dVar35 = 0.0;
      if ((this->m_isUpsideDown & 1U) == 0) {
        if (dVar38 <= 0.0) goto LAB_10037f148;
      }
      else if (0.0 <= dVar38) {
LAB_10037f148:
        dVar35 = dVar38;
      }
      dVar38 = (double)(int)dVar35;
      if (dVar35 != dVar38) {
        dVar35 = (double)(long)((dVar35 - dVar38) * 1000.0) / 1000.0 + dVar38;
      }
      this->m_yVelocity = dVar35;
      this->m_isOnGround = false;
      this->m_isOnGround2 = false;
      lVar14 = getObjectRect/*virtual+0x520*/(this);
      fVar34 = *(float *)(lVar14 + 0xc);
      getObjectRect/*virtual+0x520*/(this);
      lVar14 = getPosition/*virtual+0xc0*/(this);
      fVar42 = -1.0;
      if (this->m_isUpsideDown == false) {
        fVar42 = 1.0;
      }
      iVar11 = object->m_uniqueID;
      dVar38 = this->m_collidedTopMinY;
      dVar35 = (double)(*(float *)(lVar14 + 4) + fVar42 * fVar34 * 0.5);
      if (dVar38 != 0.0) {
        dVar39 = dVar35;
        if (dVar35 <= dVar38) {
          dVar39 = dVar38;
        }
        dVar37 = dVar35;
        if (dVar38 <= dVar35) {
          dVar37 = dVar38;
        }
        dVar35 = dVar39;
        if ((this->m_isUpsideDown & 1U) == 0) {
          dVar35 = dVar37;
        }
      }
      this->m_collidedTopMinY = dVar35;
      if ((iVar11 != 0) && (this->m_lastCollisionTop != iVar11)) {
        this->m_lastCollisionTop = iVar11;
        if (*(long *)this->m_collisionLogTop != 0) {
          CCDictionary__setObject(*(long *)this->m_collisionLogTop,
                              *(undefined8 *)this->m_maybeLastGroundObject,(long)iVar11);
        }
      }
    }
  }
  bVar17 = this->m_isUpsideDown;
  if ((bVar18 & 1) != 0) {
    if ((bVar17 & 1) == 0) {
      dVar35 = -2.0;
      if (-2.0 < this->m_yVelocity) goto LAB_10037f244;
    }
    else {
      dVar35 = 2.0;
      if (this->m_yVelocity < 2.0) {
LAB_10037f244:
        dVar38 = (double)(int)dVar35;
        if (dVar35 != dVar38) {
          dVar35 = (double)(long)((dVar35 - dVar38) * 1000.0) / 1000.0 + dVar38;
        }
        this->m_yVelocity = dVar35;
      }
    }
  }
  if (bVar3) {
    if ((bVar17 & 1) == 0) {
      dVar35 = 2.0;
      if (2.0 <= this->m_yVelocity) {
        bVar17 = 0;
        goto LAB_10037f438;
      }
    }
    else {
      dVar35 = -2.0;
      if (this->m_yVelocity <= -2.0) {
        bVar17 = 1;
        goto LAB_10037f438;
      }
    }
    dVar38 = (double)(int)dVar35;
    if (dVar35 != dVar38) {
      dVar35 = (double)(long)((dVar35 - dVar38) * 1000.0) / 1000.0 + dVar38;
    }
    this->m_yVelocity = dVar35;
  }
LAB_10037f438:
  this->m_currentSlopeYVelocity = (double)fVar41;
  fVar42 = (float)NEON_fminnm(0.8 / fVar31,0x3f8ccccd);
  fVar34 = fVar41 * 1.4 * fVar42;
  if (((bVar26 | bVar25 ^ 0xff) & 1) == 0) {
    fVar34 = -(fVar41 * 1.4 * fVar42);
  }
  fVar42 = -fVar34;
  if ((bVar17 & 1) == 0) {
    fVar42 = fVar34;
  }
  this->m_slopeVelocity = fVar42;
  if (((bVar24 & this->m_isPlatformer) == 1) && (this->m_isBird == true)) {
    this->m_jumpBuffered = false;
  }
  if ((((((this->m_isShip & 1U) == 0) && ((this->m_isBird & 1U) == 0)) &&
       ((this->m_isDart & 1U) == 0)) && (((this->m_isSwing & 1U) == 0 && (this->m_isBall != true))))
     || (this->m_slopeVelocity = fVar42 * 0.75, (this->m_isBall & 1U) == 0)) {
    PlayerObject__updateSlopeRotation(this,dt);
  }
  else if (this->m_slopeRotation != (double)(float)dVar36) {
    this->m_isRotating = false;
    this->m_isBallRotating2 = false;
    this->m_isBallRotating = false;
    this->m_rotationSpeed = 0.0;
    if (((this->m_isDashing | this->m_isPlatformer) & 1U) == 0) {
      fVar42 = (float)_cosf((float)this->m_slopeRotation);
      fVar42 = 1.0 / fVar42;
      fVar34 = (fVar42 + -1.0) * 0.7 + 1.0;
      if (fVar42 <= 2.0) {
        fVar34 = fVar42;
      }
      this->m_isBallRotating = fVar34 != 1.0;
      this->m_rotateSpeed = fVar34;
      fVar34 = this->m_playerSpeed;
      if (fVar34 == 0.7) {
        fVar34 = 1.2405638;
      }
      else if (fVar34 == 1.1) {
        fVar34 = 0.80424345;
      }
      else if (fVar34 == 1.3) {
        fVar34 = 0.6657693;
      }
      else if (fVar34 == 1.6) {
        fVar34 = 0.5409375;
      }
      else {
        fVar34 = 1.0;
      }
      iVar11 = 0x78;
      if ((bVar17 & 1) != 0) {
        iVar11 = -0x78;
      }
      iVar1 = -iVar11;
      if (this->m_isGoingLeft == false) {
        iVar1 = iVar11;
      }
      fVar42 = 0.2;
      if (this->m_vehicleSize != 1.0) {
        fVar42 = 0.16000001;
      }
      fVar34 = (float)iVar1 / (fVar42 * fVar34);
      this->m_rotationSpeed = fVar34;
      if (this->m_isSideways == true) {
        this->m_rotationSpeed = -fVar34;
      }
      this->m_isRotating = true;
    }
  }
  return;
LAB_10037ee80:
  apfStack_e8[0] = &fStack_f8;
  fStack_f8 = fVar42;
  lVar14 = unordered_map_int_GJPointDouble__emplace(this->m_rotateObjectsRelated,&fStack_f8,&UNK_10072382e,apfStack_e8,
                               &fStack_100);
  fVar42 = (float)((double)fVar29 - *(double *)(lVar14 + 0x20));
  if (this->m_wasOnSlope != true) goto LAB_10037ef04;
LAB_10037edb8:
  if (((this->m_unk3d0 != (double)fVar29) &&
      ((this->m_isSideways != true || (this->m_blackOrbRelated != (double)fVar42)))) ||
     ((this->m_isPlatformer == true && (ABS(this->m_platformerXVelocity) < 0.10000000149011612)))) {
    if (fVar34 != 0.0) {
      if ((bVar7) && ((this->m_unk3e0 & 1U) != 0)) {
LAB_10037ee38:
        if (((this->m_isDashing & 1U) == 0) &&
           ((this->m_isPlatformer != true ||
            (0.10000000149011612 < ABS(this->m_platformerXVelocity))))) goto LAB_10037edf0;
      }
      else if (bVar6) {
        if (this->m_unk3e1 == true) goto LAB_10037ee38;
        bVar6 = true;
      }
    }
    goto LAB_10037ef04;
  }
LAB_10037edf0:
  uVar12 = 0;
  goto LAB_10037ef58;
}


// ==== PlayerObject::collidedWithSlopeInternal @ 0x37e3e4

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PlayerObject__collidedWithSlopeInternal
               (PlayerObject *this,float dt,GameObject *object,bool forced)

{
  int iVar1;
  float *pfVar2;
  bool bVar3;
  byte bVar4;
  ulong uVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  int iVar11;
  uint uVar12;
  undefined8 uVar13;
  long lVar14;
  undefined4 *puVar15;
  char cVar16;
  byte bVar17;
  byte bVar18;
  ulong uVar19;
  ulong uVar20;
  ulong uVar21;
  long *plVar22;
  ulong uVar23;
  bool bVar24;
  byte bVar25;
  byte bVar26;
  byte bVar27;
  undefined2 uVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  float fVar32;
  float fVar33;
  float fVar34;
  double dVar35;
  double dVar36;
  double dVar37;
  double dVar38;
  double dVar39;
  float fVar40;
  float fVar41;
  float fVar42;
  float fStack_100;
  float fStack_fc;
  float fStack_f8;
  float fStack_f4;
  float fStack_f0;
  float fStack_ec;
  float *apfStack_e8 [2];
  float fStack_d8;
  float fStack_d4;
  float fStack_d0;
  float fStack_cc;
  undefined4 uStack_c8;
  float fStack_c4;
  float fStack_c0;
  float fStack_bc;
  float fStack_b8;
  float fStack_b4;
  float fStack_b0;
  float fStack_ac;
  
  if ((!forced) && (bVar9 = PlayerObject__preSlopeCollision(this,dt,object), bVar9)) {
    return;
  }
  uVar13 = getObjectRect/*virtual+0x520*/(this);
  CCRect__CCRect_copy(&fStack_b8,uVar13);
  uVar13 = getObjectRect/*virtual+0x520*/(object);
  CCRect__CCRect_copy(&uStack_c8,uVar13);
  bVar25 = object->m_slopeUphill;
  if (this->m_isPlatformer == true) {
    if (0.0 <= this->m_platformerXVelocity) goto LAB_10037e494;
LAB_10037e4a8:
    bVar9 = true;
  }
  else {
    if (this->m_isGoingLeft == true) goto LAB_10037e4a8;
LAB_10037e494:
    bVar9 = false;
    bVar25 = bVar25 ^ 1;
  }
  bVar10 = GameObject__slopeFloorTop(object);
  getRealPosition/*virtual+0x540*/(apfStack_e8,object);
  uVar13 = GameObject__getLastPosition(object);
  CCPoint__operator_minus(&fStack_d0,apfStack_e8,uVar13);
  bVar7 = this->m_isSideways;
  fVar34 = fStack_d0;
  if (bVar7 == false) {
    fVar34 = fStack_cc;
    fStack_cc = fStack_d0;
  }
  dVar35 = this->m_speedMultiplier * (double)this->m_playerSpeed;
  bVar6 = this->m_isUpsideDown;
  if ((double)fStack_cc <= dVar35 * (double)dt) {
    bVar26 = 0;
    bVar25 = bVar25 ^ bVar6 != bVar7;
    cVar16 = this->m_wasOnSlope;
    if ((bool)cVar16 == true) goto LAB_10037e578;
LAB_10037e544:
    fVar41 = fStack_bc / (float)((double)fStack_c0 / dVar35);
  }
  else {
    bVar26 = bVar25 ^ bVar6;
    bVar25 = bVar25 ^ 1 ^ bVar6 != bVar7;
    cVar16 = this->m_wasOnSlope;
    if ((bool)cVar16 != true) goto LAB_10037e544;
LAB_10037e578:
    fVar42 = -this->m_slopeVelocity;
    if ((bVar6 & 1U) == 0) {
      fVar42 = this->m_slopeVelocity;
    }
    if ((((0.0 < fVar42 & bVar25) == 1) && (this->m_isCurrentSlopeTop == bVar10)) &&
       (this->m_isCurrentSlopeTop == bVar6)) {
      return;
    }
    fVar41 = fStack_bc / (float)((double)fStack_c0 / dVar35);
    if ((0.0 < fVar42) && ((double)fVar41 < this->m_currentSlopeYVelocity)) {
      return;
    }
  }
  fVar42 = 4.0;
  if ((bVar25 & 1) == 0) {
    fVar42 = 0.0;
  }
  if (cVar16 == '\0') {
    fVar42 = (float)(bVar25 & 1);
  }
  uVar13 = GameObject__getLastPosition(object);
  getRealPosition/*virtual+0x540*/(apfStack_e8,object);
  CCPoint__operator_minus(&fStack_d8,uVar13,apfStack_e8);
  pfVar2 = &fStack_d8;
  if (this->m_isSideways == false) {
    pfVar2 = &fStack_d4;
  }
  fVar29 = *pfVar2;
  bVar7 = this->m_isUpsideDown;
  if (((bVar7 & 1U) != 0) || (fVar29 <= 0.0)) {
    bVar17 = 0;
    if (fVar29 < 0.0) {
      bVar17 = bVar7;
    }
    if ((forced) || (bVar17 != 0)) goto LAB_10037e654;
  }
  else {
    bVar17 = 1;
LAB_10037e654:
    fVar40 = 10.0;
    if (this->m_isPlatformer == false) {
      fVar40 = 5.0;
    }
    fVar33 = fVar40 * dt;
    if (ABS(fVar29) <= fVar40 * dt) {
      fVar33 = ABS(fVar29);
    }
    fVar42 = fVar42 + fVar33;
  }
  fVar40 = fStack_ac * 0.5;
  fVar29 = (float)_cosf((float)this->m_slopeRotation);
  fVar40 = fVar40 / fVar29;
  lVar14 = getPosition/*virtual+0xc0*/(this);
  fVar29 = fVar42 + fVar40 + *(float *)(lVar14 + 4);
  if (bVar7 == false) {
    fVar29 = (*(float *)(lVar14 + 4) - fVar40) - fVar42;
  }
  if (this->m_wasOnSlope == true) {
    if ((this->m_isUpsideDown & 1U) == 0) {
      if (fStack_c4 + fStack_bc < fVar29) {
        return;
      }
    }
    else if (fVar29 < fStack_c4) {
      return;
    }
  }
  else {
    CCRect__CCRect(uStack_c8,fStack_c4 + 1.0,fStack_c0,fStack_bc + -2.0,apfStack_e8);
    iVar11 = CCRect__intersectsRect(&fStack_b8,apfStack_e8);
    if (iVar11 == 0) {
      return;
    }
  }
  uVar13 = getPosition/*virtual+0xc0*/(this);
  CCPoint__CCPoint_copy(&fStack_f0,uVar13);
  fVar29 = (float)CCRect__getMinY(&uStack_c8);
  fVar30 = (float)CCRect__getMaxY(&uStack_c8);
  fVar31 = GameObject__getSlopeAngle(object);
  fVar40 = fStack_ac;
  fVar32 = (float)_cosf();
  fVar33 = 0.0;
  if ((this->m_wasOnSlope == true) && (this->m_collidingWithSlopeId != object->m_uniqueID)) {
    if (this->m_isCurrentSlopeTop == bVar10) {
      bVar27 = 0;
    }
    else {
      fVar33 = 0.0;
      if ((this->m_isPlatformer & 1U) == 0) {
        fVar33 = this->m_vehicleSize * 20.0;
      }
      bVar27 = 1;
    }
  }
  else {
    bVar27 = 0;
  }
  fVar40 = (fVar40 / fVar32) * 0.5;
  dVar36 = GameObject__slopeYPos(object,fStack_f0);
  if (bVar10) {
    fVar32 = fVar33 + (fVar29 - fStack_ac * 0.5);
    fVar33 = fVar33 + ((float)dVar36 - fVar40);
    bVar7 = fVar33 <= fVar32;
    if (fVar32 < fVar33) {
      fVar32 = fVar33;
    }
    bVar6 = fVar30 <= fVar32;
    fVar29 = fVar30;
    if (!bVar6) {
      fVar29 = fVar32;
    }
    if (this->m_isUpsideDown == false) goto LAB_10037e838;
LAB_10037e8c0:
    if ((bVar27 == 0 && ((bVar25 ^ 1) & 1) == 0) && ((this->m_isOnSlope & 1U) == 0)) {
      if ((this->m_maybeIsBoosted & 1U) == 0) {
        if ((this->m_isShip & 1U) != 0) goto LAB_10037ea40;
      }
      else {
        if ((this->m_isShip & 1U) != 0) {
LAB_10037ea40:
          bVar18 = this->m_jumpBuffered ^ 1;
          goto LAB_10037e8d8;
        }
        if ((((this->m_isBird & 1U) == 0) && ((this->m_isDart & 1U) == 0)) &&
           ((this->m_isSwing & 1U) == 0)) goto LAB_10037e8d4;
      }
      bVar18 = 1;
    }
    else {
LAB_10037e8d4:
      bVar18 = 0;
    }
LAB_10037e8d8:
    if ((bVar25 & 1) == 0) {
      bVar18 = bVar17 | bVar18 | forced & (bVar25 ^ 1);
    }
    bVar8 = fStack_ec < fVar29;
    if (!bVar10) {
      if (bVar8 || ((bVar18 ^ 1) & 1) != 0) {
LAB_10037e9d8:
        bVar17 = this->m_jumpBuffered;
        goto joined_r0x00010037e9dc;
      }
      if (fVar42 + fVar29 <= fStack_ec) {
LAB_10037e9d4:
        bVar8 = false;
        goto LAB_10037e9d8;
      }
      if (this->m_isBird != true) {
LAB_10037ea14:
        bVar8 = true;
        bVar17 = this->m_jumpBuffered;
        goto joined_r0x00010037e9dc;
      }
      bVar8 = this->m_yVelocity <= 0.0;
      if ((this->m_jumpBuffered & 1U) == 0) goto LAB_10037ea20;
LAB_10037e9e0:
      if ((((this->m_isShip & 1U) == 0) && ((this->m_isBird & 1U) == 0)) &&
         ((this->m_isDart & 1U) == 0)) {
        bVar17 = this->m_isSwing;
        if ((bVar17 & bVar25 & 1) == 0) goto LAB_10037ea60;
LAB_10037ea04:
        if ((this->m_isPlatformer & 1U) == 0) goto LAB_10037ea88;
        bVar17 = 1;
LAB_10037ea68:
        bVar17 = bVar27 & bVar17 ^ 1;
        bVar3 = true;
      }
      else {
        bVar17 = 1;
        if ((bVar25 & 1) != 0) goto LAB_10037ea04;
LAB_10037ea60:
        if ((bVar17 & 1) != 0) {
          bVar17 = this->m_isPlatformer;
          goto LAB_10037ea68;
        }
LAB_10037ea88:
        bVar3 = false;
        bVar17 = 0;
      }
      bVar18 = 0;
      bVar24 = false;
      uVar12 = 0;
      if (!bVar8) goto LAB_10037ec60;
LAB_10037eaa0:
      bVar18 = 0;
      bVar24 = false;
      bVar4 = object->m_slopeIsHazard;
      goto joined_r0x00010037eaa4;
    }
    bVar8 = fStack_ec != fVar29 && !bVar8;
    if (bVar8 || ((bVar18 ^ 1) & 1) != 0) goto LAB_10037e9d8;
    if (fStack_ec <= fVar29 - fVar42) goto LAB_10037e9d4;
    if (this->m_isBird != true) goto LAB_10037ea14;
    bVar8 = 0.0 <= this->m_yVelocity;
    bVar17 = this->m_jumpBuffered;
joined_r0x00010037e9dc:
    if ((bVar17 & 1) != 0) goto LAB_10037e9e0;
LAB_10037ea20:
    bVar3 = false;
    bVar18 = 0;
    bVar17 = 0;
    bVar24 = false;
    uVar12 = 0;
    if (bVar8) goto LAB_10037eaa0;
LAB_10037ec60:
    cVar16 = this->m_isSideways;
  }
  else {
    fVar30 = (fVar30 + fStack_ac * 0.5) - fVar33;
    fVar33 = (fVar40 + (float)dVar36) - fVar33;
    bVar7 = fVar30 <= fVar33;
    if (!bVar7) {
      fVar30 = fVar33;
    }
    bVar6 = fVar30 <= fVar29;
    if (fVar29 < fVar30) {
      fVar29 = fVar30;
    }
    if ((this->m_isUpsideDown & 1U) == 0) goto LAB_10037e8c0;
LAB_10037e838:
    fVar33 = 0.0;
    if ((bVar25 & 1) == 0) {
      if ((((this->m_isShip & 1U) != 0) || ((this->m_isBird & 1U) != 0)) ||
         (((this->m_isDart & 1U) != 0 || (this->m_isSwing == true)))) {
        fVar33 = fVar42;
        if ((this->m_jumpBuffered == true) && (fVar33 = 2.0, this->m_wasOnSlope == false)) {
          fVar33 = 1.0;
        }
        goto LAB_10037e888;
      }
      if (bVar27 == 0) goto LAB_10037eab4;
LAB_10037e88c:
      bVar17 = 1;
    }
    else {
LAB_10037e888:
      fVar42 = fVar33;
      if (bVar27 != 0) goto LAB_10037e88c;
LAB_10037eab4:
      bVar17 = bVar25;
      if ((((this->m_isShip & 1U) == 0) && ((this->m_isBird & 1U) == 0)) &&
         ((this->m_isDart & 1U) == 0)) {
        bVar17 = this->m_isSwing & bVar25;
      }
      if (((bVar17 & 1) != 0) && (this->m_isPlatformer != true)) goto LAB_10037e88c;
      bVar17 = this->m_isOnSlope;
    }
    bVar8 = fStack_ec < fVar29;
    if (fStack_ec >= fVar29 && (bVar17 & 1) == 0) {
      bVar8 = fStack_ec < fVar29 + fVar42;
    }
    bVar3 = fVar29 < fStack_ec;
    if (fVar29 >= fStack_ec && (bVar17 & 1) == 0) {
      bVar3 = fVar29 - fVar42 < fStack_ec;
    }
    if (bVar10) {
      bVar8 = bVar3;
    }
    if ((this->m_jumpBuffered & 1U) == 0) {
      bVar3 = this->m_isShip;
      bVar18 = bVar25;
      if (this->m_isPlatformer == true) {
joined_r0x00010037eba0:
        bVar17 = 0;
        if ((bVar3 & 1U) == 0) {
LAB_10037eba4:
          bVar18 = bVar25;
          if ((this->m_isBird & 1U) == 0) goto LAB_10037ebac;
        }
      }
      else {
        if ((((bVar3 & 1U) != 0) || ((this->m_isBird & 1U) != 0)) ||
           (((this->m_isDart & 1U) != 0 || ((this->m_isSwing & 1U) != 0)))) {
          if ((bVar25 & 1) != 0) goto LAB_10037eb88;
          bVar18 = 0;
          goto joined_r0x00010037eba0;
        }
        if ((this->m_isBall & bVar25 & 1) != 0) {
LAB_10037eb88:
          bVar17 = this->m_wasOnSlope;
          if ((bVar3 & 1U) != 0) goto joined_r0x00010037eb40;
          goto LAB_10037eba4;
        }
        bVar17 = 0;
        if ((this->m_isBird & 1U) != 0) goto joined_r0x00010037eb40;
LAB_10037ebac:
        bVar18 = bVar25;
        if ((this->m_isDart & 1U) == 0) {
          bVar18 = this->m_isSwing & bVar25;
        }
      }
    }
    else {
      bVar17 = 0;
      bVar18 = 0;
    }
joined_r0x00010037eb40:
    if (bVar8) {
      if (((((((this->m_isShip & 1U) == 0) && ((this->m_isBird & 1U) == 0)) &&
            ((this->m_isDart & 1U) == 0)) &&
           (((this->m_isSwing & 1U) == 0 && ((this->m_isBall & 1U) == 0)))) &&
          ((this->m_isPlatformer & 1U) == 0)) && (this->m_stateHitHead < 1)) {
        if (((this->m_gameModeChangedTime != 0.0) &&
            (this->m_totalTime - this->m_gameModeChangedTime < 0.10000000149011612)) ||
           ((this->m_lastFlipTime != 0.0 &&
            (this->m_totalTime - this->m_lastFlipTime < 0.10000000149011612)))) {
          puVar15 = (undefined4 *)getPosition/*virtual+0xc0*/(this);
          CCPoint__CCPoint(*puVar15,fVar29,apfStack_e8);
          setPosition/*virtual+0xb8*/(this,apfStack_e8);
          dVar35 = this->m_yVelocity;
          if ((this->m_isUpsideDown & 1U) == 0) {
            dVar36 = -2.0;
            if (dVar35 <= -2.0) goto LAB_10037f854;
          }
          else {
            dVar36 = 2.0;
            if (2.0 <= dVar35) {
LAB_10037f854:
              dVar36 = dVar35;
            }
          }
          dVar35 = (double)(int)dVar36;
          if (dVar36 != dVar35) {
            dVar36 = (double)(long)((dVar36 - dVar35) * 1000.0) / 1000.0 + dVar35;
          }
          this->m_yVelocity = dVar36;
LAB_10037f88c:
          this->m_isOnGround = false;
          this->m_isOnGround2 = false;
          return;
        }
        if (bVar10) {
          if (fStack_ec + -2.0 <= fVar29) goto LAB_10037f88c;
        }
        else if (fVar29 <= fStack_ec + 2.0) goto LAB_10037f88c;
        if ((this->m_ignoreDamage & 1U) == 0) goto LAB_10037ec14;
      }
      bVar3 = false;
      bVar24 = true;
      bVar4 = object->m_slopeIsHazard;
joined_r0x00010037eaa4:
      if ((((bVar4 & 1) != 0) ||
          ((((bVar27 != 0 || ((this->m_isDart == true && (this->m_stateDartSlide < 1)))) &&
            ((this->m_isPlatformer & 1U) == 0)) && (this->m_stateHitHead < 1)))) &&
         ((this->m_ignoreDamage & 1U) == 0)) {
LAB_10037ec14:
        if ((this->m_maybeCanRunIntoBlocks & 1U) != 0) {
          this->m_maybeIsColliding = true;
          return;
        }
        lVar14 = GameManager__sharedState();
        (**(code **)(**(long **)(lVar14 + 0x1f8) + 0x4f8))(*(long **)(lVar14 + 0x1f8),this,0);
        return;
      }
      uVar12 = 1;
      goto LAB_10037ec60;
    }
    uVar12 = 0;
    bVar3 = false;
    bVar24 = true;
    cVar16 = this->m_isSideways;
  }
  if ((cVar16 == '\x01') && (uVar20 = *(ulong *)(this->m_rotateObjectsRelated + 8), uVar20 != 0)) {
    fVar42 = (float)object->m_uniqueID;
    uVar19 = (ulong)(int)fVar42;
    uVar13 = CONCAT17(POPCOUNT((char)(uVar20 >> 0x38)),
                      CONCAT16(POPCOUNT((char)(uVar20 >> 0x30)),
                               CONCAT15(POPCOUNT((char)(uVar20 >> 0x28)),
                                        CONCAT14(POPCOUNT((char)(uVar20 >> 0x20)),
                                                 CONCAT13(POPCOUNT((char)(uVar20 >> 0x18)),
                                                          CONCAT12(POPCOUNT((char)(uVar20 >> 0x10)),
                                                                   CONCAT11(POPCOUNT((char)(uVar20 
                                                  >> 8)),POPCOUNT((char)uVar20))))))));
    uVar28 = NEON_uaddlv(uVar13,1);
    uVar23 = CONCAT62((int6)((ulong)uVar13 >> 0x10),uVar28) & 0xffffffff;
    if (uVar23 < 2) {
      uVar21 = uVar20 - 1 & uVar19;
    }
    else {
      uVar21 = uVar19;
      if (uVar20 <= uVar19) {
        uVar21 = 0;
        if (uVar20 != 0) {
          uVar21 = uVar19 / uVar20;
        }
        uVar21 = uVar19 - uVar21 * uVar20;
      }
    }
    plVar22 = *(long **)(*(long *)this->m_rotateObjectsRelated + uVar21 * 8);
    if ((plVar22 != (long *)0x0) && (plVar22 = (long *)*plVar22, plVar22 != (long *)0x0)) {
      if (uVar23 < 2) {
        do {
          if (plVar22[1] == uVar19) {
            if (*(float *)(plVar22 + 2) == fVar42) goto LAB_10037ee80;
          }
          else if ((plVar22[1] & uVar20 - 1) != uVar21) break;
          plVar22 = (long *)*plVar22;
        } while (plVar22 != (long *)0x0);
      }
      else {
        do {
          uVar23 = plVar22[1];
          if (uVar23 == uVar19) {
            if (*(float *)(plVar22 + 2) == fVar42) goto LAB_10037ee80;
          }
          else {
            if (uVar20 <= uVar23) {
              uVar5 = 0;
              if (uVar20 != 0) {
                uVar5 = uVar23 / uVar20;
              }
              uVar23 = uVar23 - uVar5 * uVar20;
            }
            if (uVar23 != uVar21) break;
          }
          plVar22 = (long *)*plVar22;
        } while (plVar22 != (long *)0x0);
      }
    }
  }
  fVar42 = fVar29;
  if (this->m_wasOnSlope == true) goto LAB_10037edb8;
LAB_10037ef04:
  if ((uVar12 & this->m_isPlatformer) == 1) {
    CCRect__CCRect(fStack_b8 + -2.0,fStack_b4 + -10.0,fStack_b0 + 4.0,fStack_ac + 20.0,
                        apfStack_e8);
    uVar12 = CCRect__intersectsRect(&uStack_c8,apfStack_e8);
  }
LAB_10037ef58:
  if ((((bVar25 & 1) != 0) && (this->m_isDart == true)) && (this->m_jumpBuffered == true)) {
    uVar12 = this->m_isUpsideDown != bVar10 & uVar12;
  }
  if (uVar12 == 0) {
    return;
  }
  *(GameObject **)this->m_currentSlope = object;
  fVar34 = GameObject__getSlopeAngle(object);
  this->m_slopeAngleRadians = fVar34;
  *(undefined8 *)this->m_currentPotentialSlope = *(undefined8 *)this->m_currentSlope;
  fStack_f8 = (float)object->m_uniqueID;
  apfStack_e8[0] = &fStack_f8;
  lVar14 = unordered_map_int_GameObject__emplace(this->m_potentialSlopeMap,&fStack_f8,&UNK_10072382e,apfStack_e8,
                               &fStack_100);
  *(GameObject **)(lVar14 + 0x18) = object;
  this->unk_584 = (double)(fVar40 + fStack_ac * -0.5);
  this->m_isCurrentSlopeTop = bVar10;
  this->m_unk3d0 = (double)fVar29;
  this->m_blackOrbRelated = (double)fVar42;
  this->m_collidingWithSlopeId = object->m_uniqueID;
  iVar11 = 1;
  if (this->m_isUpsideDown != false) {
    iVar11 = -1;
  }
  this->m_slopeFlipGravityRelated = (bool)(bVar25 & 1);
  dVar36 = this->m_slopeRotation;
  this->m_unk3e0 = bVar7;
  this->m_unk3e1 = bVar6;
  iVar1 = -iVar11;
  if ((bool)(bVar25 & 1) != false) {
    iVar1 = iVar11;
  }
  iVar11 = -iVar1;
  if ((double)fStack_cc <= dVar35 * (double)dt) {
    iVar11 = iVar1;
  }
  iVar1 = -iVar11;
  if (!bVar9) {
    iVar1 = iVar11;
  }
  iVar11 = -iVar1;
  if (this->m_isSideways == false) {
    iVar11 = iVar1;
  }
  this->m_slopeRotation = (double)(fVar31 * 57.29578 * (float)iVar11 * 0.017453292);
  uVar13 = getPosition/*virtual+0xc0*/(this);
  CCPoint__CCPoint_copy(apfStack_e8,uVar13);
  puVar15 = (undefined4 *)getPosition/*virtual+0xc0*/(this);
  CCPoint__CCPoint(*puVar15,fVar29,&fStack_f8);
  setPosition/*virtual+0xb8*/(this,&fStack_f8);
  this->m_isOnSlope = true;
  if ((this->m_wasOnSlope & 1U) == 0) {
    this->m_slopeStartTime = this->m_totalTime;
    this->m_yVelocityBeforeSlope = this->m_yVelocity;
  }
  this->m_maybeUpsideDownSlope = bVar24;
  if ((bVar17 & 1) == 0) {
    if (bVar24 == false) {
      dVar35 = this->m_yVelocity;
      fVar34 = (float)dVar35;
      PlayerObject__hitGround(this,object,false);
      bVar9 = fVar34 < -5.0;
      if (this->m_isUpsideDown == false) {
        bVar9 = 5.0 < fVar34;
      }
      if (bVar9) {
        dVar38 = (double)fVar34;
        dVar35 = (double)(int)dVar35;
        if (dVar35 != dVar38) {
          dVar38 = (double)(long)((dVar38 - dVar35) * 1000.0) / 1000.0 + dVar35;
        }
        this->m_yVelocity = dVar38;
      }
      if (((this->m_isPlatformer == true) && (40.0 < ABS(this->m_slopeAngleRadians * 57.29578))) &&
         ((fVar34 < -5.0 && (0.0 < this->m_platformerXVelocity)))) {
        this->m_platformerXVelocity = this->m_platformerXVelocity * 0.5;
      }
      lVar14 = getObjectRect/*virtual+0x520*/(this);
      fVar42 = *(float *)(lVar14 + 0xc);
      getObjectRect/*virtual+0x520*/(this);
      lVar14 = getPosition/*virtual+0xc0*/(this);
      fVar34 = -1.0;
      if (this->m_isUpsideDown == false) {
        fVar34 = 1.0;
      }
      iVar11 = object->m_uniqueID;
      dVar38 = this->m_collidedBottomMaxY;
      dVar35 = (double)(*(float *)(lVar14 + 4) + fVar34 * fVar42 * -0.5);
      if (dVar38 != 0.0) {
        if ((this->m_isUpsideDown & 1U) == 0) {
          if (dVar35 <= dVar38) {
            dVar35 = dVar38;
          }
        }
        else if (dVar38 == dVar35 || dVar35 > dVar38) {
          dVar35 = dVar38;
        }
      }
      this->m_collidedBottomMaxY = dVar35;
      if ((iVar11 != 0) && (this->m_lastCollisionBottom != iVar11)) {
        this->m_lastCollisionBottom = iVar11;
        if (*(long *)this->m_collisionLogBottom != 0) {
          CCDictionary__setObject(*(long *)this->m_collisionLogBottom,
                              *(undefined8 *)this->m_maybeLastGroundObject,(long)iVar11);
        }
      }
      *(GameObject **)this->m_currentSlope2 = object;
      fVar34 = GameObject__getSlopeAngle(object);
      this->m_slopeAngle = fVar34;
      bVar17 = *(byte *)(*(long *)this->m_currentSlope2 + 0x438);
      this->m_slopeSlidingMaybeRotated = (bool)bVar17;
      if (this->m_isSideways == true) {
        bVar17 = bVar17 ^ 1;
        this->m_slopeSlidingMaybeRotated = (bool)bVar17;
      }
      if ((bVar17 != 0) && (1.0 <= fVar34)) {
        this->m_maybeSlidingTime = 3;
      }
      uVar13 = GameObject__getLastPosition(object);
      CCPoint__CCPoint_copy(&fStack_f8,uVar13);
      getRealPosition/*virtual+0x540*/(&fStack_100,object);
      if ((fStack_100 != fStack_f8) || (fStack_fc != fStack_f4)) {
        fVar34 = fStack_f8;
        if (this->m_isUpsideDown == false) {
          fStack_100 = fStack_fc;
          fVar34 = fStack_f4;
        }
        bVar9 = fVar34 != fStack_100 && fVar34 >= fStack_100;
        if (this->m_isUpsideDown == false) {
          bVar9 = fVar34 < fStack_100;
        }
        if (bVar9) {
          this->m_groundYVelocity = (double)((fStack_100 - fVar34) / dt);
        }
      }
    }
    else {
      dVar38 = this->m_yVelocity;
      dVar35 = 0.0;
      if ((this->m_isUpsideDown & 1U) == 0) {
        if (dVar38 <= 0.0) goto LAB_10037f148;
      }
      else if (0.0 <= dVar38) {
LAB_10037f148:
        dVar35 = dVar38;
      }
      dVar38 = (double)(int)dVar35;
      if (dVar35 != dVar38) {
        dVar35 = (double)(long)((dVar35 - dVar38) * 1000.0) / 1000.0 + dVar38;
      }
      this->m_yVelocity = dVar35;
      this->m_isOnGround = false;
      this->m_isOnGround2 = false;
      lVar14 = getObjectRect/*virtual+0x520*/(this);
      fVar34 = *(float *)(lVar14 + 0xc);
      getObjectRect/*virtual+0x520*/(this);
      lVar14 = getPosition/*virtual+0xc0*/(this);
      fVar42 = -1.0;
      if (this->m_isUpsideDown == false) {
        fVar42 = 1.0;
      }
      iVar11 = object->m_uniqueID;
      dVar38 = this->m_collidedTopMinY;
      dVar35 = (double)(*(float *)(lVar14 + 4) + fVar42 * fVar34 * 0.5);
      if (dVar38 != 0.0) {
        dVar39 = dVar35;
        if (dVar35 <= dVar38) {
          dVar39 = dVar38;
        }
        dVar37 = dVar35;
        if (dVar38 <= dVar35) {
          dVar37 = dVar38;
        }
        dVar35 = dVar39;
        if ((this->m_isUpsideDown & 1U) == 0) {
          dVar35 = dVar37;
        }
      }
      this->m_collidedTopMinY = dVar35;
      if ((iVar11 != 0) && (this->m_lastCollisionTop != iVar11)) {
        this->m_lastCollisionTop = iVar11;
        if (*(long *)this->m_collisionLogTop != 0) {
          CCDictionary__setObject(*(long *)this->m_collisionLogTop,
                              *(undefined8 *)this->m_maybeLastGroundObject,(long)iVar11);
        }
      }
    }
  }
  bVar17 = this->m_isUpsideDown;
  if ((bVar18 & 1) != 0) {
    if ((bVar17 & 1) == 0) {
      dVar35 = -2.0;
      if (-2.0 < this->m_yVelocity) goto LAB_10037f244;
    }
    else {
      dVar35 = 2.0;
      if (this->m_yVelocity < 2.0) {
LAB_10037f244:
        dVar38 = (double)(int)dVar35;
        if (dVar35 != dVar38) {
          dVar35 = (double)(long)((dVar35 - dVar38) * 1000.0) / 1000.0 + dVar38;
        }
        this->m_yVelocity = dVar35;
      }
    }
  }
  if (bVar3) {
    if ((bVar17 & 1) == 0) {
      dVar35 = 2.0;
      if (2.0 <= this->m_yVelocity) {
        bVar17 = 0;
        goto LAB_10037f438;
      }
    }
    else {
      dVar35 = -2.0;
      if (this->m_yVelocity <= -2.0) {
        bVar17 = 1;
        goto LAB_10037f438;
      }
    }
    dVar38 = (double)(int)dVar35;
    if (dVar35 != dVar38) {
      dVar35 = (double)(long)((dVar35 - dVar38) * 1000.0) / 1000.0 + dVar38;
    }
    this->m_yVelocity = dVar35;
  }
LAB_10037f438:
  this->m_currentSlopeYVelocity = (double)fVar41;
  fVar42 = (float)NEON_fminnm(0.8 / fVar31,0x3f8ccccd);
  fVar34 = fVar41 * 1.4 * fVar42;
  if (((bVar26 | bVar25 ^ 0xff) & 1) == 0) {
    fVar34 = -(fVar41 * 1.4 * fVar42);
  }
  fVar42 = -fVar34;
  if ((bVar17 & 1) == 0) {
    fVar42 = fVar34;
  }
  this->m_slopeVelocity = fVar42;
  if (((bVar24 & this->m_isPlatformer) == 1) && (this->m_isBird == true)) {
    this->m_jumpBuffered = false;
  }
  if ((((((this->m_isShip & 1U) == 0) && ((this->m_isBird & 1U) == 0)) &&
       ((this->m_isDart & 1U) == 0)) && (((this->m_isSwing & 1U) == 0 && (this->m_isBall != true))))
     || (this->m_slopeVelocity = fVar42 * 0.75, (this->m_isBall & 1U) == 0)) {
    PlayerObject__updateSlopeRotation(this,dt);
  }
  else if (this->m_slopeRotation != (double)(float)dVar36) {
    this->m_isRotating = false;
    this->m_isBallRotating2 = false;
    this->m_isBallRotating = false;
    this->m_rotationSpeed = 0.0;
    if (((this->m_isDashing | this->m_isPlatformer) & 1U) == 0) {
      fVar42 = (float)_cosf((float)this->m_slopeRotation);
      fVar42 = 1.0 / fVar42;
      fVar34 = (fVar42 + -1.0) * 0.7 + 1.0;
      if (fVar42 <= 2.0) {
        fVar34 = fVar42;
      }
      this->m_isBallRotating = fVar34 != 1.0;
      this->m_rotateSpeed = fVar34;
      fVar34 = this->m_playerSpeed;
      if (fVar34 == 0.7) {
        fVar34 = 1.2405638;
      }
      else if (fVar34 == 1.1) {
        fVar34 = 0.80424345;
      }
      else if (fVar34 == 1.3) {
        fVar34 = 0.6657693;
      }
      else if (fVar34 == 1.6) {
        fVar34 = 0.5409375;
      }
      else {
        fVar34 = 1.0;
      }
      iVar11 = 0x78;
      if ((bVar17 & 1) != 0) {
        iVar11 = -0x78;
      }
      iVar1 = -iVar11;
      if (this->m_isGoingLeft == false) {
        iVar1 = iVar11;
      }
      fVar42 = 0.2;
      if (this->m_vehicleSize != 1.0) {
        fVar42 = 0.16000001;
      }
      fVar34 = (float)iVar1 / (fVar42 * fVar34);
      this->m_rotationSpeed = fVar34;
      if (this->m_isSideways == true) {
        this->m_rotationSpeed = -fVar34;
      }
      this->m_isRotating = true;
    }
  }
  return;
LAB_10037ee80:
  apfStack_e8[0] = &fStack_f8;
  fStack_f8 = fVar42;
  lVar14 = unordered_map_int_GJPointDouble__emplace(this->m_rotateObjectsRelated,&fStack_f8,&UNK_10072382e,apfStack_e8,
                               &fStack_100);
  fVar42 = (float)((double)fVar29 - *(double *)(lVar14 + 0x20));
  if (this->m_wasOnSlope != true) goto LAB_10037ef04;
LAB_10037edb8:
  if (((this->m_unk3d0 != (double)fVar29) &&
      ((this->m_isSideways != true || (this->m_blackOrbRelated != (double)fVar42)))) ||
     ((this->m_isPlatformer == true && (ABS(this->m_platformerXVelocity) < 0.10000000149011612)))) {
    if (fVar34 != 0.0) {
      if ((bVar7) && ((this->m_unk3e0 & 1U) != 0)) {
LAB_10037ee38:
        if (((this->m_isDashing & 1U) == 0) &&
           ((this->m_isPlatformer != true ||
            (0.10000000149011612 < ABS(this->m_platformerXVelocity))))) goto LAB_10037edf0;
      }
      else if (bVar6) {
        if (this->m_unk3e1 == true) goto LAB_10037ee38;
        bVar6 = true;
      }
    }
    goto LAB_10037ef04;
  }
LAB_10037edf0:
  uVar12 = 0;
  goto LAB_10037ef58;
}


// ==== PlayerObject::handleRotatedSlopeCollision @ 0x37e0e8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PlayerObject__handleRotatedSlopeCollision
               (PlayerObject *this,float dt,GameObject *object,bool skipPre)

{
  float in_s1;
  float in_s2;
  undefined4 in_s3;
  undefined4 in_s4;
  CCRect rect;
  undefined1 auStack_50 [16];
  
  CCRect__CCRect_copy(auStack_50,0x1008b88b0);
  rect.origin.y = in_s2;
  rect.origin.x = in_s1;
  rect.height = (float)in_s4;
  rect.width = (float)in_s3;
  PlayerObject__handleRotatedCollisionInternal
            (this,dt,object,rect,SUB81(auStack_50,0),false,skipPre);
  return;
}


// ==== PlayerObject::handleRotatedCollisionInternal @ 0x37df88

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

bool PlayerObject__handleRotatedCollisionInternal
               (PlayerObject *this,float dt,GameObject *object,CCRect rect,bool skipCheck,
               bool skipPre,bool slope)

{
  bool bVar1;
  undefined8 uVar2;
  int in_w5;
  long *plVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  CCRect rect_00;
  undefined1 auStack_80 [8];
  float fStack_78;
  float fStack_74;
  float fStack_68;
  float fStack_64;
  
  fVar7 = rect.height;
  fVar6 = rect.width;
  fVar5 = rect.origin.y;
  fVar4 = rect.origin.x;
  uVar2 = getPosition/*virtual+0xc0*/();
  CCPoint__CCPoint_copy(&fStack_68,uVar2);
  PlayerObject__rotateGameplayObject(this,object);
  for (plVar3 = *(long **)(this->m_potentialSlopeMap + 0x10); plVar3 != (long *)0x0;
      plVar3 = (long *)*plVar3) {
    PlayerObject__rotateGameplayObject(this,(GameObject *)plVar3[3]);
  }
  if (in_w5 == 0) {
    CCRect__CCRect_copy(&fStack_78,skipCheck);
    rect_00.origin.y = fVar5;
    rect_00.origin.x = fVar4;
    rect_00.height = fVar7;
    rect_00.width = fVar6;
    bVar1 = PlayerObject__collidedWithObjectInternal(this,dt,object,rect_00,SUB81(&fStack_78,0));
  }
  else {
    PlayerObject__collidedWithSlopeInternal(this,dt,object,slope);
    bVar1 = false;
  }
  uVar2 = getPosition/*virtual+0xc0*/(this);
  CCPoint__CCPoint_copy(&fStack_78,uVar2);
  CCPoint__CCPoint(fStack_68 + (fStack_74 - fStack_64),fStack_64 - (fStack_78 - fStack_68),
                      auStack_80);
  setPosition/*virtual+0xb8*/(this,auStack_80);
  PlayerObject__unrotateGameplayObject(this,object);
  for (plVar3 = *(long **)(this->m_potentialSlopeMap + 0x10); plVar3 != (long *)0x0;
      plVar3 = (long *)*plVar3) {
    PlayerObject__unrotateGameplayObject(this,(GameObject *)plVar3[3]);
  }
  return bVar1;
}


// ==== PlayerObject::preSlopeCollision @ 0x3819b0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

bool PlayerObject__preSlopeCollision(PlayerObject *this,float dt,GameObject *object)

{
  bool bVar1;
  bool bVar2;
  byte bVar3;
  int iVar4;
  undefined8 uVar5;
  float *pfVar6;
  long lVar7;
  GameObject *this_00;
  byte bVar8;
  float fVar9;
  float fVar10;
  ulong uVar12;
  float fVar13;
  undefined4 uVar14;
  float in_s4;
  float fVar15;
  CCRect rect;
  CCRect rect_00;
  int iStack_b4;
  int *apiStack_b0 [2];
  undefined1 auStack_9c [4];
  float fStack_98;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  undefined1 auStack_84 [16];
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  undefined1 uStack_61;
  ulong uVar11;
  
  if (object->m_uniqueID == this->m_collidingWithSlopeId) {
    return false;
  }
  uVar5 = getObjectRect/*virtual+0x520*/(object);
  CCRect__CCRect_copy(&fStack_74,uVar5);
  uVar5 = getObjectRect/*virtual+0x520*/(this);
  CCRect__CCRect_copy(auStack_84,uVar5);
  bVar1 = GameObject__slopeWallLeft(object);
  bVar2 = GameObject__slopeFloorTop(object);
  fVar13 = 0.0;
  if (((this->m_isPlatformer == true) && (fVar13 = 5.0, (this->m_isOnSlope & 1U) == 0)) &&
     (fVar13 = 5.0, this->m_wasOnSlope == false)) {
    fVar13 = 0.0;
  }
  getRealPosition/*virtual+0x540*/(auStack_9c,object);
  uVar5 = GameObject__getLastPosition(object);
  CCPoint__operator_minus(&fStack_8c,auStack_9c,uVar5);
  pfVar6 = &fStack_88;
  if (this->m_isSideways == false) {
    pfVar6 = &fStack_8c;
  }
  fVar9 = (float)(this->m_speedMultiplier * (double)this->m_playerSpeed * (double)dt);
  if (bVar1) {
    if ((((this->m_isGoingLeft != false) && ((this->m_isPlatformer & 1U) == 0)) &&
        (fVar9 <= *pfVar6)) ||
       (pfVar6 = (float *)getPosition/*virtual+0xc0*/(this),
       fStack_74 <= *pfVar6)) goto LAB_100381c78;
    fVar9 = 0.0;
    if (this->m_isGoingLeft == true) {
      fVar9 = (float)(this->m_isPlatformer ^ 1);
    }
    fVar10 = fVar13 + fVar9 + fStack_70;
    fVar13 = fStack_68 + (fVar13 + fVar9) * -2.0;
    in_s4 = -2.0;
    fVar15 = fStack_74;
LAB_100381bac:
    uVar11 = (ulong)(uint)fVar10;
    uVar5 = 0x3f800000;
    CCRect__CCRect(fVar15,auStack_9c);
    iVar4 = CCRect__intersectsRect(auStack_84,auStack_9c);
    if (iVar4 != 0) {
      CCRect__CCRect_copy(apiStack_b0,auStack_9c);
      rect.origin.x = (float)uVar11;
      rect.origin.y = (float)uVar5;
      rect.height = in_s4;
      rect.width = fVar13;
      PlayerObject__collidedWithObjectInternal(this,dt,object,rect,SUB81(apiStack_b0,0));
    }
    bVar1 = true;
    CCRect__CCRect_zero(auStack_9c);
    if (bVar2) goto LAB_100381c8c;
LAB_100381bfc:
    uVar14 = 0x3f800000;
    CCRect__CCRect(fVar9 + fStack_74,fStack_70,fStack_6c + fVar9 * -2.0,apiStack_b0);
    CCRect__operator_assign(auStack_9c,apiStack_b0);
    lVar7 = getPosition/*virtual+0xc0*/(this);
    fStack_98 = fStack_98 + fStack_90;
    if (fStack_98 < *(float *)(lVar7 + 4)) goto LAB_100381c50;
LAB_100381cec:
    uVar12 = (ulong)(uint)fStack_90;
    uVar11 = (ulong)(uint)fStack_98;
    iVar4 = CCRect__intersectsRect(auStack_84,auStack_9c);
    if (iVar4 != 0) {
      CCRect__CCRect_copy(apiStack_b0,auStack_9c);
      rect_00.origin.x = (float)uVar11;
      rect_00.origin.y = (float)uVar12;
      rect_00.height = in_s4;
      rect_00.width = (float)uVar14;
      PlayerObject__collidedWithObjectInternal(this,dt,object,rect_00,SUB81(apiStack_b0,0));
      bVar8 = 1;
      goto LAB_100381d2c;
    }
  }
  else {
    if ((((this->m_isGoingLeft & 1U) != 0) || ((this->m_isPlatformer & 1U) != 0)) ||
       (fVar9 < *pfVar6)) {
      pfVar6 = (float *)getPosition/*virtual+0xc0*/(this);
      fVar15 = *pfVar6;
      fVar9 = (float)CCRect__getMaxX(&fStack_74);
      if (fVar9 < fVar15) {
        fVar9 = 0.0;
        if ((this->m_isGoingLeft & 1U) == 0) {
          fVar9 = (float)(this->m_isPlatformer ^ 1);
        }
        fVar15 = fStack_74 + fStack_6c + -1.0;
        fVar10 = fVar13 + fVar9 + fStack_70;
        fVar13 = fStack_68 + (fVar13 + fVar9) * -2.0;
        in_s4 = fStack_68;
        goto LAB_100381bac;
      }
    }
LAB_100381c78:
    bVar1 = false;
    fVar9 = 0.0;
    CCRect__CCRect_zero(auStack_9c);
    if (!bVar2) goto LAB_100381bfc;
LAB_100381c8c:
    uVar14 = 0x3f800000;
    CCRect__CCRect(fVar9 + fStack_74,fStack_70 + fStack_68 + -1.0,fStack_6c + fVar9 * -2.0,
                        apiStack_b0);
    CCRect__operator_assign(auStack_9c,apiStack_b0);
    lVar7 = getPosition/*virtual+0xc0*/(this);
    fStack_98 = fStack_98 + fStack_90;
    if (fStack_98 <= *(float *)(lVar7 + 4)) goto LAB_100381cec;
LAB_100381c50:
    if (!bVar1) {
      this->m_unk669 = false;
      if ((this->m_isOnSlope & 1U) == 0) {
        iStack_b4 = object->m_uniqueID;
        apiStack_b0[0] = &iStack_b4;
        lVar7 = unordered_map_int_GameObject__emplace(this->m_potentialSlopeMap,&iStack_b4,&UNK_10072382e,apiStack_b0,
                                    &uStack_61);
        *(GameObject **)(lVar7 + 0x18) = object;
        this_00 = *(GameObject **)this->m_currentPotentialSlope;
        if (this_00 == (GameObject *)0x0) {
LAB_100381e3c:
          bVar8 = 0;
          *(GameObject **)this->m_currentPotentialSlope = object;
          goto LAB_100381d2c;
        }
        if (((this_00->m_slopeUphill != true) || (bVar1 = GameObject__slopeFloorTop(this_00), bVar1)
            ) && ((object->m_slopeUphill != true ||
                  (bVar1 = GameObject__slopeFloorTop(object), bVar1)))) {
          pfVar6 = (float *)(**(code **)(**(long **)this->m_currentPotentialSlope + 0xc0))();
          fVar13 = *pfVar6;
          pfVar6 = (float *)getPosition/*virtual+0xc0*/(object);
          if (*pfVar6 < fVar13) goto LAB_100381e3c;
        }
        if (((*(GameObject **)this->m_currentPotentialSlope)->m_slopeUphill == true) &&
           (bVar1 = GameObject__slopeFloorTop(*(GameObject **)this->m_currentPotentialSlope), !bVar1
           )) {
          pfVar6 = (float *)(**(code **)(**(long **)this->m_currentPotentialSlope + 0xc0))();
          fVar13 = *pfVar6;
          pfVar6 = (float *)getPosition/*virtual+0xc0*/(object);
          if (fVar13 < *pfVar6) goto LAB_100381e3c;
        }
      }
      bVar8 = 0;
      goto LAB_100381d2c;
    }
  }
  bVar8 = 1;
LAB_100381d2c:
  bVar3 = CCRect__intersectsRect(&fStack_74,auStack_84);
  return (bool)(bVar8 | bVar3 ^ 1);
}


// ==== PlayerObject::rotatePreSlopeObjects @ 0x37e3ac

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PlayerObject__rotatePreSlopeObjects(PlayerObject *this)

{
  long *plVar1;
  
  for (plVar1 = *(long **)(this->m_potentialSlopeMap + 0x10); plVar1 != (long *)0x0;
      plVar1 = (long *)*plVar1) {
    PlayerObject__rotateGameplayObject(this,(GameObject *)plVar1[3]);
  }
  return;
}


// ==== PlayerObject::unrotatePreSlopeObjects @ 0x381978

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PlayerObject__unrotatePreSlopeObjects(PlayerObject *this)

{
  long *plVar1;
  
  for (plVar1 = *(long **)(this->m_potentialSlopeMap + 0x10); plVar1 != (long *)0x0;
      plVar1 = (long *)*plVar1) {
    PlayerObject__unrotateGameplayObject(this,(GameObject *)plVar1[3]);
  }
  return;
}


// ==== PlayerObject::rotateGameplayObject @ 0x37e158

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PlayerObject__rotateGameplayObject(PlayerObject *this,GameObject *object)

{
  ulong uVar1;
  int iVar2;
  undefined8 uVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  long *plVar7;
  ulong uVar8;
  undefined2 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  float fVar12;
  double dVar13;
  double dVar14;
  float fVar15;
  double dStack_80;
  double dStack_78;
  undefined1 auStack_70 [8];
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  
  uVar6 = *(ulong *)(this->m_rotateObjectsRelated + 8);
  if (uVar6 != 0) {
    iVar2 = object->m_uniqueID;
    uVar4 = (ulong)iVar2;
    uVar3 = CONCAT17(POPCOUNT((char)(uVar6 >> 0x38)),
                     CONCAT16(POPCOUNT((char)(uVar6 >> 0x30)),
                              CONCAT15(POPCOUNT((char)(uVar6 >> 0x28)),
                                       CONCAT14(POPCOUNT((char)(uVar6 >> 0x20)),
                                                CONCAT13(POPCOUNT((char)(uVar6 >> 0x18)),
                                                         CONCAT12(POPCOUNT((char)(uVar6 >> 0x10)),
                                                                  CONCAT11(POPCOUNT((char)(uVar6 >> 
                                                  8)),POPCOUNT((char)uVar6))))))));
    uVar9 = NEON_uaddlv(uVar3,1);
    uVar8 = CONCAT62((int6)((ulong)uVar3 >> 0x10),uVar9) & 0xffffffff;
    if (uVar8 < 2) {
      uVar5 = uVar6 - 1 & uVar4;
    }
    else {
      uVar5 = uVar4;
      if (uVar6 <= uVar4) {
        uVar5 = 0;
        if (uVar6 != 0) {
          uVar5 = uVar4 / uVar6;
        }
        uVar5 = uVar4 - uVar5 * uVar6;
      }
    }
    plVar7 = *(long **)(*(long *)this->m_rotateObjectsRelated + uVar5 * 8);
    if ((plVar7 != (long *)0x0) && (plVar7 = (long *)*plVar7, plVar7 != (long *)0x0)) {
      if (uVar8 < 2) {
        do {
          if (plVar7[1] == uVar4) {
            if ((int)plVar7[2] == iVar2) {
              return;
            }
          }
          else if ((plVar7[1] & uVar6 - 1) != uVar5) break;
          plVar7 = (long *)*plVar7;
        } while (plVar7 != (long *)0x0);
      }
      else {
        do {
          uVar8 = plVar7[1];
          if (uVar8 == uVar4) {
            if ((int)plVar7[2] == iVar2) {
              return;
            }
          }
          else {
            if (uVar6 <= uVar8) {
              uVar1 = 0;
              if (uVar6 != 0) {
                uVar1 = uVar8 / uVar6;
              }
              uVar8 = uVar8 - uVar1 * uVar6;
            }
            if (uVar8 != uVar5) break;
          }
          plVar7 = (long *)*plVar7;
        } while (plVar7 != (long *)0x0);
      }
    }
  }
  getRealPosition/*virtual+0x540*/(&fStack_58,object);
  CCPoint__CCPoint_copy(&fStack_60,&fStack_58);
  uVar3 = getPosition/*virtual+0xc0*/(this);
  CCPoint__CCPoint_copy(&fStack_68,uVar3);
  fVar12 = fStack_58 - fStack_68;
  fStack_58 = fStack_68 + (fVar12 * -4.371139e-08 - (fStack_54 - fStack_64));
  fStack_54 = fStack_64 + fVar12 + (fStack_54 - fStack_64) * -4.371139e-08;
  fVar12 = fStack_58 - fStack_60;
  dVar13 = (double)fVar12;
  fVar15 = fStack_54 - fStack_5c;
  dVar14 = (double)fVar15;
  GameObject__addToTempOffset(dVar13,dVar14,object);
  uVar3 = GameObject__getLastPosition(object);
  CCPoint__CCPoint(fVar12,fVar15,auStack_70);
  CCPoint__operator_plus(&dStack_80,uVar3,auStack_70);
  GameObject__setLastPosition(object,&dStack_80);
  uVar10 = object->m_startRotationX;
  uVar11 = object->m_startRotationY;
  object->m_startRotationX = (float)uVar10 + -90.0;
  object->m_startRotationY = (float)uVar11 + -90.0;
  virtual_0x5b8(0,object);
  virtual_0x6e0(object,1);
  iVar2 = virtual_0x6f8(object);
  if (iVar2 == 0x19) {
    GameObject__determineSlopeDirection(object);
  }
  dStack_80 = dVar13;
  dStack_78 = dVar14;
  func_0x00010039273c(this->m_rotateObjectsRelated,&object->m_uniqueID,&dStack_80);
  return;
}


// ==== PlayerObject::unrotateGameplayObject @ 0x381774

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PlayerObject__unrotateGameplayObject(PlayerObject *this,GameObject *object)

{
  byte *pbVar1;
  ulong uVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  long *plVar9;
  ulong uVar10;
  undefined2 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  int aiStack_44 [2];
  undefined1 uStack_39;
  int *piStack_38;
  
  uVar8 = *(ulong *)(this->m_rotateObjectsRelated + 8);
  if (uVar8 != 0) {
    pbVar1 = this->m_rotateObjectsRelated;
    iVar3 = object->m_uniqueID;
    uVar6 = (ulong)iVar3;
    uVar5 = CONCAT17(POPCOUNT((char)(uVar8 >> 0x38)),
                     CONCAT16(POPCOUNT((char)(uVar8 >> 0x30)),
                              CONCAT15(POPCOUNT((char)(uVar8 >> 0x28)),
                                       CONCAT14(POPCOUNT((char)(uVar8 >> 0x20)),
                                                CONCAT13(POPCOUNT((char)(uVar8 >> 0x18)),
                                                         CONCAT12(POPCOUNT((char)(uVar8 >> 0x10)),
                                                                  CONCAT11(POPCOUNT((char)(uVar8 >> 
                                                  8)),POPCOUNT((char)uVar8))))))));
    uVar11 = NEON_uaddlv(uVar5,1);
    uVar10 = CONCAT62((int6)((ulong)uVar5 >> 0x10),uVar11) & 0xffffffff;
    if (uVar10 < 2) {
      uVar7 = uVar8 - 1 & uVar6;
    }
    else {
      uVar7 = uVar6;
      if (uVar8 <= uVar6) {
        uVar7 = 0;
        if (uVar8 != 0) {
          uVar7 = uVar6 / uVar8;
        }
        uVar7 = uVar6 - uVar7 * uVar8;
      }
    }
    plVar9 = *(long **)(*(long *)pbVar1 + uVar7 * 8);
    if ((plVar9 != (long *)0x0) && (plVar9 = (long *)*plVar9, plVar9 != (long *)0x0)) {
      if (uVar10 < 2) {
        do {
          if (plVar9[1] == uVar6) {
            if ((int)plVar9[2] == iVar3) {
LAB_100381860:
              virtual_0x6e0(object,1);
              aiStack_44[0] = object->m_uniqueID;
              piStack_38 = aiStack_44;
              lVar4 = unordered_map_int_GJPointDouble__emplace(pbVar1,aiStack_44,&UNK_10072382e,&piStack_38,&uStack_39);
              GameObject__addToTempOffset(-*(double *)(lVar4 + 0x18),-*(double *)(lVar4 + 0x20),object);
              uVar5 = GameObject__getLastPosition(object);
              CCPoint__CCPoint(-(float)*(double *)(lVar4 + 0x18),
                                  -(float)*(double *)(lVar4 + 0x20),aiStack_44);
              CCPoint__operator_plus(&piStack_38,uVar5,aiStack_44);
              GameObject__setLastPosition(object,&piStack_38);
              uVar12 = object->m_startRotationX;
              uVar13 = object->m_startRotationY;
              object->m_startRotationX = (float)uVar12 + 90.0;
              object->m_startRotationY = (float)uVar13 + 90.0;
              virtual_0x5b8(0,object);
              iVar3 = virtual_0x6f8(object);
              if (iVar3 == 0x19) {
                GameObject__determineSlopeDirection(object);
              }
              piStack_38 = (int *)CONCAT44(piStack_38._4_4_,object->m_uniqueID);
              func_0x00010004a75c(pbVar1,&piStack_38);
              return;
            }
          }
          else if ((plVar9[1] & uVar8 - 1) != uVar7) {
            return;
          }
          plVar9 = (long *)*plVar9;
        } while (plVar9 != (long *)0x0);
      }
      else {
        do {
          uVar10 = plVar9[1];
          if (uVar10 == uVar6) {
            if ((int)plVar9[2] == iVar3) goto LAB_100381860;
          }
          else {
            if (uVar8 <= uVar10) {
              uVar2 = 0;
              if (uVar8 != 0) {
                uVar2 = uVar10 / uVar8;
              }
              uVar10 = uVar10 - uVar2 * uVar8;
            }
            if (uVar10 != uVar7) {
              return;
            }
          }
          plVar9 = (long *)*plVar9;
        } while (plVar9 != (long *)0x0);
      }
    }
  }
  return;
}


// ==== PlayerObject::updateSlopeRotation @ 0x3827f4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PlayerObject__updateSlopeRotation(PlayerObject *this,float dt)

{
  int iVar1;
  uint uVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  fVar5 = (float)(this->m_slopeRotation * 57.295780181884766);
  fVar4 = fVar5;
  if ((((((this->m_isShip & 1U) == 0) && ((this->m_isBird & 1U) == 0)) &&
       ((this->m_isDart & 1U) == 0)) &&
      (((this->m_isSwing & 1U) == 0 && ((this->m_isRobot & 1U) == 0)))) &&
     (((this->m_isSpider & 1U) == 0 && ((this->m_isDashing & 1U) == 0)))) {
    fVar4 = (float)virtual_0x160();
    uVar2 = (uint)fVar4;
    iVar1 = (-uVar2 / 0x168) * 0x168;
    if ((uVar2 & 0x80000000) == 0) {
      iVar1 = (uVar2 / 0x168) * -0x168;
    }
    fVar6 = (float)(int)(uVar2 + iVar1);
    fVar4 = fVar5;
    fVar3 = fVar5;
    if (fVar5 <= fVar6) {
      while (fVar4 = fVar3, fVar4 < fVar6) {
        fVar5 = fVar4;
        fVar3 = fVar4 + 90.0;
      }
    }
    else {
      do {
        fVar5 = fVar4;
        fVar4 = fVar5 + -90.0;
      } while (fVar6 < fVar4);
    }
    if (ABS(fVar6 - fVar5) <= ABS(fVar6 - fVar4)) {
      fVar4 = fVar5;
    }
  }
  if (((this->m_isPlatformer == true) && (80.0 < this->m_maybeChangedDirectionAngle)) &&
     (((this->m_platformerMovingLeft & 1U) != 0 || (this->m_platformerMovingRight == true)))) {
    fVar4 = 0.0;
  }
  if ((this->m_isDashing & 1U) != 0) {
    return;
  }
  fVar3 = (float)virtual_0x160();
  fVar5 = this->m_playerSpeed * 0.175;
  if (this->m_isShip == true) {
    fVar5 = fVar5 * 0.5;
  }
  else if ((((((this->m_isBird & 1U) == 0) && ((this->m_isDart & 1U) == 0)) &&
            ((this->m_isSwing & 1U) == 0)) &&
           (((this->m_isBall & 1U) == 0 && (this->m_isOnGround2 == true)))) &&
          (((this->m_isOnSlope & 1U) == 0 && (this->m_wasOnSlope == false)))) {
    fVar5 = fVar5 * 3.0;
  }
  fVar6 = fVar5 * dt;
  if (dt <= fVar5 * dt) {
    fVar6 = dt;
  }
  fVar3 = (float)func_0x00010022515c(fVar3 * 0.017453292,fVar4 * 0.017453292,fVar6);
  fVar3 = fVar3 * 57.29578;
  fVar5 = fVar3;
  if ((this->m_isPlatformer == true) &&
     (((((this->m_isShip & 1U) != 0 || ((this->m_isBird & 1U) != 0)) ||
       (((this->m_isDart & 1U) != 0 || (this->m_isSwing == true)))) &&
      ((this->m_isOnSlope == true && (fVar5 = fVar4, this->m_reverseRelated < 1)))))) {
    fVar5 = fVar3;
  }
                    /* WARNING: Could not recover jumptable at 0x00010037a6d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  virtual_0x158(fVar5,this);
  return;
}


// ==== PlayerObject::getModifiedSlopeYVel @ 0x37b378

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float PlayerObject__getModifiedSlopeYVel(PlayerObject *this)

{
  double dVar1;
  double dVar2;
  
  dVar1 = this->m_totalTime - this->m_slopeStartTime;
  dVar2 = dVar1 * 10.0;
  if (dVar2 <= 0.4000000059604645) {
    dVar2 = 0.4000000059604645;
  }
  if (0.10000000149011612 <= dVar1) {
    dVar2 = 1.0;
  }
  return (float)(dVar2 * (double)this->m_slopeVelocity);
}


// ==== PlayerObject::hitGround @ 0x381ea0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PlayerObject__hitGround(PlayerObject *this,GameObject *object,bool notFlipped)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  undefined4 *puVar4;
  undefined8 uVar5;
  long lVar6;
  int iVar7;
  byte bVar8;
  undefined4 uVar9;
  undefined8 uVar10;
  long *plVar11;
  double dVar12;
  float fVar13;
  double dVar14;
  undefined8 uStack_70;
  undefined8 uStack_68;
  long lStack_60;
  undefined1 auStack_50 [8];
  undefined8 uStack_48;
  
  if (object == (GameObject *)0x0) {
    lVar6 = 0;
  }
  else {
    lVar6 = (long)object->m_objectMaterial;
  }
  this->m_groundObjectMaterial = (int)lVar6;
  this->m_isOnIce = false;
  dVar12 = this->m_yVelocity;
  dVar14 = -dVar12;
  if (this->m_isUpsideDown == false) {
    dVar14 = dVar12;
  }
  if ((*(long *)this->m_gameLayer != 0) && ((this->m_isDart & 1U) == 0)) {
    if (this->m_isUpsideDown == false) {
      if (dVar12 < -14.0) goto LAB_100381f44;
      if (dVar12 < -8.0) goto LAB_100381f5c;
      if (dVar12 < -4.0) goto LAB_100381f74;
      if (dVar12 < -1.0) goto LAB_10038203c;
    }
    else {
      if (14.0 < dVar12) {
LAB_100381f44:
        iVar2 = (this->GameObject).m_uniqueID;
        uVar5 = 5;
      }
      else if (8.0 < dVar12) {
LAB_100381f5c:
        iVar2 = (this->GameObject).m_uniqueID;
        uVar5 = 4;
      }
      else if (4.0 < dVar12) {
LAB_100381f74:
        iVar2 = (this->GameObject).m_uniqueID;
        uVar5 = 3;
      }
      else {
        if (dVar12 <= 1.0) goto LAB_100381f80;
LAB_10038203c:
        iVar2 = (this->GameObject).m_uniqueID;
        if (this->m_isOnGround2 == true) {
          uVar5 = 1;
        }
        else {
          uVar5 = 2;
        }
      }
      GJBaseGameLayer__gameEventTriggered(*(long *)this->m_gameLayer,uVar5,lVar6,iVar2);
    }
LAB_100381f80:
    if (this->m_fallStartY != 0.0) {
      lVar6 = getPosition/*virtual+0xc0*/(this);
      fVar13 = this->m_fallStartY - *(float *)(lVar6 + 4);
      if ((fVar13 != 0.0) && (!NAN(fVar13))) {
        fVar13 = ABS(this->m_fallStartY - *(float *)(lVar6 + 4));
        if (fVar13 <= 450.0) {
          if (fVar13 <= 300.0) {
            if (fVar13 <= 150.0) {
              if ((7.5 < fVar13) && (lVar6 = *(long *)this->m_gameLayer, lVar6 != 0)) {
                iVar2 = this->m_groundObjectMaterial;
                iVar7 = (this->GameObject).m_uniqueID;
                uVar5 = 0x41;
                goto LAB_100382074;
              }
            }
            else {
              lVar6 = *(long *)this->m_gameLayer;
              if (lVar6 != 0) {
                iVar2 = this->m_groundObjectMaterial;
                iVar7 = (this->GameObject).m_uniqueID;
                uVar5 = 0x42;
LAB_100382074:
                GJBaseGameLayer__gameEventTriggered(lVar6,uVar5,iVar2,iVar7);
              }
            }
          }
          else {
            lVar6 = *(long *)this->m_gameLayer;
            if (lVar6 != 0) {
              iVar2 = this->m_groundObjectMaterial;
              iVar7 = (this->GameObject).m_uniqueID;
              uVar5 = 0x43;
              goto LAB_100382074;
            }
          }
        }
        else {
          lVar6 = *(long *)this->m_gameLayer;
          if (lVar6 != 0) {
            iVar2 = this->m_groundObjectMaterial;
            iVar7 = (this->GameObject).m_uniqueID;
            uVar5 = 0x44;
            goto LAB_100382074;
          }
        }
      }
      this->m_fallStartY = 0.0;
    }
  }
  this->m_yVelocity = 0.0;
  this->m_isSliding = false;
  if (((this->m_isOnGround2 & 1U) == 0) && (!notFlipped)) {
    if (this->m_playEffects == true) {
      lVar6 = GameManager__sharedState();
      uVar3 = GJBaseGameLayer__isFlipping(*(undefined8 *)(lVar6 + 0x1f8));
      if ((uVar3 & 1) != 0) goto LAB_100382250;
    }
    if ((this->m_isHidden & 1U) == 0) {
      lVar6 = 0x8b8;
      if (this->m_useLandParticles0 == false) {
        lVar6 = 0x8c0;
      }
      plVar11 = *(long **)((long)&(this->GameObject).vtable + lVar6);
      this->m_useLandParticles0 = (bool)(this->m_useLandParticles0 ^ 1);
      uVar1 = (**(code **)(*plVar11 + 0x380))(plVar11);
      if (uVar1 < 3) {
        fVar13 = -this->m_landParticlesAngle;
        if (this->m_isUpsideDown == false) {
          fVar13 = this->m_landParticlesAngle;
        }
        (**(code **)(*plVar11 + 0x3e0))(fVar13,plVar11);
        puVar4 = (undefined4 *)(**(code **)(**(long **)this->m_landParticles0 + 0x400))();
        fVar13 = -this->m_landParticleRelatedY;
        if (this->m_isUpsideDown == false) {
          fVar13 = this->m_landParticleRelatedY;
        }
        CCPoint__CCPoint(*puVar4,fVar13,&uStack_48);
        (**(code **)(*plVar11 + 0x408))(plVar11,&uStack_48);
        fVar13 = 15.0;
        if (this->m_isUpsideDown == false) {
          fVar13 = -15.0;
        }
        uVar9 = 0;
        CCPoint__CCPoint(0,this->m_vehicleSize * fVar13,&uStack_48);
        if (this->m_isSideways == true) {
          uStack_48 = NEON_rev64(uStack_48,4);
          uVar9 = 0x42b40000;
        }
        (**(code **)(*plVar11 + 0x158))(uVar9,plVar11);
        if ((object != (GameObject *)0x0) &&
           (iVar2 = virtual_0x6f8(object), iVar2 == 0x19)) {
          dVar12 = 90.0;
          if (this->m_isSideways == false) {
            dVar12 = 0.0;
          }
          (**(code **)(*plVar11 + 0x158))
                    ((float)(dVar12 + this->m_slopeRotation * 57.295780181884766),plVar11);
        }
        uVar5 = getPosition/*virtual+0xc0*/(this);
        CCPoint__operator_plus(auStack_50,uVar5,&uStack_48);
        (**(code **)(*plVar11 + 0xb8))(plVar11,auStack_50);
        CCParticleSystem__resetSystem(plVar11);
      }
    }
  }
LAB_100382250:
  if ((this->m_justPlacedStreak & 1U) == 0) {
    if (((((this->m_maybeReducedEffects & 1U) == 0) && (this->m_isDart == true)) &&
        ((this->m_isLocked & 1U) == 0)) && (this->m_fadeOutStreak == true)) {
      if (this->m_playEffects == true) {
        lVar6 = GameManager__sharedState();
        uVar3 = GJBaseGameLayer__isFlipping(*(undefined8 *)(lVar6 + 0x1f8));
        if ((uVar3 & 1) != 0) goto LAB_1003822c8;
      }
      uVar10 = *(undefined8 *)this->m_waveTrail;
      uVar5 = getPosition/*virtual+0xc0*/(this);
      CCPoint__CCPoint_copy(&uStack_48,uVar5);
      HardStreak__addPoint(uVar10,&uStack_48);
    }
LAB_1003822c8:
    this->m_justPlacedStreak = true;
  }
  if (((this->m_isOnGround2 & 1U) == 0) && ((this->m_isDashing & 1U) == 0)) {
    if (this->m_isRobot == true) {
      uVar5 = *(undefined8 *)this->m_robotSprite;
      if ((char)this->m_currentRobotAnimation[0x17] < '\0') {
        gd__string__assign(&uStack_70,*(undefined8 *)this->m_currentRobotAnimation,
                            *(undefined8 *)(this->m_currentRobotAnimation + 8));
      }
      else {
        uStack_68 = *(undefined8 *)(this->m_currentRobotAnimation + 8);
        uStack_70 = *(undefined8 *)this->m_currentRobotAnimation;
        lStack_60 = *(long *)(this->m_currentRobotAnimation + 0x10);
      }
      CCAnimatedSprite__runAnimation(uVar5,&uStack_70);
      if (lStack_60 < 0) {
        __ZdlPv(uStack_70);
      }
    }
    else if (this->m_isSpider == true) {
      PlayerObject__playDynamicSpiderRun(this);
    }
  }
  this->m_isOnGround2 = true;
  this->m_unkA29 = !notFlipped;
  if (dVar14 <= 5.0) {
    this->m_isOnGround = true;
    this->m_lastLandTime = this->m_totalTime;
  }
  this->m_isOnGround3 = true;
  this->m_stateOnGround = 2;
  bVar8 = this->m_isBall;
  if ((bVar8 & 1) == 0) {
    if (((this->m_isRotating & 1U) == 0) && (this->m_wasOnSlope != true)) goto LAB_100382408;
    this->m_isRotating = false;
    this->m_isBallRotating2 = false;
    this->m_isBallRotating = false;
    this->m_rotationSpeed = 0.0;
  }
  else {
    if ((this->m_isBallRotating == true) && ((this->m_isOnSlope & 1U) == 0)) {
      this->m_isRotating = false;
      this->m_isBallRotating2 = false;
      this->m_isBallRotating = false;
      this->m_rotationSpeed = 0.0;
    }
    if (this->m_isBallRotating2 == true) {
      this->m_isRotating = false;
      this->m_isBallRotating2 = false;
      this->m_isBallRotating = false;
      this->m_rotationSpeed = 0.0;
    }
    else if ((this->m_isRotating & 1U) != 0) goto LAB_100382408;
    PlayerObject__runRotateAction(this,0);
    bVar8 = this->m_isBall;
LAB_100382408:
    if ((bVar8 & 1) != 0) goto LAB_100382484;
  }
  if (((((this->m_isShip & 1U) == 0) && ((this->m_isBird & 1U) == 0)) &&
      ((this->m_isDart & 1U) == 0)) &&
     ((((this->m_isSwing & 1U) == 0 && ((this->m_isOnSlope & 1U) == 0)) &&
      (((this->m_wasOnSlope & 1U) == 0 &&
       (fVar13 = (float)virtual_0x160(this),
       0x2d82d82 < ((int)fVar13 * -0x5b05b05b + 0x2d82d82U >> 1 | (int)fVar13 * -0x80000000))))))) {
    this->m_isRotating = false;
    this->m_isBallRotating2 = false;
    this->m_isBallRotating = false;
    this->m_rotationSpeed = 0.0;
  }
LAB_100382484:
  uVar5 = getPosition/*virtual+0xc0*/(this);
  CCPoint__operator_assign(&this->m_lastGroundedPos,uVar5);
  if ((((this->m_isShip & 1U) == 0) && ((this->m_isBird & 1U) == 0)) &&
     (((this->m_isDart & 1U) == 0 &&
      (((this->m_isSwing & 1U) == 0 && (this->m_shouldTryPlacingCheckpoint == true)))))) {
    PlayerObject__deactivateStreak(this,0);
    this->m_canPlaceCheckpoint = true;
  }
  this->m_shouldTryPlacingCheckpoint = false;
  return;
}


// ==== PlayerObject::preCollision @ 0x37c100

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PlayerObject__preCollision(PlayerObject *this)

{
  long *plVar1;
  long lVar2;
  long lVar3;
  undefined4 uStack_40;
  undefined1 uStack_39;
  undefined1 *puStack_38;
  
  this->m_ringJumpRelated = false;
  this->m_collidedBottomMaxY = 0.0;
  this->m_collidedTopMinY = 0.0;
  this->m_collidedRightMinX = 0.0;
  this->m_collidedLeftMaxX = 0.0;
  this->m_wasOnSlope = this->m_isOnSlope;
  this->m_isOnSlope = false;
  this->m_isOnGround4 = this->m_isOnGround2;
  if ((((this->m_isOnGround2 == true) && ((this->m_platformerMovingLeft & 1U) == 0)) &&
      ((this->m_platformerMovingRight & 1U) == 0)) && (0 < this->m_maybeSlidingTime)) {
    this->m_maybeSlidingTime = 0;
    this->m_maybeSlidingStartTime = this->m_totalTime;
  }
  if (this->m_unk669 == true) {
    this->m_currentPotentialSlope[0] = 0;
    this->m_currentPotentialSlope[1] = 0;
    this->m_currentPotentialSlope[2] = 0;
    this->m_currentPotentialSlope[3] = 0;
    this->m_currentPotentialSlope[4] = 0;
    this->m_currentPotentialSlope[5] = 0;
    this->m_currentPotentialSlope[6] = 0;
    this->m_currentPotentialSlope[7] = 0;
    lVar3 = *(long *)(this->m_potentialSlopeMap + 0x18);
  }
  else {
    this->m_unk669 = true;
    lVar3 = *(long *)(this->m_potentialSlopeMap + 0x18);
  }
  if (lVar3 != 0) {
    plVar1 = *(long **)(this->m_potentialSlopeMap + 0x10);
    while (plVar1 != (long *)0x0) {
      plVar1 = (long *)*plVar1;
      __ZdlPv();
    }
    this->m_potentialSlopeMap[0x10] = 0;
    this->m_potentialSlopeMap[0x11] = 0;
    this->m_potentialSlopeMap[0x12] = 0;
    this->m_potentialSlopeMap[0x13] = 0;
    this->m_potentialSlopeMap[0x14] = 0;
    this->m_potentialSlopeMap[0x15] = 0;
    this->m_potentialSlopeMap[0x16] = 0;
    this->m_potentialSlopeMap[0x17] = 0;
    if (*(long *)(this->m_potentialSlopeMap + 8) != 0) {
      _bzero(*(undefined8 *)this->m_potentialSlopeMap,*(long *)(this->m_potentialSlopeMap + 8) << 3)
      ;
    }
    this->m_potentialSlopeMap[0x18] = 0;
    this->m_potentialSlopeMap[0x19] = 0;
    this->m_potentialSlopeMap[0x1a] = 0;
    this->m_potentialSlopeMap[0x1b] = 0;
    this->m_potentialSlopeMap[0x1c] = 0;
    this->m_potentialSlopeMap[0x1d] = 0;
    this->m_potentialSlopeMap[0x1e] = 0;
    this->m_potentialSlopeMap[0x1f] = 0;
  }
  lVar3 = *(long *)this->m_currentPotentialSlope;
  if (lVar3 != 0) {
    uStack_40 = *(undefined4 *)(lVar3 + 0x394);
    puStack_38 = (undefined1 *)&uStack_40;
    lVar2 = unordered_map_int_GameObject__emplace(this->m_potentialSlopeMap,&uStack_40,&UNK_10072382e,&puStack_38,
                                &uStack_39);
    *(long *)(lVar2 + 0x18) = lVar3;
  }
  lVar3 = *(long *)this->m_currentSlope;
  if (lVar3 != 0) {
    uStack_40 = *(undefined4 *)(lVar3 + 0x394);
    puStack_38 = (undefined1 *)&uStack_40;
    lVar2 = unordered_map_int_GameObject__emplace(this->m_potentialSlopeMap,&uStack_40,&UNK_10072382e,&puStack_38,
                                &uStack_39);
    *(long *)(lVar2 + 0x18) = lVar3;
  }
  return;
}


// ==== PlayerObject::postCollision @ 0x37c258

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PlayerObject__postCollision(PlayerObject *this,float dt,bool betweenSteps)

{
  long *plVar1;
  byte bVar2;
  char cVar3;
  undefined1 uVar4;
  bool bVar5;
  undefined8 *puVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  int iVar10;
  uint uVar11;
  long lVar12;
  ulong uVar13;
  undefined8 uVar14;
  GameObject *pGVar15;
  float *pfVar16;
  undefined4 *puVar17;
  byte bVar18;
  code *pcVar19;
  undefined8 *puVar20;
  bool bVar21;
  long *plVar22;
  undefined8 uVar23;
  byte bVar24;
  uint uVar25;
  byte bVar26;
  undefined8 *puVar27;
  float fVar28;
  float fVar29;
  double dVar30;
  double dVar31;
  double dVar32;
  double in_d3;
  float in_s4;
  float fVar33;
  undefined4 uVar34;
  float fVar35;
  float fVar36;
  CCRect rect;
  CCRect rect_00;
  CCRect rect_01;
  undefined1 auStack_e0 [16];
  float fStack_d0;
  float fStack_cc;
  float fStack_c8;
  float fStack_c4;
  float afStack_c0 [4];
  float fStack_b0;
  float fStack_ac;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  
  dVar32 = 5.2220990168286e-315;
  fVar28 = 0.5;
  if (!betweenSteps) {
    fVar28 = 1.0;
  }
  dVar30 = (double)(ulong)(uint)fVar28;
  fVar36 = dt * 4.0;
  if (this->m_enableImpulseFix == false) {
    fVar36 = fVar28;
  }
  bVar26 = this->m_holdingLeft;
  bVar24 = (bVar26 ^ 1) & this->m_holdingRight;
  if ((((bVar26 ^ 1) & 1) == 0) && ((this->m_holdingRight & 1U) != 0)) {
    bVar26 = this->m_leftPressedFirst;
    bVar24 = bVar26 ^ 1;
  }
  if ((*(long *)this->m_lastGroundObject != 0) && (iVar10 = GameObject__getGroupDisabled(), iVar10 != 0)) {
    this->m_lastGroundObject[0] = 0;
    this->m_lastGroundObject[1] = 0;
    this->m_lastGroundObject[2] = 0;
    this->m_lastGroundObject[3] = 0;
    this->m_lastGroundObject[4] = 0;
    this->m_lastGroundObject[5] = 0;
    this->m_lastGroundObject[6] = 0;
    this->m_lastGroundObject[7] = 0;
  }
  if ((*(long *)this->m_currentSlope2 != 0) && (iVar10 = GameObject__getGroupDisabled(), iVar10 != 0)) {
    this->m_currentSlope2[0] = 0;
    this->m_currentSlope2[1] = 0;
    this->m_currentSlope2[2] = 0;
    this->m_currentSlope2[3] = 0;
    this->m_currentSlope2[4] = 0;
    this->m_currentSlope2[5] = 0;
    this->m_currentSlope2[6] = 0;
    this->m_currentSlope2[7] = 0;
  }
  if (*(long *)this->m_lastGroundObject != 0) {
    this->m_isOnIce = *(bool *)(*(long *)this->m_lastGroundObject + 0x511);
  }
  bVar18 = this->m_isOnSlope;
  if ((((bool)bVar18 == true) && (*(long *)this->m_currentSlope != 0)) &&
     ((this->m_maybeUpsideDownSlope & 1U) == 0)) {
    this->m_isOnIce = *(bool *)(*(long *)this->m_currentSlope + 0x511);
  }
  if ((bool)bVar18 != this->m_wasOnSlope) {
    if (this->m_isDart == true) {
      if ((((this->m_maybeReducedEffects & 1U) == 0) && ((this->m_isLocked & 1U) == 0)) &&
         (this->m_fadeOutStreak == true)) {
        if (this->m_playEffects == true) {
          lVar12 = GameManager__sharedState();
          uVar13 = GJBaseGameLayer__isFlipping(*(undefined8 *)(lVar12 + 0x1f8));
          if ((uVar13 & 1) != 0) goto LAB_10037c3a4;
        }
        uVar23 = *(undefined8 *)this->m_waveTrail;
        uVar14 = getPosition/*virtual+0xc0*/(this);
        CCPoint__CCPoint_copy(&fStack_90,uVar14);
        HardStreak__addPoint(uVar23,&fStack_90);
      }
LAB_10037c3a4:
      this->m_justPlacedStreak = false;
      bVar18 = this->m_isOnSlope;
    }
    if ((bVar18 & 1) == 0) {
      dVar30 = this->m_totalTime;
      this->m_slopeEndTime = dVar30;
      bVar9 = this->m_isUpsideDown;
      fVar28 = this->m_slopeVelocity;
      if ((bVar9 & 1U) == 0) {
        if (0.0 > fVar28) {
          dVar32 = this->m_yVelocity;
          in_d3 = (double)fVar28;
          if ((in_d3 < dVar32) && ((this->m_isCurrentSlopeTop & 1U) != 0)) goto LAB_10037c464;
        }
        if (0.0 < fVar28) {
          dVar32 = this->m_yVelocity;
          in_d3 = (double)fVar28;
          if ((dVar32 < in_d3) && ((this->m_isCurrentSlopeTop & 1U) == 0)) goto LAB_10037c464;
        }
LAB_10037c450:
        bVar18 = 0;
        bVar2 = this->m_maybeIsBoosted;
      }
      else {
        if (0.0 <= fVar28) {
LAB_10037c3e4:
          if (0.0 < fVar28) {
            dVar32 = this->m_yVelocity;
            in_d3 = (double)fVar28;
            if (dVar32 < in_d3) {
              bVar18 = this->m_isCurrentSlopeTop ^ 1;
              bVar2 = this->m_maybeIsBoosted;
              goto joined_r0x00010037c40c;
            }
          }
          goto LAB_10037c450;
        }
        dVar32 = this->m_yVelocity;
        in_d3 = (double)fVar28;
        if ((dVar32 <= in_d3) || ((this->m_isCurrentSlopeTop & 1U) == 0)) goto LAB_10037c3e4;
LAB_10037c464:
        in_d3 = (double)fVar28;
        bVar18 = 1;
        bVar2 = this->m_maybeIsBoosted;
      }
joined_r0x00010037c40c:
      if ((((bVar2 == 1) && ((this->m_isShip & 1U) == 0)) && ((this->m_isBird & 1U) == 0)) &&
         (((this->m_isDart & 1U) == 0 && ((this->m_isSwing & 1U) == 0)))) {
        bVar18 = this->m_isBall & bVar18;
      }
      if ((bVar18 & 1) == 0) {
        if ((bVar9 & 1U) == 0) {
          if (fVar28 < 0.0) goto LAB_10037c598;
        }
        else if (0.0 < fVar28) {
LAB_10037c598:
          if ((((bVar2 & 1) == 0) && ((this->m_jumpBuffered & 1U) == 0)) &&
             (((this->m_stateRingJump & 1U) == 0 && (this->m_isCurrentSlopeTop == bVar9)))) {
            this->m_isOnGround2 = false;
            dVar31 = this->m_currentSlopeYVelocity;
            if (bVar9 == false) {
              dVar31 = -this->m_currentSlopeYVelocity;
            }
            dVar30 = (double)(int)dVar31;
            if (dVar31 != dVar30) {
              dVar32 = 0.0;
              dVar31 = (double)(long)((dVar31 - dVar30) * 1000.0) / 1000.0 + dVar30;
            }
            this->m_yVelocity = dVar31;
            this->m_isOnGround = false;
            PlayerObject__runRotateAction(this,0);
          }
        }
      }
      else {
        dVar30 = dVar30 - this->m_slopeStartTime;
        dVar32 = dVar30 * 10.0;
        if (dVar32 <= 0.4000000059604645) {
          dVar32 = 0.4000000059604645;
        }
        in_d3 = 0.10000000149011612;
        dVar31 = dVar32;
        if (0.10000000149011612 <= dVar30) {
          dVar31 = 1.0;
        }
        fVar33 = (float)(dVar31 * (double)fVar28);
        fVar35 = this->m_slopeAngle;
        fVar28 = (float)_cosf(fVar35);
        bVar7 = this->m_isPlatformer;
        if (bVar7 == true) {
          dVar32 = this->m_platformerXVelocity;
          fVar35 = (float)_tanf(fVar35);
          dVar30 = ABS(dVar32 * (double)fVar35);
          dVar32 = dVar30 * 1.100000023841858;
          dVar30 = -(dVar30 * 1.100000023841858);
          if (0.0 <= fVar33) {
            dVar30 = dVar32;
          }
          fVar33 = (float)dVar30;
        }
        if ((bVar9 & 1U) == 0) {
          if ((this->m_isCurrentSlopeTop != false) && (this->m_slopeFlipGravityRelated == true))
          goto LAB_10037c580;
LAB_10037c614:
          dVar30 = (double)fVar33;
          if (dVar30 <= this->m_yVelocity) goto LAB_10037c660;
        }
        else {
          if (((this->m_isCurrentSlopeTop & 1U) == 0) && (this->m_slopeFlipGravityRelated == true))
          goto LAB_10037c614;
LAB_10037c580:
          dVar30 = (double)fVar33;
          if (this->m_yVelocity <= dVar30) goto LAB_10037c660;
        }
        dVar30 = (double)fVar33;
        if (bVar7 == false) {
LAB_10037c654:
          PlayerObject__boostPlayer(this,fVar33);
        }
        else if (((bVar26 | bVar24) & 1) != 0) {
          dVar30 = ABS(this->m_platformerXVelocity);
          dVar32 = 1.58735232019473e-314;
          if ((double)(fVar28 * 5.0 + -1.0) <= dVar30) goto LAB_10037c654;
        }
      }
LAB_10037c660:
      if ((0.0 < this->m_maybeSlopeForce) &&
         ((((bVar26 & 1) != 0 && ((this->m_isSlidingRight & 1U) != 0)) ||
          (((bVar24 & 1) != 0 && ((this->m_isSlidingRight & 1U) == 0)))))) {
        this->m_isSliding = false;
        this->m_maybeSlopeForce = 0.0;
        this->m_isMoving = true;
      }
      this->m_slopeVelocity = 0.0;
      this->m_currentSlope[0] = 0;
      this->m_currentSlope[1] = 0;
      this->m_currentSlope[2] = 0;
      this->m_currentSlope[3] = 0;
      this->m_currentSlope[4] = 0;
      this->m_currentSlope[5] = 0;
      this->m_currentSlope[6] = 0;
      this->m_currentSlope[7] = 0;
      this->m_currentSlopeYVelocity = 0.0;
      this->m_slopeRotation = 0.0;
    }
  }
  if (((this->m_collidedTopMinY == 0.0) || (this->m_collidedBottomMaxY == 0.0)) ||
     ((this->m_disablePlayerSqueeze & 1U) != 0)) {
LAB_10037ca50:
    uVar4 = this->m_ignoreDamage;
  }
  else {
    fVar28 = 0.8;
    if (this->m_isPlatformer == false) {
      fVar28 = 0.7;
    }
    uVar14 = getObjectRect/*virtual+0x520*/(this);
    CCRect__CCRect_copy(&fStack_90,uVar14);
    dVar30 = this->m_collidedBottomMaxY;
    fVar33 = (float)(this->m_collidedTopMinY - dVar30);
    lVar12 = getPosition/*virtual+0xc0*/(this);
    if (fVar33 == 0.0) {
LAB_10037c72c:
      bVar9 = true;
      cVar3 = this->m_isPlatformer;
    }
    else {
      dVar31 = this->m_collidedTopMinY;
      dVar30 = (double)*(float *)(lVar12 + 4);
      if ((this->m_isUpsideDown & 1U) == 0) {
        if ((dVar30 <= dVar31) ||
           (dVar30 = (double)(this->GameObject).m_lastPosition.y, dVar30 <= dVar31))
        goto LAB_10037c788;
        goto LAB_10037c72c;
      }
      if ((dVar30 < dVar31) &&
         (dVar30 = (double)(this->GameObject).m_lastPosition.y, dVar30 < dVar31))
      goto LAB_10037c72c;
LAB_10037c788:
      bVar9 = false;
      cVar3 = this->m_isPlatformer;
    }
    if (cVar3 == '\x01') {
      fVar35 = ABS(fVar33);
      if (*(long **)this->m_currentSlope != (long *)0x0) {
        fVar29 = fVar28 * fStack_84;
        dVar30 = (double)(ulong)(uint)fVar29;
        bVar7 = true;
        bVar8 = false;
        if (fVar35 <= fStack_84) {
          bVar7 = false;
          bVar8 = true;
          if (!NAN(fVar35) && !NAN(fVar29)) {
            bVar7 = fVar35 < fVar29;
            bVar8 = false;
          }
        }
        if (bVar7 == bVar8) {
          uVar14 = (**(code **)(**(long **)this->m_currentSlope + 0x520))();
          CCRect__CCRect_copy(&uStack_a0,uVar14);
          iVar10 = CCRect__intersectsRect(&fStack_90,&uStack_a0);
          if (iVar10 != 0) {
            pGVar15 = *(GameObject **)this->m_currentSlope;
            if (pGVar15->m_slopeUphill == true) {
              bVar9 = GameObject__slopeFloorTop(pGVar15);
              fVar28 = -1.0;
              if (bVar9) {
                pGVar15 = *(GameObject **)this->m_currentSlope;
                fVar28 = 1.0;
                if ((pGVar15->m_slopeUphill & 1U) == 0) goto LAB_10037c80c;
              }
            }
            else {
LAB_10037c80c:
              bVar9 = GameObject__slopeFloorTop(pGVar15);
              fVar28 = -1.0;
              if (!bVar9) {
                fVar28 = 1.0;
              }
            }
            this->m_platformerXVelocity = 0.0;
            fVar33 = (this->GameObject).m_lastPosition.x;
            lVar12 = getPosition/*virtual+0xc0*/(this);
            dVar30 = (double)(ulong)*(uint *)(lVar12 + 4);
            CCPoint__CCPoint(fVar33 + dt * fVar28,&fStack_b0);
            pcVar19 = *(code **)((this->GameObject).vtable + 0xb8);
            pfVar16 = &fStack_b0;
LAB_10037ca48:
            (*pcVar19)(this,pfVar16);
            goto LAB_10037ca50;
          }
        }
      }
    }
    if ((bVar9) || (fVar28 * fStack_84 <= ABS(fVar33))) goto LAB_10037ca50;
    if (this->m_isPlatformer == true) {
      uVar23 = *(undefined8 *)this->m_gameLayer;
      uVar14 = getObjectRect/*virtual+0x520*/(this);
      CCRect__CCRect_copy(&uStack_a0,uVar14);
      dVar30 = -0.007812501848093234;
      uStack_a0 = CONCAT44((float)(uStack_a0 >> 0x20) + -1.0,(float)uStack_a0 + 1.0);
      uStack_98 = CONCAT44((float)((ulong)uStack_98 >> 0x20) + 2.0,(float)uStack_98 + -2.0);
      lVar12 = getPosition/*virtual+0xc0*/(this);
      fVar28 = *(float *)(lVar12 + 4);
      uVar25 = 1;
      do {
        CCRect__CCRect_copy(&fStack_b0,&uStack_a0);
        fVar33 = -((float)(int)((float)uVar25 / 2.0) * 3.0);
        if ((uVar25 & 1) != 0) {
          fVar33 = (float)(int)((float)uVar25 / 2.0) * 3.0;
        }
        fStack_b0 = fVar33 + fStack_b0;
        CCRect__CCRect_copy(afStack_c0,&fStack_b0);
        lVar12 = GJBaseGameLayer__staticObjectsInRect(uVar23,afStack_c0,0);
        if (lVar12 == 0) {
LAB_10037ca04:
          pfVar16 = (float *)getPosition/*virtual+0xc0*/(this);
          fVar28 = *pfVar16;
          lVar12 = getPosition/*virtual+0xc0*/(this);
          dVar30 = (double)(ulong)*(uint *)(lVar12 + 4);
          CCPoint__CCPoint(fVar33 + fVar28,afStack_c0);
          pcVar19 = *(code **)((this->GameObject).vtable + 0xb8);
          pfVar16 = afStack_c0;
          goto LAB_10037ca48;
        }
        uVar11 = **(uint **)(lVar12 + 0x38);
        if (uVar11 == 0) goto LAB_10037ca04;
        bVar7 = false;
        bVar9 = false;
        puVar20 = *(undefined8 **)(*(uint **)(lVar12 + 0x38) + 4);
        puVar6 = puVar20;
        do {
          puVar27 = puVar6 + 1;
          plVar22 = (long *)*puVar6;
          if (plVar22 == (long *)0x0) break;
          lVar12 = (**(code **)(*plVar22 + 0xc0))(plVar22);
          if (fVar28 <= *(float *)(lVar12 + 4)) {
            lVar12 = (**(code **)(*plVar22 + 0xc0))(plVar22);
            bVar9 = (bool)(bVar9 | *(float *)(lVar12 + 4) <= fVar28);
            bVar7 = true;
            if (bVar9) break;
          }
          else {
            bVar9 = true;
            if (bVar7) break;
          }
          puVar6 = puVar27;
        } while (puVar27 <= puVar20 + ((ulong)uVar11 - 1));
        if ((!bVar9) || (!bVar7)) goto LAB_10037ca04;
        uVar25 = uVar25 + 1;
      } while (uVar25 != 9);
    }
    if ((this->m_ignoreDamage & 1U) != 0) goto LAB_10037ca50;
    if ((this->m_playEffects & 1U) == 0) {
      setPosition/*virtual+0xb8*/(this,&(this->GameObject).m_lastPosition);
    }
    if ((this->m_maybeCanRunIntoBlocks & 1U) == 0) {
      lVar12 = GameManager__sharedState();
      (**(code **)(**(long **)(lVar12 + 0x1f8) + 0x4f8))(*(long **)(lVar12 + 0x1f8),this,0);
      uVar4 = this->m_ignoreDamage;
    }
    else {
      this->m_maybeIsColliding = true;
      uVar4 = this->m_ignoreDamage;
    }
  }
  if ((((uVar4 & 1) == 0) &&
      (iVar10 = CCDictionary__count(*(undefined8 *)this->m_collisionLogTop), iVar10 != 0)) &&
     (iVar10 = CCDictionary__count(*(undefined8 *)this->m_collisionLogBottom), iVar10 != 0)) {
    uVar14 = CCDictionary__allKeys(*(undefined8 *)this->m_collisionLogTop);
    iVar10 = CCArray__count();
    if (iVar10 != 0) {
      uVar25 = 0;
      do {
        lVar12 = CCArray__objectAtIndex(uVar14,uVar25);
        lVar12 = CCDictionary__objectForKey(*(undefined8 *)this->m_collisionLogBottom,
                                     (long)*(int *)(lVar12 + 0x38));
        if (lVar12 != 0) goto LAB_10037cca4;
        uVar25 = uVar25 + 1;
        uVar11 = CCArray__count(uVar14);
      } while (uVar25 < uVar11);
    }
  }
  if (this->m_isPlatformer == true) {
    if ((this->m_collidedLeftMaxX != 0.0) && (this->m_collidedRightMinX != 0.0)) {
      uVar14 = getObjectRect/*virtual+0x520*/(this);
      CCRect__CCRect_copy(&fStack_90,uVar14);
      fVar33 = this->m_vehicleSize;
      dVar30 = this->m_collidedLeftMaxX;
      fVar28 = (float)(this->m_collidedRightMinX - dVar30);
      pfVar16 = (float *)getPosition/*virtual+0xc0*/(this);
      if (fVar28 != 0.0) {
        fVar28 = ABS(fVar28);
        dVar30 = (double)(ulong)(uint)fVar28;
        dVar32 = (double)*pfVar16;
        if (0.0 <= this->m_platformerXVelocity) {
          in_d3 = this->m_collidedRightMinX;
          if ((dVar32 <= in_d3) ||
             (dVar32 = (double)(this->GameObject).m_lastPosition.x, dVar32 <= in_d3))
          goto LAB_10037d48c;
        }
        else {
          in_d3 = this->m_collidedLeftMaxX;
          if ((in_d3 <= dVar32) ||
             (dVar32 = (double)(this->GameObject).m_lastPosition.x, in_d3 <= dVar32)) {
LAB_10037d48c:
            if (fVar28 < fStack_88 + fVar33 * -5.0) {
              if (this->m_isPlatformer == true) {
                uVar23 = *(undefined8 *)this->m_gameLayer;
                uVar14 = getObjectRect/*virtual+0x520*/(this);
                CCRect__CCRect_copy(&uStack_a0,uVar14);
                dVar30 = 0.007812505573383532;
                uStack_a0 = CONCAT44((float)(uStack_a0 >> 0x20) + 1.0,(float)uStack_a0 + -1.0);
                uStack_98 = CONCAT44((float)((ulong)uStack_98 >> 0x20) + -2.0,(float)uStack_98 + 2.0
                                    );
                pfVar16 = (float *)getPosition/*virtual+0xc0*/(this);
                fVar28 = *pfVar16;
                uVar25 = 1;
                do {
                  CCRect__CCRect_copy(&fStack_b0,&uStack_a0);
                  fVar33 = -((float)(int)((float)uVar25 / 2.0) * 3.0);
                  if ((uVar25 & 1) != 0) {
                    fVar33 = (float)(int)((float)uVar25 / 2.0) * 3.0;
                  }
                  fStack_ac = fVar33 + fStack_ac;
                  CCRect__CCRect_copy(afStack_c0,&fStack_b0);
                  lVar12 = GJBaseGameLayer__staticObjectsInRect(uVar23,afStack_c0,0);
                  if (lVar12 == 0) {
LAB_10037d93c:
                    puVar17 = (undefined4 *)getPosition/*virtual+0xc0*/(this);
                    uVar34 = *puVar17;
                    lVar12 = getPosition/*virtual+0xc0*/(this);
                    dVar30 = (double)(ulong)(uint)(fVar33 + *(float *)(lVar12 + 4));
                    CCPoint__CCPoint(uVar34,afStack_c0);
                    setPosition/*virtual+0xb8*/(this,afStack_c0);
                    goto LAB_10037cb28;
                  }
                  uVar11 = **(uint **)(lVar12 + 0x38);
                  if (uVar11 == 0) goto LAB_10037d93c;
                  bVar7 = false;
                  bVar9 = false;
                  puVar20 = *(undefined8 **)(*(uint **)(lVar12 + 0x38) + 4);
                  puVar6 = puVar20;
                  while( true ) {
                    puVar27 = puVar6 + 1;
                    plVar22 = (long *)*puVar6;
                    if (plVar22 == (long *)0x0) break;
                    pfVar16 = (float *)(**(code **)(*plVar22 + 0xc0))(plVar22);
                    if (fVar28 <= *pfVar16) {
                      lVar12 = (**(code **)(*plVar22 + 0xc0))(plVar22);
                      bVar7 = (bool)(bVar7 | *(float *)(lVar12 + 4) <= fVar28);
                      bVar9 = true;
                    }
                    else {
                      bVar7 = true;
                    }
                    if (((bool)(bVar7 & bVar9)) ||
                       (puVar6 = puVar27, puVar20 + ((ulong)uVar11 - 1) < puVar27)) break;
                  }
                  if ((!bVar7) || (!bVar9)) goto LAB_10037d93c;
                  uVar25 = uVar25 + 1;
                } while (uVar25 != 9);
              }
              if ((this->m_playEffects & 1U) == 0) {
                setPosition/*virtual+0xb8*/
                          (this,&(this->GameObject).m_lastPosition);
              }
              if ((this->m_maybeCanRunIntoBlocks & 1U) == 0) {
                lVar12 = GameManager__sharedState();
                (**(code **)(**(long **)(lVar12 + 0x1f8) + 0x4f8))
                          (*(long **)(lVar12 + 0x1f8),this,0);
              }
              else {
                this->m_maybeIsColliding = (bool)(this->m_ignoreDamage ^ 1);
              }
            }
          }
        }
      }
    }
LAB_10037cb28:
    if ((((this->m_ignoreDamage & 1U) == 0) &&
        (iVar10 = CCDictionary__count(*(undefined8 *)this->m_collisionLogLeft), iVar10 != 0)) &&
       (iVar10 = CCDictionary__count(*(undefined8 *)this->m_collisionLogRight), iVar10 != 0)) {
      uVar14 = CCDictionary__allKeys(*(undefined8 *)this->m_collisionLogLeft);
      iVar10 = CCArray__count();
      if (iVar10 != 0) {
        uVar25 = 0;
        do {
          lVar12 = CCArray__objectAtIndex(uVar14,uVar25);
          lVar12 = CCDictionary__objectForKey(*(undefined8 *)this->m_collisionLogRight,
                                       (long)*(int *)(lVar12 + 0x38));
          if (lVar12 != 0) {
LAB_10037cca4:
            setPosition/*virtual+0xb8*/(this,&(this->GameObject).m_lastPosition)
            ;
            if ((this->m_maybeCanRunIntoBlocks & 1U) != 0) {
              this->m_maybeIsColliding = true;
              return;
            }
            lVar12 = GameManager__sharedState();
            (**(code **)(**(long **)(lVar12 + 0x1f8) + 0x4f8))(*(long **)(lVar12 + 0x1f8),this,0);
            return;
          }
          uVar25 = uVar25 + 1;
          uVar11 = CCArray__count(uVar14);
        } while (uVar25 < uVar11);
      }
    }
  }
  if (this->m_isPlatformer == true) {
    lVar12 = *(long *)this->m_currentSlope2;
    if (lVar12 != 0) {
      *(long *)this->m_preLastGroundObject = lVar12;
    }
    if (((*(long **)this->m_lastGroundObject == (long *)0x0) &&
        (*(long *)this->m_preLastGroundObject == 0)) ||
       ((plVar22 = *(long **)this->m_preLastGroundObject, (this->m_isOnGround2 & 1U) == 0 &&
        (plVar22 == (long *)0x0)))) {
LAB_10037cbd8:
      bVar9 = false;
      if (lVar12 == 0) goto LAB_10037ce0c;
LAB_10037cd9c:
      if ((((this->m_isOnSlope & 1U) == 0) && (this->m_wasOnSlope != true)) ||
         (((this->m_maybeUpsideDownSlope & 1U) != 0 || ((*(byte *)(lVar12 + 0x512) & 1) != 0))))
      goto LAB_10037ce0c;
      fVar28 = ABS(this->m_slopeAngle * 57.29578);
      dVar30 = 5.48113170615542e-315;
      if (fVar28 <= 40.0) goto LAB_10037ce0c;
      bVar7 = this->m_platformerMovingLeft;
      if (this->m_slopeSlidingMaybeRotated == true) {
        if ((this->m_isUpsideDown & 1U) == 0) goto LAB_10037ce00;
LAB_10037d8f4:
        bVar21 = false;
        bVar8 = true;
      }
      else {
        if ((this->m_isUpsideDown & 1U) == 0) goto LAB_10037d8f4;
LAB_10037ce00:
        bVar8 = false;
        bVar21 = true;
      }
      bVar5 = this->m_platformerMovingRight;
      this->m_platformerMovingLeft = bVar21;
      this->m_platformerMovingRight = bVar8;
      if ((bVar7 != bVar21) || (bVar5 != bVar8)) {
        dVar30 = this->m_totalTime;
        this->m_changedDirectionsTime = dVar30;
      }
      this->m_maybeChangedDirectionAngle = (double)fVar28;
      this->m_maybeGoingCorrectSlopeDirection = true;
      bVar24 = this->m_isOnGround2;
    }
    else {
      plVar1 = *(long **)this->m_lastGroundObject;
      if (plVar22 != (long *)0x0) {
        plVar1 = plVar22;
      }
      if ((*(byte *)((long)plVar1 + 0x50f) & 1) != 0) goto LAB_10037cbd8;
      uVar14 = GameObject__getLastPosition(plVar1);
      CCPoint__CCPoint_copy(&fStack_90,uVar14);
      (**(code **)(*plVar1 + 0x540))(&uStack_a0,plVar1);
      fVar28 = 0.0;
      if (*(char *)((long)plVar1 + 0x513) == '\x01') {
        GameObject__getScalePosDelta(&fStack_b0,plVar1);
        fVar28 = fStack_b0;
        fVar33 = (float)uStack_a0;
        pfVar16 = (float *)getPosition/*virtual+0xc0*/(this);
        if (*pfVar16 < fVar33) {
          fVar28 = -fVar28;
        }
      }
      if ((this->m_isSideways & 1U) == 0) {
        dVar30 = (double)(fVar28 + ((float)uStack_a0 - fStack_90));
        this->m_scaleXRelated = dVar30;
        this->m_scaleXRelated2 = dVar30;
        uVar14 = getPosition/*virtual+0xc0*/(this);
        fVar28 = (float)this->m_scaleXRelated;
        fVar33 = 0.0;
      }
      else {
        dVar30 = (double)(fVar28 + (uStack_a0._4_4_ - fStack_8c));
        this->m_scaleXRelated = dVar30;
        this->m_scaleXRelated2 = dVar30;
        uVar14 = getPosition/*virtual+0xc0*/(this);
        fVar33 = (float)this->m_scaleXRelated;
        fVar28 = 0.0;
      }
      CCPoint__CCPoint(fVar28,fVar33,afStack_c0);
      CCPoint__operator_plus(&fStack_b0,uVar14,afStack_c0);
      setPosition/*virtual+0xb8*/(this,&fStack_b0);
      dVar30 = this->m_physDeltaRelated;
      this->m_physDeltaRelated = dVar30 + (double)(dt / 60.0);
      lVar12 = *(long *)this->m_currentSlope2;
      bVar9 = true;
      if (lVar12 != 0) goto LAB_10037cd9c;
LAB_10037ce0c:
      this->m_platformerMovingLeft = false;
      this->m_platformerMovingRight = false;
      bVar24 = this->m_isOnGround2;
    }
    if ((bVar24 & 1) == 0) {
      this->m_preLastGroundObject[0] = 0;
      this->m_preLastGroundObject[1] = 0;
      this->m_preLastGroundObject[2] = 0;
      this->m_preLastGroundObject[3] = 0;
      this->m_preLastGroundObject[4] = 0;
      this->m_preLastGroundObject[5] = 0;
      this->m_preLastGroundObject[6] = 0;
      this->m_preLastGroundObject[7] = 0;
    }
  }
  else {
    bVar9 = false;
  }
  if (((*(long *)this->m_lastGroundObject == 0) || (*(long *)this->m_currentSlope2 != 0)) ||
     ((*(byte *)(*(long *)this->m_lastGroundObject + 0x510) & 1) != 0)) {
LAB_10037ce8c:
    bVar7 = false;
  }
  else {
    uVar14 = GameObject__getLastPosition();
    CCPoint__CCPoint_copy(&fStack_90,uVar14);
    (**(code **)(**(long **)this->m_lastGroundObject + 0x540))(&uStack_a0);
    GameObject__getScalePosDelta(&fStack_b0,*(undefined8 *)this->m_lastGroundObject);
    dVar30 = (double)(uStack_a0 & 0xffffffff);
    in_d3 = (double)(ulong)(uint)uStack_a0._4_4_;
    dVar32 = (double)(ulong)(uint)fStack_90;
    in_s4 = fStack_8c;
    if ((((float)uStack_a0 == fStack_90) && (uStack_a0._4_4_ == fStack_8c)) && (fStack_ac == 0.0))
    goto LAB_10037ce8c;
    bVar7 = this->m_isSideways == false;
    fVar28 = (float)uStack_a0;
    if (bVar7) {
      fVar28 = uStack_a0._4_4_;
    }
    dVar30 = (double)(ulong)(uint)fVar28;
    fVar33 = fStack_90;
    if (bVar7) {
      fVar33 = fStack_8c;
    }
    dVar32 = (double)(ulong)(uint)fVar33;
    if ((((this->m_isUpsideDown & 1U) == 0) &&
        (in_d3 = (double)(ulong)(uint)(fStack_ac + fVar28), fStack_ac + fVar28 < fVar33)) ||
       ((bVar7 = false, this->m_isUpsideDown != false && (fVar33 < fVar28 - fStack_ac)))) {
      bVar7 = true;
    }
  }
  iVar10 = CCDictionary__count(*(undefined8 *)this->m_collisionLogBottom);
  if ((bVar7) || (iVar10 == 0)) {
    this->m_isCollidingWithSlope = false;
    pGVar15 = *(GameObject **)this->m_lastGroundObject;
    this->m_lastGroundObject[0] = 0;
    this->m_lastGroundObject[1] = 0;
    this->m_lastGroundObject[2] = 0;
    this->m_lastGroundObject[3] = 0;
    this->m_lastGroundObject[4] = 0;
    this->m_lastGroundObject[5] = 0;
    this->m_lastGroundObject[6] = 0;
    this->m_lastGroundObject[7] = 0;
    bVar7 = (bool)(bVar7 ^ 1);
    if (pGVar15 == (GameObject *)0x0) {
      bVar7 = true;
    }
    if (bVar7) goto LAB_10037d0fc;
    fVar28 = 10.0;
    if (this->m_isPlatformer == false) {
      fVar28 = 5.0;
    }
    dVar30 = 5.43968647586312e-315;
    fVar33 = 20.0;
    if (pGVar15->m_isExtraSticky == false) {
      fVar33 = fVar28;
    }
    fVar33 = fVar33 * dt;
    uVar14 = getObjectRect/*virtual+0x520*/(pGVar15);
    CCRect__CCRect_copy(&fStack_b0,uVar14);
    uVar14 = getObjectRect/*virtual+0x520*/(this);
    CCRect__CCRect_copy(afStack_c0,uVar14);
    CCRect__CCRect_copy(&fStack_d0,&fStack_b0);
    if (this->m_isSideways == true) {
      fStack_c8 = fVar33 + fStack_c8;
      if ((this->m_isUpsideDown & 1U) == 0) {
        fVar28 = (float)CCRect__getMinX(afStack_c0);
        fVar35 = (float)CCRect__getMaxX(&fStack_b0);
        fVar28 = fVar28 - fVar35;
        uVar13 = CCRect__intersectsRect(afStack_c0,&fStack_d0);
      }
      else {
        fVar28 = (float)CCRect__getMinX(&fStack_b0);
        fVar35 = (float)CCRect__getMaxX(afStack_c0);
        fVar28 = fVar28 - fVar35;
        cVar3 = this->m_isSideways;
joined_r0x00010037cfd8:
        if (cVar3 != '\x01') {
          fStack_cc = fStack_cc - fVar33;
          uVar13 = CCRect__intersectsRect(afStack_c0,&fStack_d0);
          goto joined_r0x00010037d08c;
        }
        fStack_d0 = fStack_d0 - fVar33;
        uVar13 = CCRect__intersectsRect(afStack_c0,&fStack_d0);
      }
      if ((uVar13 & 1) == 0) goto LAB_10037cf88;
LAB_10037d090:
      bVar7 = false;
    }
    else {
      fStack_c4 = fVar33 + fStack_c4;
      if ((this->m_isUpsideDown & 1U) != 0) {
        fVar28 = (float)CCRect__getMinY(&fStack_b0);
        fVar35 = (float)CCRect__getMaxY(afStack_c0);
        fVar28 = fVar28 - fVar35;
        cVar3 = this->m_isSideways;
        goto joined_r0x00010037cfd8;
      }
      fVar28 = (float)CCRect__getMinY(afStack_c0);
      fVar35 = (float)CCRect__getMaxY(&fStack_b0);
      fVar28 = fVar28 - fVar35;
      uVar13 = CCRect__intersectsRect(afStack_c0,&fStack_d0);
joined_r0x00010037d08c:
      if ((uVar13 & 1) != 0) goto LAB_10037d090;
LAB_10037cf88:
      bVar7 = *(GameObject **)this->m_collidedObject == (GameObject *)0x0;
      if (!bVar7) {
        pGVar15 = *(GameObject **)this->m_collidedObject;
      }
    }
    if ((fVar33 <= fVar28) || (bVar7)) goto LAB_10037d0fc;
    this->m_isCollidingWithSlope = true;
    CCRect__CCRect_copy(auStack_e0,0x1008b88b0);
    if (this->m_isSideways == true) {
      CCRect__CCRect_copy(&uStack_a0,auStack_e0);
      CCRect__CCRect_copy(&fStack_90,&uStack_a0);
      rect.origin.x = SUB84(dVar30,0);
      rect.origin.y = SUB84(dVar32,0);
      rect.width = SUB84(in_d3,0);
      rect.height = in_s4;
      in_d3 = (double)((ulong)in_d3 & 0xffffffff);
      dVar32 = (double)((ulong)dVar32 & 0xffffffff);
      dVar30 = (double)((ulong)dVar30 & 0xffffffff);
      PlayerObject__handleRotatedCollisionInternal
                (this,0.0,pGVar15,rect,SUB81(&fStack_90,0),true,false);
      goto LAB_10037d0fc;
    }
    CCRect__CCRect_copy(&fStack_90,auStack_e0);
    rect_00.origin.x = SUB84(dVar30,0);
    rect_00.origin.y = SUB84(dVar32,0);
    rect_00.width = SUB84(in_d3,0);
    rect_00.height = in_s4;
    in_d3 = (double)((ulong)in_d3 & 0xffffffff);
    dVar32 = (double)((ulong)dVar32 & 0xffffffff);
    dVar30 = (double)((ulong)dVar30 & 0xffffffff);
    PlayerObject__collidedWithObjectInternal(this,0.0,pGVar15,rect_00,SUB81(&fStack_90,0));
    lVar12 = *(long *)this->m_currentSlope2;
    if (lVar12 != 0) goto LAB_10037d104;
LAB_10037d1b0:
    iVar10 = CCDictionary__count(*(undefined8 *)this->m_collisionLogBottom);
    bVar7 = false;
    if (iVar10 == 0) goto LAB_10037d1c4;
LAB_10037d218:
    dVar32 = this->m_yVelocityRelated;
  }
  else {
LAB_10037d0fc:
    lVar12 = *(long *)this->m_currentSlope2;
    if (lVar12 == 0) goto LAB_10037d1b0;
LAB_10037d104:
    if ((*(byte *)(lVar12 + 0x510) & 1) != 0) goto LAB_10037d1b0;
    uVar14 = GameObject__getLastPosition();
    CCPoint__CCPoint_copy(&fStack_90,uVar14);
    (**(code **)(**(long **)this->m_currentSlope2 + 0x540))(&uStack_a0);
    if (((float)uStack_a0 == fStack_90) &&
       (dVar30 = (double)(ulong)(uint)fStack_8c, uStack_a0._4_4_ == fStack_8c)) goto LAB_10037d1b0;
    dVar30 = (double)(ulong)(uint)uStack_a0._4_4_;
    if ((this->m_isUpsideDown & 1U) == 0) {
      if (fStack_8c <= uStack_a0._4_4_) goto LAB_10037d1b0;
    }
    else if (uStack_a0._4_4_ <= fStack_8c) goto LAB_10037d1b0;
    bVar7 = true;
    CCDictionary__count(*(undefined8 *)this->m_collisionLogBottom);
LAB_10037d1c4:
    this->m_isCollidingWithSlope = false;
    pGVar15 = *(GameObject **)this->m_currentSlope2;
    this->m_currentSlope2[0] = 0;
    this->m_currentSlope2[1] = 0;
    this->m_currentSlope2[2] = 0;
    this->m_currentSlope2[3] = 0;
    this->m_currentSlope2[4] = 0;
    this->m_currentSlope2[5] = 0;
    this->m_currentSlope2[6] = 0;
    this->m_currentSlope2[7] = 0;
    if (!bVar7) goto LAB_10037d218;
    this->m_isCollidingWithSlope = true;
    if (this->m_isSideways == true) {
      CCRect__CCRect_copy(&fStack_90,0x1008b88b0);
      rect_01.origin.x = SUB84(dVar30,0);
      rect_01.origin.y = SUB84(dVar32,0);
      rect_01.width = SUB84(in_d3,0);
      rect_01.height = in_s4;
      PlayerObject__handleRotatedCollisionInternal
                (this,0.0,pGVar15,rect_01,SUB81(&fStack_90,0),false,true);
      goto LAB_10037d218;
    }
    PlayerObject__collidedWithSlopeInternal(this,0.0,pGVar15,true);
    dVar32 = this->m_yVelocityRelated;
  }
  if (((dVar32 != 0.0) && (this->m_stateBoostX < 1)) &&
     (dVar30 = this->m_groundYVelocity, fVar36 * 0.5 < ABS((float)(dVar32 - dVar30)))) {
    if (((dVar32 <= 5.0) || (this->m_isUpsideDown != false)) || (dVar32 <= dVar30)) {
      if (((-5.0 <= dVar32) || (this->m_isUpsideDown == false)) || (dVar30 <= dVar32))
      goto LAB_10037d314;
      dVar30 = 20.0;
      if (dVar32 <= 20.0) {
        dVar30 = dVar32;
      }
      dVar32 = -20.0;
      if (-20.0 <= dVar30) {
        dVar32 = dVar30;
      }
      this->m_yVelocityRelated = dVar32;
      if (dVar32 <= this->m_yVelocity) goto LAB_10037d300;
    }
    else {
      dVar30 = 20.0;
      if (dVar32 <= 20.0) {
        dVar30 = dVar32;
      }
      dVar32 = -20.0;
      if (-20.0 <= dVar30) {
        dVar32 = dVar30;
      }
      this->m_yVelocityRelated = dVar32;
      if (this->m_yVelocity <= dVar32) {
LAB_10037d300:
        PlayerObject__boostPlayer(this,(float)dVar32);
      }
    }
    this->m_currentSlope2[0] = 0;
    this->m_currentSlope2[1] = 0;
    this->m_currentSlope2[2] = 0;
    this->m_currentSlope2[3] = 0;
    this->m_currentSlope2[4] = 0;
    this->m_currentSlope2[5] = 0;
    this->m_currentSlope2[6] = 0;
    this->m_currentSlope2[7] = 0;
    this->m_lastGroundObject[0] = 0;
    this->m_lastGroundObject[1] = 0;
    this->m_lastGroundObject[2] = 0;
    this->m_lastGroundObject[3] = 0;
    this->m_lastGroundObject[4] = 0;
    this->m_lastGroundObject[5] = 0;
    this->m_lastGroundObject[6] = 0;
    this->m_lastGroundObject[7] = 0;
  }
LAB_10037d314:
  if (this->m_isPlatformer == true) {
    dVar32 = this->m_scaleXRelated3;
    if ((dVar32 != 0.0) && ((this->m_isOnGround2 & 1U) == 0)) {
      bVar7 = bVar9;
      if (0 < this->m_stateBoostY) {
        bVar7 = true;
      }
      if (((!bVar7) && (0.05000000074505806 < this->m_physDeltaRelated)) &&
         (fVar36 * 0.5 < ABS((float)(dVar32 - this->m_scaleXRelated2)))) {
        fVar28 = (float)((dVar32 * 0.8999999761581421) / (double)dt);
        dVar32 = this->m_platformerXVelocity + (double)fVar28;
        this->m_platformerXVelocity = dVar32;
        if (2.0 <= ABS(fVar28)) {
          this->m_maybeHasStopped = true;
          this->m_xVelocityRelated = (float)dVar32;
        }
        this->m_scaleXRelatedTime = 0.0;
      }
    }
    dVar32 = this->m_scaleXRelated5;
    if (((dVar32 != 0.0) && (this->m_maybeStateForce2 < 1)) &&
       (dVar30 = this->m_scaleXRelated4, fVar36 * 0.5 < ABS((float)(dVar32 - dVar30)))) {
      if (((dVar32 <= 5.0) || (*(long *)this->m_collidingWithLeft == 0)) || (dVar32 <= dVar30)) {
        if (((-5.0 <= dVar32) || (*(long *)this->m_collidingWithRight == 0)) || (dVar30 <= dVar32))
        goto LAB_10037d690;
        dVar30 = 50.0;
        if (dVar32 <= 50.0) {
          dVar30 = dVar32;
        }
        dVar32 = -50.0;
        if (-50.0 <= dVar30) {
          dVar32 = dVar30;
        }
        this->m_scaleXRelated5 = dVar32;
        if (*(long *)this->m_collidingWithLeft != 0) goto LAB_10037d658;
LAB_10037d66c:
        if (dVar32 <= this->m_platformerXVelocity) goto LAB_10037d678;
      }
      else {
        dVar30 = 50.0;
        if (dVar32 <= 50.0) {
          dVar30 = dVar32;
        }
        dVar32 = -50.0;
        if (-50.0 <= dVar30) {
          dVar32 = dVar30;
        }
        this->m_scaleXRelated5 = dVar32;
LAB_10037d658:
        if (this->m_platformerXVelocity <= dVar32) {
LAB_10037d678:
          this->m_platformerXVelocity = dVar32;
          this->m_affectedByForces = true;
          this->m_isAccelerating = true;
        }
        else if (*(long *)this->m_collidingWithRight != 0) goto LAB_10037d66c;
      }
      this->m_collidingWithLeft[0] = 0;
      this->m_collidingWithLeft[1] = 0;
      this->m_collidingWithLeft[2] = 0;
      this->m_collidingWithLeft[3] = 0;
      this->m_collidingWithLeft[4] = 0;
      this->m_collidingWithLeft[5] = 0;
      this->m_collidingWithLeft[6] = 0;
      this->m_collidingWithLeft[7] = 0;
      this->m_collidingWithRight[0] = 0;
      this->m_collidingWithRight[1] = 0;
      this->m_collidingWithRight[2] = 0;
      this->m_collidingWithRight[3] = 0;
      this->m_collidingWithRight[4] = 0;
      this->m_collidingWithRight[5] = 0;
      this->m_collidingWithRight[6] = 0;
      this->m_collidingWithRight[7] = 0;
    }
LAB_10037d690:
    iVar10 = CCDictionary__count(*(undefined8 *)this->m_collisionLogLeft);
    if (iVar10 == 0) {
      this->m_collidingWithLeft[0] = 0;
      this->m_collidingWithLeft[1] = 0;
      this->m_collidingWithLeft[2] = 0;
      this->m_collidingWithLeft[3] = 0;
      this->m_collidingWithLeft[4] = 0;
      this->m_collidingWithLeft[5] = 0;
      this->m_collidingWithLeft[6] = 0;
      this->m_collidingWithLeft[7] = 0;
      iVar10 = CCDictionary__count(*(undefined8 *)this->m_collisionLogRight);
    }
    else {
      iVar10 = CCDictionary__count(*(undefined8 *)this->m_collisionLogRight);
    }
    if (iVar10 != 0) goto LAB_10037d6a8;
    this->m_collidingWithRight[0] = 0;
    this->m_collidingWithRight[1] = 0;
    this->m_collidingWithRight[2] = 0;
    this->m_collidingWithRight[3] = 0;
    this->m_collidingWithRight[4] = 0;
    this->m_collidingWithRight[5] = 0;
    this->m_collidingWithRight[6] = 0;
    this->m_collidingWithRight[7] = 0;
    this->m_collidedObject[0] = 0;
    this->m_collidedObject[1] = 0;
    this->m_collidedObject[2] = 0;
    this->m_collidedObject[3] = 0;
    this->m_collidedObject[4] = 0;
    this->m_collidedObject[5] = 0;
    this->m_collidedObject[6] = 0;
    this->m_collidedObject[7] = 0;
    dVar32 = this->m_scaleXRelated2;
  }
  else {
LAB_10037d6a8:
    this->m_collidedObject[0] = 0;
    this->m_collidedObject[1] = 0;
    this->m_collidedObject[2] = 0;
    this->m_collidedObject[3] = 0;
    this->m_collidedObject[4] = 0;
    this->m_collidedObject[5] = 0;
    this->m_collidedObject[6] = 0;
    this->m_collidedObject[7] = 0;
    dVar32 = this->m_scaleXRelated2;
  }
  if (dVar32 == 0.0) {
    if ((this->m_scaleXRelated3 == 0.0) ||
       (dVar32 = 0.0, 0.03333333507180214 <= this->m_totalTime - this->m_scaleXRelatedTime))
    goto LAB_10037d6fc;
  }
  else {
    this->m_scaleXRelatedTime = this->m_totalTime;
LAB_10037d6fc:
    this->m_scaleXRelated3 = dVar32;
  }
  this->m_yVelocityRelated = this->m_groundYVelocity;
  this->m_groundYVelocity = 0.0;
  this->m_scaleXRelated2 = 0.0;
  this->m_scaleXRelated5 = this->m_scaleXRelated4;
  this->m_scaleXRelated4 = 0.0;
  if (bVar9) {
    if (this->m_isOnGround2 == true) goto LAB_10037d72c;
LAB_10037d74c:
    bVar24 = this->m_isOnSlope;
  }
  else {
    this->m_physDeltaRelated = 0.0;
    if (this->m_isOnGround2 != true) goto LAB_10037d74c;
LAB_10037d72c:
    this->m_maybeHasStopped = false;
    bVar24 = this->m_isOnSlope;
  }
  if (((bVar24 & 1) == 0) && ((this->m_wasOnSlope & 1U) == 0)) {
    this->m_collidingWithSlopeId = 0;
    dVar32 = this->m_yVelocity;
    if ((this->m_isUpsideDown & 1U) == 0) {
      if (((dVar32 < -2.0) && (-2.0 < this->m_fallSpeed)) && (*(long *)this->m_gameLayer != 0)) {
        GJBaseGameLayer__gameEventTriggered(*(long *)this->m_gameLayer,0x4c,0,(this->GameObject).m_uniqueID);
        dVar32 = this->m_yVelocity;
      }
      if (((dVar32 < -7.0) && (-7.0 < this->m_fallSpeed)) && (*(long *)this->m_gameLayer != 0)) {
        GJBaseGameLayer__gameEventTriggered(*(long *)this->m_gameLayer,0x4d,0,(this->GameObject).m_uniqueID);
        dVar32 = this->m_yVelocity;
      }
      if ((-14.0 <= dVar32) || (this->m_fallSpeed <= -14.0)) goto LAB_10037d75c;
    }
    else {
      if ((2.0 < dVar32) && ((this->m_fallSpeed < 2.0 && (*(long *)this->m_gameLayer != 0)))) {
        GJBaseGameLayer__gameEventTriggered(*(long *)this->m_gameLayer,0x4c,0,(this->GameObject).m_uniqueID);
        dVar32 = this->m_yVelocity;
      }
      if (((7.0 < dVar32) && (this->m_fallSpeed < 7.0)) && (*(long *)this->m_gameLayer != 0)) {
        GJBaseGameLayer__gameEventTriggered(*(long *)this->m_gameLayer,0x4d,0,(this->GameObject).m_uniqueID);
        dVar32 = this->m_yVelocity;
      }
      if ((dVar32 <= 14.0) || (14.0 <= this->m_fallSpeed)) goto LAB_10037d75c;
    }
    if (*(long *)this->m_gameLayer != 0) {
      GJBaseGameLayer__gameEventTriggered(*(long *)this->m_gameLayer,0x4e,0,(this->GameObject).m_uniqueID);
    }
  }
LAB_10037d75c:
  this->m_fallSpeed = this->m_yVelocity;
  this->m_reverseRelated = this->m_reverseRelated + -1;
  return;
}


// ==== PlayerObject::performSlideCheck @ 0x37dbd8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PlayerObject__performSlideCheck(PlayerObject *this)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  float fVar5;
  
  if ((*(long *)this->m_currentSlope2 == 0) ||
     (((((this->m_isOnSlope & 1U) == 0 && (this->m_wasOnSlope != true)) ||
       ((this->m_maybeUpsideDownSlope & 1U) != 0)) ||
      (((*(byte *)(*(long *)this->m_currentSlope2 + 0x512) & 1) != 0 ||
       (fVar5 = ABS(this->m_slopeAngle * 57.29578), fVar5 <= 40.0)))))) {
    this->m_platformerMovingLeft = false;
    this->m_platformerMovingRight = false;
    return;
  }
  bVar1 = this->m_platformerMovingLeft;
  if (this->m_slopeSlidingMaybeRotated == true) {
    if ((this->m_isUpsideDown & 1U) != 0) {
LAB_10037dc60:
      bVar4 = false;
      bVar3 = true;
      goto LAB_10037dc68;
    }
  }
  else if ((this->m_isUpsideDown & 1U) == 0) goto LAB_10037dc60;
  bVar3 = false;
  bVar4 = true;
LAB_10037dc68:
  bVar2 = this->m_platformerMovingRight;
  this->m_platformerMovingLeft = bVar4;
  this->m_platformerMovingRight = bVar3;
  if ((bVar1 != bVar4) || (bVar2 != bVar3)) {
    this->m_changedDirectionsTime = this->m_totalTime;
  }
  this->m_maybeChangedDirectionAngle = (double)fVar5;
  this->m_maybeGoingCorrectSlopeDirection = true;
  return;
}


// ==== PlayerObject::collidedWithObjectInternal @ 0x37f8e4

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

bool PlayerObject__collidedWithObjectInternal
               (PlayerObject *this,float dt,GameObject *object,CCRect rect,bool skipCheck)

{
  GameObject *object_00;
  bool bVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  int iVar13;
  uint uVar14;
  undefined8 uVar15;
  ulong uVar16;
  long lVar17;
  float *pfVar18;
  long lVar19;
  undefined4 *puVar20;
  uint in_w3;
  byte bVar21;
  byte bVar22;
  byte bVar23;
  byte bVar24;
  byte bVar25;
  byte bVar26;
  byte bVar27;
  GameObject *this_00;
  uint uVar28;
  byte bVar29;
  byte *pbVar30;
  byte bVar31;
  bool bVar32;
  float fVar33;
  float fVar34;
  float fVar35;
  float fVar36;
  undefined4 uVar37;
  undefined4 in_register_00005004;
  double dVar38;
  double dVar39;
  double dVar41;
  double dVar42;
  float fVar43;
  ulong uVar44;
  float fVar45;
  float fVar46;
  float fVar47;
  float fVar48;
  double dVar49;
  double dVar50;
  float fVar51;
  float fVar52;
  double dVar53;
  float fVar54;
  double dVar55;
  double dVar56;
  CCRect rect_00;
  double dStack_140;
  float fStack_12c;
  float fStack_f8;
  float fStack_f4;
  float fStack_f0;
  float afStack_ec [3];
  float fStack_e0;
  float afStack_dc [3];
  float fStack_d0;
  float fStack_cc;
  float afStack_c8 [2];
  float fStack_c0;
  float fStack_b8;
  float fStack_b4;
  float fStack_b0;
  float fStack_ac;
  double dVar40;
  
  uVar44 = (ulong)(uint)rect.width;
  dVar55 = (double)(ulong)(uint)rect.origin.y;
  uVar16 = (ulong)skipCheck;
  bVar24 = this->m_holdingLeft;
  bVar21 = (bVar24 ^ 1) & this->m_holdingRight;
  if ((((bVar24 ^ 1) & 1) == 0) && ((this->m_holdingRight & 1U) != 0)) {
    bVar24 = this->m_leftPressedFirst;
    bVar21 = bVar24 ^ 1;
  }
  iVar13 = CCPoint__equals(CONCAT44(in_register_00005004,dt),rect.origin.x,dVar55,uVar44,
                               rect.height,uVar16,0x1008b88b0);
  object_00 = object;
  if (iVar13 == 0) {
    object_00 = (GameObject *)0x0;
  }
  uVar15 = getObjectRect/*virtual+0x520*/(this);
  CCRect__CCRect_copy(&fStack_b8,uVar15);
  if (object_00 != (GameObject *)0x0) {
    uVar16 = getObjectRect/*virtual+0x520*/(object_00);
  }
  CCRect__CCRect_copy(afStack_c8,uVar16);
  bVar22 = this->m_isPlatformer;
  dVar38 = 10.0;
  if ((((bool)bVar22 == true) && ((this->m_wasOnSlope & 1U) == 0)) &&
     (dVar38 = 10.0, this->m_isOnSlope == false)) {
    dVar38 = 5.0;
  }
  dVar50 = 15.0;
  if (this->m_stateScale < 1) {
    dVar50 = dVar38;
  }
  iVar13 = 1;
  if (this->m_isUpsideDown != false) {
    iVar13 = -1;
  }
  dVar38 = dVar50 * (double)iVar13;
  if ((((this->m_isShip & 1U) == 0) && ((this->m_isBird & 1U) == 0)) && ((this->m_isDart & 1U) == 0)
     ) {
    if (((bVar22 & 1) == 0) && ((this->m_isSwing & 1U) != 0)) {
LAB_10037fa1c:
      dVar38 = (double)(iVar13 * 6);
    }
  }
  else if ((bVar22 & 1) == 0) goto LAB_10037fa1c;
  if (this->m_wasOnSlope == true) {
    dVar38 = dVar38 + (double)iVar13 * this->unk_584;
  }
  if (object_00 == (GameObject *)0x0) {
    bVar29 = 0;
    bVar8 = 0.0 < dt && object != (GameObject *)0x0;
    if (0.0 < dt && object != (GameObject *)0x0) goto LAB_10037fa5c;
LAB_10037fb00:
    bVar6 = false;
    bVar7 = true;
    dStack_140 = 0.0;
    bVar11 = true;
  }
  else {
    bVar29 = object_00->m_isPassable;
    bVar8 = 0.0 < dt && object != (GameObject *)0x0;
    if (dt <= 0.0 || object == (GameObject *)0x0) goto LAB_10037fb00;
LAB_10037fa5c:
    uVar15 = GameObject__getLastPosition(object);
    CCPoint__CCPoint_copy(&fStack_e0,uVar15);
    getRealPosition/*virtual+0x540*/(&fStack_f0,object);
    bVar11 = this->m_isSideways == false;
    pfVar18 = &fStack_e0;
    if (bVar11) {
      pfVar18 = afStack_dc;
    }
    fVar48 = *pfVar18;
    pfVar18 = &fStack_f0;
    if (bVar11) {
      pfVar18 = afStack_ec;
    }
    fVar46 = *pfVar18;
    lVar19 = 0;
    if (bVar11) {
      lVar19 = 4;
    }
    lVar17 = getPosition/*virtual+0xc0*/(this);
    fVar51 = *(float *)(lVar17 + lVar19);
    if (this->m_isSideways == true) {
      GameObject__getScalePosDelta(&fStack_d0,object);
    }
    else {
      GameObject__getScalePosDelta(&fStack_d0,object);
      fStack_d0 = fStack_cc;
    }
    fVar47 = fStack_d0;
    if (fVar46 <= fVar51) {
      fVar47 = -fStack_d0;
    }
    fVar51 = fVar48 + fVar47;
    if (fStack_d0 == 0.0) {
      fVar51 = fVar48;
    }
    dVar55 = (double)(ulong)(uint)fStack_e0;
    if ((fStack_f0 == fStack_e0) &&
       (dVar55 = (double)(ulong)(uint)afStack_dc[0], afStack_ec[0] == afStack_dc[0])) {
      bVar6 = false;
      bVar7 = true;
      dStack_140 = 0.0;
      bVar11 = true;
    }
    else {
      bVar11 = this->m_isUpsideDown;
      if ((((bVar11 & 1U) == 0) && (fVar51 < fVar46)) || ((bVar11 != false && (fVar46 < fVar51)))) {
        fVar48 = (fVar46 - fVar51) / dt;
        fVar46 = ABS(fVar48);
        dVar55 = (double)fVar46;
        bVar6 = 5.0 < fVar46;
        uVar44 = 0;
        dVar39 = -1.0;
        if (bVar11 == false) {
          dVar39 = 1.0;
        }
        dVar38 = dVar38 + dVar39 * dVar55;
        dStack_140 = (double)fVar48;
        bVar11 = false;
        if ((this->m_isPlatformer & 1U) == 0) {
          this->m_groundYVelocity = dStack_140;
          bVar7 = true;
        }
        else {
          bVar7 = true;
        }
      }
      else {
        bVar6 = false;
        bVar7 = fVar51 < fVar46;
        if (bVar11 == false) {
          bVar7 = fVar51 != fVar46 && fVar51 >= fVar46;
        }
        bVar7 = (bool)(bVar7 ^ 1);
        bVar11 = true;
        dStack_140 = 0.0;
      }
    }
    bVar22 = this->m_isPlatformer;
  }
  fVar48 = 5.0;
  if ((bVar22 & 1) == 0) {
    fVar48 = 0.0;
  }
  if (((this->m_stateHitHead < 1) && ((bVar22 & 1) == 0)) && (this->m_stateFlipGravity < 1)) {
    bVar22 = 0;
  }
  else {
    bVar22 = bVar29 ^ 1;
  }
  bVar10 = this->m_isSideways;
  pfVar18 = (float *)getPosition/*virtual+0xc0*/(this);
  if (bVar10 == true) {
    fVar46 = *pfVar18;
    fVar51 = (this->GameObject).m_lastPosition.x;
  }
  else {
    fVar46 = pfVar18[1];
    fVar51 = (this->GameObject).m_lastPosition.y;
  }
  fVar46 = fVar46 - fVar51;
  getPosition/*virtual+0xc0*/(this);
  lVar19 = getPosition/*virtual+0xc0*/(this);
  fVar51 = fStack_ac;
  fVar47 = *(float *)(lVar19 + 4);
  fVar52 = 1.0;
  fVar45 = -1.0;
  if (this->m_isUpsideDown == false) {
    fVar45 = 1.0;
  }
  lVar19 = getPosition/*virtual+0xc0*/(this);
  fVar54 = fStack_ac;
  fVar43 = *(float *)(lVar19 + 4);
  if (this->m_isUpsideDown == false) {
    fVar52 = -1.0;
  }
  getPosition/*virtual+0xc0*/(this);
  if (((this->m_isUpsideDown & 1U) != 0) || (fVar46 <= 0.0)) {
    bVar25 = this->m_isUpsideDown ^ 1;
    if (0.0 <= fVar46) {
      bVar25 = 1;
    }
  }
  else {
    bVar25 = 0;
  }
  fVar33 = (float)CCRect__getMinX(afStack_c8);
  fVar34 = (float)CCRect__getMaxX(afStack_c8);
  fStack_12c = (float)CCRect__getMaxY(afStack_c8);
  dVar39 = (double)fStack_12c;
  fVar35 = (float)CCRect__getMinY(afStack_c8);
  dVar56 = (double)fVar35;
  if ((this->m_isDart == true) && (this->m_stateDartSlide < 1)) {
    bVar31 = 0;
    bVar23 = 1;
    cVar2 = this->m_isPlatformer;
joined_r0x0001003804c4:
    if (cVar2 == '\x01') {
      uVar15 = getPosition/*virtual+0xc0*/(this);
      CCPoint__CCPoint_copy(&fStack_f0,uVar15);
      getPosition/*virtual+0xc0*/(this);
      getPosition/*virtual+0xc0*/(this);
      lVar19 = getPosition/*virtual+0xc0*/(this);
      fVar46 = fStack_ac;
      fVar47 = *(float *)(lVar19 + 4);
      lVar19 = getPosition/*virtual+0xc0*/(this);
      fVar51 = fStack_ac;
      fVar52 = *(float *)(lVar19 + 4);
      if (bVar8) {
        uVar15 = GameObject__getLastPosition(object);
        CCPoint__CCPoint_copy(&fStack_e0,uVar15);
        getRealPosition/*virtual+0x540*/(&fStack_d0,object);
        bVar8 = this->m_isSideways;
        lVar17 = getPosition/*virtual+0xc0*/(this);
        lVar19 = 0;
        if (bVar8 == false) {
          lVar19 = 4;
        }
        fVar45 = *(float *)(lVar17 + lVar19);
        bVar8 = this->m_isSideways;
        pfVar18 = afStack_dc;
        if (bVar8 == false) {
          pfVar18 = &fStack_e0;
        }
        fVar54 = *pfVar18;
        pfVar18 = &fStack_cc;
        if (bVar8 == false) {
          pfVar18 = &fStack_d0;
        }
        fVar43 = *pfVar18;
        if (bVar8 == true) {
          GameObject__getScalePosDelta(&fStack_f8,object);
        }
        else {
          GameObject__getScalePosDelta(&fStack_f8,object);
          fStack_f4 = fStack_f8;
        }
        fVar36 = fVar43 - fVar54;
        bVar11 = 0.0 <= fVar36 + fStack_f4;
        bVar8 = fVar36 <= fStack_f4;
        if (fVar43 <= fVar45) {
          fStack_f4 = -fStack_f4;
        }
        dVar55 = (double)((fVar43 - (fVar54 + fStack_f4)) / dt);
        if ((this->m_isOnSlope & 1U) != 0) goto LAB_100380d28;
LAB_100380cfc:
        if (((this->m_wasOnSlope & 1U) != 0) ||
           (this->m_totalTime - this->m_slopeEndTime < 0.20000000298023224)) goto LAB_100380d28;
        dVar38 = (double)(fVar47 + fVar46 * 0.5) - dVar50;
        dVar50 = dVar50 + (double)(fVar52 - fVar51 * 0.5);
        if (object == (GameObject *)0x0) goto LAB_100380dd4;
LAB_100380d84:
        uVar28 = (uint)(*(GameObject **)this->m_collidingWithRight == object);
        object = (GameObject *)(ulong)(*(GameObject **)this->m_collidingWithLeft == object);
      }
      else {
        dVar55 = 0.0;
        bVar11 = true;
        bVar8 = true;
        if ((this->m_isOnSlope & 1U) == 0) goto LAB_100380cfc;
LAB_100380d28:
        lVar19 = getPosition/*virtual+0xc0*/(this);
        fVar46 = -1.0;
        if (this->m_isUpsideDown == false) {
          fVar46 = 1.0;
        }
        dVar38 = (double)(*(float *)(lVar19 + 4) + fVar46 * fStack_ac * 0.5);
        lVar19 = getPosition/*virtual+0xc0*/(this);
        dVar50 = (double)*(float *)(lVar19 + 4);
        if (object != (GameObject *)0x0) goto LAB_100380d84;
LAB_100380dd4:
        uVar28 = 0;
      }
      CCRect__CCRect(fStack_b8,fVar48 * 0.5 + fStack_b4,fStack_b0,fStack_ac - fVar48,&fStack_e0
                         );
      if (((bVar29 & 1) == 0) &&
         (uVar14 = CCRect__intersectsRect(&fStack_e0,afStack_c8),
         ((uVar14 | (uint)object | uVar28) & 1) != 0)) {
        bVar6 = false;
        bVar7 = true;
        bVar10 = false;
        if (dVar38 < dVar39) {
          bVar6 = false;
          bVar7 = false;
          bVar10 = true;
          if (!NAN(dVar38) && !NAN(dVar56)) {
            bVar6 = dVar38 < dVar56;
            bVar7 = dVar38 == dVar56;
            bVar10 = false;
          }
        }
        if ((!bVar7 && bVar6 == bVar10) || ((dVar50 < dVar39 && (dVar56 < dVar50)))) {
          this->m_scaleXRelated4 = dVar55;
          if ((((ulong)object & 1) != 0) ||
             (pfVar18 = (float *)getPosition/*virtual+0xc0*/(this),
             afStack_c8[0] + fStack_c0 * 0.5 < *pfVar18 && uVar28 == 0)) {
            if (object_00 == (GameObject *)0x0) {
              iVar13 = 0;
            }
            else {
              iVar13 = object_00->m_uniqueID;
            }
            dVar55 = this->m_collidedLeftMaxX;
            bVar8 = true;
            if (((double)fVar34 <= dVar55) && (bVar8 = false, !NAN(dVar55))) {
              bVar8 = dVar55 == 0.0;
            }
            dVar38 = (double)fVar34;
            if (!bVar8) {
              dVar38 = dVar55;
            }
            this->m_collidedLeftMaxX = dVar38;
            if (iVar13 != 0) {
              if (this->m_lastCollisionLeft != iVar13) {
                this->m_lastCollisionLeft = iVar13;
                if (*(long *)this->m_collisionLogLeft != 0) {
                  CCDictionary__setObject(*(long *)this->m_collisionLogLeft,
                                      *(undefined8 *)this->m_maybeLastGroundObject,(long)iVar13);
                }
              }
              *(GameObject **)this->m_collidingWithLeft = object_00;
              this->m_collidingWithRight[0] = 0;
              this->m_collidingWithRight[1] = 0;
              this->m_collidingWithRight[2] = 0;
              this->m_collidingWithRight[3] = 0;
              this->m_collidingWithRight[4] = 0;
              this->m_collidingWithRight[5] = 0;
              this->m_collidingWithRight[6] = 0;
              this->m_collidingWithRight[7] = 0;
            }
            lVar19 = getPosition/*virtual+0xc0*/(this);
            CCPoint__CCPoint(fVar34 + fStack_b0 * 0.5,*(undefined4 *)(lVar19 + 4),&fStack_d0);
            setPosition/*virtual+0xb8*/(this,&fStack_d0);
            if ((this->m_platformerXVelocity < 0.0) && (((bVar24 ^ 1) & 1) != 0 || bVar11)) {
              this->m_platformerXVelocity = 0.0;
            }
            if ((this->m_isDashing == true) &&
               ((*(long *)this->m_dashRing == 0 ||
                ((*(byte *)(*(long *)this->m_dashRing + 0x73c) & 1) == 0)))) {
              PlayerObject__stopDashing(this);
              this->m_jumpBuffered = false;
            }
            if (this->m_platformerMovingLeft == true) goto LAB_100381014;
          }
          else {
            PlayerObject__updateCollideRight(fVar33,this,object_00);
            lVar19 = getPosition/*virtual+0xc0*/(this);
            CCPoint__CCPoint(fVar33 + fStack_b0 * -0.5,*(undefined4 *)(lVar19 + 4),&fStack_d0);
            setPosition/*virtual+0xb8*/(this,&fStack_d0);
            if ((0.0 < this->m_platformerXVelocity) && (((bVar21 ^ 1) & 1) != 0 || bVar8)) {
              this->m_platformerXVelocity = 0.0;
            }
            if ((this->m_isDashing == true) &&
               ((*(long *)this->m_dashRing == 0 ||
                ((*(byte *)(*(long *)this->m_dashRing + 0x73c) & 1) == 0)))) {
              PlayerObject__stopDashing(this);
              this->m_jumpBuffered = false;
            }
            if ((this->m_platformerMovingRight & 1U) != 0) {
LAB_100381014:
              this->m_maybeSlidingTime = 0;
            }
          }
        }
      }
    }
    if ((bVar23 != 0) && (((this->m_isPlatformer | bVar29) & 1) == 0)) {
      virtual_0x528(&fStack_e0,0x3e99999a,0x3e99999a,this);
      iVar13 = CCRect__intersectsRect(afStack_c8,&fStack_e0);
      if (iVar13 != 0) {
        if (((bVar31 != 0) && (this->m_lastFlipTime != 0.0)) &&
           (this->m_totalTime - this->m_lastFlipTime < 0.10000000149011612)) {
          if ((this->m_isUpsideDown & 1U) == 0) {
            puVar20 = (undefined4 *)getPosition/*virtual+0xc0*/(this);
            uVar37 = *puVar20;
            fStack_ac = fStack_ac * -0.5;
          }
          else {
            puVar20 = (undefined4 *)getPosition/*virtual+0xc0*/(this);
            uVar37 = *puVar20;
            fStack_ac = fStack_ac * 0.5;
            fVar35 = fStack_12c;
          }
          CCPoint__CCPoint(uVar37,fVar35 + fStack_ac,&fStack_f0);
          setPosition/*virtual+0xb8*/(this,&fStack_f0);
          PlayerObject__hitGround(this,object_00,true);
          this->m_isOnGround2 = false;
          return true;
        }
        if (this->m_isSpider == true) {
          fVar48 = (float)CCRect__getMaxX(afStack_c8);
          fVar46 = (float)CCRect__getMaxX(&fStack_e0);
          if (((fVar48 < fVar46) && (this->m_lastSpiderFlipTime != 0.0)) &&
             (this->m_totalTime - this->m_lastSpiderFlipTime < 0.03999999910593033))
          goto LAB_100381744;
        }
        if ((object_00 != (GameObject *)0x0) &&
           (iVar13 = virtual_0x6f8(object_00), iVar13 == 0x15))
        goto LAB_100381724;
        if ((this->m_maybeCanRunIntoBlocks & 1U) == 0) {
          lVar19 = GameManager__sharedState();
          (**(code **)(**(long **)(lVar19 + 0x1f8) + 0x4f8))(*(long **)(lVar19 + 0x1f8),this,0);
          return true;
        }
        if ((this->m_ignoreDamage & 1U) == 0) {
          this->m_maybeIsColliding = true;
          return true;
        }
      }
    }
    bVar8 = false;
  }
  else {
    if ((this->m_isOnSlope & 1U) == 0) {
      bVar27 = this->m_wasOnSlope;
      if (((bVar27 & 1) != 0) || (*(long *)(this->m_potentialSlopeMap + 0x18) != 0)) {
        if (object_00 == (GameObject *)0x0) {
          bVar27 = 1;
        }
        goto LAB_10037fdd8;
      }
      bVar32 = false;
      bVar10 = false;
      bVar4 = 0;
      if (object_00 != (GameObject *)0x0) goto LAB_10037ffa0;
LAB_10037fff4:
      bVar12 = false;
    }
    else {
      bVar27 = 1;
LAB_10037fdd8:
      bVar4 = 0;
      bVar32 = false;
      bVar10 = false;
      pbVar30 = this->m_potentialSlopeMap + 0x10;
      do {
        pbVar30 = *(byte **)pbVar30;
        if (pbVar30 == (byte *)0x0) goto LAB_10037ff8c;
        this_00 = *(GameObject **)(pbVar30 + 0x18);
        if (((bVar27 & 1) == 0) && (this_00 != *(GameObject **)this->m_currentSlope)) {
          getObjectRect/*virtual+0x520*/(this_00);
          fVar36 = (float)CCRect__getMinX();
          pfVar18 = (float *)getPosition/*virtual+0xc0*/(object_00);
          if (fVar36 < *pfVar18) {
            getObjectRect/*virtual+0x520*/(this_00);
            fVar36 = (float)CCRect__getMaxX();
            pfVar18 = (float *)getPosition/*virtual+0xc0*/(object_00);
            if (*pfVar18 < fVar36) goto LAB_10037fe98;
          }
        }
        else {
LAB_10037fe98:
          virtual_0x528(&fStack_e0,0x3f99999a,0x3f8ccccd,this_00);
          iVar13 = CCRect__intersectsRect(afStack_c8,&fStack_e0);
          if (iVar13 != 0) {
            uVar15 = 0x3f8ccccd;
            virtual_0x528(&fStack_f0,0x3f99999a,this_00);
            iVar13 = CCRect__intersectsRect(&fStack_b8,&fStack_f0);
            if (iVar13 != 0) {
              rect_00.origin.x = (float)CCRect__CCRect_copy(&fStack_e0,afStack_c8);
              rect_00.origin.y = (float)uVar15;
              rect_00.width = SUB84(dVar55,0);
              rect_00.height = (undefined4)uVar44;
              uVar44 = uVar44 & 0xffffffff;
              dVar55 = (double)((ulong)dVar55 & 0xffffffff);
              dVar40 = GameObject__slopeYPos(this_00,rect_00);
              bVar12 = GameObject__slopeFloorTop(this_00);
              dVar41 = dVar40 + -2.0;
              if (dVar39 <= dVar40 + 2.0) {
                if (bVar12) {
                  bVar10 = (bool)(*(GameObject **)this->m_currentSlope == this_00 | bVar10);
                  if (dVar41 <= dVar56) goto LAB_10037ff70;
                }
                else {
                  bVar10 = true;
                  if (dVar41 <= dVar56) goto LAB_10037ff64;
                }
              }
              else if (dVar41 <= dVar56) {
                if (!bVar12) {
LAB_10037ff64:
                  if (*(GameObject **)this->m_currentSlope != this_00) goto LAB_10037fe04;
                }
LAB_10037ff70:
                bVar4 = 1;
                bVar32 = true;
                goto joined_r0x00010037ff7c;
              }
LAB_10037fe04:
              bVar4 = 1;
            }
          }
        }
joined_r0x00010037ff7c:
      } while ((!bVar10) || (!bVar32));
      bVar32 = true;
      bVar10 = true;
LAB_10037ff8c:
      if (object_00 == (GameObject *)0x0) goto LAB_10037fff4;
LAB_10037ffa0:
      iVar13 = virtual_0x6f8(object_00);
      bVar12 = iVar13 == 0x15;
    }
    dVar40 = dVar38 + (double)(fVar47 + fVar45 * fVar51 * -0.5);
    dVar55 = dVar40 - (double)fVar46;
    CCRect__CCRect(fVar48 * 0.5 + fStack_b8,fStack_b4,fStack_b0 - fVar48,fStack_ac,&fStack_e0);
    if (((this->m_isShip & 1U) == 0) && ((this->m_isBird & 1U) == 0)) {
      if (((this->m_isDart & 1U) == 0) &&
         ((((this->m_isSwing & 1U) == 0 && ((this->m_isBall & 1U) == 0)) &&
          ((this->m_isRobot & 1U) == 0)))) {
        bVar27 = this->m_isSpider ^ 1;
        bVar23 = this->m_isUpsideDown;
      }
      else {
        bVar27 = 0;
        bVar23 = this->m_isUpsideDown;
      }
      if ((bVar23 & 1) == 0) goto LAB_1003800c4;
      if ((((this->m_isDart & 1U) != 0) || ((this->m_isSwing & 1U) != 0)) ||
         (this->m_isBall == true)) goto LAB_100380040;
      bVar23 = 0;
joined_r0x000100380048:
      if ((dVar39 <= dVar40) || (dVar39 <= dVar55)) goto LAB_1003800f0;
LAB_1003800d8:
      bVar31 = 0;
      bVar25 = 0;
      cVar2 = this->m_isPlatformer;
joined_r0x000100380130:
      if (cVar2 != '\x01') goto LAB_100380178;
LAB_100380134:
      if (((this->m_isOnSlope & 1U) != 0) || (this->m_wasOnSlope == true)) {
        if (bVar31 == 0) {
          if (this->m_maybeUpsideDownSlope != false) goto LAB_10038015c;
        }
        else if ((this->m_maybeUpsideDownSlope & 1U) == 0) {
LAB_10038015c:
          bVar4 = 0;
        }
      }
      if (((in_w3 & 1) != 0) || (iVar13 = CCRect__intersectsRect(&fStack_e0,afStack_c8), iVar13 != 0))
      goto LAB_100380178;
      goto LAB_1003804b8;
    }
    bVar27 = 0;
    if ((this->m_isUpsideDown & 1U) != 0) {
LAB_100380040:
      bVar23 = bVar29 ^ 1;
      goto joined_r0x000100380048;
    }
LAB_1003800c4:
    bVar23 = 1;
    if ((dVar56 < dVar40) && (dVar56 < dVar55)) goto LAB_1003800d8;
LAB_1003800f0:
    if (((bVar25 | this->m_isPlatformer & bVar12 ^ 0xffU) & 1) == 0) {
      bVar25 = this->m_maybeTouchedBreakableBlock ^ 1;
      bVar31 = 1;
      cVar2 = this->m_isPlatformer;
      goto joined_r0x000100380130;
    }
    bVar25 = 0;
    bVar31 = 1;
    if (this->m_isPlatformer == true) goto LAB_100380134;
LAB_100380178:
    dVar38 = (double)(fVar43 + fVar52 * fVar54 * -0.5) - dVar38;
    dVar41 = dVar38 - (double)fVar46;
    if (((bVar23 | bVar22) & 1) == 0) {
LAB_1003802cc:
      bVar23 = 1;
LAB_1003802d0:
      bVar10 = this->m_isUpsideDown;
      if ((bVar10 & 1U) == 0) {
        if ((((this->m_isShip & 1U) == 0) && ((this->m_isBird & 1U) == 0)) &&
           (((this->m_isDart & 1U) == 0 &&
            (((this->m_isSwing & 1U) == 0 && (this->m_isBall != true)))))) {
          bVar26 = 0;
          bVar3 = bVar22;
        }
        else {
          bVar26 = bVar29 ^ 1;
          bVar3 = bVar26 | bVar22;
        }
      }
      else {
        bVar26 = 1;
        bVar3 = bVar22 | 1;
      }
      if ((bVar23 & bVar3) != 1) {
LAB_100380b84:
        cVar2 = this->m_isPlatformer;
        goto joined_r0x0001003804c4;
      }
      if (bVar10 == false) {
        dVar40 = dVar38;
        dVar55 = dVar41;
      }
      if (object_00 != (GameObject *)0x0) {
        iVar13 = object_00->m_uniqueID;
        if (dVar56 < dVar40) goto LAB_10038035c;
LAB_100380378:
        if ((bVar10 & 1U) != 0) goto LAB_1003803cc;
LAB_1003803b8:
        if (((this->m_isBird & bVar12) == 0) || ((this->m_isPlatformer & 1U) != 0))
        goto LAB_1003803cc;
        virtual_0x528(&fStack_f0,0x3e99999a,0x3e99999a,this);
        iVar13 = CCRect__intersectsRect(afStack_c8,&fStack_f0);
        if (iVar13 != 0) goto LAB_100381724;
LAB_100380b80:
        bVar23 = 0;
        goto LAB_100380b84;
      }
      iVar13 = 0;
      if (dVar40 <= dVar56) goto LAB_100380378;
LAB_10038035c:
      if (dVar55 <= dVar56) goto LAB_100380378;
      if (bVar10 == false) {
        if (iVar13 != this->m_unk510) goto LAB_1003804b8;
        goto LAB_1003803b8;
      }
      if (iVar13 != this->m_unk50C) {
LAB_1003804b8:
        bVar23 = 1;
        cVar2 = this->m_isPlatformer;
        goto joined_r0x0001003804c4;
      }
LAB_1003803cc:
      dVar55 = this->m_yVelocity;
      if (((dVar55 < 0.0) &&
          (((this->m_isPlatformer != true || (this->m_yVelocityRelated <= 0.0)) &&
           ((this->m_wasOnSlope & 1U) == 0 && !bVar6)))) || ((bool)(bVar4 & bVar32))) {
        if ((bVar11 || bVar31 != 0) || ((bVar10 ^ 1U) & 1) != 0) {
          if ((!bVar7 && bVar31 == 1) && (bVar10 & 1U) == 0) {
            puVar20 = (undefined4 *)getPosition/*virtual+0xc0*/(this);
            CCPoint__CCPoint(*puVar20,fVar35 + fStack_ac * -0.5,&fStack_f0);
            setPosition/*virtual+0xb8*/(this,&fStack_f0);
            if (this->m_isUpsideDown == true) {
              if ((((this->m_isShip & 1U) == 0) && ((this->m_isBird & 1U) == 0)) &&
                 ((this->m_isDart & 1U) == 0)) {
                bVar22 = this->m_isSwing;
              }
              else {
                bVar22 = 1;
              }
            }
            else {
              bVar22 = 0;
            }
            bVar11 = this->m_isOnGround;
            bVar6 = this->m_isOnGround2;
            dVar38 = this->m_lastLandTime;
            PlayerObject__hitGround(this,(GameObject *)0x0,(bool)(bVar22 & 1));
            this->m_isOnGround = bVar11;
            this->m_isOnGround2 = bVar6;
            this->m_lastLandTime = dVar38;
            if (bVar12 == false && (bVar29 & 1) == 0) {
              PlayerObject__updateCollideTop(fVar35,this,object_00);
            }
            dVar38 = (double)(int)dVar55;
            if (dVar55 != dVar38) {
              dVar55 = (double)(long)((dVar55 - dVar38) * 1000.0) / 1000.0 + dVar38;
            }
            dVar38 = this->m_groundYVelocity + -1.0;
            if (dVar55 <= dVar38) {
              dVar38 = dVar55;
            }
            dVar55 = (double)(int)dVar38;
            if (dVar38 != dVar55) {
              dVar38 = (double)(long)((dVar38 - dVar55) * 1000.0) / 1000.0 + dVar55;
            }
            this->m_yVelocity = dVar38;
            if (0 < this->m_stateFlipGravity) {
              PlayerObject__flipGravity(this,(bool)((this->m_isUpsideDown ^ 0xffU) & 1),true);
              dVar55 = 2.0;
              if (this->m_isUpsideDown == false) {
                dVar55 = -2.0;
              }
              dVar38 = (double)(int)dVar55;
              if (dVar55 != dVar38) {
                dVar55 = (double)(long)((dVar55 - dVar38) * 1000.0) / 1000.0 + dVar38;
              }
              this->m_yVelocity = dVar55;
              this->m_maybeIsBoosted = true;
              this->m_isOnGround2 = false;
              if (0 < this->m_stateNoAutoJump) {
                this->m_isOnGround = false;
                this->m_jumpBuffered = false;
                this->m_stateRingJump = false;
              }
            }
            if ((bVar25 & 1) != 0) {
              this->m_maybeTouchedBreakableBlock = true;
              if (*(long *)this->m_gameLayer == 0) {
                GameObject__destroyObject(object_00);
              }
              else {
                GJBaseGameLayer__destroyObject(*(long *)this->m_gameLayer,object_00);
              }
            }
          }
          goto LAB_100380b80;
        }
        puVar20 = (undefined4 *)getPosition/*virtual+0xc0*/(this);
        CCPoint__CCPoint(*puVar20,fVar35 + fStack_ac * -0.5,&fStack_f0);
        setPosition/*virtual+0xb8*/(this,&fStack_f0);
        if (this->m_isUpsideDown == true) {
          if ((((this->m_isShip & 1U) == 0) && ((this->m_isBird & 1U) == 0)) &&
             ((this->m_isDart & 1U) == 0)) {
            PlayerObject__hitGround(this,object_00,(bool)(this->m_isSwing & 1));
            goto joined_r0x00010038075c;
          }
          PlayerObject__hitGround(this,object_00,true);
          if (object_00 == (GameObject *)0x0) goto LAB_10038110c;
LAB_100380760:
          iVar13 = object_00->m_uniqueID;
          dVar38 = this->m_collidedBottomMaxY;
        }
        else {
          PlayerObject__hitGround(this,object_00,false);
joined_r0x00010038075c:
          if (object_00 != (GameObject *)0x0) goto LAB_100380760;
LAB_10038110c:
          iVar13 = 0;
          dVar38 = this->m_collidedBottomMaxY;
        }
        dVar40 = dVar56;
        if (dVar38 != 0.0) {
          if ((this->m_isUpsideDown & 1U) == 0) {
            if (dVar56 <= dVar38) {
              dVar40 = dVar38;
            }
          }
          else if (dVar38 <= dVar56) {
            dVar40 = dVar38;
          }
        }
        this->m_collidedBottomMaxY = dVar40;
        if ((iVar13 != 0) && (this->m_lastCollisionBottom != iVar13)) {
          this->m_lastCollisionBottom = iVar13;
          if (*(long *)this->m_collisionLogBottom != 0) {
            CCDictionary__setObject(*(long *)this->m_collisionLogBottom,
                                *(undefined8 *)this->m_maybeLastGroundObject,(long)iVar13);
          }
        }
        if (object != (GameObject *)0x0) {
          *(GameObject **)this->m_lastGroundObject = object;
          if (object->m_isDontBoostY == true) {
            this->m_stateBoostX = 2;
          }
          if (object->m_isDontBoostX == true) {
            this->m_stateBoostY = 2;
          }
        }
        this->m_groundYVelocity = dStack_140;
        dVar38 = (double)(int)dVar55;
        if (dVar55 != dVar38) {
          dVar55 = (double)(long)((dVar55 - dVar38) * 1000.0) / 1000.0 + dVar38;
        }
        if (dVar55 <= dStack_140) {
          dStack_140 = dVar55;
        }
        dVar55 = (double)(int)dStack_140;
        if (dStack_140 != dVar55) {
          dStack_140 = (double)(long)((dStack_140 - dVar55) * 1000.0) / 1000.0 + dVar55;
        }
        bVar31 = 0;
        bVar23 = 0;
        this->m_yVelocity = dStack_140;
        cVar2 = this->m_isPlatformer;
        goto joined_r0x0001003804c4;
      }
      if (bVar31 != 0) {
        dVar38 = -dVar55;
        if (bVar10 == false) {
          dVar38 = dVar55;
        }
        if ((0.0 < dVar38) && (*(long *)this->m_gameLayer != 0)) {
          GJBaseGameLayer__gameEventTriggered(*(long *)this->m_gameLayer,6,0,(this->GameObject).m_uniqueID);
        }
      }
      puVar20 = (undefined4 *)getPosition/*virtual+0xc0*/(this);
      CCPoint__CCPoint(*puVar20,fVar35 + fStack_ac * -0.5,&fStack_f0);
      setPosition/*virtual+0xb8*/(this,&fStack_f0);
      if ((bVar27 & 1) != 0) {
        PlayerObject__checkSnapJumpToObject(this,object_00);
      }
      if (((bVar26 | bVar22 ^ 0xff) & 1) == 0) {
        this->m_yVelocity = 0.0;
        bVar21 = this->m_isUpsideDown;
        bVar24 = bVar31 ^ 1 | bVar12 | bVar29;
joined_r0x000100380580:
        if ((bVar21 & 1) == 0) goto LAB_100381060;
LAB_100380584:
        fVar48 = fStack_12c;
        fStack_12c = fVar35;
        if ((bVar24 & 1) == 0) goto LAB_100381080;
joined_r0x000100380594:
        if (bVar31 != 0) {
LAB_100381090:
          if (this->m_isPlatformer == true) {
            PlayerObject__exitPlatformerAnimateJump(this);
          }
          bVar21 = 1;
          goto joined_r0x0001003810ec;
        }
        PlayerObject__updateCollideBottom(fStack_12c,this,object_00);
      }
      else {
        if ((this->m_isUpsideDown & 1U) == 0) {
          if ((((this->m_isShip & 1U) == 0) && ((this->m_isBird & 1U) == 0)) &&
             ((this->m_isDart & 1U) == 0)) {
            bVar21 = this->m_isSwing;
          }
          else {
            bVar21 = 1;
          }
        }
        else {
          bVar21 = 0;
        }
        if (bVar31 == 0) {
          PlayerObject__hitGround(this,object_00,(bool)(bVar21 & 1));
          bVar21 = this->m_isUpsideDown;
          bVar24 = bVar12 | bVar29 | 1;
          goto joined_r0x000100380580;
        }
        bVar8 = this->m_isOnGround;
        bVar6 = this->m_isOnGround2;
        dVar55 = this->m_lastLandTime;
        PlayerObject__hitGround(this,(GameObject *)0x0,(bool)(bVar21 & 1));
        this->m_isOnGround = bVar8;
        this->m_isOnGround2 = bVar6;
        this->m_lastLandTime = dVar55;
        bVar24 = bVar31 ^ 1 | bVar12 | bVar29;
        if ((this->m_isUpsideDown & 1U) != 0) goto LAB_100380584;
LAB_100381060:
        fVar48 = fVar35;
        if ((bVar24 & 1) != 0) goto joined_r0x000100380594;
LAB_100381080:
        PlayerObject__updateCollideTop(fVar48,this,object_00);
        if (bVar31 != 0) goto LAB_100381090;
      }
      if (object != (GameObject *)0x0) {
        *(GameObject **)this->m_lastGroundObject = object;
        if (object->m_isDontBoostY == true) {
          this->m_stateBoostX = 2;
        }
        if (object->m_isDontBoostX == true) {
          this->m_stateBoostY = 2;
        }
      }
      bVar21 = 0;
      this->m_groundYVelocity = dStack_140;
joined_r0x0001003810ec:
      if ((((bVar27 & 1) != 0) && (0 < this->m_stateNoAutoJump)) && (this->m_padRingRelated == true)
         ) {
        this->m_jumpBuffered = false;
      }
      if ((((this->m_isShip & 1U) == 0) && ((this->m_isBird & 1U) == 0)) &&
         ((this->m_isDart & 1U) == 0)) {
        if (!bVar11 && ((this->m_isSwing ^ 1U | bVar21 ^ 0xff) & 1) == 0) {
LAB_10038164c:
          dVar55 = this->m_groundYVelocity;
          dVar38 = (double)(int)dVar55;
          if (dVar55 != dVar38) {
            dVar55 = (double)(long)((dVar55 - dVar38) * 1000.0) / 1000.0 + dVar38;
          }
          this->m_yVelocity = dVar55;
        }
      }
      else if (!bVar11 && ((bVar21 ^ 0xff) & 1) == 0) goto LAB_10038164c;
      if ((bVar21 != 0) && (0 < this->m_stateFlipGravity)) {
        PlayerObject__flipGravity(this,(bool)((this->m_isUpsideDown ^ 0xffU) & 1),true);
        dVar55 = 2.0;
        if (this->m_isUpsideDown == false) {
          dVar55 = -2.0;
        }
        dVar38 = (double)(int)dVar55;
        if (dVar55 != dVar38) {
          dVar55 = (double)(long)((dVar55 - dVar38) * 1000.0) / 1000.0 + dVar38;
        }
        this->m_yVelocity = dVar55;
        this->m_maybeIsBoosted = true;
        this->m_isOnGround2 = false;
        if (0 < this->m_stateNoAutoJump) {
          this->m_isOnGround = false;
          this->m_jumpBuffered = false;
          this->m_stateRingJump = false;
        }
      }
      if ((bVar25 & 1) != 0) {
        this->m_maybeTouchedBreakableBlock = true;
        goto LAB_100381724;
      }
    }
    else {
      bVar1 = this->m_isUpsideDown;
      dVar53 = dVar38;
      dVar49 = dVar41;
      if (bVar1 == false) {
        dVar53 = dVar40;
        dVar49 = dVar55;
      }
      bVar5 = false;
      bVar9 = false;
      if (dVar53 < dVar39) {
        bVar5 = false;
        bVar9 = true;
        if (!NAN(dVar49) && !NAN(dVar39)) {
          bVar5 = dVar49 < dVar39;
          bVar9 = false;
        }
      }
      if (bVar5 != bVar9) goto LAB_1003802cc;
      if (((bVar1 == false) || ((this->m_isBird & bVar12) == 0)) ||
         ((this->m_isPlatformer & 1U) != 0)) {
        dVar49 = this->m_yVelocity;
        if (((0.0 < dVar49) && ((this->m_wasOnSlope & 1U) == 0 && !bVar6)) ||
           ((bool)(bVar10 & bVar4))) {
          if (bVar11 || (bVar31 != 0 || (bVar1 & 1U) != 0)) {
            if (!bVar7 && (bVar31 & bVar1) == 1) {
              puVar20 = (undefined4 *)getPosition/*virtual+0xc0*/(this);
              CCPoint__CCPoint(*puVar20,fStack_12c + fStack_ac * 0.5,&fStack_f0);
              setPosition/*virtual+0xb8*/(this,&fStack_f0);
              if (this->m_isUpsideDown == true) {
                if ((((this->m_isShip & 1U) == 0) && ((this->m_isBird & 1U) == 0)) &&
                   ((this->m_isDart & 1U) == 0)) {
                  bVar23 = this->m_isSwing;
                }
                else {
                  bVar23 = 1;
                }
              }
              else {
                bVar23 = 0;
              }
              bVar10 = this->m_isOnGround;
              bVar1 = this->m_isOnGround2;
              dVar53 = this->m_lastLandTime;
              PlayerObject__hitGround(this,(GameObject *)0x0,(bool)(bVar23 & 1));
              this->m_isOnGround = bVar10;
              this->m_isOnGround2 = bVar1;
              this->m_lastLandTime = dVar53;
              if (bVar12 == false && (bVar29 & 1) == 0) {
                PlayerObject__updateCollideTop(fStack_12c,this,object_00);
              }
              dVar53 = (double)(float)dVar49;
              dVar49 = (double)(int)dVar49;
              if (dVar49 != dVar53) {
                dVar53 = (double)(long)((dVar53 - dVar49) * 1000.0) / 1000.0 + dVar49;
              }
              dVar49 = this->m_groundYVelocity + 1.0;
              if (dVar49 <= dVar53) {
                dVar49 = dVar53;
              }
              dVar53 = (double)(int)dVar49;
              if (dVar49 != dVar53) {
                dVar49 = (double)(long)((dVar49 - dVar53) * 1000.0) / 1000.0 + dVar53;
              }
              this->m_yVelocity = dVar49;
              if (0 < this->m_stateFlipGravity) {
                PlayerObject__flipGravity(this,(bool)((this->m_isUpsideDown ^ 0xffU) & 1),true);
                dVar49 = 2.0;
                if (this->m_isUpsideDown == false) {
                  dVar49 = -2.0;
                }
                dVar53 = (double)(int)dVar49;
                if (dVar49 != dVar53) {
                  dVar49 = (double)(long)((dVar49 - dVar53) * 1000.0) / 1000.0 + dVar53;
                }
                this->m_yVelocity = dVar49;
                this->m_maybeIsBoosted = true;
                this->m_isOnGround2 = false;
                if (0 < this->m_stateNoAutoJump) {
                  this->m_isOnGround = false;
                  this->m_jumpBuffered = false;
                  this->m_stateRingJump = false;
                }
              }
              if ((bVar25 & 1) != 0) {
                this->m_maybeTouchedBreakableBlock = true;
                if (*(long *)this->m_gameLayer == 0) {
                  GameObject__destroyObject(object_00);
                }
                else {
                  GJBaseGameLayer__destroyObject(*(long *)this->m_gameLayer,object_00);
                }
              }
              goto LAB_100381024;
            }
            bVar23 = 0;
            goto LAB_1003802d0;
          }
          puVar20 = (undefined4 *)getPosition/*virtual+0xc0*/(this);
          CCPoint__CCPoint(*puVar20,fStack_12c + fStack_ac * 0.5,&fStack_f0);
          setPosition/*virtual+0xb8*/(this,&fStack_f0);
          if (this->m_isUpsideDown == true) {
            if ((((this->m_isShip & 1U) == 0) && ((this->m_isBird & 1U) == 0)) &&
               ((this->m_isDart & 1U) == 0)) {
              PlayerObject__hitGround(this,object_00,(bool)(this->m_isSwing & 1));
              goto joined_r0x000100380834;
            }
            PlayerObject__hitGround(this,object_00,true);
            if (object_00 == (GameObject *)0x0) goto LAB_100381428;
LAB_100380838:
            iVar13 = object_00->m_uniqueID;
          }
          else {
            PlayerObject__hitGround(this,object_00,false);
joined_r0x000100380834:
            if (object_00 != (GameObject *)0x0) goto LAB_100380838;
LAB_100381428:
            iVar13 = 0;
          }
          dVar42 = this->m_collidedBottomMaxY;
          dVar53 = dVar39;
          if (dVar42 != 0.0) {
            if ((this->m_isUpsideDown & 1U) == 0) {
              if (dVar39 <= dVar42) {
                dVar53 = dVar42;
              }
            }
            else if (dVar42 <= dVar39) {
              dVar53 = dVar42;
            }
          }
          this->m_collidedBottomMaxY = dVar53;
          if ((iVar13 != 0) && (this->m_lastCollisionBottom != iVar13)) {
            this->m_lastCollisionBottom = iVar13;
            if (*(long *)this->m_collisionLogBottom != 0) {
              CCDictionary__setObject(*(long *)this->m_collisionLogBottom,
                                  *(undefined8 *)this->m_maybeLastGroundObject,(long)iVar13);
            }
          }
          if (object != (GameObject *)0x0) {
            *(GameObject **)this->m_lastGroundObject = object;
            if (object->m_isDontBoostY == true) {
              this->m_stateBoostX = 2;
            }
            if (object->m_isDontBoostX == true) {
              this->m_stateBoostY = 2;
            }
          }
          this->m_groundYVelocity = dStack_140;
          dVar53 = (double)(int)dVar49;
          if (dVar49 != dVar53) {
            dVar49 = (double)(long)((dVar49 - dVar53) * 1000.0) / 1000.0 + dVar53;
          }
          dVar53 = dStack_140;
          if (dStack_140 <= dVar49) {
            dVar53 = dVar49;
          }
          dVar49 = (double)(int)dVar53;
          if (dVar53 != dVar49) {
            dVar53 = (double)(long)((dVar53 - dVar49) * 1000.0) / 1000.0 + dVar49;
          }
          bVar23 = 0;
          this->m_yVelocity = dVar53;
          goto LAB_1003802d0;
        }
        if (bVar31 != 0) {
          dVar55 = -dVar49;
          if (bVar1 == false) {
            dVar55 = dVar49;
          }
          if ((0.0 < dVar55) && (*(long *)this->m_gameLayer != 0)) {
            GJBaseGameLayer__gameEventTriggered(*(long *)this->m_gameLayer,6,0,(this->GameObject).m_uniqueID);
          }
        }
        puVar20 = (undefined4 *)getPosition/*virtual+0xc0*/(this);
        CCPoint__CCPoint(*puVar20,fStack_12c + fStack_ac * 0.5,&fStack_f0);
        setPosition/*virtual+0xb8*/(this,&fStack_f0);
        if ((bVar27 & 1) != 0) {
          PlayerObject__checkSnapJumpToObject(this,object_00);
        }
        if (((bVar23 | bVar22 ^ 0xff) & 1) == 0) {
          this->m_yVelocity = 0.0;
        }
        else {
          if (this->m_isUpsideDown == true) {
            if ((((this->m_isShip & 1U) == 0) && ((this->m_isBird & 1U) == 0)) &&
               ((this->m_isDart & 1U) == 0)) {
              bVar21 = this->m_isSwing;
            }
            else {
              bVar21 = 1;
            }
          }
          else {
            bVar21 = 0;
          }
          if (bVar31 == 0) {
            PlayerObject__hitGround(this,object_00,(bool)(bVar21 & 1));
          }
          else {
            bVar8 = this->m_isOnGround;
            bVar6 = this->m_isOnGround2;
            dVar55 = this->m_lastLandTime;
            PlayerObject__hitGround(this,(GameObject *)0x0,(bool)(bVar21 & 1));
            this->m_isOnGround = bVar8;
            this->m_isOnGround2 = bVar6;
            this->m_lastLandTime = dVar55;
          }
        }
        if ((this->m_isUpsideDown & 1U) == 0) {
          fVar48 = fVar35;
          if ((bVar31 ^ 1) == 0 && (bVar12 == false && (bVar29 & 1) == 0)) goto LAB_10038159c;
          if (bVar31 != 0) goto LAB_1003815ac;
LAB_100381588:
          PlayerObject__updateCollideBottom(fStack_12c,this,object_00);
LAB_1003815c8:
          if (object != (GameObject *)0x0) {
            *(GameObject **)this->m_lastGroundObject = object;
            if (object->m_isDontBoostY == true) {
              this->m_stateBoostX = 2;
            }
            if (object->m_isDontBoostX == true) {
              this->m_stateBoostY = 2;
            }
          }
          bVar21 = 0;
          this->m_groundYVelocity = dStack_140;
        }
        else {
          fVar48 = fStack_12c;
          if ((bVar31 ^ 1) == 0 && (bVar12 == false && (bVar29 & 1) == 0)) {
LAB_10038159c:
            PlayerObject__updateCollideTop(fVar48,this,object_00);
            if (bVar31 == 0) goto LAB_1003815c8;
          }
          else {
            fStack_12c = fVar35;
            if (bVar31 == 0) goto LAB_100381588;
          }
LAB_1003815ac:
          if (this->m_isPlatformer == true) {
            PlayerObject__exitPlatformerAnimateJump(this);
          }
          bVar21 = 1;
        }
        goto joined_r0x0001003810ec;
      }
      virtual_0x528(&fStack_f0,0x3e99999a,0x3e99999a,this);
      iVar13 = CCRect__intersectsRect(afStack_c8,&fStack_f0);
      if (iVar13 == 0) {
LAB_100381024:
        bVar23 = 0;
        goto LAB_1003802d0;
      }
LAB_100381724:
      if (*(long *)this->m_gameLayer != 0) {
        GJBaseGameLayer__destroyObject(*(long *)this->m_gameLayer,object_00);
        return true;
      }
      GameObject__destroyObject(object_00);
    }
LAB_100381744:
    bVar8 = true;
  }
  return bVar8;
}


// ==== PlayerObject::updateJump @ 0x3766e8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PlayerObject__updateJump(PlayerObject *this,float dt)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  byte bVar6;
  bool bVar7;
  int iVar8;
  long lVar9;
  undefined8 uVar10;
  int iVar11;
  uint uVar12;
  undefined8 *puVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  byte bVar16;
  byte bVar17;
  byte bVar18;
  float fVar19;
  double dVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  double dVar24;
  double dVar25;
  float fVar26;
  float fVar27;
  undefined8 auStack_d8 [2];
  char cStack_c1;
  undefined8 auStack_c0 [2];
  char cStack_a9;
  char acStack_a8 [23];
  char cStack_91;
  char acStack_90 [23];
  char cStack_79;
  undefined8 auStack_78 [2];
  char cStack_61;
  
  bVar17 = this->m_holdingLeft;
  bVar18 = (bVar17 ^ 1) & this->m_holdingRight;
  if ((((bVar17 ^ 1) & 1) == 0) && ((this->m_holdingRight & 1U) != 0)) {
    bVar17 = this->m_leftPressedFirst;
    bVar18 = bVar17 ^ 1;
  }
  if (((this->m_isPlatformer == true) && (this->m_isOnSlope == true)) &&
     ((fVar19 = ABS(this->m_slopeAngleRadians * 57.29578), 80.0 <= fVar19 ||
      ((40.0 <= fVar19 && (*(char *)(*(long *)this->m_currentSlope + 0x511) == '\x01')))))) {
    this->m_isOnGround = false;
  }
  bVar7 = this->m_isOnGround;
  iVar11 = 0xd5;
  if (bVar7 == false) {
    iVar11 = 0;
  }
  *(int *)(this->m_jumpRelatedAC2 + 8) = iVar11;
  iVar8 = _rand();
  iVar8 = (int)(((float)iVar8 / 2.1474836e+09) * 1000.0);
  *(int *)(this->m_jumpRelatedAC2 + 4) = iVar8;
  *(int *)this->m_jumpRelatedAC2 = iVar11 + iVar8;
  dVar24 = this->m_gravity;
  bVar2 = this->m_jumpBuffered;
  bVar3 = this->m_isRobot;
  bVar6 = bVar2;
  if (bVar3 == true) {
    bVar6 = this->m_stateRingJump & bVar2;
  }
  fVar19 = (float)dVar24;
  bVar4 = this->m_isBall;
  bVar16 = this->m_isShip;
  if (((bVar4 & 1U) == 0) && ((bVar16 & 1) == 0)) {
    if (((this->m_isBird & 1U) != 0) ||
       (((this->m_isDart & 1U) != 0 || ((this->m_isSwing & 1U) != 0)))) {
      bVar16 = 0;
      goto LAB_10037681c;
    }
    bVar16 = 0;
    fVar21 = fVar19;
    if (this->m_isSpider == true) goto LAB_10037681c;
  }
  else {
LAB_10037681c:
    fVar21 = 0.958199;
  }
  fVar27 = fVar21 * this->m_gravityMod;
  if (this->m_gravityMod == 1.0) {
    fVar27 = fVar21;
  }
  fVar26 = this->m_vehicleSize;
  fVar23 = 0.8;
  if (fVar26 == 1.0) {
    fVar23 = 1.0;
  }
  if (((((bVar16 & 1) == 0) && ((this->m_isBird & 1U) == 0)) && ((this->m_isDart & 1U) == 0)) &&
     ((this->m_isSwing & 1U) == 0)) {
    if ((bVar4 & 1U) == 0) {
      fVar19 = 0.9;
      if (bVar3 == false) {
        fVar19 = 1.0;
      }
      fVar21 = 0.6;
      if (this->m_isSpider == false) {
        fVar21 = fVar19;
      }
      bVar16 = this->m_platformerMovingLeft;
      if (((bVar17 | bVar16 ^ 0xff) & 1) != 0) goto LAB_100376fb4;
LAB_100376fcc:
      if ((this->m_isSlidingRight != (bool)bVar16) && ((this->m_slopeSlidingMaybeRotated & 1U) == 0)
         ) {
        this->m_maybeSlidingTime = 0;
      }
      bVar1 = this->m_maybeSlidingTime < 2;
      bVar18 = 1;
    }
    else {
      fVar21 = 0.6;
      bVar16 = this->m_platformerMovingLeft;
      if (((bVar17 | bVar16 ^ 0xff) & 1) == 0) goto LAB_100376fcc;
LAB_100376fb4:
      if (((bVar18 | this->m_platformerMovingRight ^ 0xffU) & 1) == 0) goto LAB_100376fcc;
      bVar18 = 0;
      bVar1 = true;
    }
    if ((bVar6 & 1) == 0) goto LAB_1003771fc;
    if (this->m_isOnGround == false) {
      if (this->m_maybeIsBoosted != true) goto LAB_100377398;
    }
    else {
      if ((this->m_isSpider & 1U) == 0) {
        if (((this->m_isDashing & 1U) == 0) &&
           (bVar5 = this->m_isPlatformer, bVar1 || ((bVar5 ^ 0xffU) & 1) != 0)) {
          this->m_maybeIsBoosted = true;
          this->m_isOnGround2 = false;
          this->m_isOnGround = false;
          this->m_stateRingJump = false;
          this->m_touchedPad = false;
          this->m_accelerationOrSpeed = 0.0;
          if (((bVar16 & 1) == 0) &&
             (((this->m_platformerMovingRight & 1U) == 0 && (0 < this->m_maybeSlidingTime)))) {
            this->m_maybeSlidingTime = 0;
            this->m_maybeSlidingStartTime = this->m_totalTime;
          }
          fVar19 = (float)this->m_yStart * 0.5;
          if (bVar3 == false) {
            fVar19 = (float)this->m_yStart;
          }
          if ((bVar7 & 1U) == 0) {
            this->m_isAccelerating = true;
            fVar19 = 9999.0;
          }
          if ((bVar18 & bVar5) == 1) {
            if (this->m_isMoving == true) {
              dVar24 = this->m_speedMultiplier * (double)this->m_playerSpeed;
              if (ABS(this->m_platformerXVelocity) <= dVar24) goto LAB_100377b70;
              fVar19 = (float)(ABS(this->m_platformerXVelocity) / dVar24 + (double)fVar19);
              uVar12 = this->m_maybeSlidingTime;
            }
            else {
LAB_100377b70:
              uVar12 = this->m_maybeSlidingTime;
              if (0 < (int)uVar12) {
                fVar19 = fVar19 * ((float)uVar12 * -0.3 + 1.0);
              }
            }
            this->m_maybeSlidingTime = uVar12 + 1;
          }
          fVar21 = -1.0;
          if (this->m_isUpsideDown == false) {
            fVar21 = 1.0;
          }
          fVar23 = fVar23 * fVar19 * fVar21;
          dVar24 = (double)fVar23;
          dVar20 = (double)(int)fVar23;
          if (dVar20 != dVar24) {
            dVar24 = (double)(long)((dVar24 - dVar20) * 1000.0) / 1000.0 + dVar20;
          }
          this->m_yVelocity = dVar24;
          if (((((this->m_wasOnSlope & 1U) != 0) || (this->m_isOnSlope == true)) &&
              (fVar19 = this->m_slopeVelocity, 0.0 < fVar21 * fVar19)) &&
             ((bVar5 == false || (4.0 < ABS(this->m_platformerXVelocity))))) {
            dVar25 = this->m_totalTime - this->m_slopeStartTime;
            dVar20 = dVar25 * 10.0;
            if (dVar20 <= 0.4000000059604645) {
              dVar20 = 0.4000000059604645;
            }
            if (0.10000000149011612 <= dVar25) {
              dVar20 = 1.0;
            }
            if (bVar4 == false) {
              fVar19 = (float)(dVar20 * (double)fVar19);
            }
            dVar20 = dVar24 + (double)(fVar19 * 0.25);
            dVar25 = (double)(int)dVar20;
            if (dVar20 != dVar25) {
              dVar20 = (double)(long)((dVar20 - dVar25) * 1000.0) / 1000.0 + dVar25;
            }
            this->m_yVelocity = dVar20;
            dVar24 = (double)(float)(dVar24 * 1.399999976158142);
            if ((this->m_isUpsideDown & 1U) == 0) {
              if (dVar20 <= dVar24) {
                dVar24 = dVar20;
              }
            }
            else if (dVar24 <= dVar20) {
              dVar24 = dVar20;
            }
            dVar20 = (double)(int)dVar24;
            if (dVar24 != dVar20) {
              dVar24 = (double)(long)((dVar24 - dVar20) * 1000.0) / 1000.0 + dVar20;
            }
            this->m_yVelocity = dVar24;
          }
          this->m_shouldTryPlacingCheckpoint = true;
          dVar24 = (double)func_0x00010037ac1c();
          this->m_lastJumpTime = dVar24;
          PlayerObject__incrementJumps(this);
          if (this->m_isBall == true) {
            PlayerObject__flipGravity(this,(bool)((this->m_isUpsideDown ^ 0xffU) & 1),true);
            this->m_yVelocity = this->m_yVelocity * 0.6000000238418579;
            this->m_isOnGround3 = false;
            this->m_jumpBuffered = false;
          }
          else if (((this->m_isRobot & 1U) == 0) && ((this->m_isSpider & 1U) == 0)) {
            PlayerObject__runRotateAction(this,0);
          }
          if (this->m_isRobot == true) {
            uVar10 = *(undefined8 *)this->m_robotSprite;
            func_0x00010002d748(auStack_78,"jump_loop");
            CCAnimatedSprite__tweenToAnimation(0x3dcccccd,uVar10,auStack_78);
            if (cStack_61 < '\0') {
              __ZdlPv(auStack_78[0]);
            }
          }
          if (*(long *)this->m_gameLayer != 0) {
            if ((((((this->m_isShip & 1U) == 0) && ((this->m_isBird & 1U) == 0)) &&
                 ((this->m_isDart & 1U) == 0)) &&
                (((this->m_isSwing & 1U) == 0 && ((this->m_isBall & 1U) == 0)))) &&
               (((this->m_isRobot & 1U) == 0 && (this->m_isSpider != true)))) {
              uVar10 = 0xc;
            }
            else if ((this->m_isRobot & 1U) == 0) {
              if (this->m_isBall != true) goto LAB_100377e64;
              uVar10 = 0x13;
            }
            else {
              uVar10 = 0xd;
            }
            GJBaseGameLayer__gameEventTriggered(*(long *)this->m_gameLayer,uVar10,0,(this->GameObject).m_uniqueID);
          }
LAB_100377e64:
          if (this->m_isPlatformer == true) {
            PlayerObject__animatePlatformerJump(0x3f800000,this);
          }
          goto LAB_100377808;
        }
      }
      else if ((this->m_isDashing & 1U) == 0) {
        PlayerObject__spiderTestJumpInternal(this,false);
        if (*(long *)this->m_gameLayer != 0) {
          GJBaseGameLayer__gameEventTriggered(*(long *)this->m_gameLayer,0x12,0,(this->GameObject).m_uniqueID);
        }
        if ((((this->m_isShip & 1U) == 0) && ((this->m_isBird & 1U) == 0)) &&
           (((this->m_isDart & 1U) == 0 &&
            ((((this->m_isSwing & 1U) == 0 && ((this->m_isBall & 1U) == 0)) &&
             ((this->m_isSpider & 1U) == 0)))))) {
          bVar7 = this->m_isUpsideDown == false;
          uVar14 = 0x42b40000;
          if (bVar7) {
            uVar14 = 0x43870000;
          }
          uVar15 = 0x43340000;
          if (bVar7) {
            uVar15 = 0;
          }
          if (this->m_isSideways == false) {
            uVar14 = uVar15;
          }
          virtual_0x158(uVar14,this);
        }
        goto LAB_100377808;
      }
LAB_1003771fc:
      if ((this->m_maybeIsBoosted & 1U) == 0) {
        if (this->m_isOnGround != false) {
          lVar9 = getPosition/*virtual+0xc0*/(this);
          this->m_fallStartY = *(float *)(lVar9 + 4);
        }
LAB_100377398:
        bVar18 = this->m_isSideways;
        if ((((bVar18 & 1) == 0) && ((this->m_isPlatformer & 1U) == 0)) &&
           (((this->m_isSwing & 1U) == 0 && (this->m_fixGravityBug != true)))) {
          dVar20 = this->m_gravity;
          if ((this->m_isUpsideDown & 1U) == 0) {
            bVar7 = false;
            fVar19 = -(float)dVar20;
            if (this->m_unkA99 == false) {
              fVar19 = (float)dVar20;
            }
            dVar24 = this->m_yVelocity;
            bVar2 = false;
            if (dVar24 < (double)(fVar19 + fVar19)) goto LAB_1003773fc;
          }
          else {
            dVar24 = this->m_yVelocity;
            bVar7 = true;
            bVar2 = true;
            if (dVar20 + dVar20 < dVar24) {
LAB_1003773fc:
              bVar7 = bVar2;
              if ((this->m_isPlatformer != true) ||
                 (!(bool)(this->m_totalTime - this->m_lastLandTime < 0.05000000447034836 & bVar1)))
              {
                this->m_isOnGround = false;
              }
            }
          }
        }
        else {
          fVar19 = (float)(this->m_gravity + this->m_gravity);
          dVar24 = this->m_yVelocity;
          if (this->m_isUpsideDown == true) {
            bVar2 = true;
            if ((double)-fVar19 < dVar24) goto LAB_1003773fc;
            bVar7 = true;
          }
          else {
            bVar7 = false;
            bVar2 = false;
            if (dVar24 < (double)fVar19) goto LAB_1003773fc;
          }
        }
        fVar19 = -fVar27;
        if (!bVar7) {
          fVar19 = fVar27;
        }
        dVar24 = dVar24 + (double)(fVar21 * -(fVar19 * dt));
        dVar20 = (double)(int)dVar24;
        if (dVar24 != dVar20) {
          dVar24 = (double)(long)((dVar24 - dVar20) * 1000.0) / 1000.0 + dVar20;
        }
        this->m_yVelocity = dVar24;
        if (bVar7) {
          dVar20 = 15.0;
          if (dVar24 <= 15.0) {
            dVar20 = dVar24;
          }
          dVar24 = (double)(int)dVar20;
          if (dVar20 != dVar24) {
            dVar20 = (double)(long)((dVar20 - dVar24) * 1000.0) / 1000.0 + dVar24;
          }
          this->m_yVelocity = dVar20;
          if (0.25 < dVar20) {
LAB_10037752c:
            if (((((this->m_isBall & 1U) == 0) && ((this->m_isSpider & 1U) == 0)) &&
                ((this->m_isRobot & 1U) == 0)) &&
               ((((this->m_isRotating & 1U) == 0 && ((this->m_isOnSlope & 1U) == 0)) &&
                (((this->m_isCollidingWithSlope & 1U) == 0 &&
                 ((this->m_isPlatformer != true || ((this->m_isOnGround2 & 1U) == 0)))))))) {
              PlayerObject__runRotateAction(this,0);
              bVar18 = this->m_isSideways;
            }
          }
        }
        else {
          dVar20 = -15.0;
          if (-15.0 <= dVar24) {
            dVar20 = dVar24;
          }
          dVar24 = (double)(int)dVar20;
          if (dVar20 != dVar24) {
            dVar20 = (double)(long)((dVar20 - dVar24) * 1000.0) / 1000.0 + dVar24;
          }
          this->m_yVelocity = dVar20;
          if (dVar20 < -0.25) goto LAB_10037752c;
        }
        if (((((bVar18 & 1) == 0) && ((this->m_isPlatformer & 1U) == 0)) &&
            ((this->m_isSwing & 1U) == 0)) && (this->m_fixGravityBug != true)) {
          dVar20 = this->m_gravity;
          if ((this->m_isUpsideDown & 1U) != 0) {
            dVar24 = this->m_yVelocity;
            if (dVar24 <= dVar20 + dVar20) goto LAB_100377808;
            goto LAB_1003775cc;
          }
          fVar19 = -(float)dVar20;
          if (this->m_unkA99 == false) {
            fVar19 = (float)dVar20;
          }
          dVar24 = this->m_yVelocity;
          fVar19 = fVar19 + fVar19;
LAB_100377a7c:
          if ((double)fVar19 <= dVar24) goto LAB_100377808;
          bVar7 = false;
        }
        else {
          fVar19 = (float)(this->m_gravity + this->m_gravity);
          dVar24 = this->m_yVelocity;
          if (this->m_isUpsideDown != true) goto LAB_100377a7c;
          if (dVar24 <= (double)-fVar19) goto LAB_100377808;
LAB_1003775cc:
          bVar7 = true;
        }
        if (bVar7) {
          if (dVar24 <= 4.0) goto LAB_100377808;
        }
        else if (-4.0 <= dVar24) goto LAB_100377808;
        if (((this->m_isRobot == true) && (this->m_isOnGround2 == true)) &&
           ((this->m_maybeSpriteRelated & 1U) == 0)) {
          uVar10 = *(undefined8 *)this->m_robotSprite;
          func_0x00010002d748(auStack_c0,"fall_loop");
          CCAnimatedSprite__tweenToAnimation(0x3dcccccd,uVar10,auStack_c0);
          if (cStack_a9 < '\0') {
            puVar13 = auStack_c0;
LAB_100377b60:
            __ZdlPv(*puVar13);
          }
        }
        else if (((this->m_isSpider == true) && (this->m_isOnGround2 == true)) &&
                ((this->m_maybeSpriteRelated & 1U) == 0)) {
          uVar10 = *(undefined8 *)this->m_spiderSprite;
          func_0x00010002d748(auStack_d8,"fall_loop");
          CCAnimatedSprite__tweenToAnimation(0x3dcccccd,uVar10,auStack_d8);
          if (cStack_c1 < '\0') {
            puVar13 = auStack_d8;
            goto LAB_100377b60;
          }
        }
        this->m_isOnGround2 = false;
        goto LAB_100377808;
      }
    }
    if ((((bVar3 != false) && (bVar2 != false)) && ((this->m_touchedPad & 1U) == 0)) &&
       (this->m_accelerationOrSpeed < 1.5)) {
      this->m_accelerationOrSpeed = this->m_accelerationOrSpeed + (double)(dt * 0.1);
      fVar19 = -(fVar27 * dt);
      if (this->m_isUpsideDown == false) {
        fVar19 = fVar27 * dt;
      }
      dVar24 = this->m_yVelocity + (double)(fVar21 * fVar19);
      dVar20 = (double)(int)dVar24;
      if (dVar24 != dVar20) {
        dVar24 = (double)(long)((dVar24 - dVar20) * 1000.0) / 1000.0 + dVar20;
      }
      this->m_yVelocity = dVar24;
    }
    fVar19 = -fVar27;
    if (this->m_isUpsideDown == false) {
      fVar19 = fVar27;
    }
    dVar24 = this->m_yVelocity + (double)(fVar21 * -(fVar19 * dt));
    dVar20 = (double)(int)dVar24;
    if (dVar24 != dVar20) {
      dVar24 = (double)(long)((dVar24 - dVar20) * 1000.0) / 1000.0 + dVar20;
    }
    this->m_yVelocity = dVar24;
    if (((bVar3 != false) && (this->m_touchedPad == true)) &&
       (((this->m_wasRobotJump & 1U) == 0 && (*(long *)this->m_gameLayer != 0)))) {
      GJBaseGameLayer__gameEventTriggered(*(long *)this->m_gameLayer,0xe,0,(this->GameObject).m_uniqueID);
    }
    if ((((this->m_isSideways & 1U) == 0) && ((this->m_isPlatformer & 1U) == 0)) &&
       (((this->m_isSwing & 1U) == 0 && (this->m_fixGravityBug != true)))) {
      dVar20 = this->m_gravity;
      if ((this->m_isUpsideDown & 1U) == 0) {
        fVar19 = -(float)dVar20;
        if (this->m_unkA99 == false) {
          fVar19 = (float)dVar20;
        }
        dVar24 = this->m_yVelocity;
        fVar19 = fVar19 + fVar19;
LAB_100377904:
        if (dVar24 < (double)fVar19) goto LAB_100377938;
        bVar7 = false;
      }
      else {
        dVar24 = this->m_yVelocity;
        if (dVar20 + dVar20 < dVar24) goto LAB_100377938;
LAB_100377374:
        bVar7 = true;
      }
      if (this->m_isPlatformer != true) goto LAB_100377808;
      bVar2 = dVar24 < 0.0;
      if (!bVar7) {
        bVar2 = dVar24 != 0.0 && dVar24 >= 0.0;
      }
      if (bVar2) goto LAB_100377808;
    }
    else {
      fVar19 = (float)(this->m_gravity + this->m_gravity);
      dVar24 = this->m_yVelocity;
      if (this->m_isUpsideDown != true) goto LAB_100377904;
      if (dVar24 <= (double)-fVar19) goto LAB_100377374;
    }
LAB_100377938:
    this->m_maybeIsBoosted = false;
    this->m_maybeIsFalling = true;
    this->m_isOnGround2 = false;
    lVar9 = getPosition/*virtual+0xc0*/(this);
    this->m_fallStartY = *(float *)(lVar9 + 4);
    if (this->m_isRobot == true) {
      cStack_79 = '\t';
      builtin_strncpy(acStack_90,"fall_loop",10);
      CCAnimatedSprite__tweenToAnimation(0x3dcccccd,*(undefined8 *)this->m_robotSprite,acStack_90);
      if (cStack_79 < '\0') {
        __ZdlPv(acStack_90._0_8_);
      }
      if (((this->m_touchedPad & 1U) == 0) && (*(long *)this->m_gameLayer != 0)) {
        GJBaseGameLayer__gameEventTriggered(*(long *)this->m_gameLayer,0xe,0,(this->GameObject).m_uniqueID);
      }
    }
    else if (this->m_isSpider == true) {
      cStack_91 = '\t';
      builtin_strncpy(acStack_a8,"fall_loop",10);
      CCAnimatedSprite__tweenToAnimation(0x3dcccccd,*(undefined8 *)this->m_spiderSprite,acStack_a8);
      if (cStack_91 < '\0') {
        __ZdlPv(acStack_a8._0_8_);
      }
    }
    goto LAB_100377808;
  }
  fVar23 = 0.85;
  if (fVar26 == 1.0) {
    fVar23 = 1.0;
  }
  bVar7 = this->m_isUpsideDown;
  dVar20 = this->m_yVelocity;
  if ((bVar7 & 1U) == 0) {
    if (((0.0 <= dVar20) && (dVar20 < (double)(8.0 / fVar23))) ||
       ((dVar20 <= 0.0 && ((double)(-6.4 / fVar23) < dVar20)))) goto LAB_100376900;
  }
  else if (((dVar20 <= 0.0) && ((double)-(8.0 / fVar23) < dVar20)) ||
          ((0.0 <= dVar20 && (dVar20 < (double)-(-6.4 / fVar23))))) {
LAB_100376900:
    this->m_isAccelerating = false;
  }
  if ((bVar16 & 1) == 0) {
    if (this->m_isBird == true) {
      if ((this->m_stateRingJump == true) && (bVar2 != false)) {
        this->m_stateRingJump = false;
        fVar19 = 8.0;
        if (fVar26 == 1.0) {
          fVar19 = 7.0;
        }
        fVar21 = -fVar19;
        if (bVar7 == false) {
          fVar21 = fVar19;
        }
        dVar24 = (double)(fVar23 * fVar21);
        if ((bVar7 & 1U) == 0) {
          if (dVar20 < dVar24) goto LAB_100376db8;
        }
        else if (dVar24 < dVar20) {
LAB_100376db8:
          dVar20 = (double)(int)(fVar23 * fVar21);
          if (dVar24 != dVar20) {
            dVar24 = (double)(long)((dVar24 - dVar20) * 1000.0) / 1000.0 + dVar20;
          }
          this->m_yVelocity = dVar24;
          if ((((this->m_wasOnSlope & 1U) != 0) || (this->m_isOnSlope == true)) &&
             (0.0 < this->m_slopeVelocity)) {
            dVar20 = dVar24 + (double)(this->m_slopeVelocity * 0.5);
            dVar25 = (double)(int)dVar20;
            if (dVar20 != dVar25) {
              dVar20 = (double)(long)((dVar20 - dVar25) * 1000.0) / 1000.0 + dVar25;
            }
            this->m_yVelocity = dVar20;
            dVar25 = (double)(float)(dVar24 * 1.399999976158142);
            if (dVar20 <= (double)(float)(dVar24 * 1.399999976158142)) {
              dVar25 = dVar20;
            }
            dVar24 = (double)(int)dVar25;
            if (dVar25 != dVar24) {
              dVar25 = (double)(long)((dVar25 - dVar24) * 1000.0) / 1000.0 + dVar24;
            }
            this->m_yVelocity = dVar25;
          }
        }
        PlayerObject__playBurstEffect(this);
        if (*(long *)this->m_gameLayer != 0) {
          GJBaseGameLayer__gameEventTriggered(*(long *)this->m_gameLayer,0xf,0,(this->GameObject).m_uniqueID);
        }
      }
      if ((((this->m_isSideways & 1U) == 0) && ((this->m_isPlatformer & 1U) == 0)) &&
         (((this->m_isSwing & 1U) == 0 && (this->m_fixGravityBug != true)))) {
        dVar20 = this->m_gravity;
        if ((this->m_isUpsideDown & 1U) != 0) {
          dVar24 = this->m_yVelocity;
          dVar20 = dVar20 + dVar20;
          goto LAB_100376f10;
        }
        fVar19 = -(float)dVar20;
        if (this->m_unkA99 == false) {
          fVar19 = (float)dVar20;
        }
        dVar24 = this->m_yVelocity;
        fVar19 = fVar19 + fVar19;
LAB_100377614:
        fVar21 = 0.8;
        if ((double)fVar19 <= dVar24) {
          fVar21 = 1.2;
        }
      }
      else {
        fVar19 = (float)(this->m_gravity + this->m_gravity);
        dVar24 = this->m_yVelocity;
        if (this->m_isUpsideDown != true) goto LAB_100377614;
        dVar20 = (double)-fVar19;
LAB_100376f10:
        fVar21 = 0.8;
        if (dVar24 <= dVar20) {
          fVar21 = 1.2;
        }
        fVar27 = -fVar27;
      }
      dVar24 = dVar24 + (double)((fVar21 * fVar27 * dt * -0.5) / fVar23);
      dVar20 = (double)(int)dVar24;
      if (dVar24 != dVar20) {
        dVar24 = (double)(long)((dVar24 - dVar20) * 1000.0) / 1000.0 + dVar20;
      }
      this->m_yVelocity = dVar24;
      if (this->m_jumpBuffered == true) {
        this->m_isOnGround2 = false;
      }
      goto LAB_100377698;
    }
    if (this->m_isSwing != true) {
      iVar11 = 1;
      if (bVar7 != false) {
        iVar11 = -1;
      }
      fVar19 = (float)(iVar11 << 3);
      if (bVar2 == false) {
        fVar19 = -(float)(iVar11 << 3);
      }
      dVar24 = (double)fVar19;
      dVar20 = (double)(int)fVar19;
      if (dVar20 != dVar24) {
        dVar24 = (double)(long)((dVar24 - dVar20) * 1000.0) / 1000.0 + dVar20;
      }
      this->m_yVelocity = dVar24;
      dVar20 = this->m_speedMultiplier * (double)this->m_playerSpeed;
      dVar24 = dVar20 * (double)iVar11;
      if (bVar2 == false) {
        dVar24 = -(dVar20 * (double)iVar11);
      }
      dVar20 = (double)(int)dVar24;
      if (dVar24 != dVar20) {
        dVar24 = (double)(long)((dVar24 - dVar20) * 1000.0) / 1000.0 + dVar20;
      }
      this->m_yVelocity = dVar24;
      lVar9 = *(long *)this->m_gameLayer;
      if ((lVar9 == 0) || (this->m_wasJumpBuffered == bVar2)) goto LAB_100377698;
      iVar11 = (this->GameObject).m_uniqueID;
      if (bVar2 == false) {
        uVar10 = 0x16;
      }
      else {
        uVar10 = 0x15;
      }
      goto LAB_100376d70;
    }
    if ((this->m_stateRingJump == true) && (bVar2 != false)) {
      this->m_stateRingJump = false;
      fVar19 = (float)dVar20;
      PlayerObject__flipGravity(this,(bool)(bVar7 ^ 1),true);
      dVar20 = (double)(fVar19 * 0.8);
      dVar24 = (double)(int)(fVar19 * 0.8);
      if (dVar24 != dVar20) {
        dVar20 = (double)(long)((dVar20 - dVar24) * 1000.0) / 1000.0 + dVar24;
      }
      this->m_yVelocity = dVar20;
      if (*(long *)this->m_gameLayer != 0) {
        GJBaseGameLayer__gameEventTriggered(*(long *)this->m_gameLayer,0x14,0,(this->GameObject).m_uniqueID);
        dVar20 = this->m_yVelocity;
      }
    }
    fVar19 = 1.0;
    fVar21 = 0.6;
    if (this->m_vehicleSize == 1.0) {
      fVar21 = 0.4;
    }
    fVar23 = -fVar27;
    if (this->m_isUpsideDown == false) {
      fVar23 = fVar27;
    }
    dVar20 = dVar20 + (double)(fVar21 * -(fVar23 * dt));
    dVar24 = (double)(int)dVar20;
    if (dVar20 == dVar24) {
      this->m_yVelocity = dVar20;
      if (this->m_jumpBuffered != true) goto LAB_100376f70;
LAB_100376ab8:
      this->m_isOnGround2 = false;
      fVar23 = 1.0;
    }
    else {
      this->m_yVelocity = (double)(long)((dVar20 - dVar24) * 1000.0) / 1000.0 + dVar24;
      if (this->m_jumpBuffered == true) goto LAB_100376ab8;
LAB_100376f70:
      fVar23 = 1.0;
    }
  }
  else {
    bVar3 = this->m_isAccelerating;
    if ((bVar2 & 1U) == 0) {
      if ((bVar3 & 1U) != 0) goto LAB_10037698c;
      fVar26 = 0.8;
      bVar18 = this->m_isSideways;
joined_r0x000100376ad4:
      if (((((bVar18 & 1) == 0) && ((this->m_isPlatformer & 1U) == 0)) &&
          ((this->m_isSwing & 1U) == 0)) && (this->m_fixGravityBug != true)) {
        if ((bVar7 & 1U) == 0) {
          fVar22 = -fVar19;
          if (this->m_unkA99 == false) {
            fVar22 = fVar19;
          }
          bVar3 = dVar20 < (double)(fVar22 + fVar22);
        }
        else {
          bVar3 = dVar24 + dVar24 < dVar20;
        }
      }
      else {
        bVar3 = (double)-(float)(dVar24 + dVar24) < dVar20;
        if ((bVar7 & 1U) == 0) {
          bVar3 = dVar20 < (double)(float)(dVar24 + dVar24);
        }
      }
      if (!bVar3) {
        fVar26 = 1.2;
      }
      fVar19 = fVar27 * 0.8;
      if (this->m_isPlatformer == false) {
        fVar19 = fVar27;
      }
      if (0.0 <= fVar26) {
        fVar21 = fVar19;
      }
      fVar19 = 0.4;
    }
    else {
      fVar26 = 0.8;
      if ((bVar3 & 1U) == 0) {
        fVar26 = -1.0;
      }
      if ((bVar3 & 1U) != 0) {
LAB_10037698c:
        if ((bVar7 & 1U) == 0) {
          if (0.0 <= dVar20) goto LAB_100376998;
LAB_100376b6c:
          fVar26 = -1.0;
        }
        else {
          if (0.0 < dVar20) goto LAB_100376b6c;
LAB_100376998:
          fVar26 = 0.8;
        }
        if ((bVar2 & 1U) == 0) {
          bVar18 = this->m_isSideways;
          goto joined_r0x000100376ad4;
        }
      }
      fVar22 = fVar27 * 0.8;
      if (this->m_isPlatformer == false) {
        fVar22 = fVar27;
      }
      if (0.0 <= fVar26) {
        fVar21 = fVar22;
      }
      if ((((this->m_isSideways & 1U) == 0) && ((this->m_isPlatformer & 1U) == 0)) &&
         (((this->m_isSwing & 1U) == 0 && (this->m_fixGravityBug != true)))) {
        if ((bVar7 & 1U) == 0) {
          fVar27 = -fVar19;
          if (this->m_unkA99 == false) {
            fVar27 = fVar19;
          }
          bVar3 = dVar20 < (double)(fVar27 + fVar27);
        }
        else {
          bVar3 = dVar24 + dVar24 < dVar20;
        }
      }
      else {
        bVar3 = (double)-(float)(dVar24 + dVar24) < dVar20;
        if ((bVar7 & 1U) == 0) {
          bVar3 = dVar20 < (double)(float)(dVar24 + dVar24);
        }
      }
      fVar19 = 0.5;
      if (!bVar3) {
        fVar19 = 0.4;
      }
    }
    fVar27 = -fVar21;
    if (bVar7 == false) {
      fVar27 = fVar21;
    }
    dVar20 = dVar20 + (double)((fVar19 * fVar26 * -(fVar27 * dt)) / fVar23);
    dVar24 = (double)(int)dVar20;
    if (dVar20 == dVar24) {
      this->m_yVelocity = dVar20;
      if (bVar2 == false) goto LAB_100376c74;
LAB_100376c3c:
      this->m_isOnGround2 = false;
      lVar9 = *(long *)this->m_gameLayer;
    }
    else {
      this->m_yVelocity = (double)(long)((dVar20 - dVar24) * 1000.0) / 1000.0 + dVar24;
      if (bVar2 != false) goto LAB_100376c3c;
LAB_100376c74:
      lVar9 = *(long *)this->m_gameLayer;
    }
    if ((lVar9 != 0) && (this->m_wasJumpBuffered != bVar2)) {
      iVar11 = (this->GameObject).m_uniqueID;
      if (bVar2 == false) {
        uVar10 = 0x11;
      }
      else {
        uVar10 = 0x10;
      }
LAB_100376d70:
      GJBaseGameLayer__gameEventTriggered(lVar9,uVar10,0,iVar11);
    }
LAB_100377698:
    fVar19 = 0.8;
  }
  if (((this->m_isAccelerating & 1U) == 0) && ((this->m_isDart & 1U) == 0)) {
    dVar24 = this->m_yVelocity;
    if ((this->m_isUpsideDown & 1U) == 0) {
      dVar20 = (double)((fVar19 * -8.0) / fVar23);
      if (dVar20 <= dVar24) {
        dVar20 = dVar24;
      }
      dVar24 = (double)(int)dVar20;
      if (dVar20 != dVar24) {
        dVar20 = (double)(long)((dVar20 - dVar24) * 1000.0) / 1000.0 + dVar24;
      }
      this->m_yVelocity = dVar20;
      fVar19 = 8.0;
    }
    else {
      dVar20 = (double)(-8.0 / fVar23);
      if ((double)(-8.0 / fVar23) <= dVar24) {
        dVar20 = dVar24;
      }
      dVar24 = (double)(int)dVar20;
      if (dVar20 != dVar24) {
        dVar20 = (double)(long)((dVar20 - dVar24) * 1000.0) / 1000.0 + dVar24;
      }
      this->m_yVelocity = dVar20;
      fVar19 = fVar19 * 8.0;
    }
    dVar24 = (double)(fVar19 / fVar23);
    if (dVar20 <= (double)(fVar19 / fVar23)) {
      dVar24 = dVar20;
    }
    dVar20 = (double)(int)dVar24;
    if (dVar24 != dVar20) {
      dVar24 = (double)(long)((dVar24 - dVar20) * 1000.0) / 1000.0 + dVar20;
    }
    this->m_yVelocity = dVar24;
  }
  if (((((this->m_isSideways & 1U) == 0) && ((this->m_isPlatformer & 1U) == 0)) &&
      ((this->m_isSwing & 1U) == 0)) && (this->m_fixGravityBug != true)) {
    dVar24 = this->m_gravity;
    if ((this->m_isUpsideDown & 1U) == 0) {
      fVar19 = -(float)dVar24;
      if (this->m_unkA99 == false) {
        fVar19 = (float)dVar24;
      }
      if ((double)(fVar19 + fVar19) <= this->m_yVelocity) goto LAB_100377808;
    }
    else if (this->m_yVelocity <= dVar24 + dVar24) goto LAB_100377808;
  }
  else {
    fVar19 = (float)(this->m_gravity + this->m_gravity);
    if (this->m_isUpsideDown == true) {
      if (this->m_yVelocity <= (double)-fVar19) goto LAB_100377808;
    }
    else if ((double)fVar19 <= this->m_yVelocity) goto LAB_100377808;
  }
  this->m_maybeIsBoosted = false;
LAB_100377808:
  this->m_wasJumpBuffered = this->m_jumpBuffered;
  this->m_wasRobotJump = this->m_touchedPad;
  return;
}


// ==== PlayerObject::updateRotation @ 0x382d40

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PlayerObject__updateRotation(PlayerObject *this,float dt)

{
  float fVar1;
  float fVar2;
  
  if ((this->m_isLocked & 1U) != 0) {
    return;
  }
  if ((this->m_isDashing & 1U) != 0) {
    return;
  }
  if ((this->m_isBall & 1U) != 0) goto LAB_100382dbc;
  if (this->m_isOnSlope == true) {
    PlayerObject__updateSlopeRotation(this,dt);
    goto LAB_100382dbc;
  }
  if (((((this->m_isShip & 1U) != 0) || ((this->m_isBird & 1U) != 0)) ||
      ((this->m_isDart & 1U) != 0)) || (this->m_isSwing == true)) {
    PlayerObject__updateShipRotation();
    goto LAB_100382dbc;
  }
  if (this->m_isOnGround2 == true) {
    if (this->m_isUpsideDown != true) {
      if (-0.25 <= this->m_yVelocity) goto LAB_100382e78;
      goto LAB_100382e80;
    }
    if (0.25 < this->m_yVelocity) goto LAB_100382e80;
LAB_100382e78:
    if ((this->m_wasOnSlope & 1U) != 0) goto LAB_100382e80;
    if ((this->m_isPlatformer == true) && ((this->m_isRotating & 1U) != 0)) goto LAB_100382dbc;
    this->m_isRotating = false;
    this->m_isBallRotating2 = false;
    this->m_isBallRotating = false;
    this->m_rotationSpeed = 0.0;
    fVar1 = (float)PlayerObject__convertToClosestRotation(0);
    fVar2 = dt;
  }
  else {
LAB_100382e80:
    if ((((this->m_isRobot & 1U) == 0) && (this->m_isSpider != true)) ||
       ((this->m_wasOnSlope & 1U) != 0)) goto LAB_100382dbc;
    fVar1 = 0.0;
    fVar2 = dt * 0.5;
  }
  PlayerObject__updateRotation(this,fVar2,fVar1);
LAB_100382dbc:
  if (this->m_rotationSpeed == 0.0) {
    return;
  }
  fVar2 = 1.0;
  if ((this->m_isBallRotating == true) && (fVar2 = 1.0, this->m_isBall == true)) {
    fVar2 = this->m_rotateSpeed;
  }
  fVar1 = (float)virtual_0x160();
                    /* WARNING: Could not recover jumptable at 0x000100382e2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  virtual_0x158
            (fVar1 + fVar2 * (dt / 60.0) * this->m_rotationSpeed,this);
  return;
}


// ==== PlayerObject::updateRotation @ 0x37a590

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PlayerObject__updateRotation(PlayerObject *this,float dt,float rotation)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  if ((this->m_isDashing & 1U) != 0) {
    return;
  }
  fVar1 = (float)virtual_0x160();
  fVar2 = this->m_playerSpeed * 0.175;
  if (this->m_isShip == true) {
    fVar2 = fVar2 * 0.5;
  }
  else if ((((((this->m_isBird & 1U) == 0) && ((this->m_isDart & 1U) == 0)) &&
            ((this->m_isSwing & 1U) == 0)) &&
           (((this->m_isBall & 1U) == 0 && (this->m_isOnGround2 == true)))) &&
          (((this->m_isOnSlope & 1U) == 0 && (this->m_wasOnSlope == false)))) {
    fVar2 = fVar2 * 3.0;
  }
  fVar3 = fVar2 * dt;
  if (dt <= fVar2 * dt) {
    fVar3 = dt;
  }
  fVar1 = (float)func_0x00010022515c(fVar1 * 0.017453292,rotation * 0.017453292,fVar3);
  fVar1 = fVar1 * 57.29578;
  fVar2 = fVar1;
  if (((this->m_isPlatformer == true) &&
      ((((this->m_isShip & 1U) != 0 || ((this->m_isBird & 1U) != 0)) ||
       (((this->m_isDart & 1U) != 0 || (this->m_isSwing == true)))))) &&
     ((this->m_isOnSlope == true && (fVar2 = rotation, this->m_reverseRelated < 1)))) {
    fVar2 = fVar1;
  }
                    /* WARNING: Could not recover jumptable at 0x00010037a6d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  virtual_0x158(fVar2,this);
  return;
}


// ==== PlayerObject::spiderTestJumpInternal @ 0x38373c

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PlayerObject__spiderTestJumpInternal(PlayerObject *this,bool dynamic)

{
  undefined *puVar1;
  undefined *puVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  bool bVar6;
  byte bVar7;
  char cVar8;
  bool bVar9;
  bool bVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  undefined8 uVar15;
  float *pfVar16;
  long lVar17;
  long lVar18;
  GameObject *this_00;
  long *plVar19;
  ulong uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  byte bVar24;
  float fVar25;
  float fVar26;
  double dVar27;
  float fVar28;
  double dVar29;
  float fVar30;
  float fVar31;
  float fVar32;
  float afStack_118 [4];
  undefined1 auStack_108 [4];
  float fStack_104;
  float fStack_100;
  float fStack_fc;
  float afStack_f8 [4];
  float afStack_e8 [4];
  float afStack_d8 [4];
  float afStack_c8 [4];
  float afStack_b8 [6];
  
  if ((this->m_isDead & 1U) != 0) {
    return;
  }
  if ((this->m_isLocked & 1U) != 0) {
    return;
  }
  if ((this->m_maybeReducedEffects & 1U) != 0) {
    return;
  }
  bVar6 = this->m_isSideways;
  if (((bVar6 & 1U) == 0) && ((*(byte *)(*(long *)this->m_gameLayer + 0x311) & 1) == 0)) {
    if (((((this->m_isShip & 1U) == 0) && ((this->m_isBird & 1U) == 0)) &&
        ((this->m_isDart & 1U) == 0)) &&
       (((this->m_isSwing & 1U) == 0 && ((this->m_isBall & 1U) == 0)))) {
      bVar24 = this->m_isSpider ^ 1;
    }
    else {
      bVar24 = 0;
    }
  }
  else {
    bVar24 = 1;
  }
  fVar32 = this->m_vehicleSize;
  uVar15 = getObjectRect/*virtual+0x520*/(this);
  CCRect__CCRect_copy(afStack_b8,uVar15);
  CCRect__CCRect_copy(afStack_c8,afStack_b8);
  uVar22 = (uint)bVar6;
  if ((this->m_isSideways & 1U) == 0) {
    if ((bVar24 & 1) != 0) {
      lVar17 = getPosition/*virtual+0xc0*/(this);
      fVar30 = 90.0;
      if (90.0 < *(float *)(lVar17 + 4) + -3000.0) {
        lVar17 = getPosition/*virtual+0xc0*/(this);
        fVar30 = *(float *)(lVar17 + 4) + -3000.0;
      }
      lVar17 = getPosition/*virtual+0xc0*/(this);
      fVar31 = *(float *)(lVar17 + 4) + 3000.0;
      goto LAB_100383908;
    }
    fVar30 = (float)GJBaseGameLayer__getMinPortalY(*(undefined8 *)this->m_gameLayer);
    fVar31 = (float)GJBaseGameLayer__getMaxPortalY(*(undefined8 *)this->m_gameLayer);
    if ((this->m_isUpsideDown & 1U) != 0) goto LAB_100383914;
LAB_100383970:
    lVar17 = 8;
    if (uVar22 == 0) {
      lVar17 = 0xc;
    }
    lVar18 = 0;
    if (uVar22 == 0) {
      lVar18 = 4;
    }
    fVar25 = *(float *)((long)afStack_c8 + lVar18) + *(float *)((long)afStack_c8 + lVar17) + -2.0;
    *(float *)((long)afStack_c8 + lVar18) = fVar25;
    *(float *)((long)afStack_c8 + lVar17) = fVar31 - fVar25;
  }
  else {
    pfVar16 = (float *)getPosition/*virtual+0xc0*/(this);
    fVar31 = *pfVar16 + 3000.0;
    pfVar16 = (float *)getPosition/*virtual+0xc0*/(this);
    fVar30 = 0.0;
    if (*pfVar16 + -3000.0 <= 0.0) {
LAB_100383908:
      bVar7 = this->m_isUpsideDown;
    }
    else {
      pfVar16 = (float *)getPosition/*virtual+0xc0*/(this);
      fVar30 = *pfVar16 + -3000.0;
      bVar7 = this->m_isUpsideDown;
    }
    if ((bVar7 & 1) == 0) goto LAB_100383970;
LAB_100383914:
    lVar17 = 0;
    if (bVar6 == false) {
      lVar17 = 4;
    }
    lVar18 = 8;
    if (bVar6 == false) {
      lVar18 = 0xc;
    }
    *(float *)((long)afStack_c8 + lVar18) = (*(float *)((long)afStack_c8 + lVar17) - fVar30) + 2.0;
    *(float *)((long)afStack_c8 + lVar17) = fVar30;
  }
  fVar32 = fVar32 * 8.0;
  CCRect__CCRect_copy(afStack_d8,afStack_c8);
  lVar17 = 8;
  if (uVar22 != 0) {
    lVar17 = 0xc;
  }
  *(undefined4 *)((long)afStack_d8 + lVar17) = *(undefined4 *)((long)afStack_b8 + lVar17);
  afStack_d8[bVar6] = afStack_b8[bVar6];
  CCRect__CCRect_copy(afStack_e8,afStack_d8);
  *(float *)((long)afStack_e8 + lVar17) = *(float *)((long)afStack_e8 + lVar17) + 4.0;
  fVar25 = *(float *)((long)afStack_c8 + lVar17);
  *(float *)((long)afStack_d8 + lVar17) = fVar32;
  afStack_d8[bVar6] = afStack_d8[bVar6] + (fVar25 - fVar32) * 0.5;
  uVar23 = (uint)bVar6;
  if ((this->m_isPlatformer & 1U) == 0) {
    fVar32 = *(float *)((long)afStack_b8 + lVar17) * 0.5;
    *(float *)((long)afStack_c8 + lVar17) = fVar32 + 1.0;
    fVar25 = afStack_b8[bVar6];
    if ((this->m_isGoingLeft & 1U) != 0) {
      fVar32 = fVar25 - fVar32;
      fVar25 = -1.0;
    }
    afStack_c8[uVar22] = fVar32 + fVar25;
  }
  else {
    *(float *)((long)afStack_c8 + lVar17) = fVar25 + -2.0;
    afStack_c8[uVar23] = afStack_c8[uVar22] + 1.0;
  }
  uVar15 = *(undefined8 *)this->m_gameLayer;
  CCRect__CCRect_copy(afStack_f8,afStack_c8);
  lVar17 = GJBaseGameLayer__staticObjectsInRect(uVar15,afStack_f8,1);
  uVar15 = *(undefined8 *)this->m_gameLayer;
  CCRect__CCRect_copy(afStack_f8,afStack_d8);
  lVar18 = GJBaseGameLayer__damagingObjectsInRect(uVar15,afStack_f8,1);
  bVar9 = this->m_isUpsideDown == false;
  puVar2 = &DAT_100372e94;
  if (bVar9) {
    puVar2 = &DAT_100372e30;
  }
  puVar1 = &DAT_100372dcc;
  if (bVar9) {
    puVar1 = &DAT_100372d68;
  }
  if (this->m_isSideways == false) {
    puVar2 = puVar1;
  }
  iVar11 = CCArray__count(lVar17);
  if (iVar11 == 0) {
    iVar11 = CCArray__count(lVar18);
    if ((iVar11 != 0) || (dynamic)) goto LAB_100383b34;
    bVar9 = false;
  }
  else {
    bVar9 = false;
    if (dynamic) {
LAB_100383b34:
      uVar15 = *(undefined8 *)this->m_gameLayer;
      CCRect__CCRect_copy(afStack_f8,afStack_e8);
      bVar9 = true;
      lVar17 = GJBaseGameLayer__staticObjectsInRect(uVar15,afStack_f8,1);
    }
  }
  iVar11 = CCArray__count(lVar17);
  if (iVar11 != 0) {
    _qsort(*(undefined8 *)(*(undefined4 **)(lVar17 + 0x38) + 4),**(undefined4 **)(lVar17 + 0x38),8,
           puVar2);
  }
  iVar11 = CCArray__count(lVar18);
  if (iVar11 != 0) {
    _qsort(*(undefined8 *)(*(undefined4 **)(lVar18 + 0x38) + 4),**(undefined4 **)(lVar18 + 0x38),8,
           puVar2);
  }
  iVar11 = CCArray__count(lVar17);
  if (iVar11 != 0) {
    CCRect__CCRect_copy(afStack_f8,afStack_b8);
    uVar15 = getPosition/*virtual+0xc0*/(this);
    CCPoint__CCPoint_copy(&fStack_100,uVar15);
    iVar12 = CCArray__count(lVar17);
    if (iVar12 != 0) {
      uVar21 = 0;
      fVar32 = 0.0;
      lVar3 = 0;
      if (uVar23 == 0) {
        lVar3 = 4;
      }
      lVar4 = 8;
      if (uVar23 == 0) {
        lVar4 = 0xc;
      }
LAB_100383ce0:
      this_00 = (GameObject *)CCArray__objectAtIndex(lVar17,uVar21);
      bVar10 = this->m_isUpsideDown;
      getObjectRect/*virtual+0x520*/();
      if ((bVar10 & 1U) == 0) {
        if (uVar23 == 0) {
          fVar25 = (float)CCRect__getMinY();
          pfVar16 = afStack_b8 + 3;
        }
        else {
          fVar25 = (float)CCRect__getMinX();
          pfVar16 = afStack_b8 + 2;
        }
        fVar28 = *pfVar16 * -0.5;
      }
      else {
        if (uVar23 == 0) {
          fVar25 = (float)CCRect__getMaxY();
          pfVar16 = afStack_b8 + 3;
        }
        else {
          fVar25 = (float)CCRect__getMaxX();
          pfVar16 = afStack_b8 + 2;
        }
        fVar28 = *pfVar16 * 0.5;
      }
      fVar25 = fVar25 + fVar28;
      iVar12 = virtual_0x6f8(this_00);
      if (iVar12 == 0x19) {
        getRealPosition/*virtual+0x540*/(afStack_118,this_00);
        if (this->m_isSideways == true) {
          PlayerObject__rotateGameplayObject(this,this_00);
          bVar10 = GameObject__slopeFloorTop(this_00);
          bVar10 = this->m_isUpsideDown != bVar10;
          if (!bVar10) goto LAB_100383da8;
LAB_100383dd8:
          dVar27 = GameObject__slopeYPos(this_00,fStack_100);
          getRealPosition/*virtual+0x540*/(auStack_108,this_00);
          lVar5 = 8;
          if (uVar23 == 0) {
            lVar5 = 0xc;
          }
          fVar25 = 1.0;
          if (this->m_isUpsideDown == false) {
            fVar25 = -1.0;
          }
          fVar25 = *(float *)((long)afStack_118 + lVar3) + (float)(dVar27 - (double)fStack_104) +
                   fVar25 * *(float *)((long)afStack_b8 + lVar5) * 0.5;
          cVar8 = this->m_isSideways;
        }
        else {
          bVar10 = GameObject__slopeFloorTop(this_00);
          bVar10 = this->m_isUpsideDown != bVar10;
          if (bVar10) goto LAB_100383dd8;
LAB_100383da8:
          cVar8 = this->m_isSideways;
        }
        if (cVar8 == '\x01') {
          PlayerObject__unrotateGameplayObject(this,this_00);
        }
      }
      else {
        bVar10 = false;
      }
      pfVar16 = &fStack_100;
      if (uVar23 == 0) {
        pfVar16 = &fStack_fc;
      }
      fVar28 = fVar32;
      if ((this->m_isUpsideDown & 1U) != 0) {
        if (*pfVar16 + 10.0 < fVar25) goto LAB_100383ccc;
LAB_100383e9c:
        if ((bVar10 & this->m_isPlatformer) == 0) {
          if ((this->m_isPlatformer & 1U) != 0) goto LAB_1003840a8;
          if ((this->m_isGoingLeft & 1U) == 0) {
            getObjectRect/*virtual+0x520*/(this_00);
            if ((bVar6 & 1U) == 0) {
              fVar26 = (float)CCRect__getMinX();
              pfVar16 = &fStack_100;
            }
            else {
              fVar26 = (float)CCRect__getMinY();
              pfVar16 = &fStack_fc;
            }
            if (*pfVar16 < fVar26) goto LAB_100383f24;
            if ((this->m_isGoingLeft & 1U) == 0) goto LAB_1003840a8;
          }
          getObjectRect/*virtual+0x520*/(this_00);
          if ((bVar6 & 1U) == 0) {
            fVar26 = (float)CCRect__getMaxX();
            pfVar16 = &fStack_100;
          }
          else {
            fVar26 = (float)CCRect__getMaxY();
            pfVar16 = &fStack_fc;
          }
          if (*pfVar16 <= fVar26) goto LAB_1003840a8;
        }
LAB_100383f24:
        iVar12 = CCArray__count(lVar17);
        if (iVar12 != 0) {
          uVar13 = 0;
          if (bVar10 == false) {
            do {
              plVar19 = (long *)CCArray__objectAtIndex(lVar17,uVar13);
              if (uVar21 != uVar13) {
                lVar5 = 8;
                if (bVar6 == false) {
                  lVar5 = 0xc;
                }
                *(float *)((long)afStack_f8 + lVar3) =
                     fVar25 + *(float *)((long)afStack_b8 + lVar5) * -0.5;
                uVar15 = (**(code **)(*plVar19 + 0x520))();
                CCRect__CCRect_copy(afStack_118,uVar15);
                *(float *)((long)afStack_118 + lVar4) = *(float *)((long)afStack_118 + lVar4) + -4.0
                ;
                *(float *)((long)afStack_118 + lVar3) = *(float *)((long)afStack_118 + lVar3) + 2.0;
                uVar20 = CCRect__intersectsRect(afStack_118,afStack_f8);
                if ((uVar20 & 1) != 0) goto LAB_100383ccc;
              }
              uVar13 = uVar13 + 1;
              uVar14 = CCArray__count(lVar17);
              if (uVar14 <= uVar13) goto LAB_1003840a8;
            } while( true );
          }
          do {
            plVar19 = (long *)CCArray__objectAtIndex(lVar17,uVar13);
            if (uVar21 != uVar13) {
              lVar5 = 8;
              if (bVar6 == false) {
                lVar5 = 0xc;
              }
              *(float *)((long)afStack_f8 + lVar3) =
                   fVar25 + *(float *)((long)afStack_b8 + lVar5) * -0.5;
              uVar15 = (**(code **)(*plVar19 + 0x520))();
              CCRect__CCRect_copy(afStack_118,uVar15);
              iVar12 = CCRect__intersectsRect(afStack_118,afStack_f8);
              if (iVar12 != 0) goto code_r0x000100383fb0;
            }
            uVar13 = uVar13 + 1;
            uVar14 = CCArray__count(lVar17);
            if (uVar14 <= uVar13) break;
          } while( true );
        }
        goto LAB_1003840a8;
      }
      if (*pfVar16 + -10.0 <= fVar25) goto LAB_100383e9c;
LAB_100383ccc:
      uVar21 = uVar21 + 1;
      uVar13 = CCArray__count(lVar17);
      fVar32 = fVar28;
      if (uVar13 <= uVar21) goto LAB_100384098;
      goto LAB_100383ce0;
    }
    fVar25 = 0.0;
    fVar32 = 0.0;
    goto LAB_1003840a8;
  }
  iVar12 = CCArray__count(lVar18);
  if (iVar12 != 0) {
    plVar19 = (long *)CCArray__objectAtIndex(lVar18,0);
    (**(code **)(*plVar19 + 0x540))(afStack_f8);
    lVar17 = 0;
    if (uVar23 == 0) {
      lVar17 = 4;
    }
    fVar25 = *(float *)((long)afStack_f8 + lVar17);
    fVar32 = 0.0;
    goto LAB_1003840a8;
  }
  lVar17 = 8;
  if (uVar23 == 0) {
    lVar17 = 0xc;
  }
  fVar25 = *(float *)((long)afStack_b8 + lVar17) * 0.5;
  if (this->m_isUpsideDown == true) {
    fVar25 = fVar30 + fVar25;
  }
  else {
    fVar25 = fVar31 - fVar25;
  }
LAB_100384128:
  iVar11 = CCArray__count(lVar18);
  if (iVar11 != 0) {
    plVar19 = (long *)CCArray__objectAtIndex(lVar18,0);
    (**(code **)(*plVar19 + 0x540))(afStack_f8);
    lVar17 = 0;
    if (bVar6 == false) {
      lVar17 = 4;
    }
    fVar32 = *(float *)((long)afStack_f8 + lVar17);
    bVar6 = fVar32 <= fVar25;
    if (this->m_isUpsideDown == false) {
      bVar6 = fVar25 <= fVar32;
    }
    if (!bVar6) {
      fVar25 = fVar32;
    }
    if (!bVar9 && !bVar6) {
      PlayerObject__spiderTestJumpInternal(this,true);
      return;
    }
  }
LAB_10038418c:
  uVar15 = getPosition/*virtual+0xc0*/(this);
  CCPoint__CCPoint_copy(afStack_f8,uVar15);
  CCPoint__CCPoint_copy(afStack_118,afStack_f8);
  lVar17 = 0;
  if (uVar22 == 0) {
    lVar17 = 4;
  }
  *(float *)((long)afStack_118 + lVar17) = fVar25;
  setPosition/*virtual+0xb8*/(this,afStack_118);
  PlayerObject__flipGravity(this,(bool)((this->m_isUpsideDown ^ 0xffU) & 1),true);
  dVar27 = 1.0;
  if (this->m_isUpsideDown == false) {
    dVar27 = -1.0;
  }
  dVar29 = (double)(int)dVar27;
  if (dVar27 != dVar29) {
    dVar27 = (double)(long)((dVar27 - dVar29) * 1000.0) / 1000.0 + dVar29;
  }
  this->m_yVelocity = dVar27;
  this->m_isOnGround3 = false;
  this->m_jumpBuffered = false;
  CCDictionary__removeAllObjects(*(undefined8 *)this->m_collisionLogTop);
  CCDictionary__removeAllObjects(*(undefined8 *)this->m_collisionLogBottom);
  CCDictionary__removeAllObjects(*(undefined8 *)this->m_collisionLogLeft);
  CCDictionary__removeAllObjects(*(undefined8 *)this->m_collisionLogRight);
  this->m_unk50C = -1;
  this->m_unk510 = -1;
  this->m_lastCollisionLeft = -1;
  this->m_lastCollisionRight = -1;
  this->m_lastCollisionBottom = -1;
  this->m_lastCollisionTop = -1;
  *(undefined4 *)(this->m_playerColor2 + lVar17 + 3) = *(undefined4 *)((long)afStack_118 + lVar17);
  this->m_lastSpiderFlipTime = this->m_totalTime;
  CCPoint__CCPoint_copy(&fStack_100,afStack_f8);
  CCPoint__CCPoint_copy(auStack_108,afStack_118);
  PlayerObject__playSpiderDashEffect(this,&fStack_100,auStack_108);
  if (((bVar24 & 1) != 0) && (*(long *)this->m_gameLayer != 0)) {
    GJBaseGameLayer__checkCameraLimitAfterTeleport(0x42700000,*(long *)this->m_gameLayer,this);
  }
  return;
code_r0x000100383fb0:
  fVar28 = fVar25;
  if (fVar32 != 0.0) {
    bVar10 = fVar25 != fVar32 && fVar25 >= fVar32;
    if (this->m_isUpsideDown == false) {
      bVar10 = fVar25 < fVar32;
    }
    if (!bVar10) {
      fVar28 = fVar32;
    }
  }
  goto LAB_100383ccc;
LAB_100384098:
  fVar25 = 0.0;
LAB_1003840a8:
  if (this->m_isPlatformer == false) {
    fVar32 = 0.0;
  }
  if (fVar32 == 0.0) {
    if (fVar25 == 0.0) {
      lVar17 = 8;
      if (bVar6 == false) {
        lVar17 = 0xc;
      }
      fVar32 = *(float *)((long)afStack_b8 + lVar17) * 0.5;
      if ((this->m_isUpsideDown & 1U) == 0) {
        fVar25 = fVar31 - fVar32;
      }
      else {
        fVar25 = fVar30 + fVar32;
      }
    }
  }
  else {
    bVar10 = fVar32 != fVar25 && fVar32 >= fVar25;
    if (this->m_isUpsideDown == false) {
      bVar10 = fVar32 < fVar25;
    }
    fVar30 = fVar32;
    if (!bVar10) {
      fVar30 = fVar25;
    }
    fVar25 = fVar30;
    if (fVar30 == 0.0) {
      fVar25 = fVar32;
    }
  }
  if (iVar11 == 0) goto LAB_10038418c;
  goto LAB_100384128;
}


// ==== PlayerObject::isBoostValid @ 0x37d9d4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

bool PlayerObject__isBoostValid(PlayerObject *this,float yVelocity)

{
  if ((this->m_isUpsideDown & 1U) == 0) {
    if ((this->m_isCurrentSlopeTop != false) && (this->m_slopeFlipGravityRelated == true))
    goto LAB_10037da04;
  }
  else if (((this->m_isCurrentSlopeTop & 1U) != 0) || (this->m_slopeFlipGravityRelated != true)) {
LAB_10037da04:
    return (double)yVelocity < this->m_yVelocity;
  }
  return this->m_yVelocity < (double)yVelocity;
}


// ==== PlayerObject::boostPlayer @ 0x37da2c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PlayerObject__boostPlayer(PlayerObject *this,float yVelocity)

{
  byte bVar1;
  undefined8 uVar2;
  float fVar3;
  float fVar4;
  double dVar5;
  double dVar6;
  char acStack_38 [23];
  char cStack_21;
  
  this->m_maybeIsBoosted = true;
  this->m_isOnGround2 = false;
  this->m_isOnGround = false;
  this->m_shouldTryPlacingCheckpoint = true;
  this->m_isAccelerating = true;
  dVar6 = (double)yVelocity;
  dVar5 = (double)(int)yVelocity;
  if (dVar5 == dVar6) {
    this->m_yVelocity = dVar6;
    bVar1 = this->m_isDashing;
  }
  else {
    this->m_yVelocity = (double)(long)((dVar6 - dVar5) * 1000.0) / 1000.0 + dVar5;
    bVar1 = this->m_isDashing;
  }
  if ((bVar1 & 1) == 0) {
    if (((((this->m_isShip & 1U) == 0) && ((this->m_isBird & 1U) == 0)) &&
        ((this->m_isDart & 1U) == 0)) &&
       ((((this->m_isSwing & 1U) == 0 && ((this->m_isBall & 1U) == 0)) &&
        (((this->m_isRobot & 1U) == 0 && ((this->m_isSpider & 1U) == 0)))))) {
      this->m_isBallRotating = false;
      fVar4 = 0.8666667;
      if (this->m_vehicleSize != 1.0) {
        fVar4 = 0.6666667;
      }
      fVar3 = 180.0;
      if (this->m_isUpsideDown == false) {
        fVar3 = -180.0;
      }
      this->m_rotationSpeed = fVar3 / fVar4;
      this->m_isRotating = true;
      this->m_isBallRotating2 = false;
    }
    else if (this->m_isSpider == true) {
      cStack_21 = '\t';
      builtin_strncpy(acStack_38,"fall_loop",10);
      CCAnimatedSprite__tweenToAnimation(0x3dcccccd,*(undefined8 *)this->m_spiderSprite,acStack_38);
      if (cStack_21 < '\0') {
        __ZdlPv(acStack_38._0_8_);
      }
    }
  }
  uVar2 = getPosition/*virtual+0xc0*/(this);
  CCPoint__operator_assign(&this->m_lastGroundedPos,uVar2);
  return;
}


// ==== PlayerObject::updateMove @ 0x378054

/* WARNING: Removing unreachable block (ram,0x0001003783d0) */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PlayerObject__updateMove(PlayerObject *this,float dt)

{
  ulong uVar1;
  undefined8 *******pppppppuVar2;
  char cVar3;
  byte bVar4;
  undefined8 *******pppppppuVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  int iVar11;
  undefined8 uVar12;
  byte bVar13;
  uint uVar14;
  double dVar15;
  undefined8 *puVar16;
  long lVar17;
  byte bVar18;
  byte bVar19;
  byte bVar20;
  ulong uVar21;
  float fVar22;
  float fVar23;
  double dVar24;
  double dVar25;
  float fVar26;
  double dVar27;
  double dVar28;
  double dVar29;
  double dVar30;
  double dVar31;
  double dVar32;
  undefined4 uStack_168;
  undefined2 uStack_164;
  undefined1 uStack_162;
  undefined1 uStack_161;
  char cStack_151;
  undefined4 uStack_150;
  undefined2 uStack_14c;
  undefined1 uStack_14a;
  undefined1 uStack_149;
  char cStack_139;
  undefined8 uStack_138;
  char cStack_121;
  undefined8 uStack_120;
  char cStack_109;
  undefined4 uStack_108;
  undefined2 uStack_104;
  undefined1 uStack_102;
  undefined1 uStack_f1;
  undefined8 *******pppppppuStack_f0;
  ulong uStack_e8;
  undefined8 uStack_e0;
  undefined4 uStack_d8;
  undefined2 uStack_d4;
  undefined1 uStack_d2;
  undefined1 uStack_c1;
  undefined8 *******pppppppuStack_c0;
  ulong uStack_b8;
  ulong uStack_b0;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  
  dVar30 = this->m_speedMultiplier * (double)this->m_playerSpeed;
  bVar10 = this->m_isOnSlope;
  if (((bVar10 == true) && ((this->m_slopeFlipGravityRelated & 1U) == 0)) &&
     ((this->m_maybeUpsideDownSlope & 1U) == 0)) {
    fVar22 = (float)_cosf(this->m_slopeAngle);
    dVar30 = dVar30 * (double)fVar22;
  }
  if ((this->m_holdingLeft & 1U) == 0) {
    if ((this->m_holdingRight & 1U) == 0) {
      if ((this->m_platformerMovingLeft & 1U) == 0) {
        bVar19 = 0;
        bVar20 = this->m_platformerMovingRight;
        goto joined_r0x00010037813c;
      }
      bVar18 = 0;
    }
    else {
      bVar18 = 1;
    }
    bVar19 = 0;
    bVar20 = 1;
joined_r0x000100378128:
    if ((this->m_isOnIce & 1U) != 0) goto LAB_100378168;
LAB_100378140:
    dVar15 = 1.0;
    if (((this->m_isOnGround2 & 1U) == 0) && (this->m_isSlidingRight != (bool)(bVar19 & 1))) {
      if (0 < this->m_maybeSlidingTime) goto LAB_100378168;
      dVar31 = this->m_totalTime - this->m_maybeSlidingStartTime;
      if (dVar31 < 0.5) {
        dVar15 = (double)(float)((dVar31 + dVar31) * 0.800000011920929 + 0.20000000298023224);
      }
    }
  }
  else {
    if (this->m_holdingRight == false) {
      bVar20 = 1;
      bVar19 = 1;
joined_r0x00010037813c:
      bVar18 = 0;
      goto joined_r0x000100378128;
    }
    bVar19 = this->m_leftPressedFirst;
    bVar18 = bVar19 ^ 1;
    bVar20 = 1;
    if ((this->m_isOnIce & 1U) == 0) goto LAB_100378140;
LAB_100378168:
    dVar15 = 0.20000000298023224;
  }
  dVar32 = this->m_platformerXVelocity;
  dVar31 = (double)dt;
  if ((((this->m_platformerMovingLeft & bVar19 & 1) == 0) &&
      ((this->m_platformerMovingRight & bVar18 & 1) == 0)) ||
     (ABS(dVar32) < dVar30 * 0.949999988079071 || bVar10 == false)) {
    bVar13 = 0;
    if ((this->m_isSliding & 1U) == 0) goto LAB_1003781e8;
LAB_100378208:
    dVar24 = 1.0;
    if (this->m_yVelocityBeforeSlope < 0.0) {
      dVar24 = (this->m_yVelocityBeforeSlope / -15.0) * 0.30000001192092896 + 1.0;
    }
    if ((bVar13 & 1) == 0) {
      dVar24 = this->m_maybeSlopeForce;
    }
    else {
      dVar24 = this->m_maybeSlopeForce + dVar24 * (double)(dt * 0.25);
      this->m_maybeSlopeForce = dVar24;
    }
    dVar30 = dVar30 + dVar24;
    this->m_isSliding = true;
    dVar15 = dVar31 * 0.5 * dVar15;
    if ((bVar19 & 0.0 < dVar32) != 0) goto LAB_10037828c;
LAB_100378280:
    if ((bVar18 & 1) == 0) goto LAB_100378294;
    if (dVar32 < 0.0) goto LAB_10037828c;
LAB_10037829c:
    this->m_platformerVelocityRelated = 0.0;
    if (((bVar19 & -dVar30 < dVar32) == 0) && ((bVar18 & dVar32 < dVar30) == 0)) {
      cVar3 = this->m_isOnGround2;
    }
    else {
      dVar24 = -1.0;
      if ((bVar19 & 1) == 0) {
        dVar24 = 1.0;
      }
      this->m_platformerXVelocity = dVar32 + dVar24 * dVar15;
      cVar3 = this->m_isOnGround2;
    }
    if (cVar3 == '\x01') {
      if (this->m_isRobot == true) {
        uVar12 = *(undefined8 *)this->m_robotSprite;
        if ((char)this->m_currentRobotAnimation[0x17] < '\0') {
          gd__string__assign(&uStack_a0,*(undefined8 *)this->m_currentRobotAnimation,
                              *(undefined8 *)(this->m_currentRobotAnimation + 8));
        }
        else {
          uStack_98 = *(undefined8 *)(this->m_currentRobotAnimation + 8);
          uStack_a0 = *(undefined8 *)this->m_currentRobotAnimation;
          uStack_90 = *(undefined8 *)(this->m_currentRobotAnimation + 0x10);
        }
        CCAnimatedSprite__runAnimation(uVar12,&uStack_a0);
      }
      else if (this->m_isSpider == true) {
        PlayerObject__playDynamicSpiderRun(this);
      }
    }
    bVar10 = false;
    bVar6 = true;
    dVar24 = 0.05000000074505806;
    dVar25 = this->m_platformerXVelocity;
joined_r0x000100378400:
    if (0.5 <= ABS(dVar25)) goto LAB_1003787b4;
LAB_100378404:
    this->m_affectedByForces = false;
LAB_1003787c8:
    if ((this->m_isMoving & 1U) != 0) {
      bVar10 = true;
      goto LAB_1003787e8;
    }
    if (this->m_maybeHasStopped == true) goto LAB_1003787e8;
LAB_1003787f0:
    if ((this->m_maybeGoingCorrectSlopeDirection == true) && (this->m_isOnIce == false)) {
      dVar24 = 0.10000000149011612;
    }
    bVar13 = this->m_platformerMovingLeft;
    if ((bVar13 & 1) != 0) goto LAB_100378820;
LAB_100378870:
    if ((this->m_platformerMovingRight & 1U) != 0) {
      this->m_isSlidingRight = (bool)bVar13;
      bVar4 = bVar18;
      goto joined_r0x00010037887c;
    }
  }
  else {
    bVar13 = this->m_maybeUpsideDownSlope ^ 1;
    if ((this->m_isSliding & 1U) != 0) goto LAB_100378208;
LAB_1003781e8:
    if ((bVar13 & 1) != 0) goto LAB_100378208;
    dVar15 = dVar31 * 0.5 * dVar15;
    if ((bVar19 & 0.0 < dVar32) == 0) goto LAB_100378280;
LAB_10037828c:
    dVar15 = dVar15 * 1.5;
LAB_100378294:
    if (((bVar19 | bVar18) & 1) != 0) goto LAB_10037829c;
    if (this->m_isOnGround2 == true) {
      if (this->m_isRobot == true) {
        lVar17 = *(long *)(*(long *)this->m_robotSprite + 0x288);
        if (*(char *)(lVar17 + 0x1a7) < '\0') {
          gd__string__assign(&pppppppuStack_c0,*(undefined8 *)(lVar17 + 400),
                              *(undefined8 *)(lVar17 + 0x198));
        }
        else {
          uStack_b8 = *(ulong *)(lVar17 + 0x198);
          pppppppuStack_c0 = *(undefined8 ********)(lVar17 + 400);
          uStack_b0 = *(ulong *)(lVar17 + 0x1a0);
        }
        uStack_c1 = 6;
        uStack_d8 = 0x656c6469;
        uStack_d4 = 0x3130;
        uStack_d2 = 0;
        pppppppuVar2 = pppppppuStack_c0;
        uVar1 = uStack_b8;
        if (-1 < (long)uStack_b0) {
          pppppppuVar2 = &pppppppuStack_c0;
          uVar1 = uStack_b0 >> 0x38;
        }
        uVar21 = uVar1;
        if (5 < uVar1) {
          uVar21 = 6;
        }
        iVar11 = _memcmp(pppppppuVar2,&uStack_d8,uVar21);
        if ((uVar1 != 6) || (bVar10 = false, iVar11 != 0)) {
          lVar17 = *(long *)(*(long *)this->m_robotSprite + 0x288);
          if (*(char *)(lVar17 + 0x1a7) < '\0') {
            gd__string__assign(&pppppppuStack_f0,*(undefined8 *)(lVar17 + 400),
                                *(undefined8 *)(lVar17 + 0x198));
          }
          else {
            uStack_e8 = *(ulong *)(lVar17 + 0x198);
            pppppppuStack_f0 = *(undefined8 ********)(lVar17 + 400);
            uStack_e0 = *(long *)(lVar17 + 0x1a0);
          }
          pppppppuVar5 = pppppppuStack_f0;
          uStack_f1 = 6;
          uStack_108 = 0x656c6469;
          uStack_104 = 0x3230;
          uStack_102 = 0;
          uVar21 = (ulong)uStack_e0._7_1_;
          pppppppuVar2 = pppppppuStack_f0;
          uVar1 = uStack_e8;
          if (-1 < uStack_e0) {
            pppppppuVar2 = &pppppppuStack_f0;
            uVar1 = uVar21;
          }
          bVar10 = uVar1 != 6;
          if (5 < uVar1) {
            uVar1 = 6;
          }
          iVar11 = _memcmp(pppppppuVar2,&uStack_108,uVar1);
          bVar10 = iVar11 != 0 || bVar10;
          if ((long)uVar21 < 0) {
            __ZdlPv(pppppppuVar5);
          }
        }
        if ((long)uStack_b0 < 0) {
          __ZdlPv(pppppppuStack_c0);
        }
        if (bVar10) {
          cStack_109 = '\x06';
          uStack_120._0_4_ = 0x656c6469;
          uStack_120._4_2_ = 0x3130;
          uStack_120._6_1_ = 0;
          CCAnimatedSprite__tweenToAnimation(0x3e4ccccd,*(undefined8 *)this->m_robotSprite,&uStack_120);
          if (cStack_109 < '\0') {
            puVar16 = &uStack_120;
LAB_100378704:
            __ZdlPv(*puVar16);
          }
        }
      }
      else if (this->m_isSpider == true) {
        lVar17 = *(long *)(*(long *)this->m_spiderSprite + 0x288);
        if (*(char *)(lVar17 + 0x1a7) < '\0') {
          gd__string__assign(&pppppppuStack_c0,*(undefined8 *)(lVar17 + 400),
                              *(undefined8 *)(lVar17 + 0x198));
        }
        else {
          uStack_b8 = *(ulong *)(lVar17 + 0x198);
          pppppppuStack_c0 = *(undefined8 ********)(lVar17 + 400);
          uStack_b0 = *(ulong *)(lVar17 + 0x1a0);
        }
        uStack_c1 = 6;
        uStack_d8 = 0x656c6469;
        uStack_d4 = 0x3130;
        uStack_d2 = 0;
        pppppppuVar2 = pppppppuStack_c0;
        uVar1 = uStack_b8;
        if (-1 < (long)uStack_b0) {
          pppppppuVar2 = &pppppppuStack_c0;
          uVar1 = uStack_b0 >> 0x38;
        }
        uVar21 = uVar1;
        if (5 < uVar1) {
          uVar21 = 6;
        }
        iVar11 = _memcmp(pppppppuVar2,&uStack_d8,uVar21);
        if ((uVar1 != 6) || (bVar10 = false, iVar11 != 0)) {
          lVar17 = *(long *)(*(long *)this->m_spiderSprite + 0x288);
          if (*(char *)(lVar17 + 0x1a7) < '\0') {
            gd__string__assign(&pppppppuStack_f0,*(undefined8 *)(lVar17 + 400),
                                *(undefined8 *)(lVar17 + 0x198));
          }
          else {
            uStack_e8 = *(ulong *)(lVar17 + 0x198);
            pppppppuStack_f0 = *(undefined8 ********)(lVar17 + 400);
            uStack_e0 = *(long *)(lVar17 + 0x1a0);
          }
          pppppppuVar5 = pppppppuStack_f0;
          uStack_f1 = 6;
          uStack_108 = 0x656c6469;
          uStack_104 = 0x3230;
          uStack_102 = 0;
          uVar21 = (ulong)uStack_e0._7_1_;
          pppppppuVar2 = pppppppuStack_f0;
          uVar1 = uStack_e8;
          if (-1 < uStack_e0) {
            pppppppuVar2 = &pppppppuStack_f0;
            uVar1 = uVar21;
          }
          bVar10 = uVar1 != 6;
          if (5 < uVar1) {
            uVar1 = 6;
          }
          iVar11 = _memcmp(pppppppuVar2,&uStack_108,uVar1);
          bVar10 = iVar11 != 0 || bVar10;
          if ((long)uVar21 < 0) {
            __ZdlPv(pppppppuVar5);
          }
        }
        if ((long)uStack_b0 < 0) {
          __ZdlPv(pppppppuStack_c0);
        }
        if (bVar10) {
          cStack_121 = '\x06';
          uStack_138._0_4_ = 0x656c6469;
          uStack_138._4_2_ = 0x3130;
          uStack_138._6_1_ = 0;
          CCAnimatedSprite__tweenToAnimation(0x3e4ccccd,*(undefined8 *)this->m_spiderSprite,&uStack_138);
          if (cStack_121 < '\0') {
            puVar16 = &uStack_138;
            goto LAB_100378704;
          }
        }
      }
    }
    if ((this->m_isOnIce & 1U) == 0) {
      fVar23 = (float)NEON_fminnm(this->m_platformerVelocityRelated + 0.2,0x3f800000);
      fVar22 = 0.2;
      if ((this->m_isOnGround2 & 1U) == 0) {
        if ((((this->m_isShip & 1U) == 0) && ((this->m_isBall & 1U) == 0)) &&
           ((this->m_isBird & 1U) == 0)) {
          if ((this->m_isRobot & 1U) == 0) {
            fVar22 = 0.1;
            if (this->m_isSpider == false) {
              fVar22 = 0.05;
            }
          }
          else {
            fVar22 = 0.1;
          }
        }
        else {
          fVar22 = 0.02;
        }
      }
      bVar6 = false;
      dVar24 = (double)fVar23;
      this->m_platformerVelocityRelated = this->m_platformerVelocityRelated + fVar22 * dt;
      bVar10 = true;
      dVar25 = this->m_platformerXVelocity;
      goto joined_r0x000100378400;
    }
    bVar6 = false;
    bVar10 = true;
    dVar24 = 0.20000000298023224;
    dVar25 = this->m_platformerXVelocity;
    if (ABS(dVar25) < 0.5) goto LAB_100378404;
LAB_1003787b4:
    if ((this->m_affectedByForces & 1U) == 0) goto LAB_1003787c8;
    bVar10 = true;
LAB_1003787e8:
    if ((this->m_isOnIce & 1U) != 0) goto LAB_1003787f0;
    dVar24 = 0.05000000074505806;
    if (((this->m_decreaseBoostSlide | bVar20) & 1) == 0) {
      dVar24 = 0.20000000298023224;
    }
    bVar13 = this->m_platformerMovingLeft;
    if ((bVar13 & 1) == 0) goto LAB_100378870;
LAB_100378820:
    this->m_isSlidingRight = (bool)bVar13;
    if ((bVar19 & 1) != 0) {
      bVar4 = bVar18 | this->m_platformerMovingRight ^ 0xffU;
joined_r0x00010037887c:
      if ((bVar4 & 1) != 0) goto LAB_100378a88;
    }
    if (*(long *)this->m_currentSlope == 0) {
      dVar27 = 0.0;
    }
    else {
      dVar27 = (double)ABS(this->m_slopeAngleRadians * 57.29578);
    }
    dVar28 = 80.0;
    if (dVar27 <= 80.0) {
      dVar28 = dVar27;
    }
    if (dVar28 <= 40.0) {
      dVar28 = 40.0;
    }
    dVar29 = (dVar28 + -40.0) / 40.0;
    dVar28 = dVar31 * 0.5 * (dVar29 * 0.5 + 0.5) * 0.4000000059604645;
    dVar27 = dVar28 * 0.699999988079071;
    if (this->m_isShip == false) {
      dVar27 = dVar28;
    }
    if (((bVar13 != 0) && (0.0 < dVar25)) ||
       ((this->m_platformerMovingRight == true && (dVar25 < 0.0)))) {
      dVar28 = dVar29 * 0.699999988079071 + 1.350000023841858;
      if (this->m_isShip == false) {
        if (this->m_isBall == true) {
          dVar29 = dVar28 + -0.2800000011920929;
        }
        else {
          dVar29 = dVar28 + -0.20000000298023224;
          if (this->m_isSpider == false) {
            dVar29 = dVar28;
          }
        }
      }
      else {
        dVar29 = dVar28 + -0.25;
      }
      dVar28 = dVar29 * 4.0;
      if (this->m_isOnIce == false) {
        dVar28 = dVar29;
      }
      if ((((bVar13 ^ 1 | bVar18) & 1) == 0) ||
         (((bVar19 | this->m_platformerMovingRight ^ 0xffU) & 1) == 0)) {
        dVar28 = dVar28 * 0.800000011920929;
      }
      dVar29 = dVar15 * dVar28;
      if (ABS(dVar15 * dVar28) <= ABS(dVar27)) {
        dVar29 = dVar27;
      }
      cVar3 = this->m_isOnSlope;
    }
    else {
      dVar29 = dVar15 + dVar27;
      if ((bVar13 & bVar18) == 0 && (this->m_platformerMovingRight & bVar19) == 0) {
        dVar29 = dVar27;
      }
      cVar3 = this->m_isOnSlope;
    }
    if ((((cVar3 == '\x01') && ((this->m_isOnGround4 & 1U) == 0)) && (0 < this->m_maybeSlidingTime))
       && ((this->m_maybeUpsideDownSlope & 1U) == 0)) {
      dVar25 = dVar25 * 0.800000011920929;
      this->m_platformerXVelocity = dVar25;
    }
    bVar10 = false;
    dVar15 = -1.0;
    if (bVar13 == 0) {
      dVar15 = 1.0;
    }
    dVar25 = dVar25 + dVar15 * dVar29;
    this->m_platformerXVelocity = dVar25;
  }
LAB_100378a88:
  if (((this->m_maybeGoingCorrectSlopeDirection == true) && (((this->m_isOnIce | bVar13) & 1) == 0))
     && ((this->m_platformerMovingRight & 1U) == 0)) {
    if (this->m_isSlidingRight == true) {
      if (0.0 < dVar25) {
LAB_100378ac8:
        this->m_maybeGoingCorrectSlopeDirection = false;
      }
    }
    else if (dVar25 < 0.0) goto LAB_100378ac8;
  }
  if ((bVar10) || (dVar30 < ABS(dVar25))) {
    if ((this->m_isOnIce & 1U) == 0) {
      dVar15 = 0.15000000596046448;
      if (this->m_isMoving == false) {
        dVar15 = 1.0;
      }
    }
    else {
      dVar15 = 0.15000000596046448;
    }
    dVar25 = dVar25 + dVar15 * -(dVar24 * dVar25) * dVar31;
    this->m_platformerXVelocity = dVar25;
    if ((ABS(dVar25) < 0.009999999776482582) ||
       ((this->m_isPlatformer == true &&
        (((0.0 < dVar32 && (dVar25 < 0.0)) || ((dVar32 < 0.0 && (0.0 < dVar25)))))))) {
      this->m_platformerXVelocity = 0.0;
LAB_100378b48:
      this->m_maybeHasStopped = false;
      this->m_affectedByForces = false;
      this->m_maybeGoingCorrectSlopeDirection = false;
      this->m_isMoving = false;
    }
  }
  else if (this->m_isPlatformer == true) {
    if (((ABS(dVar25) < 0.009999999776482582) || (dVar25 < 0.0 && 0.0 < dVar32)) ||
       ((dVar32 < 0.0 && (0.0 < dVar25)))) goto LAB_100378b48;
  }
  if (this->m_maybeHasStopped == true) {
    if ((this->m_isOnIce & 1U) == 0) {
      dVar15 = 0.15000000596046448;
      if (this->m_isMoving == false) {
        dVar15 = 1.0;
      }
    }
    else {
      dVar15 = 0.15000000596046448;
    }
    fVar22 = (float)((double)this->m_xVelocityRelated +
                    dVar15 * -(dVar24 * (double)this->m_xVelocityRelated) * dVar31);
    this->m_xVelocityRelated = fVar22;
    if (ABS(fVar22) < 1.0) {
      this->m_maybeHasStopped = false;
    }
  }
  if (this->m_isDashing == true) {
    this->m_platformerXVelocity = dVar30;
  }
  else {
    bVar10 = this->m_isGoingLeft;
    if (((bVar19 & 1) == 0) || (bVar10 != false)) {
      if (((bVar18 & 1) != 0) && (bVar10 != false)) {
        uVar12 = 0;
        goto LAB_100378c80;
      }
    }
    else {
      uVar12 = 1;
LAB_100378c80:
      PlayerObject__doReversePlayer(this,uVar12);
    }
    if (bVar10 != this->m_isGoingLeft) {
      PlayerObject__exitPlatformerAnimateJump(this);
      if (((this->m_isShip & 1U) == 0) && ((this->m_isBird & 1U) == 0)) {
        if (((((this->m_isDart & 1U) == 0) && ((this->m_isSwing & 1U) == 0)) &&
            ((this->m_isBall & 1U) == 0)) &&
           ((((this->m_isRobot & 1U) == 0 && ((this->m_isSpider & 1U) == 0)) &&
            ((this->m_isRotating & 1U) == 0)))) {
          fVar22 = (float)virtual_0x160(this);
          if (this->m_isOnSlope == true) {
            fVar22 = (float)((double)fVar22 + this->m_slopeRotation * -57.295780181884766);
          }
          fVar22 = ABS(fVar22);
          if (((45.0 < fVar22) && (fVar22 < 135.0)) || ((225.0 < fVar22 && (fVar22 < 315.0)))) {
            fVar22 = (float)virtual_0x160(this);
            fVar22 = fVar22 + 180.0;
            goto LAB_100378cc0;
          }
        }
      }
      else {
        fVar22 = (float)virtual_0x160(this);
        fVar22 = -fVar22;
LAB_100378cc0:
        virtual_0x158(fVar22,this);
      }
    }
  }
  if ((((((this->m_isShip & 1U) == 0) && ((this->m_isBird & 1U) == 0)) &&
       ((this->m_isDart & 1U) == 0)) &&
      (((this->m_isSwing & 1U) == 0 && ((this->m_isBall & 1U) == 0)))) &&
     (((this->m_isRobot & 1U) == 0 && ((this->m_isSpider & 1U) == 0)))) {
    bVar13 = 0;
    if (((this->m_platformerXVelocity == 0.0) || ((this->m_isRotating & 1U) != 0)) ||
       (((bVar20 ^ 1) & 1) != 0)) goto LAB_100378d0c;
    if (ABS(this->m_yVelocity) <= 1.0) {
      bVar13 = 0;
      goto LAB_100378d0c;
    }
    PlayerObject__runRotateAction(this,0);
    PlayerObject__exitPlatformerAnimateJump(this);
  }
  else {
    bVar13 = 1;
LAB_100378d0c:
    if (((((this->m_isOnSlope & 1U) == 0) && (((bVar13 | bVar20 | this->m_wasOnSlope) & 1) == 0)) &&
        ((this->m_isOnGround2 & 1U) == 0)) &&
       (((this->m_isRotating & 1U) == 0 &&
        (fVar22 = (float)virtual_0x160(this),
        0x2d82d82 < ((int)fVar22 * -0x5b05b05b + 0x2d82d82U >> 1 | (int)fVar22 * -0x80000000))))) {
      fVar22 = 0.0;
      if (((((this->m_isShip & 1U) == 0) &&
           (((this->m_isBird & 1U) == 0 && ((this->m_isDart & 1U) == 0)))) &&
          ((this->m_isSwing & 1U) == 0)) &&
         ((((this->m_isRobot & 1U) == 0 && ((this->m_isSpider & 1U) == 0)) &&
          ((this->m_isDashing & 1U) == 0)))) {
        fVar22 = (float)virtual_0x160(this);
        uVar14 = (uint)fVar22;
        if ((int)uVar14 < 0) {
          fVar23 = (float)(int)-(-uVar14 % 0x168);
          if (-uVar14 % 0x168 == 0) goto LAB_100378fb8;
          fVar22 = 0.0;
          do {
            fVar26 = fVar22;
            fVar22 = fVar26 + -90.0;
          } while (fVar23 < fVar22);
        }
        else {
          fVar23 = (float)(uVar14 % 0x168);
          if (uVar14 % 0x168 == 0) {
LAB_100378fb8:
            fVar22 = 0.0;
            fVar26 = 0.0;
          }
          else {
            fVar22 = 0.0;
            do {
              fVar26 = fVar22;
              fVar22 = fVar26 + 90.0;
            } while (fVar22 < fVar23);
          }
        }
        if (ABS(fVar23 - fVar26) <= ABS(fVar23 - fVar22)) {
          fVar22 = fVar26;
        }
      }
      PlayerObject__updateRotation(this,dt,fVar22);
    }
  }
  if ((bVar6) || ((this->m_isOnGround2 & 1U) == 0)) {
    this->m_lastMovedTime = (float)this->m_totalTime;
  }
  else if ((double)this->m_playerSpeedAC < this->m_totalTime - (double)this->m_lastMovedTime) {
    iVar11 = _rand();
    this->m_playerSpeedAC = ((float)iVar11 / 2.1474836e+09) * 10.0 + 5.0;
    this->m_lastMovedTime = (float)this->m_totalTime;
    if (this->m_isRobot == true) {
      cStack_139 = '\x06';
      uStack_150 = 0x656c6469;
      uStack_14c = 0x3230;
      uStack_14a = 0;
      CCAnimatedSprite__runAnimation(*(undefined8 *)this->m_robotSprite,&uStack_150);
      if (cStack_139 < '\0') {
        uVar12 = CONCAT17(uStack_149,CONCAT16(uStack_14a,CONCAT24(uStack_14c,uStack_150)));
LAB_100379158:
        __ZdlPv(uVar12);
      }
    }
    else if (this->m_isSpider == true) {
      cStack_151 = '\x06';
      uStack_168 = 0x656c6469;
      uStack_164 = 0x3230;
      uStack_162 = 0;
      CCAnimatedSprite__runAnimation(*(undefined8 *)this->m_spiderSprite,&uStack_168);
      if (cStack_151 < '\0') {
        uVar12 = CONCAT17(uStack_161,CONCAT16(uStack_162,CONCAT24(uStack_164,uStack_168)));
        goto LAB_100379158;
      }
    }
  }
  if (((this->m_isBall != true) || ((this->m_isBallRotating2 & 1U) != 0)) ||
     ((this->m_isDashing & 1U) != 0)) goto LAB_100379278;
  bVar10 = this->m_isSideways;
  dVar30 = this->m_platformerXVelocity;
  if (this->m_isOnIce == true) {
    if (((dVar30 < 0.0) && (fVar22 = this->m_xVelocityRelated2, (0.0 < fVar22 & bVar19) != 0)) ||
       (fVar22 = this->m_xVelocityRelated2, ((fVar22 < 0.0 && 0.0 < dVar30) & bVar18) != 0)) {
LAB_1003790e8:
      fVar23 = 0.2;
      if (fVar22 <= 0.0) goto LAB_1003791a4;
LAB_1003790fc:
      if (((double)fVar22 < dVar30 & bVar18) == 0) goto LAB_1003791a4;
LAB_1003791c4:
      fVar23 = 0.3;
    }
    else {
      bVar6 = false;
      if ((dVar30 < (double)fVar22) && (bVar6 = false, !NAN(fVar22))) {
        bVar6 = fVar22 < 0.0;
      }
      bVar7 = false;
      bVar8 = true;
      bVar9 = false;
      if ((double)fVar22 < dVar30) {
        bVar7 = false;
        bVar8 = false;
        bVar9 = true;
        if (!NAN(fVar22)) {
          bVar7 = fVar22 < 0.0;
          bVar8 = fVar22 == 0.0;
          bVar9 = false;
        }
      }
      if ((!bVar8 && bVar7 == bVar9) || (bVar6)) goto LAB_1003790e8;
      fVar23 = 0.1;
      if (0.0 < fVar22) goto LAB_1003790fc;
LAB_1003791a4:
      if ((fVar22 < 0.0) && ((dVar30 < (double)fVar22 & bVar19) == 1)) goto LAB_1003791c4;
    }
    if ((bVar19 & 1) != 0) {
LAB_1003791d4:
      fVar22 = fVar22 - fVar23 * dt;
      goto LAB_1003791e4;
    }
    if ((bVar18 & 1) != 0) {
LAB_1003791e0:
      fVar22 = fVar22 + fVar23 * dt;
      goto LAB_1003791e4;
    }
    if (((this->m_platformerMovingLeft & 1U) != 0) || (dVar30 < (double)fVar22)) goto LAB_1003791d4;
    if (((this->m_platformerMovingRight & 1U) != 0) || ((double)fVar22 < dVar30))
    goto LAB_1003791e0;
    if (0.0 < fVar22) {
      fVar23 = fVar23 * dt * 0.5;
      if (fVar22 <= fVar23) {
        fVar23 = fVar22;
      }
      fVar22 = fVar22 - fVar23;
LAB_1003791e4:
      this->m_xVelocityRelated2 = fVar22;
    }
    else if (fVar22 < 0.0) {
      fVar23 = fVar23 * dt * 0.5;
      if (-fVar22 <= fVar23) {
        fVar23 = -fVar22;
      }
      fVar22 = fVar22 + fVar23;
      goto LAB_1003791e4;
    }
    fVar22 = (float)cocos2d__clampf(fVar22,0xc0a00000,0x40a00000);
    this->m_xVelocityRelated2 = fVar22;
  }
  else {
    fVar22 = (float)dVar30;
  }
  fVar23 = -(fVar22 * dt);
  if (this->m_isUpsideDown == false) {
    fVar23 = fVar22 * dt;
  }
  fVar22 = -fVar23;
  if (bVar10 == false) {
    fVar22 = fVar23;
  }
  fVar22 = fVar22 * 2.8;
  if (this->m_isOnSlope == true) {
    fVar23 = (float)_cosf((float)this->m_slopeRotation);
    fVar22 = fVar22 / fVar23;
  }
  fVar23 = (float)virtual_0x160(this);
  virtual_0x158(fVar22 + fVar23,this);
LAB_100379278:
  if ((this->m_isOnIce & 1U) == 0) {
    this->m_xVelocityRelated2 = (float)this->m_platformerXVelocity;
  }
  return;
}


// ==== PlayerObject::flipGravity @ 0x37b40c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PlayerObject__flipGravity(PlayerObject *this,bool flip,bool noEffects)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  long lVar5;
  ulong uVar6;
  undefined8 uVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  float fVar10;
  float fVar11;
  undefined1 auStack_38 [8];
  
  if (this->m_isUpsideDown == flip) {
    return;
  }
  if (((((this->m_maybeReducedEffects & 1U) == 0) && (this->m_isDart == true)) &&
      ((this->m_isLocked & 1U) == 0)) && (this->m_fadeOutStreak == true)) {
    if (this->m_playEffects == true) {
      lVar5 = GameManager__sharedState();
      uVar6 = GJBaseGameLayer__isFlipping(*(undefined8 *)(lVar5 + 0x1f8));
      if ((uVar6 & 1) != 0) goto LAB_10037b4a8;
    }
    uVar9 = *(undefined8 *)this->m_waveTrail;
    uVar7 = getPosition/*virtual+0xc0*/(this);
    CCPoint__CCPoint_copy(auStack_38,uVar7);
    HardStreak__addPoint(uVar9,auStack_38);
  }
LAB_10037b4a8:
  this->m_justPlacedStreak = false;
  this->m_isUpsideDown = flip;
  if (*(long *)this->m_gameLayer != 0) {
    uVar8 = 10;
    if (!flip) {
      uVar8 = 0xb;
    }
    GJBaseGameLayer__gameEventTriggered(*(long *)this->m_gameLayer,uVar8,0,(this->GameObject).m_uniqueID);
  }
  this->m_lastFlipTime = this->m_totalTime;
  this->m_unkA29 = false;
  this->m_collidedBottomMaxY = 0.0;
  this->m_collidedTopMinY = 0.0;
  if (((this->m_wasOnSlope & 1U) != 0) || (this->m_isOnSlope == true)) {
    this->m_slopeFlipGravityRelated = (bool)(this->m_slopeFlipGravityRelated ^ 1);
  }
  CCDictionary__removeAllObjects(*(undefined8 *)this->m_collisionLogTop);
  CCDictionary__removeAllObjects(*(undefined8 *)this->m_collisionLogBottom);
  CCDictionary__removeAllObjects(*(undefined8 *)this->m_collisionLogLeft);
  CCDictionary__removeAllObjects(*(undefined8 *)this->m_collisionLogRight);
  this->m_unk50C = -1;
  this->m_unk510 = -1;
  this->m_lastCollisionLeft = -1;
  this->m_lastCollisionRight = -1;
  this->m_lastCollisionBottom = -1;
  this->m_lastCollisionTop = -1;
  if (((this->m_maybeReducedEffects & 1U) == 0) &&
     (this->m_yVelocity = this->m_yVelocity * 0.5, !noEffects)) {
    uVar7 = 0xc8ff;
    if (!flip) {
      uVar7 = 0xff9600;
    }
    PlayerObject__spawnPortalCircle(0x42340000,this,uVar7);
  }
  GJActionManager__stopInternalAction(*(undefined8 *)this->m_actionManager,6);
  virtual_0x80(this->m_vehicleSize,this);
  virtual_0x90(this->m_vehicleSize,this);
  PlayerObject__updatePlayerArt(this);
  if (((((this->m_isBall & 1U) == 0) &&
       (lVar5 = GameManager__sharedState(), *(long *)(lVar5 + 0x1f8) != 0)) &&
      (lVar5 = GameManager__sharedState(), (*(byte *)(*(long *)(lVar5 + 0x1f8) + 0x3099) & 1) == 0)) &&
     (((this->m_isDart & 1U) == 0 && ((this->m_maybeReducedEffects & 1U) == 0)))) {
    this->m_shouldTryPlacingCheckpoint = true;
    PlayerObject__activateStreak(this);
  }
  CCPoint__operator_assign(&this->m_lastGroundedPos,&this->m_lastPortalPos);
  this->m_isOnGround = false;
  if (this->m_isBall == true) {
    this->m_isRotating = false;
    this->m_isBallRotating2 = false;
    this->m_isBallRotating = false;
    this->m_rotationSpeed = 0.0;
    if ((this->m_isDashing & 1U) == 0) {
      fVar10 = 1.0;
      if (this->m_vehicleSize != 1.0) {
        fVar10 = 0.8;
      }
      fVar11 = this->m_playerSpeed;
      fVar4 = 1.0;
      if (fVar11 == 1.6) {
        fVar4 = 0.5409375;
      }
      fVar3 = 0.6657693;
      if (fVar11 != 1.3) {
        fVar3 = fVar4;
      }
      fVar4 = 0.80424345;
      if (fVar11 != 1.1) {
        fVar4 = fVar3;
      }
      fVar3 = 1.2405638;
      if (fVar11 != 0.7) {
        fVar3 = fVar4;
      }
      iVar1 = -0x154;
      if (this->m_isUpsideDown != false) {
        iVar1 = 0x154;
      }
      iVar2 = -iVar1;
      if (this->m_isGoingLeft == false) {
        iVar2 = iVar1;
      }
      this->m_rotationSpeed = (this->m_gravityMod * (float)iVar2) / (fVar10 * 0.8 * fVar3);
      this->m_isBallRotating2 = true;
    }
  }
  else if (this->m_isSwing == true) {
    PlayerObject__updateSwingFire(this);
  }
  return;
}


// ==== GameObject::slopeYPos @ 0x4f8cb8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

double GameObject__slopeYPos(GameObject *this,float x)

{
  undefined8 uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  undefined1 auStack_50 [8];
  float fStack_48;
  float fStack_44;
  
  uVar1 = getObjectRect/*virtual+0x520*/();
  CCRect__CCRect_copy(auStack_50,uVar1);
  fVar2 = (float)CCRect__getMinX(auStack_50);
  fVar3 = (float)CCRect__getMaxX(auStack_50);
  fVar4 = (float)CCRect__getMinY(auStack_50);
  fVar5 = (float)CCRect__getMaxY(auStack_50);
  dVar7 = (double)(fStack_44 / fStack_48);
  dVar9 = (double)x - (double)fVar3;
  dVar6 = (double)fVar5 + dVar7 * dVar9;
  if (this->m_slopeUphill == false) {
    dVar6 = (double)fVar4 - dVar7 * dVar9;
  }
  dVar8 = (double)fVar2 - (double)x;
  dVar9 = (double)fVar4 - dVar7 * dVar8;
  if (this->m_slopeUphill == false) {
    dVar9 = (double)fVar5 + dVar7 * dVar8;
  }
  if (x <= fVar2) {
    dVar6 = dVar9;
  }
  if (this->m_slopeIsHazard == true) {
    if (((uint)this->m_slopeDirection < 7) &&
       ((1 << (ulong)(this->m_slopeDirection & 0x1f) & 0x6aU) != 0)) {
      dVar7 = -4.0;
    }
    else {
      dVar7 = 4.0;
    }
    dVar6 = dVar6 + dVar7;
  }
  return dVar6;
}


// ==== GameObject::slopeYPos @ 0x4f8c48

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

double GameObject__slopeYPos(GameObject *this,CCRect rect)

{
  undefined8 uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  undefined1 auStack_50 [8];
  float fStack_48;
  float fStack_44;
  
  if ((uint)this->m_slopeDirection < 7 && (1 << (ulong)(this->m_slopeDirection & 0x1f) & 0x6aU) != 0
     ) {
    if ((this->m_slopeUphill & 1U) == 0) {
LAB_1004f8ca0:
      fVar2 = (float)CCRect__getMinX(rect.origin.x,rect.origin.y,rect.width,rect.height);
      goto GameObject__slopeYPos;
    }
  }
  else if ((this->m_slopeUphill & 1U) != 0) goto LAB_1004f8ca0;
  fVar2 = (float)CCRect__getMaxX();
GameObject__slopeYPos:
  uVar1 = getObjectRect/*virtual+0x520*/();
  CCRect__CCRect_copy(auStack_50,uVar1);
  fVar3 = (float)CCRect__getMinX(auStack_50);
  fVar4 = (float)CCRect__getMaxX(auStack_50);
  fVar5 = (float)CCRect__getMinY(auStack_50);
  fVar6 = (float)CCRect__getMaxY(auStack_50);
  dVar8 = (double)(fStack_44 / fStack_48);
  dVar10 = (double)fVar2 - (double)fVar4;
  dVar7 = (double)fVar6 + dVar8 * dVar10;
  if (this->m_slopeUphill == false) {
    dVar7 = (double)fVar5 - dVar8 * dVar10;
  }
  dVar9 = (double)fVar3 - (double)fVar2;
  dVar10 = (double)fVar5 - dVar8 * dVar9;
  if (this->m_slopeUphill == false) {
    dVar10 = (double)fVar6 + dVar8 * dVar9;
  }
  if (fVar2 <= fVar3) {
    dVar7 = dVar10;
  }
  if (this->m_slopeIsHazard == true) {
    if (((uint)this->m_slopeDirection < 7) &&
       ((1 << (ulong)(this->m_slopeDirection & 0x1f) & 0x6aU) != 0)) {
      dVar8 = -4.0;
    }
    else {
      dVar8 = 4.0;
    }
    dVar7 = dVar7 + dVar8;
  }
  return dVar7;
}


// ==== GameObject::slopeYPos @ 0x4f8ba8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

double GameObject__slopeYPos(GameObject *this,GameObject *object)

{
  undefined8 uVar1;
  float fVar2;
  double dVar3;
  undefined1 auStack_30 [16];
  
  uVar1 = getObjectRect/*virtual+0x520*/(object);
  CCRect__CCRect_copy(auStack_30,uVar1);
  if ((uint)this->m_slopeDirection < 7 && (1 << (ulong)(this->m_slopeDirection & 0x1f) & 0x6aU) != 0
     ) {
    if ((this->m_slopeUphill & 1U) == 0) {
LAB_1004f8c28:
      fVar2 = (float)CCRect__getMinX(auStack_30);
      dVar3 = GameObject__slopeYPos(this,fVar2);
      return dVar3;
    }
  }
  else if ((this->m_slopeUphill & 1U) != 0) goto LAB_1004f8c28;
  fVar2 = (float)CCRect__getMaxX(auStack_30);
  dVar3 = GameObject__slopeYPos(this,fVar2);
  return dVar3;
}


// ==== GameObject::slopeFloorTop @ 0x4f8b8c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

bool GameObject__slopeFloorTop(GameObject *this)

{
  return (bool)((uint)this->m_slopeDirection < 7 &
               (byte)(0x6a >> (ulong)(this->m_slopeDirection & 0x1f)));
}


// ==== GameObject::slopeWallLeft @ 0x4f8b70

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

bool GameObject__slopeWallLeft(GameObject *this)

{
  return (bool)((uint)this->m_slopeDirection < 7 &
               (byte)(0x5c >> (ulong)(this->m_slopeDirection & 0x1f)));
}


// ==== GameObject::determineSlopeDirection @ 0x4ef52c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void GameObject__determineSlopeDirection(GameObject *this)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  float fVar10;
  
  uVar7 = virtual_0x580();
  uVar8 = virtual_0x588(this);
  fVar10 = (float)virtual_0x618(this);
  iVar4 = (int)fVar10 % 0x168;
  this->m_slopeUphill = false;
  uVar2 = uVar8;
  if (iVar4 != 0) {
    uVar2 = 1;
  }
  if (((uVar7 & 1) != 0) || (iVar9 = 0, uVar2 != 0)) {
    fVar10 = ABS((float)iVar4);
    uVar3 = uVar7 ^ 1;
    uVar5 = uVar3 | uVar8 ^ 1;
    if (((uVar5 & 1) == 0) && (fVar10 == 180.0)) {
      iVar9 = 0;
    }
    else {
      uVar1 = 0;
      if (iVar4 == 0) {
        uVar1 = uVar8;
      }
      if (((uVar3 & uVar1 & 1) != 0) ||
         ((uVar6 = uVar3 | uVar8, (uVar6 & 1) == 0 && (fVar10 == 180.0)))) {
        iVar9 = 1;
        goto LAB_1004ef5e4;
      }
      if ((((uVar3 | uVar2) & 1) == 0) ||
         ((uVar2 = uVar7 | uVar8 ^ 1, (uVar2 & 1) == 0 && (fVar10 == 180.0)))) {
        iVar9 = 2;
        goto LAB_1004ef5e4;
      }
      if (((uVar7 & uVar1 & 1) == 0) &&
         ((uVar7 = uVar7 | uVar8, (uVar7 & 1) != 0 || (fVar10 != 180.0)))) {
        if ((((((uVar7 & 1) == 0) && ((iVar9 = 4, iVar4 == -0x10e || (iVar4 == 0x5a)))) ||
             (((uVar5 & 1) == 0 && ((iVar9 = 4, iVar4 == -0x5a || (iVar4 == 0x10e)))))) ||
            (((uVar7 & 1) == 0 && ((iVar9 = 5, iVar4 == -0x5a || (iVar4 == 0x10e)))))) ||
           (((uVar5 & 1) == 0 && ((iVar9 = 5, iVar4 == -0x10e || (iVar4 == 0x5a))))))
        goto LAB_1004ef5e4;
        if (((uVar6 & 1) != 0) || ((iVar9 = 6, iVar4 != -0x10e && (iVar4 != 0x5a)))) {
          if ((uVar2 & 1) == 0) {
            iVar9 = 6;
            if (iVar4 < 0x5a) {
              if (iVar4 != -0x10e) {
                if (iVar4 == -0x5a) goto LAB_1004ef5dc;
                goto LAB_1004ef6f4;
              }
            }
            else if (iVar4 != 0x5a) {
              if (iVar4 == 0x10e) goto LAB_1004ef5dc;
              goto LAB_1004ef6f4;
            }
          }
          else {
LAB_1004ef6f4:
            if ((uVar6 & 1) != 0) {
              return;
            }
            if ((iVar4 != 0x10e) && (iVar4 != -0x5a)) {
              return;
            }
          }
          iVar9 = 7;
        }
      }
      else {
        iVar9 = 3;
      }
    }
  }
LAB_1004ef5dc:
  this->m_slopeUphill = true;
LAB_1004ef5e4:
  this->m_slopeDirection = iVar9;
  return;
}


// ==== GameObject::getSlopeAngle @ 0x4ef748

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float GameObject__getSlopeAngle(GameObject *this)

{
  undefined8 uVar1;
  float fVar2;
  undefined1 auStack_20 [8];
  float fStack_18;
  float fStack_14;
  
  uVar1 = getObjectRect/*virtual+0x520*/();
  CCRect__CCRect_copy(auStack_20,uVar1);
                    /* WARNING: Could not recover jumptable at 0x0001006d1ec4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  fVar2 = (float)(*(code *)PTR__atanf_1008b06d0)(fStack_14 / fStack_18);
  return fVar2;
}


// ==== GJBaseGameLayer::collisionCheckObjects @ 0xff074

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void GJBaseGameLayer__collisionCheckObjects
               (GJBaseGameLayer *this,PlayerObject *object,undefined *objects,int objectCount,
               float dt)

{
  undefined8 *puVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  ulong uVar5;
  undefined8 uVar6;
  long lVar7;
  undefined8 uVar8;
  ulong uVar9;
  byte bVar10;
  ulong uVar11;
  undefined8 *puVar12;
  long lVar13;
  undefined8 *puVar14;
  GameObject *object_00;
  long lVar15;
  long lVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  undefined1 auVar23 [16];
  long lStack_c8;
  long lStack_c0;
  undefined8 uStack_b8;
  undefined1 auStack_b0 [16];
  
  uVar4 = getObjectRect/*virtual+0x520*/(object);
  fVar17 = (float)CCRect__getMaxX();
  fVar18 = (float)CCRect__getMinX(uVar4);
  fVar19 = (float)CCRect__getMaxY(uVar4);
  fVar20 = (float)CCRect__getMinY(uVar4);
  if (0 < objectCount) {
    lVar16 = 0;
    do {
      object_00 = *(GameObject **)(*(long *)objects + lVar16);
      iVar2 = object_00->m_objectType;
      if (((iVar2 == 7) || ((object_00->m_isGroupDisabled & 1U) != 0)) ||
         ((object_00->m_isDisabled & 1U) != 0)) goto LAB_1000ff12c;
      if (0x14 < iVar2) {
        if (iVar2 == 0x15) goto LAB_1000ff254;
        if (iVar2 != 0x27) {
          if (iVar2 == 0x2f) goto LAB_1000ff17c;
          goto LAB_1000ff1a4;
        }
        goto LAB_1000ff12c;
      }
      if (iVar2 == 0) {
LAB_1000ff254:
        iVar2 = *(int *)(this + 0x300);
        iVar3 = *(int *)&this[0x2ff].field_0xc;
        if (iVar3 < iVar2) {
          *(GameObject **)(*(long *)&this[0x300].field_0x8 + (long)iVar3 * 8) = object_00;
        }
        else {
          puVar12 = *(undefined8 **)(this + 0x301);
          if (puVar12 < *(undefined8 **)&this[0x301].field_0x8) {
            puVar14 = puVar12 + 1;
            *puVar12 = object_00;
          }
          else {
            lVar15 = *(long *)&this[0x300].field_0x8;
            lVar13 = (long)puVar12 - lVar15 >> 3;
            uVar5 = lVar13 + 1;
            if (uVar5 >> 0x3d != 0) {
LAB_100100078:
              func_0x00010004922c();
LAB_10010007c:
              uVar4 = func_0x000100049050();
              if (lStack_c8 != 0) {
                lStack_c0 = lStack_c8;
                __ZdlPv();
              }
              auVar23 = __Unwind_Resume(uVar4);
              if ((*(int *)(auVar23._0_8_ + 0x33c) != 0) && (*(int *)(auVar23._8_8_ + 0x4e0) == 1))
              {
                return;
              }
              return;
            }
            uVar9 = (long)*(undefined8 **)&this[0x301].field_0x8 - lVar15;
            uVar11 = (long)uVar9 >> 2;
            if (uVar11 <= uVar5) {
              uVar11 = uVar5;
            }
            if (0x7ffffffffffffff7 < uVar9) {
              uVar11 = 0x1fffffffffffffff;
            }
            if (uVar11 == 0) {
              lVar7 = 0;
            }
            else {
              if (uVar11 >> 0x3d != 0) goto LAB_10010007c;
              lVar7 = __Znwm(uVar11 << 3);
            }
            puVar1 = (undefined8 *)(lVar7 + lVar13 * 8);
            puVar14 = puVar1 + 1;
            *puVar1 = object_00;
            _memcpy(lVar7,lVar15,(long)puVar12 - lVar15);
            *(long *)&this[0x300].field_0x8 = lVar7;
            *(undefined8 **)(this + 0x301) = puVar14;
            *(ulong *)&this[0x301].field_0x8 = lVar7 + uVar11 * 8;
            if (lVar15 != 0) {
              __ZdlPv(lVar15);
              iVar2 = *(int *)(this + 0x300);
              iVar3 = *(int *)&this[0x2ff].field_0xc;
            }
          }
          *(undefined8 **)(this + 0x301) = puVar14;
          *(int *)(this + 0x300) = iVar2 + 1;
        }
        *(int *)&this[0x2ff].field_0xc = iVar3 + 1;
        goto LAB_1000ff12c;
      }
      if (iVar2 == 2) {
LAB_1000ff17c:
        iVar2 = *(int *)&this[0x302].field_0x4;
        iVar3 = *(int *)(this + 0x302);
        if (iVar3 < iVar2) {
          *(GameObject **)(*(long *)&this[0x302].field_0x8 + (long)iVar3 * 8) = object_00;
        }
        else {
          puVar12 = *(undefined8 **)(this + 0x303);
          if (puVar12 < *(undefined8 **)&this[0x303].field_0x8) {
            puVar14 = puVar12 + 1;
            *puVar12 = object_00;
          }
          else {
            lVar15 = *(long *)&this[0x302].field_0x8;
            lVar13 = (long)puVar12 - lVar15 >> 3;
            uVar5 = lVar13 + 1;
            if (uVar5 >> 0x3d != 0) goto LAB_100100078;
            uVar9 = (long)*(undefined8 **)&this[0x303].field_0x8 - lVar15;
            uVar11 = (long)uVar9 >> 2;
            if (uVar11 <= uVar5) {
              uVar11 = uVar5;
            }
            if (0x7ffffffffffffff7 < uVar9) {
              uVar11 = 0x1fffffffffffffff;
            }
            if (uVar11 == 0) {
              lVar7 = 0;
            }
            else {
              if (uVar11 >> 0x3d != 0) goto LAB_10010007c;
              lVar7 = __Znwm(uVar11 << 3);
            }
            puVar1 = (undefined8 *)(lVar7 + lVar13 * 8);
            puVar14 = puVar1 + 1;
            *puVar1 = object_00;
            _memcpy(lVar7,lVar15,(long)puVar12 - lVar15);
            *(long *)&this[0x302].field_0x8 = lVar7;
            *(undefined8 **)(this + 0x303) = puVar14;
            *(ulong *)&this[0x303].field_0x8 = lVar7 + uVar11 * 8;
            if (lVar15 != 0) {
              __ZdlPv(lVar15);
              iVar2 = *(int *)&this[0x302].field_0x4;
              iVar3 = *(int *)(this + 0x302);
            }
          }
          *(undefined8 **)(this + 0x303) = puVar14;
          *(int *)&this[0x302].field_0x4 = iVar2 + 1;
        }
        *(int *)(this + 0x302) = iVar3 + 1;
        goto LAB_1000ff12c;
      }
LAB_1000ff1a4:
      uVar5 = virtual_0x5f8(object_00,object);
      if ((uVar5 & 1) != 0) goto LAB_1000ff12c;
      CCRect__CCRect_zero(auStack_b0);
      iVar2 = virtual_0x6f8(object_00);
      if (iVar2 == 0x19) {
        virtual_0x528(&lStack_c8,0x40000000,0x40000000,object_00);
        uVar6 = CCRect__operator_assign(auStack_b0,&lStack_c8);
        if (object_00->m_objectRadius <= 0.0) goto LAB_1000ff210;
LAB_1000ff384:
        if (*(char *)(*(long *)(this + 0xcb) + 0x1c7) != '\x01') {
          iVar2 = GJBaseGameLayer__objectIntersectsCircle(uVar6,object,object_00);
          if (iVar2 != 0) goto LAB_1000ff4d8;
          goto LAB_1000ff12c;
        }
        uVar6 = getPosition/*virtual+0xc0*/(object);
        getRealPosition/*virtual+0x540*/(&lStack_c8,object_00);
        fVar21 = (float)cocos2d__ccpDistance(uVar6,&lStack_c8);
        fVar22 = (float)GameObject__getObjectRadius(object_00);
        lVar13 = getObjectRect/*virtual+0x520*/(object);
        if (fVar22 + *(float *)(lVar13 + 8) * 0.5 < fVar21) goto LAB_1000ff12c;
      }
      else {
        uVar6 = getObjectRect/*virtual+0x520*/(object_00);
        uVar6 = CCRect__operator_assign(auStack_b0,uVar6);
        if (0.0 < object_00->m_objectRadius) goto LAB_1000ff384;
LAB_1000ff210:
        fVar21 = (float)CCRect__getMinX(auStack_b0);
        if (((fVar17 < fVar21) || (fVar21 = (float)CCRect__getMaxX(auStack_b0), fVar21 < fVar18)
            ) || ((fVar21 = (float)CCRect__getMinY(auStack_b0), fVar19 < fVar21 ||
                  (fVar21 = (float)CCRect__getMaxY(auStack_b0), fVar21 < fVar20))))
        goto LAB_1000ff12c;
      }
LAB_1000ff4d8:
      if ((object_00->m_shouldUseOuterOb != true) ||
         ((*(char *)(*(long *)(this + 0xcb) + 0x1c7) == '\x01' && (0.0 < object_00->m_objectRadius))
         )) {
        iVar2 = 1;
        iVar3 = virtual_0x6f8(object_00);
      }
      else {
        uVar6 = virtual_0x608(object_00);
        virtual_0x610(object);
        uVar8 = virtual_0x608(object);
        iVar2 = OBB2D__overlaps1Way(uVar6,uVar8);
        if (iVar2 == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = OBB2D__overlaps1Way(uVar8,uVar6);
        }
        iVar3 = virtual_0x6f8(object_00);
      }
      if (iVar3 == 0x19) {
        uVar6 = getObjectRect/*virtual+0x520*/(object_00);
        CCRect__operator_assign(auStack_b0,uVar6);
      }
      if ((iVar2 == 0) ||
         ((((*(int *)&this[0x33].field_0xc != 0 && (object_00->m_classType == 1)) &&
           (*(int *)&object_00[1].field_0x1a8 != 0)) &&
          (*(int *)&object_00[1].field_0x1a8 != *(int *)&this[0x33].field_0xc))))
      goto LAB_1000ff12c;
      switch(object_00->m_objectType) {
      case 3:
        iVar2 = GJBaseGameLayer__canBeActivatedByPlayer(this,object,object_00);
        if (iVar2 != 0) {
          if (((object->m_isUpsideDown & 1U) == 0) && ((object_00->m_hasNoEffects & 1U) == 0)) {
            (**(code **)(*(long *)this + 0x590))(this,1);
          }
          uVar6 = getPosition/*virtual+0xc0*/(object_00);
          CCPoint__CCPoint_copy(&lStack_c8,uVar6);
          CCPoint__operator_assign(&object->m_lastPortalPos,&lStack_c8);
          *(GameObject **)object->m_lastActivatedPortal = object_00;
          if ((object_00->m_hasNoEffects & 1U) == 0) {
            bVar10 = object_00->m_isHide;
          }
          else {
            bVar10 = 1;
          }
          GJBaseGameLayer__flipGravity(this,object,1,bVar10 & 1);
          GameObject__playShineEffect(object_00);
          virtual_0x5f0(object_00,object);
          uVar6 = 0x32;
code_r0x000100100038:
          GJBaseGameLayer__gameEventTriggered(this,uVar6,0,0);
        }
        break;
      case 4:
        iVar2 = GJBaseGameLayer__canBeActivatedByPlayer(this,object,object_00);
        if (iVar2 != 0) {
          if ((object->m_isUpsideDown == true) && ((object_00->m_hasNoEffects & 1U) == 0)) {
            (**(code **)(*(long *)this + 0x590))(this,0);
          }
          uVar6 = getPosition/*virtual+0xc0*/(object_00);
          CCPoint__CCPoint_copy(&lStack_c8,uVar6);
          CCPoint__operator_assign(&object->m_lastPortalPos,&lStack_c8);
          *(GameObject **)object->m_lastActivatedPortal = object_00;
          if ((object_00->m_hasNoEffects & 1U) == 0) {
            bVar10 = object_00->m_isHide;
          }
          else {
            bVar10 = 1;
          }
          GJBaseGameLayer__flipGravity(this,object,0,bVar10 & 1);
          GameObject__playShineEffect(object_00);
          virtual_0x5f0(object_00,object);
          uVar6 = 0x33;
          goto code_r0x000100100038;
        }
        break;
      case 5:
        iVar2 = GJBaseGameLayer__canBeActivatedByPlayer(this,object,object_00);
        if (iVar2 != 0) {
          GJBaseGameLayer__playerWillSwitchMode(this,object,object_00);
          uVar6 = 5;
code_r0x0001000ffde0:
          GJBaseGameLayer__switchToFlyMode(this,object,object_00,0,uVar6);
code_r0x0001000ffe4c:
          GameObject__playShineEffect(object_00);
          virtual_0x5f0(object_00,object);
        }
        break;
      case 6:
        iVar2 = GJBaseGameLayer__canBeActivatedByPlayer(this,object,object_00);
        if (iVar2 != 0) {
          GJBaseGameLayer__playerWillSwitchMode(this,object,object_00);
          uVar6 = getPosition/*virtual+0xc0*/(object_00);
          CCPoint__CCPoint_copy(&lStack_c8,uVar6);
          CCPoint__operator_assign(&object->m_lastPortalPos,&lStack_c8);
          *(GameObject **)object->m_lastActivatedPortal = object_00;
          PlayerObject__switchedToMode(object,6);
          PlayerObject__modeDidChange(object);
          goto code_r0x0001000ffe4c;
        }
        break;
      case 8:
      case 9:
      case 0x22:
      case 0x2c:
        GJBaseGameLayer__bumpPlayer(this,object,object_00);
        break;
      case 10:
        GJBaseGameLayer__gravBumpPlayer(this,object,object_00);
        break;
      case 0xb:
      case 0xc:
      case 0xd:
      case 0x1d:
      case 0x20:
      case 0x23:
      case 0x24:
      case 0x25:
      case 0x26:
      case 0x2b:
        GJBaseGameLayer__playerTouchedRing(this,object,object_00);
        break;
      case 0xe:
        if (((this[0x2f3].field_0x4 & 1) == 0) &&
           (iVar2 = GJBaseGameLayer__canBeActivatedByPlayer(this,object,object_00), iVar2 != 0)) {
          uVar6 = getPosition/*virtual+0xc0*/(object_00);
          CCPoint__CCPoint_copy(&lStack_c8,uVar6);
          CCPoint__operator_assign(&object->m_lastPortalPos,&lStack_c8);
          *(GameObject **)object->m_lastActivatedPortal = object_00;
          GJBaseGameLayer__toggleFlipped(this,1,object_00->m_hasNoEffects);
          GameObject__playShineEffect(object_00);
          virtual_0x5c0(0,object_00);
          uVar6 = 0x35;
          goto code_r0x000100100038;
        }
        break;
      case 0xf:
        if (((this[0x2f3].field_0x4 & 1) == 0) &&
           (iVar2 = GJBaseGameLayer__canBeActivatedByPlayer(this,object,object_00), iVar2 != 0)) {
          uVar6 = getPosition/*virtual+0xc0*/(object_00);
          CCPoint__CCPoint_copy(&lStack_c8,uVar6);
          CCPoint__operator_assign(&object->m_lastPortalPos,&lStack_c8);
          *(GameObject **)object->m_lastActivatedPortal = object_00;
          GJBaseGameLayer__toggleFlipped(this,0,object_00->m_hasNoEffects);
          GameObject__playShineEffect(object_00);
          virtual_0x5c0(0,object_00);
          uVar6 = 0x36;
          goto code_r0x000100100038;
        }
        break;
      case 0x10:
        iVar2 = GJBaseGameLayer__canBeActivatedByPlayer(this,object,object_00);
        if (iVar2 != 0) {
          GJBaseGameLayer__playerWillSwitchMode(this,object,object_00);
          GJBaseGameLayer__switchToRollMode(this,object,object_00,0);
          goto code_r0x0001000ffe4c;
        }
        break;
      case 0x11:
        iVar2 = GJBaseGameLayer__canBeActivatedByPlayer(this,object,object_00);
        if (iVar2 != 0) {
          uVar6 = getPosition/*virtual+0xc0*/(object_00);
          CCPoint__CCPoint_copy(&lStack_c8,uVar6);
          CCPoint__operator_assign(&object->m_lastPortalPos,&lStack_c8);
          *(GameObject **)object->m_lastActivatedPortal = object_00;
          PlayerObject__togglePlayerScale(object,0,object_00->m_hasNoEffects);
          GameObject__playShineEffect(object_00);
          virtual_0x5f0(object_00,object);
          uVar6 = 0x37;
          goto code_r0x000100100038;
        }
        break;
      case 0x12:
        iVar2 = GJBaseGameLayer__canBeActivatedByPlayer(this,object,object_00);
        if (iVar2 != 0) {
          uVar6 = getPosition/*virtual+0xc0*/(object_00);
          CCPoint__CCPoint_copy(&lStack_c8,uVar6);
          CCPoint__operator_assign(&object->m_lastPortalPos,&lStack_c8);
          *(GameObject **)object->m_lastActivatedPortal = object_00;
          PlayerObject__togglePlayerScale(object,1,object_00->m_hasNoEffects);
          GameObject__playShineEffect(object_00);
          virtual_0x5f0(object_00,object);
          uVar6 = 0x38;
          goto code_r0x000100100038;
        }
        break;
      case 0x13:
        iVar2 = GJBaseGameLayer__canBeActivatedByPlayer(this,object,object_00);
        if (iVar2 != 0) {
          GJBaseGameLayer__playerWillSwitchMode(this,object,object_00);
          uVar6 = 0x13;
          goto code_r0x0001000ffde0;
        }
        break;
      case 0x14:
      case 0x2d:
        GJBaseGameLayer__playerTouchedTrigger(this,object,object_00);
        break;
      case 0x16:
        if ((this[0x305].field_0x8 & 1) == 0) {
          virtual_0x500(object_00,this,(object->GameObject).m_uniqueID,0)
          ;
          virtual_0x5c0(0,object_00);
          GJBaseGameLayer__destroyObject(this,object_00);
          uVar5 = GJBaseGameLayer__hasUniqueCoin(this,object_00);
          if ((uVar5 & 1) == 0) {
            GJBaseGameLayer__pickupItem(this,object_00);
          }
          uVar6 = 0x3e;
          goto code_r0x000100100038;
        }
        break;
      case 0x17:
        iVar2 = GJBaseGameLayer__canBeActivatedByPlayer(this,object,object_00);
        if (iVar2 != 0) {
          uVar6 = getPosition/*virtual+0xc0*/(object_00);
          CCPoint__CCPoint_copy(&lStack_c8,uVar6);
          CCPoint__operator_assign(&object->m_lastPortalPos,&lStack_c8);
          *(GameObject **)object->m_lastActivatedPortal = object_00;
          *(undefined1 *)(*(long *)&this[0xca].field_0x8 + 0xa40) = 1;
          GJBaseGameLayer__toggleDualMode(this,object_00,1,object,0);
          *(undefined1 *)(*(long *)&this[0xca].field_0x8 + 0xa40) = 0;
          GameObject__playShineEffect(object_00);
          virtual_0x5c0(0,object_00);
          uVar6 = 0x39;
          goto code_r0x000100100038;
        }
        break;
      case 0x18:
        iVar2 = GJBaseGameLayer__canBeActivatedByPlayer(this,object,object_00);
        if (iVar2 != 0) {
          uVar6 = getPosition/*virtual+0xc0*/(object_00);
          CCPoint__CCPoint_copy(&lStack_c8,uVar6);
          CCPoint__operator_assign(&object->m_lastPortalPos,&lStack_c8);
          *(GameObject **)object->m_lastActivatedPortal = object_00;
          GJBaseGameLayer__toggleDualMode(this,object_00,0,object,0);
          GameObject__playShineEffect(object_00);
          virtual_0x5c0(0,object_00);
          uVar6 = 0x3a;
          goto code_r0x000100100038;
        }
        break;
      case 0x19:
        PlayerObject__collidedWithSlope(object,dt,object_00,false);
        goto code_r0x0001000ffe80;
      case 0x1a:
        if (((this[0x2f3].field_0x6 & 1) == 0) &&
           (iVar2 = GJBaseGameLayer__canBeActivatedByPlayer(this,object,object_00), iVar2 != 0)) {
          GJBaseGameLayer__playerWillSwitchMode(this,object,object_00);
          uVar6 = 0x1a;
          goto code_r0x0001000ffde0;
        }
        break;
      case 0x1b:
        iVar2 = GJBaseGameLayer__canBeActivatedByPlayer(this,object,object_00);
        if (iVar2 != 0) {
          GJBaseGameLayer__playerWillSwitchMode(this,object,object_00);
          GJBaseGameLayer__switchToRobotMode(this,object,object_00,0);
          goto code_r0x0001000ffe4c;
        }
        break;
      case 0x1c:
        iVar2 = GJBaseGameLayer__canBeActivatedByPlayer(this,object,object_00);
        if (iVar2 != 0) {
          GJBaseGameLayer__gameEventTriggered(this,0x3b,0,0);
          GJBaseGameLayer__teleportPlayer(this,object_00,object);
          goto code_r0x0001000ffe80;
        }
        break;
      case 0x1e:
        uVar5 = GJEffectManager__hasBeenTriggered(*(undefined8 *)(this + 0x85),object_00->m_uniqueID,0);
        if ((uVar5 & 1) == 0) {
          GJEffectManager__storeTriggeredID(*(undefined8 *)(this + 0x85),object_00->m_uniqueID,0);
          if (object_00->m_objectID == 0x4f4) {
            lStack_c8 = 0;
            lStack_c0 = 0;
            uStack_b8 = 0;
            SpawnTriggerGameObject__updateRemapKeys(object_00,&lStack_c8);
            if (lStack_c8 != 0) {
              lStack_c0 = lStack_c8;
              __ZdlPv();
            }
          }
          virtual_0x500(object_00,this,(object->GameObject).m_uniqueID,0)
          ;
          uVar6 = 0x3f;
code_r0x0001000fff48:
          GJBaseGameLayer__gameEventTriggered(this,uVar6,0,0);
        }
code_r0x0001000fff54:
        virtual_0x5c0(0,object_00);
        GJBaseGameLayer__destroyObject(this,object_00);
        break;
      case 0x1f:
        if ((this[0x305].field_0x8 & 1) == 0) {
          uVar5 = GJEffectManager__hasBeenTriggered(*(undefined8 *)(this + 0x85),object_00->m_uniqueID,0);
          if ((uVar5 & 1) == 0) {
            GJEffectManager__storeTriggeredID(*(undefined8 *)(this + 0x85),object_00->m_uniqueID,0);
            virtual_0x500
                      (object_00,this,(object->GameObject).m_uniqueID,0);
            uVar5 = GJBaseGameLayer__hasUniqueCoin(this,object_00);
            if ((uVar5 & 1) == 0) {
              GJBaseGameLayer__pickupItem(this,object_00);
            }
            uVar6 = 0x3e;
            goto code_r0x0001000fff48;
          }
          goto code_r0x0001000fff54;
        }
        break;
      case 0x21:
        iVar2 = GJBaseGameLayer__canBeActivatedByPlayer(this,object,object_00);
        if (iVar2 != 0) {
          GJBaseGameLayer__playerWillSwitchMode(this,object,object_00);
          GJBaseGameLayer__switchToSpiderMode(this,object,object_00,0);
          goto code_r0x0001000ffe4c;
        }
        break;
      case 0x28:
        PlayerObject__touchedObject(object,object_00);
        break;
      case 0x29:
        if (((this[0x2f3].field_0x6 & 1) == 0) &&
           (iVar2 = GJBaseGameLayer__canBeActivatedByPlayer(this,object,object_00), iVar2 != 0)) {
          GJBaseGameLayer__playerWillSwitchMode(this,object,object_00);
          uVar6 = 0x29;
          goto code_r0x0001000ffde0;
        }
        break;
      case 0x2a:
        iVar2 = GJBaseGameLayer__canBeActivatedByPlayer(this,object,object_00);
        if (iVar2 != 0) {
          if ((object_00->m_hasNoEffects & 1U) == 0) {
            (**(code **)(*(long *)this + 0x590))(this,(object->m_isUpsideDown ^ 0xffU) & 1);
          }
          uVar6 = getPosition/*virtual+0xc0*/(object_00);
          CCPoint__CCPoint_copy(&lStack_c8,uVar6);
          CCPoint__operator_assign(&object->m_lastPortalPos,&lStack_c8);
          *(GameObject **)object->m_lastActivatedPortal = object_00;
          if ((object_00->m_hasNoEffects & 1U) == 0) {
            bVar10 = object_00->m_isHide;
          }
          else {
            bVar10 = 1;
          }
          GJBaseGameLayer__flipGravity(this,object,(object->m_isUpsideDown ^ 1U) & 1,bVar10 & 1);
          GameObject__playShineEffect(object_00);
          virtual_0x5f0(object_00,object);
          uVar6 = 0x34;
          goto code_r0x000100100038;
        }
        break;
      case 0x2e:
        GJBaseGameLayer__playerTouchedRing(this,object,object_00);
code_r0x0001000ffe80:
        uVar6 = getObjectRect/*virtual+0x520*/(object);
        CCRect__operator_assign(uVar4,uVar6);
        fVar17 = (float)CCRect__getMaxX(uVar4);
        fVar18 = (float)CCRect__getMinX(uVar4);
        fVar19 = (float)CCRect__getMaxY(uVar4);
        fVar20 = (float)CCRect__getMinY(uVar4);
      }
LAB_1000ff12c:
      lVar16 = lVar16 + 8;
    } while ((ulong)(uint)objectCount << 3 != lVar16);
  }
  return;
}


// ==== GJBaseGameLayer::checkCollisions @ 0xfe188

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int GJBaseGameLayer__checkCollisions
              (GJBaseGameLayer *this,PlayerObject *object,float dt,bool ignoreDamage)

{
  undefined1 *puVar1;
  uint uVar2;
  long lVar3;
  bool bVar4;
  byte bVar5;
  bool bVar6;
  bool bVar7;
  byte bVar8;
  int iVar9;
  int iVar10;
  float *pfVar11;
  long lVar12;
  ulong uVar13;
  undefined4 *puVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  long *plVar17;
  code *pcVar18;
  uint uVar19;
  ulong uVar20;
  int iVar21;
  ulong uVar22;
  long *plVar23;
  long lVar24;
  long lVar25;
  uint uVar26;
  ulong uVar27;
  char cVar28;
  ulong uVar29;
  ulong uVar30;
  ulong uVar31;
  float fVar32;
  float fVar33;
  double dVar34;
  float fVar35;
  float fVar36;
  double dVar37;
  float fVar38;
  float fVar39;
  undefined *puStack_a8;
  
  puVar1 = &this[0x2f3].field_0x6;
  bVar4 = object->m_wasTeleported;
  object->m_wasTeleported = false;
  PlayerObject__preCollision(object);
  bVar8 = 0;
  fVar36 = object->m_unkAngle1 * (1.0 - object->m_vehicleSize) * 0.5;
  if (object->m_vehicleSize == 1.0) {
    fVar36 = 0.0;
  }
  fVar38 = object->m_unkAngle1 * 0.5;
  if ((this[0x31].field_0x1 & 1) == 0) {
    uVar13 = PlayerObject__isFlying(object);
    if (((uVar13 & 1) != 0) || ((object->m_isBall & 1U) != 0)) {
      bVar8 = 1;
      cVar28 = object->m_isOutOfBounds;
      object->m_isOutOfBounds = false;
      bVar5 = *puVar1;
      goto joined_r0x0001000fe6a4;
    }
    if ((object->m_isSpider & 1U) != 0) {
      bVar8 = 1;
      cVar28 = object->m_isOutOfBounds;
      object->m_isOutOfBounds = false;
      bVar5 = *puVar1;
      goto joined_r0x0001000fe6a4;
    }
    bVar8 = this[0x3f].field_0x2;
    cVar28 = object->m_isOutOfBounds;
    object->m_isOutOfBounds = false;
    if ((*puVar1 & 1) != 0) goto LAB_1000fe238;
LAB_1000fe2c0:
    if ((object->m_isGoingLeft != true) ||
       (pfVar11 = (float *)getPosition/*virtual+0xc0*/(object),
       -30.0 <= *pfVar11)) goto LAB_1000fe2f4;
    bVar7 = true;
  }
  else {
    cVar28 = object->m_isOutOfBounds;
    object->m_isOutOfBounds = false;
    bVar5 = *puVar1;
joined_r0x0001000fe6a4:
    if ((bVar5 & 1) == 0) goto LAB_1000fe2c0;
LAB_1000fe238:
    pfVar11 = (float *)getPosition/*virtual+0xc0*/(object);
    if (*pfVar11 < -30.0) {
      object->m_platformerXVelocity = 0.0;
      lVar12 = getPosition/*virtual+0xc0*/(object);
      CCPoint__CCPoint(0xc1f00000,*(undefined4 *)(lVar12 + 4),&puStack_a8);
      setPosition/*virtual+0xb8*/(object,&puStack_a8);
    }
LAB_1000fe2f4:
    bVar7 = false;
  }
  fVar32 = (fVar38 + 90.0) - fVar36;
  lVar12 = getPosition/*virtual+0xc0*/(object);
  if ((fVar32 <= *(float *)(lVar12 + 4)) ||
     (((bVar8 & 1) != 0 &&
      ((((uVar13 = PlayerObject__isFlying(object), (uVar13 & 1) != 0 || ((object->m_isBall & 1U) != 0))
        || ((this[0x3f].field_0x2 & 1) != 0)) || ((object->m_isSpider & 1U) != 0)))))) {
    lVar12 = getPosition/*virtual+0xc0*/(object);
    if (fVar36 + *(float *)(this + 0x349) < *(float *)(lVar12 + 4)) goto LAB_1000fe360;
  }
  else if (object->m_isUpsideDown == true) {
    iVar9 = PlayerObject__isSafeFlip(0x3dcccccd,object);
    if (iVar9 != 0) {
      puVar14 = (undefined4 *)getPosition/*virtual+0xc0*/(object);
      CCPoint__CCPoint(*puVar14,fVar32,&puStack_a8);
      setPosition/*virtual+0xb8*/(object,&puStack_a8);
      PlayerObject__hitGround(object,(GameObject *)0x0,true);
      PlayerObject__updateCollide(object,0,0);
      object->m_isOnGround2 = false;
      return 0;
    }
LAB_1000fe360:
    bVar7 = true;
  }
  else if ((object->m_maybeIsBoosted & 1U) == 0) {
    puVar14 = (undefined4 *)getPosition/*virtual+0xc0*/(object);
    CCPoint__CCPoint(*puVar14,fVar32,&puStack_a8);
    setPosition/*virtual+0xb8*/(object,&puStack_a8);
    PlayerObject__hitGround(object,(GameObject *)0x0,false);
    PlayerObject__updateCollide(object,1,0);
  }
  bVar6 = bVar7;
  if (((bVar8 & 1) == 0) || ((bVar4 & 1U) != 0)) goto LAB_1000fe91c;
  if ((*(float *)&this[0x23].field_0xc == 0.0) || ((*(byte *)(this + 0x2a) & 1) != 0)) {
    fVar32 = *(float *)&this[0x1a].field_0x8;
    fVar35 = *(float *)&this[0x1b].field_0x4 +
             *(float *)&this[0x30].field_0x8 + (*(float *)&this[0x2e].field_0xc * -0.5) / fVar32;
    if (fVar35 <= 90.0) {
      fVar35 = 90.0;
    }
    fVar35 = *(float *)&this[0x2e].field_0xc / fVar32 + fVar35;
    if (*(float *)&this[0x23].field_0xc != 0.0) goto LAB_1000fe480;
LAB_1000fe488:
    fVar32 = *(float *)&this[0x1b].field_0x4 +
             *(float *)&this[0x30].field_0x8 + (*(float *)&this[0x2e].field_0xc * -0.5) / fVar32;
    if (fVar32 <= 90.0) {
      fVar32 = 90.0;
    }
  }
  else {
    fVar35 = *(float *)&this[0x4b].field_0x8;
    lVar12 = (**(code **)(**(long **)&this[0xee].field_0x8 + 0xc0))();
    fVar32 = *(float *)&this[0x1a].field_0x8;
    fVar35 = fVar35 + (*(float *)(lVar12 + 4) + 1.0) / fVar32;
    if (*(float *)&this[0x23].field_0xc == 0.0) goto LAB_1000fe488;
LAB_1000fe480:
    if ((*(byte *)(this + 0x2a) & 1) != 0) goto LAB_1000fe488;
    fVar39 = *(float *)&this[0x4b].field_0x8;
    lVar12 = (**(code **)(**(long **)(this + 0xee) + 0xc0))();
    fVar32 = 90.0;
    if (90.0 < fVar39 + (*(float *)(lVar12 + 4) + -1.0) / *(float *)&this[0x1a].field_0x8) {
      fVar32 = *(float *)&this[0x4b].field_0x8;
      lVar12 = (**(code **)(**(long **)(this + 0xee) + 0xc0))();
      fVar32 = fVar32 + (*(float *)(lVar12 + 4) + -1.0) / *(float *)&this[0x1a].field_0x8;
    }
  }
  if (object->m_isShip == true) {
    bVar8 = object->m_jumpBuffered;
  }
  else {
    bVar8 = 0;
  }
  fVar39 = fVar35 - *(float *)&this[0x6b].field_0xc;
  fVar35 = fVar36 + (fVar35 - fVar38);
  lVar12 = getPosition/*virtual+0xc0*/(object);
  if (*(float *)(lVar12 + 4) <= fVar35) {
    fVar36 = (fVar38 + fVar32) - fVar36;
    lVar12 = getPosition/*virtual+0xc0*/(object);
    if (fVar36 <= *(float *)(lVar12 + 4)) goto LAB_1000fe91c;
    if ((object->m_wasOnSlope == true) &&
       (lVar12 = getPosition/*virtual+0xc0*/(object),
       *(float *)(lVar12 + 4) < fVar36 - fVar38)) goto LAB_1000fe5b8;
    iVar9 = PlayerObject__destroyFromHitHead(object);
    if (iVar9 == 0) {
      bVar6 = false;
LAB_1000fe7c0:
      dVar34 = (double)PlayerObject__getYVelocity(object);
      if ((object->m_isUpsideDown & 1U) != 0) goto LAB_1000fe7d4;
LAB_1000fe7f8:
      iVar10 = PlayerObject__canStickToGround(object);
      iVar9 = 0;
      if (fVar39 != 0.0) {
        iVar9 = iVar10;
      }
    }
    else {
      if (object->m_isUpsideDown == true) {
        iVar9 = PlayerObject__isSafeHeadTest(object);
        bVar6 = true;
        if (iVar9 == 0) goto LAB_1000fe91c;
        goto LAB_1000fe7c0;
      }
      bVar6 = false;
      dVar34 = (double)PlayerObject__getYVelocity(object);
      if ((object->m_isUpsideDown & 1U) == 0) goto LAB_1000fe7f8;
LAB_1000fe7d4:
      iVar9 = 0;
    }
    fVar38 = 0.0;
    if (((bVar6 == false) && (uVar13 = PlayerObject__canStickToGround(object), (uVar13 & 1) == 0)) &&
       (*(float *)&this[0x1a].field_0x8 != *(float *)&this[0x1a].field_0xc)) {
      fVar38 = 1.0;
    }
    puVar14 = (undefined4 *)getPosition/*virtual+0xc0*/(object);
    CCPoint__CCPoint(*puVar14,fVar36 + fVar38,&puStack_a8);
    setPosition/*virtual+0xb8*/(object,&puStack_a8);
    if (bVar6) {
      PlayerObject__pushDown(object);
    }
    else if ((((object->m_isShip & 1U) == 0) && (object->m_isSwing != true)) ||
            (dVar37 = (double)PlayerObject__getYVelocity(object), dVar37 < 0.0)) {
      PlayerObject__hitGround(object,(GameObject *)0x0,object->m_isUpsideDown);
    }
    fVar36 = (float)dVar34;
    PlayerObject__updateCollide(object,object->m_isUpsideDown ^ 1,0);
    if (iVar9 == 0) {
LAB_1000fe8e8:
      if (((object->m_isUpsideDown & bVar8 & 1) != 0) && (fVar39 < 0.0)) goto LAB_1000fe900;
    }
    else {
      dVar37 = (double)fVar36;
      dVar34 = (double)PlayerObject__getYVelocity(object);
      if (dVar34 <= dVar37) goto LAB_1000fe8e8;
LAB_1000fe904:
      PlayerObject__setYVelocity(dVar37,object,0);
    }
  }
  else {
    if ((object->m_wasOnSlope == true) &&
       (lVar12 = getPosition/*virtual+0xc0*/(object),
       fVar38 + fVar35 < *(float *)(lVar12 + 4))) {
LAB_1000fe5b8:
      bVar6 = true;
      goto LAB_1000fe91c;
    }
    iVar9 = PlayerObject__destroyFromHitHead(object);
    if ((iVar9 == 0) || ((object->m_isUpsideDown & 1U) != 0)) {
      bVar6 = false;
    }
    else {
      iVar9 = PlayerObject__isSafeHeadTest(object);
      bVar6 = true;
      if (iVar9 == 0) goto LAB_1000fe91c;
    }
    dVar34 = (double)PlayerObject__getYVelocity(object);
    if (object->m_isUpsideDown == true) {
      iVar10 = PlayerObject__canStickToGround(object);
      iVar9 = 0;
      if (fVar39 != 0.0) {
        iVar9 = iVar10;
      }
    }
    else {
      iVar9 = 0;
    }
    puVar14 = (undefined4 *)getPosition/*virtual+0xc0*/(object);
    CCPoint__CCPoint(*puVar14,fVar35,&puStack_a8);
    setPosition/*virtual+0xb8*/(object,&puStack_a8);
    if (bVar6) {
      PlayerObject__pushDown();
    }
    else {
      dVar37 = (double)PlayerObject__getYVelocity(object);
      if (0.0 < dVar37) {
        PlayerObject__hitGround
                  (object,(GameObject *)0x0,(bool)((object->m_isUpsideDown ^ 0xffU) & 1));
      }
    }
    fVar36 = (float)dVar34;
    PlayerObject__updateCollide(object,object->m_isUpsideDown,0);
    if (iVar9 != 0) {
      dVar37 = (double)fVar36;
      dVar34 = (double)PlayerObject__getYVelocity(object);
      if (dVar34 < dVar37) goto LAB_1000fe904;
    }
    if (((bVar8 & (object->m_isUpsideDown ^ 0xffU) & 1) != 0) && (0.0 < fVar39)) {
LAB_1000fe900:
      dVar37 = (double)fVar36;
      goto LAB_1000fe904;
    }
  }
  object->m_wasOnSlope = false;
  bVar6 = bVar7;
LAB_1000fe91c:
  if ((bVar6) && (cVar28 != '\0')) {
    if (ignoreDamage) {
LAB_1000fe928:
      iVar9 = 1;
    }
    else {
      pcVar18 = *(code **)(*(long *)this + 0x4f8);
      plVar17 = (long *)0x0;
LAB_1000fe9b0:
      (*pcVar18)(this,object,plVar17);
      iVar9 = 1;
    }
  }
  else {
    object->m_isOutOfBounds = bVar6;
    pfVar11 = (float *)getPosition/*virtual+0xc0*/(object);
    fVar38 = 0.0;
    fVar36 = 0.0;
    if (0.0 < *pfVar11) {
      pfVar11 = (float *)getPosition/*virtual+0xc0*/(object);
      fVar32 = 1e+07;
      if (1e+07 <= *pfVar11) {
        fVar36 = *(float *)&this[0x348].field_0x8;
      }
      else {
        pfVar11 = (float *)getPosition/*virtual+0xc0*/(object);
        fVar36 = *pfVar11;
        fVar32 = *(float *)&this[0x348].field_0x8;
      }
      fVar36 = fVar36 * fVar32;
    }
    uVar26 = (uint)fVar36;
    lVar12 = getPosition/*virtual+0xc0*/(object);
    if (0.0 < *(float *)(lVar12 + 4)) {
      lVar12 = getPosition/*virtual+0xc0*/(object);
      fVar36 = 1e+07;
      if (1e+07 <= *(float *)(lVar12 + 4)) {
        fVar38 = *(float *)&this[0x348].field_0xc;
      }
      else {
        lVar12 = getPosition/*virtual+0xc0*/(object);
        fVar38 = *(float *)(lVar12 + 4);
        fVar36 = *(float *)&this[0x348].field_0xc;
      }
      fVar38 = fVar38 * fVar36;
    }
    uVar19 = (uint)fVar38;
    uVar2 = uVar26;
    if ((int)uVar26 < 2) {
      uVar2 = 1;
    }
    lVar24 = *(long *)(this + 0x33a);
    lVar25 = *(long *)&this[0x339].field_0x8;
    lVar12 = lVar24 - lVar25 >> 3;
    iVar9 = (int)lVar12 + -1;
    if ((ulong)(long)(int)(uVar26 + 1) <= lVar12 - 1U) {
      iVar9 = uVar26 + 1;
    }
    uVar26 = uVar19;
    if ((int)uVar19 < 2) {
      uVar26 = 1;
    }
    *(undefined4 *)&this[0x2ff].field_0xc = 0;
    *(undefined4 *)(this + 0x302) = 0;
    if ((lVar24 != lVar25) && ((int)(uVar2 - 1) <= iVar9)) {
      uVar13 = (ulong)uVar2 - 1;
      do {
        plVar17 = *(long **)(*(long *)&this[0x339].field_0x8 + uVar13 * 8);
        if (plVar17 != (long *)0x0) {
          lVar12 = plVar17[1] - *plVar17 >> 3;
          iVar10 = (int)lVar12 + -1;
          if ((ulong)(long)(int)(uVar19 + 1) <= lVar12 - 1U) {
            iVar10 = uVar19 + 1;
          }
          if ((int)(uVar26 - 1) <= iVar10) {
            uVar31 = (ulong)uVar26 - 1;
            do {
              plVar17 = *(long **)(**(long **)(*(long *)&this[0x339].field_0x8 + uVar13 * 8) +
                                  uVar31 * 8);
              if (plVar17 != (long *)0x0) {
                uVar2 = *(uint *)(**(long **)(*(long *)(this + 0x344) + uVar13 * 8) + uVar31 * 4);
                uVar29 = (ulong)(int)uVar2;
                uVar27 = uVar31 >> 6;
                uVar30 = 1L << (uVar31 & 0x3f);
                if ((*(ulong *)(**(long **)(*(long *)(this + 0x347) + uVar13 * 8) + uVar27 * 8) &
                    uVar30) != 0) {
                  puStack_a8 = &DAT_1000e9bdc;
                  lVar12 = 0;
                  if (uVar2 != 0) {
                    lVar12 = LZCOUNT(uVar29) * -2 + 0x7e;
                  }
                  func_0x0001000e3dbc(*plVar17,*plVar17 + uVar29 * 8,&puStack_a8,lVar12,1);
                  if (0 < (int)uVar2) {
                    lVar12 = *plVar17;
                    if (uVar2 < 4) {
                      uVar20 = 0;
                    }
                    else {
                      uVar22 = 0;
                      uVar20 = uVar29 & 0x7ffffffc;
                      plVar23 = (long *)(lVar12 + 0x10);
                      do {
                        iVar21 = (int)uVar22;
                        lVar25 = plVar23[-1];
                        lVar24 = *plVar23;
                        lVar3 = plVar23[1];
                        *(int *)(plVar23[-2] + 0x270) = iVar21;
                        *(int *)(lVar25 + 0x270) = iVar21 + 1;
                        *(int *)(lVar24 + 0x270) = iVar21 + 2;
                        *(int *)(lVar3 + 0x270) = iVar21 + 3;
                        uVar22 = uVar22 + 4;
                        plVar23 = plVar23 + 4;
                      } while (uVar20 != uVar22);
                      if (uVar20 == uVar29) goto LAB_1000feb24;
                    }
                    do {
                      *(int *)(*(long *)(lVar12 + uVar20 * 8) + 0x270) = (int)uVar20;
                      uVar20 = uVar20 + 1;
                    } while (uVar29 != uVar20);
                  }
LAB_1000feb24:
                  lVar12 = **(long **)(*(long *)(this + 0x347) + uVar13 * 8);
                  *(ulong *)(lVar12 + uVar27 * 8) =
                       *(ulong *)(lVar12 + uVar27 * 8) & (uVar30 ^ 0xffffffffffffffff);
                }
                GJBaseGameLayer__collisionCheckObjects(this,object,(undefined *)plVar17,uVar2,dt);
              }
              uVar31 = uVar31 + 1;
            } while (uVar31 != iVar10 + 1);
          }
        }
        uVar13 = uVar13 + 1;
      } while (uVar13 != iVar9 + 1);
    }
    if (0 < *(int *)(this + 0x33e)) {
      GJBaseGameLayer__collisionCheckObjects
                (this,object,&this[0x33c].field_0x8,*(int *)(this + 0x33e),dt);
    }
    if (*(long *)object->m_lastGroundObject == 0) {
      bVar8 = 0;
    }
    else {
      bVar8 = object->m_isCollidingWithSlope;
    }
    uVar15 = getObjectRect/*virtual+0x520*/(object);
    fVar36 = (float)CCRect__getMaxX();
    fVar38 = (float)CCRect__getMinX(uVar15);
    fVar32 = (float)CCRect__getMaxY(uVar15);
    fVar35 = (float)CCRect__getMinY(uVar15);
    iVar9 = *(int *)&this[0x2ff].field_0xc;
    if (0 < iVar9) {
      iVar10 = 0;
      iVar21 = -1;
      do {
        lVar12 = *(long *)(*(long *)&this[0x300].field_0x8 + (long)(iVar9 + iVar21) * 8);
        uVar13 = GameObject__getGroupDisabled(lVar12);
        if ((uVar13 & 1) == 0) {
          uVar16 = GameObject__getObjectRectPointer(lVar12);
          if ((bVar8 & 1) == 0) {
            bVar8 = 0;
            fVar39 = (float)CCRect__getMinX(uVar16);
          }
          else if (*(short *)(lVar12 + 0x490) < 1) {
            bVar8 = 1;
            fVar39 = (float)CCRect__getMinX(uVar16);
          }
          else {
            bVar8 = PlayerObject__testForMoving(dt,object,lVar12);
            bVar8 = bVar8 ^ 1;
            fVar39 = (float)CCRect__getMinX(uVar16);
          }
          if ((((fVar39 <= fVar36) &&
               (fVar39 = (float)CCRect__getMaxX(uVar16), fVar38 <= fVar39)) &&
              (fVar39 = (float)CCRect__getMinY(uVar16), fVar39 <= fVar32)) &&
             (fVar39 = (float)CCRect__getMaxY(uVar16), fVar35 <= fVar39)) {
            PlayerObject__collidedWithObject(dt,object,lVar12);
            uVar16 = getObjectRect/*virtual+0x520*/(object);
            CCRect__operator_assign(uVar15,uVar16);
            fVar36 = (float)CCRect__getMaxX(uVar15);
            fVar38 = (float)CCRect__getMinX(uVar15);
            fVar32 = (float)CCRect__getMaxY(uVar15);
            fVar35 = (float)CCRect__getMinY(uVar15);
          }
        }
        iVar10 = iVar10 + 1;
        iVar9 = *(int *)&this[0x2ff].field_0xc;
        iVar21 = iVar21 + -1;
      } while (iVar10 < iVar9);
    }
    if ((*(byte *)(*(long *)(this + 0xca) + 0x970) & 1) != 0) {
      PlayerObject__removePlacedCheckpoint();
    }
    uVar16 = getObjectRect/*virtual+0x520*/(object);
    CCRect__operator_assign(uVar15,uVar16);
    fVar36 = (float)CCRect__getMaxX(uVar15);
    fVar38 = (float)CCRect__getMinX(uVar15);
    fVar32 = (float)CCRect__getMaxY(uVar15);
    fVar35 = (float)CCRect__getMinY(uVar15);
    virtual_0x610(object);
    if (0 < *(int *)(this + 0x302)) {
      lVar12 = 0;
      do {
        plVar17 = *(long **)(*(long *)&this[0x302].field_0x8 + lVar12 * 8);
        uVar13 = GameObject__getGroupDisabled(plVar17);
        if ((uVar13 & 1) == 0) {
          uVar15 = GameObject__getObjectRectPointer(plVar17);
          if (*(float *)((long)plVar17 + 900) <= 0.0) {
            fVar39 = (float)CCRect__getMinX();
            if (((fVar39 <= fVar36) &&
                (fVar39 = (float)CCRect__getMaxX(uVar15), fVar38 <= fVar39)) &&
               ((fVar39 = (float)CCRect__getMinY(uVar15), fVar39 <= fVar32 &&
                (fVar39 = (float)CCRect__getMaxY(uVar15), fVar35 <= fVar39))))
            goto LAB_1000fefa4;
          }
          else if (*(char *)(*(long *)(this + 0xcb) + 0x1c7) == '\x01') {
            uVar15 = getPosition/*virtual+0xc0*/(object);
            (**(code **)(*plVar17 + 0x540))(&puStack_a8,plVar17);
            fVar39 = (float)cocos2d__ccpDistance(uVar15,&puStack_a8);
            fVar33 = (float)GameObject__getObjectRadius(plVar17);
            lVar24 = getObjectRect/*virtual+0x520*/(object);
            if (fVar39 <= fVar33 + *(float *)(lVar24 + 8) * 0.5) {
LAB_1000fefa4:
              if (((char)plVar17[0x5d] == '\x01') &&
                 ((*(char *)(*(long *)(this + 0xcb) + 0x1c7) != '\x01' ||
                  (*(float *)((long)plVar17 + 900) <= 0.0)))) {
                uVar15 = (**(code **)(*plVar17 + 0x608))(plVar17);
                uVar16 = virtual_0x608(object);
                iVar9 = OBB2D__overlaps1Way(uVar15,uVar16);
                if ((iVar9 == 0) || (iVar9 = OBB2D__overlaps1Way(uVar16,uVar15), iVar9 == 0))
                goto LAB_1000fee9c;
              }
              if (ignoreDamage) goto LAB_1000fe928;
              pcVar18 = *(code **)(*(long *)this + 0x4f8);
              goto LAB_1000fe9b0;
            }
          }
          else {
            iVar9 = GJBaseGameLayer__objectIntersectsCircle(uVar15,object,plVar17);
            if (iVar9 != 0) goto LAB_1000fefa4;
          }
        }
LAB_1000fee9c:
        lVar12 = lVar12 + 1;
      } while (lVar12 < *(int *)(this + 0x302));
    }
    PlayerObject__postCollision(object,dt,(bool)this[0x356].field_0x8);
    iVar9 = 0;
  }
  return iVar9;
}



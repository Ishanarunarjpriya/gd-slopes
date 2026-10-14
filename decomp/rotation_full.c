// ==== PlayerObject::runNormalRotation @ 0x377f68

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PlayerObject__runNormalRotation(PlayerObject *this,bool notNormalMode,float speed)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  
  if ((!notNormalMode) &&
     (((((((this->m_isShip & 1U) != 0 || ((this->m_isBird & 1U) != 0)) ||
         ((this->m_isDart & 1U) != 0)) ||
        (((this->m_isSwing & 1U) != 0 || ((this->m_isRobot & 1U) != 0)))) ||
       (((this->m_isSpider & 1U) != 0 || ((this->m_isDashing & 1U) != 0)))) ||
      ((((this->m_isPlatformer == true && ((this->m_holdingLeft & 1U) == 0)) &&
        ((this->m_holdingRight & 1U) == 0)) &&
       (((this->m_platformerMovingLeft & 1U) == 0 && (this->m_platformerMovingRight != true))))))))
  {
    return;
  }
  fVar3 = 0.43333334;
  if (this->m_vehicleSize != 1.0) {
    fVar3 = 0.33333334;
  }
  iVar1 = 0xb4;
  if (this->m_isUpsideDown != false) {
    iVar1 = -0xb4;
  }
  iVar2 = -iVar1;
  if (this->m_isGoingLeft == false) {
    iVar2 = iVar1;
  }
  fVar4 = -(float)iVar2;
  if (this->m_isSideways == false) {
    fVar4 = (float)iVar2;
  }
  this->m_rotationSpeed = (this->m_gravityMod * fVar4 * speed) / fVar3;
  this->m_isRotating = true;
  return;
}


// ==== PlayerObject::runNormalRotation @ 0x37bcb4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PlayerObject__runNormalRotation(PlayerObject *this)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  
  if (((((((this->m_isShip & 1U) == 0) && ((this->m_isBird & 1U) == 0)) &&
        ((this->m_isDart & 1U) == 0)) &&
       (((this->m_isSwing & 1U) == 0 && ((this->m_isRobot & 1U) == 0)))) &&
      (((this->m_isSpider & 1U) == 0 && ((this->m_isDashing & 1U) == 0)))) &&
     ((((this->m_isPlatformer != true || ((this->m_holdingLeft & 1U) != 0)) ||
       ((this->m_holdingRight & 1U) != 0)) ||
      (((this->m_platformerMovingLeft & 1U) != 0 || (this->m_platformerMovingRight == true)))))) {
    fVar3 = 0.43333334;
    if (this->m_vehicleSize != 1.0) {
      fVar3 = 0.33333334;
    }
    iVar1 = 0xb4;
    if (this->m_isUpsideDown != false) {
      iVar1 = -0xb4;
    }
    iVar2 = -iVar1;
    if (this->m_isGoingLeft == false) {
      iVar2 = iVar1;
    }
    fVar4 = -(float)iVar2;
    if (this->m_isSideways == false) {
      fVar4 = (float)iVar2;
    }
    this->m_rotationSpeed = (this->m_gravityMod * fVar4) / fVar3;
    this->m_isRotating = true;
  }
  return;
}


// ==== PlayerObject::runRotateAction @ 0x37a398

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PlayerObject__runRotateAction(PlayerObject *this,bool ground,int type)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  if (((this->m_isLocked & 1U) != 0) || ((this->m_isDashing & 1U) != 0)) {
    return;
  }
  this->m_isRotating = false;
  this->m_isBallRotating2 = false;
  this->m_isBallRotating = false;
  this->m_rotationSpeed = 0.0;
  if ((this->m_isBall & 1U) == 0) {
    if ((this->m_isShip & 1U) != 0) {
      return;
    }
    if ((this->m_isBird & 1U) != 0) {
      return;
    }
    if ((this->m_isDart & 1U) != 0) {
      return;
    }
    if ((this->m_isSwing & 1U) != 0) {
      return;
    }
    if ((this->m_isRobot & 1U) != 0) {
      return;
    }
    if ((this->m_isSpider & 1U) != 0) {
      return;
    }
    if ((((this->m_isPlatformer == true) && ((this->m_holdingLeft & 1U) == 0)) &&
        ((this->m_holdingRight & 1U) == 0)) &&
       (((this->m_platformerMovingLeft & 1U) == 0 && (this->m_platformerMovingRight != true)))) {
      return;
    }
    fVar5 = 0.43333334;
    if (this->m_vehicleSize != 1.0) {
      fVar5 = 0.33333334;
    }
    iVar1 = 0xb4;
    if (this->m_isUpsideDown != false) {
      iVar1 = -0xb4;
    }
    iVar2 = -iVar1;
    if (this->m_isGoingLeft == false) {
      iVar2 = iVar1;
    }
    fVar3 = -(float)iVar2;
    if (this->m_isSideways == false) {
      fVar3 = (float)iVar2;
    }
    fVar5 = (this->m_gravityMod * fVar3) / fVar5;
  }
  else {
    if ((this->m_isPlatformer & 1U) != 0) {
      return;
    }
    this->m_rotateSpeed = 1.0;
    fVar3 = this->m_playerSpeed;
    fVar5 = 1.0;
    if (fVar3 == 1.6) {
      fVar5 = 0.5409375;
    }
    fVar4 = 0.6657693;
    if (fVar3 != 1.3) {
      fVar4 = fVar5;
    }
    fVar5 = 0.80424345;
    if (fVar3 != 1.1) {
      fVar5 = fVar4;
    }
    fVar4 = 1.2405638;
    if (fVar3 != 0.7) {
      fVar4 = fVar5;
    }
    iVar1 = 0x78;
    if (this->m_isUpsideDown != false) {
      iVar1 = -0x78;
    }
    iVar2 = -iVar1;
    if (this->m_isGoingLeft == false) {
      iVar2 = iVar1;
    }
    fVar5 = 0.2;
    if (this->m_vehicleSize != 1.0) {
      fVar5 = 0.16000001;
    }
    fVar5 = (float)iVar2 / (fVar5 * fVar4);
    this->m_rotationSpeed = fVar5;
    if (this->m_isSideways != true) goto LAB_10037a4b8;
    fVar5 = -fVar5;
  }
  this->m_rotationSpeed = fVar5;
LAB_10037a4b8:
  this->m_isRotating = true;
  return;
}


// ==== PlayerObject__updateRotation @ 0x37a590

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


// ==== PlayerObject__updateRotation @ 0x382d40

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
    PlayerObject__updateShipRotation(this,dt);
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
    fVar1 = PlayerObject__convertToClosestRotation(this,0.0);
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


// ==== PlayerObject::convertToClosestRotation @ 0x37a6dc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float PlayerObject__convertToClosestRotation(PlayerObject *this,float rotation)

{
  int iVar1;
  float fVar2;
  uint uVar3;
  float fVar4;
  float fVar5;
  
  fVar4 = rotation;
  if (((((this->m_isShip & 1U) == 0) && ((this->m_isBird & 1U) == 0)) &&
      ((this->m_isDart & 1U) == 0)) &&
     ((((this->m_isSwing & 1U) == 0 && ((this->m_isRobot & 1U) == 0)) &&
      (((this->m_isSpider & 1U) == 0 && ((this->m_isDashing & 1U) == 0)))))) {
    fVar4 = (float)virtual_0x160();
    uVar3 = (uint)fVar4;
    iVar1 = (-uVar3 / 0x168) * 0x168;
    if ((uVar3 & 0x80000000) == 0) {
      iVar1 = (uVar3 / 0x168) * -0x168;
    }
    fVar5 = (float)(int)(uVar3 + iVar1);
    fVar4 = rotation;
    fVar2 = rotation;
    if (rotation <= fVar5) {
      while (fVar4 = fVar2, fVar4 < fVar5) {
        rotation = fVar4;
        fVar2 = fVar4 + 90.0;
      }
    }
    else {
      do {
        rotation = fVar4;
        fVar4 = rotation + -90.0;
      } while (fVar5 < fVar4);
    }
    if (ABS(fVar5 - rotation) <= ABS(fVar5 - fVar4)) {
      fVar4 = rotation;
    }
  }
  return fVar4;
}


// ==== PlayerObject::stopRotation @ 0x37bca4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PlayerObject__stopRotation(PlayerObject *this,bool ground,int type)

{
  this->m_isRotating = false;
  this->m_isBallRotating2 = false;
  this->m_isBallRotating = false;
  this->m_rotationSpeed = 0.0;
  return;
}


// ==== PlayerObject::runBallRotation @ 0x37bd90

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PlayerObject__runBallRotation(PlayerObject *this,float speed)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  if (((this->m_isDashing & 1U) == 0) && ((this->m_isPlatformer & 1U) == 0)) {
    this->m_isBallRotating = speed != 1.0;
    this->m_rotateSpeed = speed;
    fVar3 = this->m_playerSpeed;
    fVar5 = 1.0;
    if (fVar3 == 1.6) {
      fVar5 = 0.5409375;
    }
    fVar4 = 0.6657693;
    if (fVar3 != 1.3) {
      fVar4 = fVar5;
    }
    fVar5 = 0.80424345;
    if (fVar3 != 1.1) {
      fVar5 = fVar4;
    }
    fVar4 = 1.2405638;
    if (fVar3 != 0.7) {
      fVar4 = fVar5;
    }
    iVar1 = 0x78;
    if (this->m_isUpsideDown != false) {
      iVar1 = -0x78;
    }
    iVar2 = -iVar1;
    if (this->m_isGoingLeft == false) {
      iVar2 = iVar1;
    }
    fVar5 = 0.2;
    if (this->m_vehicleSize != 1.0) {
      fVar5 = 0.16000001;
    }
    fVar5 = (float)iVar2 / (fVar5 * fVar4);
    this->m_rotationSpeed = fVar5;
    if (this->m_isSideways == true) {
      this->m_rotationSpeed = -fVar5;
    }
    this->m_isRotating = true;
  }
  return;
}


// ==== PlayerObject::runBallRotation2 @ 0x37bebc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PlayerObject__runBallRotation2(PlayerObject *this)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  if ((this->m_isDashing & 1U) == 0) {
    fVar5 = 1.0;
    if (this->m_vehicleSize != 1.0) {
      fVar5 = 0.8;
    }
    fVar6 = this->m_playerSpeed;
    fVar4 = 1.0;
    if (fVar6 == 1.6) {
      fVar4 = 0.5409375;
    }
    fVar3 = 0.6657693;
    if (fVar6 != 1.3) {
      fVar3 = fVar4;
    }
    fVar4 = 0.80424345;
    if (fVar6 != 1.1) {
      fVar4 = fVar3;
    }
    fVar3 = 1.2405638;
    if (fVar6 != 0.7) {
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
    this->m_rotationSpeed = (this->m_gravityMod * (float)iVar2) / (fVar5 * 0.8 * fVar3);
    this->m_isBallRotating2 = true;
  }
  return;
}


// ==== PlayerObject::updateShipRotation @ 0x382970

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PlayerObject__updateShipRotation(PlayerObject *this,float dt)

{
  bool bVar1;
  undefined8 uVar2;
  byte bVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fStack_38;
  float fStack_34;
  
  if ((this->m_isOnSlope & 1U) != 0) {
    return;
  }
  if ((this->m_isDashing & 1U) != 0) {
    return;
  }
  uVar2 = getPosition/*virtual+0xc0*/(this);
  CCPoint__CCPoint_copy(&fStack_38,uVar2);
  if ((((this->m_isBird & 1U) == 0) && ((this->m_isShip & 1U) == 0)) &&
     ((this->m_isSwing & 1U) == 0)) {
    bVar3 = this->m_isDart;
    if ((this->m_isSideways & 1U) != 0) goto LAB_1003829ec;
LAB_100382a48:
    if (((bVar3 & 1) == 0) || (this->m_isGoingLeft != true)) {
      fStack_38 = fStack_38 - (this->m_shipRotation).x;
    }
    else {
      fStack_38 = ABS(fStack_38 - (this->m_shipRotation).x);
    }
    fVar6 = -(fStack_34 - (this->m_shipRotation).y);
    if (dt * 1.2 <= fVar6 * fVar6 + fStack_38 * fStack_38) goto LAB_100382aac;
  }
  else {
    bVar3 = 1;
    if ((this->m_isSideways & 1U) == 0) goto LAB_100382a48;
LAB_1003829ec:
    if (((bVar3 & 1) == 0) || (this->m_isGoingLeft != true)) {
      fStack_34 = fStack_34 - (this->m_shipRotation).y;
    }
    else {
      fStack_34 = ABS(fStack_34 - (this->m_shipRotation).y);
    }
    fStack_38 = fStack_38 - (this->m_shipRotation).x;
    if (dt * 1.2 <= fStack_38 * fStack_38 + fStack_34 * fStack_34) goto LAB_100382aac;
  }
  if (this->m_isPlatformer != true) {
    return;
  }
  if (((this->m_isShip | this->m_isBird) & 1U) == 0) {
    return;
  }
LAB_100382aac:
  fVar4 = (float)_atan2f();
  fVar5 = (float)virtual_0x160(this);
  bVar1 = this->m_isBird;
  fVar6 = fVar4 * -0.4;
  if (bVar1 == false) {
    fVar6 = fVar4;
  }
  if ((this->m_isCollidingWithSlope == true) &&
     (((((this->m_isShip & 1U) != 0 || ((bVar1 & 1U) != 0)) || ((this->m_isDart & 1U) != 0)) ||
      (fVar6 = fVar4, this->m_isSwing == true)))) {
    fVar6 = 0.0;
  }
  fVar4 = fVar6;
  if (((bVar3 & 1) != 0) && (fVar4 = -fVar6, this->m_isGoingLeft == false)) {
    fVar4 = fVar6;
  }
  if (bVar1 == false) {
    if (this->m_isDart == true) {
      fVar6 = 0.25;
      if (this->m_vehicleSize != 1.0) {
        fVar6 = 0.4;
      }
    }
    else if ((this->m_isPlatformer == true) && (this->m_isShip == true)) {
      if (((((this->m_holdingLeft & 1U) == 0) && ((this->m_holdingRight & 1U) == 0)) &&
          ((this->m_platformerMovingLeft & 1U) == 0)) && (this->m_platformerMovingRight != true)) {
        fVar4 = 0.0;
        fVar6 = 0.06;
      }
      else {
        fVar7 = -1.0;
        if (this->m_isGoingLeft == false) {
          fVar7 = 1.0;
        }
        if (this->m_isUpsideDown != this->m_isSideways) {
          fVar7 = -fVar7;
        }
        fVar4 = fVar7 * 0.7853982;
        fVar6 = 0.015;
        if (0.1 <= ABS(fVar7 * 0.5235988) - ABS(fVar5 * 0.017453292)) {
          fVar4 = fVar7 * 0.5235988;
          fVar6 = 0.07;
        }
      }
    }
    else {
      fVar6 = 0.15;
    }
  }
  else {
    fVar6 = (float)NEON_fminnm(fVar4,0x3dcccccd);
    if (this->m_isGoingLeft != this->m_isUpsideDown) {
      fVar4 = fVar6;
    }
    if ((this->m_isPlatformer == true) &&
       ((ABS(this->m_platformerXVelocity) <= 0.5 || (this->m_isOnGround2 == true)))) {
      fVar4 = 0.0;
    }
    fVar6 = 0.07;
  }
  if ((this->m_isCollidingWithSlope != false) &&
     ((((this->m_isShip & 1U) != 0 || ((bVar1 & 1U) != 0)) ||
      (((this->m_isDart & 1U) != 0 || (this->m_isSwing == true)))))) {
    fVar6 = fVar6 * 0.25;
  }
  fVar7 = fVar6 * dt;
  if (dt <= fVar6 * dt) {
    fVar7 = dt;
  }
  fVar6 = (float)func_0x00010022515c(fVar5 * 0.017453292,fVar4,fVar7);
  virtual_0x158(fVar6 * 57.29578,this);
  return;
}


// ==== PlayerObject__updateSlopeRotation @ 0x3827f4

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


// ==== PlayerObject::limitDashRotation @ 0x386c4c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PlayerObject__limitDashRotation(PlayerObject *this,undefined *rotation)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
  fVar5 = -90.0;
  if (this->m_isSideways == false) {
    fVar5 = 0.0;
  }
  fVar4 = fVar5 + 180.0;
  if (this->m_isGoingLeft == false) {
    fVar4 = fVar5;
  }
  fVar5 = *(float *)rotation;
  if (fVar4 != 0.0) {
    fVar5 = fVar4 + fVar5;
    *(float *)rotation = fVar5;
    if (fVar5 <= 180.0) {
      if (-180.0 <= fVar5) goto LAB_100386cc8;
      fVar6 = 360.0;
    }
    else {
      fVar6 = -360.0;
    }
    fVar5 = fVar5 + fVar6;
    *(float *)rotation = fVar5;
  }
LAB_100386cc8:
  if (90.0 < ABS(fVar5)) {
    fVar6 = 180.0;
    if (fVar5 <= 0.0) {
      fVar6 = -180.0;
    }
    fVar5 = fVar6 - fVar5;
    *(float *)rotation = fVar5;
    if (fVar5 <= 180.0) {
      if (-180.0 <= fVar5) goto LAB_100386d2c;
      fVar6 = 360.0;
    }
    else {
      fVar6 = -360.0;
    }
    fVar5 = fVar5 + fVar6;
    *(float *)rotation = fVar5;
  }
LAB_100386d2c:
  bVar1 = true;
  if ((fVar5 <= 70.0) && (bVar1 = false, !NAN(fVar5))) {
    bVar1 = fVar5 < -70.0;
  }
  if (bVar1) {
    bVar1 = false;
    if ((-180.0 < fVar5) && (bVar1 = false, !NAN(fVar5))) {
      bVar1 = fVar5 < 70.0;
    }
    fVar6 = -70.0;
    if (!bVar1) {
      fVar6 = 70.0;
    }
    fVar7 = 70.0;
    bVar1 = false;
    bVar2 = true;
    bVar3 = false;
    if (fVar5 < 180.0) {
      bVar1 = false;
      bVar2 = false;
      bVar3 = true;
      if (!NAN(fVar5)) {
        bVar1 = fVar5 < 70.0;
        bVar2 = fVar5 == 70.0;
        bVar3 = false;
      }
    }
    if (bVar2 || bVar1 != bVar3) {
      fVar7 = -70.0;
    }
    bVar1 = 0.0 < fVar5;
    fVar5 = fVar6;
    if (bVar1) {
      fVar5 = fVar7;
    }
    *(float *)rotation = fVar5;
  }
  if (fVar4 != 0.0) {
    fVar5 = fVar5 - fVar4;
    *(float *)rotation = fVar5;
    if (fVar5 <= 180.0) {
      if (-180.0 <= fVar5) {
        return;
      }
      fVar4 = 360.0;
    }
    else {
      fVar4 = -360.0;
    }
    *(float *)rotation = fVar5 + fVar4;
  }
  return;
}


// ==== PlayerObject::flipMod @ 0x3793cc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int PlayerObject__flipMod(PlayerObject *this)

{
  int iVar1;
  
  iVar1 = 1;
  if (this->m_isUpsideDown != false) {
    iVar1 = -1;
  }
  return iVar1;
}


// ==== PlayerObject__hitGround @ 0x381ea0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PlayerObject__hitGround(PlayerObject *this,GameObject *object,bool notFlipped)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  undefined4 *puVar4;
  undefined8 uVar5;
  int iVar6;
  ulong uVar7;
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
    uVar7 = 0;
  }
  else {
    uVar7 = (ulong)object->m_objectMaterial;
  }
  this->m_groundObjectMaterial = (int)uVar7;
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
        iVar6 = (this->GameObject).m_uniqueID;
        uVar5 = 5;
      }
      else if (8.0 < dVar12) {
LAB_100381f5c:
        iVar6 = (this->GameObject).m_uniqueID;
        uVar5 = 4;
      }
      else if (4.0 < dVar12) {
LAB_100381f74:
        iVar6 = (this->GameObject).m_uniqueID;
        uVar5 = 3;
      }
      else {
        if (dVar12 <= 1.0) goto LAB_100381f80;
LAB_10038203c:
        iVar6 = (this->GameObject).m_uniqueID;
        if (this->m_isOnGround2 == true) {
          uVar5 = 1;
        }
        else {
          uVar5 = 2;
        }
      }
      GJBaseGameLayer__gameEventTriggered(*(long *)this->m_gameLayer,uVar5,uVar7,iVar6);
    }
LAB_100381f80:
    if (this->m_fallStartY != 0.0) {
      lVar3 = getPosition/*virtual+0xc0*/(this);
      fVar13 = this->m_fallStartY - *(float *)(lVar3 + 4);
      if ((fVar13 != 0.0) && (!NAN(fVar13))) {
        fVar13 = ABS(this->m_fallStartY - *(float *)(lVar3 + 4));
        if (fVar13 <= 450.0) {
          if (fVar13 <= 300.0) {
            if (fVar13 <= 150.0) {
              if ((7.5 < fVar13) && (lVar3 = *(long *)this->m_gameLayer, lVar3 != 0)) {
                uVar7 = (ulong)(uint)this->m_groundObjectMaterial;
                iVar6 = (this->GameObject).m_uniqueID;
                uVar5 = 0x41;
                goto LAB_100382074;
              }
            }
            else {
              lVar3 = *(long *)this->m_gameLayer;
              if (lVar3 != 0) {
                uVar7 = (ulong)(uint)this->m_groundObjectMaterial;
                iVar6 = (this->GameObject).m_uniqueID;
                uVar5 = 0x42;
LAB_100382074:
                GJBaseGameLayer__gameEventTriggered(lVar3,uVar5,uVar7,iVar6);
              }
            }
          }
          else {
            lVar3 = *(long *)this->m_gameLayer;
            if (lVar3 != 0) {
              uVar7 = (ulong)(uint)this->m_groundObjectMaterial;
              iVar6 = (this->GameObject).m_uniqueID;
              uVar5 = 0x43;
              goto LAB_100382074;
            }
          }
        }
        else {
          lVar3 = *(long *)this->m_gameLayer;
          if (lVar3 != 0) {
            uVar7 = (ulong)(uint)this->m_groundObjectMaterial;
            iVar6 = (this->GameObject).m_uniqueID;
            uVar5 = 0x44;
            goto LAB_100382074;
          }
        }
      }
      this->m_fallStartY = 0.0;
    }
  }
  iVar6 = (int)uVar7;
  this->m_yVelocity = 0.0;
  this->m_isSliding = false;
  if (((this->m_isOnGround2 & 1U) == 0) && (!notFlipped)) {
    if (this->m_playEffects == true) {
      lVar3 = GameManager__sharedState();
      uVar7 = GJBaseGameLayer__isFlipping(*(undefined8 *)(lVar3 + 0x1f8));
      if ((uVar7 & 1) != 0) goto LAB_100382250;
    }
    if ((this->m_isHidden & 1U) == 0) {
      lVar3 = 0x8b8;
      if (this->m_useLandParticles0 == false) {
        lVar3 = 0x8c0;
      }
      plVar11 = *(long **)((long)&(this->GameObject).vtable + lVar3);
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
        lVar3 = GameManager__sharedState();
        uVar7 = GJBaseGameLayer__isFlipping(*(undefined8 *)(lVar3 + 0x1f8));
        if ((uVar7 & 1) != 0) goto LAB_1003822c8;
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
        iVar6 = (int)*(undefined8 *)(this->m_currentRobotAnimation + 8);
        gd__string__assign(&uStack_70,*(undefined8 *)this->m_currentRobotAnimation);
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
    PlayerObject__runRotateAction(this,false,iVar6);
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


// ==== PlayerObject::setRotation @ 0x391b20

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PlayerObject__setRotation(PlayerObject *this,float rotation)

{
  long *plVar1;
  undefined2 uVar2;
  undefined4 in_register_00005004;
  
  if ((*(float *)&(this->GameObject).field_0x38 == rotation) &&
     (*(float *)&(this->GameObject).field_0x3c == rotation)) {
    return;
  }
  (this->GameObject).m_isObjectRectDirty = true;
  (this->GameObject).m_isOrientedBoxDirty = true;
  (this->GameObject).m_isDirty = true;
  CCSpritePlus__setRotation(this);
  plVar1 = *(long **)(this->GameObject).m_glowSprite;
  if (plVar1 != (long *)0x0) {
    (**(code **)(*plVar1 + 0x158))(CONCAT44(in_register_00005004,rotation));
  }
  plVar1 = *(long **)(this->GameObject).m_colorSprite;
  if ((plVar1 != (long *)0x0) && (((this->GameObject).m_colorSpriteLocked & 1U) == 0)) {
    (**(code **)(*plVar1 + 0x158))(CONCAT44(in_register_00005004,rotation));
  }
  plVar1 = *(long **)(this->GameObject).m_particle;
  if ((plVar1 != (long *)0x0) && (((this->GameObject).m_particleLocked & 1U) == 0)) {
    (**(code **)(*plVar1 + 0x158))();
  }
  uVar2 = NEON_umaxv(CONCAT26(-(ushort)(rotation == -270.0),
                              CONCAT24(-(ushort)(rotation == 270.0),
                                       CONCAT22(-(ushort)(rotation == -90.0),
                                                -(ushort)(rotation == 90.0)))),2);
  (this->GameObject).m_isRotationAligned = (bool)((byte)uVar2 & 1);
  return;
}


// ==== PlayerObject::getObjectRotation @ 0x390694

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float PlayerObject__getObjectRotation(PlayerObject *this)

{
  float fVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00010039069c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  fVar1 = (float)virtual_0x160();
  return fVar1;
}



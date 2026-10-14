# GD 2.2081 player rotation notes

Source: `rotation_full.c` (16 functions). Angles in degrees, velocities world-relative.
Timing: GJBaseGameLayer::update runs 4 substeps per 60fps frame. Rotation gets dt in real frames (60 = 1 s); PlayerObject::update passes `dt * 0.9` to updateJump/updateMove (physics), but not to updateRotation. `m_playerSpeed` = 0.7 / 0.9 / 1.1 / 1.3 / 1.6 for 0.5x-4x.

- Spin speed (`runRotateAction` / `runNormalRotation`), cube only (not ship/ufo/wave/swing/robot/spider/dash):
  `rotationSpeed = flip * gravityMod * 180 / (mini ? 0.3333 : 0.4333)` deg/s, flip = -1 if upside down, x-1 going left, x-1 sideways.
  Applied each step: `rotation += (dt / 60) * rotationSpeed`.
- Ball (`runRotateAction`): `rotationSpeed = 120 * flip / ((mini ? 0.16 : 0.2) * speedFactor)`, speedFactor = 1.2405638 (0.5x), 1 (1x), 0.80424345 (2x), 0.6657693 (3x), 0.5409375 (4x). Ball also uses `m_rotateSpeed` while ball-rotating.
- `updateRotation(dt)`, in order: ball -> just spin; on slope -> `updateSlopeRotation`; ship/ufo/wave/swing -> `updateShipRotation`;
  on ground and not moving away (|yVel| <= 0.25 toward ground side) and not just off a slope -> stop spin and ease to `convertToClosestRotation` (nearest 90 deg);
  robot/spider in air -> ease toward 0 at half rate.
- Easing (`updateRotation(dt, target)`): factor = `playerSpeed * 0.175` (x0.5 ship; x3 for cube/robot/spider on flat ground), `t = min(factor * dt, dt)`, angle-lerp current -> target by t.
- `convertToClosestRotation`: snaps to the multiple of 90 nearest to the current rotation.
- Leaving a slope (`postCollision`):
  - Launching off it (slope's upward speed beats current yVel): `boostPlayer` -> cube spins **backwards** at `180 / (mini ? 0.6667 : 0.8667)` deg/s (half normal speed) until it lands; ship/ufo/wave/swing/ball/robot get no rotation change, spider plays `fall_loop`.
  - Going off the downhill end without a launch: `yVel = -m_currentSlopeYVelocity` and the normal forward spin (`runRotateAction`).
- On a slope (`updateSlopeRotation`): eases toward slope angle + nearest multiple of 90 deg, rate `playerSpeed * 0.175` (no x3).

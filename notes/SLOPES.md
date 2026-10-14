# GD 2.2081 slope collision notes

Source: Ghidra decompile of the macOS arm64 binary (`slopes_full.c`, 33 functions), names/offsets from geode-sdk/bindings 2.2081.
Units below are GD units (Web Dashers world units are 2x). Velocities are world-relative (positive = up).

## Call chain
`GJBaseGameLayer::collisionCheckObjects` -> `PlayerObject::collidedWithSlope` -> (rotated slopes: `handleRotatedSlopeCollision` -> `handleRotatedCollisionInternal`) -> `collidedWithSlopeInternal`.
`collidedWithSlopeInternal` first calls `preSlopeCollision` (side-wall check for the vertical edge, `slopeWallLeft`), unless `forced`.
`postCollision` handles slope exit (sets `m_slopeVelocity`-based launch), `updateSlopeRotation` snaps rotation.

## Slope geometry (GameObject)
- `m_slopeDirection` (0x43c) is 0..7 from `determineSlopeDirection` (flipX/flipY/rotation).
- `slopeFloorTop()` = direction in {1,3,5,6} (solid side is on top, i.e. a ceiling slope).
- `slopeWallLeft()` = direction in {2,3,4,6}.
- `slopeYPos(x)` = line through the object rect; hazard slopes (`m_slopeIsHazard`) are offset 4 units into the solid side.
- `getSlopeAngle()` = `atan(rect.h / rect.w)`.

## collidedWithSlopeInternal, condensed
1. `slidingDown` = slope goes down in the travel direction (flipped by upside-down, going-left, sideways).
2. Early-outs when already on a slope:
   - leaving an uphill slope onto a downhill one of the same top/bottom type while `m_slopeVelocity > 0` -> ignore;
   - new slope's y-speed (`h / (w / (speedMul * playerSpeed))`) lower than `m_currentSlopeYVelocity` while launching -> ignore.
3. Stick distance: `4` if sliding down and was on a slope, else `slidingDown ? 1 : 0`; plus moving-slope movement clamped to `5*dt` (`10*dt` platformer).
4. Player half-height is divided by `cos(m_slopeRotation)`. Target y = `slopeYPos(playerX) +/- halfH/cos(angle)`, clamped to the slope rect.
   When switching between a floor slope and a ceiling slope (slope intersection) the target is pulled in by `20 * vehicleSize` (0 in platformer).
5. "Landing" side (floor slope with normal gravity, or ceiling slope upside down): collide if past target (or within stick distance when sliding down / ship-style modes). Lands with `hitGround`; y-velocity > 5 (away from slope) is kept.
6. "Wrong" side (ceiling slope with normal gravity, floor slope upside down), when the player has gone past the target:
   - cube / robot / spider (not platformer):
     - if gamemode changed or gravity flipped < 0.1 s ago: snap to target, `yVel = min(yVel, -2)` (`max(yVel, 2)` upside down), not on ground, return;
     - within 2 units of target: no death, just `onGround = false`;
     - otherwise die (unless `m_ignoreDamage`, or `m_maybeCanRunIntoBlocks`).
   - ship / UFO / wave / swing / ball / platformer: pushed to target like hitting a ceiling, `yVel` toward the slope zeroed.
     Exceptions that still kill: hazard slopes, slope intersections, wave (dart) without slide state.
7. After colliding: `m_slopeVelocity = slopeYVel * 1.4 * min(0.8 / angle, 1.1)` (sign by direction/gravity), x0.75 for flying modes and ball.
   Ball skips `updateSlopeRotation`; other modes call it.
8. Exit launch uses `getModifiedSlopeYVel`: `m_slopeVelocity * clamp((time - slopeStart) * 10, 0.4, 1)` (full after 0.1 s on the slope).

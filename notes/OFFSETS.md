GD 2.2081 mac arm64, decompiled with Ghidra 12.1.4 (~/Applications/ghidra_12.1.4_PUBLIC, decompiler built locally for mac_arm_64).
Function names from geode-sdk/bindings 2.2081 (names.txt = m1 offsets). Image base 0x100000000.

Re-run:
  export JAVA_HOME=/opt/homebrew/opt/openjdk@21
  ~/Applications/ghidra_12.1.4_PUBLIC/support/analyzeHeadless <proj_dir> gd -process gd_arm64 -noanalysis -scriptPath <dir with Decomp.java> -postScript Decomp.java <names.txt> 0xADDR,0xADDR <out.c>
  (first time: -import gd_arm64 instead of -process; gd_arm64 = lipo -thin arm64 of the GD binary)

PlayerObject offsets (param_2 in slope code; param_2[N] = byte offset N*8):
0x590 slope start time   0x5cc/0x5c8 last ground obj ids
0x680 m_collidingWithSlopeId   0x684 m_slopeFlipGravityRelated   0x690 m_slopeAngleRadians
0x780 m_speedMultiplier  0x790 m_gravity  0x7a0 m_gameModeChangedTime  0x7c8 m_lastFlipTime
0x7ad m_maybeCanRunIntoBlocks (no slope death)
0x8e0 m_slopeRotation  0x8e8 m_currentSlopeYVelocity  0x903 m_isCurrentSlopeTop
0x8f0/0x8f8 last slope y / adjusted y   0x900/0x901 last clamp flags
0x934 m_maybeIsColliding  0x935 m_jumpBuffered (holding jump)
0x950 m_yVelocity  0x960 m_isOnSlope  0x961 m_wasOnSlope  0x964 m_slopeVelocity
0x969 ship 0x96a ufo 0x96b ball 0x96c wave 0x96d robot 0x96e spider 0x96f upsideDown
0x970 dead 0x971 onGround 0x972 goingLeft 0x973 sideways 0x974 swing
0x9a0 m_vehicleSize (1 / 0.6)  0x9a4 m_playerSpeed  0x9bc onGround2
0xa38 total time  0xa90 platformer x velocity  0xb08 isPlatformer

GameObject: 0x394 uniqueID  0x438 slope "flipped" bool  0x43c slope type (0..7)  0x440 slope "+4 y" bool
slopeFloorTop = type in {1,3,5,6}   slopeWallLeft = type in {2,3,4,6}

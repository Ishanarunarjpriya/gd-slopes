# gd-slopes

Geometry Dash 2.2081 slope and player-rotation logic, decompiled from the macOS arm64 binary with Ghidra 12.1.4.
Function names and struct layouts come from [geode-sdk/bindings](https://github.com/geode-sdk/bindings) (2.2081).

## Contents
- `notes/SLOPES.md`: plain-English summary of slope collision, launches, and slope exit.
- `notes/ROTATION.md`: cube/ball spin speeds, landing snap, slope rotation, slope-launch spin.
- `notes/HITBOX_SNAP.md`: object rect / hitbox, landing snap-jump offsets, editor slope rotation.
- `notes/OFFSETS.md`: PlayerObject / GameObject field offsets used in the code.
- `decomp/slopes_full.c`: 33 slope-related functions (`collidedWithSlopeInternal`, `preSlopeCollision`, `postCollision`, `updateJump`, `boostPlayer`, ...).
- `decomp/rotation_full.c`: 16 rotation functions (`runRotateAction`, `updateRotation`, `updateSlopeRotation`, ...).
- `decomp/hitbox_snap_editor.c`: object rect + oriented box, `checkSnapJumpToObject`, `rotationForSlopeNearObject`.
- `tools/`: Ghidra headless scripts and the layout/name files to regenerate or extend the output.

## Regenerating
1. `lipo "Geometry Dash" -thin arm64 -output gd_arm64`
2. `analyzeHeadless <proj> gd -import gd_arm64 -noanalysis -scriptPath tools -postScript DecompTyped.java <dir with po_layout.txt, go_layout.txt, names.txt, targets.txt> out.c`

`targets.txt` lines are `m1offset|Class|returnType|name|args|static`. Addresses are binding m1 offsets + 0x100000000.

Units are GD units; Web Dashers world units are 2x.

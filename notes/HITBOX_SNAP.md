# Object rect, snap jump, editor slope rotation

Source: `decomp/hitbox_snap_editor.c` (11 functions).

## GameObject::getObjectRect(width, height)
- size = (m_width * scaleX * width, m_height * scaleY * height); scales use abs() when `m_isMirroredByScale`.
- If `m_isRotationAligned` (rotated by 90/270), width and height are swapped.
- Rect is centered on `getRealPosition() + getBoxOffset()`.
- `getObjectRect()` (no args) returns the cached rect, rebuilt when `m_objectRectDirty`; slopes use this same rect, and the slope line is the rect diagonal (`GameObject::slopeYPos`).
- `getOrientedBox` / `calculateOrientedBox` / `updateOrientedBox`: the OBB used for rotated hitboxes.

## PlayerObject::checkSnapJumpToObject(object)
Called on landing. If the previously landed object exists and the new one sits at a standard jump offset from it, the player's x is nudged so its offset to the new object equals the offset it had to the old one (`m_snapDistance`), moving at most `tol` units.
Offsets (dx, dy relative to old object, dy flipped when upside down), `tol` = 1 (2 at 2x/3x):

| speed | dx for dy=+30 | dx for dy=-30 | dx for dy=+60 |
|---|---|---|---|
| 0.5x | 90 | 120 | 60 |
| 1x | 120 (mini 90) | 150 | 90 |
| 2x | 150 (mini 90) | 195 | 120 |
| 3x | 180 (mini 90) | 225 | 135 |
| 4x | 120 | 150 | 90 |

Afterwards `m_objectSnappedTo = object` and `m_snapDistance = player.x - object.x`.

## LevelEditorLayer::rotationForSlopeNearObject(object)
Editor-only helper used when auto-rotating placed objects (e.g. spikes) next to a slope; uses `determineSlopeDirection`, `slopeFloorTop` and `getSlopeAngle`.

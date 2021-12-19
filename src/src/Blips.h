#pragma once

const Hash BLIP_STYLE_ENEMY = 0x318C617C;
const Hash BLIP_STYLE_WHITE_DOT = 0xB04092F8;
const Hash BLIP_STYLE_FLASHING = 0x4B1C3939;

Blip createBlip(Vector3 pos, Hash blipType, Hash blipSprite = 0);
Blip createBlip(Entity entity, Hash blipType, Hash blipSprite = 0);
Blip createBlip(Vector3 source, float radius, Hash blipType, Hash blipSprite = 0);
void setBlipLabel(Blip blip, const char* label);
void deleteBlipSafe(Blip* blip);
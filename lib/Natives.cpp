#pragma once

#include "Natives.h"
#include "Utils.h"

void (*__DRAW_RECT) (float, float, float, float, int, int, int, int);
void (*__DRAW_SPRITE) (const char*, const char*, float, float, float, float, float, int, int, int, int, bool, bool);

void InitialiseNatives()
{
    ConvertCall(
            hook::get_pattern(
                        "48 8B C4 48 89 58 08 57 48 83 EC 70 48 63 0D ? ? ? ? 0F 29 70 E8"),
                            __DRAW_RECT);

    ConvertCall(
                hook::get_pattern("48 8B C4 48 89 58 08 48 89 68 10 48 89 70 18 57 48 81 EC ? ? ? ? 0F 29 70 E8 0F 29 78 D8 48 8B F2"),
                        __DRAW_SPRITE);
}

void DRAW_RECT(float x, float y, float width, float height, int r, int g, int b, int a)
{
    return __DRAW_RECT(x, y, width, height, r, g, b, a);
}

void DRAW_SPRITE(const char* textureDictionary, const char* textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a)
{
    return __DRAW_SPRITE(textureDictionary, textureName, x, y, width, height, rotation, r, g, b, a, false, false);
}
#ifndef REVENANT_NATIVES_H
#define REVENANT_NATIVES_H

#pragma once

void DRAW_RECT(float x, float y, float width, float height, int r, int g, int b, int a);
void DRAW_SPRITE(const char* textureDictionary, const char* textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a);

void InitialiseNatives();

#endif //REVENANT_NATIVES_H
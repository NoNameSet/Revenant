#ifndef REVENANT_BLIP_H
#define REVENANT_BLIP_H

#pragma once

#include "../entities/Entity.h"

namespace revenant
{
    class Blip
    {
    public:
        Blip(const Vector3& position);
        Blip(const Vector3& position, float radius);
        Blip(const Vector3& position, const Vector2& area);
        Blip(const Entity& entity);
        Blip(int32_t handle);

        bool operator==(int32_t other) const;
        bool operator==(const Blip& other) const;

        static bool Exists(const Blip* blip);
        static bool Exists(int32_t handle);

        [[nodiscard]] bool IsShortRange() const;
        [[nodiscard]] bool IsOnMiniMap() const;
        [[nodiscard]] bool IsFlashing() const;
        [[nodiscard]] bool Exists() const;

        [[nodiscard]] int GetHandle() const;
        [[nodiscard]] int GetAlpha() const;
        [[nodiscard]] int GetRotation() const;

        [[nodiscard]] BLIP_SPRITE GetSprite() const;

        [[nodiscard]] Vector3 GetPosition() const;

        void SetPosition(const Vector3& position) const;
        void SetSprite(BLIP_SPRITE sprite) const;
        void SetName(const std::string& name) const;
        void SetRoute(bool enabled) const;
        void SetRouteColor(RGBA color) const;
        void SetAlpha(int alpha) const;
        void SetRotation(int value) const;
        void SetFlashes(bool toggle) const;
        void SetFlashTimer(int duration) const;
        void SetFlashInterval(int interval) const;
        void SetColor(RGBA color) const;
        void SetSecondaryColor(RGBA color) const;
        void SetHiddenOnLegend(bool toggle) const;
        void SetShortRange(bool toggle) const;
        void SetScale(float scale) const;
        void SetScale(const Vector2& scale) const;
        void ShowNumber(int number) const;
        void HideNumber() const;
        void ShowHeight(bool toggle) const;
        void ShowTick(bool toggle) const;
        void ShowHeadingIndicator(bool toggle) const;
        void ShowOutlineIndicator(bool toggle) const;
        void ShowCone(bool toggle, HUD_COLOURS color = HUD_COLOUR_BLUEDARK) const;
        void Delete();
    private:
        int32_t handle;
    };
}

#endif //REVENANT_BLIP_H
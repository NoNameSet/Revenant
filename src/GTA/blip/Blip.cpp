#include "Blip.h"
#include "../entities/Entity.h"

namespace revenant
{
    Blip::Blip(const Vector3 &position)
    {
        this->handle = HUD::ADD_BLIP_FOR_COORD(position.x, position.y, position.z);
    }

    Blip::Blip(const Vector3 &position, float radius)
    {
        this->handle = HUD::ADD_BLIP_FOR_RADIUS(position.x, position.y, position.z, radius);
    }

    Blip::Blip(const Vector3 &position, const Vector2 &area)
    {
        this->handle = HUD::ADD_BLIP_FOR_AREA(position.x, position.y, position.z, area.x, area.y);
    }

    Blip::Blip(const Entity &entity)
    {
        this->handle = HUD::ADD_BLIP_FOR_ENTITY(entity.GetHandle());
    }

    Blip::Blip(int32_t handle)
    {
        this->handle = handle;
    }

    bool Blip::operator==(int32_t other) const
    {
        return Exists() && Exists(other) && this->handle == other;
    }

    bool Blip::operator==(const Blip &other) const
    {
        return Exists() && other.Exists() && this->handle == other.GetHandle();
    }

    bool Blip::Exists(const Blip *blip)
    {
        return blip != nullptr && blip->Exists();
    }

    bool Blip::Exists(int32_t handle)
    {
        return HUD::DOES_BLIP_EXIST(handle);
    }

    bool Blip::IsShortRange() const
    {
        return HUD::IS_BLIP_SHORT_RANGE(this->handle);
    }

    bool Blip::IsOnMiniMap() const
    {
        return HUD::IS_BLIP_ON_MINIMAP(this->handle);
    }

    bool Blip::IsFlashing() const
    {
        return HUD::IS_BLIP_FLASHING(this->handle);
    }

    bool Blip::Exists() const
    {
        return HUD::DOES_BLIP_EXIST(this->handle);
    }

    int Blip::GetHandle() const
    {
        return this->handle;
    }

    int Blip::GetAlpha() const
    {
        return HUD::GET_BLIP_ALPHA(this->handle);
    }

    int Blip::GetRotation() const
    {
        return HUD::GET_BLIP_ROTATION(this->handle);
    }

    BLIP_SPRITE Blip::GetSprite() const
    {
        return static_cast<BLIP_SPRITE>(HUD::GET_BLIP_SPRITE(this->handle));
    }

    Vector3 Blip::GetPosition() const
    {
        return HUD::GET_BLIP_COORDS(this->handle);
    }

    void Blip::SetPosition(const Vector3 &position) const
    {
        HUD::SET_BLIP_COORDS(this->handle, position.x, position.y, position.z);
    }

    void Blip::SetSprite(BLIP_SPRITE sprite) const
    {
        HUD::SET_BLIP_SPRITE(this->handle, static_cast<int>(sprite));
    }

    void Blip::SetName(const std::string &name) const
    {
        HUD::BEGIN_TEXT_COMMAND_SET_BLIP_NAME("STRING");
        HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(name.c_str());
        HUD::END_TEXT_COMMAND_SET_BLIP_NAME(this->handle);
    }

    void Blip::SetRoute(bool enabled) const
    {
        HUD::SET_BLIP_ROUTE(this->handle, enabled);
    }

    void Blip::SetRouteColor(rage::Color32 color) const
    {
        HUD::SET_BLIP_ROUTE_COLOUR(this->handle, color.m_Color);
    }

    void Blip::SetAlpha(int alpha) const
    {
        HUD::SET_BLIP_ALPHA(this->handle, alpha);
    }

    void Blip::SetRotation(int value) const
    {
        HUD::SET_BLIP_ROTATION(this->handle, value);
    }

    void Blip::SetFlashes(bool toggle) const
    {
        HUD::SET_BLIP_FLASHES(this->handle, toggle);
    }

    void Blip::SetFlashTimer(int duration) const
    {
        HUD::SET_BLIP_FLASH_TIMER(this->handle, duration);
    }

    void Blip::SetFlashInterval(int interval) const
    {
        HUD::SET_BLIP_FLASH_INTERVAL(this->handle, interval);
    }

    void Blip::SetColor(rage::Color32 color) const
    {
        HUD::SET_BLIP_COLOUR(this->handle, color.GetRGBA());
    }

    void Blip::SetSecondaryColor(rage::Color32 color) const
    {
        HUD::SET_BLIP_SECONDARY_COLOUR(this->handle, color.GetRed(), color.GetGreen(), color.GetBlue());
    }

    void Blip::SetHiddenOnLegend(bool toggle) const
    {
        HUD::SET_BLIP_HIDDEN_ON_LEGEND(this->handle, toggle);
    }

    void Blip::SetShortRange(bool toggle) const
    {
        HUD::SET_BLIP_AS_SHORT_RANGE(this->handle, toggle);
    }

    void Blip::SetScale(float scale) const
    {
        HUD::SET_BLIP_SCALE(this->handle, scale);
    }

    void Blip::SetScale(const Vector2 &scale) const
    {
        HUD::SET_BLIP_SCALE_2D(this->handle, scale.x, scale.y);
    }

    void Blip::ShowNumber(int number) const
    {
        HUD::SHOW_NUMBER_ON_BLIP(this->handle, number);
    }

    void Blip::HideNumber() const
    {
        HUD::HIDE_NUMBER_ON_BLIP(this->handle);
    }

    void Blip::ShowHeight(bool toggle) const
    {
        HUD::SHOW_HEIGHT_ON_BLIP(this->handle, toggle);
    }

    void Blip::ShowTick(bool toggle) const
    {
        HUD::SHOW_TICK_ON_BLIP(this->handle, toggle);
    }

    void Blip::ShowHeadingIndicator(bool toggle) const
    {
        HUD::SHOW_HEADING_INDICATOR_ON_BLIP(this->handle, toggle);
    }

    void Blip::ShowOutlineIndicator(bool toggle) const
    {
        HUD::SHOW_OUTLINE_INDICATOR_ON_BLIP(this->handle, toggle);
    }

    void Blip::ShowCone(bool toggle, HUD_COLOURS color) const
    {
        HUD::SET_BLIP_SHOW_CONE(this->handle, toggle, static_cast<int>(color));
    }

    void Blip::Delete()
    {
        HUD::REMOVE_BLIP(&this->handle);
    }
}
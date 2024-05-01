#include "Player.h"
#include "fwScriptGuid.h"
#include "CGameWorld.h"

namespace revenant
{
    void Player::SetModel(const Model &model)
    {
        PLAYER::SET_PLAYER_MODEL(PLAYER::PLAYER_ID(), model.GetModelHash());
    }

    void Player::SetWantedLevel(int level)
    {
        PLAYER::SET_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_ID(), level, false);
        PLAYER::SET_PLAYER_WANTED_LEVEL_NOW(PLAYER::PLAYER_ID(), false);
    }

    void Player::SetMaxWantedLevel(int level)
    {
        PLAYER::SET_MAX_WANTED_LEVEL(level);
    }

    void Player::SetControl(bool setControlOn, SET_PLAYER_CONTROL_FLAGS flags)
    {
        PLAYER::SET_PLAYER_CONTROL(PLAYER::PLAYER_ID(), setControlOn, static_cast<int>(flags));
    }

    int Player::GetWantedLevel()
    {
        return PLAYER::GET_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_ID());
    }

    int Player::GetMaxWantedLevel()
    {
        return PLAYER::GET_MAX_WANTED_LEVEL();
    }

    int Player::GetId()
    {
        return PLAYER::PLAYER_ID();
    }

    bool Player::IsPlaying()
    {
        return PLAYER::IS_PLAYER_PLAYING(PLAYER::PLAYER_ID());
    }

    bool Player::IsFreeAiming()
    {
        return PLAYER::IS_PLAYER_FREE_AIMING(PLAYER::PLAYER_ID());
    }

    bool Player::IsFreeAimingAtEntity(const Entity &entity)
    {
        return PLAYER::IS_PLAYER_FREE_AIMING_AT_ENTITY(PLAYER::PLAYER_ID(), entity.GetHandle());
    }

    bool Player::IsControlOn()
    {
        return PLAYER::IS_PLAYER_CONTROL_ON(PLAYER::PLAYER_ID());
    }

    std::unique_ptr<PedGroup> Player::GetGroup()
    {
        return std::make_unique<PedGroup>(PLAYER::GET_PLAYER_GROUP(PLAYER::PLAYER_ID()));
    }

    std::unique_ptr<Entity> Player::GetFreeAimingTarget()
    {
        int guid;
        return std::make_unique<Entity>(PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &guid));
    }

    std::unique_ptr<Ped> Player::GetCharacter()
    {
        return std::make_unique<Ped>(fwScriptGuid::CreateGuid(reinterpret_cast<uint64_t*>(CGameWorld::FindPlayer())));
    }
}
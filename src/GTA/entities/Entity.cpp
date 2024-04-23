#pragma once

#include "Entity.h"
#include "fwScriptGuid.h"

namespace revenant
{
    Entity::Entity() : Entity(NULL)
    { }

    Entity::Entity(int32_t handle)
    {
        this->handle = handle;
    }

    bool Entity::operator==(int32_t other) const
    {
        return Exists() && Exists(other) && GetHandle() == other;
    }

    bool Entity::operator==(const Entity &other) const
    {
        return Exists() && other.Exists() && GetHandle() == other.GetHandle();
    }

    bool Entity::Exists() const
    {
        return ENTITY::DOES_ENTITY_EXIST(this->handle);
    }

    bool Entity::Exists(int32_t handle)
    {
        return ENTITY::DOES_ENTITY_EXIST(handle);
    }

    bool Entity::Exists(const Entity *entity)
    {
        return entity != nullptr && entity->Exists();
    }

    bool Entity::IsValid() const
    {
        return this->Exists() && this->handle != 0;
    }

    int Entity::GetHandle() const
    {
        return handle;
    }

    std::unique_ptr<Model> Entity::GetModel()
    {
        return std::make_unique<Model>(ENTITY::GET_ENTITY_MODEL(this->handle));
    }

    uintptr_t Entity::GetMemoryAddress() const
    {
        return fwScriptGuid::GetBaseFromGuid(this->handle);
    }
}
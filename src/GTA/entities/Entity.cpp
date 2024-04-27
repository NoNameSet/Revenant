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

    bool Entity::HasBeenDamagedByAnyObject() const
    {
        return ENTITY::HAS_ENTITY_BEEN_DAMAGED_BY_ANY_OBJECT(this->handle);
    }

    bool Entity::HasBeenDamagedByAnyPed() const
    {
        return ENTITY::HAS_ENTITY_BEEN_DAMAGED_BY_ANY_PED(this->handle);
    }

    bool Entity::HasBeenDamagedByAnyVehicle() const
    {
        return ENTITY::HAS_ENTITY_BEEN_DAMAGED_BY_ANY_VEHICLE(this->handle);
    }

    bool Entity::HasBeenDamagedBy(const Entity &entity, bool includeVehicle) const
    {
        return ENTITY::HAS_ENTITY_BEEN_DAMAGED_BY_ENTITY(this->handle, entity.GetHandle(), includeVehicle);
    }

    bool Entity::CanSee(const Entity &entity, LOS_FLAGS flags) const
    {
        return ENTITY::HAS_ENTITY_CLEAR_LOS_TO_ENTITY(this->handle, entity.GetHandle(), static_cast<int>(flags));
    }

    bool Entity::CanSee(Entity &entity) const
    {
        return ENTITY::HAS_ENTITY_CLEAR_LOS_TO_ENTITY_IN_FRONT(this->handle, entity.GetHandle());
    }

    bool Entity::HasCollidedWithAnything() const
    {
        return ENTITY::HAS_ENTITY_COLLIDED_WITH_ANYTHING(this->handle);
    }

    bool Entity::IsMissionEntity() const
    {
        return ENTITY::IS_ENTITY_A_MISSION_ENTITY(this->handle);
    }

    bool Entity::IsAttached() const
    {
        return ENTITY::IS_ENTITY_ATTACHED(this->handle);
    }

    bool Entity::IsAttachedToAnyObject() const
    {
        return ENTITY::IS_ENTITY_ATTACHED_TO_ANY_OBJECT(this->handle);
    }

    bool Entity::IsAttachedToAnyPed() const
    {
        return ENTITY::IS_ENTITY_ATTACHED_TO_ANY_PED(this->handle);
    }

    bool Entity::IsAttachedToAnyVehicle() const
    {
        return ENTITY::IS_ENTITY_ATTACHED_TO_ANY_VEHICLE(this->handle);
    }

    bool Entity::IsAttachedTo(const Entity &entity) const
    {
        return ENTITY::IS_ENTITY_ATTACHED_TO_ENTITY(this->handle, entity.GetHandle());
    }

    bool Entity::IsAlive() const
    {
        return !ENTITY::IS_ENTITY_DEAD(this->handle, false);
    }

    bool Entity::IsDead() const
    {
        return ENTITY::IS_ENTITY_DEAD(this->handle, false);
    }

    bool Entity::IsInAir() const
    {
        return ENTITY::IS_ENTITY_IN_AIR(this->handle);
    }

    bool Entity::IsInWater() const
    {
        return ENTITY::IS_ENTITY_IN_WATER(this->handle);
    }

    bool Entity::IsOnScreen() const
    {
        return ENTITY::IS_ENTITY_ON_SCREEN(this->handle);
    }

    bool Entity::IsStatic() const
    {
        return ENTITY::IS_ENTITY_STATIC(this->handle);
    }

    bool Entity::IsTouching(const Entity &entity) const
    {
        return ENTITY::IS_ENTITY_TOUCHING_ENTITY(this->handle, entity.GetHandle());
    }

    bool Entity::IsUpright(float angle) const
    {
        return ENTITY::IS_ENTITY_UPRIGHT(this->handle, angle);
    }

    bool Entity::IsUpsideDown() const
    {
        return ENTITY::IS_ENTITY_UPSIDEDOWN(this->handle);
    }

    bool Entity::IsVisible() const
    {
        return ENTITY::IS_ENTITY_VISIBLE(this->handle);
    }

    bool Entity::IsOccluded() const
    {
        return ENTITY::IS_ENTITY_OCCLUDED(this->handle);
    }

    bool Entity::IsWaitingForCollision() const
    {
        return ENTITY::IS_ENTITY_WAITING_FOR_WORLD_COLLISION(this->handle);
    }

    bool Entity::IsCollisionEnabled() const
    {
        return !ENTITY::GET_ENTITY_COLLISION_DISABLED(this->handle);
    }

    float Entity::GetHeading() const
    {
        return ENTITY::GET_ENTITY_HEADING(this->handle);
    }

    float Entity::GetHeight() const
    {
        Vector3 position = GetPosition();
        return ENTITY::GET_ENTITY_HEIGHT(this->handle, position.x, position.y, position.z, true, true);
    }

    float Entity::GetHeightAboveGround() const
    {
        return ENTITY::GET_ENTITY_HEIGHT_ABOVE_GROUND(this->handle);
    }

    float Entity::GetSpeed() const
    {
        return ENTITY::GET_ENTITY_SPEED(this->handle);
    }

    std::unique_ptr<Entity> Entity::GetEntityAttachedTo() const
    {
        return std::make_unique<Entity>(ENTITY::GET_ENTITY_ATTACHED_TO(this->handle));
    }

    Vector3 Entity::GetPosition() const
    {
        return ENTITY::GET_ENTITY_COORDS(this->handle, false);
    }

    Vector3 Entity::GetForwardVector() const
    {
        Vector3 forwardVector, rightVector, upVector, position;
        ENTITY::GET_ENTITY_MATRIX(this->handle, &forwardVector, &rightVector, &upVector, &position);
        return forwardVector;
    }

    Vector3 Entity::GetRearVector() const
    {
        Vector3 forwardVector, rightVector, upVector, position;
        ENTITY::GET_ENTITY_MATRIX(this->handle, &forwardVector, &rightVector, &upVector, &position);
        return { forwardVector.x, -forwardVector.y, forwardVector.z };
    }

    Vector3 Entity::GetRightVector() const
    {
        Vector3 forwardVector, rightVector, upVector, position;
        ENTITY::GET_ENTITY_MATRIX(this->handle, &forwardVector, &rightVector, &upVector, &position);
        return rightVector;
    }

    Vector3 Entity::GetLeftVector() const
    {
        Vector3 forwardVector, rightVector, upVector, position;
        ENTITY::GET_ENTITY_MATRIX(this->handle, &forwardVector, &rightVector, &upVector, &position);
        return { -rightVector.x, rightVector.y, rightVector.z };
    }

    Vector3 Entity::GetUpVector() const
    {
        Vector3 forwardVector, rightVector, upVector, position;
        ENTITY::GET_ENTITY_MATRIX(this->handle, &forwardVector, &rightVector, &upVector, &position);
        return upVector;
    }

    Vector3 Entity::GetBottomVector() const
    {
        Vector3 forwardVector, rightVector, upVector, position;
        ENTITY::GET_ENTITY_MATRIX(this->handle, &forwardVector, &rightVector, &upVector, &position);
        return { upVector.x, upVector.y, -upVector.z };
    }

    Vector3 Entity::GetPositionOffset(const Vector3 &position) const
    {
        return ENTITY::GET_OFFSET_FROM_ENTITY_GIVEN_WORLD_COORDS(this->handle, position.x, position.y, position.z);
    }

    Vector3 Entity::GetOffsetPosition(const Vector3 &offset) const
    {
        return ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(this->handle, offset.x, offset.y, offset.z);
    }

    Vector3 Entity::GetRotation() const
    {
        return ENTITY::GET_ENTITY_ROTATION(this->handle, static_cast<int>(EULER_YXZ));
    }

    Vector3 Entity::GetVelocity() const
    {
        return ENTITY::GET_ENTITY_VELOCITY(this->handle);
    }

    Vector3 Entity::GetBoneRotation(int boneId) const
    {
        return ENTITY::GET_ENTITY_BONE_ROTATION(this->handle, boneId);
    }

    Vector3 Entity::GetBonePosition(int boneId) const
    {
        return ENTITY::GET_ENTITY_BONE_POSTION(this->handle, boneId);
    }

    int Entity::GetHandle() const
    {
        return handle;
    }

    int Entity::GetHealth() const
    {
        return ENTITY::GET_ENTITY_HEALTH(this->handle);
    }

    int Entity::GetMaxHealth() const
    {
        return ENTITY::GET_ENTITY_MAX_HEALTH(this->handle);
    }

    int Entity::GetBoneIndexByName(const std::string &boneName) const
    {
        return ENTITY::GET_ENTITY_BONE_INDEX_BY_NAME(this->handle, boneName.c_str());
    }

    int Entity::GetOpacity() const
    {
        return ENTITY::GET_ENTITY_ALPHA(this->handle);
    }

    ENTITY_TYPE Entity::GetType() const
    {
        return static_cast<ENTITY_TYPE>(ENTITY::GET_ENTITY_TYPE(this->handle));
    }

    std::unique_ptr<Model> Entity::GetModel() const
    {
        return std::make_unique<Model>(ENTITY::GET_ENTITY_MODEL(this->handle));
    }

    uintptr_t Entity::GetMemoryAddress() const
    {
        return fwScriptGuid::GetBaseFromGuid(this->handle);
    }

    void Entity::SetMaxHealth(int value) const
    {
        ENTITY::SET_ENTITY_MAX_HEALTH(this->handle, value);
    }

    void Entity::SetHealth(int value) const
    {
        ENTITY::SET_ENTITY_HEALTH(this->handle, value, NULL, NULL);
    }

    void Entity::AttachTo(const Entity &entity, int boneId, const Vector3 &offset, const Vector3 &rotation, bool detachWhenDead, bool detachWhenRagdoll, bool activeCollisions, bool useBasicAttachIfPed, EULER_ROT_ORDER rotationOrder, bool attachOffsetIsRelative, bool markAsNoLongerNeededWhenDetached) const
    {
        ENTITY::ATTACH_ENTITY_TO_ENTITY(this->handle, entity.GetHandle(), boneId, offset.x, offset.y, offset.z, rotation.x, rotation.y, rotation.z, detachWhenDead, detachWhenRagdoll, activeCollisions, useBasicAttachIfPed, static_cast<int>(rotationOrder), attachOffsetIsRelative, markAsNoLongerNeededWhenDetached);
    }

    void Entity::Detach(bool applyVelocity, bool noCollisionUntilClear) const
    {
        ENTITY::DETACH_ENTITY(this->handle, applyVelocity, noCollisionUntilClear);
    }

    void Entity::FreezePosition(bool toggle) const
    {
        ENTITY::FREEZE_ENTITY_POSITION(this->handle, toggle);
    }

    void Entity::SetShouldFreezeWaitingOnCollision(bool toggle) const
    {
        ENTITY::SET_ENTITY_SHOULD_FREEZE_WAITING_ON_COLLISION(this->handle, toggle);
    }

    void Entity::MarkAsNoLongerNeeded()
    {
        ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&this->handle);
    }

    void Entity::SetCollision(bool toggle) const
    {
        ENTITY::SET_ENTITY_COLLISION(this->handle, toggle, false);
    }

    void Entity::SetPosition(const Vector3 &position) const
    {
        ENTITY::SET_ENTITY_COORDS(this->handle, position.x, position.y, position.z, false, true, true, false);
    }

    void Entity::SetDynamic(bool toggle) const
    {
        ENTITY::SET_ENTITY_DYNAMIC(this->handle, toggle);
    }

    void Entity::SetHeading(float value) const
    {
        ENTITY::SET_ENTITY_HEADING(this->handle, value);
    }

    void Entity::SetInvincible(bool toggle) const
    {
        ENTITY::SET_ENTITY_INVINCIBLE(this->handle, toggle);
    }

    void Entity::SetMaxSpeed(float value) const
    {
        ENTITY::SET_ENTITY_MAX_SPEED(this->handle, value);
    }

    void Entity::SetRotation(const Vector3 &rotation) const
    {
        ENTITY::SET_ENTITY_ROTATION(this->handle, rotation.x, rotation.y, rotation.z, static_cast<int>(EULER_YXZ), false);
    }

    void Entity::SetVisible(bool toggle) const
    {
        ENTITY::SET_ENTITY_VISIBLE(this->handle, toggle, false);
    }

    void Entity::SetVelocity(const Vector3 &value) const
    {
        ENTITY::SET_ENTITY_VELOCITY(this->handle, value.x, value.y, value.z);
    }

    void Entity::SetOpacity(int value) const
    {
        ENTITY::SET_ENTITY_ALPHA(this->handle, value, true);
    }

    void Entity::SetCollisionIgnoredEntity(const Entity &entity) const
    {
        ENTITY::SET_ENTITY_NO_COLLISION_ENTITY(this->handle, entity.GetHandle(), false);
    }

    void Entity::Delete()
    {
        ENTITY::DELETE_ENTITY(&this->handle);
    }
}
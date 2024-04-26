#ifndef REVENANT_ENTITY_H
#define REVENANT_ENTITY_H

#pragma once

#include "Model.h"

namespace revenant
{
    class Entity
    {
    public:
        Entity();
        Entity(int32_t handle);
        virtual ~Entity() = default;

        bool operator==(int32_t other) const;
        bool operator==(const Entity& other) const;

        static bool Exists(const Entity* entity);
        static bool Exists(int32_t handle);

        [[nodiscard]] bool Exists() const;
        [[nodiscard]] bool IsValid() const;
        [[nodiscard]] bool HasBeenDamagedByAnyObject() const;
        [[nodiscard]] bool HasBeenDamagedByAnyPed() const;
        [[nodiscard]] bool HasBeenDamagedByAnyVehicle() const;
        [[nodiscard]] bool HasBeenDamagedBy(const Entity& entity, bool includeVehicle) const;
        [[nodiscard]] bool CanSee(const Entity& entity, LOS_FLAGS flags) const;
        [[nodiscard]] bool CanSee(Entity& entity) const;
        [[nodiscard]] bool HasCollidedWithAnything() const;
        [[nodiscard]] bool IsPersistent() const;
        [[nodiscard]] bool IsAttached() const;
        [[nodiscard]] bool IsAttachedToAnyObject() const;
        [[nodiscard]] bool IsAttachedToAnyPed() const;
        [[nodiscard]] bool IsAttachedToAnyVehicle() const;
        [[nodiscard]] bool IsAttachedTo(const Entity& entity) const;
        [[nodiscard]] bool IsAlive() const;
        [[nodiscard]] bool IsDead() const;
        [[nodiscard]] bool IsInAir() const;
        [[nodiscard]] bool IsInWater() const;
        [[nodiscard]] bool IsOnScreen() const;
        [[nodiscard]] bool IsStatic() const;
        [[nodiscard]] bool IsTouching(const Entity& entity) const;
        [[nodiscard]] bool IsUpright(float angle) const;
        [[nodiscard]] bool IsUpsideDown() const;
        [[nodiscard]] bool IsVisible() const;
        [[nodiscard]] bool IsOccluded() const;
        [[nodiscard]] bool IsWaitingForCollision() const;
        [[nodiscard]] bool IsCollisionEnabled() const;

        [[nodiscard]] float GetHeading() const;
        [[nodiscard]] float GetHeight() const;
        [[nodiscard]] float GetHeightAboveGround() const;
        [[nodiscard]] float GetSpeed() const;

        [[nodiscard]] std::unique_ptr<Entity> GetEntityAttachedTo() const;

        [[nodiscard]] Vector3 GetPosition() const;
        [[nodiscard]] Vector3 GetForwardVector() const;
        [[nodiscard]] Vector3 GetRearVector() const;
        [[nodiscard]] Vector3 GetRightVector() const;
        [[nodiscard]] Vector3 GetLeftVector() const;
        [[nodiscard]] Vector3 GetUpVector() const;
        [[nodiscard]] Vector3 GetBottomVector() const;
        [[nodiscard]] Vector3 GetPositionOffset(const Vector3& position) const;
        [[nodiscard]] Vector3 GetOffsetPosition(const Vector3& offset) const;
        [[nodiscard]] Vector3 GetRotation() const;
        [[nodiscard]] Vector3 GetVelocity() const;
        [[nodiscard]] Vector3 GetBoneRotation(int boneId) const;
        [[nodiscard]] Vector3 GetBonePosition(int boneId) const;

        [[nodiscard]] int GetHandle() const;
        [[nodiscard]] int GetHealth() const;
        [[nodiscard]] int GetMaxHealth() const;
        [[nodiscard]] int GetBoneIndexByName(const std::string& boneName) const;
        [[nodiscard]] int GetOpacity() const;

        [[nodiscard]] ENTITY_TYPE GetType() const;

        [[nodiscard]] std::unique_ptr<Model> GetModel() const;

        [[nodiscard]] uintptr_t GetMemoryAddress() const;

        void SetMaxHealth(int value) const;
        void SetHealth(int value) const;
        void AttachTo(const Entity& entity, int boneId, const Vector3& offset, const Vector3& rotation, bool detachWhenDead = false, bool detachWhenRagdoll = false, bool activeCollisions = false, bool useBasicAttachIfPed = false, EULER_ROT_ORDER rotationOrder = EULER_YXZ, bool attachOffsetIsRelative = true, bool markAsNoLongerNeededWhenDetached = false) const;
        void Detach(bool applyVelocity = true, bool noCollisionUntilClear = true) const;
        void FreezePosition(bool toggle) const;
        void SetShouldFreezeWaitingOnCollision(bool toggle) const;
        void MarkAsNoLongerNeeded();
        void SetCollision(bool toggle) const;
        void SetPosition(const Vector3& position) const;
        void SetDynamic(bool toggle) const;
        void SetHeading(float value) const;
        void SetInvincible(bool toggle) const;
        void SetMaxSpeed(float value) const;
        void SetRotation(const Vector3& rotation) const;
        void SetVisible(bool toggle) const;
        void SetVelocity(const Vector3& value) const;
        void SetOpacity(int value) const;
        void SetCollisionIgnoredEntity(const Entity& entity) const;
    protected:
        int32_t handle;
    };
}

#endif //REVENANT_ENTITY_H
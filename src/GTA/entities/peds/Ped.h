#ifndef REVENANT_PED_H
#define REVENANT_PED_H

#pragma once

#include "../Entity.h"
#include "../vehicles/Vehicle.h"
#include "TaskInvoker.h"
#include "PedGroup.h"

namespace revenant
{
    class Ped : public Entity
    {
    public:
        Ped(const std::string& modelName, Vector3 position, float heading);
        Ped(Vector3 position);
        Ped(int32_t handle);

        void ClearTasks();
        void ClearSecondaryTask();
        void ClearAllTasks();
        void ClearTasksImmediately();
        void SetPathCanUseClimbovers(bool toggle);
        void SetPathCanUseLadders(bool toggle);
        void SetPathCanDropFromHeight(bool toggle);
        void SetPathMayEnterWater(bool toggle);
        void SetPathPreferToAvoidWater(bool toggle);
        void SetPathAvoidFire(bool toggle);
        void WarpIntoVehicle(const Vehicle& vehicle, VEHICLE_SEAT seat);
        void SetAccuracy(int value);
        void SetArmor(int value);
        void ResetLastVehicle();
        void SetMoney(int value);
        void ClearLastDamageBone();
        void SetIdentificationRange(float value);

        [[nodiscard]] int GetAccuracy() const;
        [[nodiscard]] int GetMoney() const;
        [[nodiscard]] int GetArmor() const;
        [[nodiscard]] int GetTimeOfDeath() const;

        [[nodiscard]] uint32_t GetCauseOfDeath() const;

        [[nodiscard]] PED_BONETAG GetLastDamageBone() const;

        [[nodiscard]] bool IsStill() const;
        [[nodiscard]] bool IsWalking() const;
        [[nodiscard]] bool IsRunning() const;
        [[nodiscard]] bool IsSprinting() const;
        [[nodiscard]] bool IsInVehicle(const Vehicle& vehicle, bool considerEnteringAsInVehicle) const;
        [[nodiscard]] bool IsInAnyVehicle(bool considerEnteringAsInVehicle) const;
        [[nodiscard]] bool IsInjured() const;
        [[nodiscard]] bool IsFatallyInjured() const;
        [[nodiscard]] bool IsHurt() const;
        [[nodiscard]] bool IsReloading() const;
        [[nodiscard]] bool IsPlayer() const;
        [[nodiscard]] bool IsFacing(const Ped& ped, float angle) const;
        [[nodiscard]] bool IsInMeleeCombat() const;
        [[nodiscard]] bool IsStopped() const;
        [[nodiscard]] bool IsShooting() const;
        [[nodiscard]] bool IsMale() const;
        [[nodiscard]] bool IsFemale() const;
        [[nodiscard]] bool IsHuman() const;
        [[nodiscard]] bool IsOnVehicle() const;
        [[nodiscard]] bool IsSittingInVehicle(const Vehicle& vehicle) const;
        [[nodiscard]] bool IsSittingInAnyVehicle() const;
        [[nodiscard]] bool IsOnFoot() const;
        [[nodiscard]] bool IsFalling() const;
        [[nodiscard]] bool IsJumping() const;
        [[nodiscard]] bool IsClimbing() const;
        [[nodiscard]] bool IsVaulting() const;
        [[nodiscard]] bool IsDiving() const;
        [[nodiscard]] bool IsFleeing() const;

        TaskInvoker& GetTaskInvoker();

        [[nodiscard]] std::unique_ptr<PedGroup> GetGroup() const;
        std::unique_ptr<Entity> GetSourceOfDeath();
        [[nodiscard]] std::unique_ptr<Vehicle> GetCurrentVehicle(bool considerEnteringAsInVehicle) const;
    protected:
        TaskInvoker taskInvoker;
    };
}

#endif //REVENANT_PED_H
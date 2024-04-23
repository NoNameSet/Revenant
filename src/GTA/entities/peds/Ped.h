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

        bool IsStill();
        bool IsWalking();
        bool IsRunning();
        bool IsSprinting();

        [[nodiscard]] std::unique_ptr<PedGroup> GetGroup() const;

        TaskInvoker& GetTaskInvoker();
    protected:
        TaskInvoker taskInvoker;
    };
}

#endif //REVENANT_PED_H
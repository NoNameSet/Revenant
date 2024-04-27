#ifndef REVENANT_VEHICLE_H
#define REVENANT_VEHICLE_H

#pragma once

#include "../Entity.h"

namespace revenant
{
    class Vehicle : public Entity
    {
    public:
        Vehicle(const std::string& modelName, Vector3 position, float heading);
        Vehicle(int32_t handle);

        bool IsStuckOnRoof();
        bool IsStopped();

        int GetNumPassengers(bool includeDriver, bool deadPassengers);
        int GetMaxPassengers();
        int GetNumSeats();

        void SetDoorsLockState(LOCK_STATE lockState);
        void SetDoorLockState(int doorId, LOCK_STATE lockState);
    };
}

#endif //REVENANT_VEHICLE_H
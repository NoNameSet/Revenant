#include "Vehicle.h"

namespace revenant
{
    Vehicle::Vehicle(const std::string& modelName, Vector3 position, float heading)
    {
        VEHICLE::CREATE_VEHICLE(MISC::GET_HASH_KEY(modelName.c_str()), position.x, position.y, position.z, heading, false, false, true);
    }

    bool Vehicle::IsStuckOnRoof()
    {
        return VEHICLE::IS_VEHICLE_STUCK_ON_ROOF(this->handle);
    }

    bool Vehicle::IsStopped()
    {
        return VEHICLE::IS_VEHICLE_STOPPED(this->handle);
    }

    int Vehicle::GetNumPassengers(bool includeDriver, bool deadPassengers)
    {
        return VEHICLE::GET_VEHICLE_NUMBER_OF_PASSENGERS(this->handle, includeDriver, deadPassengers);
    }

    int Vehicle::GetMaxPassengers()
    {
        return VEHICLE::GET_VEHICLE_MAX_NUMBER_OF_PASSENGERS(this->handle);
    }

    int Vehicle::GetNumSeats()
    {
        return VEHICLE::GET_VEHICLE_MODEL_NUMBER_OF_SEATS(ENTITY::GET_ENTITY_MODEL(this->handle));
    }

    void Vehicle::SetDoorsLockState(LOCK_STATE lockState)
    {
        VEHICLE::SET_VEHICLE_DOORS_LOCKED(this->handle, static_cast<int>(lockState));
    }

    void Vehicle::SetDoorLockState(int doorId, LOCK_STATE lockState)
    {
        VEHICLE::SET_VEHICLE_INDIVIDUAL_DOORS_LOCKED(this->handle, doorId, static_cast<int>(lockState));
    }
}
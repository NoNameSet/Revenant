#include "Ped.h"

namespace revenant
{
    Ped::Ped(const std::string &modelName, Vector3 position, float heading) : Ped(NULL)
    {
        this->handle = PED::CREATE_PED(26, MISC::GET_HASH_KEY(modelName.c_str()), position.x, position.y, position.z, heading, false, false);
    }

    Ped::Ped(Vector3 position) : Ped(NULL)
    {
        this->handle = PED::CREATE_RANDOM_PED(position.x, position.y, position.z);
    }

    Ped::Ped(int32_t handle) : Entity(handle), taskInvoker(*this)
    {
    }

    void Ped::ClearTasks()
    {
        TASK::CLEAR_PED_TASKS(this->handle);
    }

    void Ped::ClearSecondaryTask()
    {
        TASK::CLEAR_PED_SECONDARY_TASK(this->handle);
    }

    void Ped::ClearAllTasks()
    {
        TASK::CLEAR_PED_TASKS(this->handle);
        TASK::CLEAR_PED_SECONDARY_TASK(this->handle);
    }

    void Ped::ClearTasksImmediately()
    {
        TASK::CLEAR_PED_TASKS_IMMEDIATELY(this->handle);
    }

    void Ped::SetPathCanUseClimbovers(bool toggle)
    {
        TASK::SET_PED_PATH_CAN_USE_CLIMBOVERS(this->handle, toggle);
    }

    void Ped::SetPathCanUseLadders(bool toggle)
    {
        TASK::SET_PED_PATH_CAN_USE_LADDERS(this->handle, toggle);
    }

    void Ped::SetPathCanDropFromHeight(bool toggle)
    {
        TASK::SET_PED_PATH_CAN_DROP_FROM_HEIGHT(this->handle, toggle);
    }

    void Ped::SetPathMayEnterWater(bool toggle)
    {
        TASK::SET_PED_PATH_MAY_ENTER_WATER(this->handle, toggle);
    }

    void Ped::SetPathPreferToAvoidWater(bool toggle)
    {
        TASK::SET_PED_PATH_PREFER_TO_AVOID_WATER(this->handle, toggle);
    }

    void Ped::SetPathAvoidFire(bool toggle)
    {
        TASK::SET_PED_PATH_AVOID_FIRE(this->handle, toggle);
    }

    void Ped::WarpIntoVehicle(const Vehicle &vehicle, VEHICLE_SEAT seat)
    {
        TASK::TASK_WARP_PED_INTO_VEHICLE(this->handle, vehicle.GetHandle(), static_cast<int>(seat));
    }

    bool Ped::IsStill()
    {
        return TASK::IS_PED_STILL(this->handle);
    }

    bool Ped::IsWalking()
    {
        return TASK::IS_PED_WALKING(this->handle);
    }

    bool Ped::IsRunning()
    {
        return TASK::IS_PED_RUNNING(this->handle);
    }

    bool Ped::IsSprinting()
    {
        return TASK::IS_PED_SPRINTING(this->handle);
    }

    std::unique_ptr<PedGroup> Ped::GetGroup() const
    {
        return std::make_unique<PedGroup>(PED::GET_PED_GROUP_INDEX(this->handle));
    }

    TaskInvoker &Ped::GetTaskInvoker()
    {
        return taskInvoker;
    }
}
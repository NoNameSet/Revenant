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

    Ped::Ped(int32_t handle) : Entity(handle), taskInvoker(*this), pedInventory(*this)
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

    void Ped::SetAccuracy(int value)
    {
        PED::SET_PED_ACCURACY(this->handle, value);
    }

    void Ped::SetArmor(int value)
    {
        PED::SET_PED_ARMOUR(this->handle, value);
    }

    void Ped::ResetLastVehicle()
    {
        PED::RESET_PED_LAST_VEHICLE(this->handle);
    }

    void Ped::SetMoney(int value)
    {
        PED::SET_PED_MONEY(this->handle, value);
    }

    void Ped::ClearLastDamageBone()
    {
        PED::CLEAR_PED_LAST_DAMAGE_BONE(this->handle);
    }

    void Ped::SetIdentificationRange(float value)
    {
        PED::SET_PED_ID_RANGE(this->handle, value);
    }

    int Ped::GetAccuracy() const
    {
        return PED::GET_PED_ACCURACY(this->handle);
    }

    int Ped::GetMoney() const
    {
        return PED::GET_PED_MONEY(this->handle);
    }

    int Ped::GetArmor() const
    {
        return PED::GET_PED_ARMOUR(this->handle);
    }

    int Ped::GetTimeOfDeath() const
    {
        return PED::GET_PED_TIME_OF_DEATH(this->handle);
    }

    uint32_t Ped::GetCauseOfDeath() const
    {
        return PED::GET_PED_CAUSE_OF_DEATH(this->handle);
    }

    PED_BONETAG Ped::GetLastDamageBone() const
    {
        int boneId;
        PED::GET_PED_LAST_DAMAGE_BONE(this->handle, &boneId);
        return static_cast<PED_BONETAG>(boneId);
    }

    bool Ped::IsStill() const
    {
        return TASK::IS_PED_STILL(this->handle);
    }

    bool Ped::IsWalking() const
    {
        return TASK::IS_PED_WALKING(this->handle);
    }

    bool Ped::IsRunning() const
    {
        return TASK::IS_PED_RUNNING(this->handle);
    }

    bool Ped::IsSprinting() const
    {
        return TASK::IS_PED_SPRINTING(this->handle);
    }

    bool Ped::IsInVehicle(const Vehicle &vehicle, bool considerEnteringAsInVehicle) const
    {
        return PED::IS_PED_IN_VEHICLE(this->handle, vehicle.GetHandle(), considerEnteringAsInVehicle);
    }

    bool Ped::IsInAnyVehicle(bool considerEnteringAsInVehicle) const
    {
        return PED::IS_PED_IN_ANY_VEHICLE(this->handle, considerEnteringAsInVehicle);
    }

    bool Ped::IsInjured() const
    {
        return PED::IS_PED_INJURED(this->handle);
    }

    bool Ped::IsFatallyInjured() const
    {
        return PED::IS_PED_FATALLY_INJURED(this->handle);
    }

    bool Ped::IsHurt() const
    {
        return PED::IS_PED_HURT(this->handle);
    }

    bool Ped::IsReloading() const
    {
        return PED::IS_PED_RELOADING(this->handle);
    }

    bool Ped::IsPlayer() const
    {
        return PED::IS_PED_A_PLAYER(this->handle);
    }

    bool Ped::IsFacing(const Ped &ped, float angle) const
    {
        return PED::IS_PED_FACING_PED(this->handle, ped.GetHandle(), angle);
    }

    bool Ped::IsInMeleeCombat() const
    {
        return PED::IS_PED_IN_MELEE_COMBAT(this->handle);
    }

    bool Ped::IsStopped() const
    {
        return PED::IS_PED_STOPPED(this->handle);
    }

    bool Ped::IsShooting() const
    {
        return PED::IS_PED_SHOOTING(this->handle);
    }

    bool Ped::IsMale() const
    {
        return PED::IS_PED_MALE(this->handle);
    }

    bool Ped::IsFemale() const
    {
        return !PED::IS_PED_MALE(this->handle);
    }

    bool Ped::IsHuman() const
    {
        return PED::IS_PED_HUMAN(this->handle);
    }

    bool Ped::IsOnVehicle() const
    {
        return PED::IS_PED_ON_VEHICLE(this->handle);
    }

    bool Ped::IsSittingInVehicle(const Vehicle &vehicle) const
    {
        return PED::IS_PED_SITTING_IN_VEHICLE(this->handle, vehicle.GetHandle());
    }

    bool Ped::IsSittingInAnyVehicle() const
    {
        return PED::IS_PED_SITTING_IN_ANY_VEHICLE(this->handle);
    }

    bool Ped::IsOnFoot() const
    {
        return PED::IS_PED_ON_FOOT(this->handle);
    }

    bool Ped::IsFalling() const
    {
        return PED::IS_PED_FALLING(this->handle);
    }

    bool Ped::IsJumping() const
    {
        return PED::IS_PED_JUMPING(this->handle);
    }

    bool Ped::IsClimbing() const
    {
        return PED::IS_PED_CLIMBING(this->handle);
    }

    bool Ped::IsVaulting() const
    {
        return PED::IS_PED_VAULTING(this->handle);
    }

    bool Ped::IsDiving() const
    {
        return PED::IS_PED_DIVING(this->handle);
    }

    bool Ped::IsFleeing() const
    {
        return PED::IS_PED_FLEEING(this->handle);
    }

    TaskInvoker &Ped::GetTaskInvoker()
    {
        return taskInvoker;
    }

    PedInventory &Ped::GetInventory()
    {
        return pedInventory;
    }

    std::unique_ptr<PedGroup> Ped::GetGroup() const
    {
        return std::make_unique<PedGroup>(PED::GET_PED_GROUP_INDEX(this->handle));
    }

    std::unique_ptr<Entity> Ped::GetSourceOfDeath()
    {
        return std::make_unique<Entity>(PED::GET_PED_SOURCE_OF_DEATH(this->handle));
    }

    std::unique_ptr<Vehicle> Ped::GetCurrentVehicle(bool considerEnteringAsInVehicle) const
    {
        return std::make_unique<Vehicle>(PED::GET_VEHICLE_PED_IS_IN(this->handle, false));
    }
}
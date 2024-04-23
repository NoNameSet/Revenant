#ifndef REVENANT_TASKINVOKER_H
#define REVENANT_TASKINVOKER_H

#pragma once

#include "../Entity.h"
#include "../vehicles/Vehicle.h"
#include "Task.h"

namespace revenant
{
    class Ped;

    class TaskInvoker
    {
    public:
        TaskInvoker(Ped& owner);

        std::unique_ptr<Task> StandStill(int duration);
        std::unique_ptr<Task> Jump();
        std::unique_ptr<Task> Cower(int duration);
        std::unique_ptr<Task> OpenVehicleDoor(const Vehicle& vehicle, int timeout, int seatId, float moveBlendRatio);
        std::unique_ptr<Task> EnterVehicle(const Vehicle& vehicle, int timeout, int seatId, float moveBlendRatio, ENTER_EXIT_VEHICLE_FLAGS enterVehicleFlags);
        std::unique_ptr<Task> LeaveVehicle(const Vehicle& vehicle, ENTER_EXIT_VEHICLE_FLAGS exitVehicleFlags);
        std::unique_ptr<Task> DriveToPosition(const Vehicle& vehicle, const Vector3& position, float speed, DRIVINGSTYLE style, DRIVINGMODE mode, float targetRadius, float straightLineDistance);
        std::unique_ptr<Task> DriveToPositionLongRange(const Vehicle& vehicle, const Vector3& position, float speed, DRIVINGMODE mode, float targetRadius);
        std::unique_ptr<Task> DriveWander(const Vehicle& vehicle, float speed, DRIVINGMODE mode);
        std::unique_ptr<Task> FollowToOffsetOfEntity(const Entity& entity, const Vector3& offset, float moveBlendRatio, int timeout, float targetRadius, bool relativeOffset);
        std::unique_ptr<Task> GoStraightToPosition(const Vector3& position, float moveBlendRatio, int timeout, float targetHeading, float targetRadius);
        std::unique_ptr<Task> GoToEntity(const Entity& entity, int timeout, float targetRadius, float moveBlendRation, float slowDownDistance, EGOTO_ENTITY_FLAGS flags);
        std::unique_ptr<Task> AchieveHeading(float heading, int timeout);
        std::unique_ptr<Task> WanderInArea(const Vector3& position, float radius, float minWaitTime, float maxWaitTime);
        std::unique_ptr<Task> FollowNavmeshToPosition(const Vector3& position, float moveBlendRatio, int timeout, float targetRadius, ENAV_SCRIPT_FLAGS flags, float targetHeading);
        std::unique_ptr<Task> PlayAnimation(const std::string& animationDictionary, const std::string& animationName, float blendInSpeed, float blendOutSpeed, int duration, ANIMATION_FLAGS animationFlags, float startPhase, IK_CONTROL_FLAGS controlFlags);
        std::unique_ptr<Task> LookAt(const Vector3& position, int duration, SCRIPT_LOOK_FLAG lookFlag, SCRIPT_LOOK_PRIORITY priorityFlag);
        std::unique_ptr<Task> LookAt(const Entity& entity, int duration, SCRIPT_LOOK_FLAG lookFlag, SCRIPT_LOOK_PRIORITY priorityFlag);
        std::unique_ptr<Task> TalkTo(const Ped& ped, CHAT_FLAGS flags, Vector3 optionalGoToPosition, float optionalHeading, float idleTime);
        std::unique_ptr<Task> ShootAt(const Entity& entity, int duration, FIRING_TYPE firingType);
        std::unique_ptr<Task> CombatPed(const Ped& ped, TASK_COMBAT_PED_FLAGS combatFlags, TASK_THREAT_RESPONSE_FLAGS threatResponseFlags);

        SCRIPTTASKSTATUS GetStatus();
    private:
        Ped* const owner;
    };
}

#endif //REVENANT_TASKINVOKER_H
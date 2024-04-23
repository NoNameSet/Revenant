#include "TaskInvoker.h"
#include "CPed.h"
#include "Ped.h"

namespace revenant
{
    TaskInvoker::TaskInvoker(Ped &owner) : owner(&owner)
    {
    }

    std::unique_ptr<Task> TaskInvoker::StandStill(int duration)
    {
        TASK::TASK_STAND_STILL(owner->GetHandle(), duration);
        auto task = std::make_unique<Task>(*owner, MISC::GET_HASH_KEY("SCRIPT_TASK_STAND_STILL"));
        return task;
    }

    std::unique_ptr<Task> TaskInvoker::Jump()
    {
        TASK::TASK_JUMP(owner->GetHandle(), false, false, false);
        auto task = std::make_unique<Task>(*owner, MISC::GET_HASH_KEY("SCRIPT_TASK_JUMP"));
        return task;
    }

    std::unique_ptr<Task> TaskInvoker::Cower(int duration)
    {
        TASK::TASK_COWER(owner->GetHandle(), duration);
        auto task = std::make_unique<Task>(*owner, MISC::GET_HASH_KEY("SCRIPT_TASK_COWER"));
        return task;
    }

    std::unique_ptr<Task> TaskInvoker::OpenVehicleDoor(const Vehicle& vehicle, int timeout, int doorId, float moveBlendRatio)
    {
        TASK::TASK_OPEN_VEHICLE_DOOR(owner->GetHandle(), vehicle.GetHandle(), timeout, doorId, moveBlendRatio);
        auto task = std::make_unique<Task>(*owner, MISC::GET_HASH_KEY("SCRIPT_TASK_ENTER_VEHICLE"));
        return task;
    }

    std::unique_ptr<Task> TaskInvoker::EnterVehicle(const Vehicle& vehicle, int timeout, int seatId, float moveBlendRatio, ENTER_EXIT_VEHICLE_FLAGS enterVehicleFlags)
    {
        TASK::TASK_ENTER_VEHICLE(owner->GetHandle(), vehicle.GetHandle(), timeout, seatId, moveBlendRatio, static_cast<int>(enterVehicleFlags), NULL);
        auto task = std::make_unique<Task>(*owner, MISC::GET_HASH_KEY("SCRIPT_TASK_ENTER_VEHICLE"));
        return task;
    }

    std::unique_ptr<Task> TaskInvoker::LeaveVehicle(const Vehicle &vehicle, ENTER_EXIT_VEHICLE_FLAGS exitVehicleFlags)
    {
        TASK::TASK_LEAVE_VEHICLE(owner->GetHandle(), vehicle.GetHandle(), static_cast<int>(exitVehicleFlags));
        auto task = std::make_unique<Task>(*owner, MISC::GET_HASH_KEY("SCRIPT_TASK_LEAVE_VEHICLE"));
        return task;
    }

    std::unique_ptr<Task> TaskInvoker::DriveToPosition(const Vehicle &vehicle, const Vector3 &position, float speed, DRIVINGSTYLE style, DRIVINGMODE mode, float targetRadius, float straightLineDistance)
    {
        TASK::TASK_VEHICLE_DRIVE_TO_COORD(owner->GetHandle(), vehicle.GetHandle(), position.x, position.y, position.z, speed, static_cast<int>(style), ENTITY::GET_ENTITY_MODEL(vehicle.GetHandle()), static_cast<int>(mode), targetRadius, straightLineDistance);
        auto task = std::make_unique<Task>(*owner, MISC::GET_HASH_KEY("SCRIPT_TASK_VEHICLE_DRIVE_TO_COORD"));
        return task;
    }

    std::unique_ptr<Task> TaskInvoker::DriveToPositionLongRange(const Vehicle &vehicle, const Vector3 &position, float speed, DRIVINGMODE mode, float targetRadius)
    {
        TASK::TASK_VEHICLE_DRIVE_TO_COORD_LONGRANGE(owner->GetHandle(), vehicle.GetHandle(), position.x, position.y, position.z, speed, static_cast<int>(mode), targetRadius);
        auto task = std::make_unique<Task>(*owner, MISC::GET_HASH_KEY("SCRIPT_TASK_VEHICLE_DRIVE_TO_COORD_LONGRANGE"));
        return task;
    }

    std::unique_ptr<Task> TaskInvoker::DriveWander(const Vehicle &vehicle, float speed, DRIVINGMODE mode)
    {
        TASK::TASK_VEHICLE_DRIVE_WANDER(owner->GetHandle(), vehicle.GetHandle(), speed, static_cast<int>(mode));
        auto task = std::make_unique<Task>(*owner, MISC::GET_HASH_KEY("SCRIPT_TASK_VEHICLE_DRIVE_WANDER"));
        return task;
    }

    std::unique_ptr<Task> TaskInvoker::FollowToOffsetOfEntity(const Entity &entity, const Vector3 &offset, float moveBlendRatio, int timeout, float targetRadius, bool relativeOffset)
    {
        TASK::TASK_FOLLOW_TO_OFFSET_OF_ENTITY(owner->GetHandle(), entity.GetHandle(), offset.x, offset.y, offset.z, moveBlendRatio, timeout, targetRadius, relativeOffset);
        auto task = std::make_unique<Task>(*owner, MISC::GET_HASH_KEY("SCRIPT_TASK_FOLLOW_TO_OFFSET_OF_ENTITY"));
        return task;
    }

    std::unique_ptr<Task> TaskInvoker::GoStraightToPosition(const Vector3 &position, float moveBlendRatio, int timeout, float targetHeading, float targetRadius)
    {
        TASK::TASK_GO_STRAIGHT_TO_COORD(owner->GetHandle(), position.x, position.y, position.z, moveBlendRatio, timeout, targetHeading, targetRadius);
        auto task = std::make_unique<Task>(*owner, MISC::GET_HASH_KEY("SCRIPT_TASK_GO_STRAIGHT_TO_COORD"));
        return task;
    }

    std::unique_ptr<Task> TaskInvoker::GoToEntity(const Entity &entity, int timeout, float targetRadius, float moveBlendRation, float slowDownDistance, EGOTO_ENTITY_FLAGS flags)
    {
        TASK::TASK_GO_TO_ENTITY(owner->GetHandle(), entity.GetHandle(), timeout, targetRadius, moveBlendRation, slowDownDistance, static_cast<int>(flags));
        auto task = std::make_unique<Task>(*owner, MISC::GET_HASH_KEY("SCRIPT_TASK_GO_TO_ENTITY"));
        return task;
    }

    std::unique_ptr<Task> TaskInvoker::AchieveHeading(float heading, int timeout)
    {
        TASK::TASK_ACHIEVE_HEADING(owner->GetHandle(), heading, timeout);
        auto task = std::make_unique<Task>(*owner, MISC::GET_HASH_KEY("SCRIPT_TASK_ACHIEVE_HEADING"));
        return task;
    }

    std::unique_ptr<Task> TaskInvoker::WanderInArea(const Vector3 &position, float radius, float minWaitTime, float maxWaitTime)
    {
        TASK::TASK_WANDER_IN_AREA(owner->GetHandle(), position.x, position.y, position.z, radius, minWaitTime, maxWaitTime);
        auto task = std::make_unique<Task>(*owner, MISC::GET_HASH_KEY("SCRIPT_TASK_WANDER_IN_AREA"));
        return task;
    }

    std::unique_ptr<Task> TaskInvoker::FollowNavmeshToPosition(const Vector3 &position, float moveBlendRatio, int timeout, float targetRadius, ENAV_SCRIPT_FLAGS flags, float targetHeading)
    {
        TASK::TASK_FOLLOW_NAV_MESH_TO_COORD(owner->GetHandle(), position.x, position.y, position.z, moveBlendRatio, timeout, targetRadius, static_cast<int>(flags), targetHeading);
        auto task = std::make_unique<Task>(*owner, MISC::GET_HASH_KEY("TASK_FOLLOW_NAV_MESH_TO_COORD"));
        return task;
    }

    std::unique_ptr<Task> TaskInvoker::PlayAnimation(const std::string &animationDictionary, const std::string &animationName, float blendInSpeed, float blendOutSpeed, int duration, ANIMATION_FLAGS animationFlags, float startPhase, IK_CONTROL_FLAGS controlFlags)
    {
        TASK::TASK_PLAY_ANIM(owner->GetHandle(), animationDictionary.c_str(), animationName.c_str(), blendInSpeed, blendOutSpeed, duration, static_cast<int>(animationFlags), startPhase, false, static_cast<int>(controlFlags), false);
        auto task = std::make_unique<Task>(*owner, MISC::GET_HASH_KEY("SCRIPT_TASK_PLAY_ANIM"));
        return task;
    }

    std::unique_ptr<Task> TaskInvoker::LookAt(const Vector3 &position, int duration, SCRIPT_LOOK_FLAG lookFlag, SCRIPT_LOOK_PRIORITY priorityFlag)
    {
        TASK::TASK_LOOK_AT_COORD(owner->GetHandle(), position.x, position.y, position.z, duration, static_cast<int>(lookFlag), static_cast<int>(priorityFlag));
        auto task = std::make_unique<Task>(*owner, MISC::GET_HASH_KEY("SCRIPT_TASK_LOOK_AT_COORD"));
        return task;
    }

    std::unique_ptr<Task> TaskInvoker::LookAt(const Entity &entity, int duration, SCRIPT_LOOK_FLAG lookFlag, SCRIPT_LOOK_PRIORITY priorityFlag)
    {
        TASK::TASK_LOOK_AT_ENTITY(owner->GetHandle(), entity.GetHandle(), duration, static_cast<int>(lookFlag), static_cast<int>(priorityFlag));
        auto task = std::make_unique<Task>(*owner, MISC::GET_HASH_KEY("SCRIPT_TASK_LOOK_AT_ENTITY"));
        return task;
    }

    std::unique_ptr<Task> TaskInvoker::TalkTo(const revenant::Ped &ped, CHAT_FLAGS flags, Vector3 optionalGoToPosition, float optionalHeading, float idleTime)
    {
        TASK::TASK_CHAT_TO_PED(owner->GetHandle(), ped.GetHandle(), static_cast<int>(flags), optionalGoToPosition.x, optionalGoToPosition.y, optionalGoToPosition.z, optionalHeading, idleTime);
        auto task = std::make_unique<Task>(*owner, MISC::GET_HASH_KEY("SCRIPT_TASK_CHAT_TO_PED"));
        return task;
    }

    std::unique_ptr<Task> TaskInvoker::ShootAt(const Entity &entity, int duration, FIRING_TYPE firingType)
    {
        TASK::TASK_SHOOT_AT_ENTITY(owner->GetHandle(), entity.GetHandle(), duration, static_cast<Hash>(firingType));
        auto task = std::make_unique<Task>(*owner, MISC::GET_HASH_KEY("SCRIPT_TASK_SHOOT_AT_ENTITY"));
        return task;
    }

    std::unique_ptr<Task> TaskInvoker::CombatPed(const Ped &ped, TASK_COMBAT_PED_FLAGS combatFlags, TASK_THREAT_RESPONSE_FLAGS threatResponseFlags)
    {
        TASK::TASK_COMBAT_PED(owner->GetHandle(), ped.GetHandle(), static_cast<int>(combatFlags), static_cast<int>(threatResponseFlags));
        auto task = std::make_unique<Task>(*owner, MISC::GET_HASH_KEY("SCRIPT_TASK_COMBAT"));
        return task;
    }

    SCRIPTTASKSTATUS TaskInvoker::GetStatus()
    {
        CPed* pPed = (CPed*) this->owner->GetMemoryAddress();

        if (pPed == nullptr)
            return FINISHED_TASK;

        CPedIntelligence* nIntellOffset = pPed->GetIntelligence();

        if (nIntellOffset == nullptr)
            return FINISHED_TASK;

        CQueriableInterface* nQueryOffset = nIntellOffset->GetQueryableInterface();

        if (nQueryOffset == nullptr)
            return FINISHED_TASK;

        return static_cast<SCRIPTTASKSTATUS>(nQueryOffset->m_iScriptTaskStage);
    }
}
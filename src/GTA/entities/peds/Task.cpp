#include "Task.h"
#include "Ped.h"

namespace revenant
{
    Task::Task(Ped &owner, int taskId) : owner(&owner), taskId(taskId)
    {
    }

    bool Task::IsActive()
    {
        SCRIPTTASKSTATUS status = this->GetStatus();
        return status == PERFORMING_TASK;
    }

    SCRIPTTASKSTATUS Task::GetStatus()
    {
        return static_cast<SCRIPTTASKSTATUS>(TASK::GET_SCRIPT_TASK_STATUS(owner->GetHandle(), taskId));
    }
}
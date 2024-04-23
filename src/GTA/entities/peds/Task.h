#ifndef REVENANT_TASK_H
#define REVENANT_TASK_H

#pragma once

namespace revenant
{
    class Ped;

    class Task
    {
    public:
        Task(Ped& owner, int taskId);

        bool IsActive();

        SCRIPTTASKSTATUS GetStatus();
    private:
        Ped* owner;
        int taskId;
    };
}

#endif //REVENANT_TASK_H
#ifndef REVENANT_PEDGROUP_H
#define REVENANT_PEDGROUP_H

#pragma once

namespace revenant
{
    class Ped;

    class PedGroup
    {
    public:
        PedGroup();
        PedGroup(int32_t handle);
        virtual ~PedGroup() = default;

        bool operator==(int32_t other) const;
        bool operator==(const PedGroup& other) const;

        [[nodiscard]] int GetHandle() const;

        [[nodiscard]] bool IsMember(const Ped& ped) const;
        [[nodiscard]] bool Exists() const;
        [[nodiscard]] bool IsValid() const;

        static bool Exists(const PedGroup* group);
        static bool Exists(int32_t handle);

        [[nodiscard]] int GetSize() const;

        void SetLeader(const Ped& ped) const;
        void AddMember(const Ped& ped) const;
        void RemoveMember(const Ped& ped);
        void SetCanTeleportToLeader(const Ped& ped, bool toggle) const;
        void SetNeverLeavesGroup(const Ped& ped, bool toggle);
        void Remove() const;

        [[nodiscard]] std::unique_ptr<Ped> GetLeader() const;
        [[nodiscard]] std::unique_ptr<Ped> GetMember(int member) const;
    private:
        int32_t handle;
    };
}

#endif //REVENANT_PEDGROUP_H
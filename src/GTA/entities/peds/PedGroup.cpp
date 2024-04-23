#include "PedGroup.h"
#include "Ped.h"

namespace revenant
{
    PedGroup::PedGroup()
    {
        this->handle = PED::CREATE_GROUP(NULL);
    }

    PedGroup::PedGroup(int32_t handle)
    {
        this->handle = handle;
    }

    bool PedGroup::operator==(int32_t other) const
    {
        return Exists() && Exists(other) && this->handle == other;
    }

    bool PedGroup::operator==(const PedGroup &other) const
    {
        return Exists() && Exists(other.handle) && this->handle == other.handle;
    }

    int PedGroup::GetHandle() const
    {
        return this->handle;
    }

    bool PedGroup::IsMember(const Ped &ped) const
    {
        return PED::IS_PED_GROUP_MEMBER(ped.GetHandle(), this->handle);
    }

    bool PedGroup::Exists() const
    {
        return PED::DOES_GROUP_EXIST(this->handle);
    }

    bool PedGroup::IsValid() const
    {
        return this->Exists() && this->handle != 0;
    }

    bool PedGroup::Exists(const PedGroup *group)
    {
        return group != nullptr && PED::DOES_GROUP_EXIST(group->handle);
    }

    bool PedGroup::Exists(int32_t handle)
    {
        return PED::DOES_GROUP_EXIST(handle);
    }

    int PedGroup::GetSize() const
    {
        int hasLeader, numMembers;
        PED::GET_GROUP_SIZE(this->handle, &hasLeader, &numMembers);
        return numMembers;
    }

    void PedGroup::SetLeader(const Ped &ped) const
    {
        PED::SET_PED_AS_GROUP_LEADER(ped.GetHandle(), this->handle);
    }

    void PedGroup::AddMember(const Ped &ped) const
    {
        PED::SET_PED_AS_GROUP_MEMBER(ped.GetHandle(), this->handle);
    }

    void PedGroup::RemoveMember(const Ped &ped)
    {
        PED::REMOVE_PED_FROM_GROUP(ped.GetHandle());
    }

    void PedGroup::SetCanTeleportToLeader(const Ped &ped, bool toggle) const
    {
        PED::SET_PED_CAN_TELEPORT_TO_GROUP_LEADER(ped.GetHandle(), this->handle, toggle);
    }

    void PedGroup::SetNeverLeavesGroup(const Ped &ped, bool toggle)
    {
        PED::SET_PED_NEVER_LEAVES_GROUP(ped.GetHandle(), toggle);
    }

    void PedGroup::Remove() const
    {
        PED::REMOVE_GROUP(this->handle);
    }

    std::unique_ptr<Ped> PedGroup::GetLeader() const
    {
        return std::make_unique<Ped>(PED::GET_PED_AS_GROUP_LEADER(this->handle));
    }

    std::unique_ptr<Ped> PedGroup::GetMember(int member) const
    {
        return std::make_unique<Ped>(PED::GET_PED_AS_GROUP_MEMBER(this->handle, member));
    }
}
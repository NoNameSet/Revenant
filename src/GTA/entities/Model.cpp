#include "Model.h"

namespace revenant
{
    Model::Model(uint32_t modelHash)
    {
        this->modelHash = modelHash;
    }

    Model::Model(const std::string &modelName)
    {
        this->modelHash = MISC::GET_HASH_KEY(modelName.c_str());
    }

    bool Model::operator==(const std::string &other) const
    {
        return this->modelHash == MISC::GET_HASH_KEY(other.c_str());
    }

    bool Model::operator==(const revenant::Model &other) const
    {
        return this->modelHash == other.modelHash;
    }

    bool Model::IsLoaded() const
    {
        return STREAMING::HAS_MODEL_LOADED(this->modelHash);
    }

    bool Model::IsValid() const
    {
        return STREAMING::IS_MODEL_VALID(this->modelHash);
    }

    bool Model::IsBike() const
    {
        return VEHICLE::IS_THIS_MODEL_A_BIKE(this->modelHash);
    }

    bool Model::IsBoat() const
    {
        return VEHICLE::IS_THIS_MODEL_A_BOAT(this->modelHash);
    }

    bool Model::IsJetski() const
    {
        return VEHICLE::IS_THIS_MODEL_A_JETSKI(this->modelHash);
    }

    bool Model::IsPlane() const
    {
        return VEHICLE::IS_THIS_MODEL_A_PLANE(this->modelHash);
    }

    bool Model::IsHeli() const
    {
        return VEHICLE::IS_THIS_MODEL_A_HELI(this->modelHash);
    }

    bool Model::IsCar() const
    {
        return VEHICLE::IS_THIS_MODEL_A_CAR(this->modelHash);
    }

    bool Model::IsTrain() const
    {
        return VEHICLE::IS_THIS_MODEL_A_TRAIN(this->modelHash);
    }

    bool Model::IsBicycle() const
    {
        return VEHICLE::IS_THIS_MODEL_A_BICYCLE(this->modelHash);
    }

    bool Model::IsQuadbike() const
    {
        return VEHICLE::IS_THIS_MODEL_A_QUADBIKE(this->modelHash);
    }

    bool Model::IsAmphibiousCar() const
    {
        return VEHICLE::IS_THIS_MODEL_AN_AMPHIBIOUS_CAR(this->modelHash);
    }

    bool Model::IsAmphibiousQuadBike() const
    {
        return VEHICLE::IS_THIS_MODEL_AN_AMPHIBIOUS_QUADBIKE(this->modelHash);
    }

    bool Model::IsPed() const
    {
        return STREAMING::IS_MODEL_A_PED(this->modelHash);
    }

    bool Model::IsVehicle() const
    {
        return STREAMING::IS_MODEL_A_VEHICLE(this->modelHash);
    }

    uint32_t Model::GetModelHash() const
    {
        return this->modelHash;
    }

    void Model::Dispose() const
    {
        STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(this->modelHash);
    }
}
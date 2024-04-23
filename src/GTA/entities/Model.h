#ifndef REVENANT_MODEL_H
#define REVENANT_MODEL_H

namespace revenant
{
    class Model
    {
    public:
        Model(uint32_t modelHash);
        Model(const std::string& modelName);

        bool operator==(const std::string& other) const;
        bool operator==(const Model& other) const;

        [[nodiscard]] bool IsLoaded() const;
        [[nodiscard]] bool IsValid() const;

        [[nodiscard]] bool IsBike() const;
        [[nodiscard]] bool IsBoat() const;
        [[nodiscard]] bool IsJetski() const;
        [[nodiscard]] bool IsPlane() const;
        [[nodiscard]] bool IsHeli() const;
        [[nodiscard]] bool IsCar() const;
        [[nodiscard]] bool IsTrain() const;
        [[nodiscard]] bool IsBicycle() const;
        [[nodiscard]] bool IsQuadbike() const;
        [[nodiscard]] bool IsAmphibiousCar() const;
        [[nodiscard]] bool IsAmphibiousQuadBike() const;
        [[nodiscard]] bool IsPed() const;
        [[nodiscard]] bool IsVehicle() const;

        uint32_t GetModelHash();

        void Dispose() const;

    private:
        uint32_t modelHash;
    };
}

#endif //REVENANT_MODEL_H
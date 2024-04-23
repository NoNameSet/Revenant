#ifndef REVENANT_ENTITY_H
#define REVENANT_ENTITY_H

#pragma once

#include "Model.h"

namespace revenant
{
    class Entity
    {
    public:
        Entity();
        Entity(int32_t handle);
        virtual ~Entity() = default;

        bool operator==(int32_t other) const;
        bool operator==(const Entity& other) const;

        static bool Exists(const Entity* entity);
        static bool Exists(int32_t handle);

        [[nodiscard]] bool Exists() const;
        [[nodiscard]] bool IsValid() const;

        [[nodiscard]] int GetHandle() const;

        std::unique_ptr<Model> GetModel();

        [[nodiscard]] uintptr_t GetMemoryAddress() const;
    protected:
        int32_t handle;
    };
}

#endif //REVENANT_ENTITY_H
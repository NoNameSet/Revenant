#ifndef REVENANT_PROP_H
#define REVENANT_PROP_H

#pragma once

#include "Entity.h"

namespace revenant
{
    class Prop : public Entity
    {
    public:
        Prop(const std::string& modelName, Vector3 position);

        void PlaceOnGroundProperly();
        void PlaceOnGroundOrObjectProperly();

        bool IsVisible();
        bool IsBroken();
        bool IsDestroyed();
    };
}

#endif //REVENANT_PROP_H
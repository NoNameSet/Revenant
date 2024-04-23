#include "Prop.h"

namespace revenant
{
    Prop::Prop(const std::string &modelName, Vector3 position)
    {
        this->handle = OBJECT::CREATE_OBJECT(MISC::GET_HASH_KEY(modelName.c_str()), position.x, position.y, position.z, false, false, true);
    }

    void Prop::PlaceOnGroundProperly()
    {
        OBJECT::PLACE_OBJECT_ON_GROUND_PROPERLY(this->handle);
    }

    void Prop::PlaceOnGroundOrObjectProperly()
    {
        OBJECT::PLACE_OBJECT_ON_GROUND_OR_OBJECT_PROPERLY(this->handle);
    }

    bool Prop::IsVisible()
    {
        return OBJECT::IS_OBJECT_VISIBLE(this->handle);
    }

    bool Prop::IsBroken()
    {
        return OBJECT::HAS_OBJECT_BEEN_BROKEN(this->handle, false);
    }

    bool Prop::IsDestroyed()
    {
        return OBJECT::GET_HAS_OBJECT_BEEN_COMPLETELY_DESTROYED(this->handle);
    }
}
#ifndef REVENANT_PLAYER_H
#define REVENANT_PLAYER_H

#pragma once

#include "../entities/peds/Ped.h"

namespace revenant
{
    class Player
    {
    public:
        static std::unique_ptr<Ped> GetCharacter();
    };
}

#endif //REVENANT_PLAYER_H
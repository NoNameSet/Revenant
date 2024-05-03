#ifndef REVENANT_SOUND_H
#define REVENANT_SOUND_H

#pragma once

#include "entities/Entity.h"

namespace revenant
{
    class Sound
    {
    public:
        Sound();
        Sound(int handle);

        static int GetId();

        static bool RequestAudioBank(const char* name);

        [[nodiscard]] bool IsFinished() const;

        void Stop() const;
        void Release() const;
        void Play(const char* soundName, const char* setName) const;
        void PlayFrontend(const char* soundName, const char* setName) const;
        void PlayFromEntity(const char* soundName, const char* setName, const Entity& entity) const;
        void PlayFromPosition(const char* soundName, const Vector3& position, const char* setName);
        void UpdatePosition(const Vector3& position);
    private:
        int id;
    };
}

#endif //REVENANT_SOUND_H
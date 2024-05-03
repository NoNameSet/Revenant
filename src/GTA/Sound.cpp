#include "Sound.h"

namespace revenant
{
    Sound::Sound() : Sound(GetId())
    {
    }

    Sound::Sound(int id)
    {
        this->id = id;
    }

    bool Sound::RequestAudioBank(const char *name)
    {
        return AUDIO::REQUEST_SCRIPT_AUDIO_BANK(name, false, -1);
    }

    int Sound::GetId()
    {
        return AUDIO::GET_SOUND_ID();
    }

    bool Sound::IsFinished() const
    {
        return AUDIO::HAS_SOUND_FINISHED(this->id);
    }

    void Sound::Stop() const
    {
        AUDIO::STOP_SOUND(this->id);
    }

    void Sound::Release() const
    {
        AUDIO::RELEASE_SOUND_ID(this->id);
    }

    void Sound::Play(const char *soundName, const char *setName) const
    {
        AUDIO::PLAY_SOUND(this->id, soundName, setName == NULL ? NULL : setName, false, false, true);
    }

    void Sound::PlayFrontend(const char *soundName, const char *setName) const
    {
        AUDIO::PLAY_SOUND_FRONTEND(this->id, soundName, setName == NULL ? NULL : setName, true);
    }

    void Sound::PlayFromEntity(const char *soundName, const char *setName, const Entity &entity) const
    {
        AUDIO::PLAY_SOUND_FROM_ENTITY(this->id, soundName, entity.GetHandle(), setName == NULL ? NULL : setName, false, 0);
    }

    void Sound::PlayFromPosition(const char *soundName, const Vector3 &position, const char *setName)
    {
        AUDIO::PLAY_SOUND_FROM_COORD(this->id, soundName, position.x, position.y, position.z, setName == NULL ? NULL : setName, false, 0, true);
    }

    void Sound::UpdatePosition(const Vector3 &position)
    {
        AUDIO::UPDATE_SOUND_COORD(this->id, position.x, position.y, position.z);
    }
}
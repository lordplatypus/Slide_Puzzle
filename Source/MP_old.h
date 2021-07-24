#ifndef MP_H_
#define MP_H_
#include <SFML/Audio.hpp>

class MP
{
public:
    MP();
    ~MP();
    //Music
    static int SetMusic(const int key, const std::string& filePath);
    static void PlayMusic(const int key);
    static void PlayMusic(const int key, const bool loop);
    static void PauseMusic(const int key);
    static void StopMusic(const int key);
    static void LoopMusic(const int key, const bool loop);
    static void RemoveMusic(const int key);
    static void ClearMusic();

    //Sound Effects
    static int SetSound(const int key, const std::string& filePath);
    static void PlaySound(const int key);
    static void PlaySound(const int key, const bool loop);
    static void PauseSound(const int key);
    static void StopSound(const int key);
    static void LoopSound(const int key, const bool loop);
    static void RemoveSound(const int key);
    static void ClearSound();
};

#endif
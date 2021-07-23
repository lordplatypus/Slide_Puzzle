#include "MP.h"
#include <unordered_map>

std::unordered_map<int, sf::Music> musicMap_;
std::unordered_map<int, sf::SoundBuffer> bufferMap_;
std::unordered_map<int, sf::Sound> soundMap_;

MP::MP()
{}

MP::~MP()
{}


//Music

int MP::SetMusic(const int key, const std::string& filePath)
{
    musicMap_[key].openFromFile(filePath);
}

void MP::PlayMusic(const int key)
{
    musicMap_[key].play();
}

void MP::PlayMusic(const int key, const bool loop)
{ 
    musicMap_[key].play();
    musicMap_[key].setLoop(loop);
}

void MP::PauseMusic(const int key)
{
    musicMap_[key].pause();
}

void MP::StopMusic(const int key)
{
    musicMap_[key].stop();
}

void MP::LoopMusic(const int key, const bool loop)
{
    musicMap_[key].setLoop(loop);
}

void MP::RemoveMusic(const int key)
{
    if (musicMap_[key].getStatus() == musicMap_[key].Playing) StopMusic(key);
    soundMap_.erase(key);
}

void MP::ClearMusic()
{
    musicMap_.clear();
}


//Sound Effects

int MP::SetSound(const int key, const std::string& filePath)
{
    bufferMap_[key].loadFromFile(filePath);
    soundMap_[key].setBuffer(bufferMap_[key]);
}

void MP::PlaySound(const int key)
{
    soundMap_[key].play();
}

void MP::PlaySound(const int key, const bool loop)
{
    soundMap_[key].play();
    soundMap_[key].setLoop(loop);
}

void MP::PauseSound(const int key)
{
    soundMap_[key].pause();
}

void MP::StopSound(const int key)
{
    soundMap_[key].stop();
}

void MP::LoopSound(const int key, const bool loop)
{
    soundMap_[key].setLoop(loop);
}

void MP::RemoveSound(const int key)
{
    if (soundMap_[key].getStatus() == soundMap_[key].Playing) StopSound(key);
    soundMap_.erase(key);
    bufferMap_.erase(key);
}

void MP::ClearSound()
{
    soundMap_.clear();
    bufferMap_.clear();
}
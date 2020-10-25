#include "MusicPlayer.h"
#include "ID.h" //Music ID

MusicPlayer::MusicPlayer()
{
    //music_[music_ID].openFromFile("File_Path");
}

MusicPlayer::~MusicPlayer()
{}

void MusicPlayer::PlayMusic(const int musicID, const bool loop)
{
    music_[musicID].setLoop(loop);
    music_[musicID].play();
}
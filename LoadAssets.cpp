#include <iostream>
#include <SFML/Graphics.hpp>
#include "LoadAssets.h"
#include "ID.h"
#include "LP.h"
#include "MP.h"

LoadAssets::LoadAssets()
{}

LoadAssets::~LoadAssets()
{}

void LoadAssets::Load()
{
    LoadImage();
    LoadSound();
}

void LoadAssets::LoadImage()
{
    // LP::SetFont("Path to Font");
    // LP::SetTexture(Texture Key, "Path to texture", texture width, texture height);
    LP::SetTexture(pic_texture_, "./pic.png", 1920, 1080);
    LP::SetFont("./Blue Sky 8x8.ttf");
}

void LoadAssets::LoadSound()
{
    // MP::SetMusic(Music Key, "Path to music");
    // MP::SetSound(Sound Key, "Path to sound clip");
}
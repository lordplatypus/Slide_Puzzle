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

const bool LoadAssets::AddImage(const std::string& filePath)
{
    return LP::SetTexture(image_texture_, filePath);
}

void LoadAssets::LoadImage()
{
    // LP::SetFont("Path to Font");
    // LP::SetTexture(Texture Key, "Path to texture", texture width, texture height);
    LP::SetTexture(image_texture_, "./image.png");
    LP::SetFont("./Blue Sky 8x8.ttf");
}

void LoadAssets::LoadSound()
{
    // MP::SetMusic(Music Key, "Path to music");
    // MP::SetSound(Sound Key, "Path to sound clip");
}
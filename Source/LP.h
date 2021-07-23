#ifndef LP_H_
#define LP_H_
#include <SFML/Graphics.hpp>
#include <vector>
#include <unordered_map>
#include "TileMap.h"

class LP
{
public:
    //Sprite
    static bool SetTexture(const int textureKey, const std::string& filePath);
    static bool SetTexture(const int textureKey, const std::string& filePath, int width, int height);
    static sf::Texture GetTexture(const int textureKey);
    static sf::Sprite SetSprite(const int textureKey, const sf::Vector2f& position = sf::Vector2f(0.0f, 0.0f));
    static sf::Sprite SetSprite(const int textureKey, const int cellWidth, const int cellHeight, const int cellID, const sf::Vector2f& position = sf::Vector2f(0.0f, 0.0f));
    static std::vector<sf::Sprite> SetMultiFrameSprite(const int textureKey, const int cellWidth, const int cellHeight, const int numOfColumns, const int numOfRows, const sf::Vector2f& position = sf::Vector2f(0.0f, 0.0f));
    static void SetSpriteHorizontalFlip(sf::Sprite* sprite, const bool flip);
    static void SetSpriteOriginCenter(sf::Sprite* sprite);
    //Text
    static void SetFont(const std::string& filePath);
    static sf::Text SetText(const std::string& string, const sf::Vector2f& position = sf::Vector2f(0.0f, 0.0f), const int textSize = 32, const sf::Vector2f& scale = sf::Vector2f(1.0f, 1.0f));
    static void SetTextOriginCenter(sf::Text* text);
    //TileMap
    static TileMap SetTileMap(const int textureKey, sf::Vector2u tileSize, const std::vector<std::vector<int>> map, sf::Vector2f position, int width, int height);

private:
    static std::unordered_map<int, sf::Texture> textureMap_;
    static sf::Font font_;
};

#endif
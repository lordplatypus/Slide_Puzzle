#include <SFML/Graphics.hpp>
#include "GameObjectManager.h"

GameObjectManager::GameObjectManager()
{}

GameObjectManager::~GameObjectManager()
{
    Clear();
}

void GameObjectManager::Add(GameObject* gameObject)
{
    gameObjects_.push_back(gameObject);
}

void GameObjectManager::Update(float delta_time)
{
    for (auto gameObject : gameObjects_)
    {
        gameObject->Update(delta_time);
    }
}

void GameObjectManager::Draw() const
{
    for (auto gameObject : gameObjects_)
    {
        gameObject->Draw();
    }
}

void GameObjectManager::Collision()
{
    for (auto i = gameObjects_.begin(); i != gameObjects_.end(); i++)
    {
        for (auto j = next(i); j != gameObjects_.end(); j++)
        {
            if ((*i)->IsCollision(**j)) (*i)->OnCollision(**j);
        }
    }
}

void GameObjectManager::Remove()
{
    for (auto i = gameObjects_.begin(); i != gameObjects_.end(); )
    {
        if ((*i)->IsDead() && (*i)->GetTag() != "Player")
        {
            delete *i;
            i = gameObjects_.erase(i);
        }
        else i++;
    }
}

GameObject* GameObjectManager::Find(const std::string& tag) const
{
    for (auto gameObject : gameObjects_)
    {
        if (gameObject->GetTag() == tag)
        {
            return gameObject;
        }
    }
    return nullptr;
}

GameObject* GameObjectManager::Find(const int ID) const
{
    for (auto gameObject : gameObjects_)
    {
        if (gameObject->GetID() == ID)
        {
            return gameObject;
        }
    }
    return nullptr;
}

void GameObjectManager::Clear()
{
    for (auto gameObject : gameObjects_)
    {
        delete gameObject;
    }
    gameObjects_.clear();
}
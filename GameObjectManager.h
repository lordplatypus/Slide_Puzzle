#ifndef GAMEOBJECT_MANAGER_H_
#define GAMEOBJECT_MANAGER_H_
#include <list>
#include "GameObject.h"

class GameObjectManager
{
public:
    GameObjectManager();
    ~GameObjectManager();
    //Add a gameobject to the list of gameobjects
    void Add(GameObject* gameObject);
    //Update all gameobjects in the list
    void Update(float delta_time);
    //Draw all gameobjects in the list
    void Draw() const;
    //Check collision between gameobjects
    void Collision();
    //Remove "dead" gameobjects
    void Remove();
    //Find a specific gameobject by tag
    GameObject* Find(const std::string& tag) const;
    //Find a specific gameobject by ID
    GameObject* Find(const int ID) const;
    //Delete all gameobjects, call when scene ends
    void Clear();

    GameObjectManager(const GameObjectManager& other) = delete;
    GameObjectManager& operator = (const GameObjectManager& other) = delete;

private:
    std::list<GameObject*> gameObjects_; //list of GameObjects
};

#endif
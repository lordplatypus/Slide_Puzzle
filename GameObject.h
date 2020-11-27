#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_
#include <SFML/Graphics.hpp>
#include "Scene.h"

class Scene;

class GameObject
{
public:
    GameObject();
    virtual ~GameObject();

    //Update
    virtual void Update(float delta_time);
    //Delayed Update - use this if something sould be calculated after normal Update
    virtual void DelayedUpdate(float delta_time);
    //Draw
    virtual void Draw();
    //Delayed Updated - draw things after the normal Draw - helpful for UI
    virtual void DelayedDraw();

    //This is called when colliding with another gameobject, write reaction logic here
    virtual void ReactOnCollision(GameObject& other);
    //This is called if "Iteraction" is used instead of "Collision" - meaning that if 2 objects DON'T collide this is called
    virtual void ReactOnMissedCollision(GameObject& other);
    //Marks the gameobject as "dead" so that it can be removed
    virtual void Kill();

    //Hitbox
    sf::IntRect GetHitBox() const;

    //Collision
    //Check if collision happened between this gameobject and "other"
    bool IsCollision(GameObject& other);
    //If collision occured, call "ReactOnCollision" for this gameobject and "other"
    void OnCollision(GameObject& other);
    //called by "Interaction"
    void OnMissedCollision(GameObject& other);
    //Called by "OneWayCollision"
    void OnOneWayCollision(GameObject& other);
    //Called by "OneWayInteraction"
    void OnMissedOneWayCollision(GameObject& other);
    //See if the object is included in collision calculations
    bool GetActive() const;
    //Set whether or not an object is "active" in collision calculations
    void SetActive(const bool isActive);

    //Data
    //Store position
    void StorePosition();
    //Returns current position
    sf::Vector2f GetPosition() const;
    //Returns stored position
    sf::Vector2f GetPrevPosition() const;
    //Returns "living" state
    bool IsDead() const;
    //Return tag
    const std::string& GetTag() const;
    //Return name
    const std::string& GetName() const;
    //return ID
    int GetID() const;

    GameObject(const GameObject& other) = delete;
    GameObject& operator = (const GameObject& other) = delete;

private:
    sf::Vector2f prevPosition_{0.0f, 0.0f}; //store prev position
    bool isActive_{true}; //included in collision calculations?

protected:
    Scene* scene_{nullptr}; //Gives access to the scene, Set this up in the gameobjects constructor
    sf::Vector2f position_{0.0f, 0.0f}; //gameobjects position
    sf::Vector2f velocity_{0.0f, 0.0f}; //gameobjects velocity
    bool isDead_{false}; //"Death" flag
    int sprite_{0}; //Used to store sprite ID - Used for drawing/editing sprite
    int imageWidth_{0}; //sprite width - Set up in the constructor
    int imageHeight_{0}; //sprite height - Set up in the constructor
    std::string tag_{""}; //gameobject tag - Set up in the constructor
    std::string name_{""}; //gameobject name - Set up in the constructor
    int ID_{0}; //gameobject ID - Set up in the constructor
};

#endif
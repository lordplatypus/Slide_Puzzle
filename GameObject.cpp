#include <SFML/Graphics.hpp>
#include "GameObject.h"
using namespace std;
using namespace sf;

GameObject::GameObject() {}

GameObject::~GameObject() {}

void GameObject::Update(float delta_time)
{}

void GameObject::DelayedUpdate(float delta_time)
{}

void GameObject::Draw()
{}

void GameObject::DelayedDraw()
{}

void GameObject::ReactOnCollision(GameObject& other)
{}

void GameObject::ReactOnMissedCollision(GameObject& other)
{}

void GameObject::StorePosition()
{
    prevPosition_ = position_;
}

sf::IntRect GameObject::GetHitBox() const
{
    return sf::IntRect(position_.x, position_.y, imageWidth_, imageHeight_);
}

bool GameObject::IsCollision(GameObject& other)
{
    return GetHitBox().intersects(other.GetHitBox());
}

void GameObject::OnCollision(GameObject& other)
{
    ReactOnCollision(other);
    other.ReactOnCollision(*this);
}

void GameObject::OnMissedCollision(GameObject& other)
{
    ReactOnMissedCollision(other);
    other.ReactOnMissedCollision(*this);
}

void GameObject::OnOneWayCollision(GameObject& other)
{
    ReactOnCollision(other);
}

void GameObject::OnMissedOneWayCollision(GameObject& other)
{
    ReactOnMissedCollision(other);
}

bool GameObject::GetActive() const
{
    return isActive_;
}

void GameObject::SetActive(const bool isActive)
{
    isActive_ = isActive;
}

void GameObject::Kill()
{
    isDead_ = true;
}

Vector2f GameObject::GetPosition() const
{
    return position_;
}

Vector2f GameObject::GetPrevPosition() const
{
    return prevPosition_;
}

bool GameObject::IsDead() const
{
    return isDead_;
}

const string& GameObject::GetTag() const
{
    return tag_;
}

const string& GameObject::GetName() const
{
    return name_;
}

int GameObject::GetID() const
{
    return ID_;
}
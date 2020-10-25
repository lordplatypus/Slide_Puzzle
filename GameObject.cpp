#include <SFML/Graphics.hpp>
#include "GameObject.h"
using namespace std;
using namespace sf;

GameObject::GameObject() {}

GameObject::~GameObject() {}

void GameObject::Update(float delta_time)
{}

void GameObject::Draw()
{}

void GameObject::ReactOnCollision(GameObject& other)
{}

void GameObject::StorePosition()
{
    prevPosition_ = position_;
}

int GameObject::GetLeft() const
{
    return position_.x + left_;
}

void GameObject::SetLeft(const int left)
{
    left_ = left;
}

int GameObject::GetRight() const
{
    return position_.x + right_;
}

void GameObject::SetRight(const int right)
{
    right_ = right;
}

int GameObject::GetTop() const
{
    return position_.y + top_;
}

void GameObject::SetTop(const int top)
{
    top_ = top;
}

int GameObject::GetBottom() const
{
    return position_.y + bottom_;
}

void GameObject::SetBottom(const int bottom)
{
    bottom_ = bottom;
}

const std::vector<sf::Vector2f> GameObject::GetHitBox()
{
    return std::vector<sf::Vector2f>
    {
        sf::Vector2f(GetLeft(), GetTop()), 
        sf::Vector2f(GetRight(), GetTop()), 
        sf::Vector2f(GetLeft(), GetBottom()), 
        sf::Vector2f(GetRight(), GetBottom())
    };
}

bool GameObject::IsCollision(GameObject& other)
{
    std::vector<sf::Vector2f> otherHitBox = other.GetHitBox();
    for (int i = 0; i < otherHitBox.size(); i++)
    {
        if (otherHitBox[i].x > GetLeft() && otherHitBox[i].x < GetRight() && otherHitBox[i].y > GetTop() && otherHitBox[i].y < GetBottom())
        {
            return true;
        }
    }
    if (position_ == other.GetPosition()) return true;
    return false;
}

void GameObject::OnCollision(GameObject& other)
{
    ReactOnCollision(other);
    other.ReactOnCollision(*this);
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
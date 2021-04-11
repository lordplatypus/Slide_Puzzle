
#include "Camera.h"

//Camera::Camera(sf::RenderWindow* render_window) : window_{render_window} {}
Camera::Camera(const sf::Vector2f& aspectRatio) : aspectRatio_{aspectRatio} 
{}

Camera::~Camera() 
{
    Clear();
}

void Camera::SetAspectRatio(const sf::Vector2f& aspectRatio)
{
    aspectRatio_ = aspectRatio;
}

const sf::Vector2f& Camera::GetAspectRatio() const
{
    return aspectRatio_;
}

void Camera::SetView(const std::string& viewName)
{
    views_[viewName] = new sf::View(sf::FloatRect(0.0f, 0.0f, aspectRatio_.x, aspectRatio_.y));
}

void Camera::SetView(const std::string& viewName, float width, float height)
{
    views_[viewName] = new sf::View(sf::FloatRect(0.0f, 0.0f, width, height));
    //SetCurrentView(viewName);
}

void Camera::SetView(const std::string& viewName, const sf::Vector2f& size)
{
    views_[viewName] = new sf::View(sf::FloatRect(0.0f, 0.0f, size.x, size.y));
    //SetCurrentView(viewName);
}

void Camera::SetView(const std::string& viewName, const sf::FloatRect& viewArea)
{
    views_[viewName] = new sf::View(viewArea);
    //SetCurrentView(viewName);
}

sf::View* Camera::GetView(const std::string& viewName)
{
    return views_[viewName];
}

std::unordered_map<std::string, sf::View*> Camera::GetAllViews()
{
    return views_;
}

void Camera::RemoveView(const std::string& viewName)
{
    //Not sure if needed but left here just in case this may be used in the future
}

void Camera::Clear()
{
    for (auto view : views_)
    {
        delete view.second;
    }
    views_.clear();
}
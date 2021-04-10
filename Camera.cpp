
#include "Camera.h"

Camera::Camera(sf::RenderWindow* render_window) : window_{render_window} {}

Camera::~Camera() {}

void Camera::SetView(const std::string& viewName, float width, float height)
{
    views_[viewName] = sf::View(sf::FloatRect(0.0f, 0.0f, width, height));
    SetCurrentView(viewName);
}

void Camera::SetView(const std::string& viewName, const sf::Vector2f& size)
{
    views_[viewName] = sf::View(sf::FloatRect(0.0f, 0.0f, size.x, size.y));
    SetCurrentView(viewName);
}

void Camera::SetView(const std::string& viewName, const sf::FloatRect& viewArea)
{
    views_[viewName] = sf::View(viewArea);
    SetCurrentView(viewName);
}

void Camera::SetCurrentView(const std::string& viewName)
{
    window_->setView(views_[viewName]);
}

const sf::View& Camera::GetView(const std::string& viewName)
{
    return views_[viewName];
}

void Camera::SetViewTarget(const std::string& viewName, sf::Vector2f targetPosition)
{
    views_[viewName].setCenter(targetPosition);
    SetCurrentView(viewName);
}

void Camera::SetViewSize(const std::string& viewName, float width, float height)
{
    views_[viewName].setSize(width, height);
    SetCurrentView(viewName);
}

void Camera::SetViewSize(const std::string& viewName, const sf::Vector2f& size)
{
    views_[viewName].setSize(size);
    SetCurrentView(viewName);
}

void Camera::SetViewSize(const std::string& viewName, const sf::FloatRect& area)
{
    views_[viewName].setViewport(area);
    SetCurrentView(viewName);
}

const sf::Vector2f& Camera::GetViewCenter(const std::string& viewName)
{
    return views_[viewName].getCenter();
}

const sf::Vector2f& Camera::GetViewSize(const std::string& viewName)
{
    return views_[viewName].getSize();
}

const sf::FloatRect& Camera::GetViewRect(const std::string& viewName)
{
    return views_[viewName].getViewport();
}

float Camera::GetViewRightEdge(const std::string& viewName)
{
    return GetViewCenter(viewName).x + (GetViewSize(viewName).x / 2);
}

float Camera::GetViewLeftEdge(const std::string& viewName)
{
    return GetViewCenter(viewName).x - (GetViewSize(viewName).x / 2);
}

float Camera::GetViewTopEdge(const std::string& viewName)
{
    return GetViewCenter(viewName).y - (GetViewSize(viewName).y / 2);
}

float Camera::GetViewBottomEdge(const std::string& viewName)
{
    return GetViewCenter(viewName).y + (GetViewSize(viewName).y / 2);
}

void Camera::SetAllViewsSize(const sf::FloatRect& area)
{
    for (auto view : views_)
    {
        view.second.setViewport(area);
        SetCurrentView(view.first);
    }
}


const sf::RenderWindow& Camera::GetRenderWindowForView(const std::string& viewName)
{
    SetCurrentView(viewName);
    return *window_;
}
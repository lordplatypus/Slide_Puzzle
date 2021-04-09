
#include "Camera.h"

Camera::Camera(sf::RenderWindow* render_window) : window_{render_window} {}

Camera::~Camera() {}

// const sf::View& Camera::GetCamera()
// {
//     return mainCamera;
// }

// void Camera::SetTarget(sf::Vector2f position)
// {
//     mainCamera.setCenter(position);
//     window_->setView(mainCamera);
// }

// void Camera::SetCameraViewSize(float width, float height)
// {
//     mainCamera.setSize(width, height);
//     window_->setView(mainCamera);
// }

// void Camera::SetCameraViewSize(sf::Vector2f size)
// {
//     mainCamera.setSize(size);
//     window_->setView(mainCamera);
// }

// void Camera::SetCameraViewSize(const sf::FloatRect& area)
// {
//     //mainCamera.reset(area);
//     mainCamera.setViewport(area);
//     window_->setView(mainCamera);
// }

// sf::IntRect Camera::GetCameraRect() const
// {
//     sf::IntRect test(GetCameraLeftEdge(), GetCameraTopEdge(), GetCameraViewSize().x, GetCameraViewSize().y);
//     return test;
// }

// const sf::Vector2f& Camera::GetCameraCenter() const
// {
//     return mainCamera.getCenter();
// }

// const sf::Vector2f& Camera::GetCameraViewSize() const
// {
//     return mainCamera.getSize();
// }

// float Camera::GetCameraRightEdge() const
// {
//     return GetCameraCenter().x + (GetCameraViewSize().x / 2);
// }

// float Camera::GetCameraLeftEdge() const
// {
//     return GetCameraCenter().x - (GetCameraViewSize().x / 2);
// }

// float Camera::GetCameraTopEdge() const
// {
//     return GetCameraCenter().y - (GetCameraViewSize().y / 2);
// }

// float Camera::GetCameraBottomEdge() const
// {
//     return GetCameraCenter().y + (GetCameraViewSize().y / 2);
// }

void Camera::SetView(std::string viewName, float width, float height)
{
    views_[viewName] = sf::View(sf::FloatRect(0.0f, 0.0f, width, height));
    SetCurrentView(viewName);
}

void Camera::SetView(std::string viewName, const sf::Vector2f& size)
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

const sf::View& Camera::GetView(std::string viewName)
{
    return views_[viewName];
}

void Camera::SetViewTarget(std::string viewName, sf::Vector2f targetPosition)
{
    views_[viewName].setCenter(targetPosition);
    SetCurrentView(viewName);
}

void Camera::SetViewSize(std::string viewName, float width, float height)
{
    views_[viewName].setSize(width, height);
    SetCurrentView(viewName);
}

void Camera::SetViewSize(std::string viewName, const sf::Vector2f& size)
{
    views_[viewName].setSize(size);
    SetCurrentView(viewName);
}

void Camera::SetViewSize(std::string viewName, const sf::FloatRect& area)
{
    views_[viewName].setViewport(area);
    SetCurrentView(viewName);
}

const sf::Vector2f& Camera::GetViewCenter(std::string viewName)
{
    return views_[viewName].getCenter();
}

const sf::Vector2f& Camera::GetViewSize(std::string viewName)
{
    return views_[viewName].getSize();
}

const sf::FloatRect& Camera::GetViewRect(std::string viewName)
{
    return views_[viewName].getViewport();
}

float Camera::GetViewRightEdge(std::string viewName)
{
    return GetViewCenter(viewName).x + (GetViewSize(viewName).x / 2);
}

float Camera::GetViewLeftEdge(std::string viewName)
{
    return GetViewCenter(viewName).x - (GetViewSize(viewName).x / 2);
}

float Camera::GetViewTopEdge(std::string viewName)
{
    return GetViewCenter(viewName).y - (GetViewSize(viewName).y / 2);
}

float Camera::GetViewBottomEdge(std::string viewName)
{
    return GetViewCenter(viewName).y + (GetViewSize(viewName).y / 2);
}
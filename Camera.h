#ifndef CAMERA_H_
#define CAMERA_H_
#include <SFML/Graphics.hpp>
#include <unordered_map>

class Camera
{
public:
    Camera(sf::RenderWindow* render_window);
    ~Camera();
    // const sf::View& GetCamera();
    // void SetTarget(sf::Vector2f position);
    // void SetCameraViewSize(float width, float height);
    // void SetCameraViewSize(sf::Vector2f size);
    // void SetCameraViewSize(const sf::FloatRect& area);
    // sf::IntRect GetCameraRect() const;
    // const sf::Vector2f& GetCameraCenter() const;
    // const sf::Vector2f& GetCameraViewSize() const;
    // float GetCameraRightEdge() const;
    // float GetCameraLeftEdge() const;
    // float GetCameraTopEdge() const;
    // float GetCameraBottomEdge() const;

    void SetView(std::string viewName, float width, float height);
    void SetView(std::string viewName, const sf::Vector2f& size);
    void SetView(const std::string& viewName, const sf::FloatRect& viewArea);
    void SetCurrentView(const std::string& viewName);
    const sf::View& GetView(std::string viewName);
    void SetViewTarget(std::string viewName, sf::Vector2f targetPosition);
    void SetViewSize(std::string viewName, float width, float height);
    void SetViewSize(std::string viewName, const sf::Vector2f& size);
    void SetViewSize(std::string viewName, const sf::FloatRect& area);
    const sf::Vector2f& GetViewCenter(std::string viewName);
    const sf::Vector2f& GetViewSize(std::string viewName);
    const sf::FloatRect& GetViewRect(std::string viewName);
    float GetViewRightEdge(std::string viewName);
    float GetViewLeftEdge(std::string viewName);
    float GetViewTopEdge(std::string viewName);
    float GetViewBottomEdge(std::string viewName);  

    Camera(const Camera& other) = delete;
    Camera& operator = (const Camera& other) = delete;

private:
    //sf::View mainCamera;
    sf::RenderWindow* window_{nullptr};

    std::unordered_map<std::string, sf::View> views_;
};

#endif
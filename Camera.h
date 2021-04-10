#ifndef CAMERA_H_
#define CAMERA_H_
#include <SFML/Graphics.hpp>
#include <unordered_map>

class Camera
{
public:
    Camera(sf::RenderWindow* render_window);
    ~Camera();

    //Create a new view
    void SetView(const std::string& viewName, float width, float height);
    //Create a new view
    void SetView(const std::string& viewName, const sf::Vector2f& size);
    //Create a new view
    void SetView(const std::string& viewName, const sf::FloatRect& viewArea);
    //Call this to activate a view, this must be done before rendering anything to a specific view
    void SetCurrentView(const std::string& viewName);
    //returns a view
    const sf::View& GetView(const std::string& viewName);
    //moves view so that the given position is centered within the view
    void SetViewTarget(const std::string& viewName, sf::Vector2f targetPosition);
    //Changes a view's size
    void SetViewSize(const std::string& viewName, float width, float height);
    //Changes a view's size
    void SetViewSize(const std::string& viewName, const sf::Vector2f& size);
    //Changes a view's size
    void SetViewSize(const std::string& viewName, const sf::FloatRect& area);
    //return a view's center (world coordinate)
    const sf::Vector2f& GetViewCenter(const std::string& viewName);
    //return a view's size 
    const sf::Vector2f& GetViewSize(const std::string& viewName);
    //return a view's size 
    const sf::FloatRect& GetViewRect(const std::string& viewName);
    //return a view's right edge (world coordinate)
    float GetViewRightEdge(const std::string& viewName);
    //return a view's left edge (world coordinate)
    float GetViewLeftEdge(const std::string& viewName);
    //return a view's top edge (world coordinate)
    float GetViewTopEdge(const std::string& viewName);
    //return a view's bottom edge (world coordinate)
    float GetViewBottomEdge(const std::string& viewName);
    //Sets a views to the given size
    void SetAllViewsSize(const sf::FloatRect& area);

    const sf::RenderWindow& GetRenderWindowForView(const std::string& viewName);

    Camera(const Camera& other) = delete;
    Camera& operator = (const Camera& other) = delete;

private:
    sf::RenderWindow* window_{nullptr};
    std::unordered_map<std::string, sf::View> views_;
};

#endif
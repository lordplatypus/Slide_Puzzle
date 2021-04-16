#ifndef CAMERA_H_
#define CAMERA_H_
#include <SFML/Graphics.hpp>
#include <unordered_map>

class Camera
{
public:
    Camera() = default;
    Camera(sf::RenderWindow* renderWindow, const sf::Vector2f& aspectRatio);
    ~Camera();

    //Get the render window
    const sf::RenderWindow& GetRenderWindow() const;
    //Set the game aspect ratio
    void SetAspectRatio(const sf::Vector2f& aspectRatio);
    //Get the game aspect ratio
    const sf::Vector2f& GetAspectRatio() const;
    //create a new niew with default size
    void SetView(const std::string& viewName);
    //Create a new view
    void SetView(const std::string& viewName, float width, float height);
    //Create a new view
    void SetView(const std::string& viewName, const sf::Vector2f& size);
    //Create a new view
    void SetView(const std::string& viewName, const sf::FloatRect& viewArea);
    //returns a view
    sf::View* GetView(const std::string& viewName);
    //return all views
    std::unordered_map<std::string, sf::View*> GetAllViews();
    //Delete a view
    void RemoveView(const std::string& viewName);
    //Deletes all views from the unordered map
    void Clear();

    

    //FUNCTIONS TO ADD
    //CLEAR
    //DELETE VIEW

    Camera(const Camera& other) = delete;
    Camera& operator = (const Camera& other) = delete;

private:
    sf::RenderWindow* renderWindow_{nullptr};
    std::unordered_map<std::string, sf::View*> views_;
    sf::Vector2f aspectRatio_;
};

#endif
cmake_minimum_required(VERSION 3.10)

# set the project name
project(Kiara_Loading_Game)

# set path to findSFML.cmake file
set(CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules")

# find SFML components
find_package(SFML 2.4 COMPONENTS graphics window system audio REQUIRED)

# list .cpp files
set(SOURCES main.cpp LP.cpp Game.cpp SceneGame.cpp LoadImage.cpp GameObject.cpp GameObjectManager.cpp Kiara.cpp ChickenSpawner.cpp Chicken.cpp Score.cpp Points.cpp MusicPlayer.cpp)

# add the executable
add_executable(Kiara_Loading_Game ${SOURCES}) 

# link SFML libraries
target_link_libraries(Kiara_Loading_Game sfml-graphics sfml-window sfml-system sfml-audio)
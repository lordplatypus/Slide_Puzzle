cmake_minimum_required(VERSION 3.10)

# set the project name
project(Game)

# set path to findSFML.cmake file
set(CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules")

# find SFML components
find_package(SFML 2.4 COMPONENTS graphics window system audio REQUIRED)

# list .cpp files
set(SOURCES main.cpp EL.cpp LP.cpp MP.cpp Game.cpp SceneGame.cpp GameObject.cpp GameObjectManager.cpp IP.cpp Camera.cpp Particle.cpp ParticleManager.cpp 
    TileMap.cpp PictureBox.cpp EmptyBox.cpp PuzzleManager.cpp Hint.cpp SceneOptions.cpp Button.cpp Counter.cpp Options.cpp TI.cpp WinText.cpp FileManager.cpp)

# add the executable
add_executable(Game ${SOURCES}) 

# link SFML libraries
target_link_libraries(Game sfml-graphics sfml-window sfml-system sfml-audio)
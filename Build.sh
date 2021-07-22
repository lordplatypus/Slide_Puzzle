#Make the Game directory for the executable and resources
mkdir Game

#move the resources to the Game directory
mv Blue\ Sky\ 8x8.ttf ./Game

#Make a build directory and move to it
mkdir Build && cd ./Build

#Generate the make files into the Build directory
cmake -S ../ -B ./

#Make
make

#move the executable to the Game directory
mv Game ../Game

#move out of the Build directory
cd ../

#remove the Build directory
rm -r ./Build
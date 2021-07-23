#Make a build directory and move to it
mkdir build && cd ./build

#Generate the make files into the build directory
cmake -S ../Source -B ./

#Make
make

#move the executable to the Game directory
mv Game ../

#move out of the build directory
cd ../

#remove the build directory
rm -r ./build
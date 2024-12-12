rmdir /s /q build
mkdir build
cd build
cmake .. -G "MinGW Makefiles" -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -DCONNEXTDDS_ARCH=x64Win64VS2017
mingw32-make
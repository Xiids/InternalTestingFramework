rm -rf  ./build
mkdir build
cd build
source ~/dds/rti_connext_dds-7.3.0/resource/scripts/rtisetenv_x64Linux4gcc7.3.0.bash
cmake ..  -DCONNEXTDDS_ARCH=x64Linux4gcc7.3.0
make
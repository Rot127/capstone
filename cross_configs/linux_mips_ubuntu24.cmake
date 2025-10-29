# This example file is for builds on Ubunutu 24.04.
# Search for required packages (compiler + libc) with `apt search mips`
# sudo apt install gcc-mips-linux-gnu g++-mips-linux-gnu binutils-mips-linux-gnu libc6-dev-mips-cross qemu-user-static
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR mips)

set(CMAKE_C_COMPILER   mips-linux-gnu-gcc)
set(CMAKE_CXX_COMPILER mips-linux-gnu-g++)

set(CMAKE_SYSROOT /usr/mips-linux-gnu)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

set(CMAKE_CROSSCOMPILING_EMULATOR qemu-mips-static;-L;${CMAKE_SYSROOT})

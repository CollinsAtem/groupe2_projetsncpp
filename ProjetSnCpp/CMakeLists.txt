cmake_minimum_required(VERSION 3.24)
project(ProjetSnCpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(include)

add_executable(ProjetSnCpp
        include/Drive.h
        src/Drive.cpp
        main.cpp
        notif.cpp
        notif.h
        resource.h
        usb.cpp
        usb.h)

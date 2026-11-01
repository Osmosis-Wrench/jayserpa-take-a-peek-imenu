cmake_minimum_required(VERSION 3.21)

project(keyholepeekmenu VERSION 1.3.1 LANGUAGES CXX)

find_package(CommonLibSSE CONFIG REQUIRED)

add_commonlibsse_plugin(${PROJECT_NAME}
    NAME "Take A Peek Custom IMenu"
    AUTHOR "OsmosisWrench"
    SOURCES src/main.cpp src/PCH.cpp src/PeekMenu.cpp src/papyrus.cpp
)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_23)
target_include_directories(${PROJECT_NAME} PRIVATE src)
target_precompile_headers(${PROJECT_NAME} PRIVATE src/PCH.h)

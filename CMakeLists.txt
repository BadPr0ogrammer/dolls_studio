cmake_minimum_required(VERSION 3.27)

set(PROGNAME dolls_studio)
project(${PROGNAME}
    VERSION 1.0.0
    LANGUAGES CXX)

include(GNUInstallDirs)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC OFF)
set(CMAKE_GLOBAL_AUTOGEN_TARGET OFF)
set(AUTOGEN_BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}/autogen")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_C_VISIBILITY_PRESET hidden)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)

add_compile_options( -Wall -Wextra )

set(CMAKE_BUILD_TYPE Debug)
add_compile_definitions(ITEM_STATISTICS=1)
add_compile_options(-O0)
add_compile_options(-ffast-math)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Quick OpenGL)
find_package(QSkinny REQUIRED COMPONENTS QSkinny)
find_package(VTK REQUIRED)
find_package(f3d REQUIRED COMPONENTS library)

qt_add_executable(${PROGNAME}
    main.cpp
    vtkitem.cpp vtkitem.h
    mainview.cpp mainview.h
    support/SkinnyGlobal.h
    support/SkinnyNamespace.cpp 
    support/SkinnyNamespace.h 
    support/SkinnyShapeFactory.cpp 
    support/SkinnyShapeFactory.h 
    support/SkinnyShapeProvider.cpp 
    support/SkinnyShapeProvider.h 
    support/SkinnyShortcut.cpp 
    support/SkinnyShortcut.h 
    support/DejaVuSans.qrc 
    support/Roboto.qrc 
    support/SegoeUI.qrc 

)

target_include_directories(${PROGNAME} PUBLIC /usr/local/include/f3d)

target_link_libraries(${PROGNAME}
    PUBLIC
    Qt6::Core
    Qt6::Gui
    Qt6::Quick
    Qt6::OpenGL    
    ${VTK_LIBRARIES}
    assimp
    f3d
    Qsk::QSkinny
)

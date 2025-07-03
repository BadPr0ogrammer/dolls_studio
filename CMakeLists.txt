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

add_compile_definitions(VTK_USE_X)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Quick OpenGL Widgets)
find_package(QSkinny REQUIRED COMPONENTS QSkinny)
find_package(VTK REQUIRED)
#find_package(f3d REQUIRED COMPONENTS library)

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
    mainheader.h
    mainheader.cpp
    f3d/engine.h
    f3d/engine.cpp
    f3d/F3D/F3DLog.cxx
    f3d/F3D/F3DLog.h
    f3d/F3D/F3DDefaultHDRI.cxx
    f3d/F3D/F3DDefaultHDRI.h
    f3d/F3D/F3DColoringInfoHandler.cxx
    f3d/F3D/F3DColoringInfoHandler.h
    f3d/vtkF3D/vtkF3DRenderPass.cxx
    f3d/vtkF3D/vtkF3DRenderPass.h
    f3d/vtkF3D/vtkF3DUIActor.cxx
    f3d/vtkF3D/vtkF3DUIActor.h
    f3d/vtkF3D/vtkF3DRenderer.cxx
    f3d/vtkF3D/vtkF3DRenderer.h
    f3d/vtkF3D/vtkF3DGLXRenderWindow.cxx
    f3d/vtkF3D/vtkF3DGLXRenderWindow.h
    f3d/vtkF3D/vtkF3DHexagonalBokehBlurPass.cxx
    f3d/vtkF3D/vtkF3DHexagonalBokehBlurPass.h
    f3d/vtkF3D/vtkF3DCachedLUTTexture.cxx
    f3d/vtkF3D/vtkF3DCachedLUTTexture.h
    f3d/vtkF3D/vtkF3DCachedSpecularTexture.cxx
    f3d/vtkF3D/vtkF3DCachedSpecularTexture.h
    f3d/vtkF3D/vtkF3DSolidBackgroundPass.cxx
    f3d/vtkF3D/vtkF3DSolidBackgroundPass.h
    f3d/vtkF3D/vtkF3DUserRenderPass.cxx
    f3d/vtkF3D/vtkF3DUserRenderPass.h
    f3d/vtkF3D/vtkF3DOverlayRenderPass.cxx
    f3d/vtkF3D/vtkF3DOverlayRenderPass.h
    f3d/vtkF3D/vtkF3DOpenGLGridMapper.cxx
    f3d/vtkF3D/vtkF3DOpenGLGridMapper.h
    f3d/vtkF3D/vtkF3DPostProcessFilter.cxx
    f3d/vtkF3D/vtkF3DPostProcessFilter.h
    f3d/vtkF3D/vtkF3DMetaImporter.cxx
    f3d/vtkF3D/vtkF3DMetaImporter.h
    f3d/vtkF3D/vtkF3DGenericImporter.cxx
    f3d/vtkF3D/vtkF3DGenericImporter.h
    f3d/vtkF3D/vtkF3DImporter.cxx
    f3d/vtkF3D/vtkF3DImporter.h
    f3d/vtkF3D/vtkF3DAssimpImporter.cxx
    f3d/vtkF3D/vtkF3DAssimpImporter.h
)

#target_include_directories(${PROGNAME} PUBLIC /usr/local/include/f3d)
target_include_directories(${PROGNAME} PUBLIC f3d f3d/F3D f3d/vtkF3D f3d/vtkext)

target_link_libraries(${PROGNAME}
    PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Quick
    Qt6::OpenGL    
    Qt6::Widgets
    ${VTK_LIBRARIES}
    assimp
#    f3d
    Qsk::QSkinny
)

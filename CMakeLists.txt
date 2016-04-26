cmake_minimum_required(VERSION 3.3)
project(msmv_framework)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package( OpenCV REQUIRED )
find_package(Boost 1.58 COMPONENTS system filesystem program_options REQUIRED)
include_directories( ${Boost_INCLUDE_DIR} )

set(SOURCE_FILES main.cpp ImageHandler.h AbstractTransformation.hpp SaltPepperNoise.cpp SaltPepperNoise.h GaussianNoise.cpp GaussianNoise.h
        BrightnessAndContrast.cpp BrightnessAndContrast.h GaussianBlur.cpp GaussianBlur.h
        TransformationsHolder.h Options.hpp RandomItem.hpp ImageDB.cpp ImageDB.h TransformationsHolder.cpp Options.cpp Resize.cpp Resize.h Compression.cpp Compression.h LensDistort.cpp LensDistort.h)
add_executable(msmv_framework ${SOURCE_FILES})
target_link_libraries(msmv_framework ${OpenCV_LIBS}   ${Boost_LIBRARIES} )
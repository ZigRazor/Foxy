cmake_minimum_required(VERSION 3.11)

# set the project name and version
project(Foxy VERSION 0.0.1)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


option(DEBUG "Enable Debug" OFF)
if(DEBUG)
	add_compile_options(
		-O0  #no optimization
		-g   #generate debug info
	)
endif(DEBUG)

file (GLOB_RECURSE FOXY_SRC_FILES "Src/**.cpp")

add_library(Foxy SHARED ${FOXY_SRC_FILES})

target_include_directories(Foxy PUBLIC "${CMAKE_SOURCE_DIR}/Include"
                                            "${CMAKE_SOURCE_DIR}/Include/Observable"
                                            )


add_subdirectory(Examples)
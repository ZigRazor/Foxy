
file (GLOB OBSERVABLE_SRC_FILES "*.cpp")

add_executable(Observable ${OBSERVABLE_SRC_FILES})
target_include_directories(Observable PUBLIC "${CMAKE_SOURCE_DIR}/Include"
                                            "${CMAKE_SOURCE_DIR}/Include/Observable"
                                            )

target_link_libraries(Observable Foxy)
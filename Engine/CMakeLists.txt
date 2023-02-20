set(ENGINE_ROOT_DIR "${DREAM_ROOT_DIR}/engine")
set(THIRD_PARTY_DIR "${ENGINE_ROOT_DIR}/3rdparty")

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options("/MP")
    set_property(DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Editor)
endif()


add_subdirectory(3rdparty)

add_subdirectory(source/runtime)
add_subdirectory(source/editor)
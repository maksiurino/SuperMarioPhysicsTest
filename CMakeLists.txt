cmake_minimum_required(VERSION 3.28)
project(SuperMarioPhysicsTest)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
# --- SDL3 ---
FetchContent_Declare(SDL3
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG release-3.4.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SDL3)
# --- JSON (Nlohmann) ---
FetchContent_Declare(nlohmann_json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.11.3
)
FetchContent_MakeAvailable(nlohmann_json)

add_executable(SuperMarioPhysicsTest WIN32
        src/main.cpp
        src/sprite.cpp
        src/sprite.hpp
        src/Maths.cpp
        src/Maths.hpp
)
target_compile_features(SuperMarioPhysicsTest PRIVATE cxx_std_17)
target_link_libraries(SuperMarioPhysicsTest PRIVATE
        SDL3::SDL3
        nlohmann_json::nlohmann_json
)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT SuperMarioPhysicsTest)

add_custom_target(copy_resources ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/Resources
        $<TARGET_FILE_DIR:SuperMarioPhysicsTest>/Resources
)

add_dependencies(SuperMarioPhysicsTest copy_resources)


cmake_minimum_required(VERSION 3.10)
project(TestProj)

# Force static linking
set(SFML_STATIC_LIBRARIES TRUE)

# Look in /usr/local (where we installed from source)
set(CMAKE_PREFIX_PATH "/usr/local")

# Find SFML 3.0+ (will use static .a files)
find_package(SFML 3.0 COMPONENTS graphics window system REQUIRED)

# Build executable
add_executable(mygame main.cpp)

# Link SFML + all required system libs for static build
target_link_libraries(mygame
    sfml-graphics
    sfml-window
    sfml-system
    # System deps required when linking SFML statically
    X11
    Xrandr
    Xcursor
    Xi
    freetype
    GL
    pthread
    udev
    mpg123
    openal
    FLAC
    vorbis
    ogg
    # Optional: for audio input (if used later)
    # asound
)

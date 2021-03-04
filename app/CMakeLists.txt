# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.10.2)

# Declares and names the project.

project("myxplay")

include_directories(src/main/jniLibs/include)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

LINK_DIRECTORIES(${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI})
#指定自己便携的源文件目录
AUX_SOURCE_DIRECTORY(${CMAKE_SOURCE_DIR}/src/main/cpp SRC_LIST)

#指定生成动态库music-player
add_library(
        # Sets the name of the library.
        music-player
        # Sets the library as a shared library.
        SHARED
        # Provides a relative path to your source file(s).
        ${SRC_LIST}
)

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.
#连接以上编译
target_link_libraries( # Specifies the target library.
#        native-lib
        music-player
#        ffmpeg
        #播放音频
        OpenSLES
        #视频shader播放
        EGL
        GLESv2
        android
        avcodec
        avfilter
        avformat
        avutil
        swresample
        swscale

        # Links the target library to the log library
        # included in the NDK.
        ${log-lib})
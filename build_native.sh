cd "native"

export ANDROID_NDK=/Users/seekting/Library/Android/sdk/ndk/25.1.8937393
export NDK_ROOT=/Users/seekting/Library/Android/sdk/ndk/25.1.8937393
rm -r  CMakeFiles/
cmake -DCMAKE_TOOLCHAIN_FILE=$NDK_ROOT/build/cmake/android.toolchain.cmake -DANDROID_ABI=armeabi-v7a -DCMAKE_BUILD_TYPE=Release
make
rm -r  CMakeFiles/

cmake -DCMAKE_TOOLCHAIN_FILE=$NDK_ROOT/build/cmake/android.toolchain.cmake -DANDROID_ABI=arm64-v8a -DCMAKE_BUILD_TYPE=Release
make
rm -r  CMakeFiles/

cmake -DCMAKE_TOOLCHAIN_FILE=$NDK_ROOT/build/cmake/android.toolchain.cmake -DANDROID_ABI=x86  -DCMAKE_BUILD_TYPE=Release
make
rm -r  CMakeFiles/

cmake -DCMAKE_TOOLCHAIN_FILE=$NDK_ROOT/build/cmake/android.toolchain.cmake -DANDROID_ABI=x86_64  -DCMAKE_BUILD_TYPE=Release
make
rm -r  CMakeFiles/

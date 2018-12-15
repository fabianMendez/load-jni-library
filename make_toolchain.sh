#! /bin/bash

NDK=~/Android/Sdk/ndk-bundle/
ARCH=x86

$NDK/build/tools/make-standalone-toolchain.sh --arch=$ARCH --platform=android-21 --install-dir=$HOME/toolchains/android-$ARCH --force

#!/bin/bash

cp ../dllPrj2/dylibs/* ./build-AppPrjTest-Release/appPrj/appPrj.app/Contents/MacOS/

install_name_tool -change "libdllPrj2.1.dylib" "@executable_path/libdllPrj2.1.dylib" ./build-AppPrjTest-Release/appPrj/appPrj.app/Contents/MacOS/appPrj

macdeployqt ./build-AppPrjTest-Release/appPrj/appPrj.app -qmldir="/Users/davis/Qt5.12.6/5.12.6/clang_64/qml" -dmg

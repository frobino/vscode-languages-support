Intro from:
https://thoughts-on-cpp.com/2019/04/10/introduction-into-c-builds-with-gradle/

Examples from:
https://github.com/gradle/native-samples

Use the following, NOT the one provided with debian!
~/Tools/gradle-5.6.3/bin/gradle

~/Tools/gradle-5.6.3/bin/gradle init -> application, c++
├── build.gradle
├── gradle
│   └── wrapper
│       ├── gradle-wrapper.jar
│       └── gradle-wrapper.properties
├── gradlew
├── gradlew.bat
├── settings.gradle
└── src
    ├── main
    │   ├── cpp
    │   │   └── app.cpp
    │   └── headers
    │       └── app.h
    └── test
        └── cpp
            └── app_test.cpp

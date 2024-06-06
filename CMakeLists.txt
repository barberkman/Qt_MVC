cmake_minimum_required(VERSION 3.16)

project(MVC_deneme VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

qt_add_executable(appMVC_deneme
    main.cpp
    listcontroller.h listcontroller.cpp
)

qt_add_qml_module(appMVC_deneme
    URI MVC_deneme
    VERSION 1.0
    QML_FILES Main.qml
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appMVC_deneme PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appMVC_deneme
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appMVC_deneme
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appMVC_deneme
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

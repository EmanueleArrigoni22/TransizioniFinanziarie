cmake_minimum_required(VERSION 3.31)
project(transazioni_finanziarie)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Qt via Homebrew
set(CMAKE_PREFIX_PATH "/opt/homebrew/opt/qt")
find_package(Qt6 COMPONENTS Widgets REQUIRED)

message(STATUS "Qt6Widgets found at: ${Qt6Widgets_DIR}")

# Libreria core con le classi principali
add_library(core
        ContoCorrente.cpp
        ContoCorrente.h
        Movimento.cpp
        Movimento.h
        Entrata.cpp
        Entrata.h
        Uscita.cpp
        Uscita.h
)

# Eseguibile principale Qt
add_executable(transazioni_finanziarie main.cpp MainWindow.cpp MainWindow.h)
target_link_libraries(transazioni_finanziarie PRIVATE Qt6::Widgets core)

message(STATUS "Caricamento cartella test...")#li avevo inseriti per controllare se riuscivo ad entrare dentro il CMakefile.txt dentro /test
add_subdirectory(test)
message(STATUS "Cartella test caricata.")


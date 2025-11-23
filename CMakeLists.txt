cmake_minimum_required(VERSION 3.31)
project(transazioni_finanziarie)

set(CMAKE_CXX_STANDARD 20)
# Attiva il verbose dei makefile
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Percorso di Qt (Homebrew)
set(CMAKE_PREFIX_PATH "/opt/homebrew/opt/qt")

# Trova i pacchetti Qt
find_package(Qt6 COMPONENTS Widgets REQUIRED)

# Messaggi di debug: mostra dove Qt è stato trovato
message(STATUS "Qt6Widgets found at: ${Qt6Widgets_DIR}")
message(STATUS "Qt6Core found at: ${Qt6Core_DIR}")
message(STATUS "Qt6Gui found at: ${Qt6Gui_DIR}")

add_executable(transazioni_finanziarie main.cpp
        ContoCorrente.cpp
        ContoCorrente.h
        Movimento.cpp
        Movimento.h
        Uscita.cpp
        Uscita.h
        Entrata.cpp
        Entrata.h
        MainWindow.cpp
        MainWindow.h
)

# Linka librerie Qt
target_link_libraries(transazioni_finanziarie PRIVATE Qt6::Widgets)


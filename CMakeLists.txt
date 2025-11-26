cmake_minimum_required(VERSION 3.31)
project(transazioni_finanziarie)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Percorso Qt installato con Homebrew
set(CMAKE_PREFIX_PATH "/opt/homebrew/opt/qt")

# Trova Qt
find_package(Qt6 COMPONENTS Widgets REQUIRED)

message(STATUS "Qt6Widgets found at: ${Qt6Widgets_DIR}")
message(STATUS "Qt6Core found at: ${Qt6Core_DIR}")
message(STATUS "Qt6Gui found at: ${Qt6Gui_DIR}")

# 1) Compila le classi come libreria core (per i test) ---> La libreria core è composta solo da classi che implementano la logica(backend) dell'applicazione
set(CORE_SOURCES
        ContoCorrente.cpp
        ContoCorrente.h
        Movimento.cpp
        Movimento.h
        Uscita.cpp
        Uscita.h
        Entrata.cpp
        Entrata.h
)

add_library(core ${CORE_SOURCES})

target_link_libraries(core PRIVATE Qt6::Widgets)


# 2) Eseguibile Principale Qt ----> classi adibite principalmente all'esecuzione(frontend)

add_executable(transazioni_finanziarie
        main.cpp
        MainWindow.cpp
        MainWindow.h
)

# Linka l'eseguibile con la libreria core + Qt
target_link_libraries(transazioni_finanziarie PRIVATE core Qt6::Widgets)

# 3) AGGIUNGECLA SOTTOCARTELLA TEST
add_subdirectory(test)

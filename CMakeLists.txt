cmake_minimum_required(VERSION 3.31)
project(transazioni_finanziarie)

set(CMAKE_CXX_STANDARD 20)

add_executable(transazioni_finanziarie main.cpp
        ContoCorrente.cpp
        ContoCorrente.h
        Movimento.cpp
        Movimento.h
        Uscita.cpp
        Uscita.h
        Entrata.cpp
        Entrata.h
)

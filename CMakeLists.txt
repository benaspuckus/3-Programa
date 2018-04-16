# cmake_minimum_required(VERSION <specify CMake version here>)
project(test)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(test
        Galutinis.cpp
        Galutinis.h
        Generavimas.cpp
        Generavimas.h
        git.cpp
        IsFailo.cpp
        IsFailo.h
        IsFailoD.cpp
        IsFailoD.h
        IsFailoL.cpp
        IsFailoL.h
        IvestiPaciamZinomus.cpp
        IvestiPaciamZinomus.h
        Mediana.cpp
        Mediana.h
        Paleisti.cpp
        PazymiuIvedimas.cpp
        PazymiuIvedimas.h
        studentai.h)

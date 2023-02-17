cmake_minimum_required(VERSION 3.23)
project(Nagy_hazi C)

set(CMAKE_C_STANDARD 99)

add_executable(Nagy_hazi main.c menu.c menu.h lancoltlista.c lancoltlista.h bejegyzes.h kereses.c kereses.h fajlkezeles.c fajlkezeles.h)

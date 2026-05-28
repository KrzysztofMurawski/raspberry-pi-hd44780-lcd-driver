cmake_minimum_required(VERSION 3.24)

project(lcd C)

set(SOURCE_FILES 
    # src/main.c
    src/gpio.c
    src/signals.c
    src/lcd.c
    src/utils.c
)

set(INCLUDE_DIRECTORIES
    include/
)

add_library(${PROJECT_NAME} ${SOURCE_FILES})

# add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIRECTORIES})
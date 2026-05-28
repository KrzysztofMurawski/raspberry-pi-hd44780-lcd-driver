cmake_minimum_required(VERSION 3.24)

project(lcd VERSION 1.0.0 LANGUAGES C)

set(LCD_SOURCES
    src/gpio.c
    src/signals.c
    src/lcd.c
    src/utils.c
)

add_library(lcd STATIC ${LCD_SOURCES})

target_include_directories(lcd
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_compile_features(lcd PRIVATE c_std_11)

set_target_properties(lcd PROPERTIES
    VERSION ${PROJECT_VERSION}
)

#
# Optional example executable
#

add_executable(lcd_example src/main.c)

target_link_libraries(lcd_example
    PRIVATE lcd
)

#
# Install rules
#

install(TARGETS lcd
    ARCHIVE DESTINATION lib
)

install(FILES
    include/lcd.h
    include/gpio.h
    include/signals.h
    include/utils.h
    DESTINATION include/lcd
)
project(console_card_conf)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/general.cfg
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
# TODO: make add files easier
add_library(ConsoleCardConf all_configs.cpp all_configs.h conf_parser.cpp conf_parser.h general.cfg)

target_link_libraries(ConsoleCardConf ConsoleCardLib)

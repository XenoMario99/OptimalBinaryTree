project(optSearch)

add_library(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/src/optSearch.cc)
add_library(lib::optSearch ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/inc)
target_sources(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/src)

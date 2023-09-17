project(binaryTree)

add_library(${PROJECT_NAME} INTERFACE)
add_library(lib::binaryTree ALIAS ${PROJECT_NAME})

include(GNUInstallDirs)

target_include_directories(
    ${PROJECT_NAME}
    INTERFACE 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
        $<INSTALL_INTERFACE:include>
)

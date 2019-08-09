cmake_minimum_required(VERSION 3.0)

project(hometask_1 VERSION 1.0.0)


############################################################################################################################################################################
set(sources
    "src/levelLink.cpp"
    "src/brackets.cpp"
)

set(headers
    "include/brackets.h"
    "include/levelLink.h"
    )

add_library(functions SHARED ${sources})

set_target_properties(functions PROPERTIES
                        C_STANDARD 11
                        CXX_STANDARD 11
                        PUBLIC_HEADER "${headers}"
                        VERSION "${PROJECT_VERSION}"
                        SOVERSION "${PROJECT_VERSION_MAJOR}"
)

target_compile_options(functions PRIVATE -Wall -Wextra)

target_include_directories(functions
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)


############################################################################################################################################################################


include(GNUInstallDirs)

set(config_install_dir "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}")

set(generated_dir "${CMAKE_CURRENT_BINARY_DIR}/generated")

set(version_config "${generated_dir}/${PROJECT_NAME}ConfigVersion.cmake")
set(project_config "${generated_dir}/${PROJECT_NAME}Config.cmake")
set(TARGETS_EXPORT_NAME "${PROJECT_NAME}Targets")
set(namespace "${PROJECT_NAME}::")

include(CMakePackageConfigHelpers)


install(
    TARGETS functions
    EXPORT "${TARGETS_EXPORT_NAME}"
    RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
    LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
    INCLUDES DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)

install(
    FILES "${project_config}" "${version_config}"
    DESTINATION "${config_install_dir}"
)

install(
    EXPORT "${TARGETS_EXPORT_NAME}"
    NAMESPACE "${namespace}"
    DESTINATION "${config_install_dir}"
)
############################################################################################################################################################################
 add_subdirectory(test)

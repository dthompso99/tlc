cmake_minimum_required(VERSION 3.2)
project(TLC)

SET(BUILD_SHARED_LIBS, OFF)
SET(GLFW_BUILD_EXAMPLES, OFF)
SET(GLFW_BUILD_TESTS, OFF)
SET(GLFW_BUILD_DOCS, OFF)


add_subdirectory(vendor/glfw)

INCLUDE_DIRECTORIES(app/include vendor/glfw/include vendor/glad/include)

FILE(GLOB SOURCE_FILES app/src/*.cpp vendor/glad/src/glad.c)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})



target_link_libraries (${PROJECT_NAME} glfw ${GLFW_LIBRARIES})

add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/resources $<TARGET_FILE_DIR:${PROJECT_NAME}>/resources)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION "." COMPONENT centauri)
install(DIRECTORY "${PROJECT_SOURCE_DIR}/resources" DESTINATION "." COMPONENT centauri)

set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_VENDOR "thompsoninnovations.com")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "${PROJECT_NAME} Installer")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_PACKAGE_INSTALL_DIRECTORY ${PROJECT_NAME})
set(CPACK_COMPONENTS_ALL centauri)
set(CPACK_NSIS_MUI_ICON "${PROJECT_SOURCE_DIR}/resources/drakeblue.ico")

include(CPack)
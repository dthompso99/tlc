
add_subdirectory(vendor/glfw)

INCLUDE_DIRECTORIES(include vendor/glfw/include vendor/glad/include)

FILE(GLOB SOURCE_FILES src/tlc.cpp src/tlc_window.cpp vendor/glad/src/glad.c)

add_library(${PROJECT_NAME} ${SOURCE_FILES})

#target_link_libraries (${PROJECT_NAME} glfw ${GLFW_LIBRARIES})

SET(TLC_LIBS glfw ${GLFW_LIBRARIES} ${PROJECT_NAME} PARENT_SCOPE)

target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    PRIVATE src)

install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME}Config
    ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR})  # This is for Windows

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT ${PROJECT_NAME}Config DESTINATION share/${PROJECT_NAME}/cmake)

export(TARGETS ${PROJECT_NAME} FILE ${PROJECT_NAME}Config.cmake)

#target_include_directories (${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

#add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/resources $<TARGET_FILE_DIR:${PROJECT_NAME}>/resources)


#install(TARGETS ${PROJECT_NAME} 
#        LIBRARY DESTINATION lib
#        ARCHIVE DESTINATION lib/static
#		COMPONENT centauri)

#install(DIRECTORY "${PROJECT_SOURCE_DIR}/resources" DESTINATION "." COMPONENT centauri)


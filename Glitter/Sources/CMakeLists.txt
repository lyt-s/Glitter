foreach (source IN ITEMS ${PROJECT_SOURCES})
    get_filename_component(name "${source}" NAME_WLE)
    add_executable(${name} ${name}.cpp  ${PROJECT_HEADERS}
                               ${PROJECT_SHADERS} ${PROJECT_CONFIGS}
                               ${VENDORS_SOURCES})

target_link_libraries(${name} assimp glfw
                      ${GLFW_LIBRARIES} ${GLAD_LIBRARIES}
                      BulletDynamics BulletCollision LinearMath)

#set_target_properties(${name} PROPERTIES
#     RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${name})

add_custom_command(
    TARGET ${name} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/Glitter/Shaders $<TARGET_FILE_DIR:${name}>
    DEPENDS ${PROJECT_SHADERS})

endforeach() 
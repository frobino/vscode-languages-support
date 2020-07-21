# Create a few variables, used to make this file modular
set(MODULE1_NAME module1)
set(MODULE1_H_DIR include/)
file(GLOB MODULE1_SRC
    "src/*.cpp"
)
set(TEST1_NAME test_${MODULE1_NAME}_getters)
file(GLOB TEST_SRC
    "test/*.cpp"
)

add_executable(${TEST1_NAME} ${TEST_SRC} ${MODULE1_SRC})
target_link_libraries(${TEST1_NAME} -lcunit)
target_include_directories(${TEST1_NAME} PRIVATE ${MODULE1_H_DIR})
add_test(${TEST1_NAME} ${TEST1_NAME})
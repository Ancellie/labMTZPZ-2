cmake_minimum_required(VERSION 3.23)
project(labMTZPZ-2)

set(CMAKE_CXX_STANDARD 20)

# Додаємо директорію з Google Test
add_subdirectory(googletest)

# Додаємо виконуваний файл вашого проекту
add_executable(labMTZPZ-2 main.cpp converter.cpp converter.hpp)

# Додаємо тести до вашого проекту
add_executable(tests tests.cpp converter.cpp) # Додаємо converter.cpp до виконуваного файла з тестами

# Включаємо Google Test у ваш проект
target_link_libraries(labMTZPZ-2 gtest gtest_main)
target_link_libraries(tests gtest gtest_main)

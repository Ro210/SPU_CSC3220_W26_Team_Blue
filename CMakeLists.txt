cmake_minimum_required(VERSION 3.26)
project(SPU_CSC3220_W26_Team_Blue)

set(CMAKE_CXX_STANDARD 20)

set(MYSQL_CONNECTOR_DIR /opt/homebrew/opt/mysql-connector-c++)

add_executable(SPU_CSC3220_W26_Team_Blue
        User.cpp
        User.h
        Main.cpp
        Item.h
        Item.cpp
        Category.h
        Category.cpp)

target_include_directories(SPU_CSC3220_W26_Team_Blue PUBLIC
        ${MYSQL_CONNECTOR_DIR}/include
)

target_link_directories(SPU_CSC3220_W26_Team_Blue PUBLIC
        ${MYSQL_CONNECTOR_DIR}/lib
)

target_link_libraries(SPU_CSC3220_W26_Team_Blue
        mysqlcppconnx
)
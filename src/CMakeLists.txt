set(SRC_LIST Muduo_Log.cpp)
add_library(muduo_hand ${SRC_LIST})
target_link_libraries(muduo_hand pthread)
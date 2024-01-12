cmake_minimum_required(VERSION 2.8)

project(myfunc)

# 如果制作自定义的库文件用到了其他的库，那么就需要link
add_library(${PROJECT_NAME} SHARED
    myadd.cpp
)   
# 如
# 这里使用链接的原因是因为自定义的库依赖于其他的库，如果不依赖，可以不需要
# target_link_libraries(${PROJECT_NAME}
# ${OpenCV_LIBS}
# ${EIGEN3_LIBS}
# ${Pangolin_LIBRARIES}
# ${PROJECT_SOURCE_DIR}/Thirdparty/DBoW2/lib/libDBoW2.so
# ${PROJECT_SOURCE_DIR}/Thirdparty/g2o/lib/libg2o.so
# -lboost_serialization
# -lcrypto
# )

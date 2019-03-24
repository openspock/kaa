cmake_minimum_required(VERSION 3.10)
project(kaasvc)

#include(FindProtobuf)

find_package(Protobuf REQUIRED)
#include_directories(${Protobuf_INCLUDE_DIR})

set(CMAKE_CPP_FLAGS "${CMAKE_CPP_FLAGS} -std=c++17 pkg-config --cflags --lib protobuf grpc")

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

#set(PROTOBUF_PROTOC_EXECUTABLE "${`which protoc`}")
set(PROTO_PATH "${CMAKE_SOURCE_DIR}/protos")
set(KAA_PROTO "${PROTO_PATH}/kaa.proto")
set(GENERATED_PROTOBUF_PATH "${CMAKE_BINARY_DIR}/protos")

set(KAA_PB_CPP_FILE "${GENERATED_PROTOBUF_PATH}/kaa.pb.cpp")
set(KAA_PB_H_FILE "${GENERATED_PROTOBUF_PATH}/kaa.pb.h")
set(KAA_GRPC_PB_CPP_FILE "${GENERATED_PROTOBUF_PATH}/kaa.grpc.pb.cpp")
set(KAA_GRPC_PB_H_FILE "${GENERATED_PROTOBUF_PATH}/kaa.grpc.pb.h")
add_custom_command(
    OUTPUT "${KAA_PB_H_FILE}"
           "${KAA_PB_CPP_FILE}"
           "${KAA_GRPC_PB_H_FILE}"
           "${KAA_GRPC_PB_CPP_FILE}"
    COMMAND ${PROTOBUF_PROTOC_EXECUTABLE}
    ARGS "-I ${PROTO_PATH}}" 
        "--proto_path=${PROTO_PATH}"
        "--grpc_out=${GENERATED_PROTOBUF_PATH}"
        "--plugin=protoc-gen-grpc=/usr/local/bin/grpc_cpp_plugin"
        "${KAA_PROTO}"
    COMMAND ${PROTOBUF_PROTOC_EXECUTABLE}
    ARGS "-I ${PROTO_PATH}"
         "--proto_path=${PROTO_PATH}"
         "--cpp_out=${GENERATED_PROTOBUF_PATH}"
         "${KAA_PROTO}"

    )

set(GENERATED_PROTOBUF_FILES ${KAA_PB_H_FILE} ${KAA_PB_CPP_FILE}
    ${KAA_GRPC_PB_H_FILE} ${KAA_GRPC_PB_CPP_FILE})

file(GLOB_RECURSE INC_FILES src/**/*.h)
file(GLOB_RECURSE SRC_FILES src/**/*.cpp)

add_custom_target(kaa_header ALL DEPENDS ${GENERATED_PROTOBUF_FILES})
include_directories(${GENERATED_PROTOBUF_PATH})

set(SOURCE_FILES src/main.cpp ${GENERATED_PROTOBUF_FILES} ${INC_FILES} ${SRC_FILES})
link_libraries(protoc protobuf grpc++_unsecure gpr grpc++ )
add_executable(kaasvc_server ${SOURCE_FILES})

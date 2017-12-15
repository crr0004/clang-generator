cmake_minimum_required(VERSION 3.4.3)
project(SimpleProject)

find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
set(CMAKE_BUILD_TYPE Debug)

# Set your project compile flags.
# E.g. if using the C++ header files
# you will need to enable C++11 support
# for your compiler.

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})
add_subdirectory(mstch)
include_directories(${mstch_INCLUDE_DIR})

# Now build our tools
add_executable(ClangGeneratorp1 src/main.cpp)
add_executable(ClangGeneratorTooling src/tooling_main.cpp)
target_link_libraries(ClangGeneratorp1 mstch)
target_link_libraries(ClangGeneratorTooling mstch)

# Link against LLVM libraries
target_link_libraries(ClangGeneratorp1 
clangTooling
clangFrontendTool
clangFrontend
clangDriver
clangSerialization
clangCodeGen
clangParse
clangSema
clangStaticAnalyzerFrontend
clangStaticAnalyzerCheckers
clangStaticAnalyzerCore
clangAnalysis
clangARCMigrate
clangRewrite
clangRewriteFrontend
clangEdit
clangAST
clangLex
clangBasic
clang
llvm
version
boost_system-mt
boost_filesystem-mt
	)
target_link_libraries(ClangGeneratorTooling
clangTooling
clangFrontendTool
clangFrontend
clangDriver
clangSerialization
clangCodeGen
clangParse
clangSema
clangStaticAnalyzerFrontend
clangStaticAnalyzerCheckers
clangStaticAnalyzerCore
clangAnalysis
clangARCMigrate
clangRewrite
clangRewriteFrontend
clangEdit
clangAST
clangLex
clangBasic
clang
llvm
version
boost_system-mt
boost_filesystem-mt
	)

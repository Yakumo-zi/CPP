cmake_minimum_required(VERSION 3.22)
project(Reflection)

set(CMAKE_CXX_STANDARD 14)

add_executable(Reflection main.cpp reflect/ClassFactory.h reflect/ClassFactory.cpp utilty/Singleton.h test/a.h test/b.h reflect/ClassRegister.h reflect/ClassField.cpp reflect/ClassField.h reflect/ClassMethod.h)

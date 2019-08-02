cmake_minimum_required(VERSION 3.0)


#THIS IS MAIN CMAKELISTS FOR MY PROJECT
#TO START Testing CHANGE ENABLE_TESTING FLAG TO false
#		^
#		|
#		|
#		|
 set(ENABLE_TESTING false)

 enable_testing()
 set(MAIN_PROJECT_SRC_LIST main.cpp)
 if (ENABLE_TESTING)
   add_executable(main ${MAIN_PROJECT_SRC_LIST})
 else()
   add_subdirectory(functions)
 endif()




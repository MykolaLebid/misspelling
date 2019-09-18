
cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

# project name and language
project(misspelling LANGUAGES CXX)

# require C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# download Google Test sources on our code project repo 
# at configure time using FetchContent
include(FetchContent)

FetchContent_Declare(
	googletest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG release-1.8.0
)

FetchContent_GetProperties(googletest)

if(NOT googletest_POPULATED)
	FetchContent_Populate(googletest)
	## Prevent GoogleTest from overriding our compiler/linker options
	## when building with Visual Studio
	#set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
	
	
	####################################################
	## Prevent GoogleTest from using PThreads
	#set(gtest_disable_pthreads ON CACHE BOOL "" FORCE)
	## adds the targers: gtest, gtest_main, gmock, gmock_main
	####################################################

	add_subdirectory(
		${googletest_SOURCE_DIR}
		${googletest_BINARY_DIR}
	)
	# Silence std::tr1 warning on MSVC
	if(MSVC)
		foreach(_tgt gtest gtest_main gmock gmock_main)
			target_compile_definitions(${_tgt}
				PRIVATE "_SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING"
			)
		endforeach()
	endif()
endif()

add_executable(test_spell "")

target_sources(test_spell
	PRIVATE
	test_main.cpp
	test_misspelling.cpp
	misspelling.cpp
	)

target_link_libraries(test_spell
	PRIVATE
	gtest_main 
	)

enable_testing()

add_test(
	NAME google_test
	COMMAND $<TARGET_FILE:test_spell>
)


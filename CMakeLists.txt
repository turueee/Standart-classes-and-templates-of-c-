cmake_minimum_required(VERSION 3.5) #Проверка версии CMake.

set(PROJECT_NAME Classes_of_STD) #Создаем обычную локальную переменную с именем проекта
project(${PROJECT_NAME}) # Название проекта

set(application Application) #Переменная с именем приложения
set(strlibrary StringLibrary)
set(arrlibrary ArrayLibrary)
set(ritlibrary ReverseIteratorLibrary)
set(alloclibrary AllocatorLibrary)
set(vectorlibrary VectorLibrary)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) 
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/TString)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/TArray)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/TReverseIterator)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/TAllocator)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/TVector)

add_subdirectory(Main)
add_subdirectory(TString)
add_subdirectory(TArray)
add_subdirectory(TReverseIterator)
add_subdirectory(TAllocator)
add_subdirectory(TVector)
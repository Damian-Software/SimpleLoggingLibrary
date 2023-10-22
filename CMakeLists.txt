#************************************************************************
#*
#* Copyright (C) 2023 Damian-Software
#* All rights reserved.
#*
#* Author: Damián Zelený
#* Contact: Damian-Software (dzeleny@damiansoftware.com)
#*
#************************************************************************

cmake_minimum_required (VERSION 3.8)

# Pokud je to podporováno, povolte Opětovné načítání za provozu pro kompilátory MSVC.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

# Nastavení název projektu a verze
project ("SimpleLoggingLibrary" VERSION 1.0.0)

# include složky zdrojakama
include_directories(src)
include_directories(binary)

# Přidejte zdrojový kód ke spustitelnému souboru tohoto projektu.
add_executable (SimpleLoggingLibrary "binary/SimpleLoggingLibrary.cpp" "src/SimpleLoggingLibrary.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET SimpleLoggingLibrary PROPERTY CXX_STANDARD 20)
endif()

# Povolte standard C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# if (WIN32)
#    add_library(libMUnit STATIC "binary/libMUnit.cpp")
# else()
#    add_library(libMUnit SHARED "binary/libMUnit.cpp")
# endif()

# Přidejte podporu pro generování .rpm balíčku pomocí CPack
set(CPACK_GENERATOR "RPM")
set(CPACK_PACKAGE_NAME "libMUnit")

set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})

set(CPACK_PACKAGE_DESCRIPTION "Lib Multiplatform Loggin")
set(CPACK_PACKAGE_CONTACT "dzeleny@damiansoftware.com")

include(CTest)
include(CPack)

# Instalační cíle
# install(TARGETS libMUnit DESTINATION /usr/lib64)
# install(FILES libMUnit.h DESTINATION /usr/include)
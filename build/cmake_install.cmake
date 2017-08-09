# Install script for directory: /afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "RelWithDebInfo")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/GBL/V01-17-01/lib/libGBL.so.1.17.1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libEutelescope.so.1.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libEutelescope.so.1.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libEutelescope.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Marlin/v01-09/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lcio/v02-07-02/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/gear/v01-06/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CLHEP/2.1.4.1/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/ilcutil/v01-02-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/MarlinUtil/v01-08/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CED/v01-09-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/RAIDA/v01-07/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/root/5.34.30/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lccd/v01-03-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/GBL/V01-17-01/lib")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE FILES
    "/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/build/lib/libEutelescope.so.1.0.0"
    "/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/build/lib/libEutelescope.so.1.0"
    "/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/build/lib/libEutelescope.so"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libEutelescope.so.1.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libEutelescope.so.1.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libEutelescope.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHANGE
           FILE "${file}"
           OLD_RPATH "/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Marlin/v01-09/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lcio/v02-07-02/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/gear/v01-06/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CLHEP/2.1.4.1/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/ilcutil/v01-02-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/MarlinUtil/v01-08/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CED/v01-09-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/RAIDA/v01-07/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/root/5.34.30/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lccd/v01-03-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/GBL/V01-17-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/lib:"
           NEW_RPATH "/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Marlin/v01-09/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lcio/v02-07-02/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/gear/v01-06/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CLHEP/2.1.4.1/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/ilcutil/v01-02-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/MarlinUtil/v01-08/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CED/v01-09-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/RAIDA/v01-07/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/root/5.34.30/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lccd/v01-03-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/GBL/V01-17-01/lib")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFEI4Double.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFEI4Double.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFEI4Double.so"
         RPATH "/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Marlin/v01-09/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lcio/v02-07-02/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/gear/v01-06/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CLHEP/2.1.4.1/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/ilcutil/v01-02-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/MarlinUtil/v01-08/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CED/v01-09-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/RAIDA/v01-07/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/root/5.34.30/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lccd/v01-03-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/GBL/V01-17-01/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE FILES "/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/build/lib/libFEI4Double.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFEI4Double.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFEI4Double.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFEI4Double.so"
         OLD_RPATH "/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Marlin/v01-09/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lcio/v02-07-02/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/gear/v01-06/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CLHEP/2.1.4.1/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/ilcutil/v01-02-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/MarlinUtil/v01-08/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CED/v01-09-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/RAIDA/v01-07/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/root/5.34.30/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lccd/v01-03-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/GBL/V01-17-01/lib:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"
         NEW_RPATH "/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Marlin/v01-09/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lcio/v02-07-02/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/gear/v01-06/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CLHEP/2.1.4.1/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/ilcutil/v01-02-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/MarlinUtil/v01-08/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CED/v01-09-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/RAIDA/v01-07/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/root/5.34.30/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lccd/v01-03-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/GBL/V01-17-01/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFEI4Double.so")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFEI4FourChip.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFEI4FourChip.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFEI4FourChip.so"
         RPATH "/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Marlin/v01-09/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lcio/v02-07-02/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/gear/v01-06/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CLHEP/2.1.4.1/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/ilcutil/v01-02-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/MarlinUtil/v01-08/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CED/v01-09-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/RAIDA/v01-07/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/root/5.34.30/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lccd/v01-03-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/GBL/V01-17-01/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE FILES "/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/build/lib/libFEI4FourChip.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFEI4FourChip.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFEI4FourChip.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFEI4FourChip.so"
         OLD_RPATH "/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Marlin/v01-09/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lcio/v02-07-02/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/gear/v01-06/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CLHEP/2.1.4.1/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/ilcutil/v01-02-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/MarlinUtil/v01-08/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CED/v01-09-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/RAIDA/v01-07/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/root/5.34.30/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lccd/v01-03-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/GBL/V01-17-01/lib:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"
         NEW_RPATH "/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Marlin/v01-09/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lcio/v02-07-02/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/gear/v01-06/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CLHEP/2.1.4.1/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/ilcutil/v01-02-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/MarlinUtil/v01-08/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CED/v01-09-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/RAIDA/v01-07/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/root/5.34.30/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lccd/v01-03-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/GBL/V01-17-01/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFEI4FourChip.so")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFEI4Single.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFEI4Single.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFEI4Single.so"
         RPATH "/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Marlin/v01-09/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lcio/v02-07-02/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/gear/v01-06/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CLHEP/2.1.4.1/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/ilcutil/v01-02-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/MarlinUtil/v01-08/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CED/v01-09-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/RAIDA/v01-07/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/root/5.34.30/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lccd/v01-03-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/GBL/V01-17-01/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE FILES "/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/build/lib/libFEI4Single.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFEI4Single.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFEI4Single.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFEI4Single.so"
         OLD_RPATH "/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Marlin/v01-09/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lcio/v02-07-02/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/gear/v01-06/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CLHEP/2.1.4.1/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/ilcutil/v01-02-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/MarlinUtil/v01-08/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CED/v01-09-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/RAIDA/v01-07/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/root/5.34.30/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lccd/v01-03-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/GBL/V01-17-01/lib:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"
         NEW_RPATH "/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Marlin/v01-09/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lcio/v02-07-02/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/gear/v01-06/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CLHEP/2.1.4.1/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/ilcutil/v01-02-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/MarlinUtil/v01-08/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CED/v01-09-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/RAIDA/v01-07/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/root/5.34.30/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lccd/v01-03-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/GBL/V01-17-01/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFEI4Single.so")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFEI4FourChipUK_G4.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFEI4FourChipUK_G4.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFEI4FourChipUK_G4.so"
         RPATH "/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Marlin/v01-09/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lcio/v02-07-02/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/gear/v01-06/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CLHEP/2.1.4.1/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/ilcutil/v01-02-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/MarlinUtil/v01-08/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CED/v01-09-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/RAIDA/v01-07/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/root/5.34.30/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lccd/v01-03-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/GBL/V01-17-01/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE FILES "/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/build/lib/libFEI4FourChipUK_G4.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFEI4FourChipUK_G4.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFEI4FourChipUK_G4.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFEI4FourChipUK_G4.so"
         OLD_RPATH "/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Marlin/v01-09/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lcio/v02-07-02/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/gear/v01-06/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CLHEP/2.1.4.1/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/ilcutil/v01-02-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/MarlinUtil/v01-08/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CED/v01-09-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/RAIDA/v01-07/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/root/5.34.30/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lccd/v01-03-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/GBL/V01-17-01/lib:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"
         NEW_RPATH "/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Marlin/v01-09/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lcio/v02-07-02/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/gear/v01-06/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CLHEP/2.1.4.1/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/ilcutil/v01-02-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/MarlinUtil/v01-08/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CED/v01-09-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/RAIDA/v01-07/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/root/5.34.30/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lccd/v01-03-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/GBL/V01-17-01/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFEI4FourChipUK_G4.so")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libMimosa26.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libMimosa26.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libMimosa26.so"
         RPATH "/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Marlin/v01-09/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lcio/v02-07-02/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/gear/v01-06/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CLHEP/2.1.4.1/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/ilcutil/v01-02-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/MarlinUtil/v01-08/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CED/v01-09-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/RAIDA/v01-07/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/root/5.34.30/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lccd/v01-03-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/GBL/V01-17-01/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE FILES "/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/build/lib/libMimosa26.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libMimosa26.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libMimosa26.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libMimosa26.so"
         OLD_RPATH "/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Marlin/v01-09/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lcio/v02-07-02/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/gear/v01-06/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CLHEP/2.1.4.1/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/ilcutil/v01-02-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/MarlinUtil/v01-08/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CED/v01-09-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/RAIDA/v01-07/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/root/5.34.30/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lccd/v01-03-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/GBL/V01-17-01/lib:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"
         NEW_RPATH "/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Marlin/v01-09/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lcio/v02-07-02/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/gear/v01-06/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CLHEP/2.1.4.1/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/ilcutil/v01-02-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/MarlinUtil/v01-08/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CED/v01-09-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/RAIDA/v01-07/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/root/5.34.30/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lccd/v01-03-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/GBL/V01-17-01/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libMimosa26.so")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFEI4Single250x50.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFEI4Single250x50.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFEI4Single250x50.so"
         RPATH "/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Marlin/v01-09/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lcio/v02-07-02/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/gear/v01-06/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CLHEP/2.1.4.1/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/ilcutil/v01-02-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/MarlinUtil/v01-08/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CED/v01-09-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/RAIDA/v01-07/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/root/5.34.30/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lccd/v01-03-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/GBL/V01-17-01/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE FILES "/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/build/lib/libFEI4Single250x50.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFEI4Single250x50.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFEI4Single250x50.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFEI4Single250x50.so"
         OLD_RPATH "/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Marlin/v01-09/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lcio/v02-07-02/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/gear/v01-06/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CLHEP/2.1.4.1/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/ilcutil/v01-02-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/MarlinUtil/v01-08/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CED/v01-09-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/RAIDA/v01-07/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/root/5.34.30/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lccd/v01-03-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/GBL/V01-17-01/lib:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"
         NEW_RPATH "/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Marlin/v01-09/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lcio/v02-07-02/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/gear/v01-06/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CLHEP/2.1.4.1/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/ilcutil/v01-02-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/MarlinUtil/v01-08/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CED/v01-09-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/RAIDA/v01-07/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/root/5.34.30/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lccd/v01-03-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/GBL/V01-17-01/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFEI4Single250x50.so")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/pede2lcio" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/pede2lcio")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/pede2lcio"
         RPATH "/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Marlin/v01-09/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lcio/v02-07-02/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/gear/v01-06/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CLHEP/2.1.4.1/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/ilcutil/v01-02-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/MarlinUtil/v01-08/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CED/v01-09-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/RAIDA/v01-07/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/root/5.34.30/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lccd/v01-03-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/GBL/V01-17-01/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/build/bin/pede2lcio")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/pede2lcio" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/pede2lcio")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/pede2lcio"
         OLD_RPATH "/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Marlin/v01-09/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lcio/v02-07-02/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/gear/v01-06/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CLHEP/2.1.4.1/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/ilcutil/v01-02-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/MarlinUtil/v01-08/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CED/v01-09-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/RAIDA/v01-07/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/root/5.34.30/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lccd/v01-03-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/GBL/V01-17-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/build/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/lib:"
         NEW_RPATH "/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Marlin/v01-09/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lcio/v02-07-02/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/gear/v01-06/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CLHEP/2.1.4.1/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/ilcutil/v01-02-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/MarlinUtil/v01-08/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CED/v01-09-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/RAIDA/v01-07/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/root/5.34.30/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lccd/v01-03-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/GBL/V01-17-01/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/pede2lcio")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/pedestalmerge" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/pedestalmerge")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/pedestalmerge"
         RPATH "/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Marlin/v01-09/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lcio/v02-07-02/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/gear/v01-06/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CLHEP/2.1.4.1/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/ilcutil/v01-02-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/MarlinUtil/v01-08/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CED/v01-09-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/RAIDA/v01-07/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/root/5.34.30/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lccd/v01-03-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/GBL/V01-17-01/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/build/bin/pedestalmerge")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/pedestalmerge" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/pedestalmerge")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/pedestalmerge"
         OLD_RPATH "/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Marlin/v01-09/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lcio/v02-07-02/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/gear/v01-06/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CLHEP/2.1.4.1/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/ilcutil/v01-02-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/MarlinUtil/v01-08/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CED/v01-09-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/RAIDA/v01-07/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/root/5.34.30/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lccd/v01-03-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/GBL/V01-17-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/build/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/lib:"
         NEW_RPATH "/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Marlin/v01-09/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lcio/v02-07-02/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/gear/v01-06/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CLHEP/2.1.4.1/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/ilcutil/v01-02-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/MarlinUtil/v01-08/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/CED/v01-09-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/RAIDA/v01-07/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/root/5.34.30/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/lccd/v01-03-01/lib:/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/GBL/V01-17-01/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/pedestalmerge")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  EXECUTE_PROCESS(COMMAND ln -sf /afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/jobsub/jobsub.py /afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/bin/jobsub)
    EXECUTE_PROCESS(COMMAND ln -sf /afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/jobsub/jobsub.py /afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/bin/jobsub.py)
    EXECUTE_PROCESS(COMMAND ln -sf /afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/tools/pyroplot/pyroplot.py /afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/bin/pyroplot.py)
    EXECUTE_PROCESS(COMMAND ln -sf /afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/tools/pyroplot/pyroplot.py /afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/bin/pyroplot)
    EXECUTE_PROCESS(COMMAND ln -sf /afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/tools/parsepede/parsemilleout.sh /afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/bin/parsemilleout.sh)
    EXECUTE_PROCESS(COMMAND ln -sf /afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/tools/resIntoSteer.py /afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/bin/resIntoSteer.py)
    EXECUTE_PROCESS(COMMAND ln -sf /afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/tools/iterAlign.py /afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/bin/iterAlign )
    EXECUTE_PROCESS(COMMAND ln -sf /afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/tools/gearUpdate.py /afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/bin/gearUpdate )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/build/external/CMSPixelDecoder/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/afs/desy.de/user/y/yanwing/ILCSOFT/v01-17-10/Eutelescope/v1.0/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")

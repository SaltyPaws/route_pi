##---------------------------------------------------------------------------
## Author:      SaltyPaws aka. Walbert Schulpen
## Copyright:
## License:     wxWidgets License
##---------------------------------------------------------------------------

# define minimum cmake version
CMAKE_MINIMUM_REQUIRED(VERSION 2.6.2)

PROJECT(route_pi)

SET(PACKAGE_NAME route_pi)
SET(VERBOSE_NAME Route)
SET(TITLE_NAME Route)
SET(CPACK_PACKAGE_CONTACT "SaltyPaws")

SET(VERSION_MAJOR "1")
SET(VERSION_MINOR "1")

#SET(CMAKE_BUILD_TYPE Debug)

# Definitions
add_definitions (
-D_FILE_OFFSET_BITS=64
-D_LARGEFILE_SOURCE
-DLIBUNRAR_BUILD
-DRARDLL
-DUNRAR
-DSILENT
)

INCLUDE("cmake/PluginConfigure.cmake")

SET(SRC_ROUTE
            src/route_pi.h
            src/route_pi.cpp
            src/icons.h
            src/icons.cpp
	    src/routegui.h
	    src/routegui.cpp
	    src/routegui_impl.cpp
	    src/routegui_impl.h
	    src/NavFunc.h
	    src/NavFunc.cpp
	    src/vincenty.h
	    src/vincenty.cpp
#	    src/georef.h
#	    src/georef.c
	    src/OpenCPN/ocpn_plugin.h
	)

SET(SRC_FROM_OCPN 	
	src/OpenCPN/cutil.h
	src/OpenCPN/cutil.cpp
	src/OpenCPN/georef.h
	src/OpenCPN/georef.cpp
	src/OpenCPN/gpxdocument.h
	src/OpenCPN/gpxdocument.cpp	    	
	)

INCLUDE_DIRECTORIES(
  src
  src/OpenCPN
)

IF(UNIX)
 INCLUDE("cmake/FindTinyXML.cmake")
 FIND_PACKAGE(TinyXML QUIET)
ENDIF(UNIX)

IF(TINYXML_FOUND)
 message (STATUS "Building with system tinyxml")
 INCLUDE_DIRECTORIES(${TINYXML_INCLUDE_DIR})
 ADD_LIBRARY(${PACKAGE_NAME} SHARED ${SRC_ROUTE} ${SRC_FROM_OCPN})
 TARGET_LINK_LIBRARIES(${PACKAGE_NAME} ${TINYXML_LIBRARIES})
ELSE(TINYXML_FOUND)
 message (STATUS "Building with embedded tinyxml")
 INCLUDE_DIRECTORIES(src/tinyxml/)
 SET(SRC_LTINYXML
            src/TinyXML/tinyxml.cpp
            src/TinyXML/tinyxmlparser.cpp
            src/TinyXML/tinyxmlerror.cpp
 )
 ADD_LIBRARY(${PACKAGE_NAME} SHARED ${SRC_ROUTE} ${SRC_FROM_OCPN} ${SRC_LTINYXML})
ENDIF(TINYXML_FOUND)
ADD_DEFINITIONS(-DTIXML_USE_STL)

INCLUDE("cmake/PluginInstall.cmake")
INCLUDE("cmake/PluginLocalization.cmake")
INCLUDE("cmake/PluginPackage.cmake")


##---------------------------------------------------------------------------
## Author:      SaltyPaws aka. Walbert Schulpen
## Copyright:
## License:     wxWidgets License
##---------------------------------------------------------------------------

# define minimum cmake version
CMAKE_MINIMUM_REQUIRED(VERSION 2.6.2)
IF(NOT APPLE) #wxCTB not known to work on Mac
# This should be 2.8.0 to have FindGTK2 module
IF (COMMAND cmake_policy)
  CMAKE_POLICY(SET CMP0003 OLD)
  CMAKE_POLICY(SET CMP0005 OLD)
  CMAKE_POLICY(SET CMP0011 OLD)
ENDIF (COMMAND cmake_policy)

PROJECT(ROUTE_pi)

SET(PACKAGE_NAME ROUTE_pi)
SET(PLUGIN_SOURCE_DIR .)
MESSAGE (STATUS "*** Building ${PACKAGE_NAME} ***")

#SET(CMAKE_BUILD_TYPE Debug)

INCLUDE_DIRECTORIES(
	${CMAKE_SOURCE_DIR}/include 
	${CMAKE_SOURCE_DIR}/src
	${CMAKE_SOURCE_DIR}/plugins/route_pi/src/expression_parser


)



# require proper c++
#ADD_DEFINITIONS( "-Wall -ansi -pedantic -Wno-variadic-macros" )
#TODO: Should we use  -fno-stack-protector
#  IF NOT DEBUGGING CFLAGS="-O2 -march=native"
IF(NOT WIN32)
 ADD_DEFINITIONS( "-Wall -g -fexceptions -fvisibility=hidden" )
 ADD_DEFINITIONS( -DOMIT_GEOS -DOMIT_PROJ -DOMIT_FREEXL -DSQLITE_ENABLE_RTREE=1 -DVERSION="\\"3.0.1\\"")

 IF(NOT APPLE)
  SET(CMAKE_SHARED_LINKER_FLAGS "-Wl,-Bsymbolic")
 ELSE(NOT APPLE)
  SET(CMAKE_SHARED_LINKER_FLAGS "-Wl -undefined dynamic_lookup")
 ENDIF(NOT APPLE)

ENDIF(NOT WIN32)

# Add some definitions to satisfy MS
IF(WIN32)
    ADD_DEFINITIONS(-D__MSVC__)
    ADD_DEFINITIONS(-D_CRT_NONSTDC_NO_DEPRECATE -D_CRT_SECURE_NO_DEPRECATE)
    ADD_DEFINITIONS( /DOMIT_GEOS /DOMIT_PROJ /DOMIT_FREEXL /DSQLITE_ENABLE_RTREE=1 /DVERSION="\\"3.0.1\\"")
ENDIF(WIN32)


#SET(wxWidgets_USE_LIBS base core net xml html adv)
#SET(BUILD_SHARED_LIBS TRUE)
#FIND_PACKAGE(wxWidgets REQUIRED)

INCLUDE(${wxWidgets_USE_FILE})

FIND_PACKAGE(Gettext REQUIRED)


# For convenience we define the sources as a variable. You can add
# header files and cpp/c files and CMake will sort them out



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
	)

SET(SRC_FROM_OCPN 	

	../../../include/georef.h
	../../../src/georef.c
	../../../include/gpxdocument.h
	../../../src/gpxdocument.cpp	    	
	)

SET(SRC_TINYXML
	../../../include/tinyxml.h
        ../../../src/tinyxml.cpp
        ../../../src/tinyxmlparser.cpp
        ../../../src/tinyxmlerror.cpp
	)

IF(TINYXML_FOUND)
    message (STATUS "Building with tinyxml includes")
    INCLUDE_DIRECTORIES(${TINYXML_INCLUDE_DIR})
    ADD_DEFINITIONS(-DTIXML_USE_STL)
ELSE(TINYXML_FOUND)
    message (STATUS "tinyxml library not found")
    SET(SRC_SURVEY ${SRC_SURVEY} ${SRC_TINYXML})
    ADD_DEFINITIONS(-DTIXML_USE_STL)
ENDIF(TINYXML_FOUND)

ADD_LIBRARY(${PACKAGE_NAME} SHARED ${SRC_ROUTE} ${SRC_FROM_OCPN})

IF(WIN32)
  SET(OPENCPN_IMPORT_LIB "../../${CMAKE_CFG_INTDIR}/${PARENT}")
  TARGET_LINK_LIBRARIES( ${PACKAGE_NAME} ${OPENCPN_IMPORT_LIB} )
  ADD_DEPENDENCIES(${PACKAGE_NAME} ${PARENT})
  TARGET_LINK_LIBRARIES( ${PACKAGE_NAME} C:/OSGeo4W/lib/iconv.lib )
ENDIF(WIN32)

TARGET_LINK_LIBRARIES( ${PACKAGE_NAME} ${ICONV_LIBRARIES} )

TARGET_LINK_LIBRARIES( ${PACKAGE_NAME} ${wxWidgets_LIBRARIES} )

IF(APPLE)
 FIND_PACKAGE(ZLIB REQUIRED)
 TARGET_LINK_LIBRARIES( ${PACKAGE_NAME} ${ZLIB_LIBRARIES} )
ENDIF(APPLE)

IF(APPLE)
	INSTALL(TARGETS ${PACKAGE_NAME} RUNTIME LIBRARY DESTINATION ${CMAKE_BINARY_DIR}/OpenCPN.app/Contents/SharedSupport/plugins)
ENDIF(APPLE)

IF(UNIX AND NOT APPLE)
	INSTALL(TARGETS ${PACKAGE_NAME} RUNTIME LIBRARY DESTINATION ${PREFIX_PLUGINS})
ENDIF(UNIX AND NOT APPLE)

IF(WIN32)
INSTALL(TARGETS ${PACKAGE_NAME} RUNTIME DESTINATION "plugins")
ENDIF(WIN32)

# find src/ -name \*.cpp -or -name \*.c -or -name \*.h -or -name \*.hpp >po/POTFILES.in
FIND_PROGRAM(GETTEXT_XGETTEXT_EXECUTABLE xgettext)
IF (GETTEXT_XGETTEXT_EXECUTABLE)
ADD_CUSTOM_COMMAND(
   OUTPUT po/${PACKAGE_NAME}.pot.dummy
   COMMAND ${GETTEXT_XGETTEXT_EXECUTABLE} --force-po --package-name=${PACKAGE_NAME} --package-version="${PACKAGE_VERSION}" --output=po/${PACKAGE_NAME}.pot  --keyword=_ --width=80 --files-from=${CMAKE_CURRENT_SOURCE_DIR}/po/POTFILES.in
   DEPENDS po/POTFILES.in po/${PACKAGE_NAME}.pot
   WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
   COMMENT "ROUTE-pot-update [${PACKAGE_NAME}]: Generated pot file."
)
ADD_CUSTOM_TARGET(ROUTE-pot-update COMMENT "ROUTE-pot-update: Done." DEPENDS po/${PACKAGE_NAME}.pot.dummy)

ENDIF(GETTEXT_XGETTEXT_EXECUTABLE )

MACRO(GETTEXT_UPDATE_PO _potFile)
   SET(_poFiles ${_potFile})
   GET_FILENAME_COMPONENT(_absPotFile ${_potFile} ABSOLUTE)

   FOREACH (_currentPoFile ${ARGN})
      GET_FILENAME_COMPONENT(_absFile ${_currentPoFile} ABSOLUTE)
      GET_FILENAME_COMPONENT(_poBasename ${_absFile} NAME_WE)

      ADD_CUSTOM_COMMAND(
         OUTPUT ${_absFile}.dummy
         COMMAND ${GETTEXT_MSGMERGE_EXECUTABLE} --width=80 --strict --quiet --update --backup=none --no-location -s ${_absFile} ${_absPotFile}
         DEPENDS ${_absPotFile} ${_absFile}
         COMMENT "ROUTE-po-update [${_poBasename}]: Updated po file."
      )

      SET(_poFiles ${_poFiles} ${_absFile}.dummy)

   ENDFOREACH (_currentPoFile )

   ADD_CUSTOM_TARGET(ROUTE-po-update COMMENT "ROUTE-po-update: Done." DEPENDS ${_poFiles})
ENDMACRO(GETTEXT_UPDATE_PO)

IF (GETTEXT_MSGMERGE_EXECUTABLE)
FILE(GLOB PACKAGE_PO_FILES po/*.po)
GETTEXT_UPDATE_PO(po/${PACKAGE_NAME}.pot ${PACKAGE_PO_FILES})
ENDIF(GETTEXT_MSGMERGE_EXECUTABLE)

SET(_gmoFiles)
MACRO(GETTEXT_BUILD_MO)
   FOREACH (_poFile ${ARGN})
      GET_FILENAME_COMPONENT(_absFile ${_poFile} ABSOLUTE)
      GET_FILENAME_COMPONENT(_poBasename ${_absFile} NAME_WE)
      SET(_gmoFile ${CMAKE_CURRENT_BINARY_DIR}/${_poBasename}.mo)

      ADD_CUSTOM_COMMAND(
         OUTPUT ${_gmoFile}
         COMMAND ${GETTEXT_MSGFMT_EXECUTABLE} --check -o ${_gmoFile} ${_absFile}
         DEPENDS ${_absFile}
         COMMENT "ROUTE-i18n [${_poBasename}]: Created mo file."
      )

If(APPLE)
      INSTALL(FILES ${_gmoFile} DESTINATION ${CMAKE_BINARY_DIR}/OpenCPN.app/Contents/Resources/${_poBasename}.lproj RENAME opencpn-${PACKAGE_NAME}.mo )
ELSE(APPLE)
      INSTALL(FILES ${_gmoFile} DESTINATION ${PREFIX_DATA}/locale/${_poBasename}/LC_MESSAGES RENAME opencpn-${PACKAGE_NAME}.mo )
ENDIF(APPLE)
      SET(_gmoFiles ${_gmoFiles} ${_gmoFile})
   ENDFOREACH (_poFile )
ENDMACRO(GETTEXT_BUILD_MO)

if(GETTEXT_MSGFMT_EXECUTABLE)
   FILE(GLOB PACKAGE_PO_FILES po/*.po)
   GETTEXT_BUILD_MO(${PACKAGE_PO_FILES})
   ADD_CUSTOM_TARGET(ROUTE-i18n COMMENT "ROUTE-i18n: Done." DEPENDS ${_gmoFiles})
   #ADD_DEPENDENCIES(ROUTE-i18n ${PACKAGE_PO_FILES})
   ADD_DEPENDENCIES(${PACKAGE_NAME} ROUTE-i18n)
ENDIF(GETTEXT_MSGFMT_EXECUTABLE)
ENDIF(NOT APPLE)

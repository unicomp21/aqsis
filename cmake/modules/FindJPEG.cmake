# Custom Aqsis specific version of FindTIFF
SET(AQSIS_JPEG_FOUND 0)

SET(AQSIS_JPEG_INCLUDE_SEARCHPATH)
SET(AQSIS_JPEG_LIBRARY_NAMES jpeg)

IF(WIN32)
	IF(AQSIS_WIN32LIBS)
		SET(AQSIS_JPEG_INCLUDE_SEARCHPATH ${AQSIS_JPEG_INCLUDE_SEARCHPATH} ${AQSIS_WIN32LIBS}/jpeg/include)
		IF(MSVC AND MSVC80)
			SET(AQSIS_JPEG_LIBRARIES_DIR ${AQSIS_WIN32LIBS}/jpeg/lib/vc8 CACHE PATH "Semi-colon separated list of paths to search for jpeg libraries")
			SET(AQSIS_JPEG_LIBRARY_NAMES ${AQSIS_JPEG_LIBRARY_NAMES} libjpeg)
		ELSEIF(MSVC AND MSVC90)
			SET(AQSIS_JPEG_LIBRARIES_DIR ${AQSIS_WIN32LIBS}/jpeg/lib/vc9 CACHE PATH "Semi-colon separated list of paths to search for jpeg libraries")
			SET(AQSIS_JPEG_LIBRARY_NAMES ${AQSIS_JPEG_LIBRARY_NAMES} libjpeg)
		ELSE(MSVC AND MSVC80)
			IF(MINGW)
				SET(AQSIS_JPEG_LIBRARIES_DIR ${AQSIS_WIN32LIBS}/jpeg/lib/mingw CACHE PATH "Semi-colon separated list of paths to search for jpeg libraries")
				SET(AQSIS_JPEG_LIBRARY_NAMES ${AQSIS_JPEG_LIBRARY_NAMES} jpeg)
			ENDIF(MINGW)
		ENDIF(MSVC AND MSVC80)
	ENDIF(AQSIS_WIN32LIBS)
ELSE(WIN32)
	SET(AQSIS_JPEG_LIBRARIES_DIR "" CACHE PATH "Semi-colon separated list of paths to search for jpeg libraries")
ENDIF(WIN32)

FIND_PATH(AQSIS_JPEG_INCLUDE_DIR
			jpeglib.h
			PATHS ${AQSIS_JPEG_INCLUDE_SEARCHPATH}
			DOC "Location of the jpeg headers"
			)

FIND_LIBRARY(AQSIS_JPEG_LIBRARIES
			NAMES ${AQSIS_JPEG_LIBRARY_NAMES}	
			PATHS ${AQSIS_JPEG_LIBRARIES_DIR}
			DOC "Location of the jpeg library"
			)
MARK_AS_ADVANCED(AQSIS_JPEG_LIBRARIES)


STRING(COMPARE EQUAL "${AQSIS_JPEG_INCLUDE_DIR}" "AQSIS_JPEG_INCLUDE-NOTFOUND" AQSIS_JPEG_INCLUDE_NOTFOUND)
STRING(COMPARE EQUAL "${AQSIS_JPEG_LIBRARIES}" "AQSIS_JPEG_LIBRARIES-NOTFOUND" AQSIS_JPEG_LIBRARIES_NOTFOUND)

IF(NOT AQSIS_JPEG_LIBRARIES_NOTFOUND AND NOT AQSIS_JPEG_INCLUDE_NOTFOUND)
	SET(AQSIS_JPEG_FOUND 1)
ENDIF(NOT AQSIS_JPEG_LIBRARIES_NOTFOUND AND NOT AQSIS_JPEG_INCLUDE_NOTFOUND)


#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW_TDM-Windows
CND_DLIB_EXT=dll
CND_CONF=win64-debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/appdate.o \
	${OBJECTDIR}/src/application.o \
	${OBJECTDIR}/src/apptime.o \
	${OBJECTDIR}/src/coordinates.o \
	${OBJECTDIR}/src/database.o \
	${OBJECTDIR}/src/entity.o \
	${OBJECTDIR}/src/event.o \
	${OBJECTDIR}/src/main.o \
	${OBJECTDIR}/src/properties.o \
	${OBJECTDIR}/src/ui.o \
	${OBJECTDIR}/src/world.o


# C Compiler Flags
CFLAGS=-m64

# CC Compiler Flags
CCFLAGS=-m64
CXXFLAGS=-m64

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=--64

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk tbw-debug.exe

tbw-debug.exe: ${OBJECTFILES}
	${LINK.cc} -o tbw-debug ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/appdate.o: src/appdate.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/appdate.o src/appdate.cpp

${OBJECTDIR}/src/application.o: src/application.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/application.o src/application.cpp

${OBJECTDIR}/src/apptime.o: src/apptime.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/apptime.o src/apptime.cpp

${OBJECTDIR}/src/coordinates.o: src/coordinates.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/coordinates.o src/coordinates.cpp

${OBJECTDIR}/src/database.o: src/database.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/database.o src/database.cpp

${OBJECTDIR}/src/entity.o: src/entity.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/entity.o src/entity.cpp

${OBJECTDIR}/src/event.o: src/event.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/event.o src/event.cpp

${OBJECTDIR}/src/main.o: src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/main.o src/main.cpp

${OBJECTDIR}/src/properties.o: src/properties.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/properties.o src/properties.cpp

${OBJECTDIR}/src/ui.o: src/ui.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ui.o src/ui.cpp

${OBJECTDIR}/src/world.o: src/world.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/world.o src/world.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} tbw-debug.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc

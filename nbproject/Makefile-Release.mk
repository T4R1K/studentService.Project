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
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/baza/ispit.o \
	${OBJECTDIR}/baza/predmet.o \
	${OBJECTDIR}/baza/profesor.o \
	${OBJECTDIR}/baza/student.o \
	${OBJECTDIR}/baza/studijski\ program.o \
	${OBJECTDIR}/baza/usmjerenje.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-std=c++11
CXXFLAGS=-std=c++11

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/st-sluzbaold.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/st-sluzbaold.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/st-sluzbaold ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/baza/ispit.o: baza/ispit.cpp
	${MKDIR} -p ${OBJECTDIR}/baza
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/baza/ispit.o baza/ispit.cpp

${OBJECTDIR}/baza/predmet.o: baza/predmet.cpp
	${MKDIR} -p ${OBJECTDIR}/baza
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/baza/predmet.o baza/predmet.cpp

${OBJECTDIR}/baza/profesor.o: baza/profesor.cpp
	${MKDIR} -p ${OBJECTDIR}/baza
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/baza/profesor.o baza/profesor.cpp

${OBJECTDIR}/baza/student.o: baza/student.cpp
	${MKDIR} -p ${OBJECTDIR}/baza
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/baza/student.o baza/student.cpp

.NO_PARALLEL:${OBJECTDIR}/baza/studijski\ program.o
${OBJECTDIR}/baza/studijski\ program.o: baza/studijski\ program.cpp
	${MKDIR} -p ${OBJECTDIR}/baza
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/baza/studijski\ program.o baza/studijski\ program.cpp

${OBJECTDIR}/baza/usmjerenje.o: baza/usmjerenje.cpp
	${MKDIR} -p ${OBJECTDIR}/baza
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/baza/usmjerenje.o baza/usmjerenje.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc

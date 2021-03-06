#############################################################################
# Makefile for building: sudoku
# Generated by qmake (2.01a) (Qt 4.5.0) on: So. Jul 5 21:59:50 2009
# Project:  sudoku.pro
# Template: app
# Command: /usr/bin/qmake -unix CONFIG+=hpdf -o Makefile sudoku.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -I. -I.
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib -lQtGui -lQtCore -lpthread
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -sf
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = sudoku.cpp \
		mainwindow.cpp \
		element.cpp \
		puzzle.cpp \
		field.cpp \
		gamecontrol.cpp moc_mainwindow.cpp \
		moc_element.cpp \
		moc_gamecontrol.cpp \
		qrc_sudoku.cpp
OBJECTS       = sudoku.o \
		mainwindow.o \
		element.o \
		puzzle.o \
		field.o \
		gamecontrol.o \
		moc_mainwindow.o \
		moc_element.o \
		moc_gamecontrol.o \
		qrc_sudoku.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/static.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		sudoku.pro
QMAKE_TARGET  = sudoku
DESTDIR       = 
TARGET        = sudoku

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: sudoku.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/static.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/lib/libQtGui.prl \
		/usr/lib/libQtCore.prl
	$(QMAKE) -unix CONFIG+=hpdf -o Makefile sudoku.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/static.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/lib/libQtGui.prl:
/usr/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -unix CONFIG+=hpdf -o Makefile sudoku.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/sudoku1.0.0 || $(MKDIR) .tmp/sudoku1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/sudoku1.0.0/ && $(COPY_FILE) --parents mainwindow.h sudoku.h element.h puzzle.h field.h gamecontrol.h .tmp/sudoku1.0.0/ && $(COPY_FILE) --parents sudoku.qrc .tmp/sudoku1.0.0/ && $(COPY_FILE) --parents sudoku.cpp mainwindow.cpp element.cpp puzzle.cpp field.cpp gamecontrol.cpp .tmp/sudoku1.0.0/ && $(COPY_FILE) --parents sudoku_de.ts .tmp/sudoku1.0.0/ && (cd `dirname .tmp/sudoku1.0.0` && $(TAR) sudoku1.0.0.tar sudoku1.0.0 && $(COMPRESS) sudoku1.0.0.tar) && $(MOVE) `dirname .tmp/sudoku1.0.0`/sudoku1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/sudoku1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_mainwindow.cpp moc_element.cpp moc_gamecontrol.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindow.cpp moc_element.cpp moc_gamecontrol.cpp
moc_mainwindow.cpp: mainwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) mainwindow.h -o moc_mainwindow.cpp

moc_element.cpp: element.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) element.h -o moc_element.cpp

moc_gamecontrol.cpp: puzzle.h \
		mainwindow.h \
		gamecontrol.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) gamecontrol.h -o moc_gamecontrol.cpp

compiler_rcc_make_all: qrc_sudoku.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_sudoku.cpp
qrc_sudoku.cpp: sudoku.qrc \
		images/sudoku.png
	/usr/bin/rcc -name sudoku sudoku.qrc -o qrc_sudoku.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean 

####### Compile

sudoku.o: sudoku.cpp mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sudoku.o sudoku.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		element.h \
		puzzle.h \
		field.h \
		gamecontrol.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

element.o: element.cpp element.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o element.o element.cpp

puzzle.o: puzzle.cpp puzzle.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o puzzle.o puzzle.cpp

field.o: field.cpp field.h \
		element.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o field.o field.cpp

gamecontrol.o: gamecontrol.cpp gamecontrol.h \
		puzzle.h \
		mainwindow.h \
		element.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o gamecontrol.o gamecontrol.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_element.o: moc_element.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_element.o moc_element.cpp

moc_gamecontrol.o: moc_gamecontrol.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_gamecontrol.o moc_gamecontrol.cpp

qrc_sudoku.o: qrc_sudoku.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_sudoku.o qrc_sudoku.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:


COMPILER = clang++
SOURCE_LIBS = -Ilib/
OSX_OPT = -Llib/ -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL lib/libraylib.a
OUT = -o "bin/visigotia"
CFILES = src/src/*.cpp

build_linux:
	$(COMPILER) -std=c++11 $(CFILES) $(SOURCE_LIBS) $(OUT)

build_osx: 
	$(COMPILER) -std=c++11 $(CFILES) $(SOURCE_LIBS) $(OUT) $(OSX_OPT)

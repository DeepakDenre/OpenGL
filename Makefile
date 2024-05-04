SOURCES := $(wildcard src/*.cpp src/*.c)
compile:
	mkdir Build
	g++ $(SOURCES) -Iinclude -Llib -lglfw3 -lgdi32 -luser32 -lopengl32 -o Build/OpenGL.exe

run:
	./Build/OpenGL.exe

clean:
	del Build\OpenGL.exe
	rmdir Build
	
test:
	make compile run clean

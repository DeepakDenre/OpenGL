SOURCES := $(wildcard src/*.cpp src/*.c)
windows:
	mkdir Build
	g++ $(SOURCES) -Iinclude -Llib -lglfw3 -lgdi32 -luser32 -lopengl32 -o Build/OpenGL.exe
	./Build/OpenGL.exe

android:
	mkdir Build
	clang++ src/main.cpp src/glad.c -Iinclude -lglfw -lGL -lX11 -o Build/OpenGL
	./Build/OpenGL

clean:
	rm Build/OpenGL*
	rmdir Build
	
test:
	make compile run clean

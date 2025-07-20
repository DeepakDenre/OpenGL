# Makefile

# Variables
rwildcard = $(foreach d,$(wildcard $(1)*),$(call rwildcard,$d/,$2)) $(wildcard $(1)$2)
SRC := $(call rwildcard,src/,*.cpp)
INCLUDE := -Iinclude
LIBDIR64 := -Llib/MingW/64
LIBDIR32 := -Llib/MingW/32
LIBS := -lglfw3 -lopengl32 -lgdi32 -luser32 -lkernel32 -lwinmm
OUT := -o OpenGL.exe
CXX := g++
CXXFLAGS := -Wall -Wextra -g

# Default target
all: win64

# Target for 64-bit build
win64:
	$(CXX) $(CXXFLAGS) $(SRC) $(INCLUDE) $(LIBDIR64) $(LIBS) $(OUT)

# Target for 32-bit build
win32:
	$(CXX) $(CXXFLAGS) $(SRC) $(INCLUDE) $(LIBDIR32) $(LIBS) $(OUT)

raspberrypi:
	$(CXX) $(CXXFLAGS) $(SRC) $(INCLUDE) -lglfw -lGLESv2 -lEGL -o OpenGL

termux:
	$(CXX) $(CXXFLAGS) $(SRC) $(INCLUDE) -lglfw -lGL -lX11 -o OpenGL

# Clean target
clean:
	del /Q OpenGL.exe 2> NUL || exit 0

# Run target
run: 
	@if [ -f "OpenGL.exe" ]; then\
		./OpenGL.exe; \
	elif [ -f "OpenGL" ]; then \
		./OpenGL; \
	else \
		echo "No executable found!"; \
	fi


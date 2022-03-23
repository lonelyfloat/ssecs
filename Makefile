SOURCE_FILES ?= src/demo/systems.c src/ecs/ssecs.c src/demo/main.c
PROJECT_NAME ?= demo

CFLAGS ?= -Os -std=c99 -Wall -Isrc -Lsrc/demo/lib/
WEBFLAGS = web -s USE_GLFW=3 -s TOTAL_MEMORY=67108864 -s FORCE_FILESYSTEM=1 --shell-file config/template.html  --preload-file src/demo/assets
ADDFLAGS = 
ADDLIBFLAGS = 
PCFLAGS = desktop -DPLATFORM_DESKTOP
RAYLIB_LOC = src/lib/desktop
LDFLAGS ?= -lraylib
OUTPUT ?= $(PROJECT_NAME).exe

CC = cc
ifeq ($(OS), Windows_NT)
	CC = gcc
	ADDFLAGS = -static -mwindows
	ADDLIBFLAGS = -static
else
	LDFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
endif

build lib(desktop):
	$(CC) -c $(ADDLIBFLAGS) src/ecs/ssecs.c -Os -std=c99 -Wall &&  ar -rc libssecs.a ssecs.o 

build lib(web): # MUST HAVE EMSCRIPTEN INSTALLED FIRST
	emcc -c -static src/ecs/ssecs.c -Os -std=c99 -Wall && emar rcs ssecs.a ssecs.o 

build demo:
	gcc $(ADDFLAGS) $(SOURCE_FILES) -o  $(PROJECT_NAME) $(CFLAGS)$(PCFLAGS) $(LDFLAGS) -lopengl32 -lgdi32 -lwinmm
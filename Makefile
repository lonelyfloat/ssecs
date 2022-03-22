SOURCE_FILES ?= src/demo/systems.c src/ecs/ecs.c src/demo/main.c
PROJECT_NAME ?= demo

CFLAGS ?= -Os -std=c99 -Wall -Isrc -Lsrc/demo/lib/
WEBFLAGS = web -s USE_GLFW=3 -s TOTAL_MEMORY=67108864 -s FORCE_FILESYSTEM=1 --shell-file config/template.html  --preload-file src/demo/assets
PCFLAGS = desktop -DPLATFORM_DESKTOP
RAYLIB_LOC = src/lib/desktop
LDFLAGS ?= -lraylib
OUTPUT ?= $(PROJECT_NAME).exe


build lib(windows):
	ar 

build lib(web):
	emar

build demo(windows):
	gcc -static -mwindows $(SOURCE_FILES) -o  builds/$(PROJECT_NAME).exe $(CFLAGS)$(PCFLAGS) $(LDFLAGS) -lopengl32 -lgdi32 -lwinmm

build demo(web):
	emcc -static $(SOURCE_FILES) -o  builds/web/$(PROJECT_NAME).html $(CFLAGS)$(WEBFLAGS) $(LDFLAGS)

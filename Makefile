SOURCE_FILES ?= src/entity.c src/main.c
PROJECT_NAME ?= game

CFLAGS ?= -Os -std=c99 -Wall -Isrc/include -Lsrc/lib/
WEBFLAGS = web -s USE_GLFW=3 -s TOTAL_MEMORY=67108864 -s FORCE_FILESYSTEM=1 --shell-file template.html  # --preload-file assets
PCFLAGS = desktop -DPLATFORM_DESKTOP
RAYLIB_LOC = src/lib/desktop
LDFLAGS ?= -lraylib
OUTPUT ?= $(PROJECT_NAME).exe


debug:
	gcc $(SOURCE_FILES) -o $(PROJECT_NAME).exe $(CFLAGS)$(PCFLAGS) $(LDFLAGS) -lopengl32 -lgdi32 -lwinmm

release(windows):
	gcc -static -mwindows $(SOURCE_FILES) -o  $(PROJECT_NAME).exe $(CFLAGS)$(PCFLAGS) $(LDFLAGS) -lopengl32 -lgdi32 -lwinmm

release(web):
	emcc -static $(SOURCE_FILES) -o  $(PROJECT_NAME).html $(CFLAGS)$(WEBFLAGS) $(LDFLAGS)
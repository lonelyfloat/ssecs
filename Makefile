SOURCE_FILES ?= src/ssecs.c

CC = cc
ifeq ($(OS), Windows_NT)
	CC = gcc
endif

desktop:
	$(CC) -c $(SOURCE_FILES) -Os -std=c99 -Wall &&  ar -rc libssecs.a ssecs.o 

web: # MUST HAVE EMSCRIPTEN INSTALLED FIRST
	emcc -c -static $(SOURCE_FILES) -Os -std=c99 -Wall && emar rcs libssecs.a ssecs.o 

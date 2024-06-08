.PHONY: all clean re run

CC = g++

SRC	= src
OBJ = bin
DEP = lib

TARGET = program

CFLAGS = -lm -lpthread -lncurses -g -std=c++20

_DEP = defs.h Vector2.h Vector3.h Vector4.h Rasterizer.h Framebuffer.h Matrix2x2.h Matrix3x3.h Matrix4x4.h Camera.h ModelFile.h
ALLDEP = $(patsubst %,$(DEP)/%,$(_DEP))

_OBJ = main.o Vector2.o Vector3.o Vector4.o Rasterizer.o Framebuffer.o Matrix2x2.o Matrix3x3.o Matrix4x4.o Camera.o ModelFile.o
ALLOBJ = $(patsubst %,$(OBJ)/%,$(_OBJ))

all: $(OBJ) run

re: clean all

run: build
	./$(TARGET)

build: $(ALLOBJ) 
	$(CC) -o $(TARGET) $^ -g $(CFLAGS)

clean:
	rm -f $(OBJ)/*.o $(TARGET)
	rmdir $(OBJ) 2> /dev/null || :

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) -o $@ $< -g -c $(CFLAGS)

$(OBJ):
	mkdir -p $(OBJ)

.PHONY: all clean OBJ run

CC = g++

SRC	= src
OBJ = bin

TARGET = program

CFLAGS = -lm -lpthread -lncurses -Wall

_OBJ = main.o Vector2.o Vector3.o Vector4.o Rasterizer.o Framebuffer.o
ALLOBJ = $(patsubst %,$(OBJ)/%,$(_OBJ))

run: build
	./$(TARGET)

build: $(ALLOBJ)
	$(CC) -o $(TARGET) $^ $(CFLAGS)

clean:
	rm -f $(OBJ)/*.o $(TARGET)

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) -o $@ $< -c $(CFLAGS)

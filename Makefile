CC = gcc
CFLAGS = -g -Wall -std=c11
INCL_DIR = include
CPPFLAGS = -I$(INCL_DIR)

EXEC = theChat
LSG_EXEC = musterloesung

LSG_OBJ_DIR = obj_lsg
OBJ_DIR = obj
SRC_DIR = src

OBJ = $(OBJ_DIR)/list.o
OBJ += $(OBJ_DIR)/main.o
OBJ += $(OBJ_DIR)/output.o

ABGABE_OBJ = $(OBJ_DIR)/kitchen.o
ABGABE_OBJ += $(OBJ_DIR)/parseLine.o
ABGABE_OBJ += $(OBJ_DIR)/readData.o
ABGABE_OBJ += $(OBJ_DIR)/serve.o

LSG_OBJ = $(subst $(OBJ_DIR),$(LSG_OBJ_DIR),$(ABGABE_OBJ))


.PHONY: all clean submission

all: $(EXEC) $(LSG_EXEC)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $< 

$(EXEC): $(ABGABE_OBJ) $(OBJ)
	$(CC) -o $@ $^

$(LSG_EXEC): $(LSG_OBJ) $(OBJ)
	$(CC) -o $@ $^

test_kitchen: $(subst $(LSG_OBJ_DIR)/kitchen.o,$(OBJ_DIR)/kitchen.o,$(LSG_OBJ)) $(OBJ)
	$(CC) -o $@ $^

test_parseLine: $(subst $(LSG_OBJ_DIR)/parseLine.o,$(OBJ_DIR)/parseLine.o,$(LSG_OBJ)) $(OBJ)
	$(CC) -o $@ $^

test_readData: $(subst $(LSG_OBJ_DIR)/readData.o,$(OBJ_DIR)/readData.o,$(LSG_OBJ)) $(OBJ)
	$(CC) -o $@ $^

test_serve: $(subst $(LSG_OBJ_DIR)/serve.o,$(OBJ_DIR)/serve.o,$(LSG_OBJ)) $(OBJ)
	$(CC) -o $@ $^

submission:
	zip Abgabe.zip $(SRC_DIR)/kitchen.c $(SRC_DIR)/parseLine.c $(SRC_DIR)/readData.c $(SRC_DIR)/serve.c

clean:
	rm -rf $(EXEC) $(LSG_EXEC) $(ABGABE_OBJ) $(OBJ) test_* Abgabe.zip

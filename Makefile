
CC = g++
CFLAGS = -Wall 
BIN_DIR = ./bin
OBJ_DIR = ./obj

calculator_6_1: $(OBJ_DIR)/main_6_1.o $(OBJ_DIR)/Calculate_6_1.o
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^

$(OBJ_DIR)/main_6_1.o: ./6.1/main.cpp $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/Calculate_6_1.o: ./6.1/Calculate.cpp $(OBJ_DIR) ./6.1/Calculate.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR):
	mkdir -p $@

$(OBJ_DIR):
	mkdir -p $@
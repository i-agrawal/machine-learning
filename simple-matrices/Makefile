OBJ = obj
SRC = src
BIN = bin
INC = include
EXE = mmtest

DEP = $(wildcard $(INC)/*.h)
MID = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(wildcard $(SRC)/*.c))
FIN = $(BIN)/$(EXE)

CC = gcc
OFLAGS = -O3 -I$(INC)
CFLAGS =
ifneq ($(OS),Windows_NT)
  ifeq ($(shell uname -s),Darwin)
    CFLAGS += -framework Accelerate
  endif
endif

$(FIN) : $(MID)
	$(CC) -o $@ $^ $(CFLAGS)

$(OBJ)/%.o : $(SRC)/%.c $(DEP)
	$(CC) -c -o $@ $< $(OFLAGS)

.PHONY: display clean
display:
	@ECHO $(DEP)
	@ECHO $(MID)
	@ECHO $(FIN)

clean:
	rm -rf $(MID) $(FIN)

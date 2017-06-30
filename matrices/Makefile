OBJ = obj
SRC = src
BIN = bin
INC = include
EXE = mmtest

DEP = $(wildcard $(INC)/*.h)
MID = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(wildcard $(SRC)/*.c))
FIN = $(BIN)/$(EXE)

CC = gcc
OFLAGS = -O2 -I$(INC)

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

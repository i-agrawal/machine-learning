OBJ = obj
SRC = src
BIN = bin
INC = include
EXE = linreg
MML = ../../simple-matrices
GRL = ../../grapher

MMO = $(MML)/$(OBJ)/mm.o
MMM = $(MML)/Makefile
GRO = $(GRL)/$(OBJ)/grapher.o
GRM = $(GRL)/Makefile

DEP = $(wildcard $(INC)/*.h)
MID = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(wildcard $(SRC)/*.c))
FIN = $(BIN)/$(EXE)

CC = gcc
OFLAGS = -O3 -I$(MML)/$(INC) -I$(INC) -I$(GRL)/$(INC)

$(FIN): $(MID) $(MMO) $(GRO)
	$(CC) -o $@ $^ $(CFLAGS)

$(MMO): $(MMM)
	$(MAKE) -C $(MML)

$(GRO): $(GRM)
	$(MAKE) -C $(GRL)

$(OBJ)/%.o: $(SRC)/%.c $(DEP)
	$(CC) -c -o $@ $< $(OFLAGS)

.PHONY: display clean
display:
	@ECHO $(DEP)
	@ECHO $(MID)
	@ECHO $(FIN)

clean:
	rm -rf $(MID) $(FIN)

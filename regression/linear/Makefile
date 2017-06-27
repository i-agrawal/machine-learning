OBJ = obj
SRC = src
BIN = bin
INC = include
EXE = linreg
MML = ../../simple-matrices

MMO = $(MML)/$(OBJ)/mm.o
MMM = $(MML)/Makefile
DEP = $(wildcard $(INC)/*.h)
MID = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(wildcard $(SRC)/*.c))
FIN = $(BIN)/$(EXE)

GRAPHDIR = ../../gnuplot
GRAPHNAME = gnuplot
GRAPHER = $(GRAPHDIR)/install/bin/$(GRAPHNAME)

CC = gcc
OFLAGS = -O3 -I$(MML)/$(INC) -I$(INC)
CFLAGS = $(MMO)
ifneq ($(OS),Windows_NT)
  ifeq ($(shell uname -s),Darwin)
    CFLAGS += -framework Accelerate
  endif
endif

$(FIN): $(MID) $(MMO) $(GRAPHER)
	$(CC) -o $@ $^ $(CFLAGS)

$(MMO): $(MMM)
	make -C $(MML)

$(OBJ)/%.o: $(SRC)/%.c $(DEP)
	$(CC) -c -o $@ $< $(OFLAGS)

$(GRAPHER) : $(GRAPHDIR)/Makefile
	make -C $(GRAHPDIR)

.PHONY: display clean
display:
	@ECHO $(DEP)
	@ECHO $(MID)
	@ECHO $(FIN)

clean:
	make -C $(MML) clean
	rm -rf $(MID) $(FIN)

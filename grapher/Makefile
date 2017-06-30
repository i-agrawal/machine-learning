OBJ = obj
SRC = src
BIN = bin
INC = include
EXE = graphtest

DEP = $(wildcard $(INC)/*.h)
MID = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(wildcard $(SRC)/*.c))
FIN = $(BIN)/$(EXE)

GRAPHDIR = $(CURDIR)/gnuplot-src
GRAPHER = $(GRAPHDIR)/install/bin/gnuplot
VAR_NAME = GNUPLOT_LOC

CC = gcc
OFLAGS = -O3 -I$(INC) -D$(VAR_NAME)='"$(GRAPHER)"'

$(FIN) : $(MID) $(GRAPHER)
	$(CC) -o $@ $(MID) $(CFLAGS)

$(OBJ)/%.o : $(SRC)/%.c $(DEP)
	$(CC) -c -o $@ $< $(OFLAGS)

$(GRAPHER) :
	$(MAKE) -C $(GRAPHDIR)

.PHONY: display clean
display:
	@ECHO $(DEP)
	@ECHO $(MID)
	@ECHO $(FIN)

clean:
	rm -rf $(MID) $(FIN)

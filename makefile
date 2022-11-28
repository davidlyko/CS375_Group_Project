EXE = evaluate

FLAGS = -Wall -Wextra -g
CC = g++
OBJ = obj
SRC_DIR = src

REPODIR = ../lyko_d_p2
TARFILE = lyko_d_p2.tar

$(EXE): $(OBJ)/Evaluate.o 
	$(CC) $(FLAGS) $(OBJ)/Evaluate.o  -o $@

$(OBJ)/Evaluate.o:	$(SRC_DIR)/Evaluate.cpp 
	$(CC) $(FLAGES) -c $(SRC_DIR)/Evaluate.cpp -o $@


tar:	clean
	tar cvvf $(TARFILE) $(REPODIR)
	gzip $(TARFILE)

clean:
	rm -f $(OBJ)/*.o  *.tar.gz
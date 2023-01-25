# makefile permettant de compiler, supprimer, et créer la documentation doxygen
# author PRADAL Titouan <pradaltito@cy-tech.fr>

CC = gcc
CFLAGS = -Wall -g
EXEC = exe
SRC = $(wildcard *.c) # Fichiers sources
OBJ = $(SRC:.c=.o)    # Fichiers objets
LDFLAGS = -lm
SAV = saves/

all:$(EXEC)

$(EXEC) : $(OBJ) # Compilation du programme
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

.c.o :          # Compilation des objets
	$(CC) $(CFLAGS) -c $^ -o $@

.PHONY :
clean : save        # Sauvegarde des fichiers .c et .h + effacement des objets et de l'exécutable
	rm -rf $(OBJ) exe latex html DoxyFile

.PHONY :
createSave :
	mkdir -p $(SAV)

.PHONY :
save: createSave
	cp *$(SRC) *.h $(SAV)

doxy: 
	doxygen -g DoxyFile && doxygen DoxyFile

docHtml: doxy
	firefox html/index.html

help:
	@echo 'General targets: '
	@echo ' help      - display this help'
	@echo 'Building targets: '
	@echo ' all       - build the project'
	@echo ' doxy      - build documentation'
	@echo ' docHtml   - ouvre doxygen sur internet'
	@echo 'Cleaning targets: '
	@echo ' clean     - save all the .c and .h files and remove anything that can be generated'
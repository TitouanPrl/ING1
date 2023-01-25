# makefile permettant de compiler, supprimer, et créer la documentation doxygen
# author PRADAL Titouan <pradaltito@cy-tech.fr>

CC = gcc
CFLAGS = -Wall -g
EXEC = bin/exe	#Fichier exécutable
SRC = $(wildcard $(SRCDIR)*.c) # Fichiers sources
OBJ = $(subst $(SRCDIR), $(BINDIR), $(SRC:.c=.o))    # Fichiers objets
LDFLAGS = -lm
SAV = saves/	#Fichiers sauvegarde
DOC = doc/DoxyFile	#Fichiers documentation
SRCDIR = src/
BINDIR = bin/

all:$(EXEC)

$(EXEC) : $(OBJ) # Compilation du programme
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

./bin/%.o : ./src/%.c	# Compilation des objets
	mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -c $^ -o $@

.PHONY : clean
clean : save        # Sauvegarde des dossiers + effacement
	@rm -rf doc/ bin/

.PHONY : createSave
createSave :
	@rm -rf $(SAV) 
	@mkdir -p $(SAV)

.PHONY : save
save: createSave
	@echo 'Saving files...'
	@cp src/* $(SAV)

.PHONY : createDoc
createDoc :
	@rm -rf doc/
	@mkdir -p doc/

.PHONY : restore
restore: 
	@echo 'Restoring files...'
	rm -rf $(SRCDIR)*
	cp saves/* $(SRCDIR)

doxy: createDoc
	@doxygen DoxyFile
	@mv html/ doc/
	@mv latex doc/
	@echo 'Creating documentation...'
	

docHtml: doxy
	@firefox doc/html/index.html

help:
	@echo 'General targets: '
	@echo ' help      - display this help'
	@echo 'Building targets: '
	@echo ' all       - build the project'
	@echo ' doxy      - build documentation'
	@echo ' docHtml   - ouvre doxygen sur internet'
	@echo 'Cleaning targets: '
	@echo ' clean     - save all the .c and .h files and remove anything that can be generated'
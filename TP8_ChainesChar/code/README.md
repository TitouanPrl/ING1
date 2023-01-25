# README
## TP 8 de programmation C
### Table des matières
1. [Compiler](#compiler)
2. [Lancer l'exécutable](#exe)
3. [Supprimer les fichiers en .exe et .o](#suppr)
4. [Documentation Doxygen](#doxy)

#### Compiler
***
Pour compiler :
```sh
make
```
Cela créera aussi l'éxecutable.
#### Lancer l'exécutable
##### L'option -c permet de choisir la méthode de cryptage (cesar/vigenere/scytale)
##### L'option -m permet de choisir le message à crypter (ex : -m "Bonjour Eshan")
##### L'option -d permet de choisir le décalage pour le cryptage césar (ex : -d 5)
##### L'option -k permet de choisir la clé pour le cryptage vigenere (ex : -k allo)
***
Pour lancer l'exécutable :
```sh
./exe -c <...> -m <...> 
```
#### Supprimer les fichiers en .exe, .o et la dox Doxygen
***
Pour supprimer les fichiers en .exe, .o et la doc Doxygen :
```sh
make clean
```
#### Documentation Doxygen
***
En lançant cette commande :
```sh
make doxy
```
La documentation Doxygen sera créée ou mise à jour si elle existe déjà.

Pour l'ouvrir dans Firefox faire :
```sh
make docHtml
```

### Crédits
***
Auteur : PRADAL Titouan <pradaltito@cy-tech.fr>
CC=g++
CFLAGS = -c -Wall -Werror
LDFLAGS =
SOURCES = $(wildcard *.cpp)
DEPENDENCIES = $(SOURCES:.cpp=.d)
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = voyageur_commerce_achandeze.bin

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) $(DEPENDENCIES)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.d: %.cpp
	$(CC) -MM -MT '$*.o' $< > $@

%.o: %.cpp %.d
	$(CC) $(CFLAGS) $< -o $@

-include $(wildcard *.d)

clean:
	rm *.o *.d $(EXECUTABLE)

.PHONY: all clean

.DEFAULT_GOAL := all


# Ici vous configurez le makefile pour qu'il compile les
# fichiers .cpp de manière séparée en fichiers objet (.o)
# Et de créer un executable à part.
# C'est une bonne pratique

# Etant donné qu'on n'utilisera pas les fichiers .o
# séparément pour dans d'autres utilisations, le makefile
# est un peu overkill ici.

# Il suffit de lancer g++ en lui passant les fichiers à
# compiler (tous les fichiers .cpp) pour qu'il créé
# directement l'executable, pas besoin des fichiers .o
# séparés.
# g++ cities.cpp city.cpp main.cpp neighbor.cpp

# Cela créé un fichier executable (a.out par défaut).
# qui est déjà lié avec tous les autres fichiers .o via le
# code. Pas besoin de linker avec des choses exterieures.

# Afin de ne pas avoir à retaper cette commande à chaque fois,
# on peut très bien la metttre dans un script shell qu'on
# pourra lancer très rapidement.

# Si vous êtes à l'aise avec les Makefile continuez
# vous en aurez de toute façon besoin et ce n'est pas
# l'objet du cours donc cela ne rentre pas en considération

# Simplement il est important de comprendre ce qu'il se passe
# en dessous et comment fonctionne la compilation (sans entrer
# dans les moindres détails) afin d'utiliser des solutions
# adaptées aux problèmes.
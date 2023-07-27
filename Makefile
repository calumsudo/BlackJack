# 10 points
INCLUDE := -I ~/include
# Define Make rules as follows:
# A default rule to compile a .c file into a .o file
all: game
game: game.o card.o
	cc -o game game.o card.o
# A rule for "all" to build the entire project into a program called "game"
%.o: %.c card.h
	cc -c $< -I ~/include

# A rule for "clean" to remove all .o files
clean: 
	rm -f *.o game

run:
	./game

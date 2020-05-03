.PHONY: all bot
all:
	gcc projeto/main_game.c projeto/data.c projeto/interface.c projeto/logic.c projeto/listas_ligadas.c -o game -lm -std=gnu11 -Wall -Wextra -pedantic-errors -O

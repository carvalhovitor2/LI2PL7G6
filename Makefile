
all:
	gcc projeto/main_game.c projeto/data/data.c projeto/interface/interface.c projeto/logic/logic.c projeto/listas_ligadas/listas_ligadas.c -o game -lm

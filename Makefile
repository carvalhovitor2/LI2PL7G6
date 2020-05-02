.PHONY: all bot
all:
	gcc projeto/main_game.c projeto/data/data.c projeto/interface/interface.c projeto/logic/logic.c projeto/listas_ligadas/listas_ligadas.c -o game -lm -std=gnu11 -Wall -Wextra -pedantic-errors -O
bot:
	gcc projeto/bot/bot.c projeto/data/data.c projeto/interface/interface.c projeto/logic/logic.c projeto/listas_ligadas/listas_ligadas.c -lm -o bot

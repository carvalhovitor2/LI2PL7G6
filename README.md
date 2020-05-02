Autores
=========  
Pedro Miguel Ribeiro Ferreira - A93282   
 
Rui Miguel Borges Braga       - A93228       

Vitor de Almeida de Carvalho  - A90648     


LI2 - PL7 - GRUPO 6
------------



Modus Operandi
------------  

As alterações devem ser feitas sempre nos modulos destinados para tais funções, ou seja:  

Funções que mexem com a lógica do programa ficam em DEFINIDAS logic/logic.c e DECLARADAS em logic/logic.h  
  
Funções que mexem com a interface do programa ficam em DEFINIDAS interface/interface.c e DECLARADAS em interface/interface.h  
  
Funções que mexem com os dados do programa ficam em DEFINIDAS data/data.c e DECLARADAS em data/data.h 


Compilação
------------  

Para compilar, execute o comando 'make' de dentro do diretorio base do projeto. Isto é, em LI2PL7G6.    

O output gerado pode ser algo como:  
```
gcc projeto/main_game.c projeto/data/data.c projeto/interface/interface.c projeto/logic/logic.c projeto/listas_ligadas/listas_ligadas.c -o game -lm -std=gnu11 -Wall -Wextra -pedantic-errors -O
```

Bot
------------  

Para compilar o bot, execute o comando 'make bot' de  dentro do diretório base do projeto. Isto é, em LI2PL7G6.  

O output gerado pode ser algo como:  
```
vac@vac-ThinkPad-E490:~/Desktop/uMinho/periodo02/LI2PL7G6$ make bot
gcc projeto/bot/bot.c projeto/data/data.c projeto/interface/interface.c projeto/logic/logic.c projeto/listas_ligadas/listas_ligadas.c -lm -o bot
```



 

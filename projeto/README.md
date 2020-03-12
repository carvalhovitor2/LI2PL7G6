Autores
=========  
Pedro Miguel Ribeiro Ferreira - A93282  
Rui Miguel Borges Braga       - A93228     
Vitor de Almeida de Carvalho  - A90648  

LI2 - PL7
------------



Modus Operandi
------------  

As alterações devem ser feitas sempre nos modulos destinados para tais funções, ou seja:  

Funções que mexem com a lógica do programa ficam em DEFINIDAS logic/logic.c e DECLARADAS em logic/logic.h  
  
Funções que mexem com a interface do programa ficam em DEFINIDAS interface/interface.c e DECLARADAS em interface/interface.h  
  
Funções que mexem com os dados do programa ficam em DEFINIDAS data/data.c e DECLARADAS em data/data.h 


Compilação
------------  

Para compilar, execute o comando 'make' de dentro do diretorio base do projeto. Isto é, em LI2/projeto.  

O output gerado pode ser algo como:  
```
gcc -o game main_game.c data/data.c interface/interface.c logic/logic.c
main_game.c: In function ‘main’:
main_game.c:7:2: warning: implicit declaration of function ‘mostrar_tabuleiro’ [-Wimplicit-function-declaration]
  mostrar_tabuleiro(e);
```



 

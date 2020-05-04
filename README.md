Autores
=========  
Pedro Miguel Ribeiro Ferreira - A93282   
 
Rui Miguel Borges Braga       - A93228       

Vitor de Almeida de Carvalho  - A90648     


MIEI - LI2 - PL7 - GRUPO 6
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


```



 

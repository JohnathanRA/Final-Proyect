#include<stdio.h>

  main()
  {FILE *archivo;
   archivo=fopen("hola.txt", "r");
   if (archivo==NULL){
     printf("No existe el archivo");
     return 0;
  }

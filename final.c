#include<stdio.h>

int main(){
  FILE *archivo;
  char Usu_Alu[20];
  int i, j, Cue_Alu;
  
  printf("Debebs ingresar tu usuario y tu numero de cuenta.");
  printf("\n\nIngresa un usuario de max. 20 caracteres:");
  gets(Usu_Alu);
  
  printf("Ingresa tu numero de cuenta:");
  scanf("%d", & Cue_Alu);
  
  printf("%s, %d", Usu_Alu, Cue_Alu);
  
  archivo=fopen("hola.txt", "r");
  if (archivo==NULL){
   printf("\nNo existe el archivo");
  }
  
  return 0;
}

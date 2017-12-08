#include<stdio.h>

void datos();

int main(){
	datos();
	
	
	
	
  	return 0;
}

void datos(){
	FILE *archivo;
  	int CueAlu, nuevo;
  
 	printf("Ingresa tu numero de cuenta:");
  	scanf("%d", & CueAlu);
  	
  	archivo=fopen("Info.txt", "a");
  	
  	while(!feof(archivo)){
		fscanf(archivo, ",%d", &nuevo);
  	}
  	
  	fprintf(archivo, ",%d", CueAlu);
  	
	fclose(archivo);
}


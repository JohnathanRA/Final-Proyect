#include<stdio.h>
#include<string.h>
#include<time.h>

int num_ran(int y);

int main(){
	int d=0;
	
	num_ran(d);
}
int num_ran(int y){
	FILE *archivo;
	int aleat[100];
	int i=0,z;
	int p;
	if(y==0){
		archivo=fopen("preg.txt", "w");
		fflush(archivo);
		fclose(archivo);	
	}
	srand(time(NULL));
	do{
	i=0;
	z=(rand()%100)+0;
	archivo=fopen("preg.txt", "a+");
	while(!feof(archivo)){
		fscanf(archivo,"%d,",&p);
    	if(z==p){
    		i=-1;
		}
	}
	}
	while(i==-1||z==0);
	
	fprintf(archivo, "%d,", z);
	fclose(archivo);
	return z;	
}

int num_cue(int *cue_alu){
	FILE *archivo;
	int n, y=0; 
	
	archivo=fopen("info.txt", "r");
	
	while(!feof(archivo)){
		fscanf(archivo,"%d,%d ",&n,&y);
		if(n==*cue_alu){
			printf("Ya realizaste el examen, tu calificacion registrada es: %d\n", y);
			n=-1;
			break;
		}
		n=0;
	}
	fclose(archivo);
	
	if(n!=-1){
		archivo=fopen("info.txt", "a");
		fprintf(archivo,"%d,%d ",*cue_alu,y);
		fclose(archivo);
		return 1;
	}
}


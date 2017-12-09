#include<stdio.h>

int num_cue(int *cue_alu);

int main(){	
	FILE *archivo;
	char usu[20];
	int cue, t;
	int *a, *b;
	b=&cue;
	
	printf("Ingresa tu numero de cuenta y tu nombre \nIngresa tu numero de cuenta:");
	scanf("%d",&*b);
	t=num_cue(b);
	
	if(t==1){
		printf("Ingresa tu nombre:");
		gets("")
	}
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


#include<stdio.h>
#include<string.h>
#include<time.h>
#include<ctype.h>
#include<stdlib.h>

int num_ran(int y);
int num_cue(int *cue_alu);

int main(){
	FILE *archivo;
	int o,i,L=0,x=0,cue,calif,d=0;
	char p,r;
	char react[150],nombre[100];
	int *b, *num;
	b=&cue;
	
	printf("Ingresa tu numero de cuenta y tu nombre \nIngresa tu nombre:\n");
	gets(nombre);
	setbuf(stdin,NULL);
	printf("\nIngresa tu numero de cuenta:\n");
	scanf("%d",&*b);
	setbuf(stdin,NULL);
	calif=num_cue(b);
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	for(L=0;L<10;L++){
		num_ran(d);
		d++;
		archivo=fopen("preguntas.txt", "r");
		i=0;
		while(i<o){
			fgets(react,150,archivo);
			
			if(react[0]=='*'){
				i++;
			}
			if(i==o-1){
				if(react[0]=='#'){
					r=react[1];
				}
				if(react[0]!='#'&&react[0]!='*'){
					printf("%s",react);
				}
			}
		
		}
		printf("%c\n",r);
		setbuf(stdin,NULL);
		scanf(" %c",&p);
		p=toupper(p);
		if(p==r){
			x++;
		}
		printf("\n");
	}
	printf("Obtuviste %d en este examen\n",x);
	if(calif!=0){
		calif = (x + calif)/2;
	}
	else{
	calif=x;
	}
	printf("\n%s tu promedio es de: %d\n",nombre,calif);
	final(calif, b);
	fclose(archivo);
	return 0;
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
	
	archivo=fopen("info.txt", "a");
	fclose(archivo);
	archivo=fopen("info.txt", "r");
	
	while(!feof(archivo)){
		fscanf(archivo,"%d,%d ",&n,&y);
		if(n==*cue_alu){
			printf("\nYa realizaste el examen, tu calificacion registrada es: %d\n\n", y);
			n=-1;
			return y;
			break;
		}
	}
	n=0;
	
	fclose(archivo);
	
	if(n!=-1){
		y=0;
		archivo=fopen("info.txt", "a");
		fprintf(archivo,"%d,%d ",*cue_alu,y);
		fclose(archivo);
		return y;
	}
}



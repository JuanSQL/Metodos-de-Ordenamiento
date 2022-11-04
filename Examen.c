#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int numDim(char []);
void lecturaArchivo(char []);
void menu(int *,int );
void Burbuja(int *,int);
void Insercion(int *,int);
void Seleccion(int *,int);

int main(){
	char dir[60];
	printf("Este programa se encarga de ordenar una lista de edades de adultos en USA por medio de los algoritmos de selección, insercion o burbuja\n");	
	printf("Ingrese la dirección del archivo del cual se desea obtener la lista de números:\n");	
	scanf("%s",dir);
	fflush(stdin);
	lecturaArchivo(dir);

	return 0;
}

/******************************************************FUNCIÓN******************************************************/
void menu(int *lista,int dim){
	int resp;
	struct timeval start, end;
	do{
		printf("MENÚ:\n");
		printf("Seleccione una de las siguientes opciones:\n\n");
		printf("1.- Ordenamiento burbuja\n");
		printf("2.- Ordenamiento por inserción\n");
		printf("3.- Ordenamiento por selección\n");
		printf("4.- Salir\n");
		scanf("%d",&resp);
		fflush(stdin);
	} while (resp>4 || resp<=0);	
	if (resp==1){
		gettimeofday(&start, NULL);
		Burbuja(lista,dim);
		gettimeofday(&end, NULL);
		long seconds = (end.tv_sec - start.tv_sec);
		long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);

		printf("\nEl tiempo de ejecución es de: %d segundos y %d microsegundos\n", seconds,micros);
		menu(lista,dim);
	}
	if (resp==2){
		gettimeofday(&start, NULL);
		Insercion(lista,dim);
		gettimeofday(&end, NULL);
		long seconds = (end.tv_sec - start.tv_sec);
		long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);

		printf("\nEl tiempo de ejecución es de: %d segundos y %d microsegundos\n", seconds,micros);
		menu(lista,dim);
	}
	if (resp==3){
		gettimeofday(&start, NULL);
		Seleccion(lista,dim);
		gettimeofday(&end, NULL);
		long seconds = (end.tv_sec - start.tv_sec);
		long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);

		printf("\nEl tiempo de ejecución es de: %d segundos y %d microsegundos\n", seconds,micros);
		menu(lista,dim);
	}
}


/******************************************************FUNCIÓN******************************************************/
void lecturaArchivo(char dir[]){
	FILE *fp;
	fp = fopen(dir,"rt");//setdatosedades.txt
	int dim;
	dim = (numDim(dir));
	int *lista;
	lista=(int *)malloc(dim*sizeof(int));
	if (lista==NULL){
		printf("Hubo un problema en la asignacion de memoria\n");
		exit(-1);
	}
	for (int i = 0; i < dim; i++){
		fscanf(fp, "%d", &lista[i]);
	}
	fclose(fp);
	if (lista!=NULL){
		printf("Archivo recuperado de forma exitosa\n\n");
	}
	menu(lista,dim);
	//Comprobando que se llene correctamente la estructura
	/*
	for (int i = 0; i < dim; ++i){
		printf("%d \t", lista[i]);
	}*/
}


/******************************************************FUNCIÓN******************************************************/
int numDim(char dir[]){
	int i=0;
	char aux;
	FILE *fp;
	fp = fopen(dir,"rt");
	while(aux!=EOF){
		aux=fgetc(fp);
		if(aux == '\n'){
			i++;
		}
	}
	return i;
}


/******************************************************FUNCIÓN******************************************************/
void Burbuja(int *lista,int dim){
	int delete, aux;
	delete=1;
	while((dim-1)!=delete){
		for (int i = 0; i < (dim-delete); i++){
			if (lista[i]>lista[i+1]){
				aux=lista[i];
				lista[i]=lista[i+1];
				lista[i+1]=aux;
			}
		}
		delete++;
	}

	printf("Datos ordenados:\n");
	for (int i = 0; i < dim; ++i){
		printf("%d\t",lista[i]);
	}
}


/******************************************************FUNCIÓN******************************************************/
void Insercion(int *lista,int dim){
	int aux;
	for (int i = 0; i < dim; ++i){
		int j;
		aux=lista[i];
		for (j = i; j > 0 && lista[j-1]>aux; j--){
			lista[j]=lista[j-1];
		}
		lista[j]=aux;
	}
	printf("Datos ordenados:\n");
	for (int i = 0; i < dim; ++i){
		printf("%d\t",lista[i]);
	}
}


/******************************************************FUNCIÓN******************************************************/
void Seleccion(int *lista,int dim){
	int aux1, aux2;

	for (int i = 0; i < dim; i++){
		aux1=i;
		for (int j = i+1; j < dim; j++){
			if (lista[j]<lista[aux1]){
				aux1=j;
			}
			aux2=lista[i];
			lista[i]=lista[aux1];
			lista[aux1]=aux2;
		}
	}

	printf("Datos ordenados:\n");
	for (int i = 0; i < dim; ++i){
		printf("%d\t",lista[i]);
	}
}
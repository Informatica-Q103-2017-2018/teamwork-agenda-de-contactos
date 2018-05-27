#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Nombre 1
#define Apellido 2
#define Telefono 3 
#define Direccion 4
#define NOMBRE 1
#define APELLIDO 2
#define TELEFONO 3

typedef struct
{
	char nombre[100];
	char apellido [100];
	int telefono;
}contacto;
contacto PedirContacto();
void Mostrar_Contacto(contacto cont);
int Leer_Contacto(FILE *f,contacto *cont);
int Guardar_Contacto(FILE *f,contacto cont);
void Intercambia(contacto *cont1,contacto *cont2);

int Compara(contacto cont1,contacto cont2,int campo);
void Mostrar_Agenda(contacto agenda[],int num);
void Buscar_Contacto(contacto agenda[],int num, contacto cont ,int campo);
void Nuevo_Contacto(contacto agenda[],int *num,contacto cont);

void Eliminar_Contacto(contacto agenda[],int *num, int i);
int Leer_Agenda(char fichero[],contacto agenda[], int *num);
int Guardar_Agenda(char fichero[],contacto agenda[], int num);


int main ()

{
	contacto agenda [50];
	int num=0;
	int option=0;
	contacto c;
	int n;
	Leer_Agenda("Agenda.txt",agenda,&num);
	do{
		printf("Elija una opcion 0-Salir del programa, 1-Mostrar agenda, 2-Nuevo contacto, 3-Eliminar: ");
		scanf("%d",&option);
		switch(option)
		{
			case 0:
				printf("Adios");
				break;
			case 1: 
				Mostrar_Agenda(agenda,num);
				break;	
			case 2:
				c=PedirContacto();
				Nuevo_Contacto(agenda,&num,c);
				break;
		
			case 3:
				Mostrar_Agenda(agenda,num);
				printf("que contacto quiere borrar?");
				scanf("%d",&n);
				Eliminar_Contacto(agenda,&num,n);
				Mostrar_Agenda(agenda,num);
				break;		
		}
	}
	while(option!=0);
	Guardar_Agenda("Agenda.txt",agenda,num);
}
contacto PedirContacto()
{
	contacto cont;
	fflush(stdin);
	printf("Nombre: ");
	gets(cont.nombre);
	printf("Apellido: ");
	gets(cont.apellido);
	printf("Telefono: ");
	scanf("%d",&cont.telefono);
	return cont;
	
}

void Mostrar_Contacto(contacto cont)
{
printf("%20s %20s %10d\n",cont.nombre,cont.apellido,cont.telefono);	
}

int Leer_Contacto(FILE *f,contacto *cont)
{
	if(f==NULL)
	{
		printf("Error al abrir el fichero");
	return 0;
	}
	else
	{
		fscanf(f,"%s %s %d",cont->nombre,cont->apellido,&cont->telefono);
	}
	return 1;
}

int Guardar_Contacto(FILE *f,contacto cont)
{
	if(f==NULL)
	{
		printf("Error al abrir el fichero");
	return 0;
    }
	else
	{
		fprintf(f,"%s %s %d\n",cont.nombre,cont.apellido,cont.telefono);
	}
	return 1;
}
int Compara(contacto cont1,contacto cont2,int campo)
{
	if(campo==Nombre)
	return strcmp(cont1.nombre,cont2.nombre);
	if(campo==Apellido)
	return strcmp(cont1.apellido,cont2.apellido);
	if(campo==Telefono)
	{
		if(cont1.telefono<cont2.telefono)
		return -1;
		else if(cont1.telefono>cont2.telefono)
		return 1;
		else
		return 0;
	}
	return -1; 
}


void Mostrar_Agenda(contacto agenda[],int num)
{
	int i; 
		
		printf("%20s %20s %10s\n","Nombre","Apellido","Telefono");
		
	for(i=0;i<num;i++)
	{
		printf("%d: ",i);
		Mostrar_Contacto(agenda[i]);
	}
}
void Buscar_Contacto(contacto agenda[],int num,contacto cont,int campo)
{
	int i;
		printf("%20s %20s %10s\n","Nombre","Apellido","Telefono");
	for(i=0;i<num;i++)
	{
		if(0==Compara(agenda[i],cont,campo))
		{
	
		printf("%d: ",i);
		Mostrar_Contacto(agenda[i]);
		}
	}
	
}

void Nuevo_Contacto(contacto agenda[],int *num,contacto cont)
{
	int n=*num;
	if(n<50)
	{
		agenda[n]=cont;
		n++;
	}
	*num=n;
}
void Eliminar_Contacto(contacto agenda[],int* num,int n)
{
	int i;
	int numero=*num;
	if(n<0 || n>=numero)
	return;
	for(i=n;i<numero-1;i++)
	{
		agenda[i]=agenda[i+1];
	}
	*num=numero-1;
}
int Leer_Agenda(char fichero[],contacto agenda[],int* num)
{
	contacto contact;
	int n=0;
	FILE* f=fopen(fichero,"r");
	if(f==NULL)
	return 0;
	while(Leer_Contacto(f,&contact))
	{
		agenda[n]=contact;
		n++;
	}
	*num=n;
	fclose(f);
	return 1;
}
int Guardar_Agenda(char fichero[],contacto agenda[],int num)
{
	int i;
	FILE* f=fopen(fichero,"w");
	if(f==NULL)
	return 0;
	for (i=0;i<num;i++)
	Guardar_Contacto(f,agenda[i]);
	fclose(f);
	return 1;
}



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_CONT 50

typedef struct
{
	char nombre[100];
	char apellido [100];
	int telefono;
}contacto;
contacto PedirContacto();
void MostrarContacto(contacto c);
int LeerContacto(FILE* f,contacto* c);
int GuardarContacto(FILE* f,contacto c);

int Compara(contacto c1,contacto c2,int campo);
void Intercambia(contacto* c1,contacto* c2);


int main ()
{
	contacto agenda [MAX_CONT];
	int num_contactos=0;
	int option=0;
	contacto c;
	int n;
	LeerAgenda("Agenda.txt",agenda,&num_contactos);
	do{
		option=Menu();
		switch(option)
		{
			case 0:
				printf("Hasta la vista");
				break;
			case 1: 
				MostrarAgenda(agenda,num_contactos);
				break;	
			case 2:
				c=PedirContacto();
				NuevoContacto(agenda,&num_contactos,c);
				break;
			case 3:
				Buscar(agenda,num_contactos);
				break;
			case 4: 
				n=MenuCampo();		
				OrdenarAgenda(agenda,num_contactos,n);
				MostrarAgenda(agenda,num_contactos);
				break;
			case 5:
				MostrarAgenda(agenda,num_contactos);
				printf("que contacto desea borrar?");
				scanf("%d",&n);
				EliminarContacto(agenda,&num_contactos,n);
				MostrarAgenda(agenda,num_contactos);
				break;		
		}
	}
	while(option!=0);
	GuardarAgenda("Agenda.txt",agenda,num_contactos);
}
contacto PedirContacto()
{
	contacto c;
	fflush(stdin);
	printf("Nombre: ");
	gets(c.nombre);
	printf("Apellido: ");
	gets(c.apellido);
	printf("Telefono: ");
	scanf("%d",&c.telefono);
	return c;
	
}
void MostrarContacto(contacto c)
{
printf("%20s %20s %10d\n",c.nombre,c.apellido,c.telefono);	
}
int LeerContacto(FILE* f,contacto* c)
{
	if(f==NULL)
	{
		printf("Error al abrir el fichero");
	return 0;
	}
	else
	{
		fscanf(f,"%s %s %d",c->nombre,c->apellido,&c->telefono);
	}
	return 1;
}

int GuardarContacto(FILE* f,contacto c)
{
	if(f==NULL)
	{
		printf("Error al abrir el fichero");
	return 0;
    }
	else
	{
		fprintf(f,"%s %s %d\n",c.nombre,c.apellido,c.telefono);
	}
	return 1;
}
void Intercambia (contacto* c1,contacto* c2)
{
	contacto aux =*c1;
	*c1=*c2;
	*c2=aux;
}

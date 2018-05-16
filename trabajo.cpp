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

#include <stdio.h>
#include <string.h>

typedef struct{
	char nombre[30];
	char apellido[30];
	int telefono[9];
	int edad[2];
}contacto;

int main(){
	int opcion;
	int n,i;
	char contactobusqueda[100];
	
	do{
	printf("Introducir contacto(1)\t  Buscar contacto(2)\t  Eliminar contacto(3)\t  Ordenar contactos(4)\t  Salir del programa(5)\n");
	scanf("%d",&opcion);
		switch (opcion)
		{
			case 1:
				
				printf("Cuantos contactos desea introducir?\n");
				scanf("%d",&n);
				
	
				
				for(i=0;i<n;i++){
					contacto c;
					
					printf("Introduce el nombre del contacto\n");
					scanf("%s",c.nombre);
					printf("Introduce el apellido del contacto\n");
					scanf("%s",c.apellido);
					printf("Introduce la edad del contacto\n");
					scanf("%d",&c.edad);
					printf("Introduce el numero de telefono\n");
					scanf("%d",&c.telefono);
					}
				break;
		    case 2:
		    	contacto c;
		    	
		    	do{
		    		printf("Introduzca contacto a buscar\n");
		    		scanf("%s",contactobusqueda);
		    		if(strcmp(c.nombre,contactobusqueda)!=0)
		    		{
		    			printf("%s",c.nombre);
					}
		    	    else
		    	    printf("No existe ese contacto\n");
		    	}
		    		while(strcmp(c.nombre,contactobusqueda)!=0);
			break;    		
					

				
			case 5:
				printf("Agenda Cerrado");
				break;
			
			default: printf("Opcion no valida\n");
			
		
	}
			
		}
			while(opcion!=5);
			return 0;	
		}
		




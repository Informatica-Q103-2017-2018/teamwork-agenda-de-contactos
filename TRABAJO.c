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
	printf("Introducir contacto(1),buscar contacto(2),eliminar contacto(3), ordenar contactos(4) y salir del programa(5)\n");
		switch (opcion)
		{
			case 1:
				
				printf("¿Cuantos contactos desea introducir?\n");
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
				}
		
			
			
				
			return 0;	
		}
		




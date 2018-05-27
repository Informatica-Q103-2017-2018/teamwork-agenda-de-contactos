#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Nombre 1
#define Apellido 2
#define Telefono 3 

//Definicion de la estructura de contacto,ésta estará formada por un nombre,un apellido y un telefono
typedef struct
{
	char nombre[100];
	char apellido [100];
	int telefono;
}contacto;
//Definimos las diferenctes funciones que entrarán a formar parte del programa
contacto PedirContacto();
void MostrarContacto(contacto cont); 
int LeerContacto(FILE *f,contacto *cont);
int GuardarContacto(FILE *f,contacto cont);
void Intercambia(contacto *cont1,contacto *cont2);


void MostrarAgenda(contacto agenda[],int num);
void NuevoContacto(contacto agenda[],int *num,contacto cont);

void EliminarContacto(contacto agenda[],int *num, int i);
int LeerAgenda(char fichero[],contacto agenda[], int *num);



int main ()

{
	contacto agenda [50]; //Definimos el numero máximo de contactos que puede almacenar la agenda
	int num=0; //Fijamos el numero inical de contactos en 0
	int option;
	contacto contacto; //Hacemos la llamada a la estructura dentro del programa
	int n;
	int i;
	char fichero[200];
	FILE* f=fopen(fichero,"w"); //Abrimos un fichero donde se van a almacenar los diferentes contactos guardados

	LeerAgenda("Agenda.txt",agenda,&num);
	do{
		printf("Elija una opcion:\t 0-Salir del programa\t 1-Mostrar agenda\t 2-Nuevo contacto\t 3-Eliminar contacto:\n ");
		scanf("%d",&option);
		switch(option)
		{
			case 0:
				printf("Adios");
				break;
			case 1: 
				MostrarAgenda(agenda,num);
				break;	
			case 2:
				contacto=PedirContacto();
				NuevoContacto(agenda,&num,contacto);
				break;
		
			case 3:
				MostrarAgenda(agenda,num);
				printf("Que contacto quiere borrar?");
				scanf("%d",&n);
				EliminarContacto(agenda,&num,n);
				MostrarAgenda(agenda,num);
				break;		
		}
	}
	while(option!=0);
	//Creacion de un menu de interfaz que dotará al programa de su estructura principal
	if(f==NULL)
	return 0;
	for (i=0;i<num;i++)//El bucle for recorrerá todos los contactos introducidos empezando por el 1º y los irá guardando en un fichero gracias a la función guardarcontacto
	GuardarContacto(f,agenda[i]);
	fclose(f);
	return 1;
}
contacto PedirContacto() //Esta funcion permite al programa preguntar al usuario el nombre,apellido y telefono. Una vez el usuario introduce dicha informacion, el programa la guardará en la estructura contacto.
{
	contacto contacto;
	fflush(stdin);
	printf("Nombre: ");
	gets(contacto.nombre);
	printf("Apellido: ");
	gets(contacto.apellido);
	printf("Telefono: ");
	scanf("%d",&contacto.telefono);
	return contacto; //Le decimos al programa que retorne los valores que hemos introducido para introducirlos despues en la funcion NuevoContacto
	
}

void MostrarContacto(contacto contacto)
{
printf("%20s %20s %10d\n",contacto.nombre,contacto.apellido,contacto.telefono);	 //El programa imprime los contactos introducidos
}


int GuardarContacto(FILE *f,contacto contacto)
{
	if(f==NULL)
	{
		printf("Error al abrir el fichero");
	return 0;
    }
	else
	{
		fprintf(f,"%s %s %d\n",contacto.nombre,contacto.apellido,contacto.telefono); //Le decimos al programa que cree un fichero donde se iran almacenando los diferentes contactos. Este fichero se utilizará mas adelante en la funcion LeerContacto
	}
	return 1;
}

int LeerContacto(FILE *f,contacto *contacto)
{
	if(f==NULL)
	{
		printf("Error al abrir el fichero");
	return 0;
	}
	else
	{
		fscanf(f,"%s %s %d",contacto->nombre,contacto->apellido,&contacto->telefono);//Abrimos el fichero donde habíamos guardado nuestros contactos y le pedimos al programa que los vaya recorriendo, indicando que el primer valor leido corresponde al nombre, el segundo al apellido y por ultimo el telefono
	}
	return 1;
}
void MostrarAgenda(contacto agenda[],int num)
{
	int i; 
		
		printf("%20s %20s %10s\n","Nombre","Apellido","Telefono");
		
	for(i=0;i<num;i++)//recorre el vector hasta el valor de num,que es el numero de contactos que hemos introducido e inicialmente es 0
	{
		printf("%d: ",i);
		MostrarContacto(agenda[i]); //Aqui lo que le estamos diciendo al programa es que vaya imprimiendo todos los contactos que se encuentran guardados. Para ello, recorre la funcion mostrarcontacto y va imprimiendo cada uno de los elementos del vector donde se han almacenado
	}
}


void NuevoContacto(contacto agenda[],int *num,contacto contacto)
{
	int n=*num; //El contacto que hemos introducido le añadimos un puntero que va a señalr a una posicion del vector donde tenemos almacenados los contactos
	if(n<50)//si n es menor al numero maximo de contactos
	{
		agenda[n]=contacto; //cada puntero señala a una posicion de vector y aumenta, el primer contacto se almacenara en agenda[1] tendra su puntero y asi progresivamente
		n++;
	}
	*num=n;
}
void EliminarContacto(contacto agenda[],int *num,int n)
{
	int i;
	int numero=*num; //
	if(n<0 || n>=numero)//n es el contacto que hemos definido en la estructura y que es el contacto que queremos eliminar
	return;
	for(i=n;i<numero-1;i++)
	{
		agenda[i]=agenda[i+1];//una vez eliminado el contacto, adelanta una posicion a todos los contactos que esten por detrás del que acabamos de eliminar
	}
	*num=numero-1;
}
int LeerAgenda(char fichero[],contacto agenda[],int *num)
{
	contacto contacto;
	int n=0;
	FILE* f=fopen(fichero,"r");//abre el fichero donde estan los contactos y los lee
	if(f==NULL)
	return 0;
	while(LeerContacto(f,&contacto))//segun los va leyendo les va a proporcionar un espacio dentro del vector contacto, asi el primer contacto que lea ocupara el primer puesto en la agenda
	{
		agenda[n]=contacto;
		n++;
	}
	*num=n;
	fclose(f);//una vez que los haya leido cierra el fichero
	return 1;
}




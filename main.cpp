/*______________________________________________________________________________
Curso: Estructura de Datos, Reconocimiento unidad 1 - UNAD 2015

Funcionalidad del programa: Aplica los operadores new y delete para gestion
dinamicamica de memoria y hace uso de estructuras y apuntadores. 
El programa calcula el promedio de nota de x numero de estudiantes
(el usuario agrega tantos como desee), imprime nombre y promedio del estudiante
luego libera la memoria que fue reservada para la creacion de los objetos
"Estudiante".

Planteamiento del problema: Desarrollar un programa que haga uso de los
operadores new y delete para gesti�n din�mica de memoria y tambi�n de
apuntadores. El programa debe permitir ingresar x n�mero de estudiantes
(sin preguntar cu�ntos desea ingresar) y cada uno solicita datos de nombre 
y sus 3 notas obtenidas en el curso. Cada estudiante es una estructura creada 
con el operador "new". Permitir al usuario imprimir en cualquier momento 
los promedios de cada estudiante obtenidos de una lista apilada (pila). 
Luego liberar la memoria reservada de cada elemento de la pila con el operador 
"delete" y finalizar el programa.

Desarrollado por Luis Hernando Benitez, bajo licencia MIT
GitHub: https://github.com/orgs/UNAD-luisbenitez

Con informacion y explicaciones de:
Aplikdos (Listas enlazadas)
	https://youtu.be/aKymaTZnvIg?list=PLuRwC0BwoxO2qpfXY9k6V8SYaPzGEoe-d

Programacion y mas (Arreglos Dinamicos en C++)
	https://youtu.be/gzVhDRzaRIQ?list=PLuRwC0BwoxO2qpfXY9k6V8SYaPzGEoe-d

______________________________________________________________________________*/
#include <iostream>
#include <stdlib.h>//usa system("pause")
#include <stdio.h>//permite usar funcion gets()
using namespace std;//permite usar cin y cout sdsdd
//Creamos una PILA
struct Estudiante{//defino estructura (hace las veces de nodo)
	char nombre[256];
    float nota[3];//espacio para tres calificaciones por estudiante
    float promedio;//almacenara el promedio de calificaciones
    struct Estudiante *next;//puntero a la siguiente de un nuevo nodo
}*ultimo=NULL, *aux;//puntero al inicio de la pila, aux para seguir agregando

//definicion de funciones
void start();
void borrado();
unsigned int conta=1;//entero sin signo (es un contador)

//Funcion de ingreso
void ingreso(){
	cout<<"\tIngreso Estudiante #"<< conta << endl;
	aux= new Estudiante;//nuevo objeto estudiante en puntero aux
	cout<<"Nombre: ";
	gets(aux->nombre);//guardo nombre (con espacios)
	for(int i = 0; i < 3; i++)//solicito las 3 calificaciones de cada estudiante
	{
		cout<< endl <<"Calificacion #"<<i+1<<": ";
		cin>> aux->nota[i];
		fflush(stdin);//limpio buffer
	}
	
	//calculo promedio a continuacion
	aux->promedio= (aux->nota[0] + aux->nota[1] + aux->nota[2])/3;

	if(ultimo==NULL){//si no hay elementos en la PILA
		ultimo = aux;//el ultimo ahora tiene el valor del recien ingresado
		aux->next=NULL;//aux crea un nuevo espacio vacio en el puntero next
	}
	//si ya hay elementos
	else{
		aux->next=ultimo;//ultimo elemento agregado, guardo en espacio aux-<next
		ultimo=aux;//el recien agregado es el primero en la pila
	}
	conta++;//aumento contador de estudiantes
	start();//llamo al menu	de inicio
}

//funcion que imprime los promedios
void imprime(){
	cout<<endl<<"======================================================";
	cout<<endl<<"NOTA: Si imprimes los promedios LIBERAREMOS LA MEMORIA "<<
	" y el programa finalizara" << endl;
	cout<<"======================================================";
	//solicito una opcion antes de continuar
	cout<<endl<<"Pulsa 1 para listar, otro numero cualquiera para abortar";
	short op=0;
	cin>> op;
	fflush(stdin);//limpio buffer
	if(op==1)
	{
	cout<<endl<<"\t\t Promedio de Calificaciones:"<<endl;
	aux=ultimo;//pone el puntero en la primera posicion de la pila (arriba)

	while(aux!=NULL){//mientras aux sea diferente de NULL (vacio)
		cout<< aux->nombre<<" : ";//imprimo nombre y promedio
		cout<< " "<<aux->promedio<<endl;
		aux=aux->next;//paso a siguiente elemento en la pila
	}
	cout<< endl << "===FIN de la lista";
	borrado();	//LLAMO funcion que libera la memoria
	}else{
		start();//llamo a start(menu) si no ingreso 1
	}

}

//Funcion que libera la memoria
void borrado(){
	cout<<endl<<"\t\t --- Liberando memoria---" << endl;
	aux=ultimo;//pone el puntero en la primera posicion de la pila (arriba)
	while(aux!=NULL){
/*=============================================================================
	ANOTACION: Descomenta las lineas de codigo para ver como al liberar la
	memoria, tambien se da�an algunos de los nombres ingresados
=============================================================================*/
		//cout<< aux << endl;
		//cout<< aux->nombre;
		delete aux;//libero memoria reservada para el elemento creado con new
		//cout<< endl << "-------.Borro?" << endl;
		//cout<< endl<< aux << endl;
		//cout<< "nombre: "<<aux->nombre;
		aux=aux->next;//paso a siguiente elemento
		//cout<< ultimo << endl;
		//cout<< "---------------======" << endl;
	}
	//delete ultimo;
	//delete aux;
	cout<<"----Memoria Liberada------";
	system("pause");//---espero tecla para continuar y finalizo
	//fflush(stdin);
	//start();
}

//El menu del programa
void start(){
	short opcion;
	cout<< endl<<"======================================"<<endl;
	cout<< "--Opciones:"<<endl;
	cout<< "--1. Ingresar nuevo estudiante (new)"<<endl;
	cout<< "--2. Imprimir Promedios y libera memoria (delete)"<<endl;
	cin>>  opcion;
	fflush(stdin);//limpio buffer
	//solicito opciones
	if(opcion==1)
	{
		ingreso();	//llamo funciones
	}else if(opcion==2){
		imprime();
	}else{
		start();
	}
}

int main()
{
	cout<<"Bienvenido al Sistema de Evaluacion De Estudiantes";
	start();//funcion de inicio
	return 0;
}

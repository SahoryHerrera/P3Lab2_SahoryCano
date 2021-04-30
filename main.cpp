
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <ctime>
#include <string>

using std:: cout;
using std:: cin;
using std:: endl;


void Imprimir_Arreglo(int array[], int);
void Random(int array[], bool);
double Desviacion_estandar();
void triangulo_de_pascal(int,int,int[],int[]);
void limpiar(int[],int[]);
void grafico_de_barra(int,int,int[],int[]);
void desviacionEstandar();
void ejercicio3();

/*30/04/2021*/


void desviacionEstandar(){
	int size = 20;
	int Arreglo[size];
	double suma = 0;
	double result = 0;
	double sumaresult = 0;
	double total = 0;
	double raizcuadrada = 0;
	srand (time(NULL));
	for(int i = 0; i < size; i++){
		Arreglo[i] = 1+rand()%100;	
	}
	// imprimir
	for(int i = 0; i < size; i++){
	cout<<	Arreglo[i]<<", ";	
	}
	// sumar
	cout<<endl;
	for(int i = 0; i < size; i++){
		suma += Arreglo[i];	
	}
	double prom = suma / 2.0;
	for(int i = 0; i < size; i++){
		 result = Arreglo[i] - prom;
		sumaresult += result * result;
	}
	total = sumaresult / size;
	raizcuadrada = sqrt(total);

 	cout<< "El resultado de la desviacion estandar es: : " << raizcuadrada << endl;
 	
    }


//Metodo de menu
int menu(){
	int p = 0; 
	while (p != 4){
	cout<<"--------[MENU]------"<<endl;
	cout<<"Ejercicio---------[1]"<<endl;
	cout<<"Ejercicio---------[2]"<<endl;
	cout<<"Ejercicio---------[3]"<<endl;
	cout<<"Salir-------------[4]"<<endl;	
	cin>> p; 
		if (p == 4){
			cout << "Saliendo... " <<endl; 
		}else if (p > 0 && p < 4){
			break; 
		}
	}
	return p; 
}



int main(int argc, char** argv) {
	int p = menu();

	while(p != 4){
		switch(p){
			case 1:{	
			/*Triangulo de pascal*/
			int filas=0;
			while (filas<1){
				cout <<"Ingrese numero de filas: ";
				cin >> filas;
			}//fin while
			
			cout<<endl;
			int res_anterior[100];
			int salida[100];
			for(int i = 0; i<100; i++){
				res_anterior[i]=0;
				salida[i]=0; 
			}
				triangulo_de_pascal(1,filas+1,res_anterior,salida);
				cout<<endl; 
		
				break;
			}//fin case 1
				
			case 2:{
				/*calcule el promedio y la desviación estándar 
				poblacional de los elementos de un arreglo*/
				desviacionEstandar();

		
				
				break;
			}//fin case 2
			
			case 3:{
				/*Grafico de barra*/
			
		    ejercicio3();
			
				break;
			}//fin case 3
			
			case 4:{
				cout<< "Saliendo..."<<endl;
				break;
			}//fin case 4
			
			
			default: {
				cout<< "Entrada No valida ingrese numero del 1-4"<<endl;
				break;
			}
		}
		p = menu();
				
		
	}
	
	return 0;
}//fin main

 void ejercicio3(){
    	int size = 10;
		int Arreglo1[size];
		int Arreglo2[size];
		char caracter1 = 177;
		char caracter2 = 178;
		srand (time(NULL));
		for(int i = 0; i < size; i++){
			Arreglo1[i] = 1+rand()%20;	
		}
		for(int i = 0; i < size; i++){
			Arreglo2[i] = 1+rand()%20;	
		}
		for(int i = 0; i < size; i++){
			cout<<i+1<<" "<<endl;
			for(int j = 0; j < Arreglo1[i]; j++){
				cout<<caracter1;
			}	
			cout<<endl;
			for(int j = 0; j < Arreglo2[i]; j++){
				cout<<caracter2;
			}	
			cout<<endl;
		}
		
		
	}

void Random(int array[], bool flag){
	
	if(flag){
		
		for(int i = 0; i < 20; i++){
			array[i] = rand() % 100 + 1;
		}	
		
	}
	else{
		
		for(int i = 0; i < 10; i++){
			array[i] = rand() % 20 + 1;
		}	
		
	}
	
}//fin metodo para llenar random

void Imprimir_Arreglo(int array[], int size){
	

	
	for(int i = 0; i < size; i++){
		cout << array[i] << " ";
	}
	
;
}//fin metodo de imprimir arreglo



void triangulo_de_pascal(int contador, int filas, int res_anterior[], int salida[]) {
    if (contador < filas) {
        if (contador == 1) {
            salida[0] = 1;
        } else {
            for (int j = 0; j < contador; j++) {
                salida[j] = res_anterior[j] + res_anterior[j - 1];
            }//
        }//
        for (int i = 0; i < 100; i++) {
            if (salida[i] > 0) {
                cout << salida[i] << " ";
            }//
        }//
        cout << endl;
        limpiar(res_anterior, salida);
        triangulo_de_pascal(contador + 1, filas, res_anterior, salida);
    }
}

void limpiar(int res_anterior[], int salida[]) {
    for (int i = 0; i < 100; i++) {
        res_anterior[i] = 0;
    }
    for (int i = 0; i < 100; i++) {
        res_anterior[i] = salida[i];
        salida[i] = 0;
    }
}



	

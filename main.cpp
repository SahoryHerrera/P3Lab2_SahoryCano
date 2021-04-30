
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
void Desviacion();
void Grafica_Barra();

/*30/04/2021*/


void Desviacion(){
	int size = 20;
	int Array[size];
	double suma = 0;
	double result = 0;
	double suma_t = 0;
	double total = 0;
	double raiz = 0;
	srand (time(NULL));
	for(int i = 0; i < size; i++){
		Array[i] = 1+rand()%100;	
	}
	cout<<"[";
	for(int i = 0; i < size; i++){
	cout<<Array[i]<<", ";	
	}
	cout<<"]";
	
	cout<<endl;
	for(int i = 0; i < size; i++){
		suma += Array[i];	
	}
	double prom = suma / 2.0;
	for(int i = 0; i < size; i++){
		 result = Array[i] - prom;
		suma_t += result * result;
	}
	total = suma_t / size;
	raiz = sqrt(total);
	cout<<endl;
 	cout<< "El resultado de la desviacion estandar es: : " << raiz << endl;
 		cout<<endl;
 	
    }


//Metodo de menu
int menu(){
	int p = 0; 
	while (p != 4){
	cout<<"+--------[MENU]------+"<<endl;
	cout<<"Ejercicio---------[1]"<<endl;
	cout<<"Ejercicio---------[2]"<<endl;
	cout<<"Ejercicio---------[3]"<<endl;
	cout<<"Salir-------------[4]"<<endl;	
	cout<<"+--------------------+"<<endl;
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
			cout<<"Triangulo de pascal"<<endl;
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
				cout<<"Calculo de desviacion estandar"<<endl;
				Desviacion();
				
				break;
			}//fin case 2
			
			case 3:{
				/*Grafico de barra*/
				cout<<"Grafico de barra"<<endl;
		        Grafica_Barra();
			
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
				
		
	}//fin del while
	
	return 0;
}//fin main

 void Grafica_Barra(){
 	
    	int size = 10;
		int Array_1[size],Array_2[size];	
		char Num_1 = 177;
		char Num_2 = 178;
		srand (time(NULL));
		for(int i = 0; i < size; i++){
			Array_1[i] = 1+rand()%20;	
		}
		for(int i = 0; i < size; i++){
			Array_2[i] = 1+rand()%20;	
		}
		for(int i = 0; i < size; i++){
			cout<<i+1<<" "<<endl;
			for(int j = 0; j < Array_1[i]; j++){
				cout<<Num_1;
			}	
			cout<<endl;
			for(int j = 0; j < Array_2[i]; j++){
				cout<<Num_2;
			}	
			cout<<endl;
		}//for donde se imprimen los dos arreglos
		
		
	}//fin del metodo grafico de barra

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
            }
        }
        for (int i = 0; i < 100; i++) {
            if (salida[i] > 0) {
                cout << salida[i] << " ";
            }
        }
        cout << endl;
        limpiar(res_anterior, salida);
        triangulo_de_pascal(contador + 1, filas, res_anterior, salida);
    }
}//fin de metodo del triangulo de pascal

void limpiar(int res_anterior[], int salida[]) {
    for (int i = 0; i < 100; i++) {
        res_anterior[i] = 0;
    }
    for (int i = 0; i < 100; i++) {
        res_anterior[i] = salida[i];
        salida[i] = 0;
    }
}//fin metodo limiar



	

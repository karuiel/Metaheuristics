#ifndef AG_HPP
#define AG_HPP

#include "../include/data_container.h"
#include <fstream>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <algorithm> 
#include <random>   
#include <vector>      
#include <ctime>        
#include <cstdlib>    
#define MASK 2147483647
#define PRIME 65539
#define SCALE 0.4656612875e-9
struct Cromosoma
{
	vector<float> pesos;
	float porcentaje;
	float KNN(vector<Example> &conjunto){

		float contadorClas=0;
		float contadorRed=0;
		float tasaClas=0;
		float tasaRed=0;
		float dmin,d=0;
		
		string cmin = conjunto[0].class_name;		
		dmin =  9999;
		float tamanioConjunto=conjunto.size();

		for(int i = 0;i<tamanioConjunto;i++){
			dmin =  9999;				
			for(int j=0;j<tamanioConjunto;j++){	
				if(i==j){
					continue;
				}				
				d=distanciaEuclidea(conjunto[j],conjunto[i]);
				if(d<dmin){
					cmin=conjunto[j].class_name;
					dmin=d;
				}
				

			}
			if(cmin==conjunto[i].class_name){
				contadorClas++;
			}

		}

		for(int i=0;i<pesos.size();i++){
			if(pesos[i]<0.1){
				contadorRed++;
			}
		}
		tasaClas=(100*(contadorClas/conjunto.size()));
		tasaRed=(100*(contadorRed/pesos.size()));

		return (tasaClas+tasaRed)*0.5;
	}
	double distanciaEuclidea(Example e1, Example e2){
				double suma=0;
		double diff;
		for (int i=0;i<e1.data.size();i++){	
				diff=(e1.data[i]-e2.data[i]);				
				suma +=diff*diff*pesos[i];				
			
		}
		return suma;
	}

	Cromosoma &operator=(const Cromosoma &other){
	  if (this != &other) {
	    pesos = other.pesos;
	    porcentaje = other.porcentaje;
	  }
	  return *this;
	}

};

class AG{
	
public:
	int llamadas;
	int indiceMejorPoblacion;
	vector<Cromosoma> poblacion;
	vector<Cromosoma> hijos;
	vector<Example> particionTrain;
	long SEED=10;
	AG(vector<Example> &train);	
	AG(vector<Example> &train,vector<vector<float>>poblacionInicial);		
	void reemplazamiento(int tipoGenetico);
	void seleccion(int numIteraciones);
	void comprobar();
	void cruce(int tipoCruce,Cromosoma &padre1,Cromosoma &padre2);
	void mutacion(int fila, int columna);
	float generarNumAleatorio(float low,float high);
	vector<float> AGGBLX(int iteraciones); 
	vector<float> AGGCA();
	vector<float> AGEBLX();
	vector<float> AGECA();


	
	

};
#endif
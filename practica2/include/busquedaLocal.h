#ifndef BUSQUEDALOCAL_HPP
#define BUSQUEDALOCAL_HPP

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


class BusquedaLocal{
	
public:
	long SEED=123.123;
	vector<float> pesos;
	vector<Example> particionA;
	BusquedaLocal(vector<Example> otraparticionA);
	float KNN(vector<Example> &conjunto);	
	float generarNumAleatorio(float low,float high);
	void train(vector<Example> &train,int iteraciones);
	void LS(vector<Example> &train);
	void ILS(vector<Example> &train);
	double distanciaEuclidea(Example e1, Example e2);
	double distanciaEuclideaSinPeso(Example e1, Example e2);

};
#endif
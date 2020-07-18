#ifndef ALGORITMOS_HPP
#define ALGORITMOS_HPP

#include "../include/data_container.h"
#include <fstream>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <algorithm> 
#include "AG.h"   
#include <vector>      
#include <ctime>        
#include <cstdlib>    
#define MASK 2147483647
#define PRIME 65539
#define SCALE 0.4656612875e-9

class Algoritmos{
	
public:
	long SEED=123.123;
	vector<float> pesos;
	vector<Example> particionTrain;
	vector<Example> particionTest;
	Algoritmos(vector<Example> otraparticionTrain, vector<Example> otraparticionTest );
	float KNN(vector<Example> &conjunto);
	float evaluacion(vector<Example> &conjunto);
	vector<float> ES(vector <Example> &conjunto, int iteraciones);
	void DEBest(vector <Example> &conjunto);
	void DERand(vector <Example> &conjunto);
	void relief();
	float generarNumAleatorio(float low,float high);
	double distanciaEuclidea(Example e1, Example e2);
	void SAGA(vector<Example> &conjunto);
	double distanciaEuclideaSinPeso(Example e1, Example e2);

};
#endif
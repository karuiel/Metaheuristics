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
#include <vector>      
#include <ctime>        
#include <cstdlib>    
#define MASK 2147483647
#define PRIME 65539
#define SCALE 0.4656612875e-9

class Algoritmos{
	
public:
	vector<float> pesos;
	vector<Example> particionA;
	vector<Example> particionB;
	Algoritmos(vector<Example> otraparticionA, vector<Example> otraparticionB );
	float KNN(vector<Example> conjuntos);
	void relief();
	int generarNumAleatorio(int low,int high,unsigned long seed);
	double distanciaEuclidea(Example e1, Example e2);
	double distanciaEuclideaSinPeso(Example e1, Example e2);

};
#endif
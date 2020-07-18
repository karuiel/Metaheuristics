#ifndef SONAR_HPP
#define SONAR_HPP

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

class Sonar{
	
public:
	ExampleContainer datos;
	vector<vector<Example>> particionesTrain;
	vector<Example> particionTest;
	vector<Example> particionTrain;
	Sonar(unsigned long  Seed, int iteracion);
	void leerArchivo(unsigned long  Seed);
	int generarNumAleatorio(int low,int high,unsigned long seed);
	vector<Example> normalizarDatos(vector<Example> datos);
};
#endif
#include "spam.h"
	Spam::Spam(unsigned long  Seed){
		leerArchivo(Seed);

	}
	
	void Spam::leerArchivo(unsigned long  Seed){
		std::srand ( unsigned ( Seed ) );
		ExampleContainer lector;
		lector.ReadData("spambase-460.arff");
		datos = lector;
		vector<unsigned int> indicesClase0 = datos.class_index["0"];
		vector<unsigned int> indicesClase1 = datos.class_index["1"];
		for(int i = 0; i<indicesClase1.size();i++){
			std::random_shuffle(indicesClase1.begin(),indicesClase1.end());
		}
		for(int j = 0; j<indicesClase0.size();j++){
			std::random_shuffle(indicesClase0.begin(),indicesClase0.end());
		}

		for(int i = 0; i<indicesClase1.size();i++){
			if(i<=indicesClase1.size()/2){
				particionA.push_back(datos.example_vector.at(indicesClase1.at(i)));
			}else{
				particionB.push_back(datos.example_vector.at(indicesClase1.at(i)));
			}
		}

		for(int j = 0; j<indicesClase0.size();j++){
			if(j<=indicesClase0.size()/2){
				particionA.push_back(datos.example_vector.at(indicesClase0.at(j)));
			}else{
				particionB.push_back(datos.example_vector.at(indicesClase0.at(j)));
			}
		}

		vector<Example>aux=normalizarDatos(particionA);
		vector<Example>aux2=normalizarDatos(particionB);
		particionA=aux;
		particionB=aux2;



	}
	int Spam::generarNumAleatorio(int low,int high,unsigned long  seed){
		
		(int)(low + (high-(low))* (  (seed * PRIME) & MASK)* SCALE );

	} 

	vector<Example> Spam::normalizarDatos(vector<Example> datos){
		vector<float> min;
		vector<float> max;

		for(int j=0; j<datos.at(0).data.size();j++){
				min.push_back(datos.at(0).data.at(j));
				max.push_back(datos.at(0).data.at(j));
			for(int i=0; i<datos.size();i++){
				if(datos.at(i).data.at(j)<min.at(j)){
					min.at(j)=datos.at(i).data.at(j);
				}
				if(datos.at(i).data.at(j)>max.at(j)){
					max.at(j)=datos.at(i).data.at(j);
				}
				
			}
		}

		for(int i=0; i<datos.size();i++){
			for(int j=0; j<datos.at(i).data.size();j++){
				datos.at(i).data.at(j)=(datos.at(i).data.at(j)-min.at(j))/(max.at(j)-min.at(j));
			}
		}
		return datos;
	}
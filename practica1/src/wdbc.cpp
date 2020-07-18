#include "wdbc.h"
	Wdbc::Wdbc(unsigned long  Seed){
		leerArchivo(Seed);

	}
	
	void Wdbc::leerArchivo(unsigned long  Seed){
		std::srand ( unsigned ( Seed ) );
		ExampleContainer lector;
		lector.ReadData("wdbc.arff");
		datos = lector;
		vector<unsigned int> indicesClaseM = datos.class_index["M"];
		vector<unsigned int> indicesClaseB = datos.class_index["B"];

		for(int i = 0; i<indicesClaseB.size();i++){
			std::random_shuffle(indicesClaseB.begin(),indicesClaseB.end());
		}

		for(int j = 0; j<indicesClaseM.size();j++){
			std::random_shuffle(indicesClaseM.begin(),indicesClaseM.end());
		}


		for(int i = 0; i<indicesClaseB.size();i++){
			if(i<=indicesClaseB.size()/2){
				particionA.push_back(datos.example_vector.at(indicesClaseB.at(i)));
			}else{
				particionB.push_back(datos.example_vector.at(indicesClaseB.at(i)));
			}
		}

		for(int j = 0; j<indicesClaseM.size();j++){
			if(j<=indicesClaseM.size()/2){
				particionA.push_back(datos.example_vector.at(indicesClaseM.at(j)));
			}else{
				particionB.push_back(datos.example_vector.at(indicesClaseM.at(j)));
			}
		}

		vector<Example>aux=normalizarDatos(particionA);
		vector<Example>aux2=normalizarDatos(particionB);
		particionA=aux;
		particionB=aux2;


	}
	int Wdbc::generarNumAleatorio(int low,int high,unsigned long  seed){
		seed = ( (seed * PRIME) & MASK) * SCALE;
		
		return (int)(low + (high-(low))*seed);


	} 
	vector<Example> Wdbc::normalizarDatos(vector<Example> datos){
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
#include "sonar.h"
	Sonar::Sonar(unsigned long Seed){
		leerArchivo(Seed);

	}
	
	void Sonar::leerArchivo(unsigned long Seed){
		std::srand ( unsigned ( Seed ) );
		ExampleContainer lector ;
		lector.ReadData("sonar.arff");
		
		
		datos = lector;
		
		vector<unsigned int> indicesClaseRock = datos.class_index["Rock"];
		vector<unsigned int> indicesClaseMine = datos.class_index["Mine"];
		
		for(int i = 0; i<indicesClaseMine.size();i++){
			std::random_shuffle(indicesClaseMine.begin(),indicesClaseMine.end());
		}
		for(int j = 0; j<indicesClaseRock.size();j++){
			std::random_shuffle(indicesClaseRock.begin(),indicesClaseRock.end());
		}

		for(int i = 0; i<indicesClaseMine.size();i++){
			if(i<=indicesClaseMine.size()/2){
				particionA.push_back(datos.example_vector.at(indicesClaseMine.at(i)));
			}else{
				particionB.push_back(datos.example_vector.at(indicesClaseMine.at(i)));
			}
		}

		for(int j = 0; j<indicesClaseRock.size();j++){
			if(j<=indicesClaseRock.size()/2){
				particionA.push_back(datos.example_vector.at(indicesClaseRock.at(j)));
			}else{
				particionB.push_back(datos.example_vector.at(indicesClaseRock.at(j)));
			}
		}
		vector<Example>aux=normalizarDatos(particionA);
		vector<Example>aux2=normalizarDatos(particionB);
		particionA=aux;
		particionB=aux2;


	}
	int Sonar::generarNumAleatorio(int low,int high,unsigned long seed){
		
		(int)(low + (high-(low))* ( seed =(seed * PRIME) & MASK) * SCALE );

	} 
    
	vector<Example> Sonar::normalizarDatos(vector<Example> datos){
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
#include "sonar.h"
	Sonar::Sonar(unsigned long Seed, int iteracion){
		leerArchivo(Seed);
		particionTest=particionesTrain.at(iteracion);
		particionesTrain.erase(particionesTrain.begin()+iteracion);
		for(int i=0;i<particionesTrain.size();i++){
			for(int j=0; j<particionesTrain.at(i).size();j++){
				particionTrain.push_back(particionesTrain.at(i).at(j));
			}
		}

	}
	
	void Sonar::leerArchivo(unsigned long Seed){
		std::srand ( unsigned ( Seed ) );
		ExampleContainer lector ;
		lector.ReadData("sonar.arff");
		vector <Example> particion1Temp;
		vector <Example> particion2Temp;
		vector <Example> particion3Temp;
		vector <Example> particion4Temp;
		vector <Example> particion5Temp;	

		
		datos = lector;
		
		vector<unsigned int> indicesClaseRock = datos.class_index["Rock"];
		vector<unsigned int> indicesClaseMine = datos.class_index["Mine"];
		int tamanioMine = indicesClaseMine.size()/5;
		int tamanioRock = indicesClaseRock.size()/5;
			std::random_shuffle(indicesClaseMine.begin(),indicesClaseMine.end());
			std::random_shuffle(indicesClaseRock.begin(),indicesClaseRock.end());


		for (int i=0;i<5;i++){
			
			for(int j = 0; j<indicesClaseMine.size();j++){
				if((j<tamanioMine)&&(i==0)){
					particion1Temp.push_back(datos.example_vector.at(indicesClaseMine.at(0)));
					indicesClaseMine.erase(indicesClaseMine.begin());
				}
				if((j<tamanioMine)&&(i==1)){
					particion2Temp.push_back(datos.example_vector.at(indicesClaseMine.at(0)));
					indicesClaseMine.erase(indicesClaseMine.begin());
				}
				if((j<tamanioMine)&&(i==2)){
					particion3Temp.push_back(datos.example_vector.at(indicesClaseMine.at(0)));
					indicesClaseMine.erase(indicesClaseMine.begin());
				}
				if((j<tamanioMine)&&(i==3)){
					particion4Temp.push_back(datos.example_vector.at(indicesClaseMine.at(0)));
					indicesClaseMine.erase(indicesClaseMine.begin());
				}
				if(i==4){
					particion5Temp.push_back(datos.example_vector.at(indicesClaseMine.at(j)));
				}
			}

			for(int j = 0; j<indicesClaseRock.size();j++){
				if((j<tamanioRock)&&(i==0)){
					particion1Temp.push_back(datos.example_vector.at(indicesClaseRock.at(0)));
					indicesClaseRock.erase(indicesClaseRock.begin());
				}
				if((j<tamanioRock)&&(i==1)){
					particion2Temp.push_back(datos.example_vector.at(indicesClaseRock.at(0)));
					indicesClaseRock.erase(indicesClaseRock.begin());
				}
				if((j<tamanioRock)&&(i==2)){
					particion3Temp.push_back(datos.example_vector.at(indicesClaseRock.at(0)));
					indicesClaseRock.erase(indicesClaseRock.begin());
				}
				if((j<tamanioRock)&&(i==3)){
					particion4Temp.push_back(datos.example_vector.at(indicesClaseRock.at(0)));
					indicesClaseRock.erase(indicesClaseRock.begin());
				}
				if(i==4){
					particion5Temp.push_back(datos.example_vector.at(indicesClaseRock.at(j)));
				}
			}
		}
		particionesTrain.push_back(normalizarDatos(particion1Temp));
		particionesTrain.push_back(normalizarDatos(particion2Temp));
		particionesTrain.push_back(normalizarDatos(particion3Temp));
		particionesTrain.push_back(normalizarDatos(particion4Temp));
		particionesTrain.push_back(normalizarDatos(particion5Temp));



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
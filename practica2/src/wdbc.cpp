#include "wdbc.h"
	Wdbc::Wdbc(unsigned long  Seed, int iteracion){
		leerArchivo(Seed);
		particionTest=particionesTrain.at(iteracion);
		particionesTrain.erase(particionesTrain.begin()+iteracion);
		for(int i=0;i<particionesTrain.size();i++){
			for(int j=0; j<particionesTrain.at(i).size();j++){
				particionTrain.push_back(particionesTrain.at(i).at(j));
			}
		}


	}
	
	void Wdbc::leerArchivo(unsigned long  Seed){
		std::srand ( unsigned ( Seed ) );
		ExampleContainer lector;
		lector.ReadData("wdbc.arff");
		datos = lector;
		vector <Example> particion1Temp;
		vector <Example> particion2Temp;
		vector <Example> particion3Temp;
		vector <Example> particion4Temp;
		vector <Example> particion5Temp;		
		vector<unsigned int> indicesClaseM = datos.class_index["M"];
		vector<unsigned int> indicesClaseB = datos.class_index["B"];
		int tamanioB = indicesClaseB.size()/5;
		int tamanioM = indicesClaseM.size()/5;
			std::random_shuffle(indicesClaseB.begin(),indicesClaseB.end());
			std::random_shuffle(indicesClaseM.begin(),indicesClaseM.end());


		for (int i=0;i<5;i++){
			
			for(int j = 0; j<indicesClaseB.size();j++){
				if((j<tamanioB)&&(i==0)){
					particion1Temp.push_back(datos.example_vector.at(indicesClaseB.at(0)));
					indicesClaseB.erase(indicesClaseB.begin());
				}
				if((j<tamanioB)&&(i==1)){
					particion2Temp.push_back(datos.example_vector.at(indicesClaseB.at(0)));
					indicesClaseB.erase(indicesClaseB.begin());
				}
				if((j<tamanioB)&&(i==2)){
					particion3Temp.push_back(datos.example_vector.at(indicesClaseB.at(0)));
					indicesClaseB.erase(indicesClaseB.begin());
				}
				if((j<tamanioB)&&(i==3)){
					particion4Temp.push_back(datos.example_vector.at(indicesClaseB.at(0)));
					indicesClaseB.erase(indicesClaseB.begin());
				}
				if(i==4){
					particion5Temp.push_back(datos.example_vector.at(indicesClaseB.at(j)));
				}
			}

			for(int j = 0; j<indicesClaseM.size();j++){
				if((j<tamanioM)&&(i==0)){
					particion1Temp.push_back(datos.example_vector.at(indicesClaseM.at(0)));
					indicesClaseM.erase(indicesClaseM.begin());
				}
				if((j<tamanioM)&&(i==1)){
					particion2Temp.push_back(datos.example_vector.at(indicesClaseM.at(0)));
					indicesClaseM.erase(indicesClaseM.begin());
				}
				if((j<tamanioM)&&(i==2)){
					particion3Temp.push_back(datos.example_vector.at(indicesClaseM.at(0)));
					indicesClaseM.erase(indicesClaseM.begin());
				}
				if((j<tamanioM)&&(i==3)){
					particion4Temp.push_back(datos.example_vector.at(indicesClaseM.at(0)));
					indicesClaseM.erase(indicesClaseM.begin());
				}
				if(i==4){
					particion5Temp.push_back(datos.example_vector.at(indicesClaseM.at(j)));
				}
			}
		}
		particionesTrain.push_back(normalizarDatos(particion1Temp));
		particionesTrain.push_back(normalizarDatos(particion2Temp));
		particionesTrain.push_back(normalizarDatos(particion3Temp));
		particionesTrain.push_back(normalizarDatos(particion4Temp));
		particionesTrain.push_back(normalizarDatos(particion5Temp));



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
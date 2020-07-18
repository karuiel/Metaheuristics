#include "busquedaLocal.h"
	
	BusquedaLocal::BusquedaLocal(vector<Example> otraParticionA){
		particionA=otraParticionA;
		for(int i = 0;i<particionA[0].data.size();i++){
			pesos.push_back(generarNumAleatorio(0.0,1.0));
			
		}

	}
	float BusquedaLocal::KNN(vector<Example> &conjunto){
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
	float BusquedaLocal::generarNumAleatorio(float low,float high){
		 return (low + (high-(low))*(( SEED = ((SEED * PRIME) & MASK)) * SCALE));


	}

	void BusquedaLocal::LS(vector<Example> &train){
		this->train(train,15000);

	}
	void BusquedaLocal::train(vector<Example> &train, int iteraciones){
		//declaracion de variables
		vector<float> pesoslocal;
		vector<int> ordenPesos;
		vector<int> ordenPesosOriginal;
		float orden0;
		float ultimoPeso=0;
		float result=0.0;
		int malVecino=0;
		minstd_rand0 generator (time(NULL));
  		normal_distribution<float> distribucionNormal(0.0, 3.0);
		float maxResult=0;
		int numCaracteristicas=train[0].data.size();
		int maxVecinos=numCaracteristicas*20;

		//inicializo vectores

		for(int i = 0;i<numCaracteristicas;i++){
			pesoslocal.push_back(generarNumAleatorio(0.0,1.0));
			ordenPesos.push_back(i);
		}
		//pesos es un atributo de la clase
		pesos=pesoslocal;
		ordenPesosOriginal=ordenPesos;
		maxResult=KNN(train);
		for(int i=0;i<iteraciones&&(malVecino<maxVecinos);i++){
				if(ordenPesos.size()==0){
					ordenPesos=ordenPesosOriginal;
				}
				orden0=ordenPesos[0];
				ultimoPeso=pesos[orden0];

				pesos[orden0]+=distribucionNormal(generator);
				if(pesos[orden0]<0){
					pesos[orden0]=0;
				}
				if(pesos[orden0]>1){
					pesos[orden0]=1;
				}
				result=KNN(train);
				if(result>maxResult){
					maxResult=result;
					malVecino=0;
					ordenPesos=ordenPesosOriginal;
				}else{
					pesos[orden0]=ultimoPeso;
					malVecino++;
					ordenPesos.erase(ordenPesos.begin());
				}
		}
	}

	void BusquedaLocal::ILS(vector<Example> &train){
		int numAleatorio=0;
		float porcentajePesosAntiguos=0;
		float porcentajePesosNuevos=0;
		minstd_rand0 generator (time(NULL));
  		normal_distribution<float> distribucionNormal(0.0, 4.0);
		float numMutadas = 0.1*train[0].data.size();
		vector <float> pesosAnteriores;		
		this->train(train,1000);
		pesosAnteriores=pesos;
		porcentajePesosAntiguos=KNN(train);

		for(int j=0;(j<15);j++){
			for(int i=0;i<numMutadas;i++){
				numAleatorio=generarNumAleatorio(0,pesos.size());
				pesos[numAleatorio]+=distribucionNormal(generator);
			}
			this->train(train,1000);
			porcentajePesosNuevos=KNN(train);
			if(porcentajePesosNuevos>porcentajePesosAntiguos){
				porcentajePesosAntiguos=porcentajePesosNuevos;
				pesosAnteriores=pesos;
				
			}else{
				pesos=pesosAnteriores;
				
			}
		}
	}
	
	double BusquedaLocal::distanciaEuclidea(Example e1, Example e2){
		double suma=0;
		double diff;
		for (int i=0;i<e1.data.size();i++){	
				diff=(e1.data[i]-e2.data[i]);				
				suma +=diff*diff*pesos[i];				
			
		}
		return suma;

	}
	double BusquedaLocal::distanciaEuclideaSinPeso(Example e1, Example e2){
		double suma=0;
		for (int i=0;i<e1.data.size();i++){
			suma +=(e1.data[i]-e2.data[i])*(e1.data[i]-e2.data[i]);
		}
		return suma;

	}
#include "algoritmos.h"
	Algoritmos::Algoritmos(vector <Example> otraparticionTrain, vector<Example> otraparticionTest ){
		vector<float> aux(otraparticionTrain.at(0).data.size(),(float)1.0);
		pesos=aux;
		particionTrain=otraparticionTrain;
		particionTest= otraparticionTest;
	}
	float Algoritmos::evaluacion(vector<Example> &conjunto){


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
	void Algoritmos::SAGA(vector<Example> &conjunto){
		int numCaracteristicas= conjunto[0].data.size();
		vector<vector<float>> poblacionInicial;
		vector<float> aux;
		for(int i = 0;i<numCaracteristicas;i++){
			aux.push_back(generarNumAleatorio(0.0,1.0));
			
		}
		pesos=aux;
		for(int i=0;i<10;i++){			
			poblacionInicial.push_back(this->ES(conjunto,3000));
			pesos=aux;
		}
		AG genetico(conjunto,poblacionInicial);
		pesos=genetico.AGGBLX(10);

	}
	vector<float> Algoritmos::ES(vector <Example> &conjunto, int iteraciones){

		minstd_rand0 generator (time(NULL));
  		normal_distribution<float> distribucionNormal(0.0, 4.0);
		vector <float> mejorSol;
		vector <float> solActual;
		float tempInicial=0;
		float costeSolActual=0;
		float costeSolMutada=0;
		float costeMejorSol=0;
		int numEval=0;
		float temp=0;
		int numCaracteristicas= conjunto[0].data.size();
		float tempFinal=0.001;
		int vecinos=0;
		int exitos=1;
		int maxVecinos=10*numCaracteristicas;
		int maxExitos=0.1*maxVecinos;
		float beta=0;
		float costeSolInicial;
		float variacionF=0;
		int indiceMutar=0;
		float M=iteraciones/maxVecinos;
		for(int i = 0;i<numCaracteristicas;i++){
			pesos[i]=(generarNumAleatorio(0.0,1.0));
			
		}
		solActual=pesos;
		mejorSol=pesos;
		costeSolInicial=evaluacion(conjunto);
		costeSolActual=costeSolInicial;
		costeMejorSol=costeSolInicial;
		tempInicial=(-1*(0.3*costeSolInicial)/(log(0.3)));
		beta=(tempInicial-tempFinal)/(M*tempInicial*tempFinal);
		temp=tempInicial;


		while(numEval<iteraciones&&exitos!=0){
		
			exitos=0;
			vecinos=0;
			while(vecinos<maxVecinos&&exitos<maxExitos){
				
				indiceMutar=generarNumAleatorio(0,pesos.size());
				pesos[indiceMutar]+=distribucionNormal(generator);
				if(pesos[indiceMutar]<0){
					pesos[indiceMutar]=0;
				}
				if(pesos[indiceMutar]>1){
					pesos[indiceMutar]=1;
				}
				costeSolMutada=evaluacion(conjunto);
			 	numEval++;
			 	
				vecinos++;
				variacionF=costeSolMutada-costeSolActual;

				if((variacionF>0)||(generarNumAleatorio(0.0,1.0)<=exp(variacionF/temp))){
					costeSolActual=costeSolMutada;
					solActual=pesos;
					exitos++;

					if(costeSolActual>costeMejorSol){
						mejorSol=solActual;
						costeMejorSol=costeSolActual;
					}
				}else{
					pesos=solActual;
				}

			}			
			
			if(temp>tempFinal){
				temp=temp/(1+(beta*temp));
			}
		}
		return mejorSol;
	}
	void Algoritmos::DERand(vector <Example> &conjunto){
		vector<vector<float>> padres;
		vector<float> porcentajes;
		vector<float> aux;
		int evaluaciones=15000;
		int numCaracteristicas= conjunto[0].data.size();
		int indiceA,indiceB,indiceC;
		float porcentajeOffspring=0;

		for(int i=0;i<50;i++){
			for (int j=0;j<numCaracteristicas;j++){
				aux.push_back(generarNumAleatorio(0.0,1.0));
			}	
			pesos=aux;
			porcentajes.push_back(evaluacion(conjunto));
			evaluaciones--;
			padres.push_back(aux);
			aux.clear();	
		}

		while(evaluaciones>0){
			for(int i =0 ; i<padres.size(); i++){
				indiceA=generarNumAleatorio(0.0,padres.size());
				indiceB=generarNumAleatorio(0.0,padres.size());
				indiceC=generarNumAleatorio(0.0,padres.size());
				for(int j=0;j<numCaracteristicas;j++){
					if(generarNumAleatorio(0.0,1.0)<0,5){
						aux.push_back(padres[indiceA][j]+(0.5*(padres[indiceB][j]-padres[indiceC][j])));
						if(aux[j]>1){
							aux[j]=1;
						}
						if(aux[j]<0){
							aux[j]=0;
						}
					}else{
						aux.push_back(padres[i][j]);
					}
				}
				pesos=aux;
				porcentajeOffspring=evaluacion(conjunto);
				evaluaciones--;
				
				if(porcentajes[i]<porcentajeOffspring){
					padres[i]=aux;
					porcentajes[i]=porcentajeOffspring;
				}
				aux.clear();
			}
		}


	}
	void Algoritmos::DEBest(vector <Example> &conjunto){
		vector<vector<float>> padres;
		vector<float> porcentajes;
		vector<float> aux;
		int evaluaciones=15000;
		int numCaracteristicas= conjunto[0].data.size();
		int indiceA,indiceB;
		float porcentajeOffspring=0;
		float mejorPorcentaje=0;
		int indiceMejor=0;

		for(int i=0;i<50;i++){
			for (int j=0;j<numCaracteristicas;j++){
				aux.push_back(generarNumAleatorio(0.0,1.0));
			}	
			pesos=aux;
			porcentajes.push_back(evaluacion(conjunto));
			evaluaciones--;
			padres.push_back(aux);
			aux.clear();	
			if(porcentajes[i]>mejorPorcentaje){
				mejorPorcentaje=porcentajes[i];
				indiceMejor=i;
			}
		}

		while(evaluaciones>0){
			for(int i =0 ; i<padres.size(); i++){
				indiceA=generarNumAleatorio(0.0,padres.size());
				indiceB=generarNumAleatorio(0.0,padres.size());
				for(int j=0;j<numCaracteristicas;j++){
					if(generarNumAleatorio(0.0,1.0)<0.5){
						aux.push_back(padres[i][j]+(0.5*(padres[indiceMejor][j]-padres[i][j]))+(0.5*(padres[indiceA][j]-padres[indiceB][j])));
						if(aux[j]>1){
							aux[j]=1;
						}
						if(aux[j]<0){
							aux[j]=0;
						}
					}else{
						aux.push_back(padres[i][j]);
					}
				}
				pesos=aux;
				porcentajeOffspring=evaluacion(conjunto);
				evaluaciones--;
				if(porcentajes[i]<porcentajeOffspring){
					padres[i]=aux;
					porcentajes[i]=porcentajeOffspring;
					if(porcentajes[i]>mejorPorcentaje){
						mejorPorcentaje=porcentajes[i];
						indiceMejor=i;
					}
				}
				aux.clear();
			}

		}

	}
	float Algoritmos::KNN(vector <Example> &conjunto){
		float contadorClas=0;
		float contadorRed=0;
		double dmin,d;
		float tasaClas=0;
		float tasaRed=0;
		string cmin = particionTrain.at(0).class_name;		
		for(int i = 0;i<conjunto.size();i++){
			dmin = distanciaEuclidea(particionTrain.at(0) , conjunto.at(i));	
			for(int j=1;j<particionTrain.size();j++){
				d=distanciaEuclidea(particionTrain.at(j),conjunto.at(i));

				if(d<dmin){
					cmin=particionTrain.at(j).class_name;
					dmin=d;
				}

			}
			if(cmin==conjunto.at(i).class_name){
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
		cout<<"tasaClas : "<<tasaClas<<"  tasaRed"<<tasaRed<<"\n";

		return (tasaClas+tasaRed)*0.5;

	}
	float Algoritmos::generarNumAleatorio(float low,float high){

			return (low + (high-(low))*(( SEED = ((SEED * PRIME) & MASK)) * SCALE));
	}



	void Algoritmos::relief(){
		bool flagA=false;
		bool flagE=false;
		int indiceminA=0;
		float dminA=0,dminE=0;
		int indiceminE=0;
		float maxW=0;
		float d=0;
		for(int i=0;i<pesos.size();i++){
            pesos.at(i)=(float)0;

        }
		//buscamos amigo y enemigo mas cercano

	    for(int i=0;i<particionTrain.size();i++){
	    	for(int l=0;(l<particionTrain.size())&&((flagA==false)||(flagE==false));l++){
				if(i!=l){
					if(particionTrain.at(i).class_name==particionTrain.at(l).class_name){
						dminA=distanciaEuclideaSinPeso(particionTrain.at(i),particionTrain.at(l));
						flagA=true;
						
					}else{
						dminE=distanciaEuclideaSinPeso(particionTrain.at(i),particionTrain.at(l));
						flagE=true;
						
					}
				}
			}
			flagA=false;
			flagE=false;
	    	for(int j=0; j<particionTrain.size();j++){
	    		if(i!=j){
	    			d=distanciaEuclideaSinPeso(particionTrain.at(i),particionTrain.at(j));
	    			if(d<dminA&&(particionTrain.at(i).class_name==particionTrain.at(j).class_name)){
	    				dminA=d;
	    				indiceminA=j;
	     			}
	     			if(d<dminE&&(particionTrain.at(i).class_name!=particionTrain.at(j).class_name)){
	     				dminE=d;
	     				indiceminE=j;
	     				
	     			}

	    		}

	    	}
	    //calculamos los pesos y el maximo de ellos
	    	for(int k = 0;k<pesos.size();k++){
	    		pesos.at(k)+=((particionTrain.at(i).data.at(k)-particionTrain.at(indiceminE).data.at(k))*(particionTrain.at(i).data.at(k)-particionTrain.at(indiceminE).data.at(k))) -
	    		((particionTrain.at(i).data.at(k)-particionTrain.at(indiceminA).data.at(k))*(particionTrain.at(i).data.at(k)-particionTrain.at(indiceminA).data.at(k)));
	    		
	    		if(maxW<pesos.at(k)){
	    			maxW=pesos.at(k);
	    			
	    		}
	    	}
	    }
	    //normalizamos pesos
	    for(int i=0;i<pesos.size();i++){
	    	if(pesos.at(i)<0){
	    		pesos.at(i)=0;
	    	}else{
	    		pesos.at(i)=pesos.at(i)/maxW;
	    	}
	    }
	}

	double Algoritmos::distanciaEuclidea(Example e1, Example e2){
		double suma=0;
		for (int i=0;i<e1.data.size();i++){
			suma +=(e1.data.at(i)-e2.data.at(i))*(e1.data.at(i)-e2.data.at(i))*pesos.at(i);
			
		}

		return suma;

	}

	double Algoritmos::distanciaEuclideaSinPeso(Example e1, Example e2){
		double suma=0;
		for (int i=0;i<e1.data.size();i++){
			suma +=(e1.data.at(i)-e2.data.at(i))*(e1.data.at(i)-e2.data.at(i));
			
		}
		
		return suma;
	}









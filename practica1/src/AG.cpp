#include "AG.h"

	AG::AG(vector<Example> &train){
		particionTrain=train;
		Cromosoma auxcromosoma;
		indiceMejorPoblacion=0;
		vector<float> auxpesos;
		llamadas=15000;
		int numCaracteristicas= train[0].data.size();
		for(int i=0;i<30;i++){
			for(int i = 0;i<numCaracteristicas;i++){
				auxpesos.push_back(generarNumAleatorio(0.0,1.0));
				
			}
			auxcromosoma.pesos=auxpesos;
			poblacion.push_back(auxcromosoma);
			auxpesos.clear();
			poblacion[i].porcentaje=poblacion[i].KNN(train);
			llamadas--;
		}
	}
	float AG::generarNumAleatorio(float low,float high){
		 return (low + (high-(low))*(( SEED = ((SEED * PRIME) & MASK)) * SCALE));
	}

	void AG::reemplazamiento(int tipoGenetico){
		comprobar();
		int posMejor=0,posPeor=0,posPeor2=0;
		float maxResult,minResult,minResult2;
		if(tipoGenetico==0){
			bool sobrevive=false;

			maxResult=poblacion[0].porcentaje; 
		    minResult=hijos[0].porcentaje;
			

			for(int i=1;i<poblacion.size();i++){

				if(maxResult<poblacion[i].porcentaje){
					maxResult=poblacion[i].porcentaje;
					posMejor=i;
					

				}
				if(minResult>hijos[i].porcentaje){
					minResult=hijos[i].porcentaje;
					posPeor=i;
				}

			}
			for(int i=0;i<poblacion.size()&&sobrevive==false;i++){
				for(int j=0;j<hijos.size()&&sobrevive==false;j++){
					if(poblacion[i].pesos==hijos[j].pesos){
						sobrevive=true;
					}	
				}			
			}
			if(sobrevive==false){
				hijos[posPeor]=poblacion[posMejor];
				poblacion=hijos;
			}else{
				poblacion=hijos;
			}

			
		}else{
			Cromosoma hijo1,hijo2;
			
			float posMejor2=0;
			posMejor=0;
			maxResult=hijos[0].porcentaje;
			for(int i=1;i<hijos.size();i++){
				if(maxResult<hijos[i].porcentaje){
					maxResult=hijos[i].porcentaje;
					posMejor=i;
					hijo1.pesos=hijos[i].pesos;
					hijo1.porcentaje=hijos[i].porcentaje;
				}

			}
			maxResult=hijos[0].porcentaje;
			for(int i=1;i<hijos.size();i++){
				if(maxResult<hijos[i].porcentaje&&i!=posMejor){
					maxResult=hijos[i].porcentaje;
					posMejor2=i;
					hijo2.pesos=hijos[i].pesos;
					hijo2.porcentaje=hijos[i].porcentaje;
				}
				
			}
			minResult=poblacion[0].porcentaje;
			for(int i=1;i<poblacion.size();i++){

				if(minResult>poblacion[i].porcentaje){
					minResult=poblacion[i].porcentaje;
					posPeor=i;
				}

			}
			minResult=poblacion[0].porcentaje;

			for(int i=1;i<poblacion.size();i++){

				if(minResult>poblacion[i].porcentaje&&i!=posPeor){
				    minResult=poblacion[i].porcentaje;
					posPeor2=i;
				}

			}
			poblacion[posPeor].pesos=hijo1.pesos;
			poblacion[posPeor].porcentaje=hijo1.porcentaje;
			poblacion[posPeor2].pesos=hijo2.pesos;
			poblacion[posPeor2].porcentaje=hijo2.porcentaje;

		}
		hijos.clear();
	}
	void AG::seleccion(int numIteraciones){
		//0 generacional, 1 estacionario
		std::srand ( time(NULL) );
		int indiceCromosoma1,indiceCromosoma2;
		Cromosoma cromosoma1, cromosoma2;
		float resultadoC1=0, resultadoC2=0;
		for(int i=0;i<numIteraciones;i++){
			indiceCromosoma1=rand()%30;
			indiceCromosoma2=rand()%30;
			cromosoma1=poblacion[indiceCromosoma1];
			cromosoma2=poblacion[indiceCromosoma2];
			resultadoC1=cromosoma1.porcentaje;
			resultadoC2=cromosoma2.porcentaje;
			if(resultadoC1>resultadoC2){
				hijos.push_back(cromosoma1);
			}else{
				hijos.push_back(cromosoma2);
			}
		}
	}

	void AG::comprobar(){
  		
	  for(int i= 0; i < hijos.size(); i++){
	  	
	    if(hijos[i].porcentaje == -1){
	      hijos[i].porcentaje=hijos[i].KNN(particionTrain);
	      llamadas--;
	    }
	  }
	  	
	}
	//tipocruze es 0 si es BLX o 1 si es CA
	void AG::cruce(int tipoCruce, Cromosoma &padre1, Cromosoma &padre2){
		srand(time(NULL));
		float alpha=0.3;
		float cmax=0;
		float c1=0,c2=0,hi=0;
		float cmin=0;
		float I=0;
		Cromosoma aux;
		int tamanio=padre1.pesos.size();
		vector<Cromosoma> hijoCruce;

		if(tipoCruce==0){
			for(int i=0;i<2;i++){
				for(int j=0; j<tamanio;j++){
					c1=padre1.pesos[j];
					c2=padre2.pesos[j];
					if(c1<c2){
						cmax=c2;
						cmin=c1;
					}else{
						cmax=c1;
						cmin=c2;
					}
					I=cmax-cmin;

					hi=generarNumAleatorio(cmin-(I*alpha),cmax + (I*alpha));
					aux.pesos.push_back(hi);
				}
				aux.porcentaje=-1;
				hijoCruce.push_back(aux);
				aux.pesos.clear();
			}
				hijos.push_back(hijoCruce[0]);
				hijos.push_back(hijoCruce[1]);				
			
		}else{
			if(tipoCruce==1){
			
				 for(int i=0;i<tamanio;i++){
					hi=(padre1.pesos[i]+padre2.pesos[i])/2;
					
				 	aux.pesos.push_back(hi);
				 }
				aux.porcentaje=-1;
				
			    hijos.push_back(aux);
			}			
			
		}
	}
	void AG::mutacion(int fila ,int columna){
		minstd_rand0 generator (time(NULL));
  		normal_distribution<float> distribucionNormal(0.0, 3.0);
		hijos[fila].pesos[columna]+=distribucionNormal(generator);
		if(hijos[fila].pesos[columna]<0){
			hijos[fila].pesos[columna]=0;
		}

		if(hijos[fila].pesos[columna]>1){
			hijos[fila].pesos[columna]=1;
		}
		if(hijos[fila].porcentaje!=-1){
			hijos[fila].porcentaje=-1;
		}

	}

	vector<float> AG::AGGBLX(){
		Cromosoma padre1,padre2;
		float numCruces;
		int numMutaciones;
		int random1,random2;
		srand(time(NULL));
		while(llamadas>0){			
			seleccion(30);
			numCruces=0.7*hijos.size();
			

			for(int i=0;i<numCruces;i+=2){
				padre1=hijos[0];
				padre2=hijos[1];
				cruce(0,padre1,padre2);
				hijos.erase(hijos.begin());
				hijos.erase(hijos.begin());
			}
			numMutaciones=0.001*hijos.size()*hijos[0].pesos.size();
			for(int i =0;i<numMutaciones;i++){
				random1=rand()%hijos.size();
				random2=rand()%hijos[0].pesos.size();
				mutacion(random1,random2);
			}
			reemplazamiento(0);
			

		}
		int posMejor=0;
			float maxResult=poblacion[0].porcentaje;
			for(int i=1;i<poblacion.size();i++){
				if(maxResult<poblacion[i].porcentaje){
					maxResult=poblacion[i].porcentaje;
					posMejor=i;									
				}

			}
			indiceMejorPoblacion=posMejor;
			
		
		
		
		return poblacion[indiceMejorPoblacion].pesos;

	} 
	vector<float> AG::AGGCA(){
		Cromosoma padre1,padre2;
		float numCruces;
		int numMutaciones;
		int random1,random2;
		srand(time(NULL));
		while(llamadas>0){			
			seleccion(51);		
			for(int i=0;i<21;i++){
				padre1=hijos[0];
				padre2=hijos[1];
				cruce(1,padre1,padre2);
				hijos.erase(hijos.begin());
				hijos.erase(hijos.begin());
			}
			numMutaciones=0.001*hijos.size()*hijos[0].pesos.size();
			for(int i =0;i<numMutaciones;i++){
				random1=rand()%hijos.size();
				random2=rand()%hijos[0].pesos.size();
				mutacion(random1,random2);
			}
			reemplazamiento(0);
			
		}

			int posMejor=0;
			float maxResult=poblacion[0].porcentaje;
			for(int i=1;i<poblacion.size();i++){
				if(maxResult<poblacion[i].porcentaje){
					maxResult=poblacion[i].porcentaje;
					posMejor=i;									
				}

			}
			indiceMejorPoblacion=posMejor;
		return poblacion[indiceMejorPoblacion].pesos;

	}
	vector<float> AG::AGEBLX(){
		Cromosoma padre1,padre2;
		float numCruces;
		int numMutaciones;
		int random1,random2;
		srand(time(NULL));
		while(llamadas>0){			
			seleccion(2);
			numCruces=hijos.size();
			for(int i=0;i<numCruces;i+=2){
				padre1=hijos[0];
				padre2=hijos[1];
				cruce(0,padre1,padre2);
			}
			for(int i=0;i<hijos.size();i++){
				random1=rand();
				if(random1<=0.001){
					random2=rand()%hijos[0].pesos.size();
					mutacion(i,random2);
				}
			}
			reemplazamiento(1);

		}
			int posMejor=0;
			float maxResult=poblacion[0].porcentaje;
			for(int i=1;i<poblacion.size();i++){
				if(maxResult<poblacion[i].porcentaje){
					maxResult=poblacion[i].porcentaje;
					posMejor=i;									
				}

			}
			indiceMejorPoblacion=posMejor;
		
		return poblacion[indiceMejorPoblacion].pesos;
	}
	vector<float> AG::AGECA(){
		Cromosoma padre1,padre2;
		float numCruces;
		int numMutaciones;
		int random1,random2;
		srand(time(NULL));
		while(llamadas>0){			
			seleccion(2);
			numCruces=hijos.size();
			for(int i=0;i<numCruces;i+=2){
				padre1=hijos[0];
				padre2=hijos[1];
				cruce(1,padre1,padre2);
			}
			for(int i=0;i<hijos.size();i++){
				random1=rand();
				if(random1<=0.001){
					random2=rand()%hijos[0].pesos.size();
					mutacion(i,random2);
				}
			}
			reemplazamiento(1);
		}

			int posMejor=0;
			float maxResult=poblacion[0].porcentaje;
			for(int i=1;i<poblacion.size();i++){
				if(maxResult<poblacion[i].porcentaje){
					maxResult=poblacion[i].porcentaje;
					posMejor=i;									
				}

			}
			indiceMejorPoblacion=posMejor;

		return poblacion[indiceMejorPoblacion].pesos;
	}

	


#include "algoritmos.h"
	Algoritmos::Algoritmos(vector<Example> otraparticionA, vector<Example> otraparticionB ){
		vector<float> aux(otraparticionA.at(0).data.size(),(float)1.0);
		pesos=aux;
		particionA= otraparticionA;
		particionB= otraparticionB;

	}
	float Algoritmos::KNN(vector <Example> conjunto){
		float contador=0;
		double dmin,d;
		string cmin = particionA.at(0).class_name;		
		for(int i = 0;i<conjunto.size();i++){
			dmin = distanciaEuclidea(particionA.at(0) , conjunto.at(i));	
			for(int j=1;j<particionA.size();j++){
				d=distanciaEuclidea(particionA.at(j),conjunto.at(i));
				if(d<dmin){
					cmin=particionA.at(j).class_name;
					dmin=d;
				}

			}
			if(cmin==conjunto.at(i).class_name){
				contador++;
			}

		}
			for(int i=0;i<pesos.size();i++){
				cout<<"Pesos: "<<i<<" "<<pesos[i]<<"\n";
			}
		return (100*(contador/conjunto.size()));

	}
	int Algoritmos::generarNumAleatorio(int low,int high,unsigned long seed){

			(int)(low + (high-(low))* ( seed =(seed * PRIME) & MASK) * SCALE );
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
	    for(int i=0;i<particionA.size();i++){
	    	for(int l=0;(l<particionA.size())&&((flagA==false)||(flagE==false));l++){
				if(i!=l){
					if(particionA.at(i).class_name==particionA.at(l).class_name){
						dminA=distanciaEuclideaSinPeso(particionA.at(i),particionA.at(l));
						flagA=true;
						
					}else{
						dminE=distanciaEuclideaSinPeso(particionA.at(i),particionA.at(l));
						flagE=true;
						
					}
				}
			}
			flagA=false;
			flagE=false;
	    	for(int j=0; j<particionA.size();j++){
	    		if(i!=j){
	    			d=distanciaEuclideaSinPeso(particionA.at(i),particionA.at(j));
	    			if(d<dminA&&(particionA.at(i).class_name==particionA.at(j).class_name)){
	    				dminA=d;
	    				indiceminA=j;
	     			}
	     			if(d<dminE&&(particionA.at(i).class_name!=particionA.at(j).class_name)){
	     				dminE=d;
	     				indiceminE=j;
	     				
	     			}

	    		}

	    	}
	    //calculamos los pesos y el maximo de ellos
	    	for(int k = 0;k<pesos.size();k++){
	    		pesos.at(k)+=((particionA.at(i).data.at(k)-particionA.at(indiceminE).data.at(k))*(particionA.at(i).data.at(k)-particionA.at(indiceminE).data.at(k))) -
	    		((particionA.at(i).data.at(k)-particionA.at(indiceminA).data.at(k))*(particionA.at(i).data.at(k)-particionA.at(indiceminA).data.at(k)));
	    		
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









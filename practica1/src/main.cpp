#include <iostream>
#include <string>
#include "wdbc.h"
#include "spam.h"
#include "sonar.h"
#include "AG.h"
#include "busquedaLocal.h"
#include "algoritmos.h"
#include <chrono>

using namespace std;
using namespace std::chrono;
using hrc = high_resolution_clock::time_point;
int main(int argc, char *argv[]){



hrc time_before, time_after;
duration<double> total_time;	
vector <float> porcentajesKNNWdbc;
vector <float> tiemposKNNWdbc;
vector <float> porcentajesReliefWdbc;
vector <float> tiemposReliefWdbc;
vector <float> porcentajesBLWdbc;
vector <float> tiemposBLWdbc;
vector <float> porcentajesAGGBLXWdbc;
vector <float> tiemposAGGBLXWdbc;
vector <float> porcentajesAGGCAWdbc;
vector <float> tiemposAGGCAWdbc;
vector <float> porcentajesAGEBLXWdbc;
vector <float> tiemposAGEBLXWdbc;
vector <float> porcentajesAGECAWdbc;
vector <float> tiemposAGECAWdbc;

vector <float> porcentajesKNNSonar;
vector <float> tiemposKNNSonar;
vector <float> porcentajesReliefSonar;
vector <float> tiemposReliefSonar;
vector <float> porcentajesBLSonar;
vector <float> tiemposBLSonar;
vector <float> porcentajesAGGBLXSonar;
vector <float> tiemposAGGBLXSonar;
vector <float> porcentajesAGGCASonar;
vector <float> tiemposAGGCASonar;
vector <float> porcentajesAGEBLXSonar;
vector <float> tiemposAGEBLXSonar;
vector <float> porcentajesAGECASonar;
vector <float> tiemposAGECASonar;

vector <float> porcentajesKNNSpam;
vector <float> tiemposKNNSpam;
vector <float> porcentajesReliefSpam;
vector <float> tiemposReliefSpam;
vector <float> porcentajesBLSpam;
vector <float> tiemposBLSpam;
vector <float> porcentajesAGGBLXSpam;
vector <float> tiemposAGGBLXSpam;
vector <float> porcentajesAGGCASpam;
vector <float> tiemposAGGCASpam;
vector <float> porcentajesAGEBLXSpam;
vector <float> tiemposAGEBLXSpam;
vector <float> porcentajesAGECASpam;
vector <float> tiemposAGECASpam;


float sumaWdbc=0.0;
float sumaSonar=0.0;
float sumaSpam=0.0;
float aux=0;
unsigned long seed = 123;
    for (int i=0;i<5;i++){
        //creamos los datos necesarios
        Wdbc wdbc(seed+(i*10));
        Sonar sonar(seed+(i*10));
        Spam spam(seed+(i*10));

        
        Algoritmos algoritmosWdbc(wdbc.particionA,wdbc.particionB);
        Algoritmos algoritmos2Wdbc(wdbc.particionB,wdbc.particionA);
        Algoritmos algoritmosSonar(sonar.particionA,sonar.particionB);
        Algoritmos algoritmos2Sonar(sonar.particionB,sonar.particionA);
        Algoritmos algoritmosSpam(spam.particionA,spam.particionB);
        Algoritmos algoritmos2Spam(spam.particionB,spam.particionA);
        
        BusquedaLocal busquedaWdbc(wdbc.particionA);
        BusquedaLocal busquedaSonar(sonar.particionA);
        BusquedaLocal busquedaSpam(spam.particionA);
        
        AG aggblxWdbc(wdbc.particionA);
        AG aggblxSonar(sonar.particionA);
        AG aggblxSpam(spam.particionA);
        AG aggcaWdbc(wdbc.particionA);
        AG aggcaSonar(sonar.particionA);
        AG aggcaSpam(spam.particionA);
        AG ageblxWdbc(wdbc.particionA);
        AG ageblxSonar(sonar.particionA);
        AG ageblxSpam(spam.particionA);
        AG agecaWdbc(wdbc.particionA);
        AG agecaSonar(sonar.particionA); 
        AG agecaSpam(spam.particionA);

        AG aggblxWdbc2(wdbc.particionB);
        AG aggblxSonar2(sonar.particionB);
        AG aggblxSpam2(spam.particionB);
        AG aggcaWdbc2(wdbc.particionB);
        AG aggcaSonar2(sonar.particionB);
        AG aggcaSpam2(spam.particionB);
        AG ageblxWdbc2(wdbc.particionB);
        AG ageblxSonar2(sonar.particionB);
        AG ageblxSpam2(spam.particionB);
        AG agecaWdbc2(wdbc.particionB);
        AG agecaSonar2(sonar.particionB); 
        AG agecaSpam2(spam.particionB);   
        //ejecutamos Wdbc

        // time_before = high_resolution_clock::now ();
        // aux=algoritmosWdbc.KNN(wdbc.particionB);
        // porcentajesKNNWdbc.push_back(aux);
        // time_after = high_resolution_clock::now ();               
        // total_time = duration_cast<duration<double>>(time_after - time_before);
        // tiemposKNNWdbc.push_back(total_time.count());
        // cout<<"Tiempo particion "<<i<<"-1 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";


        // time_before = high_resolution_clock::now ();
        // aux=algoritmos2Wdbc.KNN(wdbc.particionA);
        // porcentajesKNNWdbc.push_back(aux);
        // time_after = high_resolution_clock::now ();               
        // total_time = duration_cast<duration<double>>(time_after - time_before);
        // tiemposKNNWdbc.push_back(total_time.count());
        // cout<<"Tiempo particion "<<i<<"-2 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";
        

        // time_before = high_resolution_clock::now ();
        // algoritmosWdbc.relief();
        // time_after = high_resolution_clock::now ();
        // aux=algoritmosWdbc.KNN(wdbc.particionB);
        // porcentajesReliefWdbc.push_back(aux);       
        // total_time = duration_cast<duration<double>>(time_after - time_before);
        // tiemposReliefWdbc.push_back(total_time.count());
        // cout<<"Tiempo particion "<<i<<"-1 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";
        
        // time_before = high_resolution_clock::now ();
        // algoritmos2Wdbc.relief();
        // time_after = high_resolution_clock::now ();
        // aux=algoritmos2Wdbc.KNN(wdbc.particionA);
        // porcentajesReliefWdbc.push_back(aux);        
        // total_time = duration_cast<duration<double>>(time_after - time_before);
        // tiemposReliefWdbc.push_back(total_time.count());
        // cout<<"Tiempo particion "<<i<<"-2 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";

        // time_before = high_resolution_clock::now ();
        // busquedaWdbc.train(wdbc.particionA);
        // time_after = high_resolution_clock::now ();
        // algoritmosWdbc.pesos=busquedaWdbc.pesos;
        // aux=algoritmosWdbc.KNN(wdbc.particionB);
        // porcentajesBLWdbc.push_back(aux);
        // total_time = duration_cast<duration<double>>(time_after - time_before);
        // tiemposBLWdbc.push_back(total_time.count());
        // cout<<"Tiempo particion "<<i<<"-1 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";

        // time_before = high_resolution_clock::now ();
        // busquedaWdbc.train(wdbc.particionB);
        // time_after = high_resolution_clock::now ();
        // algoritmos2Wdbc.pesos=busquedaWdbc.pesos;
        // aux=algoritmos2Wdbc.KNN(wdbc.particionA);
        // porcentajesBLWdbc.push_back(aux);
        // total_time = duration_cast<duration<double>>(time_after - time_before);
        // tiemposBLWdbc.push_back(total_time.count());
        // cout<<"Tiempo particion "<<i<<"-2 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";

        // time_before = high_resolution_clock::now ();
        // algoritmosWdbc.pesos = aggblxWdbc.AGGBLX();
        // time_after = high_resolution_clock::now ();
        // aux=algoritmosWdbc.KNN(wdbc.particionB);        
        // porcentajesAGGBLXWdbc.push_back(aux);
        // total_time = duration_cast<duration<double>>(time_after - time_before);
        // tiemposAGGBLXWdbc.push_back(total_time.count());
        // cout<<"Tiempo particion "<<i<<"-1 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";
        // cout.flush();
        // time_before = high_resolution_clock::now ();
        // algoritmos2Wdbc.pesos = aggblxWdbc2.AGGBLX();
        // time_after = high_resolution_clock::now ();
        // aux= algoritmos2Wdbc.KNN(wdbc.particionA);
        // porcentajesAGGBLXWdbc.push_back(aux);
        // total_time = duration_cast<duration<double>>(time_after - time_before);
        // tiemposAGGBLXWdbc.push_back(total_time.count());
        // cout<<"Tiempo particion "<<i<<"-2 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";      


        // time_before = high_resolution_clock::now ();
        // algoritmosWdbc.pesos = aggcaWdbc.AGGCA();
        // cout.flush();
        // time_after = high_resolution_clock::now (); 
        // aux=algoritmosWdbc.KNN(wdbc.particionB);     
        // porcentajesAGGCAWdbc.push_back(aux);
        // total_time = duration_cast<duration<double>>(time_after - time_before);
        // tiemposAGGCAWdbc.push_back(total_time.count());
        // cout<<"Tiempo particion "<<i<<"-1 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";
        // cout.flush();

        // time_before = high_resolution_clock::now ();
        // algoritmos2Wdbc.pesos = aggcaWdbc2.AGGCA();
        // time_after = high_resolution_clock::now ();
        // aux=algoritmos2Wdbc.KNN(wdbc.particionA);
        // porcentajesAGGCAWdbc.push_back(aux);
        // total_time = duration_cast<duration<double>>(time_after - time_before);
        // tiemposAGGCAWdbc.push_back(total_time.count());
        // cout<<"Tiempo particion "<<i<<"-2 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";


        



        //ejecutamos sonar


        // time_before = high_resolution_clock::now ();
        // aux=algoritmosSonar.KNN(sonar.particionB);
        // porcentajesKNNSonar.push_back(aux);
        // time_after = high_resolution_clock::now ();               
        // total_time = duration_cast<duration<double>>(time_after - time_before);
        // tiemposKNNSonar.push_back(total_time.count());
        // cout<<"Tiempo particion "<<i<<"-1 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";

        // time_before = high_resolution_clock::now ();
        // aux=algoritmos2Sonar.KNN(sonar.particionA);
        // porcentajesKNNSonar.push_back(aux);
        // time_after = high_resolution_clock::now ();               
        // total_time = duration_cast<duration<double>>(time_after - time_before);
        // tiemposKNNSonar.push_back(total_time.count());
        // cout<<"Tiempo particion "<<i<<"-2 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";


        // time_before = high_resolution_clock::now ();
        // algoritmosSonar.relief();
        // time_after = high_resolution_clock::now ();
        // aux=algoritmosSonar.KNN(sonar.particionB);
        // porcentajesReliefSonar.push_back(aux);       
        // total_time = duration_cast<duration<double>>(time_after - time_before);
        // tiemposReliefSonar.push_back(total_time.count());
        // cout<<"Tiempo particion "<<i<<"-1 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";
        
        // time_before = high_resolution_clock::now ();
        // algoritmos2Sonar.relief();
        // time_after = high_resolution_clock::now ();
        // aux=algoritmos2Sonar.KNN(sonar.particionA);
        // porcentajesReliefSonar.push_back(aux);        
        // total_time = duration_cast<duration<double>>(time_after - time_before);
        // tiemposReliefSonar.push_back(total_time.count());
        // cout<<"Tiempo particion "<<i<<"-2 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";



        time_before = high_resolution_clock::now ();
        busquedaSonar.train(sonar.particionA);
        time_after = high_resolution_clock::now ();
        algoritmosSonar.pesos=busquedaSonar.pesos;
        aux=algoritmosSonar.KNN(sonar.particionB);
        porcentajesBLSonar.push_back(aux);
        total_time = duration_cast<duration<double>>(time_after - time_before);
        tiemposBLSonar.push_back(total_time.count());
        cout<<"Tiempo particion "<<i<<"-1 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";

        time_before = high_resolution_clock::now ();
        busquedaSonar.train(sonar.particionB);
        time_after = high_resolution_clock::now ();
        algoritmosSonar.pesos=busquedaSonar.pesos;
        aux=algoritmosSonar.KNN(sonar.particionA);
        porcentajesBLSonar.push_back(aux);
        total_time = duration_cast<duration<double>>(time_after - time_before);
        tiemposBLSonar.push_back(total_time.count());
        cout<<"Tiempo particion "<<i<<"-1 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";

        // time_before = high_resolution_clock::now ();
        // busquedaSonar.train(sonar.particionB);
        // time_after = high_resolution_clock::now ();
        // algoritmos2Sonar.pesos=busquedaSonar.pesos;
        // aux=algoritmos2Sonar.KNN(sonar.particionA);
        // porcentajesBLSonar.push_back(aux);
        // total_time = duration_cast<duration<double>>(time_after - time_before);
        // tiemposBLSonar.push_back(total_time.count());
        // cout<<"Tiempo particion "<<i<<"-2 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";


        // time_before = high_resolution_clock::now ();
        // algoritmosSonar.pesos = aggblxSonar.AGGBLX();
        // time_after = high_resolution_clock::now ();
        // aux=algoritmosSonar.KNN(sonar.particionB);        
        // porcentajesAGGBLXSonar.push_back(aux);
        // total_time = duration_cast<duration<double>>(time_after - time_before);
        // tiemposAGGBLXSonar.push_back(total_time.count());
        // cout<<"Tiempo particion "<<i<<"-1 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";
        // cout.flush();
        // time_before = high_resolution_clock::now ();
        // algoritmos2Sonar.pesos = aggblxSonar2.AGGBLX();
        // time_after = high_resolution_clock::now ();
        // aux= algoritmos2Sonar.KNN(sonar.particionA);
        // porcentajesAGGBLXSonar.push_back(aux);
        // total_time = duration_cast<duration<double>>(time_after - time_before);
        // tiemposAGGBLXSonar.push_back(total_time.count());
        // cout<<"Tiempo particion "<<i<<"-2 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";

       


        // time_before = high_resolution_clock::now ();
        // algoritmosSonar.pesos = aggcaSonar.AGGCA();
        // cout.flush();
        // time_after = high_resolution_clock::now (); 
        // aux=algoritmosSonar.KNN(sonar.particionB);     
        // porcentajesAGGCASonar.push_back(aux);
        // total_time = duration_cast<duration<double>>(time_after - time_before);
        // tiemposAGGCASonar.push_back(total_time.count());
        // cout<<"Tiempo particion "<<i<<"-1 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";
        // cout.flush();

        // time_before = high_resolution_clock::now ();
        // algoritmos2Sonar.pesos = aggcaSonar2.AGGCA();
        // time_after = high_resolution_clock::now ();
        // aux=algoritmos2Sonar.KNN(sonar.particionA);
        // porcentajesAGGCASonar.push_back(aux);
        // total_time = duration_cast<duration<double>>(time_after - time_before);
        // tiemposAGGCASonar.push_back(total_time.count());
        // cout<<"Tiempo particion "<<i<<"-2 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";

        // time_before = high_resolution_clock::now ();
        // algoritmosSonar.pesos = ageblxSonar.AGEBLX();
        // time_after = high_resolution_clock::now ();
        // aux=algoritmosSonar.KNN(sonar.particionB);        
        // porcentajesAGEBLXSonar.push_back(aux);
        // total_time = duration_cast<duration<double>>(time_after - time_before);
        // tiemposAGEBLXSonar.push_back(total_time.count());
        // cout<<"Tiempo particion "<<i<<"-1 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";

        // time_before = high_resolution_clock::now ();
        // algoritmos2Sonar.pesos = ageblxSonar2.AGEBLX();
        // time_after = high_resolution_clock::now ();
        // porcentajesAGEBLXSonar.push_back(algoritmos2Sonar.KNN(sonar.particionA));
        // total_time = duration_cast<duration<double>>(time_after - time_before);
        // tiemposAGEBLXSonar.push_back(total_time.count());

        // time_before = high_resolution_clock::now ();
        // algoritmosSonar.pesos = agecaSonar.AGECA();
        // time_after = high_resolution_clock::now ();        
        // porcentajesAGECASonar.push_back(algoritmosSonar.KNN(sonar.particionB));
        // total_time = duration_cast<duration<double>>(time_after - time_before);
        // tiemposAGECASonar.push_back(total_time.count());

        // time_before = high_resolution_clock::now ();
        // algoritmos2Sonar.pesos = agecaSonar2.AGECA();
        // time_after = high_resolution_clock::now ();
        // porcentajesAGECASonar.push_back(algoritmos2Sonar.KNN(sonar.particionA));
        // total_time = duration_cast<duration<double>>(time_after - time_before);
        // tiemposAGECASonar.push_back(total_time.count());



        //ejecutamos Spam
        time_before = high_resolution_clock::now ();
        aux=algoritmosSpam.KNN(spam.particionB);
        porcentajesKNNSpam.push_back(aux);
        time_after = high_resolution_clock::now ();               
        total_time = duration_cast<duration<double>>(time_after - time_before);
        tiemposKNNSpam.push_back(total_time.count());
        cout<<"Tiempo particion "<<i<<"-1 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";

        // time_before = high_resolution_clock::now ();
        // aux=algoritmos2Spam.KNN(spam.particionA);
        // porcentajesKNNSpam.push_back(aux);
        // time_after = high_resolution_clock::now ();               
        // total_time = duration_cast<duration<double>>(time_after - time_before);
        // tiemposKNNSpam.push_back(total_time.count());
        // cout<<"Tiempo particion "<<i<<"-2 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";


        // time_before = high_resolution_clock::now ();
        // algoritmosSpam.relief();
        // time_after = high_resolution_clock::now ();
        // aux=algoritmosSpam.KNN(spam.particionB);
        // porcentajesReliefSpam.push_back(aux);        
        // total_time = duration_cast<duration<double>>(time_after - time_before);
        // tiemposReliefSpam.push_back(total_time.count());
        // cout<<"Tiempo particion "<<i<<"-1 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";

        
        // time_before = high_resolution_clock::now ();
        // algoritmos2Spam.relief();
        // time_after = high_resolution_clock::now ();
        // aux=algoritmos2Spam.KNN(spam.particionA);
        // porcentajesReliefSpam.push_back(aux);        
        // total_time = duration_cast<duration<double>>(time_after - time_before);
        // tiemposReliefSpam.push_back(total_time.count());
        // cout<<"Tiempo particion "<<i<<"-2 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";

        // time_before = high_resolution_clock::now ();
        // busquedaSpam.train(spam.particionA);
        // time_after = high_resolution_clock::now ();
        // algoritmosSpam.pesos=busquedaSpam.pesos;
        // aux=algoritmosSpam.KNN(spam.particionB);
        // porcentajesBLSpam.push_back(aux);
        // total_time = duration_cast<duration<double>>(time_after - time_before);
        // tiemposBLSpam.push_back(total_time.count());
        // cout<<"Tiempo particion "<<i<<"-1 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";

        // time_before = high_resolution_clock::now ();
        // busquedaSpam.train(spam.particionB);
        // time_after = high_resolution_clock::now ();
        // algoritmos2Spam.pesos=busquedaSpam.pesos;
        // aux=algoritmos2Spam.KNN(spam.particionA);
        // porcentajesBLSpam.push_back(aux);
        // total_time = duration_cast<duration<double>>(time_after - time_before);
        // tiemposBLSpam.push_back(total_time.count());
        // cout<<"Tiempo particion "<<i<<"-2 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";

        // time_before = high_resolution_clock::now ();
        // algoritmosSpam.pesos = aggblxSpam.AGGBLX();
        // time_after = high_resolution_clock::now ();
        // aux=algoritmosSpam.KNN(spam.particionB);        
        // porcentajesAGGBLXSpam.push_back(aux);
        // total_time = duration_cast<duration<double>>(time_after - time_before);
        // tiemposAGGBLXSpam.push_back(total_time.count());
        // cout<<"Tiempo particion "<<i<<"-1 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";
        // cout.flush();

        // time_before = high_resolution_clock::now ();
        // algoritmos2Spam.pesos = aggblxSpam2.AGGBLX();
        // time_after = high_resolution_clock::now ();
        // aux= algoritmos2Spam.KNN(spam.particionA);
        // porcentajesAGGBLXSpam.push_back(aux);
        // total_time = duration_cast<duration<double>>(time_after - time_before);
        // tiemposAGGBLXSpam.push_back(total_time.count());
        // cout<<"Tiempo particion "<<i<<"-2 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";

       


        // time_before = high_resolution_clock::now ();
        // algoritmosSpam.pesos = aggcaSpam.AGGCA();
        // cout.flush();
        // time_after = high_resolution_clock::now (); 
        // aux=algoritmosSpam.KNN(spam.particionB);     
        // porcentajesAGGCASpam.push_back(aux);
        // total_time = duration_cast<duration<double>>(time_after - time_before);
        // tiemposAGGCASpam.push_back(total_time.count());
        // cout<<"Tiempo particion "<<i<<"-1 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";
        // cout.flush();

        // time_before = high_resolution_clock::now ();
        // algoritmos2Spam.pesos = aggcaSpam2.AGGCA();
        // time_after = high_resolution_clock::now ();
        // aux=algoritmos2Spam.KNN(spam.particionA);
        // porcentajesAGGCASpam.push_back(aux);
        // total_time = duration_cast<duration<double>>(time_after - time_before);
        // tiemposAGGCASpam.push_back(total_time.count());
        // cout<<"Tiempo particion "<<i<<"-2 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";

    }

   
    return 0;
}
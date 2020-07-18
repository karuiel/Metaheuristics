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
vector <float> porcentajes;
vector <float> tiempos;


float sumaWdbc=0.0;
float sumaSonar=0.0;
float sumaSpam=0.0;
float aux=0;
unsigned long seed = 123;
    for (int i=0;i<5;i++){
        //creamos los datos necesarios
        Wdbc wdbc(seed,i);
        Sonar sonar(seed,i);
        Spam spam(seed,i);

        
        Algoritmos algoritmosWdbc(wdbc.particionTrain,wdbc.particionTest);        
        Algoritmos algoritmosSonar(sonar.particionTrain,sonar.particionTest);
        Algoritmos algoritmosSpam(spam.particionTrain,spam.particionTest);        
        BusquedaLocal busquedaWdbc(wdbc.particionTrain);
        BusquedaLocal busquedaSonar(sonar.particionTrain);
        BusquedaLocal busquedaSpam(spam.particionTrain);
        AG aggblxSonar(sonar.particionTrain);
        AG aggblxSpam(spam.particionTrain);
        AG aggblxWdbc(wdbc.particionTrain);
        
       // ejecutamos Wdbc
        // cout<<"WDBC"<<"\n\n";
        // time_before = high_resolution_clock::now ();
        // aux=algoritmosWdbc.KNN(wdbc.particionTest);
        // time_after = high_resolution_clock::now ();               
        // total_time = duration_cast<duration<double>>(time_after - time_before);
        // cout<<"Tiempo KNN particion "<<i<<"-1 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";
        

        // time_before = high_resolution_clock::now ();
        // algoritmosWdbc.relief();
        // time_after = high_resolution_clock::now ();
        // aux=algoritmosWdbc.KNN(wdbc.particionTest);      
        // total_time = duration_cast<duration<double>>(time_after - time_before);
        // cout<<"Tiempo Relief particion "<<i<<"-1 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";


        // time_before = high_resolution_clock::now ();
        // busquedaWdbc.LS(wdbc.particionTrain);
        // time_after = high_resolution_clock::now ();
        // algoritmosWdbc.pesos=busquedaWdbc.pesos;
        // aux=algoritmosWdbc.KNN(wdbc.particionTest);
        // total_time = duration_cast<duration<double>>(time_after - time_before);
        // cout<<"Tiempo LS particion "<<i<<"-1 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";

        // time_before = high_resolution_clock::now ();
        // busquedaWdbc.ILS(wdbc.particionTrain);
        // time_after = high_resolution_clock::now ();
        // algoritmosWdbc.pesos=busquedaWdbc.pesos;
        // aux=algoritmosWdbc.KNN(wdbc.particionTest);
        // total_time = duration_cast<duration<double>>(time_after - time_before);
        // cout<<"Tiempo ILS particion "<<i<<"-1 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";

        // time_before = high_resolution_clock::now ();
        // algoritmosWdbc.pesos = aggblxWdbc.AGGBLX(30);
        // time_after = high_resolution_clock::now ();
        // aux=algoritmosWdbc.KNN(wdbc.particionTest);        
        // total_time = duration_cast<duration<double>>(time_after - time_before);
        // cout<<"Tiempo AGGBLX particion "<<i<<"-1 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";     


        // time_before = high_resolution_clock::now ();
        // algoritmosWdbc.pesos=algoritmosWdbc.ES(wdbc.particionTrain,15000);
        // time_after = high_resolution_clock::now ();
        // aux=algoritmosWdbc.KNN(wdbc.particionTest);
        // total_time = duration_cast<duration<double>>(time_after - time_before);
        // cout<<"Tiempo SA particion "<<i<<"-1 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";

        // time_before = high_resolution_clock::now ();
        // algoritmosWdbc.DEBest(wdbc.particionTrain);
        // time_after = high_resolution_clock::now ();
        // aux=algoritmosWdbc.KNN(wdbc.particionTest);
        // total_time = duration_cast<duration<double>>(time_after - time_before);
        // cout<<"Tiempo DEBest particion "<<i<<"-1 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";


        // time_before = high_resolution_clock::now ();
        // algoritmosWdbc.DERand(wdbc.particionTrain);
        // time_after = high_resolution_clock::now ();
        // aux=algoritmosWdbc.KNN(wdbc.particionTest);
        // total_time = duration_cast<duration<double>>(time_after - time_before);
        // cout<<"Tiempo DERand particion "<<i<<"-1 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";

        // time_before = high_resolution_clock::now ();
        // algoritmosWdbc.SAGA(wdbc.particionTrain);
        // time_after = high_resolution_clock::now ();
        // aux=algoritmosWdbc.KNN(wdbc.particionTest);
        // total_time = duration_cast<duration<double>>(time_after - time_before);
        // cout<<"Tiempo SAGA particion "<<i<<"-1 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";


//SONAR
        // cout<<"SONAR"<<"\n\n";

       // time_before = high_resolution_clock::now ();
       //  aux=algoritmosSonar.KNN(sonar.particionTest);
       //  time_after = high_resolution_clock::now ();               
       //  total_time = duration_cast<duration<double>>(time_after - time_before);
       //  cout<<"Tiempo KNN particion "<<i<<"-1 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";
        

       //  time_before = high_resolution_clock::now ();
       //  algoritmosSonar.relief();
       //  time_after = high_resolution_clock::now ();
       //  aux=algoritmosSonar.KNN(sonar.particionTest);      
       //  total_time = duration_cast<duration<double>>(time_after - time_before);
       //  cout<<"Tiempo Relief particion "<<i<<"-1 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";


       //  time_before = high_resolution_clock::now ();
       //  busquedaSonar.LS(sonar.particionTrain);
       //  time_after = high_resolution_clock::now ();
       //  algoritmosSonar.pesos=busquedaSonar.pesos;
       //  aux=algoritmosSonar.KNN(sonar.particionTest);
       //  total_time = duration_cast<duration<double>>(time_after - time_before);
       //  cout<<"Tiempo LS particion "<<i<<"-1 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";

       //  time_before = high_resolution_clock::now ();
       //  busquedaSonar.ILS(sonar.particionTrain);
       //  time_after = high_resolution_clock::now ();
       //  algoritmosSonar.pesos=busquedaSonar.pesos;
       //  aux=algoritmosSonar.KNN(sonar.particionTest);
       //  total_time = duration_cast<duration<double>>(time_after - time_before);
       //  cout<<"Tiempo ILS particion "<<i<<"-1 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";

       //  time_before = high_resolution_clock::now ();
       //  algoritmosSonar.pesos = aggblxSonar.AGGBLX(30);
       //  time_after = high_resolution_clock::now ();
       //  aux=algoritmosSonar.KNN(sonar.particionTest);        
       //  total_time = duration_cast<duration<double>>(time_after - time_before);
       //  cout<<"Tiempo AGGBLX particion "<<i<<"-1 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";     


       //  time_before = high_resolution_clock::now ();
       //  algoritmosSonar.pesos=algoritmosSonar.ES(sonar.particionTrain,15000);
       //  time_after = high_resolution_clock::now ();
       //  aux=algoritmosSonar.KNN(sonar.particionTest);
       //  total_time = duration_cast<duration<double>>(time_after - time_before);
       //  cout<<"Tiempo SA particion "<<i<<"-1 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";

       //  time_before = high_resolution_clock::now ();
       //  algoritmosSonar.DEBest(sonar.particionTrain);
       //  time_after = high_resolution_clock::now ();
       //  aux=algoritmosSonar.KNN(sonar.particionTest);
       //  total_time = duration_cast<duration<double>>(time_after - time_before);
       //  cout<<"Tiempo DEBest particion "<<i<<"-1 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";


        // time_before = high_resolution_clock::now ();
        // algoritmosSonar.DERand(sonar.particionTrain);
        // time_after = high_resolution_clock::now ();
        // aux=algoritmosSonar.KNN(sonar.particionTest);
        // total_time = duration_cast<duration<double>>(time_after - time_before);
        // cout<<"Tiempo DERand particion "<<i<<"-1 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";

        // time_before = high_resolution_clock::now ();
        // algoritmosSonar.SAGA(sonar.particionTrain);
        // time_after = high_resolution_clock::now ();
        // aux=algoritmosSonar.KNN(sonar.particionTest);
        // total_time = duration_cast<duration<double>>(time_after - time_before);
        // cout<<"Tiempo SAGA particion "<<i<<"-1 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";




// SPAM
       //  cout<<"SPAM"<<"\n\n";

       // time_before = high_resolution_clock::now ();
       //  aux=algoritmosSpam.KNN(spam.particionTest);
       //  time_after = high_resolution_clock::now ();               
       //  total_time = duration_cast<duration<double>>(time_after - time_before);
       //  cout<<"Tiempo KNN particion "<<i<<"-1 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";
        

       //  time_before = high_resolution_clock::now ();
       //  algoritmosSpam.relief();
       //  time_after = high_resolution_clock::now ();
       //  aux=algoritmosSpam.KNN(spam.particionTest);      
       //  total_time = duration_cast<duration<double>>(time_after - time_before);
       //  cout<<"Tiempo Relief particion "<<i<<"-1 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";


       //  time_before = high_resolution_clock::now ();
       //  busquedaSpam.LS(spam.particionTrain);
       //  time_after = high_resolution_clock::now ();
       //  algoritmosSpam.pesos=busquedaSpam.pesos;
       //  aux=algoritmosSpam.KNN(spam.particionTest);
       //  total_time = duration_cast<duration<double>>(time_after - time_before);
       //  cout<<"Tiempo LS particion "<<i<<"-1 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";

       //  time_before = high_resolution_clock::now ();
       //  busquedaSpam.ILS(spam.particionTrain);
       //  time_after = high_resolution_clock::now ();
       //  algoritmosSpam.pesos=busquedaSpam.pesos;
       //  aux=algoritmosSpam.KNN(spam.particionTest);
       //  total_time = duration_cast<duration<double>>(time_after - time_before);
       //  cout<<"Tiempo ILS particion "<<i<<"-1 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";

       //  time_before = high_resolution_clock::now ();
       //  algoritmosSpam.pesos = aggblxSpam.AGGBLX(30);
       //  time_after = high_resolution_clock::now ();
       //  aux=algoritmosSpam.KNN(spam.particionTest);        
       //  total_time = duration_cast<duration<double>>(time_after - time_before);
       //  cout<<"Tiempo AGGBLX particion "<<i<<"-1 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";     


       //  time_before = high_resolution_clock::now ();
       //  algoritmosSpam.pesos=algoritmosSpam.ES(spam.particionTrain,15000);
       //  time_after = high_resolution_clock::now ();
       //  aux=algoritmosSpam.KNN(spam.particionTest);
       //  total_time = duration_cast<duration<double>>(time_after - time_before);
       //  cout<<"Tiempo SA particion "<<i<<"-1 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";

       //  time_before = high_resolution_clock::now ();
       //  algoritmosSpam.DEBest(spam.particionTrain);
       //  time_after = high_resolution_clock::now ();
       //  aux=algoritmosSpam.KNN(spam.particionTest);
       //  total_time = duration_cast<duration<double>>(time_after - time_before);
       //  cout<<"Tiempo DEBest particion "<<i<<"-1 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";


       //  time_before = high_resolution_clock::now ();
       //  algoritmosSpam.DERand(spam.particionTrain);
       //  time_after = high_resolution_clock::now ();
       //  aux=algoritmosSpam.KNN(spam.particionTest);
       //  total_time = duration_cast<duration<double>>(time_after - time_before);
       //  cout<<"Tiempo DERand particion "<<i<<"-1 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";

        // time_before = high_resolution_clock::now ();
        // algoritmosSpam.SAGA(spam.particionTrain);
        // time_after = high_resolution_clock::now ();
        // aux=algoritmosSpam.KNN(spam.particionTest);
        // total_time = duration_cast<duration<double>>(time_after - time_before);
        // cout<<"Tiempo SAGA particion "<<i<<"-1 "<<total_time.count()<<" Porcentaje "<<aux<<"\n";




    }

   
    return 0;
}
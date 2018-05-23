#include <iostream>
#include <chrono>
#include <iomanip>
#include "Generavimas.h"
#include "Nuskaitymas.h"
#include "Studentas.h"
using std::setw;

int main()
{
    int kiekis=10;


    auto start = std::chrono::high_resolution_clock::now();
    for(int i=0; i<5; i++)
    {
        Generavimas(kiekis);
        kiekis=kiekis*10;
    }
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    cout<<"failu generavimo laikas - "<<elapsed.count()<<"s"<<endl;
    kiekis=10;
    for(int i=0; i<5;i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        Nuskaitymas(kiekis);
         kiekis=kiekis*10;
        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        cout<<std::left<<"| "<<setw(9)<<kiekis<<" failu ivedimo ir sugrupavimo laikas - "<<setw(8)<<elapsed.count()<<"s"<<" |"<<endl;
    }
    cout<<"-------------------------------------------------------------"<<endl;

return 0;
}
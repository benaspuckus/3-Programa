#include "IsFailo.cpp"
#include "PazymiuIvedimas.cpp"
#include "Mediana.cpp"
#include "Galutinis.cpp"
#include "IsFailoD.cpp"
#include "IsFailoL.cpp"
#include "Generavimas.cpp"
#include <iomanip>
#include<cmath>
#include <chrono>
#include <Windows.h>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <iostream>
#include <random>
using std::cin;
using std::cout;
using std::string;
using std::ifstream;
using std::ofstream;
using std::setprecision;
using std::swap;
using std::sort;
using std::endl;
using std::vector;
using std::setw;
using std::random_device;
using std::mt19937;
using std::uniform_real_distribution;
int main()
{
    int kiekis=10;
    auto start = std::chrono::high_resolution_clock::now();
    for(int i=0; i<5; i++)
    {

        generavimas(kiekis);
        kiekis=kiekis*10;
    }
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    cout<<"failu generavimo laikas - "<<elapsed.count()<<"s"<<endl;
    kiekis=10;
    vector<Studentas> a;
    int n;
    int k;
    int u;
    int p;
    int x;
    int o=0;
    int t;
    int l;
    double vidurkis=0;
    double galutinis;
    cout<<"ar ivesite duomenis, ar skaitysime is failo? 1 - ivesiu 2 - is failo"<<endl;
    cin>>l;
    if(l==2) //jeigu skaitome is failo
    {
        p=1;
        cout<<"Naudojant 2 konteinerius"<<endl;
        cout<<"Vektorius:"<<endl;
        cout<<"-------------------------------------------------------------"<<endl;

        for(int i=0; i<5; i++)
        {
            auto start = std::chrono::high_resolution_clock::now();
            IsFailo(kiekis,p);
            auto finish = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = finish - start;
            cout<<std::left<<"| "<<setw(9)<<kiekis<<" failu ivedimo ir sugrupavimo laikas - "<<setw(8)<<elapsed.count()<<"s"<<" |"<<endl;
            kiekis=kiekis*10;
        }
        cout<<"-------------------------------------------------------------"<<endl;;
        kiekis=10;
        cout<<"Deque:"<<endl;
        cout<<"-------------------------------------------------------------"<<endl;
        for(int i=0; i<5; i++)
        {
            auto start = std::chrono::high_resolution_clock::now();
            IsFailoD(kiekis,p);
            auto finish = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = finish - start;
            cout<<std::left<<"| "<<setw(9)<<kiekis<<" failu ivedimo ir sugrupavimo laikas - "<<setw(8)<<elapsed.count()<<"s"<<" |"<<endl;
            kiekis=kiekis*10;
        }
        cout<<"-------------------------------------------------------------"<<endl;
                kiekis=10;
        cout<<"List:"<<endl;
        cout<<"-------------------------------------------------------------"<<endl;
        for(int i=0; i<5; i++)
        {
            auto start = std::chrono::high_resolution_clock::now();
            IsFailoL(kiekis,p);
            auto finish = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = finish - start;
            cout<<std::left<<"| "<<setw(9)<<kiekis<<" failu ivedimo ir sugrupavimo laikas - "<<setw(8)<<elapsed.count()<<"s"<<" |"<<endl;
            kiekis=kiekis*10;
        }
        cout<<"-------------------------------------------------------------"<<endl;
        cout<<"Naudojant 3 konteinerius"<<endl;
        p=2;
        kiekis=10;
        cout<<"Vektorius:"<<endl;
        cout<<"-------------------------------------------------------------"<<endl;

        for(int i=0; i<5; i++)
        {
            auto start = std::chrono::high_resolution_clock::now();
            IsFailo(kiekis,p);
            auto finish = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = finish - start;
            cout<<std::left<<"| "<<setw(9)<<kiekis<<" failu ivedimo ir sugrupavimo laikas - "<<setw(8)<<elapsed.count()<<"s"<<" |"<<endl;
            kiekis=kiekis*10;
        }
        cout<<"-------------------------------------------------------------"<<endl;;
        kiekis=10;
        cout<<"Deque:"<<endl;
        cout<<"-------------------------------------------------------------"<<endl;
        for(int i=0; i<5; i++)
        {
            auto start = std::chrono::high_resolution_clock::now();
            IsFailoD(kiekis,p);
            auto finish = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = finish - start;
            cout<<std::left<<"| "<<setw(9)<<kiekis<<" failu ivedimo ir sugrupavimo laikas - "<<setw(8)<<elapsed.count()<<"s"<<" |"<<endl;
            kiekis=kiekis*10;
        }
        cout<<"-------------------------------------------------------------"<<endl;
                kiekis=10;
        cout<<"List:"<<endl;
        cout<<"-------------------------------------------------------------"<<endl;
        for(int i=0; i<5; i++)
        {
            auto start = std::chrono::high_resolution_clock::now();
            IsFailoL(kiekis,p);
            auto finish = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = finish - start;
            cout<<std::left<<"| "<<setw(9)<<kiekis<<" failu ivedimo ir sugrupavimo laikas - "<<setw(8)<<elapsed.count()<<"s"<<" |"<<endl;
            kiekis=kiekis*10;
        }
        cout<<"-------------------------------------------------------------"<<endl;


    }
    if(l==1)
    {
        a.push_back(Studentas());
        cout<<"iveskite varda"<<endl;
        cin>>a[0].vard;
        cout<<"iveskite pavarde"<<endl;
        cin>>a[0].pav;
        cout<<"ar zinote namu darbu iverinimu skaiciu?"<<endl<<"1 - taip, zinau  2 - ne, dar nezinau"<<endl;
        cin>>t;
        if(t==1) //jeigu zinome pazymiu skaiciu
        {
            int k;
            int x;
            int o=0;
            cout<<"iveskite iverciu skaiciu"<<endl;
            cin>>n;
            cout<<"kaip ivesime?"<<endl<<"1 - patys 2 - random"<<endl;
            cin>>k;
            if(k==1) // jeigu skaicuojame pagal vidurki
            {
                cout<<"iveskite "<<n<<" pazymius"<<endl;
                for(int i=0; i<n; i++) //iveda pazymius i masyva
                {
                    cin>>x;
                    PazymiuIvedimas(x,a,i);

                }
            }

            if(k==2) //random generuoja skaicius. Tiek, kiek yra n
            {
                std::random_device rd;
                std::mt19937 mt(rd());
                std::uniform_real_distribution<double> dist(1.0, 10.0);

                for (int i=0; i<=n; ++i)
                {
                    x=dist(mt);
                    PazymiuIvedimas(x,a,i);
                }
            }
            cout<<"skaiciuosime pagal 1 - vidurkis 2 - mediana"<<endl;
            cin>>k;
            if(k==2)
            {
               Mediana(n,o,a);
            }
            o=1;
            cout<<"iveskite egzamino rezultata"<<endl;
            while(o!=0)
            {

                cin>>a[0].egz;
                int i=0;
                Galutinis(o,i,a,k,n);
            }
            cout<<a[0].vard<<"  "<<a[0].pav<<"  "<<endl;
            cout<<"pazymiai:"<<endl;
            for(int i=0; i<n; i++) // isveda turimus pazymius
            {
                cout<<a[0].v[i]<<"  ";
            }

            cout<<endl<<"egzamino rezultatas: "<<a[0].egz<<"  galutinis: "<<setprecision(3)<<a[o].gal;
        }
        if(t==2) //jeigu skaiciu nezinome
        {
            cout<<"veskite pazymius, kai noresite baigti, iveskite 0"<<endl;
            int o=0;
            int i=0;
            while(o!=1) //labai idomus ciklas. Kadangi protingai nieko nesugalvojau, pazymiai ivedami tol, kol ivesime 0, o tai reiskia, akad pazymiai baigti vesti.
            {
                cout<<"iveskite skaiciu: ";
                cin>>x;
                PazymiuIvedimas(x,a,i);
                if(x==0) // jeigu ivedame nuli
                {
                    o=1;
                    i--;
                }
                i++;
            }
            cout<<"kaip vertinsime?"<<endl<<"1 - vidurkis   2 - mediana"<<endl; //tas oats, vertinsime pagal vidurki arba mediana
            cin>>k;
            o=0;
            if(k==2)
            {
                Mediana(i,o,a);
            }
            cout<<"iveskite egzamino rezultata"<<endl;
            o=1;
            while(o!=0)
            {
                cin>>a[0].egz;
                int i=0;
                Galutinis(o,i,a,k,n);
            }


            cout<<a[0].vard<<"  "<<a[0].pav<<"  "<<endl<<"pazymiai:"<<endl;

            for(int j=0; j<i; j++)
            {
                cout<<a[0].v[j]<<"  ";
            }
            cout<<endl<<" egzamino rezultatas: "<<a[0].egz<<"  galutinis: "<<setprecision(3)<<a[0].gal;
            return 0;

        }
    }
}




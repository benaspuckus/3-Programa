#include "IvestiPaciamZinomus.h"
#include "studentai.h"
#include <iomanip>
#include<cmath>
#include "Galutinis.cpp"
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
void IvestiPaciamZinomus(int n,vector<Studentas> &a)
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

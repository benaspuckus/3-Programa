#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <fstream>
#include <random>
using std::cin;
using std::cout;
using std::string;
using std::ifstream;
using std::setprecision;
using std::endl;
using std::setw;
using std::random_device;
using std::mt19937;
using std::uniform_real_distribution;
-std=c11;
int main()
{
    ifstream fd("duom.txt");
    string vardas;
    string pavarde;
    int n;
    int k;
    int u;
    int medi=0;

    double balai[50];
    double vidurkis=0;
    double galutinis;
    double egzaminas;
    int t;
    cout<<"iveskite varda"<<endl;
    cin>>vardas;
    cout<<"iveskite pavarde"<<endl;
    cin>>pavarde;
    cout<<"ar zinote namu darbu iverinimu skaiciu?"<<endl<<"1 - taip, zinau  2 - ne, dar nezinau"<<endl;
    cin>>t;
    if(t==1)
    {
        cout<<"iveskite iverciu skaiciu"<<endl;
        cin>>n;
        cout<<"kaip vertinsime?"<<endl<<"1 - vidurkis   2 - mediana  3 - random"<<endl;
        cin>>k;
        if(k==1)
        {
            cout<<"iveskite pazymius"<<endl;
            for(int i=0; i<n; i++)
            {
                cin>>balai[i];
                vidurkis=balai[i]+vidurkis;
            }
        }
        if(k==2)
        {
            for(int i=0; i<n; i++)
            {
                if(n/2==i)
                    medi=balai[i];
            }
        }
        if(k==3)
        {
            std::random_device rd;
            std::mt19937 mt(rd());
            std::uniform_real_distribution<double> dist(1.0, 10.0);

            for (int i=0; i<n; ++i)
                cout << dist(mt) << "\n";
        }
        cout<<"iveskite ezamino rezultata"<<endl;
        cin>>egzaminas;
        galutinis=0.4*(vidurkis/n)+0.6*egzaminas;
        cout<<vardas<<"  "<<pavarde<<"  "<<endl;
        for(int i=0; i<n; i++)
        {
            cout<<balai[i]<<"  ";
        }

        cout<<endl<<egzaminas<<"  "<<setprecision(3)<<galutinis;
        return 0;
    }
    if(t==2)
    {
        cout<<"veskite pazymius, kai noresite baigti, ivedus pazymi, spauskite 1"<<endl;
        int o=0;
        int i=0;
        while(o!=1)
        {
            cout<<"iveskite skaiciu: ";
            cin>>balai[i];
            cout<<endl<<"ar uzteks skaiciu?"<<endl;
            cin>>u;


            vidurkis=balai[i]+vidurkis;
            i++;
            if(u==1)
            {
                o=1;
            }
        }
        cout<<"kaip vertinsime?"<<endl<<"1 - vidurkis   2 - mediana"<<endl;
        cin>>k;
        if(k==1)
        {
            for(int j=0; j<i; j++)
            {
                vidurkis=balai[i]+vidurkis;
            }
        }
        if(k==2)
        {
            for(int j=0; j<i; j++)
            {
                if(n/2==i)
                    medi=balai[i];
            }
        }
        cout<<"iveskite ezamino rezultata"<<endl;
        cin>>egzaminas;
        galutinis=0.4*(vidurkis/n)+0.6*egzaminas;
        cout<<vardas<<"  "<<pavarde<<"  "<<endl;
        for(int j=0; j<i; j++)
        {
            cout<<balai[i]<<"  ";
        }

        cout<<endl<<egzaminas<<"  "<<setprecision(3)<<galutinis;
        return 0;

    }
}




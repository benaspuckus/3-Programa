#include <iostream>
#include <iomanip>
#include<cmath>
#include <Windows.h>
#include <fstream>
#include <algorithm>
#include <random>
using std::cin;
using std::cout;
using std::string;
using std::ifstream;
using std::ofstream;
using std::setprecision;
using std::swap;
using std::endl;
using std::setw;
using std::random_device;
using std::mt19937;
using std::uniform_real_distribution;
struct studentas {string vard; string pav; int paz[50]; int egz; double vid; double med;};
int main()
{   studentas a[50];
    ifstream fd("duom.txt");
    ofstream fr("rez.txt");
    string vardas;
    string pavarde;
    int n;
    int k;
    int u;
    int f;
    int medi=0;

    double balai[50];
    double vidurkis=0;
    double galutinis;
    double egzaminas;
    int t;
    cout<<"ar ivesite duomenis, ar skaitysime is failo? 1 - ivesiu 2 - is failo"<<endl;
    cin>>t;
    if(t==2)
    {
        cout<<"kiek pazymiu turejo?"<<endl;
        cin>>n;
        int o=0;
        while(!fd.eof())
        {
            fd>>a[o].vard>>a[o].pav;
            cout<<a[o].vard<<"  ";

            for(int i=0;i<n;i++)
            {
                fd>>a[o].paz[i];
                a[o].vid=a[o].paz[i]+a[o].vid;
                if(n/2==i)
                    a[o].med=a[o].paz[i];
            }
            fd>>a[o].egz;
            a[o].vid=a[o].vid/n;

        o++;
        }
       for(int i=0;i<n;i++)
            for(int j=i+1;j<n-2;j++)
            {if(a[i].vard>a[j].vard)
            swap(a[i],a[j]);}
        fr<<"Vardas   Pavarde   vidurkis   mediana"<<endl;
        for(int i=0;i<o;i++)
        {   vardas=a[i].vard;
            pavarde=a[i].pav;
            vardas.resize(9);
            pavarde.resize(9);
            fr<<vardas<<"  "<<pavarde<<"  "<<a[i].vid<<"         "<<a[i].med<<endl;
        }
        fr.close();
        fd.close();
    }
    if(t==1)
    {cout<<"iveskite varda"<<endl;
    cin>>vardas;
    cout<<"iveskite pavarde"<<endl;
    cin>>pavarde;
    cout<<"ar zinote namu darbu iverinimu skaiciu?"<<endl<<"1 - taip, zinau  2 - ne, dar nezinau"<<endl;
    cin>>t;
    if(t==1) //jeigu zinome pazymiu skaiciu
    {
        cout<<"iveskite iverciu skaiciu"<<endl;
        cin>>n;
        cout<<"kaip vertinsime?"<<endl<<"1 - vidurkis   2 - mediana  3 - random"<<endl;
        cin>>k;
        //double rd;
        if(k==1) // jeigu skaicuojame pagal vidurki
        {
            cout<<"iveskite "<<n<<" pazymius"<<endl;
            for(int i=0; i<n; i++) //iveda pazymius i masyva
            {
                cin>>balai[i];
                vidurkis=balai[i]+vidurkis;
            }
        }
        if(k==2) //jeigu skaiciuosime pagal mediana
        {
            cout<<"iveskite "<<n<<" pazymius"<<endl;
            for(int i=0; i<n; i++) //iveda pazymius
            {
                cin>>balai[i];
                vidurkis=balai[i]+vidurkis;
            }
            for(int i=0; i<n; i++) // iesko medianos
            {
                if(n/2==i)
                    medi=balai[i];
            }
        }
        if(k==3) //random generuoja skaicius. Tiek, kiek yra n
        {
            std::random_device rd;
            std::mt19937 mt(rd());
            std::uniform_real_distribution<double> dist(1.0, 10.0);

            for (int i=0; i<=n; ++i)
                balai[i]=dist(mt);
        }
        cout<<"iveskite egzamino rezultata"<<endl;
        cin>>egzaminas;
        galutinis=0.4*(vidurkis/n)+0.6*egzaminas; //paskaiciuojamas galutinis pazimys
        cout<<vardas<<"  "<<pavarde<<"  "<<endl;
        cout<<"pazymiai:"<<endl;
        for(int i=0; i<n; i++) // isveda turimus pazymius
        {
            cout<<balai[i]<<"  ";
        }

        cout<<endl<<"egzamino rezultatas: "<<egzaminas<<"  galutinis: "<<setprecision(3)<<galutinis;
        return 0;
    }
    if(t==2) //jeigu skaiciu nezinome
    {
        cout<<"veskite pazymius, kai noresite baigti, iveskite 0"<<endl;
        int o=0;
        int i=0;
        while(o!=1) //labai idomus ciklas. Kadangi protingai nieko nesugalvojau, pazymiai ivedami tol, kol ivesime 0, o tai reiskia, akad pazymiai baigti vesti.
        {
            cout<<"iveskite skaiciu: ";
            cin>>balai[i];
            vidurkis=balai[i]+vidurkis;

            if(balai[i]==0) // jeigu ivedame nuli
            {
                o=1;
                i--;
            }
            i++;
        }
        cout<<"kaip vertinsime?"<<endl<<"1 - vidurkis   2 - mediana"<<endl; //tas oats, vertinsime pagal vidurki arba mediana
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
                vidurkis=balai[i]+vidurkis;
            }
            for(int j=0; j<i; j++)
            {
                if(n/2==i)
                    medi=balai[i];
            }
        }
        cout<<"iveskite egzamino rezultata"<<endl;
        cin>>egzaminas;
        galutinis=0.4*(vidurkis/n)+0.6*egzaminas;
        cout<<vardas<<"  "<<pavarde<<"  "<<endl<<"pazymiai:"<<endl;

        for(int j=0; j<i; j++)
        {
            cout<<balai[j]<<"  ";
        }
        cout<<endl<<"egzamino rezultatas: "<<egzaminas<<"  galutinis: "<<setprecision(3)<<galutinis;
        return 0;

    }
}
}




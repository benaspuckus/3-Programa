#include <iostream>
#include <iomanip>
#include<cmath>
#include <Windows.h>
#include <fstream>
#include <algorithm>
#include "studentai.h"
#include <sstream>
#include <vector>
#include <random>
using std::cin;
using std::cout;
using std::string;
using std::ifstream;
using std::ofstream;
using std::setprecision;
using std::swap;
using std::endl;
using std::vector;
using std::setw;
using std::random_device;
using std::mt19937;
using std::uniform_real_distribution;
int main()
{
    studentas a[50];
    ifstream fd("duom.txt");
    ofstream fr("rez.txt");
    string vardas;
    string pavarde;
    int n;
    int k;
    int u;
    int x;
    int f;
    int medi=0;
    vector <int> v;

    double balai[50];
    double vidurkis=0;
    double galutinis;
    double egzaminas;
    int t;
    int l;
    cout<<"ar ivesite duomenis, ar skaitysime is failo? 1 - ivesiu 2 - is failo"<<endl;
    cin>>l;
    if(l==2) //jeigu skaitome is failo
    {
        int i=0;
        int o=0;
        double g;
        int f=1;
        string vidur;
        string line;
        while (std::getline(fd, line)) //skaito po eilute ir iveda duomenis
        {


            std::istringstream iss(line);
            iss>>a[o].vard;
            iss>>a[o].pav;
            while (iss >> g) //ivedineja, kol yra pazymiu
            {
                a[o].paz[i]=g;
                a[o].vid=a[o].paz[i]+a[o].vid;
                i++;
            }
            a[o].egz=a[o].paz[i];
            a[o].vid=a[o].vid/(i+1);
            for(int j=0;j<i;j++) //iesko medianos
            {
                if(i/2==j && i%10!=0)
                    a[o].med=a[o].paz[j-1];
                else
                    a[i].med=(a[o].paz[j]+a[o].paz[j+1])/2;
            }
            o++;
            i=0;
            f=1;


        }
        for(int i=0; i<n; i++)  //rikiuoja gautus rezultatus pagal VARDA
            for(int j=i+1; j<n-2; j++)
            {
                if(a[i].vard>a[j].vard)
                    swap(a[i],a[j]);
            }
        fr<<"Vardas     Pavarde       vidurkis   mediana"<<endl;
        for(int i=0; i<o; i++)
        {
            vardas=a[i].vard;
            pavarde=a[i].pav;

            vardas.resize(9); //resize'inu string'us, kad galeciau graziai isdelioti rezultatu faile
            pavarde.resize(9);
            fr<<vardas<<"  "<<pavarde<<"  "<<setprecision(2)<<setw(8)<<a[i].vid<<"         "<<a[i].med<<endl;
        }
        fr.close();
        fd.close();
    }
    if(l==1)
    {
        cout<<"iveskite varda"<<endl;
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
                    cin>>x;
                    if(x>0&&x<=10)
                    {vidurkis=x+vidurkis;
                    v.push_back(x);}
                    else
                    {
                        i--;
                        cout<<"iveskite teisinga skaiciu"<<endl;
                    }
                }
            }
            if(k==2) //jeigu skaiciuosime pagal mediana
            {
                cout<<"iveskite "<<n<<" pazymius"<<endl;
                for(int i=0; i<n; i++) //iveda pazymius
                {
                    cin>>x;
                    if(x>0&&x<=10)
                    {vidurkis=balai[i]+vidurkis;
                    v.push_back(x);}
                    else
                    {
                        i--;
                        cout<<"iveskite teisinga skaiciu"<<endl;
                    }
                }
                for(int i=0; i<n; i++) // iesko medianos
                {
                    if(i/2==i && i%10!=0)
                    medi=v[i];
                else
                    medi=(v[i]+v[i+1])/2;
                }
            }
            if(k==3) //random generuoja skaicius. Tiek, kiek yra n
            {
                std::random_device rd;
                std::mt19937 mt(rd());
                std::uniform_real_distribution<double> dist(1.0, 10.0);

                for (int i=0; i<=n; ++i)
                    v[i]=dist(mt);
            }
            cout<<"iveskite egzamino rezultata"<<endl;
            cin>>egzaminas;
            galutinis=0.4*(vidurkis/n)+0.6*egzaminas; //paskaiciuojamas galutinis pazimys
            cout<<vardas<<"  "<<pavarde<<"  "<<endl;
            cout<<"pazymiai:"<<endl;
            for(int i=0; i<n; i++) // isveda turimus pazymius
            {
                cout<<v[i]<<"  ";
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
                cin>>x;
                if(x>=0&&x<=10)
                    {vidurkis=x+vidurkis;
                    v.push_back(x);}
                    else
                    {
                        i--;
                        cout<<"iveskite teisinga skaiciu"<<endl;
                    }

                if(x==0) // jeigu ivedame nuli
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
                    vidurkis=v[j]+vidurkis;
                }
            }
            if(k==2)
            {
                for(int j=0; j<i; j++)
                {
                    vidurkis=v[j]+vidurkis;
                }
                for(int j=0; j<i; j++)
                {
                           if(i/2==j && i%10!=0)
                    vidurkis=v[j];
                else
                    vidurkis=(v[j]+v[j+1])/2;
                }
            }
            cout<<"iveskite egzamino rezultata"<<endl;
            cin>>egzaminas;
            if(k==1) galutinis=0.4*(vidurkis/i)+0.6*egzaminas;
            if(k==2) galutinis=0.4*(vidurkis)+0.6*egzaminas;
            cout<<vardas<<"  "<<pavarde<<"  "<<endl<<"pazymiai:"<<endl;

            for(int j=0; j<i; j++)
            {
                cout<<v[j]<<"  ";
            }
            cout<<endl<<" egzamino rezultatas: "<<egzaminas<<"  galutinis: "<<setprecision(3)<<galutinis;
            return 0;

        }
    }
}




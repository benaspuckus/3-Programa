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
using std::sort;
using std::endl;
using std::vector;
using std::setw;
using std::random_device;
using std::mt19937;
using std::uniform_real_distribution;
int main()
{
    vector<Studentas> a;
    vector<Studentas> b;
    vector<Studentas> c;
    ifstream fd("duom.txt");
    ofstream fr("rez.txt");
    int n;
    int k;
    int u;
    int x;
    int f;
    int kof1=0;
    int kof2=0;
    int medi=0;
    //vector <int> v;

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
        string line;
        while (std::getline(fd, line)) //skaito po eilute ir iveda duomenis
        {
            a.push_back(Studentas());

            std::istringstream iss(line);
            iss>>a[o].vard;
            iss>>a[o].pav;
            while (iss >> g) //ivedineja, kol yra pazymiu
            {
                a[o].v.push_back(g);
                a[o].vid=a[o].v[i]+a[o].vid;
                i++;
            }
            a[o].egz=a[o].v[i];
            a[o].v.pop_back();
            a[o].vid=a[o].vid/(i);
            sort(a[o].v.begin(),a[o].v.end());
            for(int j=0; j<i; j++) //iesko medianos
            {
                if(i/2==j && i%10!=0)
                    a[o].med=a[o].v[j-1];
                if(i/2==j && i%10==0)
                    a[o].med=(a[o].v[j]+a[o].v[j+1])/2;
            }
            if(a[o].vid<6) //iraso i atskirus vektorius zmones, kurie prileisi ir kurie neprileisti prie egzamino
                {b.push_back(Studentas());
                b[kof1]=a[o];
                kof1++;
                }
            if(a[o].vid>=6)
            {
                c.push_back(Studentas());
                c[kof2]=a[o];
                kof2++;
            }
            o++;
            i=0;


        }
        for(int j=0; j<kof1; j++)  //rikiuoja gautus rezultatus pagal VARDA
            for(int r=j+1; r<kof1-1; r++)
            {
                if(b[j].vard>b[r].vard)
                    swap(b[j],b[r]);
            }
        for(int j=0; j<kof2; j++)  //rikiuoja gautus rezultatus pagal VARDA
            for(int r=j+1; r<kof2-1; r++)
            {
                if(c[j].vard>c[r].vard)
                    swap(c[j],c[r]);
            }
        fr<<"Vardas     Pavarde       vidurkis   mediana"<<endl;
        fr<<"looseriai:"<<endl;
        for(int i=0; i<kof1; i++)
        {

            b[i].vard.resize(9); //resize'inu string'us, kad galeciau graziai isdelioti rezultatu faile
            b[i].pav.resize(9);
            fr<<b[i].vard<<"  "<<b[i].pav<<"  "<<setprecision(2)<<setw(8)<<b[i].vid<<"         "<<b[i].med<<endl;
        }
        fr<<"mandruoliai:"<<endl;
        for(int i=0; i<kof2; i++)
        {

            c[i].vard.resize(9); //resize'inu string'us, kad galeciau graziai isdelioti rezultatu faile
            c[i].pav.resize(9);
            fr<<c[i].vard<<"  "<<c[i].pav<<"  "<<setprecision(2)<<setw(8)<<c[i].vid<<"         "<<c[i].med<<endl;
        }
        fr.close();
        fd.close();
    }
    if(l==1)
    {
        cout<<"iveskite varda"<<endl;
        cin>>a[0].vard;
        cout<<"iveskite pavarde"<<endl;
        cin>>a[0].pav;
        cout<<"ar zinote namu darbu iverinimu skaiciu?"<<endl<<"1 - taip, zinau  2 - ne, dar nezinau"<<endl;
        cin>>t;
        if(t==1) //jeigu zinome pazymiu skaiciu
        {
            cout<<"iveskite iverciu skaiciu"<<endl;
            cin>>n;
            cout<<"kaip ivesime?"<<endl<<"1 - patys 2 - random"<<endl;
            cin>>k;
            //double rd;
            if(k==1) // jeigu skaicuojame pagal vidurki
            {
                cout<<"iveskite "<<n<<" pazymius"<<endl;
                for(int i=0; i<n; i++) //iveda pazymius i masyva
                {
                    cin>>x;
                    if(x>0&&x<=10)
                    {
                        a[0].vid=x+a[0].vid;
                        a[0].v.push_back(x);
                    }
                    else
                    {
                        i--;
                        cout<<"iveskite teisinga skaiciu"<<endl;
                    }
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
                        a[0].v.push_back(x);
                        a[0].vid=x+a[0].vid;
                    }
            }
            cout<<"skaiciuosime pagal 1 - vidurkis 2 - mediana"<<endl;
            cin>>x;
            if(x==2)
            {
                for(int i=0; i<n; i++) // iesko medianos
                {
                    if(i/2==i && i%10!=0)
                        a[0].vid=a[0].v[i];
                    else
                        a[0].vid=(a[0].v[i]+a[0].v[i+1])/2;
                }
            }
int o=1;
            cout<<"iveskite egzamino rezultata"<<endl;
            while(o!=0)
            {

            cin>>a[0].egz;
            if(a[0].egz<=10)
            {
            if(x==2)
                galutinis=0.4*(a[0].vid)+0.6*a[0].egz;
            else
                galutinis=0.4*(a[0].vid/n)+0.6*a[0].egz;
                o=0;
            }
            else
                cout<<"iveskite teisinga skaiciu"<<endl;
            }
            if(k==1)
                galutinis=0.4*(a[0].vid/n)+0.6*a[0].egz;
            if(k==2)
                galutinis=0.4*(a[0].vid)+0.6*a[0].egz;//paskaiciuojamas galutinis pazimys
            if(k==3)
                galutinis=0.4*(a[0].vid/n)+0.6*a[0].egz;
            cout<<a[0].vard<<"  "<<a[0].pav<<"  "<<endl;
            cout<<"pazymiai:"<<endl;
            for(int i=0; i<n; i++) // isveda turimus pazymius
            {
                cout<<a[0].v[i]<<"  ";
            }

            cout<<endl<<"egzamino rezultatas: "<<a[0].egz<<"  galutinis: "<<setprecision(3)<<galutinis;
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
                {
                    a[0].vid=x+a[0].vid;
                    a[0].v.push_back(x);
                }
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
                   a[0].vid=a[0].v[j]+a[0].vid;
                }
            }
            if(k==2)
            {
                for(int j=0; j<i; j++)
                {
                    a[0].vid=a[0].v[j]+a[0].vid;
                }
                for(int j=0; j<i; j++)
                {
                    if(i/2==j && i%10!=0)
                        a[0].vid=a[0].v[j];
                    else
                        a[0].vid=(a[0].v[j]+a[0].v[j+1])/2;
                }
            }
            cout<<"iveskite egzamino rezultata"<<endl;
            while(o!=0)
            {

            cin>>a[0].egz;
            if(a[0].egz<=10)
            {
            if(k==1)
                galutinis=0.4*(a[0].vid/i)+0.6*a[0].egz;
            if(k==2)
                galutinis=0.4*(a[0].vid)+0.6*a[0].egz;
                o=0;
            }
            else
                cout<<"iveskite teisinga skaiciu"<<endl;
            }


            cout<<a[0].vard<<"  "<<a[0].pav<<"  "<<endl<<"pazymiai:"<<endl;

            for(int j=0; j<i; j++)
            {
                cout<<a[0].v[j]<<"  ";
            }
            cout<<endl<<" egzamino rezultatas: "<<a[0].egz<<"  galutinis: "<<setprecision(3)<<galutinis;
            return 0;

        }
    }
}




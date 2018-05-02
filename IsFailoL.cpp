#include <iostream>
#include <iomanip>
#include <list>
#include<cmath>
#include <Windows.h>
#include "IsFailoL.h"
#include <fstream>
#include <algorithm>
#include "Studentas.h"
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
using std::list;
using std::endl;
using std::vector;
using std::setw;
using std::random_device;
using std::mt19937;
using std::uniform_real_distribution;
bool RikiavimasL(const Studentas &a, const Studentas &b)
{
    return a.vard < b.vard;
}
bool RibaL(const Studentas &a)
{
    return a.vid < 6.0;
}
void IsFailoL(int n, int p)
{
    list<Studentas> a;
    list<Studentas> b;
    list<Studentas> c;
    int kof1=0;
    int kof2=0;
    int i=0;
    int y;
    ifstream fd;
    if(n==10)
        fd.open("10.txt");
    if(n==100)
        fd.open("100.txt");
    if(n==1000)
        fd.open("1000.txt");
    if(n==10000)
        fd.open("10000.txt");
    if(n==100000)
        fd.open("100000.txt");
    ofstream fr;
    if(n==10)
        fr.open("10rez.txt");
    if(n==100)
        fr.open("100rez.txt");
    if(n==1000)
        fr.open("1000rez.txt");
    if(n==10000)
        fr.open("10000rez.txt");
    if(n==100000)
        fr.open("100000rez.txt");
    int o=0;
    double g;
    string line;
    while (std::getline(fd, line)) //skaito po eilute ir iveda duomenis
    {   Studentas temp;
        //a.push_back(Studentas());

        std::istringstream iss(line);
        iss>>temp.vard;
        iss>>temp.pav;
        while (iss >> g) //ivedineja, kol yra pazymiu
        {
            temp.v.push_back(g);
            temp.vid=temp.v[i]+temp.vid;
            i++;
        }
        temp.egz=temp.v[i];
        temp.v.pop_back();
        temp.vid=temp.vid/(i);
        for(int j=0; j<i; j++) //iesko medianos
        {
            if(i/2==j && i%10!=0)
                temp.med=temp.v[j-1];
            if(i/2==j && i%10==0)
                temp.med=(temp.v[j]+temp.v[j+1])/2;
        }
        a.push_back(temp);
        if(temp.vid<6) //iraso i atskirus vektorius zmones, kurie prileisi ir kurie neprileisti prie egzamino
        {
            /*b.push_back(Studentas());
            b[kof1]=a[o];
            kof1++;*/
            b.push_back(temp);

        }
        if(p==2)
        {
          if(temp.vid>=6) //iraso i atskirus vektorius zmones, kurie prileisi ir kurie neprileisti prie egzamino
        {
            /*c.push_back(Studentas());
            c[kof2]=a[o];
            kof2++;*/
            c.push_back(temp);
        }
        }

       // a.erase(a.begin(), a.begin() + 1);
        //a.erase(std::remove_if(a.begin(), a.end(), Riba), a.end());
        //a.clear();
        o++;
        i=0;


    }
    if(p==1) {a.erase(std::remove_if(a.begin(), a.end(), RibaL), a.end()); a.sort(RikiavimasL);}
    //sort(b.begin(),b.end(),RikiavimasL);
    b.sort(RikiavimasL);
    if(p==2)
       //sort(c.begin(),c.end(),RikiavimasL);
       b.sort(RikiavimasL);
    fr<<"Vardas        Pavarde           vidurkis   mediana"<<endl;
    fr<<"looseriai:"<<endl;
    for(auto i:b)
    {

        i.vard.resize(12); //resize'inu string'us, kad galeciau graziai isdelioti rezultatu faile
        i.pav.resize(13);
        fr<<i.vard<<"  "<<i.pav<<"  "<<setprecision(2)<<setw(8)<<i.vid<<"         "<<i.med<<endl;
    }
    fr<<"mandruoliai:"<<endl;
    if(p==1)
    {for(auto i:a)
    {

        i.vard.resize(12); //resize'inu string'us, kad galeciau graziai isdelioti rezultatu faile
        i.pav.resize(13);
        fr<<i.vard<<"  "<<i.pav<<"  "<<setprecision(2)<<setw(8)<<i.vid<<"         "<<i.med<<endl;
    }}
    if(p==2)
    {
       for(auto i:c)
    {

        i.vard.resize(12); //resize'inu string'us, kad galeciau graziai isdelioti rezultatu faile
        i.pav.resize(13);
        fr<<i.vard<<"  "<<i.pav<<"  "<<setprecision(2)<<setw(8)<<i.vid<<"         "<<i.med<<endl;
    }
    }
    fr.close();
    fd.close();
    fr.clear();
    fd.clear();
    a.clear();
    b.clear();
    c.clear();
}

#include <iostream>
#include <iomanip>
#include<cmath>
#include <Windows.h>
#include "IsFailo.h"
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
bool Rikiavimas(const Studentas &a, const Studentas &b)
{
    return a.vard < b.vard;
}
bool Riba(const Studentas &a)
{
    return a.vid < 6.0;
}
void IsFailo(vector <Studentas> &a,vector <Studentas> &b,vector <Studentas> &c,int n)
{
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
        {
            b.push_back(Studentas());
            b[kof1]=a[o];
            kof1++;
        }

       // a.erase(a.begin(), a.begin() + 1);
        //a.erase(std::remove_if(a.begin(), a.end(), Riba), a.end());
        //a.clear();
        o++;
        i=0;


    }
    a.erase(std::remove_if(a.begin(), a.end(), Riba), a.end());
    sort(b.begin(),b.end(),Rikiavimas);
    sort(a.begin(),a.end(),Rikiavimas);
    fr<<"Vardas        Pavarde           vidurkis   mediana"<<endl;
    fr<<"looseriai:"<<endl;
    for(int i=0; i<kof1; i++)
    {

        b[i].vard.resize(12); //resize'inu string'us, kad galeciau graziai isdelioti rezultatu faile
        b[i].pav.resize(13);
        fr<<b[i].vard<<"  "<<b[i].pav<<"  "<<setprecision(2)<<setw(8)<<b[i].vid<<"         "<<b[i].med<<endl;
    }
    fr<<"mandruoliai:"<<endl;
    for(int i=0; i< a.size(); i++)
    {

        a[i].vard.resize(12); //resize'inu string'us, kad galeciau graziai isdelioti rezultatu faile
        a[i].pav.resize(13);
        fr<<a[i].vard<<"  "<<a[i].pav<<"  "<<setprecision(2)<<setw(8)<<a[i].vid<<"         "<<a[i].med<<endl;
    }
    fr.close();
    fd.close();
    fr.clear();
    fd.clear();
    a.clear();
    b.clear();
    c.clear();
}

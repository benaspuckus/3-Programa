//
// Created by MD on 2018-05-21.
//

#include <algorithm>
#include <iostream>
#include <fstream>
#include "Studentas.h"
void Studentas::setVardas(string v)
{this->vardas = v;}
void Studentas::setPavarde(string p)
{this->pavarde = p;}
void Studentas::setEgzaminas(double e)
{this->egzaminas = e;}
void Studentas::fillVidurkis(double v)
{
    double skaicius = this->vidurkis;
    this->vidurkis = v+skaicius;
}
void Studentas::setVidurkis(double v)
{
    this->vidurkis = v;
}
void Studentas::setMediana(double m)
{this->mediana = m;}
void Studentas::setPazymiai(int x)
{pazymiai.push_back(x);}
void Studentas::sortPazymiai() {std::sort(pazymiai.begin(),pazymiai.end());}

int Studentas::getSize(){return pazymiai.size();}

bool Studentas::operator< (const Studentas& b)
{
    return vardas < b.vardas;
}

bool Studentas::operator> (const Studentas& b)
{
    return vardas > b.vardas;
}
/*std::ofstream& operator<<(std::ofstream& fr, const Studentas& a)
{
    fr<<a.vardas<<"   "<<a.pavarde<<"  "<<a.vidurkis<<std::endl;
    return fr;
}*/

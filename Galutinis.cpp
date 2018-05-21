#include "Studentas.h"
#include "Galutinis.h"
#include <iomanip>
#include<cmath>
#include <deque>
#include <Windows.h>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <list>
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
using std::deque;
using std::list;
using std::sort;
using std::endl;
using std::vector;
using std::setw;
using std::random_device;
using std::mt19937;
using std::uniform_real_distribution;
void Galutinis(int &i, int o,vector<Studentas> &a, int k, int n)
{
    if(a[o].getEgzaminas()<=10)
                {
                    if(k==2)
                        a[o].setGalutinis(0.4*(a[o].getVidurkis())+0.6*a[o].getEgzaminas())
                    if(k==1)
                        a[o].gal=0.4*(a[o].getVidurkis()/n)+0.6*a[o].getEgzaminas();
                    i=0;
                }
                else
                    cout<<"iveskite teisinga skaiciu"<<endl;
}

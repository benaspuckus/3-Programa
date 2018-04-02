#include "studentai.h"
#include "Galutinis.h"
#include <iomanip>
#include<cmath>
#include <deque>
#include <Windows.h>
#include <fstream>
#include <algorithm>
#include <iostream>
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
using std::sort;
using std::endl;
using std::vector;
using std::setw;
using std::random_device;
using std::mt19937;
using std::uniform_real_distribution;
void Galutinis(int &i, int o,deque<Studentas> &a, int k, int n)
{
    if(a[o].egz<=10)
                {
                    if(k==2)
                        a[o].gal=0.4*(a[o].vid)+0.6*a[o].egz;
                    if(k==1)
                        a[o].gal=0.4*(a[o].vid/n)+0.6*a[o].egz;
                    i=0;
                }
                else
                    cout<<"iveskite teisinga skaiciu"<<endl;
}

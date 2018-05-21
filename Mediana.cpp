#include <iostream>
#include <iomanip>
#include<cmath>
#include <Windows.h>
#include "Mediana.h"
#include <deque>
#include <fstream>
#include <algorithm>
#include "Studentas.h"
#include <sstream>
#include <vector>
#include <list>
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
void Mediana(int n,int o,vector<Studentas> &a)
{
  for(int i=0; i<n; i++)
                {
                    if(i/2==i && i%10!=0)
                        a[o].setVidurkis(a[o].v[i]);
                    else
                        a[o].setVidurkis((a[o].v[i]+a[o].v[i+1])/2);
                }
}

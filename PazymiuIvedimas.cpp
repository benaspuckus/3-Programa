#include "studentai.h"
#include "PazymiuIvedimas.h"
#include <iomanip>
#include<cmath>
#include <Windows.h>
#include <deque>
#include <list>
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
using std::sort;
using std::endl;
using std::deque;
using std::list;
using std::vector;
using std::setw;
using std::random_device;
using std::mt19937;
using std::uniform_real_distribution;
void PazymiuIvedimas(int x,list<Studentas> &a, int &i)
{


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

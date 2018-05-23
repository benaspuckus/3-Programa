//
// Created by MD on 2018-05-21.
//

#include "Generavimas.h"
#include <iostream>
#include <time.h>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
using std::cout;
using std::endl;
using std::ofstream;
void Generavimas(int n)
{
    int random;


    ofstream fr;
    if(n==10)
        fr.open("10.txt");
    if(n==100)
        fr.open("100.txt");
    if(n==1000)
        fr.open("1000.txt");
    if(n==10000)
        fr.open("10000.txt");
    if(n==100000)
        fr.open("100000.txt");
    //srand (time(NULL));
    for(int i=1; i<=n; i++)
    {
        fr<<"vardas"<<i<<" "<<"pavarde"<<i<<" ";
        for(int j=0; j<7; j++)
        {
            random=rand() % 10 + 1;
            fr<<random<<" ";
        }
        fr<<endl;
    }
    fr.close();
    fr.clear();

}

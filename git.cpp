#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;
using namespace std;
int main()
{
    string labas="Sveikas, ";
    string vardas;
    cout<<"iveskite varda"<<endl;
    cin>>vardas;
    int ilgis=vardas.length();
    for(int i=0; i<ilgis+13; i++)
        cout<<"*";
    cout<<endl;
    cout<<"* ";
    for(int i=0; i<ilgis+9; i++)
        cout<<" ";
    cout<<" *"<<endl;
    cout<<"* "<<labas<<vardas<<" *";
    cout<<endl;
    cout<<"* ";
    for(int i=0; i<ilgis+9; i++)
        cout<<" ";
    cout<<" *"<<endl;
    for(int i=0; i<ilgis+13; i++)
        cout<<"*";
    return 0;

}


#ifndef STUDENTAS_H_INCLUDED
#define STUDENTAS_H_INCLUDED
using std::string;
using std::vector;
using std::deque;

class Studentas
{   public:
    string vard;
    string pav;
    vector<int> v;
    double egz;
    double vid;
    double med;
    double gal;
};
    void Galutinis(int &i, int o,vector<Studentas> &a, int k, int n);
    void IvestiPaciamZinomus(int n,vector<Studentas> &a);
    void Mediana(int n,int o,vector<Studentas> &a);
    void PazymiuIvedimas(int x,vector<Studentas> &a, int &i);
    void IsFailo(int n, int p);
    void IsFailoD(int n, int p);
    void IsFailoL(int n, int p);
#endif // STUDENTAS_H_INCLUDED

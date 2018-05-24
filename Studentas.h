//
// Created by MD on 2018-05-21.
//

#ifndef TIKRAI_3_PROGRAMA_STUDENTAS_H
#define TIKRAI_3_PROGRAMA_STUDENTAS_H
#include <vector>
#include <string>
using std::vector;
using std::string;
class Studentas
{ public:
    int getSize();
    void setVardas(string v);
    inline string getVardas() const {return vardas;}
    void setPavarde(string p);
    inline string getPavarde() const {return pavarde;}
    void setEgzaminas(double e);
    inline double getEgzaminas() const {return egzaminas;}
    void setVidurkis(double v);
    inline double getVidurkis() const {return vidurkis;}
    void setMediana(double m);
    inline double getMediana() const {return mediana;}
    void setPazymiai(int x);
    inline string Vardas() const {return vardas;}
    inline string Pavarde() const {return pavarde;}
    void sortPazymiai();
    inline vector<int> Pazymiai() const {return pazymiai; }
    int getPazymiai(int i) {return pazymiai[i];}
    void fillVidurkis(double v);
    /*bool Rikiavimas(const Studentas &a, const Studentas &b)
    {
        return a.Vardas() < b.Vardas();
    }*/

    bool operator< (const Studentas& b);
    bool operator> (const Studentas& b);
    //friend std::ostream& operator<<(std::ostream&, const Studentas&);
private:
    string vardas;
    string pavarde;
    double egzaminas;
    double vidurkis;
    double mediana;
    double galutinis;
    vector<int> pazymiai;
};


#endif //TIKRAI_3_PROGRAMA_STUDENTAS_H

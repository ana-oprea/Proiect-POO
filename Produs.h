#ifndef PRODUS_H
#define PRODUS_H
#include <string>
#include <cstring>
#include <iostream>
#include "TVA.h"
using namespace std;


/// ACEASTA CLASA VA FI O CLASA ABSTRACTA SI O SA O IMPLEMETEZ IN ETAPA 2, VA FI MOSTENITA DE CLASELE : AparatFoto si Drona si celelalte clase de tip produs
// VOI MUTA TOATE ATRIBUTELE COMUNE DIN CLASELE AparatFoto SI Drona IN ACEASTA CLASA SI O VOI MOSTENI IN ETAPA 2

// clasa abstracta
// este mostenita de AparatFoto si Drona
class Produs: public TVA
{
    protected:
        string firma;
        char* model;
        float pret;
        int stoc;
    public:
        Produs();
        Produs(const string firma, char* model);
        Produs(const string firma, const char* model, const float pret, const int stoc);
        Produs(const Produs& produs); // copy constructor
        ~Produs(); // destructor

        // functie virtuala pura
        virtual float calcPretCuTVA() = 0;

        // metode
        void setFirma(string);
        void setModel(char*);
        void setPret(float);
        void setStoc(int);

        string getFirma() const;
        char* getModel() const;
        float getPret() const;
        int getStoc() const;

        friend ostream& operator << (ostream&, const Produs&);
        friend istream& operator >> (istream&, Produs&);
        Produs& operator = (const Produs&);
};

#endif // PRODUS_H

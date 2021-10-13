#ifndef CLIENT_H
#define CLIENT_H
#include <vector>
#include <typeinfo>
#include "Produs.h"
#include "AparatFoto.h"
#include "Drona.h"
using namespace std;

/// ACEASTA CLASA VA FI IMPLEMETATA IN ETAPA 2 (AM NEVOIE DE CLASA PRODUS)

class Client
{
    private:
        string numeClient;
        static int nrClienti;
        const int idClient;
        vector <Produs*> cos; //  HAS A
        float total;
    public:
        Client();
        Client(string);
        ~Client();

        void setNumeClient(string);
        void setTotal(float);
        string getNumeClient();
        float getTotal();
        string getCosElem(int);
        void showCos();
        void addInCos(Produs* );
        int removeFromCos(int);
        int getCosSize();

        friend ostream& operator << (ostream&, const Client&);
        friend istream& operator >> (istream&, Client&);
        Client& operator = (const Client&);
};

#endif // CLIENT_H

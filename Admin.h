#ifndef ADMIN_H
#define ADMIN_H
#include "AparatFoto.h"
#include "Drona.h"
#include <string>
#include <vector>
#include <iostream>

class Admin
{
    private:
       vector <AparatFoto> aparate; // toate aparatele din magazin
       vector <Drona> drone;    // toate dronele din magazin
       float vanzari;

       const string numeMagazin = "Echipamente Foto";
    public:
        // CONSTRUCTORS SI DESTRUCTOR
        Admin();
        ~Admin();

        // SETTERS
        void setAparatFoto();
        void setDrona();
        void setTotal(float);

        // GETTERS
        void getAparateFoto();
        void getDrone();
        const string getNumeMagazin();
        int getAparateSize();
        int getDroneSize();
        float getTotal();

        // METODE
        void addAparatFoto(AparatFoto);
        AparatFoto getAparat(int);
        void deleteAparatFoto(int);
        void addDrona(Drona);
        void deleteDrona(int);
        void showProduseMagazin();
        void addToTotal(float);

        // NU AM SUPRAINCARCARI
};

#endif // ADMIN_H

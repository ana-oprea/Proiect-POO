#ifndef DRONA_H
#define DRONA_H
#include <string>
#include <cstring>
#include <iostream>
#include "Produs.h"
using namespace std;

class Drona: public Produs // IS A
{
    private:
        // CARAC TEHNICE
        const int idDrona;
        static int idContor;
        // string firma = "";
        // char* model = NULL;
        double* dimensiuni = NULL;
        // float pret = 0;
        // int stoc = 0;
        int distantaZborMin = 0;
        int distantaZborMax = 0;
        int nrElice = 0;
        bool gps = 0;
        char* greutate = NULL;
        // CAMERA
        string rezolutie = "";
        string rezolutieVideo = "";
        char* diafragma = NULL;

    public:
        // CONSTRUCTORI SI DESTRUCTOR
        Drona();
        Drona(const Drona&);
        Drona(const string, char*);
        Drona (const string, const char*, const float, const int);
        Drona(const string firma, char* model, float pret,
            int stoc, string rezolutie,string rezolutieVideo, char* diafragma,bool gps,
            float* dimensiuni, char* greutate, int distantaZborMin, int distantaZborMax, int nrElice);
        ~Drona();

        // SUPRAINCARCARE FUNCTIA VIRTUALA
        float calcPretCuTVA();
        float calcTaxe();

        // GETTERS
        int getIdDrona() const;
        // string getFirma() const;
        // char* getModel() const;
        // float getPret() const;
        // int getStoc() const;
        double* getDimensiuni() const;
        int getDistantaZborMin() const;
        int getDistantaZborMax() const;
        int getnrElice() const;
        bool getGps() const;
        char* getGreutate() const;
        string getRezolutie() const;
        string getRezolutieVideo() const;
        char* getDiafragma() const;

        // SETTERS
        // void setFirma(string);
        // void setModel(char*);
        // void setPret(float);
        // void setStoc(int);
        void setDimensiuni(double*);
        void setDistantaZborMin(int);
        void setDistantaZborMax(int);
        void setnrElice(int);
        void setGps(bool);
        void setGreutate(char*);
        void setRezolutie(string);
        void setRezolutieVideo(string);
        void setDiafragma(char*);

        // SUPRAINCARCARI
        friend ostream& operator << (ostream&, const Drona&);
        friend istream& operator >> (istream&, Drona&);
        friend Drona operator + (float, Drona);
        Drona operator + (float);
        Drona operator + (Drona);
        Drona operator - (float);
        Drona operator - (Drona);
        Drona& operator = (const Drona&);
        bool operator == (const Drona&);
        bool operator <= (const Drona&);
        bool operator >= (const Drona&);
        explicit operator int();
        const Drona& operator ++ (); // PRE
        const Drona operator ++ (int); // POST
        const Drona& operator -- (); // PRE
        const Drona operator -- (int); // POST
        double operator [] (int);
};


#endif // DRONA_H

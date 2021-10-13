#include "Drona.h"

int Drona::idContor= 200;

// CONSTRUCTORS
Drona::Drona():idDrona(idContor++), Produs()
{
    // this->firma = "";
    // this->model = NULL;
    // this->pret = 0;
    // this->stoc = 0;
    this->dimensiuni = NULL;
    this->distantaZborMin = 0;
    this->distantaZborMax = 0;
    this->nrElice = 0;
    this->gps = 0;
    this->greutate = NULL;
    this->rezolutie = "";
    this->rezolutieVideo = "";
    this->diafragma = NULL;

}

// 2 constructori cu param (cu unul din param static si sau const)
// constructor de copiere


Drona::Drona(const string firma, char* model):idDrona(idContor++), Produs(firma, model){
    // this->firma = firma;
    // this->model = new char[strlen(model)+1];
    // strcpy(this->model, model);
    this->pret = 0;
    this->stoc = 0;
    this->dimensiuni = NULL;
    this->distantaZborMin = 0;
    this->distantaZborMax = 0;
    this->nrElice = 0;
    this->gps = 0;
    this->greutate = NULL;
    this->rezolutie = "";
    this->rezolutieVideo = "";
    this->diafragma = NULL;
}

Drona::Drona(const string firma, const char* model, const float pret, const int stoc):idDrona(idContor++), Produs(firma, model, pret, stoc){
    // this->firma = firma;
    // this->model = new char[strlen(model)+1];
    // strcpy(this->model, model);
    // this->pret = 0;
    // this->stoc = 0;
    this->dimensiuni = NULL;
    this->distantaZborMin = 0;
    this->distantaZborMax = 0;
    this->nrElice = 0;
    this->gps = 0;
    this->greutate = NULL;
    this->rezolutie = "";
    this->rezolutieVideo = "";
    this->diafragma = NULL;
}


Drona::Drona(const string firma, char* model, float pret,
            int stoc, string rezolutie,string rezolutieVideo, char* diafragma,bool gps,
            float* dimensiuni, char* greutate, int distantaZborMin, int distantaZborMax, int nrElice):idDrona(idContor++), Produs(firma, model, pret, stoc){

    // this->firma = firma;
    // this->model = new char[strlen(model)+1];
    // strcpy(this->model, model);
    // this->pret = pret;
    // this->stoc = stoc;
    this->dimensiuni = new double[3];
    for (int i = 0; i < 3; i++)
        this->dimensiuni[i] = dimensiuni[i];
    this->distantaZborMin = distantaZborMin;
    this->distantaZborMax = distantaZborMax;
    this->nrElice = nrElice;
    this->gps = gps;
    this->greutate = new char[strlen(greutate)+1];
    strcpy(this->greutate, greutate);
    this->rezolutie = rezolutie;
    this->rezolutieVideo = rezolutieVideo;
    this->diafragma = new char[strlen(diafragma)+1];
    strcpy(this->diafragma, diafragma);

}


Drona::Drona(const Drona& drona):idDrona(idContor), Produs(drona){
    // this->firma = drona.firma;

    // this->model = new char[strlen(drona.model)+1];
    // strcpy(this->model, drona.model);

    this->dimensiuni = new double[3];
    for (int i = 0; i < 3; i++)
        this->dimensiuni[i] = drona.dimensiuni[i];

    // this->pret = drona.pret;
    // this->stoc = drona.stoc;
    this->distantaZborMin = drona.distantaZborMin;
    this->distantaZborMax = drona.distantaZborMax;
    this->nrElice = drona.nrElice;
    this->gps = drona.gps;
    this->greutate = new char[strlen(drona.greutate)+1];
    strcpy(this->greutate, drona.greutate);
    this->rezolutie = drona.rezolutie;
    this->rezolutieVideo = drona.rezolutieVideo;
    this->diafragma = new char[strlen(drona.diafragma)+1];
    strcpy(this->diafragma, drona.diafragma);

}


// DESTRUCTOR
Drona::~Drona()
{
    if(this->dimensiuni != NULL)
        delete[] this->dimensiuni;
    if(this->greutate != NULL)
        delete[] this->greutate;
    if(this->diafragma != NULL)
        delete[] this->diafragma;
}

// SUPRAINCARCARE FUCNTIE VIRTUALA PURA
float Drona::calcPretCuTVA(){
    return this->pret*0.2 + this->pret; // tva standard din romania
}

float Drona::calcTaxe(){
    return this->pret * 0.2;
}

// GETTERS

int Drona::getIdDrona() const{
    return this->idDrona;
}

// string Drona::getFirma() const{
//     return this->firma;
// }
// char* Drona::getModel() const{
//     return this->model;
// }
// float Drona::getPret()const{
//     return this->pret;
// }
// int Drona::getStoc()const{
//     return this->stoc;
// }
double* Drona::getDimensiuni()const{
    return this->dimensiuni;
}
int Drona::getDistantaZborMin()const{
    return this->distantaZborMin;
}
int Drona::getDistantaZborMax()const{
    return this->distantaZborMax;
}
int Drona::getnrElice()const{
    return this->nrElice;
}
bool Drona::getGps()const{
    return this->gps;
}
char* Drona::getGreutate()const{
    return this->greutate;
}
string Drona::getRezolutie()const{
    return this->rezolutie;
}
string Drona::getRezolutieVideo()const{
    return this->rezolutieVideo;
}
char* Drona::getDiafragma()const{
    return this->diafragma;
}


// SETTERS
// void Drona::setFirma(string firma){
//    this->firma = firma;
// }
// void Drona::setModel(char* model){
//     if(this->model != NULL)
//         delete [] this->model;
//     this->model = new char[strlen(model)+1];
//     strcpy(this->model,model);
// }
// void Drona::setPret(float pret){
//     this->pret = pret;
// }
// void Drona::setStoc(int stoc){
//     this->stoc = stoc;
// }
void Drona::setDimensiuni(double* dimensiuni){
    if (this-> dimensiuni != NULL)
        delete[] dimensiuni;
    this->dimensiuni = new double[3];
    for (int i = 0; i < 3; i++)
        this->dimensiuni[i] = dimensiuni[i];
}
void Drona::setDistantaZborMin(int distantaZborMin){
    this->distantaZborMin = distantaZborMin;
}
void Drona::setDistantaZborMax(int distantaZborMin){
    this->distantaZborMax = distantaZborMax;
}
void Drona::setnrElice(int nrElice){
    this->nrElice = nrElice;
}
void Drona::setGps(bool gps){
    this->gps = gps;
}
void Drona::setGreutate(char* greutate){
    if (this->greutate != NULL)
        delete[] greutate;
    this->greutate = new char[strlen(greutate)+1];
    strcpy(this->greutate, greutate);
}
void Drona::setRezolutie(string rezolutie){
    this->rezolutie = rezolutie;
}
void Drona::setRezolutieVideo(string rezolutieVideo){
    this->rezolutieVideo = rezolutieVideo;
}
void Drona::setDiafragma(char* diafragma){
    if(this->diafragma != NULL)
        delete[] diafragma;
    this->diafragma = new char[strlen(diafragma)+1];
    strcpy(this->diafragma, diafragma);
}

// SUPRAINCARCARI

ostream& operator << (ostream& out, const Drona& drona){
    // if (drona.firma != "")
    //     out << "Firma: " << drona.firma << endl;
    // if (drona.model != NULL)
    //     out << "Model: " << drona.model << endl;
    // if (drona.pret != 0)
    //     out << "Pret: "<< drona.pret << endl;
    // if (drona.stoc != 0)
    //     out << "Stoc: "<< drona.stoc << endl;
    out << (Produs&)drona;
    if(drona.rezolutie != "")
        out << "Rezolutie: "<< drona.rezolutie << endl;
    if(drona.rezolutieVideo != "")
        out << "Rezolutie video: "<< drona.rezolutieVideo << endl;
    if (drona.diafragma != NULL)
        out << "Diafragma: " << drona.diafragma << endl;
    if (drona.distantaZborMin != 0)
        out << "Distanta zbor minim: " << drona.distantaZborMin << endl;
    if (drona.distantaZborMax != 0)
        out << "Distanta zbor maxim: " << drona.distantaZborMax << endl;
    if (drona.nrElice != 0)
        out << "Nr elice: " << drona.nrElice << endl;
    if (drona.gps != 0)
        out << "GPS: "<< drona.gps << endl;
    if (drona.dimensiuni != NULL){
        out << "Dimensiuni: ";
        for (int i = 0; i < 3; i++)
            out << drona.dimensiuni[i] << " ";
            }
    if (drona.greutate != NULL)
        out << "\nGreutate: " << drona.greutate;
    return out;
}

istream& operator >> (istream& in, Drona& drona){
    // cout << "Introduceti numele firmei: ";
    // in >> drona.firma;

    // drona.model = new char[256];
    // cout << "Introduceti modelul: ";
    // //in.getline(drona.model, 256);
    // in.ignore();
    // in.getline(drona.model, 256);

    // cout << "Introduceti pretul: ";
    // in >> drona.pret;

    // cout << "Introduceti stocul: ";
    // in >> drona.stoc;
    in >> (Produs&)drona;

    cout << "Introduceti distanta minima de zbor: ";
    in >> drona.distantaZborMin;

    cout << "Introduceti distanta maxima de zbor: ";
    in >> drona.distantaZborMax;

    cout << "Introduceti nr de elice: ";
    in >> drona.nrElice;

    cout << "Introduceti gps: ";
    in >> drona.gps;

    cout <<"Introduceti rezolutia: ";
    in >> drona.rezolutie;

    cout <<"Introduceti rezolutia video: ";
    in >> drona.rezolutieVideo;

    if (drona.diafragma!=NULL)
        delete[] drona.diafragma;
    drona.diafragma = new char[256];
    cout << "Introduceti diafragma: ";
    in.ignore();
    in.getline(drona.diafragma, 256);

    if (drona.dimensiuni!=NULL)
        delete[] drona.dimensiuni;
    cout <<"Introduceti dimensiunile (l, L, H): ";
    drona.dimensiuni = new double[3];
    for (int i =0; i < 3; i++)
        in >> drona.dimensiuni[i];

    if (drona.greutate != NULL)
        delete[] drona.greutate;
    drona.greutate = new char[256];
    cout <<"Introduceti greutatea: ";
    in.ignore();
    in.getline(drona.greutate, 256);

    cout << endl;
    return in;
}

Drona& Drona::operator = (const Drona & drona){
    if(this != &drona){
        Produs::operator=(drona);
        // if(this->model != NULL)
        //     delete[] this->model;
        if(this->dimensiuni != NULL)
            delete[] this->dimensiuni;
        if(this->greutate != NULL)
            delete[] this->greutate;
        // this->firma = drona.firma;
        // this->model = new char[strlen(drona.model)+1];
        // strcpy(this->model, drona.model);

        this->dimensiuni = new double[3];
        for (int i = 0; i < 3; i++)
            this->dimensiuni[i] = drona.dimensiuni[i];

        // this->pret = drona.pret;
        // this->stoc = drona.stoc;
        this->distantaZborMin = drona.distantaZborMin;
        this->distantaZborMax = drona.distantaZborMax;
        this->nrElice = drona.nrElice;
        this->gps = drona.gps;
        this->greutate = new char[strlen(drona.greutate)+1];
        strcpy(this->greutate, drona.greutate);
        this->rezolutie = drona.rezolutie;
        this->rezolutieVideo = drona.rezolutieVideo;
        this->diafragma = new char[strlen(drona.diafragma)+1];
        strcpy(this->diafragma, drona.diafragma);
    }
    return *this;
}

bool Drona::operator == (const Drona& drona){
    if (this->firma == drona.firma && this->pret == drona.pret)
        return true;
    return false;
 }

bool Drona::operator <= (const Drona& drona){
    if (this->pret <= drona.pret)
        return true;
    return false;
 }

bool Drona::operator >= (const Drona& drona){
    if (this->pret >= drona.pret)
        return true;
    return false;
}

Drona::operator int(){
    return int(this->pret);
}

Drona Drona::operator + (float x){
    Drona d;
    d.pret = this->pret + x;
    return d;
}

Drona Drona::operator + (Drona d){
    Drona temp;
    temp.pret = this->pret + d.pret;
    return temp;
}

Drona operator + (float x, Drona d){
    Drona aux;
    aux.pret = x + d.pret;
    return aux;
}

Drona Drona::operator - (float x){
    Drona d;
    d.pret = this->pret - x;
    return d;
}

Drona Drona::operator - (Drona d){
    Drona temp;
    temp.pret = this->pret - d.pret;
    return temp;
}

double Drona::operator [] (int index){
    if (0 <= index && index <= 3)
        return dimensiuni[index];
    else
        cout << "Ai introdus indexul gresit!";
}

//PRE
const Drona& Drona::operator ++ (){
    this->stoc++;
    return *this;
}

//POST
const Drona Drona::operator ++ (int){
    this->stoc++;
    return *this;
}

//PRE
const Drona& Drona::operator -- (){
    this->stoc--;
    return *this;
}

//POST
const Drona Drona::operator -- (int){
    this->stoc--;
    return *this;
}

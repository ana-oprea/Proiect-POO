#include "Produs.h"

Produs::Produs(){
    this->firma = "";
    this->model = NULL;
    this->pret = 0;
    this->stoc = 0;
}

Produs::Produs(const string firma, char* model){
    this->firma = firma;
    strcpy(this->model, model);
    this->pret = 0;
    this->stoc = 0;
}
Produs::Produs(const string firma, const char* model, const float pret, const int stoc){
    this->firma = firma;
    this->model = new char[strlen(model)+1];
    strcpy(this->model,model);
    this->pret = pret;
    this->stoc = stoc;
}


Produs::Produs(const Produs& produs){
    if (produs.firma != "")
        this->firma = produs.firma;
    if (produs.model != NULL){
        this->model = new char[strlen(produs.model)+1];
        strcpy(this->model, produs.model);
    }
    if (produs.pret != 0)
        this->pret = produs.pret;
    if (produs.stoc != 0)
    this->stoc = produs.stoc;
}

// returneaza doar pretul pentru ca nu se stie inca tipul produsului si tva-ul il adaug pentru fiecare tip de produs
float Produs::calcPretCuTVA(){
    return this->pret;
}

Produs::~Produs(){
    if (this->model != NULL)
        delete[] this->model;
}

string Produs::getFirma() const{
    return this->firma;
}

char* Produs::getModel() const{
    return this->model;
}

float Produs::getPret() const{
    return this->pret;
}

int Produs::getStoc() const{
    return this->stoc;
}

// SETTERS
void Produs::setFirma(string firma){
   this->firma = firma;
}

void Produs::setModel(char* model){
    if(this->model != NULL)
        delete [] this->model;
    this->model = new char[strlen(model)+1];
    strcpy(this->model,model);
}

void Produs::setPret(float pret){
    this->pret = pret;
}

void Produs::setStoc(int stoc){
    this->stoc = stoc;
}

Produs& Produs::operator= (const Produs& produs){
    if (this != &produs){
        if (this->model != NULL)
            delete[] this->model;

        this->firma = produs.firma;
        this->model = new char[strlen(produs.model)+1];
        strcpy(this->model, produs.model);
        this->pret = produs.pret;
        this->stoc = produs.stoc;
    }
    return *this;
}

ostream& operator << (ostream& out, const Produs& produs){
    if (produs.firma != "")
        out << "Firma: " << produs.firma << endl;
    if (produs.model != NULL)
        out << "Model: " << produs.model << endl;
    if (produs.pret != 0)
        out << "Pret: "<< produs.pret << endl;
    if (produs.stoc != 0)
        out << "Stoc: "<< produs.stoc << endl;
    return out;
}

istream& operator >> (istream & in, Produs& produs){
    cout << "Introduceti numele firmei: ";
    in >> produs.firma;

    // observatia de la etapa 1
    if (produs.model != NULL)
        delete [] produs.model;

    produs.model = new char[256];
    cout << "Introduceti modelul: ";
    in.ignore(); //in.getline(aparat.model, 256);
    in.getline(produs.model, 256);

    cout << "Introduceti pretul: ";
    in >> produs.pret;

    cout << "Introduceti stocul: ";
    in >> produs.stoc;

    return in;
}

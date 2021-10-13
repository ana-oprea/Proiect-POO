#include "AparatFoto.h"

// CONSTRUCTORS

int AparatFoto::idContor= 100;

AparatFoto::AparatFoto():idAparat(idContor++), Produs(){
//     this->model = NULL;
    this->dimensiuni = NULL;
    // this->firma = "";
    // this->pret = 0;
    // this->stoc = 0;
    this->rezolutie = "";
    this->blit = 0;
    this->greutate = "";
}

AparatFoto::AparatFoto(const string firma, const char* model, const float pret, const int stoc):idAparat(idContor++), Produs(firma, model, pret, stoc){
    // this->pret = pret;
    // this->model = NULL;
    this->dimensiuni = NULL;
    // this->firma = "";
    // this->stoc = 0;
    this->rezolutie = "";
    this->blit = 0;
    this->greutate = "";
}


AparatFoto::AparatFoto(const string firma, char* model):idAparat(idContor++), Produs(firma, model){
    // this->firma = firma;
    //this-> model = model; // pt string
    // this->model=new char[strlen(model)+1];
    // strcpy(this->model,model);
    this->dimensiuni = NULL;
    this->pret = 0;
    this->stoc = 0;
    this->rezolutie = "";
    this->blit = 0;
    this->greutate = "";
}


AparatFoto::AparatFoto(string firma, char* model, float pret,
                   const int stoc, string rezolutie, bool blit,
                   float* dimensiuni, string greutate):idAparat(idContor++), Produs(firma, model, pret, stoc){
    // this->firma = firma;
    //this-> model = model; // pt string
    // this->model=new char[strlen(model)+1];
    // strcpy(this->model,model);
    this->dimensiuni = new float[3];
    for (int i =0; i < 3; i++)
        this->dimensiuni[i] = dimensiuni[i];
    // this->pret = pret;
    // this->stoc = stoc;
    this->rezolutie = rezolutie;
    this->blit = blit;
    this->greutate = greutate;
}


// constructor de copiere
AparatFoto::AparatFoto(const AparatFoto& aparat):idAparat(idContor), Produs(aparat){
    // if (aparat.firma != "")
    //     this->firma = aparat.firma;
    // if (aparat.model != NULL){
    //     this->model = new char[strlen(aparat.model)+1];
    //     strcpy(this->model, aparat.model);
    // }
    // if (aparat.pret != 0)
    //     this->pret = aparat.pret;
    // if (aparat.stoc != 0)
    // this->stoc = aparat.stoc;
    if (aparat.rezolutie != "")
        this->rezolutie = aparat.rezolutie;
    if (aparat.blit != 0)
        this->blit = aparat.blit;
    if (aparat.dimensiuni != NULL){
        this->dimensiuni = new float[3];
        for (int i = 0; i < 3; i++)
            this->dimensiuni[i] = aparat.dimensiuni[i];
    }
    if (aparat.greutate != "")
        this->greutate = aparat.greutate;
}

AparatFoto::~AparatFoto(){
    //if (this->model != NULL)
        //delete[] this->model;
    if(this->dimensiuni != NULL)
        delete[] this->dimensiuni;
}

// SUPRAINCARE FUCNTIE VIRTUALA PURA
float AparatFoto::calcPretCuTVA(){
    return this->pret * 0.1 + this->pret; // tva redus
}

float AparatFoto::calcTaxe(){
    return this->pret * 0.1;
}

// GETTERS

int AparatFoto::getIdAparat() const{
    return this->idAparat;
}

// string AparatFoto::getFirma() const{
//     return this->firma;
// }

// char* AparatFoto::getModel() const{
//     return this->model;
// }

// float AparatFoto::getPret() const{
//     return this->pret;
// }

// int AparatFoto::getStoc() const{
//     return this->stoc;
// }

string AparatFoto::getRezolutie()const{
    return this->rezolutie;
}

bool AparatFoto::getBlit()const{
    return this->blit;
}

float* AparatFoto::getDimensiuni()const{
    return this->dimensiuni;
}

string AparatFoto::getGreutate()const{
    return greutate;
}

// SETTERS
// void AparatFoto::setFirma(string firma){
//    this->firma = firma;
// }

// void AparatFoto::setModel(char* model){
//     if(this->model != NULL)
//         delete [] this->model;
//     this->model = new char[strlen(model)+1];
//     strcpy(this->model,model);
// }

// void AparatFoto::setPret(float pret){
//     this->pret = pret;
// }

// void AparatFoto::setStoc(int stoc){
//     this->stoc = stoc;
// }

void AparatFoto::setRezolutie(string rezolutie){
    this->rezolutie = rezolutie;
}

void AparatFoto::setBlit(bool blit){
    this->blit = blit;
}

void AparatFoto::setDimensiuni(float* dimensiuni){
    if(this->dimensiuni != NULL)
        delete[] this->dimensiuni;
    this->dimensiuni = new float[3];
    for (int i =0; i < 3; i++)
        this->dimensiuni[i] = dimensiuni[i];
}

void AparatFoto::setGreutate(string greutate){
    this->greutate = greutate;
}


// SUPRAINCARCARI

AparatFoto AparatFoto::operator+ (int x){
    AparatFoto aux(*this);
    aux.pret = aux.pret + x;
    return aux;
}

AparatFoto AparatFoto::operator+ (AparatFoto aparat){
    AparatFoto temp;
    temp.pret = this->pret + aparat.pret;
    return temp;
}

AparatFoto operator+ (float x, AparatFoto aparat){
    AparatFoto aux;
    aux.pret = x + aparat.pret;
    return aux;
}

AparatFoto& AparatFoto::operator= (const AparatFoto& aparat){
    if (this != &aparat){
        // if (this->model != NULL)
        //     delete[] this->model;    

        Produs::operator=(aparat);
        if(this->dimensiuni != NULL)
            delete[] this->dimensiuni;

        // this->firma = aparat.firma;
        // this->model = new char[strlen(aparat.model)+1];
        // strcpy(this->model, aparat.model);
        // this->pret = aparat.pret;
        // this->stoc = aparat.stoc;
        this->rezolutie = aparat.rezolutie;
        this->blit = aparat.blit;
        this->dimensiuni = new float[3];
        for (int i = 0; i < 3; i++)
            this->dimensiuni[i] = aparat.dimensiuni[i];
        this->greutate = aparat.greutate;
    }
    return *this;
}

ostream& operator << (ostream& out, const AparatFoto& aparat){
    out << (Produs&) aparat; // upcasting
    // if (aparat.firma != "")
    //     out << "Firma: " << aparat.firma << endl;
    // if (aparat.model != NULL)
    //     out << "Model: " << aparat.model << endl;
    // if (aparat.pret != 0)
    //     out << "Pret: "<< aparat.pret << endl;
    // if (aparat.stoc != 0)
    //     out << "Stoc: "<< aparat.stoc << endl;
    if(aparat.rezolutie != "")
        out << "Rezolutie: "<< aparat.rezolutie << endl;
    if (aparat.blit != 0)
        out << "Blit: "<< aparat.blit << endl;
    if (aparat.dimensiuni != NULL){
        out << "Dimensiuni: ";
        for (int i = 0; i < 3; i++)
            out << aparat.dimensiuni[i] << " ";
            }
    if (aparat.greutate != "")
        out << "\nGreutate: " << aparat.greutate;
    return out;
}

istream& operator >> (istream & in, AparatFoto& aparat){
    in >> (Produs&) aparat; //upcasting de la AparatFoto la Produs
    // cout << "Introduceti numele firmei: ";
    // in >> aparat.firma;

    // aparat.model = new char[256];
    // cout << "Introduceti modelul: ";
    // in.ignore(); //in.getline(aparat.model, 256);
    // in.getline(aparat.model, 256);

    // cout << "Introduceti pretul: ";
    // in >> aparat.pret;

    // cout << "Introduceti stocul: ";
    // in >> aparat.stoc;

    cout <<"Introduceti rezolutia: ";
    in >> aparat.rezolutie;

    cout <<"Introduceti blit: ";
    in >> aparat.blit;

    cout <<"Introduceti dimensiunile (l, L, H): ";
    aparat.dimensiuni = new float[3];
    for (int i =0; i < 3; i++)
        in >> aparat.dimensiuni[i];

    cout <<"Introduceti greutatea: ";
    in >> aparat.greutate;

    cout << endl;
    return in;
}

bool AparatFoto::operator == (const AparatFoto& aparat){
    if (this->firma == aparat.firma && this->pret == this->pret)
        return true;
    return false;
}

bool AparatFoto::operator < (const AparatFoto& aparat){
    if (this->pret < aparat.pret)
        return true;
    return false;
}

bool AparatFoto::operator > (const AparatFoto& aparat){
    if (this->pret > aparat.pret)
        return true;
    return false;
}

AparatFoto::operator int(){
    return int(this->pret);
}


AparatFoto AparatFoto::operator - (float x){
    AparatFoto ap;
    ap.pret = this->pret -x;
    return ap;
}

AparatFoto AparatFoto::operator - (AparatFoto ap){
    AparatFoto temp;
    temp.pret = this->pret - ap.pret;
    return temp;
}

//PRE
const AparatFoto& AparatFoto::operator ++ (){
    this->stoc++;
    return *this;
}

//POST
const AparatFoto AparatFoto::operator ++ (int){
    this->stoc++;
    return *this;
}

//PRE
const AparatFoto& AparatFoto::operator -- (){
    this->stoc--;
    return *this;
}

//POST
const AparatFoto AparatFoto::operator -- (int){
    this->stoc--;
    return *this;
}

float AparatFoto::operator [] (int index){
    if (0 <= index && index <= 3)
        return this->dimensiuni[index];
    else
        cout << "Ai introdus indexul gresit!";
}

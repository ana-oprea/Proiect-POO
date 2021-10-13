#include "Admin.h"

Admin::Admin()
{
    vanzari = 0;
}

Admin::~Admin()
{

}

// GETTERS

const string Admin::getNumeMagazin(){
    return this->numeMagazin;
}

void Admin::getAparateFoto(){
    for (int i = 0; i < this->aparate.size(); i++){
        cout << i + 1 << ". ";
        cout << this->aparate[i] << endl;
        cout << "================================================================\n";
    }
}

void Admin::getDrone(){
    for (int i = 0; i < this->drone.size(); i++){
        cout << i + 1 << ". ";
        cout << this->drone[i] << endl;
        cout << "================================================================\n";
    }
}

float Admin::getTotal(){
    return this->vanzari;
}

// SETTERS

void Admin::setAparatFoto(){
    AparatFoto ap;
    cin >> ap;
    this->aparate.push_back(ap);
}

void Admin::setDrona(){
    Drona d;
    cin >> d;
    this->drone.push_back(d);
}

void Admin::setTotal(float vanz){
    this->vanzari = vanz;
}

// METODE

AparatFoto Admin::getAparat(int poz){
    return this->aparate[poz];
}

int Admin::getAparateSize(){
    return this->aparate.size();
}

int Admin::getDroneSize(){
    return this->drone.size();
}

void Admin::deleteAparatFoto(int pozitie){
    this->aparate.erase(this->aparate.begin() + pozitie);
}

void Admin::addAparatFoto(AparatFoto ap){
    this->aparate.push_back(ap);
}

void Admin::deleteDrona(int pozitie){
    this->drone.erase(this->drone.begin()+pozitie);
}

void Admin::addDrona(Drona d){
    this->drone.push_back(d);
}

void Admin::showProduseMagazin(){
    for (int i = 0; i < this->aparate.size(); i++)
        cout << this->aparate[i] << endl;
    for (int  i =0; i< this->drone.size(); i++)
        cout << this->drone[i] << endl;
}

void Admin::addToTotal(float vanz){
    this->vanzari += vanz;
}

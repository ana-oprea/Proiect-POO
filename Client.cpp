#include "Client.h"

int Client::nrClienti = 1;

Client::Client():idClient(nrClienti++)
{
    this->total = 0;
    this->numeClient = "";
}

Client::Client(string numeClient):idClient(nrClienti++){
    this->numeClient = numeClient;
}

Client::~Client()
{

}


void Client::setTotal(float pret){
    this->total = pret;
}

float Client::getTotal(){
    return this->total;
}

void Client::setNumeClient(string numeClient){
    this->numeClient = numeClient;
}

string Client::getNumeClient(){
    return this->numeClient;
}

string Client::getCosElem(int poz){
    return this->cos[poz]->getModel();
}

void Client::addInCos(Produs* p){
    this->cos.push_back(p);
    this->total = this->total + p->getPret();
}

int Client::removeFromCos(int poz){
    if (poz < this->cos.size()){
        this->total = this-> total - this->cos[poz]->getPret();
        this->cos[poz]->setStoc(cos[poz]->getStoc()-1);
        this->cos.erase(this->cos.begin() + poz);
        return 1;
    }
    else
        return 0;
}

int Client::getCosSize(){
    return this->cos.size();
}

void Client::showCos(){
    for (int i = 0; i < this->cos.size(); i++){
            cout << i + 1 << ". ";
        if (typeid(*(this->cos[i])) == typeid(AparatFoto)) // daca produsul de pe pozitia i este de tipul AparatFoto
        {
            cout <<  static_cast<AparatFoto&>(*this->cos[i]) << endl; // downcast de la clasa Produs la clasa AparatFoto
            }
        else{
            cout <<  static_cast<Drona&>(*this->cos[i]) << endl; // downcast de la clasa Produs la clasa Drona
        }
    }
}

Client& Client::operator= (const Client& client){
    if (this != &client){
        this->numeClient = client.numeClient;
    }
    return *this;
}

ostream& operator << (ostream& out, const Client& client){
    out << "Sunteti clientul nr " << client.idClient << endl;
    if (client.numeClient != "")
        out << "Nume client: " << client.numeClient << endl;
    return out;
}

istream& operator >> (istream & in, Client& client){
    cout << "Introduceti numele: ";
    in >> client.numeClient;

    cout << endl;
    return in;
}

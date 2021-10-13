#include "AparatFoto.h"
#include "Drona.h"
#include "Admin.h"
#include "Produs.h"
#include "Client.h"
#include "TVA.h"
#include "MeniuInteractiv.h"
using namespace std;

int main()
{
    // exemplific virtualizarea
    // float dimensiuni[3] = {923, 56 ,67};

    // AparatFoto aparat("Sony", "A77", 1600, 4, "70px", 1, dimensiuni, "800g");
    // Drona drona ("Dij", "A7", 1600, 3, "20px","4k","f1.7", "1", dimensiuni, "300g", 2000, 4000, 4);

    // // obiectele aparat si drona au pretul initial (brut) de 1600

    // Produs *produse[10];
    // produse[0] = new AparatFoto(aparat);
    // // tva-ul care se adauga la aparat este de 10% din pret
    // cout << "Pret: "<< produse[0]->calcPretCuTVA()<<endl; // aparatul cu tva-ul adaugat
    // cout << "tva: " << produse[0]->calcTaxe() << endl; // tva-ul

    // // tva-ul care se adauga la aparat este de 20% din pret
    // produse[1] = new Drona(drona);
    // cout << "Pret: "<< produse[1]->calcPretCuTVA()<<endl; // drona cu tva-ul adaugat
    // cout << "tva: " << produse[1]->calcTaxe() << endl; // tva-ul

    MeniuInteractiv *meniulM = meniulM->getInstance();
    meniulM->meniu();
    return 0;
}

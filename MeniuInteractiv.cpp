#include "MeniuInteractiv.h"

MeniuInteractiv* MeniuInteractiv::ob = 0;

void MeniuInteractiv::meniu(){
     vector <Produs*> listaProduse;
     unordered_set <string> nume;
     unordered_map <string, int> prodStoc;
     list <float> vanzari;
     vector <AparatFoto> AP;
     vector <Drona> D;
     Admin admin;
     ifstream fin("date.in");
     ofstream fout("date.out");
     string inp;
     int counter = 0;
     while(fin>>inp){
        if (inp == "ap"){
            AparatFoto ap;
            string s;
            int i;
            float f;
            bool b;
            fin >> s;
            ap.setFirma(s);
            char* mod;
            mod = new char[256];
            fin.ignore();
            fin.getline(mod, 256);
            ap.setModel(mod);

            fin >> f;
            ap.setPret(f);

            fin >> i;
            ap.setStoc(i);

            fin >> s;
            ap.setRezolutie(s);


            fin >> b;
            ap.setBlit(b);


            float d[3];
            for (int i = 0; i < 3; i++)
                fin >> d[i];
            ap.setDimensiuni(d);

            fin >> s;
            ap.setGreutate(s);

            AP.push_back(ap);
            admin.addAparatFoto(ap);
            listaProduse.push_back(&AP[AP.size() - 1]);
            prodStoc[mod] = counter ++;
        }
        else{
                Drona d;
                string s;
                bool b;
                int i;
                float f;
                fin >> s;
                d.setFirma(s);
                char* mod;
                mod = new char[256];
                fin.ignore();
                fin.getline(mod, 256);
                d.setModel(mod);

                fin >> f;
                d.setPret(f);
                fin >> i;
                d.setStoc(i);
                fin >> i;
                d.setDistantaZborMin(i);
                fin >> i;
                d.setDistantaZborMax(i);
                fin >> i;
                d.setnrElice(i);
                fin >> b;
                d.setGps(b);
                fin >> s;
                d.setRezolutie(s);
                fin >> s;
                d.setRezolutieVideo(s);

                char* diaf;
                diaf = new char[256];
                fin.ignore();
                fin.getline(diaf, 256);

                d.setDiafragma(diaf);

                double dim[3];
                for (int i = 0; i < 3; i++)
                    fin >> dim[i];
                d.setDimensiuni(dim);
                char* g;
                g = new char[256];
                fin.ignore();
                fin.getline(g, 256);
                d.setGreutate(g);

                D.push_back(d);
                admin.addDrona(d);

                listaProduse.push_back(&D[D.size() - 1]);
                prodStoc[mod] = counter ++;

        }
     }
     int ok;
     int iesire = 1;
     while(iesire == 1){
        Client client;
        cin >> client;
        cout << client << "\n";
        nume.insert(client.getNumeClient());
        ok = 1;
     while (ok == 1){
        cout << "\n1. Afisare Aparate foto";
        cout << "\n2. Afisare Drone";
        cout << "\n3. Afisare Cos";
        cout << "\n4. Finalizare Comanda";
        cout << "\n5. Administrator";
        cout << "\n6. Stop";
        cout << "\nIntroduceti optiunea: ";

        int comanda;
        cin >> comanda;

        switch(comanda){
            case 1:{
                int ct = 1;
                if (AP.size() > 0){

                for (int i = 0; i < AP.size(); i ++){
                    cout << "\n" << i + 1 << " " << AP[i] << "\n";
                    cout << "==========================================\n";
                }

                int k = 1;
                while (k == 1){
                    cout << "Doriti sa adaugati un produs in cos?(1/0)";
                    int c;
                    cin >> c;
                    switch (c){
                        case 1:{
                            cout << "Introduceti nr produsului pe care doriti sa-l introduceti in cos.";
                            int c1;
                            cin >> c1;
                            if (AP[c1-1].getStoc() > 0)
                                client.addInCos(&AP[c1-1]);
                            else
                                cout << "\nProdusul nu mai este in stoc!";
                        }
                        case 0:{
                            k = 0;
                            break;
                        }
                    }
                }
                }
                else {
                    cout << "\nNu avem produse in acest moment!\n";
                }
                break;
            }
            case 2:{
                int ct = 1;
                if (D.size() > 0){

                for (auto x: D){
                    cout << x << "\n";
                    cout << "==========================================\n";
                }

                int k = 1;
                while (k == 1){
                    cout << "Doriti sa adaugati un produs in cos?(1/0)";
                    int c;
                    cin >> c;
                    switch (c){
                        case 1:{
                            cout << "Introduceti nr produsului pe care doriti sa-l introduceti in cos.";
                            int c1;
                            cin >> c1;
                            if (D[c1-1].getStoc() > 0)
                                client.addInCos(&D[c1-1]);
                            else
                                cout << "\nProdusul nu mai este in stoc!";
                        }
                        case 0:{
                            k = 0;
                            break;
                        }
                    }
                }
                }
                else {
                    cout << "\nNu avem produse in acest moment!\n";
                }
                break;
            }
            case 3:{
                if (client.getCosSize() == 0){
                    cout << "Nu aveti produse in cos!\n";
                }
                else{
                    cout << "\n";
                    client.showCos();
                    int pos = 1;
                    while (pos == 1){
                    cout << "\n1. Stergeti un produs din cos.";
                    cout << "\n2. Inapoi.";
                    int opt;
                    cin >> opt;
                    switch(opt){
                        case 1:{
                            cout << "Introduceti numarul produsului pe care doriti sa-l stergeti : ";
                            int nr;
                            cin >> nr;
                            client.removeFromCos(nr-1);
                            break;
                        }
                        case 2:{
                            pos = 0;
                            break;
                        }
                    }
                    }
                }
                break;
            }
            case 4:{
                client.showCos();
                cout << "Finalizati comanda?(y/n)";
                string finalizare;
                cin >> finalizare;
                if (finalizare == "y"){
                    cout << "\nAveti de platit " << client.getTotal();
                    cout << "\nVa multumim!";
                    fout << "Magazin: " << admin.getNumeMagazin() << endl;
                    fout << "Nume client: " << client.getNumeClient() <<endl ;
                    fout << "Total: " << client.getTotal() << endl;
                    vanzari.push_front(client.getTotal());
                    admin.addToTotal(client.getTotal());
                    cout << "\nDoriti sa continuati cumparaturile?(y/n)";
                    string rasp;
                    cin >> rasp;
                    for (int i = 0; i < client.getCosSize(); i++){
                            string mod = client.getCosElem(i);
                            if (prodStoc[mod] < AP.size()){
                                AP[prodStoc[mod]].setStoc(AP[prodStoc[mod]].getStoc() - 1);
                                }
                            else{
                                D[prodStoc[mod] - AP.size() ].setStoc(D[prodStoc[mod] - AP.size() ].getStoc() - 1);
                            }
                        }
                    if (rasp == "y"){
                        client.setTotal(0);
                        for (int i = 0; i < client.getCosSize(); i++){
                            client.removeFromCos(i);
                        }
                        break;
                    }
                    else{
                        ok = 0;
                        break;
                    }
                }
                else{
                    break;
                }

            }
            case 5:{
                int m = 1;
                while(m == 1){
                cout << "\n1. Adauga un produs.";
                cout << "\n2. Sterge un produs.";
                cout << "\n3. Total vanzari magazin.";
                cout << "\n4. Inapoi.\n";
                cout << "Introduceti optiunea: ";
                int c2;
                cin >> c2;
                cout << "\n";
                        switch(c2){
                            case 1:{
                                cout << "Introduceti tipul  produsului (ap/d): ";
                                string tip;
                                cin >> tip;
                                if (tip == "ap"){
                                    AparatFoto ap;
                                    cin >> ap;
                                    AP.push_back(ap);
                                    admin.addAparatFoto(ap);
                                    listaProduse.push_back(&AP[AP.size() - 1]);
                                    prodStoc[ap.getModel()] = counter ++;
                                }
                                else{
                                    Drona d;
                                    cin >> d;
                                    D.push_back(d);
                                    admin.addDrona(d);
                                    listaProduse.push_back(&D[D.size() - 1]);
                                    prodStoc[d.getModel()] = counter ++;
                                }
                                cout << "\n";
                                break;
                            }
                            case 2:{
                                cout << "\n";
                                int ct = 1;
                                for (auto j: AP){
                                    cout << ct << ". "<< j;
                                    cout << "\n=============================\n";
                                    ct++;
                                }
                                for (auto j: D){
                                    cout << ct << ". " << j;
                                    cout << "\n=============================\n";
                                    ct++;
                                }
                                cout << "\nIntroduceti nr produsului pe care doriti sa-l stergeti: ";
                                int p;
                                cin >> p;
                                if (p <= AP.size()){
                                    AP.erase(AP.begin() + p - 1);
                                }
                                else{
                                    D.erase(D.begin() + (p - AP.size()));
                                }

                                break;
                            }
                            case 3:{
                                cout << "\nTotalul de vanzari: " << admin.getTotal() << endl;
                                cout << "Acestia au fost clientii: " << endl;
                                for (auto x: nume)
                                    cout << x << " ";
                                cout << "\nAcestea sunt cumparaturile individuale: " << endl;
                                for (auto it = vanzari.begin(); it != vanzari.end(); it++)
                                    cout << *it << ", ";
                                break;
                            }
                            case 4:{
                                m = 0;
                                break;
                            }

                }
                }
                break;
            }
            case 6:{
                ok = 0;
                iesire = 0;
                break;
            }
        }
     }
     }
    fin.close();
    fout.close();


}

#ifndef MENIUINTERACTIV_H
#define MENIUINTERACTIV_H
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <fstream>
#include "Produs.h"
#include "Client.h"
#include "AparatFoto.h"
#include "Drona.h"
#include "Admin.h"
class MeniuInteractiv
{
    private:
    static MeniuInteractiv *ob;
    public:
        static MeniuInteractiv* getInstance(){
            if (!ob)
                ob = new MeniuInteractiv();
            return ob;
        }

        void meniu();
};

#endif // MENIUINTERACTIV_H

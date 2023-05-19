#include <iostream>
#include<cstdlib>
#include <fstream>
#include <cstring>
using namespace std;
fstream f;
ifstream g("lista_produse.txt");
struct produse {
    char nume[50];
    int stoc;
}V[50];

void afisare(int random) {
    if (V[random].stoc != 0)
    {
        cout << "Ai castigat premiul nr. " << random << ", adica " << V[random].nume << endl;
        V[random].stoc = V[random].stoc - 1;
    }
    else
    {
        int OK=0;
        do
        {
            int random2 = 1 + (rand() % 33);
            int OK = 0;
            if (V[random2].stoc != 0)
            {
                OK = 1;
                cout << "Ai castigat premiul nr. " << random2<<", adica " << V[random2].nume << endl;
                V[random2].stoc = V[random2].stoc - 1;
            }
        } while (!OK);
    }
}
void citire() {
    f.open("input.txt", ios::in);
    for (int i = 1; i <= 33; i++)
    {
        g.getline(V[i].nume,50);
        f >> V[i].stoc;
    }
    f.close();
}


    int main()
    {
        srand((unsigned)time(NULL));
        // Retrieve a random number between 100 and 200
        // Offset = 100;
        // Range = 101;
        int random = 1 + (rand() % 33);
        citire();
        afisare(random);
        f.open("input.txt", ios::out);
        for (int i = 1; i <= 33; i++)
            f << V[i].stoc << endl;;
           
        /*f << nr1 << " ";
        f << nr2;
        */

        f.close();

        return 0;

    }
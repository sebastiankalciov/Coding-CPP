/** La un concurs de patinaj participa n sportivi (maxim 25)
    Concursul are m probe (maxim 8)
    Se citeste o matrice de dimensiunea n*m cu semnificatia
    ca fiecare linie reprezinta punctajele obtinute de patinatorul i la cele m probe ale concursului
    Sa se afiseze, in fisierul text patinaj.out, pentru fiecare proba,
    punctajul maxim si concurentii care l au obtinut

    ex: n = 4, m = 3

    n - linii
    m - coloane

    si matricea
                   probe -> 0 1 2

    punctaje patinator 0 -> 5 2 3              p 0 -> 5
    punctaje patinator 1 -> 5 2 4              p 1 -> 7
    punctaje patinator 2 -> 1 7 4              p 2 -> 4
    punctaje patinator 3 -> 3 4 3

    se va afisa

    0: 5, 0, 1
    1: 7, 2
    2: 4, 1, 2

    Pas 1:
    Citim matricea din fisier

    Pas 2:

    Gasim punctajul maxim la fiecare proba

    Pas 3:

    Gasim fiecare jucator care a obtinut punctajul maxim

    Pas 4:

    Afisam probele urmate de rezultatul maxim si jucatorii care au obtinut


**/

#include <iostream>
#include <fstream>
#include "tbio.h"
using namespace std;



// Functie ce adauga intr-un vector punctajele maxime pentru fiecare proba
// Ex: proba    -> 0 1 2
//     punctaje -> 5 7 4

void maximMatrice (int A[30][30], int M[30], int m, int n)
{
    int punctajMaxim;


    for (int j = 0; j < n; j++) // Pentru fiecare coloana
    {

        punctajMaxim = A[0][j]; // Setam primul punctaj fiind cel mai mare

        for (int i = 1; i < m-1; i++) // Pentru fiecare linie, incepand cu a 2 a fiindca prima este deja setata mai devreme
        {
            if (punctajMaxim < A[i+1][j]) // Daca punctajul considerat pana acum cel mai mare este mai mic decat punctajul
            {                             // actual, atunci
                punctajMaxim = A[i+1][j]; // retinem punctajul actual ca fiind cel mai mare

            }

        }

        M[j] = punctajMaxim; // Setam apoi intr-un vector pentru fiecare proba, punctajul ce mai mare
                             // Ex: proba    -> 0 1 2
                             //     punctaje -> 5 7 4
    }
}


// Functie ce modifica matricea initiala cu 1 sau 0 in functie de punctajul fiecarui patinator
// Daca patinatorul are punctaj maxim, atunci acesta devina un 1, daca nu are punctaj maxim, devine un 0

void patinatoriMaxim(int A[30][30], int M[30], int m, int n)
{
    for (int j = 0; j < n; j++) // Pentru fiecare proba

        for (int i = 0; i < m; i++) // Pentru fiecare patinator
        {
            if (A[i][j] == M[j]) // Daca patinatorul are punctaj maxim la proba "j"
            {
                A[i][j] = 1; // Atunci acesta devina 1


            } else { /** Altfel, devine un 0
                     // Alegem sa facem patinatorii 0 sau 1 pentru ca mai tarziu cand afisam rezultatele
                     // E mai usor sa trecem o singura data printr-o matrice, sa verificam daca participantul
                     // respectiv are punctaj maxim, sau nu
                        La o anumita proba

                     **/

                A[i][j] = 0;
            }
        }
}

// Functie ce afiseaza rezultatele
void afisareRezultat(int A[30][30], int M[30], int m, int n)
{
    ofstream f("patinaj.out"); // Cream fisierul "patinaj.out"


    for (int j = 0; j < n; j++) // Pentru fiecare proba
    {
        f << j << ": " << M[j] << ", "; // Afisam proba (ex: proba 0)

        for (int i = 0; i < m; i++) // Pentru fiecare participant
            if (A[i][j] == 1) // Daca acesta a obtinut punctaj maxim
                f << i << " "; // Il afisam in fisier

        f << endl; // Trecem la rand nou, insemnand ca nu mai sunt rezultate pentru proba respectiva

    }

}


int main()

{

    int m, n, A[30][30], M[30];

    cout << "cati patinatori (n) = "; cin >> n;
    cout << "cate probe (m) = "; cin >> m;


    citireMatrice(A, n, m); // Citim matricea din fisier
    maximMatrice(A, M, n, m); // Alegem punctajele maxime
    //afisareVector(M, m);
    //cout << endl;
    patinatoriMaxim(A, M, n, m); // Setam 1 sau 0 pentru fiecare patinator, in functie de punctaj
    //afisareMatrice(A, n, m);
    //cout << endl;
    afisareRezultat(A, M, n, m); // Afisam rezultatele in fisierul "patinaj.out"

}

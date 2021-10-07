// <- Cu 2 linii punem comentarii pe o singur linie

/** Cu /**  punem comentarii
    pe mai multe linii **/

#include <iostream>
/** Includem iostream, o librarie (un alt program mai complex) ce contine functii si alte lucruri importante
    Care ne ajuta sa scriem programele
    Mai exact ne ajuta sa citim si sa afisam chestii

**/
using namespace std;
/** Folosim asta pentru a nu se incurca variabilele (ex, int varstaElev) dintr-un program cu altul,
    cand se creeaza programe mai complexe **/


// Functie ce citeste o matrice X
// Aici este definita functia
void citireMatrice (int X[5][5], int m, int n)
{

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) // Punem {} dupa instructiune(for) fiindca in ea se executa mai multe lucruri
        {
            cout << "X[" << i << "][" << j << "]= "; // cout - console out, afiseaza chestii
            cin >> X[i][j]; // cin - console in, introduce chestii

        }

}
// Functie ce afiseaza o matrice in consola (dreptunghiu negru)
void afisareMatrice (int X[5][5], int m, int n)
{

    for (int i = 0; i < m; i++)
    {

        for (int j = 0; j < n; j++)
            cout << X[i][j] << " ";

        cout << endl; // endl - endline, trece la un rand nou, se mai poate trece si cu cout << "\n";

    }




}

void produsMatrice (int A[5][5], int m, int n, int B[5][5], int p, int C[5][5])
{

    for (int i = 0; i < m; i++) // Incepem o instructiune de for ce parcurge liniile
        for (int j = 0; j < n; j++) // Incepem o alta instructiune for ce parcurge coloanele, de la 0, pana la n-1
        {
            C[i][j] = 0; // Initializam locurile din matrice pe 0, ca atunci cand inmultim, sa apara numaru corect, nu un numar urat

            for (int k = 0; k < n; k++) /** Adaugam o alta instructiune for ce parcurge numaru de coloane, fiindca asta conteaza intr o matrice
                                            Adica atunci cand luam o matrice si o inmultim, ce ne intereseaza e numaru de coloane de la prima matrice
                                            Cu numaru de linii de la a 2 a matrice, si k este acel numar comun **/

                    C[i][j] += A[i][k] * B[k][j];

        }

}
/** Functia "main" e functia principala, cu asta incepe programu, de aici "pleaca toate"
    Nu are nici un parametru (parametrii sunt variabilele din functii, cum am adaugat la produsMatrice int A[5][5], "A" ii variabila

**/
int main()
{
    int A[5][5], B[5][5], C[5][5], m, n, p; /** Cand declaram variabile intr o functie, trebuie pus o singura data tipul variabilelor
                                               Daca sunt de acelasi tip (ex: int - integer (numar fara virgule))
                                               Se pot pune de mai multe ori tipu, daca le punem astfel
                                               int A[5][5];
                                               int B[5][5]
                                               ..
                                            **/


    cout << "numar linii = "; cin >> m; // Citim numaru de linii
    cout << "numar coloane = "; cin >> n; // Citim numaru de coloane, ce va fi folosit pentru ambele matrice

    citireMatrice(A, m, n); // Citim matricea A

    citireMatrice(B, m, n); // Citim matricea B

    produsMatrice(A, m, n, B, p, C); // Inmultim matricele

    afisareMatrice(C, m, n); // Afisam matricea C


}

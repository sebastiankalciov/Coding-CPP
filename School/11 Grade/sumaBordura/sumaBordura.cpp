/** Suma elementelor de pe bordura unei matrici de dimensiune m x n

    m - numaru de linii
    n - numaru de coloane

    i - linie
    j - coloana

    m = 4; n = 5;



   linia 0->  1 1 1 1 1     prima linie: A[0][j] -     Avem A[0] pentru ca vrem sa calculam suma elementelor de pe prima linie,
   linia 1->  2 2 2 2 2                                si luam elementele doar pe linia 0, asta fiind prima linie, si schimbam doar coloana cu "j"
   linia 2->  3 3 3 3 3
   linia 3->  4 4 4 4 4                                linia 0-> A[0][0] .. A[0][1] .. A[0][2].. A[0][3].. A[0][4]

   suma = 35                ultima coloana: A[i][n-1] - Avem [n-1] pentru ca ne trebuie ultima coloana, numaratoarea incepand de la 0, nu avem linia 5,
                                                        avem linia 4 si se schimba doar linia cu "i"


                                                        linia 0-> . . . . A[0][4] <- ultima coloana, primul element
                                                        linia 1-> . . . . A[1][4]
                                                        linia 2-> . . . . A[2][4]
                                                        linia 3-> . . . . A[3][4] <- ultima coloana, ultimul element



                            ultima linie: A[m-1][j] - La fel ca la prima linie, doar ca in loc de linia 0, o punem pe ultima, pentru ca stiim ca
                                                      m ii numarul de linii, si ultima linie nu este 4 fiindca numaratoarea incepe de la 0, este 3

                                                      linia 3-> A[3][0] .. A[3][1] .. A[3][2].. A[3][3].. A[3][4]

                            prima coloana: A[i][0] - Ii la fel ca si la ultima coloana, doar ca nu o luam pe ultima, ci pe prima, adica coloana 0,
                                                     si schimbam liniile


                                                        linia 0-> . . . . A[0][0] <- prima coloana, primul element
                                                        linia 1-> . . . . A[1][0]
                                                        linia 2-> . . . . A[2][0]
                                                        linia 3-> . . . . A[3][0] <- prima coloana, ultimul element



**/



/** Includem ce avem nevoie **/
#include <iostream>

using namespace std;

// Functie de citire a unei matrici
void citireMatrice (int X[5][5], int m, int n)
{

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            cout << "X[" << i << "][" << j << "]= ";
            cin >> X[i][j];
        }

}

// Functie ce calculeaza suma bordurii
int sumaBordura(int A[5][5], int m, int n)
{

    int S = 0;

    /** O sa avem nevoie de mai multe instructiuni for pentru a lua fiecare latura a matricei **/

    // Prima linie
    for (int j = 0; j < n; j++)
        /** Am inceput instructiune cu "j" din cauza ca vrem sa schimbam doar coloanele, linia ramane aceeasi **/

        S += A[0][j];

    // Ultima coloana
    for (int i = 1; i < m; i++)
        /** Am inceput instructiune cu "i" din cauza ca vrem sa schimbam doar liniile, coloana ramane aceeasi, ultima
            Am inceput cu i de la 1 fiindca nu vrem sa adunam ultimul element de pe prima linie de 2 ori**/

        S += A[i][n-1];

    // Ultima linie
    for (int j = 0; j < n-1; j++)
        /** Am inceput instructiune cu "j" din cauza ca vrem sa schimbam doar coloanele, linia ramane aceeasi, ultima
            Mergem cu coloanele pana la penultima din cauza ca ultimul element l am adunat cand am adunat ultima coloana**/

        S += A[m-1][j];

    // Prima coloana
    for (int i = 1; i < m-1; i++)
        /** Am inceput instructiune cu "i" din cauza ca vrem sa schimbam doar liniile, coloana ramane aceeasi, prima
            Am inceput cu i de la 1 fiindca nu vrem sa adunam primul element de pe prima linie de 2 ori
            Si am mers pana la m-1 fiindca nu vrem sa adaugam si primu element de pe ultima linie de 2 ori**/

        S += A[i][0];


        return S; // Returnam suma

}


int main()
{

    int A[5][5], m, n;

    cout << "numar linii = "; cin >> m;
    cout << "numar coloane = "; cin >> n;

    citireMatrice(A, m, n);

    cout << endl << "suma elementelor de pe bordura = " << sumaBordura(A, m, n);

    return 0; // Returnam 0, insemnand ca programul a luat sfarsit


}


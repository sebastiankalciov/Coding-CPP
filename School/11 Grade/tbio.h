#ifndef TBIO_H_INCLUDED
#define TBIO_H_INCLUDED

#include <fstream>
#include <iostream>
using namespace std;

ifstream f("matrice.io");

// Functie ce citeste matrici
void citireMatrice(int A[30][30], int m, int n)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            f >> A[i][j];

}

void afisareMatrice(int A[30][30], int m, int n)
{

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                cout << A[i][j] << " ";

            cout << endl;

        }


}

void afisareVector(int A[30], int m)
{

        for (int i = 0; i < m; i++)
        {
            cout << A[i] << " ";
            cout << endl;

        }


}



#endif // TBIO_H_INCLUDED

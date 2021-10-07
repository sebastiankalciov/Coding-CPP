# Problema "Concurs Patinaj"

`Nota: Metoda folosita este diferita de cea din clasa.`

## Descrierea problemei
La un concurs de patinaj participa **n** sportivi (maxim **25**)
Concursul are **m** probe (maxim **8**)
Se citeste o matrice de dimensiunea **n*m** cu semnificatia
ca fiecare linie reprezinta punctajele obtinute de patinatorul **i** la cele **m** probe ale concursului
Sa se afiseze, in fisierul text **patinaj.out**, pentru fiecare proba,
punctajul maxim si concurentii care l-au obtinut


    Ex: n = 4, m = 3

                               0 1 2 <- Probe
    Punctaje patinator ->
                          0 -> 5 2 3             
                          1 -> 5 2 4             
                          2 -> 1 7 4             
                          3 -> 3 4 3

    Se va afisa

    0: 5, 0, 1
    1: 7, 2
    2: 4, 1, 2


## Rezolvarea problemei

- Pas 1: Citim matricea din fisier.

- Pas 2: Gasim punctajul maxim la fiecare proba.

- Pas 3: Gasim fiecare jucator care a obtinut punctajul maxim.

- Pas 4: Afisam probele urmate de rezultatul maxim si jucatorii care l-au obtinut.

#include <stdio.h>
#include <math.h>
#define ordineMAX 8 // ordine massimo della matrice

void InitMatrice(int Matrice[][ordineMAX], int ordine);
int Matrice2x2(int a11, int a12, int a21, int a22);
int CalcolaDet(int Matrice[][ordineMAX], int ordine);
void EstraiMin(int IN_Matrice[][ordineMAX], int IN_ordine, int IN_colonna, int OUT_Minore[][ordineMAX]);
int Segno(int numero);
int main()
{
    int MatriceNxN[ordineMAX][ordineMAX];
    int ordine = 0; // ordine dellla matrice
    int D = 0;

    do
    {
        printf("ordine della matrice ");
        scanf("%d", &ordine);
        if (ordine > ordineMAX)
            printf("ordine deva essere minore di %d\n", ordineMAX);
    } while (ordine > ordineMAX);

     // inilizazione matrice NxN
    InitMatrice(MatriceNxN, ordineMAX);

    //richiesta dei valori dei coeficienti
    printf("inserisci valori degli elmenti\n\n");

    //inserimento valori matrice M
    for (int j = 0; j < ordine; j++) 
        for (int i = 0; i < ordine; i++) 
        {
            printf("metti il coeficiente %d,%d ",j+1,i+1);
            scanf("%d", &MatriceNxN[j][i]);
        }
    D = CalcolaDet(MatriceNxN, ordine);
    printf("Determinante = %d", &D);
    return 0;
}

void InitMatrice(int IO_Matrice[][ordineMAX], int IN_ordine) {
    // inizializza la matrice 
    for (int h = 0; h < IN_ordine; h++)
        for (int k = 0; k < IN_ordine; k++)
            IO_Matrice[h][k] = 0;
}

int CalcolaDet(int Matrice[][ordineMAX], int ordine) {
   
    int Minore[ordineMAX][ordineMAX];
    int DetMin = 0;
    int Determinante = 0;

    InitMatrice(Minore, ordineMAX);

    if (ordine == 2)
        Determinante = Determinante + Matrice2x2(Matrice[0][0],Matrice[0][1],Matrice[1][0],Matrice[1][1]);
    else 
        for (int colonna = 0; colonna < ordine; colonna++) {
            EstraiMin(Matrice, ordine, colonna, Minore);
            DetMin = CalcolaDet(Minore,ordine-1);
            Determinante = Determinante + Segno(colonna) * Matrice[1][colonna] * DetMin;
        }
    return Determinante;

}

void EstraiMin(int IN_Matrice[][ordineMAX], int IN_ordine, int IN_colonna, int OUT_Minore[][ordineMAX]) {
    
    InitMatrice(OUT_Minore, ordineMAX);
    for (int rm = 1; rm < IN_ordine; rm++)
    {
        int cm = 0;
        int cp = 0;
        do {
            if (cm == IN_colonna)
                cm++;
            else {
                OUT_Minore[rm - 1][cp] = IN_Matrice[rm][cm];
                cm++; 
                cp++;
            }    
        } while (cm < IN_ordine);

    }
}
int Matrice2x2(int a11, int a12, int a21, int a22) {

    return ((a11 * a22) - (a12 * a21));
}
int Segno(int numero) {

    if (numero % 2 == 0)
        return -1;
    else
        return +1;
}

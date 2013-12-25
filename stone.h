#include <stdio.h>
#include <stdbool.h>

#define N 20

/*Identifichiamo le cave , in una matrice di interi , con il numero 1.
  Identifichiamo con il numero 2 la tratta.
  Identifichiamo con il numero 3 i blocchi , 4 le steli. Identifichiamo con 0 le posizioni vuote */

typedef struct coord { //Struttura utilizzata nelle funzioni per ritornare le coordinate di una cava , una stele o di un blocco

	int x , y ;

} coordinate ;

typedef struct somme {

	int P , y ;

} somma ;

coordinate siti[2] ; //Vettore utile per la funzione siti_cerimoniali()
int terreno[N][N] ;
coordinate cave* ;
int numero_di_cave=0 ;

void inizializza() ;
bool territorio( char* nomefile ) ; //Ritorna false se non è stato possibile trovare il file , true altrimenti
void nuova_cava( int x , int y ) ;
bool cava_esaurita( int x , int y ) ; //Ritorna true se la cava è stata rimossa , false se tale cava non esiste
int percorrenza_minima() ;
bool siti_cerimoniali() ;
bool sito( sito_struct s , FILE* nomefile ) ;

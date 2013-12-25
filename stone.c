//Codes for an university exam

#include "stone.h"

void inizializza() {

	for ( int i = 0 ; i < N ; i++ ) 
		for ( int j = 0 ; j < N ; j++ )
			terreno[i][j] = 0 ;


}

bool territorio( char* nomefile ) {

	FILE* f ;
	int  i , y , j ; // variabili d'iterazione
	somma sum[N] ;
	int s=0 ; //Vettore per la ricerca della tratta migliore e variabile di somma
	inizializza() ;
	f = fopen( nomefile , "r+" ) ;

	if ( f == NULL ) {

		printf("Errore nell'apertura del file\n") ;
		return false ;

	}

	fscanf( f , "%d" , &numero_di_cave) ;
	cave = (coordinate*) malloc(numero_di_cave*sizeof(coordinate*)) ;
	for ( i = 0 ; i < numero_di_cave ; i++ ) { //Carico le cave da file

		fscanf( f , "%d %d" , &cave[i].x , &cave[i].y ) ;
		terreno[cave[i].x][cave[i].y] = 1 ;

	}

	for ( i = 0 ; i < N ; i++ ) { //Stampo a video il sistema di trasporti con l'aggiornamento delle cave

		for ( j = 0 ; j < N ; j++ ) {

			printf(" %d " , terreno[i][j] ) ;

		}

		printf("\n") ;
	}
	for ( int i = 0 ; i < N ; i++ ) { //Calcolo , attraverso un algoritmo greedy , tutte le possibili tratte

		for ( int y = 0 ; y < n ; y++) {

			if ( cave[y].y > i ) {
				s += cave[y].y - i ;
			}

			else {

				s += i - cave[y].y ;

			}

		}

		sum[i].P = s ;
		sum[i].y = i ;

		s = 0 ;
	}

	for ( i = 0 ; i < N ; i++ ) {

		printf(" %d ",sum[i].P) ;

	}

	int Pmin = sum[0].P , ymin = sum[0].y ;

	for ( i = 0 ; i < N ; i++ ) {

		if ( sum[i].P < Pmin ) {

			Pmin = sum[i].P ;
			ymin = sum[i].y ;

		}
		
	}

	printf(" P = %d , y = %d\n" , Pmin , ymin ) ;
	return true ;

}

void nuova_cava( int x , int y ) {

	cave = (coordinate*) realloc((numero_di_cave++)*sizeof(coordinate*));
	cave[n].x = x ;
	cave[n].y = y ;
	terreno[x][y] = 1 ;
}

bool siti_cerimoniali() {

	int S1 , S2 ; //variabili di sommatoria per i 2 siti
	int x , y , xi ; //variabili di iterazione
	int xa , ya , xb , yb ;
	int j = 0 ;

	for ( x = 0 ; x < N ; x++ ) {

		for ( y = 0 ; y < N ; y++ ) {

			for ( xi = 0 ; xi < numero_di_cave ; xi++) {

				sum[j].P += cave[xi].x - x ;

			}

			j++ ;

		}

	}
}
int main( int argc , char** argv ) {

	territorio( "file.txt" ) ;
	return 0 ;

}

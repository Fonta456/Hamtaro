/*
	Name:
	Copyright:
	Author: Fontana Andrea 3IA
	Date: 13/09/23 07:24
	Description: La numerosa famiglia degli Hamtaro, composta da N criceti, ha prenotato un tavolo in una nota pizzeria. I membri si danno appuntamento presso un autonoleggio con M automobili a disposizione per raggiungere successivamente la pizzeria. Purtroppo gli Hamtaro non arrivano al volante e quindi devono pagare generosamente l'unico autista a disposizione dell'autonoleggio in quel momento. Nell'ambiente dei cartoni gli Hamtaro sono notoriamente dei taccagni e vogliono perciò spendere il meno possibile per la serata, pena il passare la cena a pianger miseria.
				Ogni automobile ha solo il carburante necessario per un viaggio autonoleggio-pizzeria-autonoleggio e non esistono distributori di carburante in zona: per cui dopo un viaggio con un'automobile i, l'automobile i rimane a secco e non può più essere usata.
				L'automobile i permette il trasporto di Pi membri della famiglia degli Hamtaro, al costo di Ei euro per criceto. Gli Hamtaro scelgono, ad ogni partenza, un'automobile tra quelle disponibili (tra quelle, cioè, non usate precedentemente) e l'autista la usa per accompagnare una parte di loro in pizzeria.
				Aiuta la famiglia a risparmiare indicandole qual è la minima cifra che dovrà spendere per far arrivare tutti gli N Hamtaro in pizzeria!

	ANALISI
	-Chiedo all'utente quanti criceti ci sono
	-chiedo all'utente il numero delle auto disponibili
	-chiedo all'utente il costo e i posti per ogni singola macchina
	-infine ritorno il costo totale migliore

	IPOTESI
	-il numero dei criceti deve essere compreso tra 1 e 4000
	-il numero delle macchine deve essere compreso tra 1 e 4000
	-il costo della macchina deve essere compreso tra 1 e 1000
	-il numero dei posti della macchina deve essere compresa tra 1 e 1000

	DATI INPUT
	-n (int): numero dei criceti
	-m (int): numero delle macchine
	-struct (macchina)
		*costo (int): costo per una singola macchina
		*posti (int): posti totali per ogni singola macchina

	DATI OUTPUT
	migliore (int): costo migliore per i criceti

	COSTANTI
	-MAX1 (int): 4000
	-MAX2 (int): 1000
	-MIN (int): 1

	VARIABILI
	-n (int): numero di criceti
	-m (int): numero di macchine
	-c (int): variabile contente il costo più conveniente
	
	
	DATI TEST
	IN	IN		OUT
	2	4		2
	2	1
	2	1
	1	5
	1	4
	-----------------
	7	5		42	
	10	3
	2	2
	4	1
	8	3
	16	6


*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX1 4000
#define MAX2 1000
#define MIN 1

typedef struct {
	int costi;
	int posti;
	
} Macchina;

int leggiCompreso (int, int);
int conveniente (Macchina[], int, int, int);

int main () {
	srand(time(0));
	int n = leggiCompreso(MIN,MAX1);
	int m = leggiCompreso(MIN,MAX1);

	Macchina macchina[MAX1];

	for(int i=0; i<m; i++) {
		macchina[i].costi=leggiCompreso(MIN,MAX2);
		macchina[i].posti=leggiCompreso(MIN,MAX2);
	}
	
	/*
	for(i=0; i\m; i++){
		printf("%d", macchina[i].costi);
		printf("%d", macchina[i].posti);
		
	}
	*/

	int c=costof(macchina,n,m);
	printf("%d", c);

	return 0;
}


int leggiCompreso (int min, int max) {
	int compreso;
	do {
		scanf("%d", &compreso);
		if(compreso<min || compreso>max) {
			printf("non e' compreso tra %d e %d\n", min,max);
		}
	} while(compreso<min || compreso>max);
	return compreso;
}

int casualeTra (int max, int min){
	if(max==min) return max;
	if(max<min){
		int t=max;
		max=min;
		min=t;
	}
	return (rand()%(max-min)+min);
}

void ordinaExSort (Macchina macchina[], int n){
	int i,j;
	Macchina temp;
	for(i=0; i<n; i++){
		for(j=i+1;j<n;j++){
			if(macchina[i].costi>macchina[j].costi){
				temp=macchina[i];
				macchina[i]=macchina[j];
				macchina[j]=temp;
			}
		}
	}
}


int costof(Macchina macchina[], int n, int m){
	int costof=0;
	ordinaExSort(macchina,m);
	int i=0;
	do{
		if(macchina[i].posti>n){
			costof=costof+(macchina[i].costi*n);
			n=n-macchina[i].posti;
		}else{
			costof=costof+(macchina[i].costi*macchina[i].posti);
			n=n-macchina[i].posti;
		}
		i++;
	}while(n>=0);
	return costof;	
}





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





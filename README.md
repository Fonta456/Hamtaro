
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


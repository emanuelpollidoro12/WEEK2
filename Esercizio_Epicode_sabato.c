#include <stdio.h>
#include <string.h>
void menu ();
void moltiplica ();
void dividi ();
void ins_string();


int main () 

{
	char scelta = {'\0'};
	int i;
	i = 0; 
	menu ();
	scanf ("%c", &scelta); // primo caso qui inserndo una cosa diversa da A,B,C il programma termina.
	while(scelta!='A' && scelta!='B' && scelta!='C' ){
	printf("ATTENZIONE INSERSCI UN VALORE ESATTO!!!\n"); // viene mostrata a video questa scritta in caso di errore nella scelta
	fflush(stdin); // pulisce il buffer del input
	menu(); // ripropone la funzione menu con le scelte
	scanf("%c",&scelta); // per rinserire la scelta
	}
	switch (scelta)
	{
		case 'A':
		moltiplica();
		break;
		case 'B':
                dividi();
                break;
		case 'C':
                ins_string();
                break;
	}

return 0;

}


void menu ()
{
	printf ("Benvenuto, sono un assitente digitale, posso aiutarti a sbrigare alcuni compiti\n");
	printf ("Come posso aiutarti?\n");
	printf ("A >> Moltiplicare due numeri\nB >> Dividere due numeri\nC >> Inserire una stringa\n");

}


void moltiplica ()
{	short int a; 
	int j;
	short int b;
	short int prodotto; 
	int prova_a;
	int prova_b;
	j=0;
	do{
	printf ("Inserisci i due numeri da moltiplicare:\n");
	fflush(stdin);
	prova_a=scanf ("%hd", &a); // facendo cosi assegniamo a prova_a il valore del funzione scanf di a quindi in caso di insrimento di una lettera il risultato sara 1
	prova_b=scanf ("%hd", &b); // stessa cosa per b
	if(prova_a==0 || prova_b==0) // qui controlliamo se il valore della funzione scanf sia 0 se invece fosse 1 procede con la moltiplicazione
	{
		printf ("ATTENZIONE SONO CONSENTITI SOLO NUMERI INTERI!!!\n");	 // messaggio per l'errore
	}
	else if(a>180 || b>180 || a<-180 || b<-180){ // con questo controllo faccio in modo che l'utente possa moltiplicare al massimo i numeri consentiti dallo short int
	printf ("ATTENZIONE PUOI MOLTIPLICARE AL MASSIMO 180*180!!!\n");
	}
	else{
		prodotto= a*b;
		printf ("Il prodotto tra %hd e %hd e': %hd", a,b,prodotto);
		j++; //contatore per uscire dal while in caso lui inserisca numeri troppo grandi per lo short int	
	}
}while(prova_a==0 || prova_b==0 || j==0); // qui in caso di valore 1 della funzione scanf uscira dal while oppure in caso di 0 riparte il ciclo o se j e 1
}


void dividi ()
{
        int a;
        int prova_a;
        int prova_b;
        int b;
		int divisione;
		do{
	fflush(stdin);
	printf("inserisci numeratore\n");
	prova_a=scanf ("%hd", &a);
	printf("inserisci denominatore\n");
	prova_b=scanf ("%hd", &b); 
	if(prova_a==0 || prova_b==0) 
	{
		printf ("ATTENZIONE SONO CONSENTITI SOLO NUMERI INTERI!!!\n");	 
	}
	else{
		divisione = a / b;
		printf ("La divisione tra %hd e %hd e': %hd", a,b,divisione);
		}
		}while(prova_a==0 || prova_b==0);
}




void ins_string () 
{
	char stringa[10];
        printf ("Inserisci la stringa:");
        fflush(stdin);
		fgets(stringa,10,stdin); // facendo questo anche in caso l' utente scriva stringa piu' grande di quella possibile lui la tronca
        printf("la tua stinga e' %s",stringa);
}

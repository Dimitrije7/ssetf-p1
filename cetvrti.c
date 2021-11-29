/**
 * Zadatak: 29.11.2018., prvi kolokvijum iz Programiranja 1
 * Organizacija: SSETF
 * Autor: Dimitrije Obradovic
*/

#include <stdio.h>

int main()
{
    /**
    * Napisati program u programskom
    * jeziku C (dozvoljeno je korištenje funkcija samo iz
    * stdio.h) koji učitava broj x (x∊R) i prirodan broj k
    * (k>2), a zatim iterativno računa i ispisuje k-ti član,
    * pri čemu važi sledeće:
    * 
    * X1=x, X2=x+1, Xi+1=Xi-1*(i^(2i-1))/(Xi*(i!))
    */

   double x;
   int k;

   double xn_a;//Xi-1
   double xn_b;//Xi
   double xn_c;//Xi+1

   int i=3;//brojac do k

   printf("Unesite broj x:");
   scanf("%lf",&x);

   //obezbjedjujemo da se unese broj k prema uslovu zadatka
   //petlja se izvrsava dok god unosimo k koje je manje ili jednako 2
   //kada unesemo k>2 petlja se prekida i u k ostaje pohanjena zadnja unesena vrijednost
   //koja je sigurno veca od 2
   do
   {
       printf("Unesite broj iteracija: ");
       scanf("%d",&k);
   } while (k<=2);

   //prema postavci zadatka
   xn_a=x;
   xn_b=x+1;
   
   while (i<=k)
   {
       long long int pom_br=0;//pomocni brojac za racunanje stepena i faktorijela
       long long int stepen_n=1;
       long long int fakt_n=1;

       //racunanje i^(2*i-1)
       while(pom_br<2*i-1)
       {
           stepen_n*=i;
           pom_br++;
       }

       //resetujemo brojac
       pom_br=1;

       //racunanje i!
       while(pom_br<=i)
       {
           fakt_n*=pom_br;
           pom_br++;
       }

       //racunamo Xn+1
       xn_c=xn_a*stepen_n/(xn_b*fakt_n);

       //vrsimo zamjene za sledecu iteraciju
       xn_a=xn_b;
       xn_b=xn_c;

       //inkrement brojaca koji prolazi do k
       i++;
   }

   //Ispis trazenog broja
   printf("Broj je: %lf\n",xn_c);
   
}
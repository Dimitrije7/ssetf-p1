/**
 * Zadatak: 29.11.2018., prvi kolokvijum iz Programiranja 1
 * Organizacija: SSETF
 * Autor: Dimitrije Obradovic
*/
#include <stdio.h>

int main()
{
    /**
     * Tekst zadataka:
     *  Napisati program koji u programskom jeziku ce
     *  učitava prirodne brojeve a, b (a<b) i
     *  c (c<10), a zatim ispisuje brojeve iz segmenta
     *  [a,b] koji sadrže cifru c, te ukupan broj takvih
     *  (ispisanih) brojeva.
    */

   //granice intervala koji se trazi u zadatku
   int a=0;
   int b=0;

   //cifra koja se trazi u brojevima iz intervala [a,b]
   int c=0;

   //brojac koji inkrementujemo svaki put kada naidjemo na broj koji u sebi sadrzi cifu 'c'
   int broj_brojeva=0;
   //pomocna promjenjiva za pohranjivanje k-tog broja iz intervala [a,b] kroz koji prolazimo petljom
   int temp_broj=0;
   //pomocna promjenjiva u koju skladistimo broj koji provjeravamo u trenutnoj iteraciji
   int cifra=0;
   //promjenjiva koja ako je razlicita od nule pokazuje da smo naisli na broj koji sadrzi cifru c
   int flag=0;

   //obezbjedjujemo korektne vrijednosti za granice intervala: a mora biti manje od b i a,b>0
   while(a>=b || a<=0 || b<=0)
   {
       printf("Unesite donju granicu intervala:");
       scanf("%d",&a);

       printf("Unesite gornju granicu intervala:");
       scanf("%d",&b);
   }

   //petlja za provjeru i unos cifre koju trazimo u brojevima iz intervala [a,b]
   do
   {
       printf("Unesite cifru koju zelite da nadjete:");
       scanf("%d",&c);
   } while (c>=10);
   
   //petlja kojom prolazimo kroz sve brojeve iz intervala [a,b]
   //petlja koristi C99 standard, promjenjiva 'i' se moze deklarisati i van petlje 
   for(int i=a;i<=b;++i)
   {
       //pohranjujemo trenutnu vrijednost iz intervala u temp_broj da ne bi poremetili vrijednost brojaca
       temp_broj=i;
       //resetovanje flaga koji nam pokazuje detekciju cifre u broju iz intervala na 0
       flag=0;

       //prolazimo kroz cifre broja
       while(temp_broj>0)
       {
           //uzimamo zadnju cifru
           cifra=temp_broj%10;
           
           //provjeravamo da li je cifra ista kao trazena cifra 'c'
           if(cifra==c)
           {
               //setujemo flag na 1, tj oznacavamo da smo nasli cifru u nasem broju
               flag=1;
           }

           //odbijamo zadnju cifru iz broja da bi smo obezbjedili da se u sledecoj iteraciji provjeri sledeca
           //cifra koja dolazi poslije one koja je provjerena u trenutnoj iteraciji
           //ovaj korak obezbjedjuje da se petlja terminise kada temp_broj padne na nulu, sto znaci da smo
           //provjerili sve cifre
           temp_broj/=10;
       }

       //ispitujemo da li imamo detektovanu cifru u broju 'i'
       if(flag>0)
       {
           printf("Trazena cifra je pronadjena u broju %d\n",i);
           broj_brojeva++;
       }
   }

   printf("Broj brojeva iz intervala [%d,%d] koji sadrze cifru %d je %d\n",a,b,c,broj_brojeva);
   
   return 0;
}
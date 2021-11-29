/**
 * Zadatak: 12.10.2020., pismeni ispit iz Programiranja 1
 * Organizacija: SSETF
 * Autor: Dimitrije Obradovic
*/

#include <stdio.h>

int main()
{
    /**
     *  Napisati program u programskom jeziku C
     *  koji učitava prirodne brojeve a i b, a zatim ispisuje sve
     *  brojeve iz intervala <a,b> za koje važi pravilo da se
     *  izbacivanjem svih cifara osim krajnje leve cifre i krajnje
     *  desne cifre tog broja dobije prost broj.
    */

   //granice intervala na kojem provjeravamo brojeve
   int a=0;
   int b=0;

   //trazeni broj iz zadatka je ocigledno dvocifren pa nam trebaju promjenjive
   //u koje cemo uskladistiti te dve cifre
   int zadnja_cifra=0;
   int prva_cifra=0;

   //broj koji formiramo pomocu 'zadnja_cifra' i 'prva_cifra'
   int broj=0;

   //pomocna varijabla u koju skladistimo broj iz trenutne iteracije pri prolasku kroz interval [a,b]
   int temp=0;

   //broj djelilaca broja 'broj' koji formiramo od 'zadnja_cifra' i 'prva_cifra'
   int broj_dl=0;

   //obezbjedjujemo korektne vrijednosti za granice intervala: a mora biti manje od b i a,b>0
   while(a>=b || a<=0 || b<=0)
   {
       printf("Unesite donju granicu intervala:");
       scanf("%d",&a);

       printf("Unesite gornju granicu intervala:");
       scanf("%d",&b);
   }

   for(int i=a;i<=b;++i)
   {
       //resetujemo broj djelilaca da bi smo mogli ispitati vrijednost broja 'i' iz intervala [a,b]
       //u trenutnoj iteraciji petlje, polazimo od pretpostavke da ce broj biti prost pa resetujemo
       //broj_dl na 2 jer je svaki prost broj djeljiv samo sa 1 i sa samim sobom
       broj_dl=0;

       //uzimamo zadnju cifru broja
       zadnja_cifra=i%10;
       //pohranjujemo vrijednost broja koji ispitujemo u pomocnu promjenjivu
       temp=i;

       //odbijamo redom cifre od zadnje prema prvoj dok ne ostane samo najteza cifra
       //u opstem slucaju ovo mozemo raditi n puta jer ne znamo koliko cifara ima broj
       //zaustavljamo se kada 'temp' postane manje od 10 sto znaci da smo dobili jednocifren broj
       //odnosno samo prvu cifru 
       while (temp>=10)
       {
           //u svakoj iteraciji odbijamo po jednu cifru broja pocevsi od najlakse
           temp/=10;
       }

       //ono sto ostane nakon prethodne petlje je najteza, odnosno krajnja lijeva cifra
       prva_cifra=temp;

       //formiramo dvocifren broj
       if(i>=0 && i<=9)
       {
           //u slucaju da je nas broj jednocifren krajnja lijeva i krajnja desna cifra je cifra sa iste tezine
           //tako da je trazeni broj u stvari broj 'i'
           broj=i;
       }
       else
       {
           //ako broj i nije jednocifren formiramo 'broj' na sledeci nacin
           broj=prva_cifra*10+zadnja_cifra;
       }

       //brojac kojim cemo prolaziti kroz djelioce broja 'broj'
       int d=1;

       //ispitujemo koliko dijelilaca broj ima
       while(d<=broj)
       {
           if(broj%d==0)
           {
               broj_dl++;
           }
           d++;
       }

       if(broj_dl==2)
       {
           printf("Prost broj je %d, formiran od %d\n",broj,i);
       }
   }

    return 0;
}
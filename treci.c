/**
 * Zadatak: 29.11.2016., prvi kolokvijum iz Programiranja 1
 * Organizacija: SSETF
 * Autor: Dimitrije Obradovic
*/

#include <stdio.h>

int main()
{
    /**
     *  Napisati program u programskom jeziku C
     *  koji učitava dva prirodna broja a i b
     *  (a<b), a zatim računa i ispisuje elemente niza
     *  Sa,Sa+1,...,Sb-1,Sb, pri čemu je:
     * 
     * Sn=1/(1/2)+2^2/(1/2+2/3)+3^3/(1/2+2/3+3/4)+...+(n^n)/(1/2+...+n/(n+1))
    */

   //granice intervala na kojem racunamo clanove
   int a=0;
   int b=0;

   //promjenjiva u koju cemo skladistiti opsti clan pomocu kojeg formiramo Sn, buduci da je svaki broj Sn koji predstavlja
   //clan niza koji ide od Sa do Sb u stvari suma sa opstim clanom (n^n)/(1/2+...+n/(n+1)) pri cemu
   //suma ide (ima granice) od 1 do n
   float opsti_clan=0;

   //buduci da je opsti clan u stvari razlomak mozemo ga dobiti tako sto cemo izracunati njegov imenilac
   // i brojilac pa ih podijeliti i smjestiti u 'opsti_clan'

   //brojilac opsteg clana
   long long int brojilac=0;
   //imenilac opsteg clana
   //sam imenilac opsteg clana se takodje formira kao suma sa opstim clanom n/(n+1)
   float imenilac=0;

   //promjenjiva u koju cemo smjestiti clan niza odnosno Sn
   float s_n=0;

   //obezbjedjujemo korektne vrijednosti za granice intervala: a mora biti manje od b i a,b>0
   while(a>=b || a<=0 || b<=0)
   {
       printf("Unesite donju granicu intervala:");
       scanf("%d",&a);

       printf("Unesite gornju granicu intervala:");
       scanf("%d",&b);
   }

   printf("Ispisujemo clanove niza na intervalu [%d,%d]:\n",a,b);

   //petlja kojom prolazimo kroz interval [a,b], tj. ciji brojac redom uzima vrijednosti a,a+1,a+2,...,b-1,b
   //svaku od vrijednosti brojaca obradjujemo tj. racunamo za nju clan Sn
   for(int i=a;i<=b;++i)
   {
       //resetujemo vrijednosti pomocnih promjenjivih koje nam sluze za racunanje elementa niza Sn
       s_n=0;
       opsti_clan=0;

       //pomocna promjenjiva za racunanje stepena
       int pom_st=0;
       
       //formiranje opsteg clana za sumu koja predstavlja u stvari clan niza Sn
       for(int j=1;j<=i;++j)
       {
           //postavljamo brojilac na pocetnu vrijednost za racunanje stepena
            brojilac=j;
            //postavljanje imenioca na pocetnu vrijednost za racunanje sume koja ga formira
            imenilac=0;
           
           //racunanje brojioca opsteg clana
           while (pom_st<j)
           {
               brojilac*=j;
               pom_st++;
           }
           
           //racunanje sume kojom se formira imenilac opsteg clana
           for(int k=1;k<=j;++k)
           {
               imenilac+=((float)k)/(k+1);
           }

           //racunanje ospteg clana
           opsti_clan=brojilac/imenilac;
           //dodavanje opsteg clana u sumu
           s_n+=opsti_clan;
       }

       //ispis elementa niza
       printf("%f\n",s_n);
   }

   return 0;
}
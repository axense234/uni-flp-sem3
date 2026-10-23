#include "lista.h"
#include <iostream>

int main()
{
   // Lista l, l1, l2;
   // l = creare();
   // tipar(l);

   Lista l1, l2;
   // 7
   std::cout << "l1: \n";
   l1 = creare();
   std::cout << "l2: \n";
   l2 = creare();

   // a)
   std::cout << egalitate_liste(l1, l2) << std::endl;
   // b)
   Lista rez = intersectare_liste(l1, l2);

   // clean
   distruge(rez);
   distruge(l1);
   distruge(l2);

   // tests
   test_intersectare_liste();
   test_egalitate_liste();
}

/*
a)
lists_equality(L1L2...Ln, S1S2...Sm):
- true, if n=m=0,
- false, if (n=0 and m!=0) or (n!=0 and m=0)
- false, if (L1 != S1)
- (L1 == S1) && lists_equality(L2L3...Ln, S2S3...Sm) otherwise

b)
lists_intersections(L1L2...Ln, S1S2...Sm):
- {}, if n = 0 or m = 0
- {L1} U lists_intersections(L2L3...Ln, S1S2...Sm),
   if L1 is member of S1S2...Sm
- lists_intersections(L2L3...Ln, S1S2...Sm) otherwise
*/
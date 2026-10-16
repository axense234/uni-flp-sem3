#include "lista.h"
#include <iostream>

using namespace std;

PNod creare_rec()
{
  TElem x;
  cout << "x=";
  cin >> x;
  if (x == 0)
  {
    return NULL;
  }
  else
  {
    PNod p = new Nod();
    p->e = x;
    p->urm = creare_rec();
    return p;
  }
}

Lista creare()
{
  Lista l;
  l._prim = creare_rec();
  return l;
}

void tipar_rec(PNod p)
{
  if (p != NULL)
  {
    cout << p->e << " ";
    tipar_rec(p->urm);
  }
}

void tipar(Lista l)
{
  tipar_rec(l._prim);
}

void distruge_rec(PNod p)
{
  if (p != NULL)
  {
    distruge_rec(p->urm);
    delete p;
  }
}

void distruge(Lista l)
{
  // se elibereaza memoria alocata nodurilor listei
  distruge_rec(l._prim);
}

bool egalitate_liste(Lista l, Lista s)
{
  if (l._prim == NULL && s._prim == NULL)
  {
    return true;
  }

  if (l._prim == NULL && s._prim != NULL)
  {
    return false;
  }

  if (l._prim != NULL && s._prim == NULL)
  {
    return false;
  }
  if (l._prim->e != s._prim->e)
  {
    return false;
  }

  TElem v1 = l._prim->e, v2 = s._prim->e;
  l._prim = l._prim->urm;
  s._prim = s._prim->urm;

  return (v1 == v2) && egalitate_liste(l, s);
}

void intersectare_liste(Lista l, Lista s)
{
  if (l._prim == NULL || s._prim == NULL)
  {
    return;
  }

  PNod tempS = s._prim;
  while (tempS != NULL)
  {
    if (l._prim->e == tempS->e)
    {
      TElem v = l._prim->e;

      l._prim = l._prim->urm;

      std::cout << v << ' ';
      intersectare_liste(l, s);
    }
    tempS = tempS->urm;
  }
  l._prim = l._prim->urm;
  intersectare_liste(l, s);
}
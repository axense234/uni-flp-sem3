#include "lista.h"
#include <iostream>
#include <cassert>

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

bool este_membru(PNod s, TElem x)
{
  for (PNod p = s; p != NULL; p = p->urm)
    if (p->e == x)
      return true;
  return false;
}

Lista intersectare_liste(Lista l, Lista s)
{
  Lista rez;
  rez._prim = NULL;
  PNod *tail = &rez._prim;

  for (PNod p = l._prim; p != NULL; p = p->urm)
  {
    if (este_membru(s._prim, p->e))
    {
      PNod nou = new Nod();
      nou->e = p->e;
      nou->urm = NULL;
      *tail = nou;
      tail = &nou->urm;
    }
  }
  return rez;
}

void test_intersectare_liste()
{
  // first list
  Lista l;
  PNod p1 = new Nod();
  p1->e = 3;
  PNod p2 = new Nod();
  p2->e = 4;
  PNod p3 = new Nod();
  p3->e = 5;
  l._prim = p1;
  l._prim->urm = p2;
  l._prim->urm->urm = p3;

  // second list
  Lista s;
  PNod p4 = new Nod();
  p4->e = 4;
  PNod p5 = new Nod();
  p5->e = 5;
  PNod p6 = new Nod();
  p6->e = 6;
  s._prim = p4;
  s._prim->urm = p5;
  s._prim->urm->urm = p6;

  Lista rez = intersectare_liste(l, s);
  assert(rez._prim->e == l._prim->urm->e);
  assert(rez._prim->urm->e == l._prim->urm->urm->e);

  distruge(l);
  distruge(s);
}

void test_egalitate_liste()
{
  // first list
  Lista l;
  PNod p1 = new Nod();
  p1->e = 3;
  PNod p2 = new Nod();
  p2->e = 4;
  PNod p3 = new Nod();
  p3->e = 5;
  l._prim = p1;
  l._prim->urm = p2;
  l._prim->urm->urm = p3;

  // second list
  Lista s;
  PNod p4 = new Nod();
  p4->e = 3;
  PNod p5 = new Nod();
  p5->e = 4;
  PNod p6 = new Nod();
  p6->e = 5;
  s._prim = p4;
  s._prim->urm = p5;
  s._prim->urm->urm = p6;

  bool rez = egalitate_liste(l, s);
  assert(rez);

  distruge(l);
  distruge(s);
}
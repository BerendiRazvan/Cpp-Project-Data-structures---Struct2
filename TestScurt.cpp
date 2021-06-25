#include <assert.h>
#include <exception>
#include <iostream>
#include "TestScurt.h"
#include "LI.h"
#include "IteratorLI.h"

using namespace std;

void testAll() {
    LI lista = LI();
    assert(lista.vida());

    lista.adaugaSfarsit(1);
    
    
    assert(lista.dim() == 1);

    lista.adauga(0,2);
    assert(lista.dim() == 2);

    IteratorLI it = lista.iterator();
    assert(it.valid());

    
    it.urmator();
    
    assert(it.element() == 1);
    it.prim();
    assert(it.element() == 2);
    assert(lista.cauta(1) == 1);
    assert(lista.modifica(1,3) == 1);
    assert(lista.element(1) == 3);
    assert(lista.sterge(0) == 2);
    assert(lista.dim() == 1);

}

void testareFctLab() {
    LI lista = LI();
    assert(lista.vida());

    for (int i = 1; i <= 50; i++)
        lista.adaugaSfarsit(i);
    assert(lista.dim() == 50);
    assert(lista.stergeK(10) == 5);
    assert(lista.dim() == 45);

    try {
        lista.stergeK(50);
        assert(false);
    }
    catch (exception) {
        assert(true);
    }

}

void testareFctLab2() {
    LI lista = LI();
    assert(lista.vida());

    for (int i = 1; i <= 50; i++)
        lista.adaugaSfarsit(i);


    assert(lista.ultimulIndex(55)==-1);
    assert(lista.ultimulIndex(50) == 49);
    assert(lista.ultimulIndex(55) == -1);
    assert(lista.ultimulIndex(1) == 0);
    assert(lista.ultimulIndex(2020) == -1);
    assert(lista.ultimulIndex(3) == 2);
    assert(lista.ultimulIndex(-20) == -1);
}
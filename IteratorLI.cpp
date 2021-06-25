#include "IteratorLI.h"
#include "LI.h"
#include <exception>
#include <iostream>

using namespace std;


IteratorLI::IteratorLI(const LI& li): lista(li) {
 	/* Complexitate: 0(1) */
    this->elemCurent = li.prim; //lista.prim sau li.prim???
}

void IteratorLI::prim(){
    /* Complexitate: 0(1) */
    this->elemCurent = lista.prim;
}

void IteratorLI::urmator(){
    /* Complexitate: 0(1) */
    if (valid() == false)
        throw exception();
    this->elemCurent = this->elemCurent->urmator();

}

bool IteratorLI::valid() const{
    /* Complexitate: 0(1) */
    return (elemCurent != nullptr);
}


TElem IteratorLI::element() const{
    /* Complexitate: 0(1) */
    if (valid() == false) 
        throw exception();
    return elemCurent->element();
}

#include <exception>
#include <iostream>
#include "LI.h"
#include "IteratorLI.h"

using namespace std;


Nod::Nod(TElem e, PNod urm, PNod prec) {
	/* Complexitate: 0(1) */
    this->e = e;
    this->urm = urm;
    this->prec = prec;
}

TElem Nod::element() {
	/* Complexitate: 0(1) */
    return e;
}

PNod Nod::urmator() {
	/* Complexitate: 0(1) */
    return urm;
}

PNod Nod::precedent() {
	/* Complexitate: 0(1) */
    return prec;
}


LI::LI() {
	/* Complexitate: 0(1) */
	this->prim = nullptr;
	this->ultim = nullptr;
}

int LI::dim() const {
	/* Complexitate: 0(n) */
	int i = 0;
	PNod p=this->prim;
	while (p != nullptr) {
		p = p->urm;
		i++;
	}
	return i;
}


bool LI::vida() const {
	/* Complexitate: 0(n) */
	if (dim() == 0) {
		return true;
	}
	return false;
}

TElem LI::element(int i) const {
	/* Complexitate: O(n) */
	if (i < 0 || i >= dim())
		throw exception();

	PNod p = this->prim;
	for (int k = 0; k < i; k++) {
		p = p->urm;
	}
	return p->e;
}

TElem LI::modifica(int i, TElem e) {
	/* Complexitate: O(n) */
	if (i<0 || i>=dim())
		throw exception();

	PNod p = this->prim;
	for (int k = 0; k < i; k++) {
		p = p->urm;
	}
	TElem valVeche = p->e;
	p->e = e;
	return valVeche;
}

void LI::adaugaSfarsit(TElem e) {
	/* Complexitate: 0(1) */

	PNod nou = new Nod(e, nullptr, nullptr);
	
	if (prim == nullptr) {
		prim = nou;
		ultim = nou;
	}
	else {
		// adaug ultimul element
		ultim->urm = nou;
		nou->prec = ultim;
		ultim = nou;
	}

}

void LI::adauga(int i, TElem e) {
	/* Complexitate: O(n) */
	
	if (i<0 || i>=dim())
		throw exception();

	PNod nou = new Nod(e, nullptr, nullptr);
	//lista e vida
	if (prim == nullptr) {
		prim = nou;
		ultim = nou;
		return;
	}
	
	//parcurgere pana la i
	PNod p = this->prim;
	for (int k = 0; k < i; k++) {
		p = p->urm;
	}

	//prima pozitie
	if (p == prim) {
		prim->prec = nou;
		nou->urm = prim;
		prim = nou;
		return;
	}

	//adaugare normala
	nou->urm = p;
	nou->prec = p->prec;
	p->prec->urm = nou;
	p->prec = nou;
}

TElem LI::sterge(int i) {
	/* Complexitate: O(n) */

	if (i<0 || i>=dim())
		throw exception();
	
	PNod p = this->prim;
	for (int k = 0; k < i; k++) {
		p = p->urm;
	}
	TElem valVeche = p->e;

	//un element
	if (dim() == 1) {
		this->prim = nullptr;
		this->ultim = nullptr;
	}

	//primul element
	if (i == 0 && dim() > 1) {
		p->urm->prec = nullptr;
		prim = p->urm;
	}

	//ultimul element
	if (p == ultim && dim() > 1) {
		p->prec->urm = nullptr;
		ultim = p->prec;
	}

	//stergere normala
	if (i > 0 && i < dim() - 1) {
		p->prec->urm = p->urm;
		p->urm->prec = p->prec;
	}
	delete p;

	return valVeche;
}

int LI::cauta(TElem e) const {
	/* Complexitate: O(n) */

	PNod p = this->prim;
	for (int i = 0; i < dim(); i++) {
		if (p->e == e) {
			return i;
		}
		p = p->urm;
	}
	return -1;
}



int LI::stergeK(int k) {
	/*
	Pre: k:int
	Post: stergeri:int

	Algoritm stergeK(int k)

		Daca k<2 sau k>=dim() atunci
			arunca exceptie
		SfDaca

		i<-0
		stergeri<-0

		CatTimp i<dim() executa
			sterge(i)
			stergeri<-stergeri+1
			i<-i+k
		SfCatTimp

		stergeK(int k)<-stergeri //returneaza rezultat

	SfAlgoritm

	Complexitate: O(n)
	*/

	if(k<2||k>=dim())
		throw exception();

	int i = 0, stergeri = 0;
	while (i < dim()) {
		sterge(i);
		stergeri++;
		i = i + k;
	}
	return stergeri;
}




int LI::ultimulIndex(TElem elem) const {
	/*
	Pre: elem:TElem
	Post: i:int

	Algoritm ultimulIndex(TElem elem)

		Pentru i=dim()-1, 0, -1 executa
			Daca [p].e=elem atunci
				ultimIndex(TElem elem)<-i
			SfDaca
			p<-[p].prec
		SfPentru

	SfAlgoritm

	Complexitate: O(n)

	*/
	PNod p = this->ultim;
	for (int i = dim()-1; i >= 0; i--) {
		if (p->e == elem) {
			return i;
		}
		p = p->prec;
	}
	return -1;

}

IteratorLI LI::iterator() const {
	/* Complexitate: 0(1) */
	return  IteratorLI(*this);
}

LI::~LI() {
	/* Complexitate: 0(n) */
	while (prim != nullptr) {
		PNod p = prim;
		prim = prim->urm;
		delete p;
	}
}


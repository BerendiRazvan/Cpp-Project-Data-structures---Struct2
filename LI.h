#pragma once


class IteratorLI;
typedef int TElem;


//referire a clasei Nod

class Nod;

//se defineste tipul PNod ca fiind adresa unui Nod

typedef Nod* PNod;

class Nod {
public:

	friend class LI;

	//constructor
	Nod(TElem e, PNod urm, PNod prec);
	TElem element();
	PNod urmator();
	PNod precedent();


private:
	TElem e;
	//cele doua legaturi - lista  dublu inlantuita
	PNod urm, prec;

};




class LI {
private:
    friend class IteratorLI;
    /* aici e reprezentarea */
	PNod prim, ultim;
	

public:
 		// constructor implicit
		LI ();
		
		// returnare dimensiune
		int dim() const;

		// verifica daca lista e vida
		bool vida() const;

		// returnare element
		//arunca exceptie daca i nu e valid
		TElem element(int i) const;

		// modifica element de pe pozitia i si returneaza vechea valoare
		//arunca exceptie daca i nu e valid
		TElem modifica(int i, TElem e);

		// adaugare element la sfarsit
		void adaugaSfarsit(TElem e);

		// adaugare element pe o pozitie i 
		//arunca exceptie daca i nu e valid
		void adauga(int i, TElem e);

		// sterge element de pe o pozitie i si returneaza elementul sters
		//arunca exceptie daca i nu e valid
		TElem sterge(int i);

		// cauta element si returneaza prima pozitie pe care apare (sau -1)
		int cauta(TElem e)  const;

		//sterge aparitiile elementelor din k in k
		//returneaza cate stergeri s-au facut
		//k-invalid, atunci arunca exceptie
		int stergeK(int k);


		//Returneaza ultimul index al elementului
		//returneaza -1 daca elementul nu exista
		int ultimulIndex(TElem e) const;

		// returnare iterator
		IteratorLI iterator() const;

		//destructor
		~LI();

};

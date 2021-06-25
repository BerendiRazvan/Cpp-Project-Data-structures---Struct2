#include <iostream>

#include "TestScurt.h"
#include "TestExtins.h"

int main(){
    testAll();
    testAllExtins();
    testareFctLab();
    testareFctLab2();

    std::cout<<"Finished LI Tests!"<<std::endl;
    
    return 0;
}

/*
-------------------------------------------------------------------------------------------------------------------------------------------------------------

Sa se implementeze in C++ un anumit container de date (TAD) folosind o anumita
reprezentare (indicata) si o lists inlantuita (LSI – lista simplu inlantuita, LDI – lista dublu inlantuita)
ca structura de date, cu alocare dinamica pentru memorarea inlantuirilor.

-------------------------------------------------------------------------------------------------------------------------------------------------------------

P12. TAD Lista indexata (interfata cu indici) – reprezentare folosind o LDI.

-------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
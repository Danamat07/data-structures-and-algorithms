//ADT SortedMultiMap – repräsentiert mithilfe einer SLLA mit eindeutigen Schlüsseln
//(key) und sortiert mithilfe einer Relation auf den Schlüsseln (key). Für jeden Schlüssel
//speichert man eine SLLA von Werten (value).

#include <iostream>

#include "ShortTest.h"
#include "ExtendedTest.h"

int main(){
    testAll();
    testAllExtended();

    std::cout<<"Finished SMM Tests!"<<std::endl;
    system("pause");
}
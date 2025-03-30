// ADT SortedBag – mit Elementen vom Typ TComp repräsentiert mithilfe eines
//dynamischen Arrays, sortiert mithilfe einer Relation auf den Elementen

#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <iostream>
#include "ShortTest.h"
#include "ExtendedTest.h"

using namespace std;

int main() {
    testAll();
    testAllExtended();
    cout << "Test over" << endl;
    system("pause");
}
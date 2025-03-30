//ADT Map – repräsentiert mithilfe einer Hashtabelle mit offener Adressierung, mit
// quadratischem Sondieren

#include "ExtendedTest.h"
#include "ShortTest.h"
#include "Map.h"

#include <iostream>
using namespace std;

int main() {
    testAll();
    testAllExtended();
    cout << "That's all!" << endl;
    system("pause");
    return 0;
}
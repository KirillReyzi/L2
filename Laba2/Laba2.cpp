#include <iostream>
#include "Cipher.h"
using namespace std;



int main()
{
    string message = "As a student who played dota, I don't respect lolers";
    Cipher test(message);
    test.printPeriodicity();
    test.printCodeForChar();
    test.printSize();
    test.printCode();
    test.printDecode();
    test.printCoefficient();
}
#ifndef MACHINE_HPP
#define MACHINE_HPP
#include "drink.hpp"
#include <string>
using namespace std;

class Machine {

  public:

    // Total number of drinks the machine can hold
    static const int CAPACITY = 1;

    Machine();
    void InitMachine();
    void DisplayMachine();
    void ProcessVending();

  private:
    Drink inventory[CAPACITY];

    void printColaAscii();

};
#endif
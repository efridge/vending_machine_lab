#include "machine.hpp"
#include <string>
#include <iostream>
using namespace std;

// Global variables
Machine drinkMachine;
char machineChoice;

int main() {
  // Init the machine
  drinkMachine.InitMachine();

  do {
    // Ask the user what they want to do
    drinkMachine.DisplayMachine();
    cout << "Please enter a choice: (v)end, (q)uit" << endl;
    cin >> machineChoice;

    // If they enter a "v", process a vending request
    if(machineChoice == 'v') {
      drinkMachine.ProcessVending();
    }

  } while(machineChoice != 'q');

}
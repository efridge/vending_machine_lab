#include "machine.hpp"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

Machine::Machine(){

}

/**
 * A helper method to initialize the machine
*/
void Machine::InitMachine() {
  cout << "Please enter info for " << Machine::CAPACITY << " drinks" << endl;

  for(int i = 0; i < Machine::CAPACITY; i++) {
    string name = "";
    double cost = -1;
    int quantity = -1;

    while(name == "") {
      cout << "Please enter a name for this drink: " << endl;
      cin >> name;
      cin.clear();
    }

    while(cost <= 0 || cost > 5.00) {
      cout << "Please enter a cost for the drink (up to $5): " << endl;
      cin >> cost;
      cin.clear();
    }

    while( quantity <= 0 || quantity > 10) {
      cout << "Please enter a quantity for this drink (up to 10): " << endl;
      cin >> quantity;
      cin.clear();
    }

    this->inventory[i] = Drink(name, cost, quantity);
  }
}

/**
 * Renders the machine's contents on the screen
*/
void Machine::DisplayMachine() {
  cout << "\n\n------- Drink ---- Cost --- Status ---" << endl;
  for(int i = 0; i < this->CAPACITY; i++) {
    cout << i + 1 << ": " << setw(10) << this->inventory[i].GetName() << "   ";
    cout << setw(5) << setprecision(2) << "$" << this->inventory[i].GetCost() << "   ";

    if(this->inventory[i].IsSoldOut()) {
      cout << "SOLD OUT " << endl;
    } else {
      cout << this->inventory[i].GetQuantity() << " Available" << endl;
    }
  }
  cout << "\n\n--------------------------------------" << endl;

}

/**
 * Processes a vending request
*/
void Machine::ProcessVending() {
  
  int drinkNumber;    // Used to get the drink the user wants
  int newAmount = 0;  // Will contain the number of drinks remaining
  do {
    cout << "Please enter the drink number: " << endl;
    cin >> drinkNumber;
  } while(std::cin.fail() || drinkNumber <= 0 || drinkNumber > this->CAPACITY);

  // If the drink is not sold out yet, sell one of the drinks
  if(! this->inventory[drinkNumber-1].IsSoldOut()) {
     newAmount = this->inventory[drinkNumber-1].SellDrink();
    cout << "Here's your drink!" << endl;
    this->printColaAscii();
  }

  if(newAmount > 0) {
    cout << "There are" << newAmount <<  " drinks remaining." << endl;
  } else {
    cout <<  "This drink has sold out :(" << endl;
  }
}

/**
 * Prints an ASCII art bottle of cola
*/
void Machine::printColaAscii() {
  cout << "        _        " << endl;
  cout << "      .!.!.      " << endl;
  cout << "       ! !       " << endl;
  cout << "       ; :       " << endl;
  cout << "      ;   :      " << endl;
  cout << "     ;_____:     " << endl;
  cout << "     ! cola!     " << endl;
  cout << "     !_____!     " << endl;
  cout << "     :     :     " << endl;
  cout << "     :     ;     " << endl;
  cout << "     .'   '.     " << endl;
  cout << "     :     :     " << endl;
  cout << "      '''''      \n\n\n" << endl;
}
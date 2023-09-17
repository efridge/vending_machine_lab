#include "drink.hpp"    
#include <string>
using namespace std;

// Default constructor, initialize as if it's empty
Drink::Drink(){
  this->name = "empty";
  this->cost = 0.00;
  this->quantity = 0;
}

/**
 * An alternate constructor with extra starting values
 * @param initName - An initial name for the drink
 * @param initCost - The initial cost
 * @param initQuantity - Initial number of drinks on hand
*/
Drink::Drink(string initName, double initCost, int initQuantity){
  this->name = initName;
  this->cost = initCost;
  this->quantity = initQuantity;
}

/**
 * A setter for the drink's name
 * @param newName - The new name to set
*/
void Drink::SetName(string newName){
 this->name = newName;
}

/**
 * Gets the drink cost
 * @returns The drink cost
*/
double Drink::GetCost(){
 return this->cost;
}

/**
 * Gets the drink cost
 * @returns The drink name
*/
string Drink::GetName(){
 return this->name;
}

/**
 * Sells a drink if we have inventory available
 * @returns The new inventory amount.
*/
int Drink::SellDrink() {
  if(this->quantity > 0) {
    this->quantity--;
  }
  return this->quantity;
}

/**
 * Lets us know if a drink is sold out
 * @returns A boolean indicating the drink status.
*/
bool Drink::IsSoldOut(){
  return this->quantity == 0;
}

/**
 * Gets the current quantity of this drink in stock
 * @returns The number of drinks available of this type.
*/
int Drink::GetQuantity(){
  return this->quantity;
}
#include "drink.hpp"    
#include <string>
using namespace std;

// Default constructor, initialize as if it's empty
Drink::Drink(){
  name = "empty";
  cost = 0.00;
  quantity = 0;
}

/**
 * An alternate constructor with extra starting values
 * @param initName - An initial name for the drink
 * @param initCost - The initial cost
 * @param initQuantity - Initial number of drinks on hand
*/
Drink::Drink(string initName, double initCost, int initQuantity){
  name = initName;
  cost = initCost;
  quantity = initQuantity;
}

/**
 * A setter for the drink's name
 * @param newName - The new name to set
*/
void Drink::SetName(string newName){
 name = newName;
}

/**
 * Gets the drink cost
 * @returns The drink cost
*/
double Drink::GetCost(){
 return cost;
}

/**
 * Gets the drink cost
 * @returns The drink name
*/
string Drink::GetName(){
 return name;
}

/**
 * Sells a drink if we have inventory available
 * @returns The new inventory amount.
*/
int Drink::SellDrink() {
  if(quantity > 0) {
    quantity--;
  }
  return quantity;
}

/**
 * Lets us know if a drink is sold out
 * @returns A boolean indicating the drink status.
*/
bool Drink::IsSoldOut(){
  return quantity == 0;
}

/**
 * Gets the current quantity of this drink in stock
 * @returns The number of drinks available of this type.
*/
int Drink::GetQuantity(){
  return quantity;
}
#ifndef DRINK_HPP
#define DRINK_HPP
#include <string>
using namespace std;

class Drink {
  public:
    // Constructors
    Drink();
    Drink(string initName, double initCost, int initInventory);

    // Name
    void SetName(string name);
    string GetName();

    // Cost
    double GetCost();
    int SellDrink();

    // Quantity
    bool IsSoldOut();
    int GetQuantity();

  private:
    string name; 
    double cost;
    int quantity;
};
#endif
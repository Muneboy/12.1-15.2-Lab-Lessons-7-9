#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// prototypes
void readFunc(int & spoolsNum, int & spoolsStock, double & shippingCharge);
void displayFunc(int spoolsNum, int spoolsStock, double shippingCharge);

int main()
{
  int spoolsNum = 0;
  int spoolsStock = 0;
  double shippingCharge = 0.00;

  readFunc(spoolsNum, spoolsStock, shippingCharge);
  displayFunc(spoolsNum, spoolsStock, shippingCharge);

  return 0;
}

void readFunc(int & spoolsNum, int & spoolsStock, double & shippingCharge)
{
  char specialShip;

  cout << "Spools to be ordered" << endl; // inputting spool vals
  cin >> spoolsNum;

  while (spoolsNum < 1)
  {
    cout << "Spools order must be 1 or more" << endl;
    cout << "Spools to be ordered" << endl;
    cin >> spoolsNum;
  }

  cout << "Spools in stock" << endl;
  cin >> spoolsStock;

  while (spoolsStock < 0)
  {
    cout << "Spools in stock must be 0 or more" << endl;
    cout << "Spools in stock" << endl;
    cin >> spoolsStock;
  }

  cout << "Special shipping and handling (y or n)" << endl;
  cin >> specialShip;

  if (specialShip == 'y')
  {
    cout << "Shipping and handling amount" << endl;
    cin >> shippingCharge;

    while (shippingCharge < 0.0)
    {
      cout << "The spool shipping and handling charge must be 0.0 or more" << endl;
      cout << "Shipping and handling amount" << endl;
      cin >> shippingCharge;
    }
  }
  
  else if (specialShip == 'n')
  {
    shippingCharge = 12.99;
  }

}

void displayFunc(int spoolsNum, int spoolsStock, double shippingCharge)
{
  int readySpools;
  int backOrderSpools;
  double costSpool;
  double costWShip;

  if (spoolsNum < spoolsStock)
  {
    readySpools = spoolsNum;
    backOrderSpools = 0;
  }
  else
  {
    readySpools = spoolsStock;
    backOrderSpools = spoolsNum - spoolsStock;
  }

  costSpool = readySpools * 104;
  costWShip = costSpool + (shippingCharge * readySpools);

  cout << "Spools ready to ship: " << readySpools << endl;
  cout << "Spools on back-order: " << backOrderSpools << endl;
  cout << "Subtotal ready to ship: $" << setw(10) << right << fixed << setprecision(2) << costSpool << endl;
  cout << "Shipping and handling:  $" << setw(10) << right << fixed << setprecision(2) << shippingCharge * readySpools << endl;
  cout << "Total shipping charges: $" << setw(10) << right << fixed << setprecision(2) << costWShip << endl;
}
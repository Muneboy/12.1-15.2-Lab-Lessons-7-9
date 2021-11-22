#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// prototypes
double presentValue(double futureValue, double interestRate, int numberYears);
double futureVal();
double interestRate();
int numYear();
void displayFunc(double presentValue, double futureValue, double interestRate, int numberYears);

int main()
{
  double futVal = futureVal();
  double intRat = interestRate();
  int numYr = numYear();

  double presentVal = presentValue(futVal, intRat, numYr);

  displayFunc(presentVal, futVal, intRat, numYr);

  return 0;
}

double presentValue(double futureValue, double interestRate, int numberYears)
{
  double presentVal;

  presentVal = futureValue / pow(1 + interestRate, numberYears);

  return presentVal;
}

double futureVal()
{
  double futureVal;

  cout << "Enter future value" << endl;
  cin >> futureVal;

  while (futureVal <= 0)
  {
    cout << "The future value must be greater than zero" << endl;
    cout << "Enter future value" << endl;
    cin >> futureVal;
  }

  return futureVal;
}

double interestRate()
{
  double interestRate;
  double interestPerc;

  cout << "Enter annual interest rate" << endl;
  cin >> interestRate;

  while (interestRate <= 0)
  {
    cout << "The annual interest rate must be greater than zero" << endl;
    cout << "Enter annual interest rate" << endl;
    cin >> interestRate;
  }

  interestPerc = interestRate / 100;

  return interestPerc;
}

int numYear()
{
  int numYear;

  cout << "Enter number of years" << endl;
  cin >> numYear;

  while (numYear <= 0)
  {
    cout << "The number of years must be greater than zero" << endl;
    cout << "Enter number of years" << endl;
    cin >> numYear;
  }

  return numYear;
}

void displayFunc(double presentValue, double futureValue, double interestRate, int numberYears)
{
  cout << "Present value: $" << fixed << setprecision(2) << presentValue << endl;
  cout << "Future value: $" << fixed << setprecision(2) << futureValue << endl;
  cout << "Annual interest rate: " << fixed << setprecision(3) << interestRate * 100 << "%" << endl;
  cout << "Years: " << numberYears << endl;
}
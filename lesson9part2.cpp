#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

// prototypes
double futureValue(double presentValue, double interestRate, int months);
unsigned int readFile(ifstream & inFS, double & presVal, double & intRate, int & numMonth);
void outputTable(ofstream & outFS, double futureValue, double presentValue, double interestRate, int numMonth);

int main()
{
  ifstream inFS; // file variables
  ofstream outFS;
  string fileName;

  double presVal; // math values
  double futVal;
  double intRate;
  int numMonth;
  double intPerc;

  unsigned int fileValidity = 3;

  cout << "Enter input file name" << endl;
  cin >> fileName;

  inFS.open(fileName);

  if (!inFS.is_open()) // error statement for input file
  {
    cout << "File " << "\"" << fileName << "\"" << " could not be opened" << endl;
    return 0;
  }

  else // if input file is valid
  {
    outFS.open("output.xls");

    if (!outFS.is_open())
    {
      cout << "File output.xls could not be opened" << endl;
      return 0;
    }

    else
    {
      outFS << "Future Value\tPresent Value\tMonthly Interest\tMonths" << endl;

      while (fileValidity != 2)
      {
        fileValidity = readFile(inFS, presVal, intRate, numMonth); // reinitializes fileValidity for if statements

        if (fileValidity == 1) // valid values
        {
          intPerc = intRate / 100;
          futVal = futureValue(presVal, intPerc, numMonth);

          outputTable(outFS, futVal, presVal, intRate, numMonth);
        }

        else if (fileValidity == 0) // invalid values
        {
          cout << fixed << setprecision(2) << presVal << " ";
          cout << fixed << setprecision(3) << intRate << " ";
          cout << fixed << setprecision(0) << numMonth << endl;
          cout << "One or more of the above values are not greater than zero" << endl;
        }

      }
    }
  }

  inFS.close(); // close both files
  outFS.close();

  return 0;
}

unsigned int readFile(ifstream & inFS, double & presVal, double & intRate, int & numMonth)
{
  if (inFS >> presVal >> intRate >> numMonth) // checks for the eof condition and returns the validity of the file
  {
    if (presVal <= 0 || intRate <= 0 || numMonth <= 0)
    {
      return 0;
    }

    else
    {
      return 1;
    }

  }

  else
  {
    return 2;
  }
}

double futureValue(double presentValue, double interestRate, int months) // future value calculations
{
  double futureCalc = presentValue * pow((1 + interestRate), months);

  return futureCalc;
}

void outputTable(ofstream & outFS, double futureValue, double presentValue, double interestRate, int numMonth)
{
  outFS << fixed << setprecision(2) << futureValue << "\t";
  outFS << fixed << setprecision(2) << presentValue << "\t";
  outFS << fixed << setprecision(3) << interestRate << "\t";
  outFS << fixed << setprecision(0) << numMonth << endl;
}
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() 
{
  ifstream inFS;
  ofstream outFS;

  string fileName;
  double inputVal;

  int totalVals = 0;
  int invalidVals = 0;
  int validVals = 0;
  double averageVal = 0;
  bool noValid = false;

  cout << "Enter input file name" << endl;
  cin >> fileName;

  inFS.open(fileName);
  if (!inFS.is_open()) // error statement
  {
    cout << "File " << "\"" << fileName << "\"" << " could not be opened" << endl;
    return 0;
  }

  cout << "Reading from file " << "\"" << fileName << "\"" << endl;

  outFS.open("invalid-values.txt");
  if (!outFS.is_open()) // error statement
  {
    cout << "File " << "\"" << "invalid-values.txt" << "\"" << " could not be opened" << endl;
    return 0;
  }

  while (inFS >> inputVal)
  {
    ++totalVals;

    if (inputVal < 0 || inputVal > 105)
    {
      ++invalidVals;
      outFS << fixed << setprecision(5) << inputVal << endl;
    }

    else
    {
      ++validVals;
      averageVal = averageVal + inputVal;
    }

  }

  if (validVals == 0)
  {
    noValid = true;
  }

  else
  {
    averageVal = averageVal / validVals;
  }

  cout << "Total values: " << totalVals << endl;
  cout << "Invalid values: " << invalidVals << endl;
  cout << "Valid values: " << validVals << endl;

  if (noValid)
  {
    cout << "An average cannot be calculated" << endl;
  }
  else
  {
    cout << "Average of valid values: " << fixed << setprecision(4) << averageVal << endl;
  }

  return 0;
} 
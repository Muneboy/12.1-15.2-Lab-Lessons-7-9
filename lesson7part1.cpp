//
//  main.cpp
//  12.1 Lab Lesson 7 (Part 1 of 2)
//
//  Created by Kenneth Vo on 11/18/21.
//

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

  unsigned int storeNum;
  long long int storeSale;
   
  cout << "Enter input file name" << endl; // enter file name prompt
  cin >> fileName;

  inFS.open(fileName); // reads input file
  if (!inFS.is_open()) // error statement
  {
    cout << "File " << "\"" << fileName << "\"" << " could not be opened" << endl;
    return 0;
  }

  outFS.open("saleschart.txt"); // reads output file
  if (!outFS.is_open()) // error statement
  {
    cout << "File saleschart.txt could not be opened" << endl;
    return 0;
  }

  outFS << "SALES BAR CHART" << endl;
  outFS << "(Each * equals 5,000 dollars)" << endl;

  while (inFS >> storeNum >> storeSale)
  {

    if (storeNum < 1 || storeNum > 99)
    { 
      cout << "The store number " << storeNum << " is not valid" << endl;
      
    }

    else // read in sales value and detect if sales is positive
    {
      if (storeSale < 0)
      {
        cout << "The sales value for store " << storeNum << " is negative" << endl;
      }

      else // outputting values into bar chart file
      {
        outFS << "Store " << setw(2) << storeNum << ": ";

        for (int i = 0; i < storeSale / 5000; ++i)
        {
          outFS << "*";
        }
        
        outFS << endl;
      }
    }

  }

  inFS.close(); // close both files
  outFS.close();

   return 0;
}
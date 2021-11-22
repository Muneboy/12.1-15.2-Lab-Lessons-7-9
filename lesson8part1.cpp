#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//prototypes
double readSeconds();
double calculateEarthDistance(double seconds);
double calculateMoonDistance(double seconds);
void displayResults(double seconds, double earthDistance, double moonDistance);

int main() 
{
  double seconds = 1;
  do
  {
    seconds = readSeconds();

    if (seconds > 0)
    {
      double earthDist = calculateEarthDistance(seconds);
      double moonDist = calculateMoonDistance(seconds);

      displayResults(seconds, earthDist, moonDist);
    }
  }
  while (seconds != 0);
  
  return 0;
} 

double readSeconds()
{
  double seconds;

  cout << "Enter the time (in seconds)" << endl;
  cin >> seconds;

  if (seconds < 0)
  {
    cout << "The time must be zero or more" << endl;
  }

  return seconds;
}

double calculateEarthDistance(double seconds)
{
  double distance;
  double grav = 9.8;

  distance = 0.5 * grav * pow(seconds, 2);

  return distance;
}

double calculateMoonDistance(double seconds)
{
  double distance;
  double grav = 1.6;

  distance = 0.5 * grav * pow(seconds, 2);

  return distance;
}

void displayResults(double seconds, double earthDistance, double moonDistance)
{
  cout << "The object traveled " << fixed << setprecision(4) << earthDistance << " meters in " << fixed << setprecision(2) << seconds << " seconds on Earth" << endl;
  cout << "The object traveled " << fixed << setprecision(4) << moonDistance << " meters in " << fixed << setprecision(2) << seconds << " seconds on the Moon" << endl;
}
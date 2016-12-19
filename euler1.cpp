

#include "euler1.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <cmath>

// Returns the sum of all the multiples of 3 or 5 below 1000
int eulerFirst()
{
   int endSum = 0;
   for (int i=1; i<1000; i++)
   {
	if ((i % 3 == 0) || (i % 5 == 0))
	   { endSum += i; }
   }  
   return endSum;
}

// Returns the sum of all even numbers (below 4 million) in the
// Fibonacci sequence
int eulerSecond()
{
   int endSum = 0,
       firstNum = 1,
       secondNum = 2,
       helperNum;  // Holds values during computation of next step in sequence

   do
   {
	if (secondNum % 2 == 0)
	   { endSum += secondNum; }
	helperNum = secondNum;
	secondNum += firstNum;
	firstNum = helperNum;
   }while (secondNum < 4000000);
   return endSum; 
}

// Returns the largest prime factor of the number 600851475143
long eulerThird()
{
   long testNum = 600851475143;
   //long testNum = 13195;  // Test to see that program executes, not a memory leak
   //long loopTarget = (testNum / 2) + 1;  // A prime factor can never be larger than half the original value
   long largestFactor = 1;

   for (long i=2; i <= testNum; i++)
   {
	bool isPrime = true;	
	for (long j=2; j < i; j++)
	{
	   if ((i % j == 0) && (j != i))
	      {	isPrime = false; }
	}
	if (isPrime && (testNum % i == 0))
	{ 
	   largestFactor = i;
	   testNum /= i;
	} 	
   }
   return largestFactor;
}

// Returns the largest palindrome product of two 3-digit numbers
int eulerFourth()
{
   int largestPalindrome = 0;
   int testProd;
   std::string originalProd,
	       reverseProd;
   for (int i=100; i<1000; i++)
   {
	for (int j=100; j<1000; j++)
	{
	   testProd = i * j; 
	   originalProd = std::to_string(testProd);
	   reverseProd = originalProd;
	   std::reverse(reverseProd.begin(), reverseProd.end());

	   if ((originalProd == reverseProd) && (testProd > largestPalindrome))
	   { largestPalindrome = testProd; }
	}
   }
   return largestPalindrome;
}

// Returns the smallest positive number that is evenly divisible by all the numbers from 1 to 20
int eulerFifth()
{
   int dividend = 21;
   bool isFinished = false;

   while (isFinished == false)
   {
	bool isDivisible = true;
	for (int i=1; i<21; i++)
	{
	   if (dividend % i != 0)
	   { isDivisible = false; }
	}	

	if (isDivisible)
	{ isFinished = true; }
	else
	{ dividend++; }
   }
   return dividend;
}

// Returns the difference between the sum of the squares of the first hundred natural numbers
// and the sum of the first hundred natural numbers squared
long eulerSixth()
{
   long squaresSum = 0,
        sumSquared = 0;
   for (int i=1; i<101; i++)
   {
	squaresSum += (i * i);
	sumSquared += i;
   } 
   sumSquared *= sumSquared;

   return sumSquared - squaresSum;
}

// Returns the 10,001st prime number
long euler7()
{
   long primeCandidate = 3;
   int primeCount = 1; // starts at 1 to account for '2' which we skip

   while (primeCount < 10001)
   {
	bool isPrime = true;
	for (long i=2; i<primeCandidate; i++)
	{
	   if (primeCandidate % i == 0)
	   { isPrime = false; } 
	}		
	if (isPrime)
	{ primeCount++; }

	if (primeCount < 10001)
	{ primeCandidate++; }
   }
   return primeCandidate;
}

// Returns the greatest product of 13 adjacent digits in a 1000 digit number
long euler8()
{
   long maximumProd = 1;
   std::ifstream inputFile;
   inputFile.open("eul8.txt");
   char inputDigit;
   int placement = 0;  // Start position when reading from file. Increases until all adjacent groups of 13 are read

   while (placement < 988)
   {
	long testProd = 1;
	inputFile.seekg(placement);
	for (int i=0; i<13; i++)
	{
	   inputFile >> inputDigit;
	   int convDig = inputDigit - '0';
	   testProd *= convDig;
	}
	
	if (testProd > maximumProd)
	{ maximumProd = testProd; }
	placement++;
   }
   return maximumProd;
}

// Returns the product of abc where a, b, and c are natural numbers where a^2 + b^2 = c^2 and a + b + c = 1000
int euler9()
{
   int a, b, c;  // For Euclid's formula
   int finalProd;
   for (int n=1; n<1000; n++)
   {
	for (int m=n+1; m<1000; m++)
	{
	   a = (m * m) - (n * n);
	   b = 2 * m * n;
	   c = (m * m) + (n * n);
	   if (a + b + c == 1000)
	   { finalProd = a * b * c; } 
	}
   }
   return finalProd;
}

// Returns the sum of all the primes below two million
long euler10()
{
   int const primeTarget = 2000000;
   long primeSum = 2; // Starts by accounting for '2'

   for (int i=3; i<primeTarget; i++)
   {
	bool isPrime = true;
	if (i % 2 == 0)
	{ isPrime = false; }
	else
	{
	   for (int j=2; j<(int(sqrt(double(i)))+2); j++)
	   {
	      if (i % j == 0)
	      { isPrime = false; }
	   }
	}
	if (isPrime)
	{ 
	   primeSum += i; 
	}
   }
   return primeSum;
}

// Returns the greatest product of any 4 values (in the 20x20 grid) whether horizontal, verticle, or diagonal
int euler11()
{
   std::ifstream inputFile;
   inputFile.open("eul11.txt");
   int intGrid[20][20];
   int highProd = 1;

   for (int i=0; i<20; i++)  // Populates 2-dimensional array with values from 20x20 grid
   {
	for (int j=0; j<20; j++)
	{
	   inputFile >> intGrid[i][j];
	}
   }  
     
   for (int i=0; i<20; i++) // Checks horizontal products
   {
	for (int j=0; j<17; j++)
	{
	   int testVal = intGrid[i][j] * intGrid[i][j+1] * intGrid[i][j+2] * intGrid[i][j+3]; 
	   if (testVal > highProd)
		{ highProd = testVal; }
	}	
   }
   for (int i=0; i<17; i++) // Checks vertical products
   {
	for (int j=0; j<20; j++)
	{
	   int testVal = intGrid[i][j] * intGrid[i+1][j] * intGrid[i+2][j] * intGrid[i+3][j]; 
	   if (testVal > highProd)
		{ highProd = testVal; }
	}	
   }
   for (int i=0; i<17; i++) // Checks diagonal descending products
   {
	for (int j=0; j<17; j++)
	{
	   int testVal = intGrid[i][j] * intGrid[i+1][j+1] * intGrid[i+2][j+2] * intGrid[i+3][j+3]; 
	   if (testVal > highProd)
		{ highProd = testVal; }
	}	
   }
   for (int i=0; i<17; i++) // Checks diagonal ascending products
   {
	for (int j=3; j<20; j++)
	{
	   int testVal = intGrid[i][j] * intGrid[i+1][j-1] * intGrid[i+2][j-2] * intGrid[i+3][j-3]; 
	   if (testVal > highProd)
		{ highProd = testVal; }
	}	
   }
   return highProd; 
}

// Returns the first triangle number to have over five hundred divisors
int euler12()
{
   int const DIVISORS_TARGET = 500;
   int numDivisors = 0,
       triNum = 2,
       triNumVal = 3;

   while (numDivisors <= DIVISORS_TARGET)
   {
	numDivisors = 0;
	for (int i=1; i<(int(sqrt(double(triNumVal)))+1); i++)
	{
	   if (triNumVal % i == 0)
	   { numDivisors++; }
	}
	numDivisors *= 2; // Formula in above loop finds half the divisors (since only goes up to square root of tested number
	if (numDivisors <= DIVISORS_TARGET)
	{
	   triNumVal = 0;
	   triNum++;
	   triNumVal = (triNum * (triNum+1)) / 2; // Formula to calculate a triangle number
	}
   }
   return triNumVal;
}

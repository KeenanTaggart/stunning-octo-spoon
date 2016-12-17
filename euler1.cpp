

#include "euler1.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

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

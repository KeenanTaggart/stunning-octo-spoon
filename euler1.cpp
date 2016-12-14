

#include "euler1.hpp"

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

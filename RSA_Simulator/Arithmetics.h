#ifndef ARITHMETICS_H
#define ARITHMETICS_H

#include <iostream>
#include <cmath> // MATH, ASSEMBLE
#include <vector> // dinamic arrays, OP

class Arithmetics
{
public:

	bool IsPrimeNumber(long num); // checks if the number given is actually a prime number

	long GCD(long a, long b); // finds the Greater Common Divisor of two numbers using the Euclid's Algorithm

	bool AreCoprimes(int dividend, int divisor); // checks if two numbers are coprimes

	std::vector<int> AllPrimesInRange(int current, int range); // returns a fixed vector containing all prime numbers within a range

	std::vector<int> AllDivisors(int num); // generates a vector which contains all possible divisors of a number given

	std::vector<int> Factorize(int num); // returns a vector which contains the product of primes of a number given

	int EulerFunction(int m); // returns the number of coprimes with a certain digit, notated as PHI(m)

};

#endif
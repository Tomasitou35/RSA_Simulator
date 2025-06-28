#ifndef ARITHMETICS_H
#define ARITHMETICS_H

#include <iostream>
#include <cmath> // MATH, ASSEMBLE
#include <vector> // dinamic arrays, OP
#include <iomanip> // to not to trunc on Euler's Totient

//TODO: Bezout's Identity resolver to find d for the DK
class Arithmetics
{
public:

	bool IsPrimeNumber(long long num); // checks if the number given is actually a prime number

	long long GCD(long long a, long long b); // finds the Greater Common Divisor of two numbers using the Euclid's Algorithm

	bool AreCoprimes(long long dividend, long long divisor); // checks if two numbers are coprimes

	std::vector<long long> AllPrimesInRange(long long current, long long range); // returns a fixed vector containing all prime numbers within a range

	std::vector<long long> AllDivisors(long long num); // generates a vector which contains all possible divisors of a number given

	std::vector<long long> Factorize(long long num); // returns a vector which contains the product of primes of a number given

	long long EulerFunction(long long m); // returns the number of coprimes with a certain digit, notated as PHI(m)

	long long Remainder(long long coefficient, long long modulus); // basic arithmetics but for long long values

	long long Congruence(long long coefficient, long long remainder, long long modulus); // solves a Congruence of the form ax=b(mod n)

	long long ModularPow(long long base, long long exponent, long long modulus);
};

#endif
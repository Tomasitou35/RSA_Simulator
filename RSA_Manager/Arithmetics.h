#ifndef Arithmetics_h
#define Arithmetics_h

#include <iostream>
#include <cmath> // MATH, ASSEMBLE
#include <vector> // dinamic arrays, OP
#include <random> // useful for random number generation

/* TODO: MAYBE some kind of polimorphing just to use ShowVector in different ways depending on the [MORE]
   subclass that you are. This will also mean the creation of subclasses, such that PUBLIC KEY & PRIVATE KEY
   (which actually has SO much sense because as a Public Key User, you shouldn't be able to access Private Key
   functions too, as well as both subclasses could access superclass' arithmetic methods freely).
*/
class Arithmetics // contains all the arithmetical operations needed in order to build up an RSA algorythm
{
protected:
	
	int p; // first prime number for the public key
	int q; // second prime number for the public key

public:

	// SETTERS & GETTERS

	Arithmetics();

	void SetP(int p);
	int GetP();

	void SetQ(int q);
	int GetQ();

	void virtual ShowVector(std::vector<int> vector); // output: [p1, p2, p3,...pn]

	// ARITHMETIC OPERATIONS

	bool IsPrimeNumber(int num); // checks if the number given is actually a prime number

	bool AreCoprimes(int dividend, int divisor); // checks if two numbers are coprimes

	std::vector<int> GeneratePrimes(int quantity, int from, int to); // generates random prime numbers in a range given

	std::vector<int> AllPrimesInRange(int current, int range); // returns a fixed vector containing all prime numbers within a range

	std::vector<int> AllDivisors(int num); // generates a vector which contains all possible divisors of a number given

	std::vector<int> Factorize(int num); // returns a vector which contains the product of primes of a number given

	int GCD(int a, int b); // finds the Greater Common Divisor of two numbers using the Euclid's Algorithm

	int EulerFunction(int m); // returns the number of coprimes with a certain digit, notated as PHI(m)

	int Congruences(float base, float exponent, int module); // let me cook for a bit here


	// STRICTLY FOR RSA ENCRYPTING METHOD FUNCTIONS

	std::vector<int> Encrypt(char message, int e, int module); // by making use of the public key, a message is encrypted and stored as a vector

	std::vector<int> Dencrypt(std::vector<int> encryptedMessage, std::vector<int> publicKey); // by making use of the private key, the encrypted message getsç
																							  // dencrypted and stored back again in a vector

};
#endif

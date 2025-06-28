#ifndef KEYGENERATOR_H
#define KEYGENERATOR_H

#include "Arithmetics.h";
#include "Profile.h"
#include <ctime> // for e choosing
#include <cstdlib>

class KeyGenerator
{
private:

	/*
		FRIENDLY REMINDER!

		p = first prime number
		q = second prime number
	*/
	long long p, q;
	Arithmetics arithmetics;

public:

	Key GeneratePublicKey(long long myP, long long myQ);

	Key GeneratePrivateKey(Key PK);
};

#endif

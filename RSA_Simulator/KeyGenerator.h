#ifndef KEYGENERATOR_H
#define KEYGENERATOR_H

#include "Arithmetics.h";
#include "Profile.h"

class KeyGenerator
{
private:

	/*
		FRIENDLY REMINDER!

		p = first prime number
		q = second prime number
	*/
	long p, q;
	Arithmetics arithmetics;

public:

	Key GeneratePublicKey(long myP, long myQ);

	Key GeneratePrivateKey();
};

#endif

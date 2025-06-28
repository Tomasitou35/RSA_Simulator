#include "KeyGenerator.h"

Key KeyGenerator::GeneratePublicKey(long long myP, long long myQ)
{
	Key PublicKey = { 0,0 };

	if (!arithmetics.IsPrimeNumber(myP) || !arithmetics.IsPrimeNumber(myQ))
	{
		return PublicKey;
	}

	long long n = myP * myQ;

	long long eulersTotient = arithmetics.EulerFunction(n);

	// check for a valid e, coprime with φ(n)
	bool eFound = false;
	int e = 3;

	while (e < eulersTotient && !eFound)
	{
		if (arithmetics.AreCoprimes(e, eulersTotient))
		{
			eFound = true;	
		}
		else
		{
			e += 2;
		}
	}

	PublicKey.values[0] = n;
	PublicKey.values[1] = e;

	return PublicKey;
}

Key KeyGenerator::GeneratePrivateKey(Key PK)
{
	Key DK = {0,0};

	long long n = PK.values[0];
	long long e = PK.values[1];

	long long phi = arithmetics.EulerFunction(n);
	long long d = arithmetics.Congruence(e, 1, phi);

	if (d != -1)
	{
		DK.values[0] = d;
		DK.values[1] = n;
	}

	return DK;
}
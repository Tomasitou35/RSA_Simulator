#include "KeyGenerator.h"

Key KeyGenerator::GeneratePublicKey(long myP, long myQ)
{
	Key PublicKey = { 0,0 };

	if (!arithmetics.IsPrimeNumber(myP) || !arithmetics.IsPrimeNumber(myQ))
	{
		return PublicKey;
	}

	long n = myP * myQ;

	long eulersTotient = arithmetics.EulerFunction(n);

	// check for a valid e, coprime with φ(n)
	bool eFound = false;
	int e = 2;

	while (!eFound && e<eulersTotient)
	{
		if (arithmetics.AreCoprimes(eulersTotient, e) && e>eulersTotient/2)
		{
			eFound = true;
		}
		else
		{
			e++;
		}
	}

	if (eFound)
	{
		PublicKey.values[0] = n;
		PublicKey.values[1] = e;
	}

	return PublicKey;
}
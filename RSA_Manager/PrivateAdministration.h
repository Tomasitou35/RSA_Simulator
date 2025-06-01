#ifndef PrivateAdministration_h
#define PrivateAdministration_h

#include "Arithmetics.h"

class PrivateAdministration : Arithmetics
{
private:

	std::vector<int> privateKey; // (d, n)
	int d; // the d of the (d, n)

public:

	void SetPrivateKey(std::vector<int> myPrivateKey);
	std::vector<int> GetPrivateKey();

	bool PrivateKey(); // by e and phi give, it creates a fitting private key [d, n]
};

#endif


#ifndef PublicAdministration_h
#define PublicAdministrarion_h

#include "Arithmetics.h"

class PublicAdministration : public Arithmetics
{
private:

	std::vector<int> publicKey; // (n, e)

public:

	void SetPublicKey(std::vector<int> publicKey);
	std::vector<int> GetPublicKey();

	void ShowVector(std::vector<int> vector) override;

	bool PublicKey(); // by 2 primes given, it creates a fitting public key [n, e]
};

#endif

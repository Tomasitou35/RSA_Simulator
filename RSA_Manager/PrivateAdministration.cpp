#include "PrivateAdministration.h"

void PrivateAdministration::SetPrivateKey(std::vector<int> myPrivateKey)
{
	privateKey = myPrivateKey;
}

std::vector<int> PrivateAdministration::GetPrivateKey()
{
	return privateKey;
}

bool PrivateAdministration::PrivateKey()
{
	/*
		The Private Key is built out of two digits:
		n: previously used.
		d: the "decodificator".
		ONLY THE PERSON WHO CREATED THE PUBLIC KEY should have access to the Private Key,
		in order to make the RSA as save as possible (other way it wouldn't have sense though).

		The expression of the Private Key is:	e * d = 1 mod(phi(n)).
		e has already been set at this point of the program (theorically), as a number between
		1 < e < phi(n), comprime with n.

		To clean out d, we calculate the inverse product of ed=mod(phi(n)).
	*/

	int n = GetP() * GetQ();

	// Continue from here >:)

	return true;
}
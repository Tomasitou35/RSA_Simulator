#ifndef Menu_h
#define Menu_h

#include <iostream>
#include "Arithmetics.h"
#include "PublicAdministration.h"

// TODO: Rethink the actual usefulness of some methods; maybe some are redundant.
class Menu // contains all the functions that displays the menu
{
private:
	Arithmetics operation; // the instance must be unique in order to work
	PublicAdministration opPublic; // subclass instance for PublicKey
	
public:

	char MainMenu();
	char ArithmeticalMenu();

	void CheckPrime();
	void GreatestCommonDivisor();
	void Coprimes();
	void MenuAllPrimesInRange();
	void FactorizeNumber();
	void MenuEulerFunction();

	// TODO: Implement all the methods below this comment.
	void UpdatePrimes();
	void ShowPublicKey();
	void CreatePublicKey();
	void ErasePublicKey();

	void CreatePrivateKey();
	void ShowPrivateKey();
	void ErasePrivateKey();

};

#endif
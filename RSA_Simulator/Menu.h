#ifndef MENU_H
#define MENU_H
#include "RSA_Manager.h"

// Menu functions
class Menu
{
private:

	RSA_Manager manager;
	Arithmetics arithmetics;

public:

	// Main functions

	char ShowMainMenu();

	char ArithmeticalMenu();

	void CreateNewProfile();

	void SelectExistingProfile();

	void SendMessage();

	void OpenMailbox();

	void ModularCalculator();

	// Arithmetical functions

	void CheckPrime();

	void GCD();

	void CheckCoprimes();

	void Factorize();

	void AllPrimesInRange();

	void EulersTotient();
};

void Start();

void Confirm();

#endif

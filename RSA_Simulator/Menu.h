#ifndef MENU_H
#define MENU_H
#include "RSA_Manager.h"

// Menu functions

class Menu
{
private:
	RSA_Manager manager;

	void showMainMenu();

	void createNewProfile();

	void selectExistingProfile();

	void sendMessage();

	void openMailbox();

	void modularCalculator();

public:
	static void start();
};

#endif

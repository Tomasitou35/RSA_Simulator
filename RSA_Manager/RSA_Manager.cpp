#include <iostream>
#include <Windows.h>
#include "Arithmetics.h"
#include "Menu.h"

int main()
{
    /*
        DOCUMENTATION HERE (for fast check):
        > https://en.cppreference.com/w/
        > https://stackoverflow.com/questions
        > https://www.w3schools.com/cpp/default.asp
    */

    Menu myMenu;

    char mainOption, arithOption;

    do
    {
        mainOption = myMenu.MainMenu();

        switch (mainOption)
        {
        // SET/CHANGE PRIMES OF PUBLIC KEY
        case '1':
        {
            myMenu.UpdatePrimes();
            break;
        }

        // SHOW PUBLIC KEY
        case '2':
        {
            myMenu.ShowPublicKey();
            break;
        }

        // CREATE PUBLIC KEY
        case '3':
        {
            myMenu.CreatePublicKey();
            break;
        }

        // ERASE PUBLIC KEY
        case '4':
        {
            myMenu.ErasePublicKey();
            break;
        }

        // CREATE PRIVATE KEY
        case '5':
        {
            myMenu.CreatePrivateKey();
            break;
        }

        // SHOW PRIVATE KEY
        case '6':
        {
            myMenu.ShowPrivateKey();
            break;
        }

        // ERASE PRIVATE KEY
        case '7':
        {
            myMenu.ErasePrivateKey();
            break;
        }
        // ARITHMETICAL MENU
        case '8':
        {
            do
            {
                arithOption = myMenu.ArithmeticalMenu();

                switch (arithOption)
                {
                // PRIME
                case '1':
                {
                    myMenu.CheckPrime();
                    break;
                }

                // GCD
                case '2':
                {
                    myMenu.GreatestCommonDivisor();
                    break;
                }

                // COPRIMES
                case '3':
                {
                    myMenu.Coprimes();
                    break;
                }

                // ALL PRIMES IN RANGE
                case '4':
                {
                    myMenu.MenuAllPrimesInRange();
                    break;
                }

                // FACTORIZE
                case '5':
                {
                    myMenu.FactorizeNumber();
                    break;
                }

                // EULER'S FUNCTION
                case '6':
                {
                    myMenu.MenuEulerFunction();
                    break;
                }

                // EXIT ARITHMETICAL MENU
                case '7':
                {
                    break;
                }
                default:
                    std::cout << "\n [ERROR]: wrong output selection.\n";
                    std::cin.ignore();
                    std::cin.get();
                    break;
                }

            } while (arithOption!='7');

            break;
        }
        // EXIT
        case '9':
        {
            std::cout << "\n Exiting program.\n";
            break;
        }
        default:
            std::cout << "\n [ERROR]: wrong output selection.\n";
            std::cin.ignore();
            std::cin.get();
            break;
        }

    } while (mainOption!='9');
}



#include "Menu.h"
#include <iostream>


//TODO: Exception handleling on all these functions for the user to not to input something weird.
void Start()
{
    Menu menu;
    char option;

    do
    {
        option = menu.ShowMainMenu();

        switch (option)
        {
        // CREATE NEW PROFILE
        case '1':
        {
            Key PK, DK;
            KeyGenerator keyGen;
            PK.values[0] = 13;
            PK.values[1] = 17;
            PK = keyGen.GeneratePublicKey(PK.values[0], PK.values[1]);
            DK = keyGen.GeneratePrivateKey(PK);
            Profile profile{ PK, DK, "Tomas" };

            std::cout << " PUBLIC KEY: "; profile.ShowKeys(PK);
            std::cout << " PRIVATE KEY: ";  profile.ShowKeys(DK);

            Message message;
            std::string mensaje, dencrypted;
            std::vector<long long> encrypted;
            

            std::cout << "\n Mensaje: ";
            std::cin.ignore();
            std::getline(std::cin, mensaje);

            // encryption process
            encrypted = message.Encrypt(PK, mensaje);
            std::cout << "\n ";
            for (long long character : encrypted)
            {
                std::cout << character;
            }

            // dencryption process
            std::cout << "\n";
            dencrypted = message.Dencrypt(DK, encrypted);
            std::cout << "\n " << dencrypted;
            
            Confirm();
            break;
        }

        // SELECT PROFILE
        case '2':
        {
            Confirm();
            break;
        }

        // SEND MESSAGE
        case '3':
        {
            Confirm();
            break;
        }

        // OPEN MAILBOX
        case '4':
        {
            Confirm();
            break;
        }

        // REMOVE PROFILE
        case '5':
        {
            Confirm();
            break;
        }

        // CALCULATOR
        case '6':
        {
            menu.ModularCalculator();
            break;
        }
        // EXIT
        case '7':
        {
            std::cout << "\n Thanks for using RSA Simulator! :D\n";
            break;
        }
        default:
            std::cout << "\n [ERROR]: Wrong imput.\n";
            Confirm();
            break;
        }

    } while (option != '7');
}

void Confirm()
{
    std::cin.ignore();
    std::cin.get();
}

void ShowVector(std::vector<long long> show)
{
    std::cout << "\n [";
    for (int i=0; i<show.size(); i++)
    {
        std::cout << show[i];
        if (i < show.size()-1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "] ";
}

char Menu::ShowMainMenu()
{
    char option;

    system("cls");

    std::cout << "\n\tRSA MANAGER V.1.0"
        << "\n============================================="

        << "\n 1. Create a new profile."
        << "\n 2. Select an existing profile."
        << "\n 3. Send message to another profile."
        << "\n 4. Open mail box."
        << "\n 5. Remove a profile (Private Key needed)."
        << "\n 6. Access the Modular Arithmetic Calculator."
        << "\n 7. Exit."
        << "\n\n > Selection: ";
    std::cin >> option;
    system("cls");

    return option;
}

char Menu::ArithmeticalMenu()
{
    char option;

    system("cls");

    std::cout << "\n\tARITHMETICAL MENU V.1.0"
        << "\n============================================="
        << "\n 1. Check if a number is prime."
        << "\n 2. Greatest Common Divisor between two numbers."
        << "\n 3. Check if two numbers are coprime."
        << "\n 4. Display all prime numbers in a range."
        << "\n 5. Factorize a number into it's prime factors."
        << "\n 6. Calculate Euler's Totient of a number."
        << "\n 7. Go back."
        << "\n\n > Selection: ";
    std::cin >> option;
    system("cls");

    return option;
}

void Menu::ModularCalculator()
{
    char option;

    do
    {
        option = ArithmeticalMenu();

        switch (option)
        {
        // PRIME
        case '1':
        {
            CheckPrime();
            break;
        }

        // GCD
        case '2':
        {
            GCD();
            break;
        }

        // COPRIMES
        case '3':
        {
            CheckCoprimes();
            break;
        }

        // PRIMES IN A RANGE
        case '4':
        {

            break;
        }

        // FACTORIZE
        case '5':
        {
            FactorizeNumber();
            break;
        }

        // EULER'S TOTIENT
        case '6':
        {
            EulersTotient();
            break;
        }

        // EXIT
        case '7':
        {
            std::cout << "\n Returning to main menu. ";
            Confirm();
            break;
        }

        default:
            std::cout << "\n [ERROR]: Wrong imput. ";
            Confirm();
            break;
        }

    } while (option != '7');
}

void Menu::CheckPrime()
{
    long p;

    std::cout << "\n First number: ";
    std::cin >> p;

    if (p < 0)
    {
        std::cout << "\n [ERROR]: The number has to be positive. ";
    }
    else if(p==1)
    {
        std::cout << "\n 1, surprisingly, is not prime. ";
    }
    else
    {
        bool isPrime = arithmetics.IsPrimeNumber(p);

        std::cout << "\n " << p << " is";
        if (!isPrime)
            std::cout << " not";
        std::cout << " prime. ";
    }
    Confirm();
}

void Menu::GCD()
{
    long p, q;

    std::cout << "\n First number: ";
    std::cin >> p;
    std::cout << " Second number: ";
    std::cin >> q;

    if (p < 0 || q < 0)
    {
        std::cout << "\n [ERROR]: Both numbers have to be positive. ";
    }
    else
    {
        long gcd = arithmetics.GCD(p,q);

        if (p < q)
        {
            std::cout << "\n *(a permutation was required).";
            long aux;
            aux = p;
            p = q;
            q = aux;
        }
        std::cout << "\n GCD(" << p << ", " << q << ") = " << gcd << " ";
    }
    Confirm();
}

void Menu::CheckCoprimes()
{
    long long a, b;

    std::cout << "\n First number: ";
    std::cin >> a;
    std::cout << " Second number: ";
    std::cin >> b;

    std::cout << "\n " << a << " and " << b << " are";
    if (!arithmetics.AreCoprimes(a, b))
    {
        std::cout << " not";
    }
    std::cout << " coprimes. ";

    Confirm();
}

void Menu::FactorizeNumber()
{
    long long n;
    std::cout << "\n Number: ";
    std::cin >> n;

    std::vector<long long> factorized = arithmetics.Factorize(n);
    std::cout << "\n " << n << " = ";
    ShowVector(factorized);
    Confirm();
}

void Menu::EulersTotient()
{
    long long n, phi;
    std::cout << "\n Number: ";
    std::cin >> n;

    phi = arithmetics.EulerFunction(n);
    std::cout << "\n Phi(" << n << ") = " << phi << ". ";
    Confirm();
}
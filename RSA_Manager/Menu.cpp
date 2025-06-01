#include "Menu.h"
#include "Arithmetics.h"

char Menu::MainMenu()
{
    char option;

    system("cls");

    std::cout << "\n\tRSA MANAGER V.1.0"
        << "\n============================================="

        << "\n PUBLIC KEY:"
        << "\n-------------------------------------"
        << "\n 1. Set/Change prime numbers for Public Key."
        << "\n 2. Show Public Key."
        << "\n 3. Create Public Key."
        << "\n 4. Erase Public Key."

        << "\n\n PRIVATE KEY: "
        << "\n-------------------------------------"
        << "\n 5. Create Private Key."
        << "\n 6. Show Private Key (password will be needed)."
        << "\n 7. Erase Private Key (password will be needed)."

        << "\n\n OTHER FUNCTIONALITIES:"
        << "\n-------------------------------------"
        << "\n 8. Arithmetical Menu."
        << "\n 9. Exit program."
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
        << "\n 6. Calculate Euler's Function of a number."
        << "\n 7. Go back."
        << "\n\n > Selection: ";
    std::cin >> option;
    system("cls");

    return option;
}

void Menu::CheckPrime()
{
    Arithmetics operation;
    int num;
    bool isPrime;

    std::cout << "\n Number: ";
    std::cin >> num;

    isPrime = operation.IsPrimeNumber(num);

    std::cout << "\n " << num << " is";
    if (!isPrime)
    {
        std::cout << " not";
    }
    std::cout << " prime. ";
    
    std::cin.ignore();
    std::cin.get();
}

void Menu::GreatestCommonDivisor()
{
    Arithmetics operation;
    int n1, n2, gcd;

    std::cout << "\n First number: ";
    std::cin >> n1;
    std::cout << " Second number: ";
    std::cin >> n2;

    gcd = operation.GCD(n1, n2);

    if (n1 < n2)
    {
        std::cout << "\n (a permutation was needed)*";
    }
    std::cout << "\n GCD(" << n1 << ", " << n2 << ") = " << gcd << " ";

    std::cin.ignore();
    std::cin.get();
}

void Menu::Coprimes()
{
    Arithmetics operation;
    int n1, n2;
    bool coprimes;

    std::cout << "\n First number: ";
    std::cin >> n1;
    std::cout << " Second number: ";
    std::cin >> n2;

    coprimes = operation.AreCoprimes(n1, n2);

    std::cout << "\n " << n1 << " and " << n2 << " are";
    if (!coprimes)
    {
        std::cout << " not";
    }
    std::cout << " coprimes. ";

    std::cin.ignore();
    std::cin.get();
}

// TODO: Solve the upper range issue in a more 'stylish' way
void Menu::MenuAllPrimesInRange()
{
    Arithmetics operation;
    int leftBound, rightBound;

    std::cout << "\n Set the range of generation: ";
    std::cout << "\n  > Left bound: ";
    std::cin >> leftBound;
    std::cout << "  > Right bound: ";
    std::cin >> rightBound;

    if (leftBound<1 || rightBound>= 2147483647)
    {
        std::cout << "\n [ERROR]: Range out of bounds for unsigned int values. ";
    }
    else
    {
        std::vector<int> primesRange;
        primesRange = operation.AllPrimesInRange(leftBound, rightBound);

        if (primesRange.empty())
        {
            std::cout << "\n [ERROR]: No primes within (" << leftBound << ", " << rightBound << "). ";
        }
        else
        {
            std::cout << "\n There are " << primesRange.size() << " prime numbers within (" << leftBound << ", " << rightBound << "):";

            operation.ShowVector(primesRange);
        }
    }

    std::cin.ignore();
    std::cin.get();
}

void Menu::FactorizeNumber()
{
    Arithmetics operation;
    int number;

    std::cout << "\n Number to factorize: ";
    std::cin >> number;

    if (number < 1 || number >= 2147483647)
    {
        std::cout << "\n [ERROR]: Number out of bounds for unsigned int values. ";
    }
    else
    {
        std::vector<int> factorized;
        factorized = operation.Factorize(number);

        std::cout << "\n The number " << number << " can be factorized as the product of:";
        operation.ShowVector(factorized);
    }

    std::cin.ignore();
    std::cin.get();
}

void Menu::MenuEulerFunction()
{
    Arithmetics operation;
    int totient, number;

    std::cout << "\n Euler's Totient: ";
    std::cin >> number;

    if (number < 2)
    {
        std::cout << "\n [ERROR]: Euler's Totient has to be at least 2. ";
    }
    else
    {
        totient = operation.EulerFunction(number);
        std::cout << "\n Phi(" << number << ") = " << totient << " ";
    }

    std::cin.ignore();
    std::cin.get();
}

void Menu::UpdatePrimes()
{
    int updateP, updateQ;

    std::cout << "\n First number: ";
    std::cin >> updateP;
    std::cout << " Second number: ";
    std::cin >> updateQ;

    if (!operation.IsPrimeNumber(updateP) || !operation.IsPrimeNumber(updateQ))
    {
        std::cout << "\n [ERROR]: Both numbers must be primes. ";
    }
    else
    {
        opPublic.SetP(updateP);
        opPublic.SetQ(updateQ);
        std::cout << "\n Prime numbers updated successfully. ";
    }

    std::cin.ignore();
    std::cin.get();
}

void Menu::ShowPublicKey()
{
    std::vector<int> pKey;

    pKey = opPublic.GetPublicKey();

    if (!pKey.empty())
    {
        std::cout << "\n PUBLIC KEY:";
    }
    opPublic.ShowVector(pKey);

    std::cin.ignore();
    std::cin.get();
}

// TODO: Sofisticate the displaying such that it also warns you that if it's not empty, it'll rewrite it
void Menu::CreatePublicKey()
{
    bool created;
    created = opPublic.PublicKey();

    if (created)
    {
        std::cout << "\n Public Key created successfully. ";
    }
    else
    {
        std::cout << "\n [ERROR]: something happened. ";
    }

    std::cin.ignore();
    std::cin.get();
}

void Menu::ErasePublicKey()
{

}

void Menu::ShowPrivateKey()
{

}

void Menu::CreatePrivateKey()
{

}

void Menu::ErasePrivateKey()
{

}
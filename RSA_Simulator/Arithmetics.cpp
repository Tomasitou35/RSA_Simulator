#include "Arithmetics.h"

/*

#include "Arithmetics.h"

Arithmetics::Arithmetics()
{
    SetP(0);
    SetQ(0);
}

void Arithmetics::SetP(int pPrime)
{
    p = pPrime;
}

int Arithmetics::GetP()
{
    return p;
}

void Arithmetics::SetQ(int QPrime)
{
    q = QPrime;
}

int Arithmetics::GetQ()
{
    return q;
}

bool Arithmetics::IsPrimeNumber(int num)
{
    /*
        PRIME NUMBER VERIFICATION:

        A number is a prime if it only has 4 divisors, or 2 in natural numbers, been -+1 and
        the very number itself in both positive or negative version (therefore, natural ones
        will only have as divisors 1 and the number). For this program we'll use this second
        aception in order to simplify operations.

        Knowing that every natural number has at least 2 divisors, whenever we succeed just
        once on dividing a number which isn't 1 or whatever number we'd originally chose, this
        will automatically discard this number as a prime. Nonetheless, we only need to check
        divisors for the square root-size worth of the number, because all the following number will
        cuase a non-integer coeficent.

        Neither 1 nor 0 are prime numbers, that is, 2 is the one we'll start checking.
    */

/*
bool isPrime = true; // it's easier if we start assuming every number is prime
int i = 2; // index 

if (num <= 1)
{
    return false;
}

while (i <= std::sqrt(num) && isPrime)
{
    if (num % i == 0) // we found a valid divisor (bad news actually)
    {
        isPrime = false;
    }
    else
    {
        i++;
    }
}

return isPrime;
}

// TODO: Make something funny with this weirdo.
std::vector<int> Arithmetics::GeneratePrimes(int quantity, int from, int to)
{
    /*
        This method generates random prime numbers by using the clock system, a given range and
        uniform distribution, and stores them in a vector. Because ranges can be manually set,
        duplicate primes are allowed (on the other way certain ranges could cause infinite loops).
        In order to do so, first we need to check if all parameters are valid.

        For example, if we wanted to generate 4 prime numbers between 2 and 50, a coherent output
        would be [2, 17, 29, 47].

        example of range random number generation between bounds:
        - from = 2
        - to = 50 (48 random numbers possible)

    */
/*
    std::vector<int> primeVector;

    if (quantity <= 0 || from >= to)
    {
        return primeVector; // return an empty primeVector
    }

    std::vector<int> primesAvailable; // auxiliary primes' storage

    int candidate = from;

    // fill primesAvailable with ALL prime numbers in the range given
    while (candidate <= to)
    {
        if (IsPrimeNumber(candidate))
        {
            primesAvailable.push_back(candidate);
        }
        candidate++; // valid prime number in the bounds given
    }

    // for being sure
    if (primesAvailable.empty())
    {
        std::cout << "\n [ERROR]: No primes within (" << from << ", " << to << ").";
        return primeVector;
    }

    // setting the seed for random number generation
    std::random_device rd; // a seed source for the random number engine
    std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(0, primesAvailable.size() - 1); // fixing vector size

    // generating the final vector taking in consideration all the stored prime numbers
    int counter = 0;

    while (counter < quantity)
    {
        int randomNumber = distrib(gen);

        primeVector.push_back(primesAvailable[randomNumber]);
        counter++;
    }

    return primeVector;
}

void Arithmetics::ShowVector(std::vector<int> vector)
{
    if (vector.empty())
    {
        std::cout << "\n [ERROR]: The field is empty.";
    }
    else
    {
        std::cout << "\n [";
        for (int i = 0; i < vector.size(); i++)
        {
            // the last element in the vector
            if (i == vector.size() - 1)
            {
                std::cout << vector[i] << "]";
            }
            else
            {
                std::cout << vector[i] << ", ";
            }
        }
        std::cout << "\n";
    }
}

// TODO: It doesn't handle negative inputs
int Arithmetics::GCD(int dividend, int divisor)
{
    /*
        EUCLID'S ALGORITHM:

        It's used to find iteratively the greatest common divisor between two numbers.
        We start up with an expression with the form: a = c*b + d, which stands for the
        Remainder Theorem:
        a > Dividend
        b > Divisor
        c > Coeficent
        d > Remainder

        This could be applied recursively by following the next steps:
        1. Find the greatest coeficent and calculating it's remainder
        2. Because MATH; gcd(a,b) <-> gcd(b, d). Applying this simplifies the problem in size
        3. Repeat until the remainder reaches 0, which means that the divisor on that exact
           iteration, is the actual gcd of the original numbers.
    */

    // a = c * b + d <-------> gcd(a,b) = gcd(b,d) (just for visualization)
/*
    // permutation in case of wrong imput
    if (divisor > dividend)
    {
        int aux;

        aux = divisor;
        divisor = dividend;
        dividend = aux;
    }

    int coeficent = dividend / divisor;
    int remainder = dividend % divisor;

    if (remainder == 0)
    {
        return divisor;
    }
    else
    {
        GCD(divisor, remainder);
    }
}

bool Arithmetics::AreCoprimes(int a, int b)
{
    // two numbers are coprimes between each other if it's GCD is just 1
    return(GCD(a, b) == 1);
}

std::vector<int> Arithmetics::AllDivisors(int num)
{
    /*
        In this case we need to reach half of the size of the number given
    */
/*
    int i = 1;
    std::vector<int> divisors;

    // storing every possible divisor
    while (i <= (num / 2))
    {
        if (num % i == 0)
        {
            divisors.push_back(i);
        }

        i++;
    }
    return divisors;
}

std::vector<int> Arithmetics::AllPrimesInRange(int current, int range)
{
    std::vector<int> fixed;

    while (current < range)
    {
        if (IsPrimeNumber(current))
        {
            fixed.push_back(current);
        }
        current++;
    }

    return fixed;
}

std::vector<int> Arithmetics::Factorize(int num)
{
    std::vector<int> factorized;

    if (num <= 1)
    {
        std::cout << "\n [ERROR]: el numero debe ser entero y mayor que 1.\n";
        return factorized;
    }

    if (IsPrimeNumber(num))
    {
        factorized.push_back(num);
        return factorized;
    }

    // setup all candidates of prime division
    std::vector<int> primesInRange;
    primesInRange = AllPrimesInRange(1, num);

    int i = 0;
    int current = num;

    // stops whenever the current number to divide is 1 or we reached the end of the primes vector
    while (current > 1 && i < primesInRange.size())
    {

        int prime = primesInRange[i];

        if (current % prime == 0)
        {
            factorized.push_back(prime);
            current /= prime;
        }
        else
        {
            // encapsulate the iterator in order to keep the same divisor just in case is still valid
            i++;
        }
    }

    return factorized;
}

int Arithmetics::EulerFunction(int m)
{
    /*
        For each m >= 1, and phi(m) being the number of integers (x) comprimes with m
        that 1 <= x <= m, this function phi(·) is known as the Euler's Function.
        Let p be a prime number, then 1, 2, . . . . , p - 1 will also be comprimes with
        p, therefore phi(p) = p - 1.

        Let m >= 2 be the product by n-primes just as m = p1 · p2 · . . . · pn, it's
        factorization will be:

        phi(m) = m · (1 - 1/p1) · ... · (1 - 1/pn).
    */
/*
    if (IsPrimeNumber(m))
    {
        return (m - 1);
    }
    else
    {
        // phi(m) = m · (1 - 1/p1) · ... · (1 - 1/pn)

        int phi = 1; // the answer
        std::vector<int> factorized = Factorize(m);

        for (int i = 0; i < factorized.size(); i++)
        {
            int prime = factorized[i];

            // because we always substract the 1/p to 1, at the end we end up with just the product
            // between numerators, leading to: (p1-1)*(p2-1)*...*(pn-1), which is also phi(m)
            phi *= (prime - 1);
        }
        return phi;
    }
}

int Arithmetics::Congruences(float base, float exponent, int module)
{
    // base^exponent (mod module)

    // calculate de first power

    float power = powf(base, exponent);
    float delta = power / module;

    float resultUnRounded = (delta - trunc(delta)) * module;

    int result = round(resultUnRounded);

    return result;
}

*/

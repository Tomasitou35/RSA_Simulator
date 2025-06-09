#include "Arithmetics.h"

bool Arithmetics::IsPrimeNumber(long num)
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

bool isPrime = true; // it's easier if we start assuming every number is prime
int i = 2; // index 

if (num <= 1)
{
    return false;
}

while (i <= std::sqrt(num) && isPrime)
{
    if (num % i == 0) // we found a valid divisor (which are actually bad news)
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

long Arithmetics::GCD(long dividend, long divisor)
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

    // permutation in case of wrong imput order
    if (divisor > dividend)
    {
        long aux;

        aux = divisor;
        divisor = dividend;
        dividend = aux;
    }

    long coeficent = dividend / divisor;
    long remainder = dividend % divisor;

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

// TODO: I think this doesn't work as intended
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
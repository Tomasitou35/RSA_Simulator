#include "PublicAdministration.h"

void PublicAdministration::SetPublicKey(std::vector<int> MypublicKey)
{
    publicKey = MypublicKey;
}

std::vector<int> PublicAdministration::GetPublicKey()
{
    return publicKey;
}

void PublicAdministration::ShowVector(std::vector<int> vector)
{
    if (vector.empty())
    {
        std::cout << "\n [ERROR]: Public Key has not been created yet.";
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

bool PublicAdministration::PublicKey()
{
    std::vector<int> pKey;
    int p = this->p;
    int q = this->q;

    if (p == 0 || q == 0)
    {
        std::cout << "\n [ERROR]: A pair of primes are needed. ";
        return false;
    }

    int n = p * q;


    int phi = EulerFunction(n);
    int e = 2; // starting value
    bool found = false;

    // e has to be between 1 < e < phi(n), and be coprime with n
    while ((e < phi) && !found)
    {
        // in order to chose a good candidate for e, it will only validate
        // whatever coprime exists in the upper half of all possible digits
        if (AreCoprimes(e, phi) && e >= phi / 2)
        {
            found = true;

        }
        else
        {
            e++;
        }
    }

    pKey.push_back(n);
    pKey.push_back(e);
    SetPublicKey(pKey);

    return true;
}
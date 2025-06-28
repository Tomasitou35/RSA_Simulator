#include "RSA_Manager.h"

// TODO: Check if this works
bool RSA_Manager::SeekName(std::string name)
{
	int i = 0;
	while (i < profiles.size())
	{	
		Key k = profiles[i].GetPublicKey();
		std::cout << "\n Name: " << profiles[i].GetProfileName();

		std::cout << "\n Public Key: ";
		profiles[i].ShowKeys(k);
		
		k = profiles[i].GetPrivateKey();
		std::cout << " Private Key: ";
		profiles[i].ShowKeys(k);

		if (name == profiles[i].GetProfileName())
		{
			return true;
		}
		i++;
	}
	return false;
}

// TODO: Place holder
bool RSA_Manager::AddProfile(Profile profile)
{
	profiles.push_back(profile);
	return true;
}
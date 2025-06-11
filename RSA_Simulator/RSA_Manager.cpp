#include "RSA_Manager.h"

// TODO: Check if this works
bool RSA_Manager::SeekName(std::string name)
{
	int i = 0;
	while (i < profiles.size())
	{	
		if (name == profiles[i].GetProfileName())
		{
			return true;
		}
		std::cout << profiles[i].GetProfileName();
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
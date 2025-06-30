#include "RSA_Manager.h"

bool RSA_Manager::SeekName(std::string& name)
{
	int i = 0;
	while (i < profiles.size())
	{	
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

Profile RSA_Manager::SeekProfile(std::string& name)
{
	Profile empty{{},{},""};
	int i = 0;
	while (i < profiles.size())
	{
		if (name == profiles[i].GetProfileName())
		{
			return profiles[i];
		}
		i++;
	}
	return empty;
}

bool RSA_Manager::ChooseProfile(std::string& name)
{
	Profile found = SeekProfile(name);

	if (found.GetProfileName() == "")
	{
		return false;
	}

	choosen = found;
	return true;
}
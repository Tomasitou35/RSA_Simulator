#include "Profile.h"

Profile::Profile(Key PK, Key DK, std::string name)
{
	PublicKey = PK;
	privateKey = DK;
	profileName = name;
}

void Profile::SetProfileName(std::string& myProfileName)
{
	profileName = myProfileName;
}

std::string Profile::GetProfileName()
{
	return profileName;
}

void Profile::SetPublicKey(Key& myPublicKey)
{
	PublicKey = myPublicKey;
}

Key Profile::GetPublicKey()
{
	return PublicKey;
}

void Profile::SetPrivateKey(Key& myPrivateKey)
{
	privateKey = myPrivateKey;
}

Key Profile::GetPrivateKey()
{
	return privateKey;
}

void Profile::SetPassword(std::string& myPassword)
{
	password = myPassword;
}

std::string Profile::GetPassword()
{
	return password;
}

// TODO: If a users want to see their own Private Key, a PASSWORD
// (the 'd' of the DK, or an actual password set by the user, I've not decided yet)
// will be required.
void Profile::ShowKeys(Key key)
{
	std::cout << " [";
	for (int i = 0; i < 2; i++)
	{
		std::cout << key.values[i];
		if (i == 0)
		{
			std::cout << ", ";
		}
	}
	std::cout << "] \n";
}
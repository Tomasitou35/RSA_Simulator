#include "Profile.h"

Profile::Profile()
{
	privateKey = { 0,0 };
	PublicKey = { 0,0 };
	profileName = "";
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
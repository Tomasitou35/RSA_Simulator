#include "Profile.h"

Profile::Profile(Key PK, Key DK, std::string name)
{
	PK = { 0,0 };
	DK = { 0,0 };
	name = "";
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
#ifndef PROFILE_H
#define PROFILE_H

#include "Arithmetics.h"
#include <cstring>

struct Key
{
	long long values[2];
};

class Profile
{
private:

	std::string profileName;

	Key privateKey;


public:

	Key PublicKey;

	Profile(Key PK, Key DK, std::string name);

	void SetProfileName(std::string& myProfileName);

	std::string GetProfileName();

	void SetPublicKey(Key& myPublicKey);

	Key GetPublicKey();
};
	
#endif
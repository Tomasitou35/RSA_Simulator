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

	std::string password;

public:

	Key PublicKey;

	Profile(Key PK, Key DK, std::string name);

	void SetProfileName(std::string& myProfileName);

	void SetPublicKey(Key& myPublicKey);

	void SetPrivateKey(Key& myPrivateKey);

	void SetPassword(std::string& myPassword);

	std::string GetProfileName();

	Key GetPublicKey();

	Key GetPrivateKey();

	std::string GetPassword();

	void ShowKeys(Key key);

	void ShowProfile(Profile profile);
};
	
#endif
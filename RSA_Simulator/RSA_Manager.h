#ifndef RSA_MANAGER_H
#define RSA_MANAGER_H

#include "Profile.h";
#include "KeyGenerator.h";
#include "Message.h";

class RSA_Manager
{
private:

	std::vector<Profile> profiles;
	KeyGenerator keyGenerator;
	Message message;

public:

	// for now, it only asks for name
	bool AddProfile(Profile profile);
	bool SeekName(std::string name);

};

#endif

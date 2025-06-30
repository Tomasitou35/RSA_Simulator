#ifndef RSA_MANAGER_H
#define RSA_MANAGER_H

#include "Profile.h"
#include "KeyGenerator.h"
#include "Message.h"

class RSA_Manager
{
private:

	// where profiles are stored
	std::vector<Profile> profiles;
	Profile choosen{ {}, {}, ""};
	
public:

	KeyGenerator keyGenerator;
	Message message;
	Arithmetics arithmetics;

	// for now, it only asks for name
	bool AddProfile(Profile profile);
	bool SeekName(std::string& name);
	Profile SeekProfile(std::string& name);
	bool ChooseProfile(std::string& name);

};

#endif

#include "Message.h"

std::vector<long long> Message::Encrypt(Key PK, std::string message)
{
	std::vector<long long> encrypted;

	// transform every character into it's ASCII value
	for (char character : message)
	{
		long long ascii = static_cast<int>(character);
		encrypted.push_back(arithmetics.ModularPow(ascii, PK.values[1], PK.values[0]));
	}
	std::cout << "\n CIFRADO :D";
	
	return encrypted;
}

std::string Message::Dencrypt(Key DK, std::vector<long long> encrypted)
{
	std::vector<long long> dencrypted;
	std::string message;

	for (long long character : encrypted)
	{
		long long ascii = arithmetics.ModularPow(character, DK.values[0], DK.values[1]);
		message += static_cast<char>(ascii);
	}
	std::cout << "\n DESCIFRADO :D";

	return message;
}
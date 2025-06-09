#include "Menu.h"

int main()
{
    Start();
    return 0;
}




/*
        DOCUMENTATION HERE (for fast check):
        > https://en.cppreference.com/w/
        > https://stackoverflow.com/questions
        > https://www.w3schools.com/cpp/default.asp
*/

/*
        NEW DESIGN:

        MAIN MENU:
            1. Create a New Profile
            2. Select an Existing Profile
            3. Send Message to Another Profile
            4. Open Mail box
            5. Access the Modular Arithmetic Calculator
            6. Exit the Program

        1) Create a New Profile
            a. Prompt for the profile's name
            b. Check if the name already exists and validate input
            c. Proceed with key generation:

            PUBLIC KEY:
                a. If it already exists, display it (similar to a 2FA reminder)
                b. If not, continue with the creation process
                c. Key generation:
                    - Ask for two valid prime numbers
                    - Calculate n = p × q
                    - Compute Euler’s Totient φ(n)
                    - Choose a valid exponent e (coprime with φ(n))
                d. Show a message indicating whether the key was created or updated

            PRIVATE KEY:
                a. Since the private key depends only on the primes and the public exponent,
                   it will be generated or updated immediately:
                    - Compute the modular inverse of e mod φ(n), such that:
                        e × d ≡ 1 (mod φ(n))
                b. Show a similar confirmation message

        2) Select an Existing Profile
            a. Display the list of available profiles
            b. Validate the selection
            c. Set the current active profile

        3) Send Message to Another Profile
            a. Prompt the user to enter the message
            b. Prompt to select a recipient profile
            c. If valid, encode the message into ASCII and encrypt it using the recipient's public key

        4) Read Received Messages
            a. Check for new (or unread) messages
            b. Prompt to select one
            c. Decrypt the message using the active profile's private key:
                - If the message was not meant for this profile, the output will be unreadable
                - Otherwise, display the decrypted message correctly

        5) Access the Modular Arithmetic Calculator
            → Calculator with helper functions (GCD, mod inverse, exponentiation, etc.)

        6) Exit

        NOTES:
            > The active profile should be clearly displayed every time the main menu is shown

            > Users cannot send messages to themselves

            > The inbox (mailbox) is public: any profile can see encrypted messages,
              but only the intended recipient (with the correct private key) can decrypt them

            > Messages remain visible in the inbox even after being read, until manually deleted.
              This helps demonstrate RSA functionality
    */
# RSA Simulator

Educational console simulator implementing the RSA Algorithm entirely in C++.

This project was born primarily to improve my programming skills, as the first year of Computer Science is so outdated that I often
have to relearn from scratch what I should know. The introduction to modular arithmetic and the RSA Algorithm in a Mathematics II class
inspired me to create this application, which has become my first serious and functional project.

---

## Introduction

The RSA algorithm (Rivest–Shamir–Adleman) is a public key encryption system based on the computational difficulty of factoring large
prime numbers. Each user generates a pair of keys: public (for encryption) and private (for decryption). Its security lies in the fact
that, while multiplying two large primes is straightforward, decomposing the result is practically impossible with current methods.

This program implements from scratch:

- RSA key generation (public and private).
- Message encryption and decryption.
- A modular arithmetic calculator with functions to reinforce learning (GCD, modular inverse, modular exponentiation, etc.).

---

## Conceptual example of operation

Imagine Tomás wants to send a private letter to his friend Tiago. Tiago provides him with the unique address of his mailbox (his public key).
Tomás writes the letter, seals it, and sends it by mail. Although the mail carrier transports many letters, they cannot open them. Only
Tiago has the private key to open his mailbox and read the message:

> "How does light bend if photons have no mass?"

This example reflects the essence of asymmetric encryption: anyone can send messages using the public key, but only the owner of the
private key can read them.

---

## Main features

- Automatic generation of 'secure' RSA keys.
- Sending and receiving encrypted messages between profiles.
- Management of multiple profiles with their own key pairs and message inboxes.
- Modular calculator with essential modular arithmetic operations.
- Intuitive console interface to operate the program. (I'd tried my best)

---

## Requirements and installation

To compile and run this project you will need:

- A modern C++ compiler compatible with C++11 or higher (GCC, Clang, MSVC).
- Optional but recommended:
  - Visual Studio 2022 or higher (Windows).
  - Visual Studio Code with C++ extensions (Windows, Linux, macOS).
- (Optional) CMake if you wish to manage the project using this tool.
- Basic terminal knowledge to manually compile and run commands.

No external libraries are required; the code is pure C++.

---

## How to use

When starting the program, you will see a main menu with the following options:

1. Create a new profile (person).
2. Select an existing profile.
3. Send an encrypted message to another profile.
4. Read received encrypted messages.
5. Access the modular arithmetic calculator.
6. Exit the program.

Each profile has its own key pair and personal message inbox.

---

## Warning

Although the code respects the real logic of the RSA algorithm and functions correctly, IT IS NOT INTENDER FOR A REAL-WORLD USE.
This project is strictly educational and its use outside this context is discouraged.

---

## About RSA and mathematical foundations

The RSA algorithm is based on selecting two large prime numbers, 'p' and 'q', computing their product

n = p × q

and Euler’s totient function 

φ(n) = (p - 1) × (q - 1)

This relies on two key properties of Euler’s totient function:

φ(p) = p − 1, if p is prime.

If m and n are coprime, then φ(m × n) = φ(m) × φ(n)

After that, a positive integer 'e' is selected such that:

1 < e < φ(n)

e is coprime with φ(n)

This value e becomes the public exponent of the key.
To improve efficiency, e is often chosen to have a short binary representation (e.g., 65537), although very small values like e = 3 may
pose security risks if not handled carefully.

We then determine a value d, the modular multiplicative inverse of e module φ(n), i.e., a value such that:

e × d ≡ 1 mod φ(n)

In simpler terms, (d × e − 1) must be exactly divisible by φ(n).
This value d is usually calculated using the Extended Euclidean Algorithm.

Finally:

The public key is the pair (n, e)

The private key is the pair (n, d) — and must be kept secret!

Thanks to the properties of Euler’s function, Euler’s Theorem, and the Chinese Remainder Theorem, it can be proven that:

x ≡ (x^ed) mod n, for all x in Zₙ

This ensures that both encryption and decryption work correctly.

---

## License

This project is free for educational purposes. If you find it useful or entertaining, I am glad.

Also, I recommend checking out all the websites where I searched for information, both for programming skills issues 
and for expanding knowledge around RSA and cryptography.

- https://en.cppreference.com/w/
- https://stackoverflow.com/questions
- https://www.w3schools.com/cpp/default.asp
- https://es.wikipedia.org/wiki/RSA#Generacion_de_claves
- https://youtu.be/nvcssTsiavg?si=lhkNRym5UY_rSO63
- My University notes of Modular Arithmetics which unfortunately, I'm not allowed to share with you :/

---

## Contact

Created by Tomasitou35
[GitHub Profile](https://github.com/Tomasitou35)
Music composser and producer by passion, programmer by training.

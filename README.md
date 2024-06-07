# workoncryptography

The replacement assignment for the final exam of the Internet of Things course involves Tinkercad design and source code provided by the instructor. Students are required to edit the provided source code to implement secure message encryption when sending messages to a receiver. Subsequently, on the receiver's end, the message should be decrypted to display the original message.

Here I use the affine cipher method. The affine cipher is a type of monoalphabetic substitution cipher, where each letter in an alphabet is mapped to its numeric equivalent, encrypted using a simple mathematical function, and converted back to a letter. The mathematical formula is as follows:

E(x) = (ax + b) mod m

where:

- E(x) is the encrypted character.
- x is the numerical value of the original text character (starting from A=0, B=1, and so on).
- a and b are the cipher keys (the value of a and the value of b can be freely set by the creator).
- a must be chosen in such a way that it does not have any common factors with m (the number of letters in the alphabet).
- m is the number of letters in the alphabet (26 for the English alphabet).

Below is the explanation of the assignment that I have completed:

1. Encryption session:
   
   ![encryption_session](https://github.com/notRobot200/workoncryptography/assets/117140539/60699981-1048-4ed4-b132-5bf8bbb19680)

   Using the given encryption key (a = 3, b = 5) in the Affine Cipher, we can encrypt the message "Bogi" as follows:

   'B' -> 1
   'o' -> 14
   'g' -> 6
   'i' -> 8

   Next, apply the Affine Cipher encryption formula for each character:

   - For 'B' (numeric value 1):
     𝐸(1) = (3*1 + 5) mod 26 = 8 -> 'I'
     
   - For 'o' (numeric value 14):
     𝐸(14) = (3*14 + 5) mod 26 = 21 -> 'v'
     
   - For 'g' (numeric value 6):
     𝐸(6) = (3*6 + 5) mod 26 = 23 -> 'x'
     
   - For 'i' (numeric value 8):
     𝐸(8) = (3*8 + 5) mod 26 = 3 -> 'd'

   So, the encrypted result of "Bogi" is "Ivxd".

2. Decryption session:

   ![decryption_session](https://github.com/notRobot200/workoncryptography/assets/117140539/18286bc4-b137-4b2b-8106-6c0290c7d89b)

   Decryption Calculation:
   Each character of the encrypted message is converted back using the decryption formula of the Affine Cipher. The decryption formula is:
   𝐷(𝑥) = 𝑎^−1(𝑥−𝑏) mod 𝑚
   where x is the numerical value of the character in the alphabet, a_inv is the modular inverse of the multiplier a, b is the shift, and m is the number of letters in the alphabet.

   Mapping Characters to Numerical Values:
   First, we convert each character of the encrypted message ("Ivxd") to its numerical value according to their positions in the alphabet:

   'I' -> 8
   'v' -> 21
   'x' -> 23
   'd' -> 3

   Decryption Calculation:
   Next, we apply the decryption formula of the Affine Cipher for each character:
   The modular inverse of a (3) modulo m (26) is 9 (denoted as a_inv), because 3×9 mod 26 = 1
   
   - For 'I' (numeric value 8):
     𝐷(8) = 3^−1(8−5) mod 26
     𝐷(8) = 1 (B)

   - For 'v' (numeric value 21):
     𝐷(21) = 3^−1(21−5) mod 26
     𝐷(21) = 14 (o)

   - For 'x' (numeric value 23):
     𝐷(23) = 3^−1(23−5) mod 26
     𝐷(23) = 6 (g)

   - For 'd' (numeric value 3):
     𝐷(3) = 3^−1(3−5) mod 26
     𝐷(3) = 8 (i)

   So, the message "Ivxd" is successfully decrypted into "Bogi".






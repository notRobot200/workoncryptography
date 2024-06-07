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

   For 'B' (numeric value 1):
   𝐸(1) = (3*1 + 5) mod 26 = 8 -> 'I'
   For 'o' (numeric value 14):
   𝐸(14) = (3*14 + 5) mod 26 = 21 -> 'v'
   For 'g' (numeric value 6):
   𝐸(6) = (3*6 + 5) mod 26 = 23 -> 'x'
   For 'i' (numeric value 8):
   𝐸(8) = (3*8 + 5) mod 26 = 3 -> 'd'

   So, the encrypted result of "Bogi" is "Ivxd".

#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
String message;
String encryptedMessage = "";
const int a = 3; // multiplier
const int b = 5; // shift

// Fungsi untuk mengenkripsi karakter menggunakan Affine Cipher
char encryptChar(char ch) {
  if (isUpperCase(ch)) {
    return (char)((((a * (ch - 'A')) + b) % 26) + 'A');
  } else if (isLowerCase(ch)) {
    return (char)((((a * (ch - 'a')) + b) % 26) + 'a');
  }
  return ch;
}

void setup() {
  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Message TX:");
  lcd.setCursor(0, 1);

  pinMode(1, OUTPUT);
  message = "Bogi";
  
  // Mengenkripsi pesan
  for (byte i = 0; i < message.length(); i++) {
    encryptedMessage += encryptChar(message[i]);
  }

  // Tampilkan pesan asli
  lcd.print(message);
  // Kirim pesan terenkripsi melalui serial port
  for (byte i = 0; i < encryptedMessage.length(); i++)
    Serial.write(encryptedMessage[i]);
}

void loop() {
}

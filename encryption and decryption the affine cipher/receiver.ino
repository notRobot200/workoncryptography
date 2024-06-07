#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
String encryptedMessage;
String decryptedMessage = "";
char val;
const int a = 3; // multiplier (sama seperti yang digunakan dalam enkripsi)
const int b = 5; // shift (sama seperti yang digunakan dalam enkripsi)
const int m = 26; // jumlah huruf dalam alfabet

// Fungsi untuk menghitung invers modular dari a
int modInverse(int a, int m) {
  a = a % m;
  for (int x = 1; x < m; x++) {
    if ((a * x) % m == 1) {
      return x;
    }
  }
  return 1;
}

const int a_inv = modInverse(a, m);

// Fungsi untuk mendekripsi karakter menggunakan Affine Cipher
char decryptChar(char ch) {
  if (isUpperCase(ch)) {
    return (char)((a_inv * ((ch - 'A' - b + m)) % m) + 'A');
  } else if (isLowerCase(ch)) {
    return (char)((a_inv * ((ch - 'a' - b + m)) % m) + 'a');
  }
  return ch;
}

void setup() {
  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Message RX:");
  lcd.setCursor(0, 1);

  pinMode(0, INPUT);
  delay(2000);
}

void loop() {
  if (Serial.available() > 0) {
    val = Serial.read();
    encryptedMessage = String(encryptedMessage + val);
    
    // Dekripsi pesan
    decryptedMessage = "";
    for (byte i = 0; i < encryptedMessage.length(); i++) {
      decryptedMessage += decryptChar(encryptedMessage[i]);
    }
    
    lcd.setCursor(0, 1);
    lcd.print(decryptedMessage);
  }
}

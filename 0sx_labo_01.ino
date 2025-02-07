const int LED = 13; // Utilisation de la broche 13
const int dureeAllume = 2000;
const int dureeEteint = 2000;
const int dureeCligno = 250; // 250ms ON, 250ms OFF
const int nbCligno = ceil(3/2)+1; // Calculé pour 2413335
const int dureeVariation = 2048;
const int niveauPWM = 256;


void allumerLED() {
    Serial.println("Allume - 2413335");
    digitalWrite(LED, HIGH);
    delay(dureeAllume);
    digitalWrite(LED, LOW);
     delay(dureeEteint);
}

void clignoterLED() {
    Serial.println("Clignotement - 2413335");
    for (int i = 0; i < nbCligno; i++) {
        digitalWrite(LED, HIGH);
        delay(dureeCligno);
        digitalWrite(LED, LOW);
        delay(dureeCligno);
    }
}

void variation() {
 Serial.println("Variation - 2413335"); 
const int delaiVariation= dureeVariation/niveauPWM;
for(int i= 255; i >=0;i--){
  analogWrite(LED, i);
  delay(delaiVariation);
}
}



void eteindreLED() {
    Serial.println("Éteint - 2413335");
    digitalWrite(LED, LOW);
    delay(dureeEteint);
}

void setup() {
    pinMode(LED, OUTPUT);
    Serial.begin(9600);
    
}

void loop() {
    allumerLED();
    clignoterLED();
    variation();
    eteindreLED();
}
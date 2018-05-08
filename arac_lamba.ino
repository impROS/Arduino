//Ledler
int ledDortlu = 11;
int ledSag = 10;
int ledSol = 8;
int ledFar = 9;
//int besVolt=7;

int buzzer = 12;
//Led Durum
boolean solDurum = false;
boolean sagDurum = false;
boolean dortluDurum = false;
boolean farDurum = false;

//Sureler
int sureDortlu = 500;
int sureSagSinyal = 500;
int sureSolSinyal = 500;

//Butonlar
int butonDortlu = 3;
int butonSagSinyal = 2;
int butonSolSinyal = 18;
int butonFar = 19;

int sayac = 0;
void setup() {
  //Pin Hazirlama
  pinMode(ledDortlu, OUTPUT);
  pinMode(ledSag, OUTPUT);
  pinMode(ledSol, OUTPUT);
  pinMode(ledFar, OUTPUT);
 // pinMode(besVolt,OUTPUT);

  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);

  //Kesmeler
  attachInterrupt(digitalPinToInterrupt(butonSagSinyal), sagSinyalOku, CHANGE);
  attachInterrupt(digitalPinToInterrupt(butonDortlu), dortluOku, CHANGE );
  attachInterrupt(digitalPinToInterrupt(butonSolSinyal), solSinyalOku, CHANGE);
  attachInterrupt(digitalPinToInterrupt(butonFar), farOku, CHANGE);
  //  for(int i =8;i<14;i++){
  //    pinMode(i,OUTPUT);
  //    digitalWrite(i,HIGH);
  //    }

 // digitalWrite(besVolt,HIGH);

}

void loop() {

  dortluDegis(dortluDurum);
  sagSinyalDegis(sagDurum);
  solSinyalDegis(solDurum);
  farDegis(farDurum);


}
void sagSinyalOku() {
  sayac++;
  if (sayac % 2 == 0) {
    Serial.println("sagSinyal");
    sagDurum = !sagDurum;
    sayac = 0;
  }
}
void solSinyalOku() {
  sayac++;
  if (sayac % 2 == 0) {
    Serial.println("solSinyal");
    solDurum = !solDurum;
    sayac = 0;
  }
}
void dortluOku() {
  //sayac++;
  // if (sayac % 2 == 0) {
 boolean butonOku = digitalRead(3);

    while (digitalRead(3) == HIGH) {}
    if (digitalRead(3) == LOW) {
     // delay(1000);
      Serial.println("Dortlu");
      dortluDurum = !dortluDurum;
    }


    // 

  //}

  //  sayac = 0;
  //}
  // if(ledDurum)

}
void farOku() {
 boolean butonOku = digitalRead(butonFar);

    while (digitalRead(butonFar) == HIGH) {}
    if (digitalRead(butonFar) == LOW) {
    Serial.println("Far");
    farDurum = !farDurum;
    }
  }
  // if(ledDurum)


void dortluDegis(boolean dortluDurum) {
  if (dortluDurum) {
    sagDurum = false;
    solDurum = false;
    digitalWrite(ledDortlu, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(sureDortlu);
    digitalWrite(ledDortlu, LOW);
    digitalWrite(buzzer, LOW);
    delay(sureDortlu);
  } else {
    digitalWrite(ledDortlu, LOW);
    digitalWrite(buzzer, LOW);
  }
}
void sagSinyalDegis(boolean sagDurum) {
  if (sagDurum) {
    dortluDurum = false;
    solDurum = false;
    digitalWrite(ledSag, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(sureSagSinyal);
    digitalWrite(ledSag, LOW);
    digitalWrite(buzzer, LOW);
    delay(sureSagSinyal);
  } else {
    digitalWrite(ledSag, LOW);
    digitalWrite(buzzer, LOW);
  }
}
void solSinyalDegis(boolean solDurum) {
  if (solDurum) {
    dortluDurum = false;
    sagDurum = false;
    digitalWrite(ledSol, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(sureSolSinyal);
    digitalWrite(ledSol, LOW);
    digitalWrite(buzzer, LOW);
    delay(sureSolSinyal);
  } else {
    digitalWrite(ledSol, LOW);
    digitalWrite(buzzer, LOW);
  }
}
void farDegis(boolean farDurum) {
  if (farDurum) {
    digitalWrite(ledFar, HIGH);
  } else {
    digitalWrite(ledFar, LOW);
  }
}

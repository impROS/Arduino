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
unsigned long simdikiZaman;
unsigned long basmaZamani;
unsigned long fark;
int dortluSayac = 0;
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
  attachInterrupt(digitalPinToInterrupt(butonSagSinyal), sagSinyalOku, FALLING);
  attachInterrupt(digitalPinToInterrupt(butonDortlu), dortluOku, FALLING );
  attachInterrupt(digitalPinToInterrupt(butonSolSinyal), solSinyalOku, FALLING);
  attachInterrupt(digitalPinToInterrupt(butonFar), farOku, FALLING);
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
  if (digitalRead(butonSagSinyal) == LOW) {
    sayac++;
    if (sayac % 2 == 0) {
      sayac = 0;
      dortluSayac++;
      if (dortluSayac == 1) {
        basmaZamani = millis();
        // Serial.println(" ilk Sag Rising : ");
        // Serial.print(sayac);
        sagDurum = !sagDurum;
        Serial.print(" Sag Sinyal : ");
        Serial.println(sagDurum);
      } else {
        simdikiZaman = millis();
        fark = simdikiZaman - basmaZamani;
        if (fark > 200) {
          //Serial.print(" Sag Rising : ");
          //Serial.println(sayac);
          // Serial.print(" Sag Fark : ");
          // Serial.println(fark);
          sagDurum = !sagDurum;
          basmaZamani = millis();

          Serial.print(" Sag Sinyal : ");
          Serial.println(sagDurum);
        }
      }
    }
  }
}
void solSinyalOku() {
  if (digitalRead(butonSolSinyal) == LOW) {
    sayac++;
    if (sayac % 2 == 0) {
      sayac = 0;
      dortluSayac++;
      if (dortluSayac == 1) {
        basmaZamani = millis();
        //Serial.println(" ilk Sag Rising : ");
        // Serial.print(sayac);
        solDurum = !solDurum;
        Serial.print(" Sol Sinyal : ");
        Serial.println(solDurum);
      } else {
        simdikiZaman = millis();
        fark = simdikiZaman - basmaZamani;
        if (fark > 200) {

          //Serial.println(sayac);
          //Serial.print(" Sag Fark : ");
          //Serial.println(fark);
          solDurum = !solDurum;
          Serial.print(" Sol Sinyal : ");
          Serial.println(solDurum);
          basmaZamani = millis();
        }
      }
    }
  }
}



void dortluOku() {
  if (digitalRead(butonDortlu) == LOW) {
    sayac++;
    if (sayac % 2 == 0) {
      sayac = 0;
      dortluSayac++;
      if (dortluSayac == 1) {
        basmaZamani = millis();
        dortluDurum = !dortluDurum;
        Serial.print(" dortluDurum Sinyal : ");
        Serial.println(dortluDurum);
      } else {
        simdikiZaman = millis();
        fark = simdikiZaman - basmaZamani;
        if (fark > 200) {
          dortluDurum = !dortluDurum;
          basmaZamani = millis();
          Serial.print(" dortluDurum Sinyal : ");
          Serial.println(dortluDurum);
        }
      }
    }
  }
}

void farOku() {
  if (digitalRead(butonFar) == LOW) {
    sayac++;
    if (sayac % 2 == 0) {
      sayac = 0;
      dortluSayac++;
      if (dortluSayac == 1) {
        basmaZamani = millis();
        farDurum = !farDurum;
        Serial.print(" far  : ");
        Serial.println(farDurum);
      } else {
        simdikiZaman = millis();
        fark = simdikiZaman - basmaZamani;
        if (fark > 200) {
          farDurum = !farDurum;
          basmaZamani = millis();
          Serial.print(" far  : ");
          Serial.println(farDurum);
        }
      }
    }
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

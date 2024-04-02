// C++ code

void setup()
{
  pinMode(7, OUTPUT); // Définit la broche 7 comme une sortie
  pinMode(2, INPUT);  // Définit la broche 2 comme une entrée
  digitalWrite(7, LOW); // Initialise la broche 7 à LOW
}

void loop()
{
  if (digitalRead(2) == HIGH) // Si la broche 2 est HIGH
    digitalWrite(7, HIGH);    // Met la broche 7 à HIGH
  else                          // Sinon
    digitalWrite(7, LOW);     // Met la broche 7 à LOW
}

//Definindo o numero maximo de fases
int tamanhoJogo[10] = {};

//Declarando as portas dos leds
int pinoLeds[4] = { 14, 26, 27, 12 };
//Declarando as portas dos botoes
int pinoBotoes[5] = { 19, 4, 17, 16, 25 };

//Variaveis para auxiliar na logica do jogo
int fase = 0;
int win = 0;
bool perdeu = false;

void setup() {
  Serial.begin(9600);

  //Definindo a saida dos leds
  for (int i = 0; i < 4; i++) {
    pinMode(pinoLeds[i], OUTPUT);
  }

  //Definindo a saida dos botoes
  for (int i = 0; i < 5; i++) {
    pinMode(pinoBotoes[i], INPUT);
  }

  //Sinaliza que o jogo vai comecar
  digitalWrite(14, HIGH);
  digitalWrite(26, HIGH);
  digitalWrite(27, HIGH);
  digitalWrite(12, HIGH);
  delay(500);
  digitalWrite(14, LOW);
  digitalWrite(26, LOW);
  digitalWrite(27, LOW);
  digitalWrite(12, LOW);
  delay(500);
  digitalWrite(14, HIGH);
  digitalWrite(26, HIGH);
  digitalWrite(27, HIGH);
  digitalWrite(12, HIGH);
  delay(500);
  digitalWrite(14, LOW);
  digitalWrite(26, LOW);
  digitalWrite(27, LOW);
  digitalWrite(12, LOW);
  delay(1000);
}

void loop() {
  //Gera uma ordem aleatoria
  int aleatorio = random(4);
  tamanhoJogo[fase] = aleatorio;
  fase = fase + 1;

  //Faz acender os leds que foram gerados na ordem aleatoria
  for (int i = 0; i < fase; i++) {
    digitalWrite(pinoLeds[tamanhoJogo[i]], HIGH);
    delay(500);
    digitalWrite(pinoLeds[tamanhoJogo[i]], LOW);
    delay(100);
  }

  //Salva a jogada do usuario e compara com a jogada programanda no random
  int play = 0;
  for (int i = 0; i < fase; i++) {
    bool jogou = false;
    while (!jogou) {
      for (int i = 0; i <= 3; i++) {
        if (digitalRead(pinoBotoes[i]) == HIGH) {
          play = i;
          digitalWrite(pinoLeds[i], HIGH);
          delay(300);
          digitalWrite(pinoLeds[i], LOW);
          jogou = true;
        }
      }
    }
    //Menssage informando que o jogador errou
    if (tamanhoJogo[win] != play) {
      int selascou = true;
      while (selascou = true) {
        digitalWrite(14, HIGH);
        delay(50);
        digitalWrite(14, LOW);
        delay(50);
        if (digitalRead(25) == HIGH) {
          //Sinaliza que o jogo vai recomecar
          digitalWrite(14, HIGH);
          digitalWrite(26, HIGH);
          digitalWrite(27, HIGH);
          digitalWrite(12, HIGH);
          delay(500);
          digitalWrite(14, LOW);
          digitalWrite(26, LOW);
          digitalWrite(27, LOW);
          digitalWrite(12, LOW);
          delay(500);
          digitalWrite(14, HIGH);
          digitalWrite(26, HIGH);
          digitalWrite(27, HIGH);
          digitalWrite(12, HIGH);
          delay(500);
          digitalWrite(14, LOW);
          digitalWrite(26, LOW);
          digitalWrite(27, LOW);
          digitalWrite(12, LOW);
          delay(1000);
          perdeu = true;
          break;
        }
      }
      break;
    }
    win = win + 1;
  }
  win = 0;


  //Zerar as variaveis de auxilio caso o usuario cometa um erro
  if (perdeu == true) {
    tamanhoJogo[10] = {};
    fase = 0;
    win = 0;
    perdeu = false;
  }
  delay(1000);
}

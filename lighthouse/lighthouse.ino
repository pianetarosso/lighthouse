// C++ code
//
#define LEDS_COUNT 3
#define POTENTIOMETER_PIN 3
#define LED_MIN 50
#define LED_MAX 200

int leds[] = {0,1,4};
int currentLedIndex = 0;
int brightness = 0;

void setup()
{
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(4, OUTPUT);  
  pinMode(POTENTIOMETER_PIN, INPUT);

  analogWrite(leds[0], 0);
  analogWrite(leds[1], 0);
  analogWrite(leds[2], 0);
}

void loop()
{
  if (brightness >= LED_MAX) {
    brightness = 0;
    if (currentLedIndex + 1 >= LEDS_COUNT) {
    	currentLedIndex = 0;
    } else {
      currentLedIndex = currentLedIndex + 1;
    }
  }
  
  int previousLedIndex = currentLedIndex - 1;
  if (previousLedIndex < 0) {
    previousLedIndex = LEDS_COUNT - 1;
  }
  
  analogWrite(leds[currentLedIndex], brightness);    
  if (LED_MAX - brightness < LED_MIN) {
    analogWrite(leds[previousLedIndex], 0);
  } else {
    analogWrite(leds[previousLedIndex], max(LED_MAX - brightness, LED_MIN));
  }
  int time = map(analogRead(POTENTIOMETER_PIN), 0, 1023, 1, 100);
  delay(time);
  brightness = brightness + 1;
}
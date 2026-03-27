#define LED_PIN_Y 16
#define LED_PIN_R 17

// PWM 设置
const int freq = 5000;
const int resolution = 8;

// 呼吸控制变量
int brightness = 0;
int fadeAmount = 5;
unsigned long lastFadeTime = 0;
const int interval = 10;//频闪速率

void setup() {
  Serial.begin(115200);

  ledcAttach(LED_PIN_Y, freq, resolution);
  ledcAttach(LED_PIN_R, freq, resolution);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - lastFadeTime >= interval) {
    lastFadeTime = currentMillis;

    ledcWrite(LED_PIN_Y, brightness);
    ledcWrite(LED_PIN_R, 255 - brightness);

    brightness += fadeAmount;

    if (brightness <= 0 || brightness >= 255) {
      fadeAmount = -fadeAmount;
    }
  }
}
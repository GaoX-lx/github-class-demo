const int ledPin = 2;
unsigned long lastMillis = 0; // 记录上次状态变化时间
const long interval = 500;    // 500ms 切换一次状态 → 1Hz
int ledState = LOW;           // 当前LED状态

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  unsigned long now = millis(); // 获取当前时间
  // 如果时间差超过 interval，就切换LED
  if (now - lastMillis >= interval) {
    lastMillis = now;          // 更新时间记录
    ledState = !ledState;      // 翻转状态（LOW ↔ HIGH）
    digitalWrite(ledPin, ledState);
  }
}
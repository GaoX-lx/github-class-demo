const int ledPin = 26;
unsigned long lastMillis = 0;

// 定义SOS的节奏：状态 = {亮时间, 灭时间, 重复次数}
struct Blink { int on; int off; int count; };
Blink sos[] = {
  {200, 200, 3},  // 三短闪
  {600, 200, 3},  // 三长闪
  {200, 200, 3},  // 三短闪
  {0, 2000, 1}    // 长停顿（亮0ms=灭）
};
int patternIndex = 0; // 当前节奏组索引
int blinkCount = 0;   // 当前组内闪烁次数
int state = 0;        // 0=亮，1=灭

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  unsigned long now = millis();
  Blink current = sos[patternIndex];

  if (now - lastMillis >= (state == 0 ? current.on : current.off)) {
    lastMillis = now;
    if (state == 0) {
      digitalWrite(ledPin, LOW);  // 灭
      state = 1;
      blinkCount++;
      // 当前组闪烁次数够了，切换到下一组
      if (blinkCount >= current.count) {
        blinkCount = 0;
        patternIndex = (patternIndex + 1) % 4; // 循环4组
      }
    } else {
      digitalWrite(ledPin, HIGH); // 亮
      state = 0;
    }
  }
}
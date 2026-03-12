// 定义板载LED引脚
#define LED_PIN 2

void setup() {
  // 初始化串口通信，波特率115200
  Serial.begin(115200);
  // 将LED引脚设置为输出模式
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // 向串口发送消息，loop循环
  Serial.println("Hello ESP32!");
  // 点亮LED
  digitalWrite(LED_PIN, HIGH);
  // 等待1000毫秒（1秒）
  delay(1000);
  // 熄灭LED
  digitalWrite(LED_PIN, LOW);
  // 再等待1秒
  delay(1000);
}
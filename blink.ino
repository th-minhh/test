//Sử dụng serial bluetooth terminal 
#include "BluetoothSerial.h" // Thư viện Bluetooth Serial cho ESP32

BluetoothSerial SerialBT; // Tạo đối tượng Bluetooth

const int ledPin = 2; // Chân kết nối LED

void setup() {
  pinMode(ledPin, OUTPUT); // Thiết lập chân LED là OUTPUT
  Serial.begin(115200); // Khởi tạo giao tiếp Serial cho debugging
  SerialBT.begin("ESP32_LED_Control"); // Đặt tên Bluetooth
  Serial.println("Bluetooth is ready. Pair and send commands: ON or OFF");
}

void loop() {
  if (SerialBT.available()) { // Kiểm tra xem có dữ liệu nhận được qua Bluetooth
    String command = SerialBT.readStringUntil('\n'); // Đọc chuỗi lệnh
    command.trim(); // Loại bỏ khoảng trắng ở đầu và cuối chuỗi

    if (command == "ON") {
      digitalWrite(ledPin, HIGH); // Bật LED
      Serial.println("LED is ON");
      SerialBT.println("LED is ON"); // Phản hồi lại qua Bluetooth
    } else if (command == "OFF") {
      digitalWrite(ledPin, LOW); // Tắt LED
      Serial.println("LED is OFF");
      SerialBT.println("LED is OFF"); // Phản hồi lại qua Bluetooth
    } else {
      Serial.println("Invalid command");
      SerialBT.println("Invalid command. Use ON or OFF.");
    }
  }
}

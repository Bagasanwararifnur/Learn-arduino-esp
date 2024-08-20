#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClient.h>

int val = 0;

const char* ssid = "my_SSID";
const char* password = "my_Password";

const char* serverPath = "http://php_location.php"; //Learn using mysql by default the php file need to put in httdocs folder inside xampp folder

void setup() {
  Serial.begin(115200);

  // Menghubungkan ke WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Menghubungkan ke WiFi...");
  }
  Serial.println("Terhubung ke WiFi");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    String serverURL = String(serverPath) + "?val=" + val;

    // Memulai request ke server
    http.begin(serverURL.c_str());
    int httpResponseCode = http.GET();

    Serial.println("");
    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println(response);
    } else {
      Serial.print("Error message: ");
      Serial.println(http.errorToString(httpResponseCode).c_str());
    }

    Serial.println("HTTP Response: " + String(httpResponseCode));
    Serial.println("URL Server: " + serverURL);
    
    delay(500);
    val += 1;
  }
}

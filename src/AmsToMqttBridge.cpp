#include <WiFi.h>
#define SSID "YOURSSIDHERE"
#define PSK "YOURPASSWORDHERE"
unsigned long lastSysout = 0;

void setup() {
	Serial.begin(115200);
	Serial.setDebugOutput(true);
	WiFi.mode(WIFI_STA);
	WiFi.begin(SSID, PSK);
}
void loop() {
	unsigned long now = millis();
	if(now-lastSysout > 30000) {
		IPAddress dns1 = WiFi.dnsIP(0);
		Serial.printf("DNS: %s\n", dns1.toString().c_str());
		lastSysout = now;
	}
	yield();
}

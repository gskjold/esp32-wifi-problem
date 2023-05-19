#include <WiFi.h>
#include <lwip/dns.h>

#define SSID "YOURSSIDHERE"
#define PSK "YOURPASSWORDHERE"
unsigned long lastSysout = 0;

void setup() {
	Serial.begin(115200);
	Serial.setDebugOutput(true);
	WiFi.mode(WIFI_STA);
	WiFi.begin(SSID, PSK);
	WiFi.waitForConnectResult();
	//WiFi.enableIpV6(); // This fixes this issue
}

void loop() {
	unsigned long now = millis();
	if(now-lastSysout > 1000) {
		IPAddress dns1 = WiFi.dnsIP(0);
		Serial.printf("DNS: %s\n", dns1.toString().c_str());
		IPAddress res;
		int ret = WiFi.hostByName("hub.amsleser.no", res);
		Serial.printf("hub.amsleser.no -> %s (%d)\n", res.toString().c_str(), ret);
		dns_clear_cache();
		lastSysout = now;
	}
	delay(10);
	yield();
}

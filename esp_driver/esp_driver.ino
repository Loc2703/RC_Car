#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

WiFiUDP udp;
unsigned int localUdpPort = 4210;
unsigned char incomingByte = 119;

void setup() {
    // WiFi.mode(WIFI_STA); // explicitly set mode, esp defaults to STA+AP
    // it is a good practice to make sure your code sets wifi mode how you want it.

    // put your setup code here, to run once:
    Serial.begin(115200);
    Serial.println();

    //WiFiManager, Local intialization. Once its business is done, there is no need to keep it around
    WiFiManager wm;

    // reset settings - wipe stored credentials for testing
    // these are stored by the esp library
    // wm.resetSettings();

    // Automatically connect using saved credentials,
    // if connection fails, it starts an access point with the specified name ( "AutoConnectAP"),
    // if empty will auto generate SSID, if password is blank it will be anonymous AP (wm.autoConnect())
    // then goes into a blocking loop awaiting configuration and will return success result

    bool res;
    // res = wm.autoConnect(); // auto generated AP name from chipid
    // res = wm.autoConnect("AutoConnectAP"); // anonymous ap
    res = wm.autoConnect("AutoConnectAP","password"); // password protected ap

    if(!res) {
        Serial.println("Failed to connect");
        // ESP.restart();
    } 
    else {
        //if you get here you have connected to the WiFi    
        Serial.println("connected...yeey :)");
    }

    //Start UDP
    udp.begin(localUdpPort);
    Serial.printf("Now listening at IP %s, UDP port %d\n", WiFi.localIP().toString().c_str(), localUdpPort);

}

void loop() {
    // put your main code here, to run repeatedly:   

    // check udp receiver
    int packetSize = udp.parsePacket();

    if(packetSize)
    {
      incomingByte = udp.read();
    }
    unsigned char stmRequest = Serial.read();
    if(stmRequest == 0xAA)
    {
      // Send data to uart
      // Serial.printf("UDP content: %u - %c\n",incomingByte, incomingByte);
      Serial.write(incomingByte);
      incomingByte = 119;
    }

}

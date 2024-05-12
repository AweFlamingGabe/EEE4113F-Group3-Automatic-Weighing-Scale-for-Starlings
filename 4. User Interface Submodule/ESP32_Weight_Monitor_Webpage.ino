

#include <Arduino.h>
#if defined(ESP32) || defined(ARDUINO_RASPBERRY_PI_PICO_W)
#include <WiFi.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#elif __has_include(<WiFiNINA.h>)
#include <WiFiNINA.h>
#elif __has_include(<WiFi101.h>)
#include <WiFi101.h>
#elif __has_include(<WiFiS3.h>)
#include <WiFiS3.h>
#endif

#include <WebServer.h>
#include "myWebPage.h" // Include HTML and JavaScript code
#include <ESP_Google_Sheet_Client.h>
#include <GS_SDHelper.h> // For SD/SD_MMC mounting helper


#define USE_INTRANET

#define WIFI_SSID "TP-Link_516F"
#define WIFI_PASSWORD "00754712"

#define PROJECT_ID "esp32-datalogging-421011"

// Service Account's client email
#define CLIENT_EMAIL "esp32-gabe@esp32-datalogging-421011.iam.gserviceaccount.com"

// Service Account's private key
const char PRIVATE_KEY[] PROGMEM = "-----BEGIN PRIVATE KEY-----\nMIIEvAIBADANBgkqhkiG9w0BAQEFAASCBKYwggSiAgEAAoIBAQCqwHDn0Ib8W6se\nuFO1KVS1kXxEBGvNJGeS/4G3odss9r4VuiRfqR2Sq3HYmkcgaEg4G87DOryoSZYe\nVWrLFAW0bLvXHIXJWRXT/X/vHNnb1Rhaxz7BSr5il+WVYxz960mhjMvtKwGd/CZj\nJPuBaLYtX1skFUuQChz3qvvSyYWDQmA0ri2+6yosZ/lQKEfJliNj47A1b1T5kGqo\nXtjR/FIR1kGOCUVGqEU34KLpTGtjnCJjf/izSDpX8J3WRKXSJqdadCMXl5U/RgRL\nZYXUYFo7mISbrikyLYGzO6FCzN1Kd8wACqbGGiMz1hSKw77QcuV37CxOwaNrbEP8\nwPUIWOiRAgMBAAECggEAAI3zEjLJepL1NFXw+ROGiJMf6G5+h42eiFe1I+F72rBG\nlGQgLS803w6YisxZLCOE1xc7vbDqvv3fClH2echHU7/qgGKBpgAhvNYIXwBycoX8\nPKeEDmeP+38yIyEEhGfcKT6tMm0BJfJwo1RtTs0GNrYmGMxdVWrgIf3nnfHLzSlr\nr2J2e+csyLXOujsS1U+iLC5ZEBs4B1iJq0nSF4BlrwZhHYG4i/TA0q2epvph4U7j\n/QYGlHw6Cu453e04vtrVnl/aYaRXKfMKoNZbmPvK1qgRoe77Ci6DtVqEqip3NElk\n5/HAOGovLaeT6072kKrepWJcyMprlJcpPZKOeYuLUQKBgQDt7S5tvXhPb5kemeR7\npYI+nxzrBWVxNx0H4s4qlz0AnnsZsxtVneeu4qm8w3j3LGNoJwqLuobwOG+rA3KW\nmfcoePkNKQONSasffTNUia3EhLCI1lpy7Sdo7GZ1nx5sTx61qVz5gSwg7obT4KOK\nHyfiiSkGGX3W0DuZbXdSBGRDmQKBgQC3uPNtmPM1m5NX8B0kZCDjJPuTXarJAOC+\nnXPemgvdgjr7UEdxqKY3uyRfTo26cPpsEOFNmPisswyvGzsa2wmX+d+QB+pmYYgn\n1xsHgq2kxOTM5fgyJL0GVWcgl4no1oqldibBY+PNG6F5xEIf6h8zmhPXMRwAUUQH\noZ42KS3nuQKBgAs7hVOc/E8Tv7DYJxdHSwzVyjG2QYHEzlQO+xi7px+eW8Vs1T+H\nguaYwNaui8lviQnjvfW2yqQQpgT21rQRdL+uZmOeqhJDhhaofIHjNhbvBL6REBgY\n5iFn97ZZ2r/WRGbjJgaJeKHdYPQjyNS+f82MGCm3jl9T2Vx29Ikkt+8RAoGAQdvd\n/2q1vIDRl9NuTu5Jz8MhH9mS8E0NQ6djsudb24Lkq9RCWB8RvqaqSjP5oF0BmB2Q\n9mUgt5/Tqy3CyUS9sqoTFymPQDY0PbvhZ5bTsl4WetDxYOBElnGk700DVeEagGfT\nSr4JGiyOfPz6i0A9AR15gUmMdRysm2O3OEkYuJkCgYBibIsAwn3xWiJS1C1M4Cao\na2KCfce1wMzowwppp31Z4jZQHKWRE2Q0uJVqpneXPAPH41bBBpiKi3cDGgd0Yy7M\nVwDLR7VsfTifCmLg7Bm39VZYm57wJZPtQelyLqHXXuA1/Wrz9kqAjCfnlVbIp8kT\n7EhdRkMw3aNARPWlcdeE3g==\n-----END PRIVATE KEY-----\n";

// The ID of the spreadsheet where you'll publish the data
const char spreadsheetId[] = "1W542kVC0odtTMUtQyWMngZ3MoQ2OUfFQWVREKFUJkys";

#define PIN_A0 34     // some analog input sensor
#define PIN_A1 35     // some analog input sensor
#define PIN_A2 33     // some analog input sensor

// variables to store measure data and sensor states
int BitsA0 = 0, BitsA1 = 0; int BitsA2 = 0; 
float VoltsA0 = 0, VoltsA1 = 0; float VoltsA2 = 0; 
int FanSpeed = 0;
bool LED0 = false, SomeOutput = false;
uint32_t SensorUpdate = 0;
int FanRPM = 0;

char XML[2048];

char buf[32];

// variable for the IP reported when you connect to your homes intranet 
IPAddress Actual_IP;

// definitions of your desired intranet created by the ESP32
IPAddress PageIP(192, 168, 1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress ip;

WebServer server(80);

unsigned long ms = 0;

#if defined(ARDUINO_RASPBERRY_PI_PICO_W)
WiFiMulti multi;
#endif

void tokenStatusCallback(TokenInfo info);

void setup() {
  Serial.begin(9600);
  // just an update to progress
  GSheet.printf("ESP Google Sheet Client v%s\n\n", ESP_GOOGLE_SHEET_CLIENT_VERSION);
  Serial.println("starting server");

  #ifdef USE_INTRANET
    WiFi.begin(WIFI_SSID
  , WIFI_PASSWORD
  );
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
    Serial.print("IP address: "); Serial.println(WiFi.localIP());
    Actual_IP = WiFi.localIP();
  #endif
  printWifiStatus();
  // Set the seconds to refresh the auth token before expire (60 to 3540, default is 300 seconds)
  GSheet.setPrerefreshSeconds(10 * 60);
  // Begin the access token generation for Google API authentication
  GSheet.begin(CLIENT_EMAIL, PROJECT_ID, PRIVATE_KEY);
  // these calls will handle data coming back from webpage 
  // upon ESP getting "/" string, the web page will be sent
  server.on("/", SendWebsite);
  // upon esp getting /XML string, ESP will build and send the XML - refreshes just parts of the web page
  server.on("/xml", SendXML);
  // upon ESP getting /UPDATE_SUBMIT string, ESP will execute the UpdateSubmit() function
  server.on("/UPDATE_SUBMIT", UpdateSubmit);
  // Begin the server
  server.begin();
}

void loop() {
  // Call ready() repeatedly in loop for authentication checking and processing
  bool ready = GSheet.ready();

  if ((millis() - SensorUpdate) >= 50) {

    SensorUpdate = millis();
    BitsA0 = analogRead(PIN_A0);
    BitsA1 = analogRead(PIN_A1);
    BitsA2 = analogRead(PIN_A2);
    // standard converion to go from 12 bit resolution reads to volts on ESP
    VoltsA0 = BitsA0 * 3.3 / 4096;
    VoltsA1 = BitsA1 * 3.3 / 4096;
    VoltsA2 = BitsA2 * 3.3 / 4096;
  }
  // must call handleClient repeatidly--otherwise the web page will not get instructions to do something
  server.handleClient();
}

void UpdateSubmit() {
  String leftTopSel = server.arg("leftTop");
  String leftBottomSel = server.arg("leftBottom");
  String rightTopSel = server.arg("rightTop");
  String rightBottomSel = server.arg("rightBottom");
  String date = server.arg("date");
  String time = server.arg("time");
  String birdsex = server.arg("birdsex");
  String term = server.arg("term");
  String name = server.arg("name");
  String birdId = server.arg("birdId");
  String mass = server.arg("mass");
  String ring = "Colour";

  if (birdId == "XXXX") {
    ring = "None";
  }

  FirebaseJson response;
  FirebaseJson valueRange;

  valueRange.add("majorDimension", "COLUMNS");
  valueRange.set("values/[0]/[0]", "=INDIRECT(\"A\" & ROW() - 1) + 1"); //FID
  valueRange.set("values/[1]/[0]", date); // Date
  valueRange.set("values/[2]/[0]", time); // Time
  valueRange.set("values/[3]/[0]", leftTopSel); // Top left colour
  valueRange.set("values/[4]/[0]", leftBottomSel); // Bottom left colour
  valueRange.set("values/[5]/[0]", rightTopSel); // Top right colour
  valueRange.set("values/[6]/[0]", rightBottomSel); //Bottom right colour
  valueRange.set("values/[7]/[0]", birdId); // ID
  valueRange.set("values/[8]/[0]", ring); // Ring colour
  valueRange.set("values/[9]/[0]", birdsex);  // Bird Sex
  valueRange.set("values/[10]/[0]", mass); // Mass
  valueRange.set("values/[11]/[0]", "NH"); // Day Status
  valueRange.set("values/[12]/[0]", "=TEXT(INDIRECT(\"B\" & ROW()), \"dddd\")"); // Day
  valueRange.set("values/[13]/[0]", "=IF(OR(INDIRECT(\"M\" & ROW())=\"Saturday\", INDIRECT(\"M\" & ROW())=\"Sunday\"), \"Weekend\", \"Weekday\")");
  valueRange.set("values/[14]/[0]", term); // Term
  valueRange.set("values/[15]/[0]", name); // Researcher name
  valueRange.set("values/[16]/[0]", "=IF(INDIRECT(\"C\" & ROW())<TIME(12,0,0),\"Morning\",IF(INDIRECT(\"C\" & ROW())<TIME(18,0,0),\"Afternoon\",\"Evening\"))");

  bool success = GSheet.values.append(&response /* returned response */, 
                                      spreadsheetId /* spreadsheet Id to append */, 
                                      "Sheet1!B3" /* range to append */, 
                                      &valueRange /* data range to append */);
  if (success)
      response.toString(Serial, true);
  else
      Serial.println(GSheet.errorReason());
  Serial.println();

  server.send(200, "text/plain", ""); //Send web page
}

// code to send the main web page
// PAGE_MAIN is a large char defined in myWebPage.h
void SendWebsite() {
  Serial.println("sending web page");

  server.send(200, "text/html", PAGE_MAIN);
}


void SendXML() {
  strcpy(XML, "<?xml version = '1.0'?>\n<Data>\n");
  // send bitsA0
  sprintf(buf, "<B0>%d</B0>\n", BitsA0);
  strcat(XML, buf);
  // send Volts0
  sprintf(buf, "<V0>%d.%d</V0>\n", (int) (VoltsA0), abs((int) (VoltsA0 * 10)  - ((int) (VoltsA0) * 10)));
  strcat(XML, buf);
  // send bits1
  sprintf(buf, "<B1>%d</B1>\n", BitsA1);
  strcat(XML, buf);
  // send Volts1
  sprintf(buf, "<V1>%d.%d</V1>\n", (int) (VoltsA1), abs((int) (VoltsA1 * 10)  - ((int) (VoltsA1) * 10)));
  strcat(XML, buf);
  // send bits2
  sprintf(buf, "<B2>%d</B2>\n", BitsA2);
  strcat(XML, buf);
  // send Volts2
  sprintf(buf, "<V2>%d.%d</V2>\n", (int)(VoltsA2), abs((int)(VoltsA2 * 10) - ((int)(VoltsA2) * 10)));
  strcat(XML, buf);

  strcat(XML, "</Data>\n");
  Serial.println(XML);

  server.send(200, "text/xml", XML);
}

void printWifiStatus() {

  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
  // print where to go in a browser:
  Serial.print("Open http://");
  Serial.println(ip);
}

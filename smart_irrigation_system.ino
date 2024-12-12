#include<ESP8266WiFi.h>
#include<WiFiClientSecure.h>
#include<UniversalTelegramBot.h>
#include<ArduinoJson.h>
const char* ssid = "smile123";
const char* password ="123456789";
//  with your network credentials
#define BOTtoken "7118195824:AAGnnEZ9LJWSM-qqSWjT8zqjXnBkFelxmkQ" //
#define CHAT_ID "888844426"

X509List cert(TELEGRAM_CERTIFICATE_ROOT);
WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);


char Start_buff[70]; 
int i,z;             
char ch;
int str_len;
 char textmessage[20];

void WAITING();
void setup() 
{
    // initialize the Serial
    Serial.begin(9600);
    Serial.println("Starting TelegramBot...");

    configTime(0, 0, "pool.ntp.org");      // get UTC time via NTP
  client.setTrustAnchors(&cert); // Add root certificate for api.telegram.org

  // Attempt to connect to Wifi network:
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  bot.sendMessage(CHAT_ID,"SMART AGRI S/M...."); 
}
void loop() 
{
  WAITING(); 
}

char Serial_read(void)
{
      char ch;
      while(Serial.available() == 0);
      ch = Serial.read(); 
      return ch;
}
void WAITING()
{
   Serial.println("WAITE");
  
  buffer_clear();
//  msg.text[0]='\0';
//        msg.text[1]='\0';
//         msg.text[2]='\0' ;
//         msg.text[3]='\0';
//          msg.text[4]='\0';
//           msg.text[5]='\0';
           
 while(1)
 { 
      if (Serial.available() > 0)
      {
         //Serial.println("halo");
         
          while(Serial_read()!='$');
          i=0;
          while((ch=Serial_read())!='#')
          {
            Start_buff[i] = ch;
             i++;
          }  
          Start_buff[i]='\0';
       }
       Serial.println(Start_buff);
       bot.sendMessage(CHAT_ID, Start_buff);
       delay(100);
            
    }
}
void buffer_clear()
{
  for(z=0;z<70;z++)
  {
    Start_buff[z]='\0';
//    textmessage[z]='\0';
    
  } 
}
void buffer1_clear()
{
  for(z=0;z<5;z++)
  {
   
   textmessage[z]='\0';
    
  } 

}

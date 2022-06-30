#include <ESP8266WiFi.h>

WiFiClient client;
WiFiServer server(80);

#define led1 D5
#define led2 D6

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.begin("Mooazam", "mooazam123");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(200);
    Serial.print("..");
  }
  Serial.println();
  Serial.println("NodeMCU is connected!");
  Serial.println(WiFi.localIP());
  server.begin();
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  client = server.available();  //Gets a client that is connected to the server and has data available for reading.
  if (client == 1)
  {
    String request =  client.readStringUntil('\n');
    Serial.println(request);
    request.trim();
    if (request == "GET /led1on HTTP/1.1")
    {
      digitalWrite(led1, HIGH);
      Serial.println("LED 1 is ON");
    }
    if (request == "GET /led1off HTTP/1.1")
    {
      digitalWrite(led1, LOW);
      Serial.println("LED 1 is OFF");
    }
    if (request == "GET /led2on HTTP/1.1")
    {
      digitalWrite(led2, HIGH);
      Serial.println("LED 2 is ON");
    }
    if (request == "GET /led2off HTTP/1.1")
    {
      digitalWrite(led2, LOW);
      Serial.println("LED 2 is OFF");
    }
  }
  client.println("HTTP/1.1 200 OK");
  client.println("Content-type:text/html");
  client.println("Connection: close");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<head>");
  client.println("<title>Document</title>");
  client.println("<style>");
  client.println("body {text-align: center;}");
  client.println("</style>");
  client.println("</head>");
  client.println("<body>");
  client.println("<h1>Home Automation System.<br><br>Made By: Areeba Ghazal.<br><br>Mah E Urooj.</h1>");
  client.println("<h2>Room 1</h2>");
  client.println("<a href=\"/room1led1on\"\"><button>LED 1 ON</button></a>");
  client.println("<a href=\"/room1led1off\"\"><button>LED 1 OFF</button></a>");
  client.println("<br><br>");
  client.println("<a href=\"/room1fan2on\"\"><button>FAN 2 ON</button></a>"); 
  client.println("<a href=\"/room1fan2off\"\"><button>FAN 2 OFF</button></a>"); 
  client.println("<br><br>");
  client.println("<h3>Room 2</h3>");
  client.println("<a href=\"/room2led1on\"\"><button>LED 1 ON</button></a>"); 
  client.println("<a href=\"/room2led1off\"\"><button>LED 1 OFF</button></a>"); 
  client.println("<br><br>"); 
  client.println("<a href=\"/room2led2on\"\"><button>LED 2 ON</button></a>"); 
  client.println("<a href=\"/room2led2off\"\"><button>LED 2 OFF</button></a>"); 
  client.println("<br><br>"); 
  client.println("<a href=\"/room2fan1on\"\"><button>FAN 1 ON</button></a>"); 
  client.println("<a href=\"/room2fan1off\"\"><button>FAN 1 OFF</button></a>"); 
  client.println("<br><br>");
  client.println("<a href=\"/room2fan2off\"\"><button>FAN 2 OFF</button></a>");
  client.println("<a href=\"/room2fan2on\"\"><button>FAN 2 ON</button></a>");
  client.println("<br><br>");
  client.println("<h4>Room 3</h4>");
  client.println("<a href=\"/room3led1on\"\"><button>LED 1 ON</button></a>");
  client.println("<a href=\"/room3led1off\"\"><button>LED 1 OFF</button></a>");
  client.println("<br><br>");
  client.println("<a href=\"/room3led2on\"\"><button>LED 2 ON</button></a>");
  client.println("<a href=\"/room3led2off\"\"><button>LED 2 OFF</button></a>");
  client.println("<br><br>");
  client.println("<a href=\"/room3fan1on\"\"><button>FAN 1 ON</button></a>");
  client.println("<a href=\"/room3fan1off\"\"><button>FAN 1 OFF</button></a>");
  client.println("<br><br>");
  client.println("<a href=\"/room3fan2on\"\"><button>FAN 2 ON</button></a>");
  client.println("<a href=\"/room3fan2off\"\"><button>FAN 2 OFF</button></a>");
  client.println("<br><br>");
  client.println("<h3>Room 4</h3>");
  client.println("<a href=\"/room4led1on\"\"><button>LED 1 ON</button></a>");
  client.println("<a href=\"/room4led1off\"\"><button>LED 1 OFF</button></a>");
  client.println("<br><br>");
  client.println("<a href=\"/room4led2on\"\"><button>LED 2 ON</button></a>");
  client.println("<a href=\"/room4led2off\"\"><button>LED 2 OFF</button></a>");
  client.println("<br><br>");
  client.println("<a href=\"/room4fan1on\"\"><button>FAN 1 ON</button></a>");
  client.println("<a href=\"/room4fan1off\"\"><button>FAN 1 OFF</button></a>");
  client.println("<br><br>");
  client.println("<a href=\"/room4fan2on\"\"><button>FAN 2 ON</button></a>");
  client.println("<a href=\"/room4fan2off\"\"><button>FAN 2 OFF</button></a>");
  client.println("<br><br>");
  client.println("</body>");
  client.println("</html>");
}
 
  
    
    
    
    
    
    
    

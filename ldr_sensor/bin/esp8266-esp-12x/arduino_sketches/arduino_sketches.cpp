#include "arduino.hpp"
#include "board.h"

#include "arduino_board.h"
#include "stdlib.h"
#include "/home/angela/riot_workplace/RIOT/examples/ldr_sensor/udp.c"

#define MY_IP 

#ifndef BOARD_ID
	#define BOARD_ID 1
#endif

#ifndef SERVICE_IP
	#define SERVICE_IP "ip must be provided"
#endif

#ifndef NEXT_IP
	#define NEXT_IP SERVICE_IP
#endif

#ifndef IFACE
   #define IFACE 10
#endif





//extern void send(char *addr_str, char *port_str, char *data, unsigned int num, unsigned int delay);
// int gnrc_ipv6_nib_ft_add(const ipv6_addr_t * dst, unsigned dst_len, const ipv6_addr_t * next_hop, unsigned iface, uint16_t lifetime)

                 
                 
int ldrPin = ADC_LINE(0);
int ldrStatus = 0;
char name[20] = "PhotoResistor\0";
char str[100];

void setup() {
  Serial.begin(9600);
  pinMode(ldrPin, INPUT);
  
  
  #ifdef USES_ADHOC_NETWORK
  
  Serial.println("Setting up IPV6 stuff");
  
  // nib route command absorbed as a C function  
  ipv6_addr_t pfx = IPV6_ADDR_UNSPECIFIED; 
  ipv6_addr_t next_hop = IPV6_ADDR_UNSPECIFIED; 
  sprintf(str,"Configuring NEXT HOP With %s",NEXT_IP);
  Serial.println(str);
  ipv6_addr_from_str(&next_hop, NEXT_IP);
  
  sprintf(str,"Configuring SERVICE IP With %s", SERVICE_IP);
  Serial.println(str);
  
  ipv6_addr_from_str(&pfx, SERVICE_IP);
  
  unsigned pfx_len = ipv6_addr_split_prefix((char*)SERVICE_IP);
  uint16_t ltime = 0;
        

  Serial.println("Setting up ADHOC Route");
  gnrc_ipv6_nib_ft_add(&pfx, pfx_len, &next_hop, IFACE, ltime);

  #endif
  
}
void loop() {
  uint32_t num = 1;
  uint32_t dl = 1000000;
  ldrStatus = analogRead(ldrPin);

  sprintf(str, "{\"board\":%d,\"%s\":%d};",BOARD_ID, name, ldrStatus);
  
  // udp send commmand absorbed as a C function
  
  send((char*)"fe80::dae9:e933:bf4:48b2", (char *)"8808", (char *)str, num, dl);
   
  

  delay(2000);
}

int main(void)
{
    /* run the Arduino setup */
    setup();
    /* and the event loop */
    while (1) {
        loop();
    }
    /* never reached */
    return 0;
}

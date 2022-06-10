ldr_sensor
============

This is a basic example how to use RIOT in your embedded application and print the output on Pharo image.

#### Build and runBuild and run

- First check your ipv6 with command :
    `ip address show`
and modify the sketch file, use this ipv6 as the first param in send()

- Then build your application with command :
`make` or `make BOARD=esp8266`

- Flash your application with command : 
`CFLAGS='-DESP_WIFI_SSID=\"wifi\" -DESP_WIFI_PASS=\"psw\" -DESP_WIFI_MAX_CONN=2'  make flash`

- Finally connect to port :
`make term`

#### In the Makefile

- The variable `RIOTBASE` contains an absolute or relative path to the directory where you have checked out RIOT.
  If your code resides in a subdirectory of RIOT, then you can use `$(CURDIR)` as it's done in here.

- The variable `QUIET`, which is either `1` or `0`, defines whether to print verbose compile information, or hide them, respectively.

- The last line of your Makefile must be `include $(RIOTBASE)/Makefile.include`.

#### Convert ipv6 to ipv4
-  Run the following command in a seperate terminal for convert ipv6 in port 8808 to ipv4 in port 8809
`socat UDP6-RECVFROM:8808,fork UDP4-SENDTO:localhost:8809`

#### Hardware setting
![hardware](https://github.com/angelaclan/PJI_Real-time-data-rendering/blob/master/ldr_sensor/ldr_sensor.jpg "hardware")

#### Result on Pharo Image
![result](https://github.com/angelaclan/PJI_Real-time-data-rendering/blob/master/ldr_sensor/struct.png "result")



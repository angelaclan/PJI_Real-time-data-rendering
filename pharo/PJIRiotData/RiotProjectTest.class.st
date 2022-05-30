Class {
	#name : #RiotProjectTest,
	#superclass : #TestCase,
	#category : #PJIRiotData
}

{ #category : #test }
RiotProjectTest >> testMessageReceivedFromEsp8266 [

"creat socket, bind port and address, receive datagram, store into buffer"

| socket buffer result|

socket := Socket newUDP.
socket bindTo: (NetNameResolver addressFromString: '127.0.0.1') port: 8809.
buffer := String new: 256.
socket waitForData.
result := socket receiveUDPDataInto: buffer. 
]

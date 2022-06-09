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

{ #category : #test }
RiotProjectTest >> testRestructDataReceivedFromEsp8266 [

"creat socket, bind port, receive datagram, and restruct it "

| socket stream pack|

socket := Socket newUDP.
socket setPort:8809.
stream := SocketStream on: socket .
pack := stream upToAll: ';'.
('|' split: pack ) do: [ : p |
	(':' split: p) traceCr
 ]
]

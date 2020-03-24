FOX description
===============
A hidden transmitter is known as the fox. This is the fox that I am working on.

The outer case a waterproof ammocase.

Responds to DTMF 1.(Or 6, if you want to know how many times it has been activated.)

Central Computer: Arduino Nano

Wiring
------
TX microphone input : digital pin 8 on Arduino

Power source : + goes with Vin, - goes with GND

DTMF decoder MT8870DS : 5v goes to VCC, connect the grounds

DTMF decoder ...continued : StQ(not to be confused with StQ active low) goes with pin 4 on Arduino

DTMF decoder ...continued : Q1 goes with pin 5 on Arduino, The headphone jack goes to the headphone/earpone connector on radio

DTMF decoder ...continued : Q2 - D6, Q3 - D7, Q4 - D9

PTT control : Pin 10 on Arduino

Warnings
--------
If you are using my code, please replace the callsign, and the code block that generates it, with your own.

If the speaker output is too loud, it might burn out the decoder. I don't know.

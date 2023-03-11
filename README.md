# Arduino-nerfgun
## Background
## Materials
+ Arduino Uno Rev 3 or compariable microcontroller
+ breadboard
+ jumper wires
+ PIR sensor
+ 5v relay
+ seperate 5v power supply
+ 5v hobby servo
+ battery operated Nerfgun (we used the [Stryfe](https://nerf.fandom.com/wiki/Stryfe_(N-Strike_Elite)))
## Design
References schematic1.0a found in the Assets folder

The nerfgun utilitzed has three switches that control it's operation. In the schematic switch S1 is the switch that gets depressed when a magazine is inserted into the nerfgun. Switch S2 is the switch that is depressed when the top access lid is closed. 
The third switch is operated by the small button located bellow the trigger guard. Assuming both S1 and S2 are closed this switch would activate the nerf's motor m1. This switch was cut out and replaced with the single pole double throw (SPDT) relay k1.
The connections from the nerfgun are connected to the NC (normally closed) and NO (normally open) terminals on the relay.

The microcontroller utilitzed is the Arduino Uno Rev 3. The relay is connected to the Arduino's digital pin 7 and ground pin.
The servo (M1) is connected to the Arduino's ground pin. The servo's signal pin is connected to the Arduino's digital pin 9. And the power pin is connected to an external 5V dc source whose ground is tied to the Arduino's.[^1]
The Passive Infrared (PIR) module is powered from the Arduino's 5v pin and tied the Arduino's ground. The signal pin is connected to the Arduino's digital pin 2[^2].


[^1]: Under load there is the possibility that the servo could draw more current or approach the limit of current the Arduino is capable of supplying so an external power source is used
[^2]: Our code makes use of interrupts and interrupts are tied to certain pins one of which is digital pin 2. if another pin is used changes to the code will be necessary.
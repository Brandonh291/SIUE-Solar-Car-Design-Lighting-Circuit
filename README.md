# SIUE-Solar-Car-Design-Lighting-Circuit
Solar Car Lighting Circuit
Lighting Controller MCU specifications

Read through section 9.4 of the 2020 regulations for how the external lights should behave.

Also, download the orion bms wiring sheet, it’ll be useful.

· The lighting controller will dictate when a light on the car turns on and off

· It will control 10 exterior lights

o Two forward facing headlights

o Two forward facing blinkers

o Two lateral blinkers

o Three rear lights, two of which are blinker/break and one of which is a break light

o One BPS trip strobe

· The behavior of the lights is as follows:

o The headlights will be controlled by a toggle switch. When the switch is closed, the headlights will turn on. When the switch is opened the headlights will turn off.

o The blinkers will be controlled by a three-state toggle switch. When the switch is turned left, the forward, lateral, and rear left lights will begin blinking. The same for if the switch is turned right. If the switch is neutral, no blinking will occur.

o The brakes will illuminate when the brake petal is depressed. Two of the three brake lights in the rear of the vehicle will also function as blinkers. When the blinkers and brakes are engaged, the blinkers take priority.

o The hazard will be controlled by a toggle switch. When it is closed, all lights except for the BPS strobe will flash until the switch is opened.

o The BPS strobe is controlled by an open drain output from the Orion BMS. Normal, working conditions will set the output high. When the device detects a battery fault, the output goes low. See the “Digital Signal outputs” section in the Orion BMS wiring manual for more information.

· Power requirements

o Each LED strip burns about 50mA at 12V, so whatever is used to switch them must be capable of handling this load. In the case of the headlights, and each front/lateral set of blinkers, are tied together, so the switch powering them must be able to handle approximately 100mA. There are logic level FETs that can drive the LEDs.

o I want input protection on the switches to make it ESD resistant. A google search for “MCU input protection” will yield plenty of results.

· Hardware and I/O

o It’d be nice if the I/O was confined to a single connector like a D-sub connector or something similar to confine all the connections to a single plug.

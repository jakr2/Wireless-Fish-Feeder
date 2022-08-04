# Wireless-Fish-Feeder

**Works with with Apple devices**

This project was created using an ESP32, Arduino Mega 2560, 28BYJ-48 Stepper Motor and corresponding ULN2003 Stepper Motor Driver. 

### General Overview
The ESP32 connects to a internet router and is discoverable as an Apple Accessory on the "Home" app. After powering on the device (from Apple Device), the ESP32 sends a message at 9600 baud to the Arduino. The Arduino then activates the motor which spins 360 degrees, dispensing food to the fish. A battery pack can be used to provide power without needing to be connected to a laptop.

### Wire Connections


To connect the Arduino with the ESP32 3 wires are used. Below is the where the wires should connect the Arduino and ESP32

| ESP32 Pin | Arduino Pin |
| ---------- | ------------ |
| GND | GND | 
| IO17 | 17 (RX2) |
| IO16 | 16 (TX2) |

[This image](https://user-images.githubusercontent.com/110635087/182953305-0d8be9aa-1ee4-445b-a1e6-d94cf9c79bcf.png) shows how to connect the Arduino, Stepper Motor Driver and Stepper Motor.

*In my case both the ESP32 and Stepper Motor Driver required a 5V supply, so they were connected in parallel on a breadboard, with the source being the 5V pin on the arduino*.

### Food Holder

A wooden structue was built to hold components above the top of the fish bowl. The stepper motor was drilled into the wood and the other components were left loose, however, it is likely that the other componnets could be bolted down if necessary.

A simple pipe (I used a pipe originally intended to be used under a sink) had 6 holes drilled into it and glued to the stepper motor. When the motor would rotate, it rotates the pipe and thus the holes release the fish food inside the pipe. A little "lip" is cut out of poster board and hot-glued to the front of the pipe to allow food to be put in but not fall out.

[Front View of Food Holder](https://user-images.githubusercontent.com/110635087/182958332-79c7f6eb-f260-46fd-80fb-61f37e63a916.png)

[Side View of Food Holder](https://user-images.githubusercontent.com/110635087/182958382-343f845e-8764-43fb-84ef-12d6d13ff377.png)

[Structural Top View](https://user-images.githubusercontent.com/110635087/182960009-f1553277-f381-41fa-ad8f-5730921d5eff.png)

[Structural Side View](https://user-images.githubusercontent.com/110635087/182960122-b2793458-ce04-4bd2-863b-0355f7f54c24.png)

### ESP32

After uploading code to ESP32, you must connecte it to your home wifi. With the ESP32 still plugged into your computer, make sure you are on 115200 baud and enter *?* into the Serial Monitor. THis will bring up certain HomeSpan Commands which you can follow to connect it to your desired wifi network. Ensure to upload ESP32 Push Button.ino rather than DEV_Blinker.h

After connecting it to your wifi network, going onto the home app should allow you to add it as an accessory with ***setup code 466-37-726*** after pairing.
For more information visit https://github.com/HomeSpan/HomeSpan/blob/master/docs/UserGuide.md.

### Arduino

After uploading code to Arduino wait a few minutes before attempting to turn on the fish feeder on your iPhone or you will need to reupload and wait again. Certain code is left for testing so you can monitor any issues on the Serial Monitor when connected to a computer.

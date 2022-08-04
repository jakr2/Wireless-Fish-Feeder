/**
 * Handles on & off communication from Apple Device
 * Goes with ESP32 Push Button
 **/

// IO pins on ESP32
#define RXp2 16                                     
#define TXp2 17

struct DEV_Motor : Service::LightBulb {           // LED Blinker
  
  SpanCharacteristic *power;                        // reference to the On Characteristic
  
  DEV_Motor() : Service::LightBulb(){       // constructor() method

    power=new Characteristic::On();                 
    Serial2.begin(9600, SERIAL_8N1, RXp2, TXp2); // communicates with Arduino on 9600 baud via TX and RX pins

  } // end constructor

  boolean update(){                           
    if(power->getNewVal()){                       // checks if button is pressed on Apple Device

      Serial2.println("activate motor");  // sends message to arduino
      
    }
    return(true);
  
  }

  void loop(){
    // Puts button on Apple Device in off position
    if(power->getVal() && power->timeVal()>3000){   // check that power is true, and that time since last modification is greater than 3 seconds 
      LOG1("Resetting Blinking LED Control\n");     // log message  
      power->setVal(false);                         // set power to false
    }      
    
  } // loop
  
};
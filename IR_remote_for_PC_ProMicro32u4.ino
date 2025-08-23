/*
 * Hardware Summary: PCB prototye maybe
 * Arduino Pro Micro 32u4 (USE Arduino Leonardo if you dont see ProMicro in board list)
 * 
 * Arduino IDE Settings
 * Tools> Board:  Arduino Micro (or Leonardo)
 * Programmer: AVRISP mkII 
  if you get "programmer not responding" errors and timeouts, connect usb cable DIRECTLY to your PC, do not use a USB hub.

 * IR Receiver P157 [PIN 5]
 * RGB_LED (x1)  [Pin A1]
 * 
What?
It's a multi-mode IR remote-to-USB keyboard interface with visual feedback via NeoPixels + OLED display

 */      
/* Note to self, need to delete of bunch of IR code not being used. 
Roku Remote uses NEC Protocol
uhhhh sometimes compiling on a different PC i get a out of memory error (104% mem usage) when compile. maybe a library version on the other
PC is too heavy?
on PC at home this compiles to: 73% program memory, 92% DRAM. I think its the OLED lib version and the screen buffer?
CODE VERSION: April 1 2025 PM

 */

#include <Keyboard.h> ////v 1.0.6. older versioons of arduino IDE (v1.8.8) have issue with this. need quotes like "keyboard.h" 
#include <GyverOLED.h> // by Alex Gyver v1.50
//GyverOLED<SSD1306_128x32, OLED_BUFFER> oled;
//GyverOLED<SSD1306_128x32, OLED_NO_BUFFER> oled;
//GyverOLED<SSD1306_128x64, OLED_BUFFER> oled;
//GyverOLED<SSD1306_128x64, OLED_NO_BUFFER> oled;
//GyverOLED<SSD1306_128x64, OLED_BUFFER, OLED_SPI, 8, 7, 6> oled;
GyverOLED<SSH1106_128x64> oled;
/* TIP! use Use the F macro to store data in flash (program) memory instead of SRAM. Saves SRAM memory (your Global variable memory). 
Serial.print("this string") is stored in SRAM, but Serial.print(F("this string") is moved to program memory.

*/


//====================================================================================
#include <Adafruit_NeoPixel.h> // v1.12.14 by Adafruit
#define PIN         A1
#define NUMPIXELS      5
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


// Declare a variable to track the last updated mode for color
int lastProfile = -1; // Initialize to a non-valid value

//=================================================================================
// IRremote v4.2.0
// IRremote library https://github.com/Arduino-IRremote/Arduino-IRremote
/* TIP! use Use the F macro to store data in flash (program) memory instead of SRAM. Saves SRAM memory (your Global variable memory). 
Serial.print("this string") is stored in SRAM, but Serial.print(F("this string") is moved to program memory.
/*
 * Specify which protocol(s) should be used for decoding.
 * If no protocol is defined, all protocols (except Bang&Olufsen) are active.
 * This must be done before the #include <IRremote.hpp>
 */
//#define DECODE_DENON        // Includes Sharp
//#define DECODE_JVC
//#define DECODE_KASEIKYO
//#define DECODE_PANASONIC    // alias for DECODE_KASEIKYO
//#define DECODE_LG
#define DECODE_NEC          // Includes Apple and Onkyo (works for Roku remotes)
//#define DECODE_SAMSUNG
//#define DECODE_SONY
//#define DECODE_RC5
//#define DECODE_RC6

//#define RAW_BUFFER_LENGTH  180  // Default is 112 if DECODE_MAGIQUEST is enabled, otherwise 100.
#define IR_RECEIVE_PIN 5 // D5
#include <Arduino.h>

#if !defined(STR_HELPER) //i dunno where this is helping, something with strings, but it's needed?
#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)
#endif

/*
 * This include defines the actual pin number for pins like IR_RECEIVE_PIN, IR_SEND_PIN for many different boards and architectures
 */
//#include "PinDefinitionsAndMore.h"
#define IR_USE_AVR_TIMER1 ///originally TIMER1, but the neopixel library needs to use Timer1 to function. wonder if this will be an issue later
#include <IRremote.hpp> // include the library
int profile = 0; //Start with profile 0, can be changed to 1, 2, or 3 for different profiles


#define BUTTONS 21  //Items in lookup table
struct remoteFunctions { //lookup table hex code and word structure
  uint16_t code;
  const char* word;
  bool state;
};    
//create the lookup table as (Decoded command, Button label, state)
remoteFunctions lookupTable[BUTTONS]={
  {0x17, "Pwr",   0}, //0
  {0x66, "Back",  0}, //1
  {0x3 , "Home",  0}, //2
  {0x19, "UP",    0}, //3
  {0x33, "DOWN",  0}, //4
  {0x1E, "LEFT",  0}, //5
  {0x2D, "RIGHT", 0}, //6
  {0x2A, "OK",    0}, //7
  {0x78, "Replay",0}, //8
  {0x62, "Sleep", 0},  //9
  {0x61, "Star",  0}, //10
  {0x34, "<<",    0}, // 11
  {0x4C, "PlayPause",0}, //12
  {0x55, ">>",    0}, //13
  {0xF, "vol+",   0}, //14
  {0x10, "vol-",  0}, //15
  {0x20, "mute",  0}, //16
  {0x52, "H_pts+",0}, //17
  {0x4D, "H_pts-",0}, //18
  {0x4B, "V_pts+",0}, //19
  {0xC, "V_pts-", 0}  //20

};


void setup() {

    Serial.begin(115200);
    // Just to know which program is running on my Arduino
    Serial.println(F("START " __FILE__ " from " __DATE__ "\r\nUsing library version " VERSION_IRREMOTE));

    // Start the receiver and if not 3. parameter specified, take LED_BUILTIN pin from the internal boards definition as default feedback LED
    IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);

    Serial.print(F("Ready to receive IR signals of protocols: "));
    printActiveIRProtocols(&Serial);
    Serial.println(F("at pin " STR(IR_RECEIVE_PIN)));
    //OLED stuff==========================
    oled.init();              // initialize the oled?
    oled.setContrast(255);   // contrast level 0..255
    //oled.setPower(true);    // true/false - turn on/off the display
    oled.flipH(1);       // true/false - flip horizontally
    oled.flipV(1);       // true/false - flip vertically
    oled.setScale(1);         // smallest text size (range is 1-4)
    oled.setCursorXY(0,0);  oled.print("IR_Remote for PC");
    oled.setCursorXY(0,30); oled.print("(c) 2025 Ryan Bates");
    oled.setCursorXY(0,50); oled.print("now with OLED!");
    oled.update();
    delay(300);
    oled.clear();  oled.setScale(3);         // smallest text size (range is 1-4)
 
  pixels.begin(); // This initializes the NeoPixel library.
  
//led startup blinky
int colors[][3] = {
    {0, 5, 0},  // Green
    {0, 0, 5},  // Blue
    {5, 0, 0},  // Red
    {0, 5, 0}   // Green
};

for (int i = 0; i < 5; i++) {
    pixels.setPixelColor(0, pixels.Color(colors[i][0], colors[i][1], colors[i][2]));
    pixels.setPixelColor(1, pixels.Color(colors[i][0], colors[i][1], colors[i][2]));
    pixels.setPixelColor(2, pixels.Color(colors[i][0], colors[i][1], colors[i][2]));
    pixels.setPixelColor(3, pixels.Color(colors[i][0], colors[i][1], colors[i][2]));
    pixels.setPixelColor(4, pixels.Color(colors[i][0], colors[i][1], colors[i][2]));   
    pixels.show();  // Update the pixel color
    delay(250);     // Wait for 100ms
  
}
 //setColorsMode0(); // this is overcoming a bug, where at start up profile(mode0) does not run the colorMode(0) call
 pixels.show(); // all LEDs off
Keyboard.begin();
updateColorMode();
//printTable_Debug();
}



void loop() {
    /*
     * Check if received data is available and if yes, try to decode it.
     * Decoded result is in the IrReceiver.decodedIRData structure.
     */
     
    if (IrReceiver.decode()) {
        searchTable(); // i think this has to go first to load a change in the remote control table state to dymanic mem
        handleRemoteFunctions();
        
        if (IrReceiver.decodedIRData.protocol == UNKNOWN) {
            Serial.println(F("Received noise or an unknown (or not yet enabled) protocol"));
            // We have an unknown protocol here, print more info
            IrReceiver.printIRResultRawFormatted(&Serial, true);
        }
        Serial.println();

        if (IrReceiver.decodedIRData.command == 0x17){
            checkProfile(); } //only if the prodile buttons was detected as presses, change the mode
        /* !!!Important!!! Enable receiving of the next value,
         * since receiving has stopped after the end of the current received data packet.
         */
        IrReceiver.resume(); // Enable receiving of the next value

        //Finally, check the received data and perform actions according to the received command
//        if (IrReceiver.decodedIRData.command == 0x66) // i think i can delete these sections? 
//           {} //do something maybe
//         else if (IrReceiver.decodedIRData.command == 0x11) {
//            // do something else
//        }
    }
///DO NOT PUT ANTHING CYCLE-HEAVY HERE: WILL BREAK THE ABLITY TO LOOK FOR REMOTE SIGNALS 
    

  
 delay(100); Keyboard.releaseAll();                   // this releases the buttons; is kinda a fail safe
}

//=============SUBROUTINE start==============================
void handleRemoteFunctions() {
  switch (profile) {
    case 0:
      handleProfile0(); // YouTube
      break;
    case 1:
      handleProfile1(); // VLC
      break;
    case 2:
      handleProfile2(); //Windows/ System
      break;
    case 3:
      handleProfile3(); // RetroPie
      break;
    default:
      // maybe do nothing or an error case
      break;
  }
}
 




void searchTable(){
 // Example input hex code (can be replaced with actual sensor or input data)
  // Search for the input code in the lookup table
  bool found = false; //flag to do the lookup only once? 
  for (int i = 0; i < BUTTONS; i++) {
    if (lookupTable[i].code == IrReceiver.decodedIRData.command) {
      Serial.print("Action: "); Serial.println(lookupTable[i].word); //this is a debug function
      Serial.print("Index#:  "); Serial.println(i);                  // this is a debug function
        if (lookupTable[i].state !=0 ){ //if the state is ON, set it to OFF and exit the lookup call
          lookupTable[i].state=0; 
          found=true; 
          printTable_Debug();  //DEBUG STUFF
          break;}

      lookupTable[i].state=1;

      found = true;
      printTable_Debug();
      break;
    }
  }

  if (!found) {
    Serial.println("Code not found (Repeat)");
}
 delay(10);
}

void printTable_Debug(){
  Serial.println("Array values: ");
  for (int x = 0; x < 21; x++) {
    Serial.print(lookupTable[x].state); }
    //if (x < 12 - 1) {
     Serial.println(); // Add a break
    
     //Serial.print(IrReceiver.decodedIRData.command);
     //Serial.print("profile#: "); Serial.println(profile);
}

void checkProfile(){ //hi
if (lookupTable[0].state == 1) {  // Use a specific button for profile switching
    profile = (profile + 1) % 4;  // Cycle through profiles 0 to 3
    Serial.print("Switched to profile: ");
    Serial.println(profile);
    lookupTable[0].state = 0; }  /// i found the bug. why was this 16?
     updateColorMode();  // Call the updateColorMode function here
    // Trigger color change immediately after profile switch
}

void updateColorMode() { //updates LEDs when the mode changes
    if (profile != lastProfile) {
        // Profile has changed, update the colors accordingly
        lastProfile = profile; // Store the new profile

        switch (profile) {
            case 0:
                setColorsMode0();
                break;
            case 1:
                setColorsMode1();
                break;
            case 2:
                setColorsMode2();
                break;
            case 3:
                setColorsMode3();
                break;
        }
    }
}


//==============Setting the LED Colors when the Remote mode (profile) changes============================


void setColorsMode0() {
    for (int i = 0; i < NUMPIXELS; i++) {
        pixels.setPixelColor(i, pixels.Color(40, 0, 0)); } // Red color
    pixels.show();
    oled.setScale(3);
    oled.clear(); oled.setCursorXY(0,0);  oled.print("YouTube");
    oled.update();
}

void setColorsMode1() {
    for (int i = 0; i < NUMPIXELS; i++) {
        pixels.setPixelColor(i, pixels.Color(25, 20, 0)); } // yellow color
    pixels.show();
    oled.setScale(3);
    oled.clear(); oled.setCursorXY(0,0);  oled.print("VLC");
    oled.update();
}

void setColorsMode2() {
    for (int i = 0; i < NUMPIXELS; i++) {
        pixels.setPixelColor(i, pixels.Color(0, 0, 30)); }// Blue color
    pixels.show();
    oled.setScale(3);
    oled.clear(); oled.setCursorXY(0,0);  oled.print("Win/Sys");
    oled.update();
}

void setColorsMode3() {
    for (int i = 0; i < NUMPIXELS; i++) {
        pixels.setPixelColor(i, pixels.Color(25, 0, 25)); } // Purple color
    pixels.show();
    oled.setScale(3);
    oled.clear(); oled.setCursorXY(0,0);  oled.print("Retro"); oled.setCursorXY(0,30);oled.print("Pie");
    oled.update();
}

void resetButtonState() { //reset all button states in the remote lookup table. 
    // Reset button states for the current profile
    for (int i = 1; i < BUTTONS; i++) {
        lookupTable[i].state = 0;
    }
}



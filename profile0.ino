//
//============================YouTube [chrome] browser functions==================================

//this is a profile specific description array to print to the OLED the function.
//cannot do this for exery profile??, the ProMicro32u4 does not have enough dynamic memory (currently at 92% full)
const char* lookupDescriptions[] = {  //Table inded matches the remote
  "", // index 0 reserved for profile switches
  "Alt+Tab",
  "Fullscreen", // index 2 unused
  "Up",
  "Down",
  "  -5s",
  "  +5s",
  "Subtitles", 
  "Prev vid",  
  "nul",
  "Next vid",
  " -10s",
  "play/pause",
  " +10s ",
  "Vol+ ",
  "Vol-",
  "Mute",
  "cmd YouTube"
};

void displayFunction(const char* text){
  oled.setScale(2);         // smallest text size (range is 1-4)
  oled.setCursorXY(0,30);  oled.print(text);
  oled.update();
  //oled.setCursorXY(0,30);  oled.print("           "); oled.update(); // delays could be a problem/ dirty way to clear helper text
}

void handleProfile0() { //YouTube//////
  setColorsMode0();

  if (lookupTable[1].state == 1){ // back button = alt shift tab to swap active window
    Keyboard.press(KEY_LEFT_ALT); delay(25);
    Keyboard.press(KEY_LEFT_SHIFT); delay(25);
    Keyboard.press(KEY_TAB); delay(25);
    Keyboard.release(KEY_TAB); delay(100);
    Keyboard.release(KEY_LEFT_ALT); 
    Keyboard.release(KEY_LEFT_SHIFT); 
    displayFunction(lookupDescriptions[1]); //prints the profiles remote function. helpful for human memory/learning
    resetButtonState();
  }

  if (lookupTable[2].state == 1){ // f fullscreen
    Keyboard.press('f'); delay(25);
    Keyboard.release('f'); delay(25);
 
    displayFunction(lookupDescriptions[2]);
    resetButtonState();
  }

  if (lookupTable[3].state == 1){ // up arrow
    Keyboard.press(KEY_UP_ARROW); delay(25);
    Keyboard.release(KEY_UP_ARROW); delay(25);
    displayFunction(lookupDescriptions[3]);
    resetButtonState();
  }

  if (lookupTable[4].state == 1){ // down arrow
    Keyboard.press(KEY_DOWN_ARROW); delay(25);
    Keyboard.release(KEY_DOWN_ARROW); delay(25);
    displayFunction(lookupDescriptions[4]);
    resetButtonState();
  }

  if (lookupTable[5].state == 1){ // left arrow
    Keyboard.press(KEY_LEFT_ARROW); delay(25);
    Keyboard.release(KEY_LEFT_ARROW); delay(25);
    displayFunction(lookupDescriptions[5]);
    resetButtonState();
  }

  if (lookupTable[6].state == 1){ // right arrow
    Keyboard.press(KEY_RIGHT_ARROW); delay(25);
    Keyboard.release(KEY_RIGHT_ARROW); delay(25);
    displayFunction(lookupDescriptions[6]);
    resetButtonState();
  }

  if (lookupTable[7].state == 1){ // 'c' for subtitles
    Keyboard.press('c'); delay(25);
    Keyboard.release('c'); delay(25);
    displayFunction(lookupDescriptions[7]);
    resetButtonState();
  }

    if (lookupTable[8].state == 1){ // shift + p prev video
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press('p');
    Keyboard.release(KEY_LEFT_SHIFT);
    Keyboard.release('p');
    displayFunction(lookupDescriptions[8]);
    resetButtonState();
  }

  if (lookupTable[9].state == 1){ // 
  //something
   displayFunction(lookupDescriptions[9]);
    resetButtonState();
  }

  if (lookupTable[10].state == 1){ // shift + 'n' play next video
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press('n');
    Keyboard.release(KEY_LEFT_SHIFT);
    Keyboard.release('n');
    displayFunction(lookupDescriptions[10]);
    resetButtonState();
  }

  if (lookupTable[11].state == 1){ // 'j' seek -10s
    Keyboard.press('j'); delay(25);
    Keyboard.release('j'); delay(25);
    displayFunction(lookupDescriptions[11]);
    resetButtonState();
  }

  if (lookupTable[12].state == 1){ // 'k' play/pause
    Keyboard.press('k'); delay(25);
    Keyboard.release('k'); delay(25);
    displayFunction(lookupDescriptions[12]);
    resetButtonState();
  }

  if (lookupTable[13].state == 1){ // 'l' seek +10s
    Keyboard.press('l'); delay(25);
    Keyboard.release('l'); delay(25);
    displayFunction(lookupDescriptions[13]);
    resetButtonState();
  }

  if (lookupTable[14].state == 1){ // vol+ (up arrow)
    Keyboard.press(KEY_UP_ARROW); delay(50);
    Keyboard.release(KEY_UP_ARROW); delay(25);
    displayFunction(lookupDescriptions[14]);
    resetButtonState();
  }

  if (lookupTable[15].state == 1){ // vol- (down arrow)
    Keyboard.press(KEY_DOWN_ARROW); delay(50);
    Keyboard.release(KEY_DOWN_ARROW); delay(25);
    displayFunction(lookupDescriptions[15]);
    resetButtonState();
  }

  if (lookupTable[16].state == 1){ // mute 'm'
    Keyboard.press('m'); delay(25);
    Keyboard.release('m'); delay(25);
    displayFunction(lookupDescriptions[16]);
    resetButtonState();
  }

  if (lookupTable[17].state == 1){ // launch youtube via cmd terminal
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('r');
    Keyboard.release(KEY_LEFT_GUI);
    Keyboard.release('r');
    delay(50);
    Keyboard.println(F("chrome")); delay(500);
    Keyboard.println(F("https://www.youtube.com/"));
    displayFunction(lookupDescriptions[17]);
    resetButtonState();
  }

  pixels.show();
  delay(100);
  Keyboard.releaseAll();
}

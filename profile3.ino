//
//============================RetroPie functions==================================
void handleProfile3() { //
  setColorsMode3();

  if (lookupTable[1].state == 1){ // back button = alt shift tab to swap active window
    Keyboard.press(KEY_LEFT_ALT); delay(25);
    Keyboard.press(KEY_LEFT_SHIFT); delay(25);
    Keyboard.press(KEY_TAB); delay(25);
    Keyboard.release(KEY_TAB); delay(100);
    Keyboard.release(KEY_LEFT_ALT); 
    Keyboard.release(KEY_LEFT_SHIFT);
    resetButtonState();
  }

  if (lookupTable[2].state == 1){ // Menu = F1
    Keyboard.press(KEY_F11); delay(25);
    Keyboard.release(KEY_F11); delay(25);
    resetButtonState();
  }


  if (lookupTable[3].state == 1){ // up arrow
    Keyboard.press(KEY_UP_ARROW); delay(25);
    Keyboard.release(KEY_UP_ARROW); delay(25);
    resetButtonState();
  }

  if (lookupTable[4].state == 1){ // down arrow
    Keyboard.press(KEY_DOWN_ARROW); delay(25);
    Keyboard.release(KEY_DOWN_ARROW); delay(25);
    resetButtonState();
  }

  if (lookupTable[5].state == 1){ // left arrow
    Keyboard.press(KEY_LEFT_ARROW); delay(25);
    Keyboard.release(KEY_LEFT_ARROW); delay(25);
    resetButtonState();
  }

  if (lookupTable[6].state == 1){ // right arrow
    Keyboard.press(KEY_RIGHT_ARROW); delay(25);
    Keyboard.release(KEY_RIGHT_ARROW); delay(25);
    resetButtonState();
  }

    if (lookupTable[7].state == 1) { //enter
    Keyboard.press(KEY_RETURN); delay(25);
    Keyboard.release(KEY_RETURN); delay(25);
    resetButtonState();
  }
  if (lookupTable[8].state == 1) { //duckstation menu
    Keyboard.press(KEY_ESC); delay(25);
    Keyboard.release(KEY_ESC); delay(25);
    resetButtonState();
  }


  if (lookupTable[9].state == 1){ // back
    Keyboard.press('b'); delay(25);
    Keyboard.release('b'); delay(25);
    resetButtonState();
  }

  if (lookupTable[10].state == 1){ // select
    Keyboard.press('a'); delay(25);
    Keyboard.release('a'); delay(25);
    resetButtonState();
  }

  if (lookupTable[11].state == 1){ // window snap left
    Keyboard.press(KEY_LEFT_GUI); delay(25);
    Keyboard.press(KEY_LEFT_ARROW); delay(25);
    Keyboard.release(KEY_LEFT_GUI);
    Keyboard.release(KEY_LEFT_ARROW);
    resetButtonState();
  }

  if (lookupTable[12].state == 1){ // slideshow (google slides)

    resetButtonState();
  }

  if (lookupTable[13].state == 1){ // fast forward
    Keyboard.write(32); delay(25);  // 32= space bar (in decimal)
    Keyboard.release(32); delay(25);
    resetButtonState();
  }

  if (lookupTable[17].state == 1){ // F2 Save State
    Keyboard.press(KEY_F2); delay(25);
    Keyboard.release(KEY_F2);delay(25);
    resetButtonState();
  }
  if (lookupTable[18].state == 1){ // window snap right
    Keyboard.press(KEY_LEFT_GUI); delay(25);
    Keyboard.press(KEY_LEFT_ARROW); delay(25);
    Keyboard.release(KEY_LEFT_GUI);
    Keyboard.release(KEY_LEFT_ARROW);
    resetButtonState();
  }

  if (lookupTable[19].state == 1){ // F4 Load State
    Keyboard.press(KEY_F4); delay(25);
    Keyboard.release(KEY_F4);delay(25);
    resetButtonState();
  }
  if (lookupTable[20].state == 1){ // window snap right
    Keyboard.press(KEY_LEFT_GUI); delay(25);
    Keyboard.press(KEY_RIGHT_ARROW); delay(25);
    Keyboard.release(KEY_LEFT_GUI);
    Keyboard.release(KEY_RIGHT_ARROW);
    resetButtonState();
  }


  pixels.show();
  delay(100);
  Keyboard.releaseAll();
}

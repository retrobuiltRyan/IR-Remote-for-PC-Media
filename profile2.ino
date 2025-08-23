//
//============================Windows / System functions==================================

void handleProfile2() { 
  setColorsMode2();

  if (lookupTable[1].state == 1){ // back button = alt shift tab to swap active window
    Keyboard.press(KEY_LEFT_ALT); delay(25);
    Keyboard.press(KEY_LEFT_SHIFT); delay(25);
    Keyboard.press(KEY_TAB); delay(25);
    Keyboard.release(KEY_TAB); delay(100);
    Keyboard.release(KEY_LEFT_ALT); 
    Keyboard.release(KEY_LEFT_SHIFT);
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

  if (lookupTable[9].state == 1){ // Sleep via power user menu
    Keyboard.press(KEY_LEFT_GUI); delay(25);
    Keyboard.press('x'); delay(50);
    Keyboard.release('x'); delay(50);
    Keyboard.release(KEY_LEFT_GUI); delay(50);
    Keyboard.press('u'); delay(50);
    Keyboard.release('u'); delay(50);
    Keyboard.press('s'); delay(50);
    Keyboard.release('s'); delay(50);
    resetButtonState();
  }

  if (lookupTable[10].state == 1){ // enter
    Keyboard.press(KEY_RETURN); delay(25);
    Keyboard.release(KEY_RETURN); delay(25);
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
    Keyboard.press(KEY_LEFT_CTRL); delay(25);
    Keyboard.press(KEY_F5); delay(25);
    Keyboard.release(KEY_LEFT_CTRL);
    Keyboard.release(KEY_F5);
    resetButtonState();
  }

  if (lookupTable[13].state == 1){ // window snap right
    Keyboard.press(KEY_LEFT_GUI); delay(25);
    Keyboard.press(KEY_RIGHT_ARROW); delay(25);
    Keyboard.release(KEY_LEFT_GUI);
    Keyboard.release(KEY_RIGHT_ARROW);
    resetButtonState();
  }

  if (lookupTable[17].state == 1){ // launch youtube
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('r');
    Keyboard.release(KEY_LEFT_GUI);
    Keyboard.release('r');
    delay(50);
    Keyboard.println("chrome"); delay(500);
    Keyboard.println("https://www.youtube.com/");
    resetButtonState();
  }

  pixels.show();
  delay(100);
  Keyboard.releaseAll();
}

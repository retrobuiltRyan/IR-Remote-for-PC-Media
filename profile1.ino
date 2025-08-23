//
//============================VLC media player functions==================================
void handleProfile1() { //VLC
  setColorsMode1(); 

  if (lookupTable[1].state == 1) { // back button = alt shift tab to swap active window
    Keyboard.press(KEY_LEFT_ALT); delay(25);
    Keyboard.press(KEY_LEFT_SHIFT); delay(25);
    Keyboard.press(KEY_TAB); delay(25);
    Keyboard.release(KEY_TAB); delay(100);
    Keyboard.release(KEY_LEFT_ALT);
    Keyboard.release(KEY_LEFT_SHIFT);
    resetButtonState();
  }

  if (lookupTable[2].state == 1) { // cycle audio track
    Keyboard.press('f'); delay(25);
    Keyboard.release('f'); delay(25);
    resetButtonState();
  }

  if (lookupTable[3].state == 1) { // up arrow
    Keyboard.press(KEY_UP_ARROW); delay(25);
    Keyboard.release(KEY_UP_ARROW); delay(25);
    resetButtonState();
  }

  if (lookupTable[4].state == 1) { // down arrow
    Keyboard.press(KEY_DOWN_ARROW); delay(25);
    Keyboard.release(KEY_DOWN_ARROW); delay(25);
    resetButtonState();
  }

  if (lookupTable[5].state == 1) { // left arrow
    Keyboard.press(KEY_LEFT_ARROW); delay(25);
    Keyboard.release(KEY_LEFT_ARROW); delay(25);
    resetButtonState();
  }

  if (lookupTable[6].state == 1) { // right arrow
    Keyboard.press(KEY_RIGHT_ARROW); delay(25);
    Keyboard.release(KEY_RIGHT_ARROW); delay(25);
    resetButtonState();
  }

  if (lookupTable[7].state == 1) {
    Keyboard.press(KEY_RETURN); delay(25);
    Keyboard.release(KEY_RETURN); delay(25);
    resetButtonState();
  }

  if (lookupTable[8].state == 1) {
   
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press('m'); delay(25);
    Keyboard.release('m');
    Keyboard.release(KEY_LEFT_SHIFT); delay(25);
    resetButtonState();
  }

  if (lookupTable[9].state == 1) { // cycle audio track
    Keyboard.press('b'); delay(25);
    Keyboard.release('b'); delay(25);
    resetButtonState();
  }

  if (lookupTable[10].state == 1) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press('v'); delay(25);
    Keyboard.release(KEY_LEFT_SHIFT);
    Keyboard.release('v'); delay(25);
    resetButtonState();
  }

  if (lookupTable[11].state == 1) { // seek -60 sec
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ARROW); delay(25);
    Keyboard.release(KEY_LEFT_CTRL);
    Keyboard.release(KEY_LEFT_ARROW); delay(25);
    resetButtonState();
  }

  if (lookupTable[12].state == 1) { // space play/pause
    Keyboard.write(32); delay(25);
    resetButtonState();
  }

  if (lookupTable[13].state == 1) { // seek +60 sec
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_RIGHT_ARROW); delay(25);
    Keyboard.release(KEY_LEFT_CTRL);
    Keyboard.release(KEY_RIGHT_ARROW); delay(25);
    resetButtonState();
  }

  if (lookupTable[14].state == 1) {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_UP_ARROW); delay(25);
    Keyboard.release(KEY_LEFT_CTRL);
    Keyboard.release(KEY_UP_ARROW); delay(25);
    resetButtonState();
  }

  if (lookupTable[15].state == 1) {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_DOWN_ARROW); delay(25);
    Keyboard.release(KEY_LEFT_CTRL);
    Keyboard.release(KEY_DOWN_ARROW); delay(25);
    resetButtonState();
  }

  if (lookupTable[16].state == 1) { // mute
    Keyboard.press('m'); delay(25);
    Keyboard.release('m'); delay(25);
    resetButtonState();
  }

  if (lookupTable[17].state == 1) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press('p'); delay(25);
    Keyboard.release(KEY_LEFT_SHIFT);
    Keyboard.release('p'); delay(25);
    resetButtonState();
  }

  if (lookupTable[18].state == 1) {
    Keyboard.press('p'); delay(25);
    Keyboard.release('p'); delay(25);
    resetButtonState();
  }

  if (lookupTable[19].state == 1) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press('n'); delay(25);
    Keyboard.release(KEY_LEFT_SHIFT);
    Keyboard.release('n'); delay(25);
    resetButtonState();
  }

  if (lookupTable[20].state == 1) {
    Keyboard.press('n'); delay(25);
    Keyboard.release('n'); delay(25);
    resetButtonState();
  }

  pixels.show();
  delay(100);
  Keyboard.releaseAll();
}

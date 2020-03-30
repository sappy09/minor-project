#​include​ ​<​Wire.h​>​ 
#​include​ ​<​LiquidCrystal_I2C.h​>​
LiquidCrystal_I2C ​lcd​(​0x27​, ​16​, ​2​); ​//​ Set the LCD address to 0x27; 16 chars and 2 lines (use I2C scan to confirm address)​

​void​ ​setup​()
{
  ​pinMode​(s0, OUTPUT);
  ​pinMode​(s1, OUTPUT);
  ​pinMode​(s2, OUTPUT);
  ​pinMode​(s3, OUTPUT);
  ​pinMode​(outPin, INPUT); ​//​out from sensor becomes input to arduino​

    ​//​ Setting frequency scaling to 100%​
  ​digitalWrite​(s0,HIGH);
  ​digitalWrite​(s1,HIGH);
  
  Serial.​begin​(​9600​);
  lcd.​begin​();
  ​//​ lcd.noBacklight();​
  lcd.​print​(​"​MJRoBot ColorDet​"​);
  Serial.​println​(​"​MJRoBot Color Detector​"​);
  startTiming = ​millis​();
}

​void​ ​loop​()
{
  ​getColor​();
  ​if​ (DEBUG) ​printData​(); 
  elapsedTime = ​millis​()-startTiming; 
  ​if​ (elapsedTime > ​1000​) 
  {
    ​showDataLCD​();
    startTiming = ​millis​();
  }
}

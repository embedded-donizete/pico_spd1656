#include <Arduino.h>

#include "EPD_5in65f.h"
#include "DEV_Config.h"
#include "ImageData.h"

void setup()
{
  Serial.begin(9600);

  DEV_Module_Init();
  EPD_5IN65F_Init();
  EPD_5IN65F_Clear(EPD_5IN65F_WHITE);
  DEV_Delay_ms(100);
}

void loop()
{
  Serial.println("Starting loop");

  EPD_5IN65F_Display(gImage_5in65f);
  Serial.println("First image image");
  DEV_Delay_ms(5000);
}
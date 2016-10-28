//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*                                          - Display Test -                                          *|
|*                                      ROBOTC on VEX 2.0 Cortex                                      *|
|*                                                                                                    *|
|*  This program uses the Display functions of ROBTOC on the VEX 2.0 Cortex platform.                 *|
|*  It will display a message =]                                                                      *|
|*                                                                                                    *|
|*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|
|*    1)  The LCD Screen must be attached to UART Port 2.                                             *|
|*                                                                                                    *|
|*    MOTORS & SENSORS:                                                                               *|
|*    [I/O Port]          [Name]              [Type]                [Description]                     *|
|*    UART Port 2         none                VEX LCD               VEX LCD Screen                    *|
\*-----------------------------------------------------------------------------------------------4246-*/


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
  clearLCDLine(0);                      // Clear line 1 (0) of the LCD
  clearLCDLine(1);                      // Clear line 2 (1) of the LCD

  bLCDBacklight = true;                 // Turn on LCD Backlight

  displayLCDPos(0,0);                   // Set the cursor to line 0, position 0 (top line, far left)

  displayNextLCDString("Hello from");   // Display "Hello from"

  displayLCDPos(1,0);                   // Set the cursor to line 1, position 0 (bottom line, far left)

  displayNextLCDString("ROBOTC  :]");   // Display "ROBOTC :]"

  while(true)                           // An infinite loop to keep the program running until you terminate it
  {
  }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

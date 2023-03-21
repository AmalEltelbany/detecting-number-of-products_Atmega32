# detecting-number-of-products_Atmega32
[Untitled video - Screen Recording - 3_22_2023, 1_07_56 AM.webm](https://user-images.githubusercontent.com/112574745/226762244-7e25486c-a8c0-4a7b-8355-6be0e0f288b2.webm)

  Build an AVR based system to control a DC motor that controls a belt in a
factory, the belt carries product for packaging. A sensor is fixed to detect
products passing on the belt. There are 2 LEDs, a green one indicating that
the system is running and a red one to indicate that the system is stopped;
and a buzzer that beeps on system stop. The system must follow the following
behavior:
1. A push button is used to start the belt motor when stopped, and turn
ON the green LED. Buzzer and red LED must be OFF.
2. Automatic packaging must stop after having 12 products in the box,
thus the belt motor must stop and wait until the push button is pressed
to restart the system.
3. On finishing packaging, the system is required to make a beep using a
buzzer and turn ON the red LED to indicate finishing the process

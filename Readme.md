# Wave and Ellie
(Skillmatics)

The repository contains the following files:

1. [technical_prototype](./technical_prototype.ino) - Final code which contains dependencies on all other files. To be run on an Arduino Uno/ATMega328P microcontroller natively. All components and their respective pin locations are documented within comments
2. [colour_functions](./colour_functions.ino) - Contains all the functions necessary for detection and analysis of the colour displayed in front of the toy using the TCS3200 colour sensor. Pin map in code.
3. [music_and_lights](./music_and_lights.ino) - Contains all the functions necessary for white LED output and ones required for audio output through an attached speaker. Audio files not included.
4. [test_functions](./test_functions.ino) - Contains all functions necessary for testing and calibrating the colour sensor. Corresponding functions in the main code file can be uncommented to use.
5. [rgb_functions](./rgb_functions.ino) - Contains all functions necessary for RGB LED output.
6. [pins_defined](./pins_defined.h) - Header file containing all pin placements along with corresponding component details.
7. [pitches.h](./pitches.h) - Header file containing data utilised by piexoelectric buzzer to play tunes in place of speaker if using a speaker is not possible. Corresponding lines in main code have been commented out.
8. mode_1 to mode_5 - Contains code for all 5 modes of the gameplay. Gameplay ellaborated as comments in respective files

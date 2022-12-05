Joysticktest.ino was one of the first sketches, based on the temperature sensor demo at https://blogs.uw.edu/fizzlab/technology/examples  accessed 11/21/2018. The intent was simply to connect the joystick potentiometer pins to the Arduino analog inputs, and view the data through serial monitor and plotter. Serial monitory quickly revealed problems with "centering" (neutral position for each axis was around 250-300instead of 512) along with "low-end truncation" (joystick axes would go down to around 122 but not to zero) Serial plotter revealed overall noisiness. Function remapJoyAxis() was added to separately remap the "top part" and "bottom part" of each joystick axis, to get a behavior closer to 0-1023 with 512 in the middle.  Pin assignments and remapJoyAxis() were later integrated into the main simulator code.
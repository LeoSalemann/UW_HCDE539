# Input Devices
Lots of options; need to find the right point in the {cool, easy, cheap} space.
- **USB Joystick** The most desirable; the most complex. Seems to require sophisticated boards, a simple breakout probably won't do.
  - [Circuits@home $34 USB Host Shield](http://shop.tkjelectronics.dk/product_info.php?products_id=43)
       - Can find libraries for name-brand game cotrollers
       - [They have an example with Logitech 3D](https://www.circuitsathome.com/mcu/using-logitech-extreme-3d-pro-joystick-with-arduino-hid-library/)
       - The big risk is getting my current sticks to work.  [This google search](https://www.google.com/search?ei=SQfqW8-yI5q70PEPs52o2A8&q=is+saitek+cyborg+stick+a+HID+device&oq=is+saitek+cyborg+stick+a+HID+device&gs_l=psy-ab.3..33i299l3.17461.28094..28463...0.0..0.92.2125.35......0....1..gws-wiz.......0j0i71j0i131j0i67j0i3j0i13j0i22i30j33i22i29i30j33i160.pyWuD3VB1Qk) sugest my Saitek Cyborg is a HID.
- **Old-School PC Joystick** Seems more tractable, and I do have a yoke.  
[promising  pinout link](https://allpinouts.org/pinouts/connectors/input_device/joystick-pc-gameport/)
- **Bluetooth Game Controller** I've got the shield, maybe I can read & parse gamepad data.

## Cost Considerations
- USB is the highest cost; highest risk.
- Bluetooth is free (I have one), also high risk
- Sampling pins off my PC joystick should work; easy to test.
- Basic Thumb joysticks easiest to buy/use. That's my fallback.

## Getting Iterative with Input
1. Control one servo with a pot
1. Sample pins from PC joystick, see what can be done.
1. Control servo with one PC joystick axis
1. See what I can read from bluetooth game controller

## More links
[connecting gamepad to arduino (uses weird libraries)](https://www.makeuseof.com/tag/arduino-robot-game-controller/)
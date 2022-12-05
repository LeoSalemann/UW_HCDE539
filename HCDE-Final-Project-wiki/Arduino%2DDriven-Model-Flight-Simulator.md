
[[_TOC_]]
#Overview

# Design & Architecture, Alternatives

## Arduino as Motion Platform

- All it does is move the platform (2DOF, maybe 3DOF)
- Depend on motion to operate the sim.
- No throttle or anything like that (unless robo-pen)
- All the stick has to do is talk to the arduino and ervos


## Arduino as Motion Platform AND Game controller
 - Arduino sends bluetooth signals to the phone
 - Basically build an Arduino bluetooth game controller that also moves a platform.

## Arduino as USB-to-Bluetooth Converter
- Super-hard way, Read USB
   - Get stick & button inputs form USB
   - Translate to Bluetooth
   - Also move the platform as a side-effect


# Input Devices
Lots of options; need to find the right point in the {cool, easy, cheap} space.

## USB Joystick

- The most desirable; the most complex. Seems to require sophisticated boards, a simple breakout probably won't do.
  - [Main Arduino discussion post](https://forum.arduino.cc/index.php?topic=452574.0)
    
     - First thing they reference is [Gravitech](http://www.gravitech.us/usadforarna.html), which leads you to their [full-size version](http://www.gravitech.us/usbhostshield.html) which leads you to [Circuits@home](https://www.circuitsathome.com/arduino_usb_host_shield_projects/)

       - Alternate place to purchase site is  [TKJ electronics $34 USB Host Shield](http://shop.tkjelectronics.dk/product_info.php?products_id=43)

      - Article also linked to [Circuits@home github repo](https://github.com/felis/USB_Host_Shield_2.0)

       - Has libraries for PS3, PS4, Wii, XBOX controllers

       - Best to look at [all of Oleg's Github Repos](https://github.com/felis?tab=repositories) then try USB_Host_Shield_2.0 and/or UHS30

     - Circuits@home [has an example with Logitech 3D](https://www.circuitsathome.com/mcu/using-logitech-extreme-3d-pro-joystick-with-arduino-hid-library/)

    - Circuits@Home [blog page](https://www.circuitsathome.com/category/mcu/arduino/usb-shield/) includes an announcement of [host library 3.0 on github](https://github.com/felis/UHS30) Most recent changes are 17 days ago.

     - The big risk is getting my current sticks to work.  [This google search](https://www.google.com/search?ei=SQfqW8-yI5q70PEPs52o2A8&q=is+saitek+cyborg+stick+a+HID+device&oq=is+saitek+cyborg+stick+a+HID+device&gs_l=psy-ab.3..33i299l3.17461.28094..28463...0.0..0.92.2125.35......0....1..gws-wiz.......0j0i71j0i131j0i67j0i3j0i13j0i22i30j33i22i29i30j33i160.pyWuD3VB1Qk) suggests the Saitek Cyborg is a HID.

    -  Sparkfun makes a BOB-12700 that just breaks out the four wires, but I don't think I can find code to deal with it.  Available at [Mouser](https://www.mouser.com/ProductDetail/SparkFun/BOB-12700?qs=WyAARYrbSnZJzAHrXzS2Mw%3D%3D&gclid=CjwKCAiA5qTfBRAoEiwAwQy-6RgqOXj2zFfNRXqwguTYJG9ypGGff7wP8jzyCRT53kQKeKGnxmOa6RoCpZYQAvD_BwE)

       - There's an [Arduino forum post](http://forum.arduino.cc/index.php?topic=329532.0) that dissuades you from reading D+/D- directly; and recommends the good ol' Circuits@home USB Host 2.0 shireld.

- Pinouts.ru [has a good USB article](http://pinouts.ru/Slots/USB_pinout.shtml)

- Another source is [Hobby Electronics](http://www.hobbytronics.co.uk/usb-host-board-v2) for L14.95 = $19.22
  - Not sure about cost.
  - [arduino code seems simple](http://www.hobbytronics.co.uk/usb-host-joystick)


## Old-School PC Joystick

- Seems more tractable, and I do have a yoke.  
- [promising  pinout link](https://allpinouts.org/pinouts/connectors/input_device/joystick-pc-gameport/)

- [build its has a blog article with full wiring] (http://build-its.blogspot.com/2012/01/arduino-game-port-interface.html)

## Bluetooth Game Controller 
- I've got the shield, maybe I can read & parse gamepad data.

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
- [connecting PS2 controller looks easy](http://www.billporter.info/2010/06/05/playstation-2-controller-arduino-library-v1-0/)

- [connecting gamepad to arduino (uses weird libraries)](https://www.makeuseof.com/tag/arduino-robot-game-controller/)

# Design Artifacts
[TinkerCAD Project](https://www.tinkercad.com/#/dashboard?type=all&collection=projects&id=hD0zWI7FyRN)

# Even More Links
https://allpinouts.org/pinouts/connectors/input_device/joystick-pc-gameport/


http://build-its.blogspot.com/2012/01/arduino-game-port-interface.html

https://www.reddit.com/r/arduino/comments/ps71v/why_does_my_servo_make_a_clicking_noise_at_a/

https://www.wikihow.com/Wire-a-Potentiometer

https://www.tinkercad.com/things/ehMveOIekxN-copy-of-3-servos-driven-by-pots/editel?tenant=circuits


https://learn.adafruit.com/introducing-adafruit-ble-bluetooth-low-energy-friend/ble-services

https://learn.adafruit.com/introducing-adafruit-ble-bluetooth-low-energy-friend/ble-services

https://github.com/adafruit/Adafruit_BluefruitLE_nRF51/pull/37/files

## Bluetooth/Bluefruit links
Factory reset https://learn.adafruit.com/introducing-the-adafruit-bluefruit-le-uart-friend/factory-reset

Mouse move https://learn.adafruit.com/introducing-adafruit-ble-bluetooth-low-energy-friend/ble-services#at-plus-blehidmousemove-14-35









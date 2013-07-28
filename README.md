keylight
========

A little C program to manage the backlight of an ASUS keyboard

Note: Only tested on my Asus R401VB

= Installation
* Compile the program
  > gcc -o keylight keylight.c
* Important: Change the owner to root and add setuid
  > sudo chown root keylight; sudo chmod 6755 keylight
* Move to /usr/local/bin or anyplace you want
  > sudo mv keylight /usr/local/bin/keylight

= Use

    keylight

Show current value

    keylight [n]

Set backlight to *n*

    keylight +

Increase backlight

    keylight -

Decrease backlight

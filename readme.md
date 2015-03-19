# Voice control to turn on/off lights

### Step 1: Material 

* Macbook
- Arduino uno
+ Jumper wires
+ 1 LED
+ Resistor, anything between 220 ohm to 1K ohm
- Arduino board
- Standard solderless breadboard

### Step 2: Connect LED with Arduino 

Images 



To build the circuit, connect one end of the resistor to Arduino pin 13. Connect the long leg of the LED (the positive leg, called the anode) to the other end of the resistor. Connect the short leg of the LED (the negative leg, called the cathode) to the Arduino GND.



### Step 3: Communicate Arduino with shell script

Download [Arduino-serial utility](http://todbot.com/blog/2006/12/06/arduino-serial-c-code-to-talk-to-arduino/comment-page-2/) which enables o communicate directly with the arduino from the shell script. Place it in the root of your user directory, then open up a terminal and type:

```
make arduino-serial

```
Connect your arduino with the computer and then in the terminal type:

```
ls /dev/tty.*
```

to figure out which port your arduino is on. Mine is /dev/tty.usbmodem1411. And replace it with your own port. Then try to run this line of code in terminal and see if it works 

```
./arduino-serial -b 9600 -p /dev/tty.usbmodem1411 -s lightsOn

```


My output is:

```
opened port /dev/tty.usbmodem1411
send string:lightsOn
```

Now create a shell script file in the root directory. Name it lightson.sh. Put this line in it, again with your own port 

```
./arduino-serial -b 9600 -p /dev/tty.usbmodem1411 -s lightsOn

```


### Step 4: Use Automator to run shell script

Open Automator, and create a new **application**. Find the **Run a shell Script** action and drag/add it. 

In the shell script, write 

```
sh ~/lightson.sh

```

**~/lightson.sh** is the directory where you put your shell script, I put it in the root directory.

image  


save it to **library/speech/Speakable Items** and name it "lights on".


### Step 5: Finally voice control

Go to **system preference**, then **Accessibility**, scroll down and find **Dictation**, Click **Dictation Commands** Click **+** button to add new commands. When I say **lights on** while using: **Any Application** Perform  open app and find lightson.app in the directory of **~/Library/Speech/Speakable\ Items/lights\ on.app** Finally click **Done**. now you have hooked up your voice with the shell script by running the lighton.app.


### Step 5: Run arduino 

Open arduino app, and paste the following code 


Code !





### Step 5: Final step, voice control 

Go to **system preference** and search for speech. Set the short cut. In my case I press Left Command key twice. 

Now click Left Command key twice and say "lights on", "light off", Enjoy! 
  





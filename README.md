# ThimbleKrox

A thimble which, thanks to a GY-521 and an Arduino Leonardo, is able to control the mouse pointer.
## How to build it

### Step 1: Materials and tools needed
Materials needed:
* Arduino Micro
* MPU-6050
* A cable to connect the Arduino and the PC (micro USB to USB)
* Jumper (to connect the Arduino and the MPU-6050)
* An elastic (if you want to attach the Arduino to your hand)

Tools needed:
* A computer with the Arduino IDE installed (to boot the code in the Arduino)
* Soldering iron (only if the Arduino does not have the pins connectors pre-assembled)
* 3D printer (if you want your thimble to look cool)

### Step 2: Connection
Connect the pins of the arduino to the pins of the MPU-6050:
* pin VCC of arduino to pin VCC
* pin GND to GND
* pin 2 to SDA
* pin 3 to SCL.

### Step 3: 3D printing (optional)
If you want your thimble to look good, and if you have a 3D printer, you can print the physical thimble.
I did it in two versions, one clear which therefore does not require supports to be printed and is not too bulky, a second one instead that I tried to do in steampunk style without making it too bulky (it is still more bulky than the clear one ), but this one requires supports to be printed and only return best if colored (for PLA I got along well with tempera).Both require to be printed with the part with the two internal protrusions in the bottom.

### Step 4: Assembly

#### With the 3D printed thimble
To mount everything with the printed thimble, after making the connections it is necessary to insert the MPU-6050 inside the upper cavity of the thimble housing the cables in the lower cavity

#### Without the 3D printed thimble
In this case, the assembly is done in a more amateur way, ie by positioning the MPU-6050 in the last phalanx of the interested finger and blocking it with adhesive tape or an elastic.

### Step 5: Code and Calibration
The first thing to do to run the code is to install the required libraries that is Wire.h, I2Cdev.h, MPU6050.h and Mouse.h
After doing this it is my advice to load the ThimbleKrox calibration code, put on the thimble and open the serial monitor (Ctrl + Shift + M).
You should now see something like this:<br>
`right | gx = 3165 gy = 469 gz = -1055 | ax = 15232 ay = 2064 az = -4496`<br>
Where is shown the direction in which, if correctly calibrated, you want to make the pointer go and then some values necessary for calibration.
Now you have to reopen the code and go to the lines marked with "// calibration line" and change the numerical values until you get the correct direction. (Every time you change a value in the code you need to reupload it in the Arduino)

>Ex.<br>
>Serial monitor:<br>
>`left | gx = 3165 gy = 469 gz = -1055 | ax = 5232 ay = 2064 az = -4496`<br>
>
>Calibration code:<br>
> `if (ax> = 15000) {                                 // calibration line`<br>
>   ` right ();`<br>
> ` } `<br>
>
>The serial monitor marks "left" but we want this line to be marked "right" so we need to change the "15000" value to "5000". This is because, in this case, we have to make >sure that the detected "ax" is greater than the value in the code. We understand that it must be greater because in the code there is a major sign and that we have to look at >the "ax" of the serial monitor because in the code there is "ax". (only the numerical values of the code need to be changed)
>
>After reloading the code in the Arduino we will have:
>Serial monitor:<br>
>`right | gx = 3165 gy = 469 gz = -1055 | ax = 5232 ay = 2064 az = -4496`<br>
>
>Calibration code:<br>
 >`if (ax> = 5000) {                         // calibration line`<br>
 >  ` right ();`<br>
 >` } `<br>

When all the calibration lines in the calibration code have been adjusted and therefore the calibration version thimble is functional, the values of the main code must be adjusted to match the calibration code.

>Ex.<br>
>Calibration Code:<br>
>   `if (ax> = 5000) {// calibration line` <br>
>    `right ();` <br>
>  `}` <br>
>
>Main code:<br>
>  `if (ax> = 15000) {// calibration line` <br>
>    `right ();` <br>
>  `}` <br>
>
>The main code must be changed to:<br>
>  `if (ax> = 5000) {// calibration line` <br>
>    `right ();` <br>
>  `}` <br>

### Step 6: Finish the project
Now is the time to wear your thimble and play with it!

-------------
## Hackster guide [here](https://www.hackster.io/magform/thimblekrox-mouse-control-with-your-fingers-dd8881).

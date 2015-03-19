/* Sketch Name..:  Arduino Voice Control via Serial Demo
 * Author.......:  James Bruce, for MakeUseOf.com
 * Description..:  Monitor serial communications and turn on or 
                   off relay switches for external devices
 * Date Created.: 5 February 2013
 */

//Buffer serial data to accept strings
char inData[20]; // Allocate some space for the string
char inChar=-1; // Where to store the character read
byte index = 0; // Index into array; where to store the character

int led = 13;

void setup() { 
    Serial.begin(9600);
    pinMode(led,OUTPUT);
  
}

void loop() {
  
    if(Comp("lightsOn")==0){
       //insert relay control code to turn on devices
       digitalWrite(led,HIGH);
       Serial.println("turning on");
    }
    else if(Comp("lightsOff")==0){
         
       //insert your relay controls here to turn off 
       digitalWrite(led,LOW);
       Serial.println("turning off");  
    }
    /* To create more commands, send a different string and listen for it with another
    * else if statement:
    * else if(Comp("ovenOn")==0){}
    */
    
}

/* Serial buffer for reading Strings:
* Credit to PaulS
* on this forum thread http://arduino.cc/forum/index.php/topic,45629.0.html
*/

char Comp(char* This) {
    while (Serial.available() > 0) // Don't read unless
                                   // there you know there is data
    {
        if(index < 19) // One less than the size of the array
        {
            inChar = Serial.read(); // Read a character
            inData[index] = inChar; // Store it
            index++; // Increment where to write next
            inData[index] = '\0'; // Null terminate the string
        }
    }

    if (strcmp(inData,This)  == 0) {
        for (int i=0;i<19;i++) {
            inData[i]=0;
        }
        index=0;
        return(0);
    }
    else {
        return(1);
    }
}

// Declare variables
int rLed = D5;
int gLed = D4;
int bLed = D6;

// Boolean to check if light is on/off
bool frLed = false;
bool fgLed = false;
bool fbLed = false;


int light(String command); // Forward declaration

void setup() {
    // Initialize
    pinMode(rLed, OUTPUT);
    pinMode(gLed, OUTPUT);
    pinMode(bLed, OUTPUT);
    Particle.function("led", light);

}

void loop() {

}

int light(String command)
{
    // Check which command is being use and toggle the appropriate flag
    if (command == "red")
    {
        if (frLed == false) {
            frLed = true;
        } else
        {
            frLed = false;
        }
    } else if (command == "green")
    {
        if (fgLed == false) {
            fgLed = true;
        } else
        {
            fgLed = false;
        }
    } else if (command == "blue")
    {
        if (fbLed == false) {
            fbLed = true;
        } else
        {
            fbLed = false;
        }
    } else {
        // Exit if input is bad
        return -1;
    }
    // Run commands. If commands are run event is successful
    ledOn();
    return 1;
}


void ledOn()
{
    // True means LED is being turned on. Toggle the LED on/off
        if (frLed == true)
        {
            digitalWrite(rLed, HIGH);
        } else if (frLed == false)
        {
            digitalWrite(rLed, LOW);
        }
        
        if (fbLed == true)
        {
            digitalWrite(bLed, HIGH);
        } else if (fbLed == false)
        {
            digitalWrite(bLed, LOW);
        }
        
        if (fgLed == true)
        {
            digitalWrite(gLed, HIGH);
        } else if (fgLed == false)
        {
            digitalWrite(gLed, LOW);
        }
}

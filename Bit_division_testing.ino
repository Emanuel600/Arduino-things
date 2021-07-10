/* This is meant to check analogue
 *inputs and see if I shold divide
 *the result by 1024 or 1023
 *
 * Since I don't REALLY care about
 *the accuracy (I'm only using an
 *Arduino after all) I'll just divide
 *by 1024 if testing deems it
 *necessary
 *
 * Results as a footnote at the end
 *of this code
 */

#define ANIN A0       //<= Analog input
#define VREF 5.00     //<= Reference Voltage
#define STEPS 1024.00 //<= Steps on the analogue read (2^10)

/* Testing method:
 *A know reference voltage of 5V
 *is going to be put across a 330 ohm
 *resistor and read through the analog
 *input.
 */

  // Define variables to be used
  float vout = 0; //<= Voltage to be read on the analog pin

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Read the voltage
  vout = analogRead(ANIN);
  // Print the voltage
  if (vout != 0){  //<= Only prints when something is being read
    // Print unprocessed signal
    Serial.print("Vout: ");
    Serial.println(vout);               //<= Reads 1023.00 consistently
    // Print processed signal
    Serial.print("Processed Vout: ");
    Serial.println(VREF * vout/STEPS);  //<= Reads 5.00 consistently
  }
}

/* Results:
 * Analogue read 5V as 1023.00 but
 *dividing it by 1024 always results
 *in 1.00 exactly
 */

/* Conclusion:
 * It's probably a good idea to
 *always divide by 1024 and multiply
 *by the reference value
 */

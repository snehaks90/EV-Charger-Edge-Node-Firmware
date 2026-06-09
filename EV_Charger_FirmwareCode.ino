void setup() {
  Serial.begin(115200);   // Initialize UART communication
}

const int alpha = 20;

int previousVoltage = 420;
int previousCurrent = 50;

void loop() {

  /*
   1. Sensor Simulation
  */

  int voltage;
  int current;

  bool sensorFailure = (random(0, 100) < 5);   // 5% chance of failure

  if(sensorFailure)
  {
    Serial.println("ERROR: Sensor Read Failed. Using Last Known Good Value.");

    voltage = previousVoltage;
    current = previousCurrent;
  }
  else
  {
    int baseVoltage = 420;
    int baseCurrent = 50;

    voltage = baseVoltage + random(-5, 6);
    current = baseCurrent + random(-3, 4);
  }

  /*
   2. Signal Filtering using EMA
  */

  int filteredVoltage =
      (alpha * voltage +
      (100 - alpha) * previousVoltage) / 100;

  int filteredCurrent =
      (alpha * current +
      (100 - alpha) * previousCurrent) / 100;

  /*
   3. Power Calculation
  */

  int power = filteredVoltage * filteredCurrent;

  /*
   4. Fault Detection
  */

  int faultFlag = 0;

  if(filteredVoltage > 480)
  {
    faultFlag |= 0x01;

    Serial.print("FAULT: OVER VOLTAGE | Value: ");
    Serial.print(filteredVoltage);
    Serial.println("V | Threshold: 480V");
  }

  if(filteredCurrent > 90)
  {
    faultFlag |= 0x02;

    Serial.print("FAULT: OVER CURRENT | Value: ");
    Serial.print(filteredCurrent);
    Serial.println("A | Threshold: 90A");
  }

  if(power > 22000)
  {
    faultFlag |= 0x04;

    Serial.print("FAULT: OVER POWER | Value: ");
    Serial.print(power);
    Serial.println("W | Threshold: 22000W");
  }

  Serial.print("Fault Flag: ");
  Serial.println(faultFlag);

  /*
   5. CAN Frame Packing
  */

  uint8_t canData[8];

  canData[0] = filteredVoltage & 0xFF;
  canData[1] = (filteredVoltage >> 8);

  canData[2] = filteredCurrent & 0xFF;
  canData[3] = (filteredCurrent >> 8);

  canData[4] = power & 0xFF;
  canData[5] = (power >> 8);

  canData[6] = faultFlag;

  canData[7] = 0;   // Reserved

  Serial.print("CAN Frame: ");

  for(int i = 0; i < 8; i++)
  {
    Serial.print(canData[i]);
    Serial.print(" ");
  }

  Serial.println();

  /*
   6. UART Output
  */

  Serial.print("Voltage: ");
  Serial.print(filteredVoltage);
  Serial.print(" V  ");

  Serial.print("Current: ");
  Serial.print(filteredCurrent);
  Serial.print(" A  ");

  Serial.print("Power: ");
  Serial.print(power);
  Serial.println(" W");

  /*
   7. CAN Error Handling
  */

  /*
   Simulated CAN transmission result.
   Actual TWAI/CAN transmission could not be
   verified in the simulation environment.
 */
  bool canTransmitSuccess = (random(0,100) >= 5);

  if(!canTransmitSuccess)
  {
    Serial.println("ERROR: CAN Transmission Failed");
  }

  Serial.println("--------------------------------------------------");

  /*
   Update Previous Values
  */

  previousVoltage = filteredVoltage;
  previousCurrent = filteredCurrent;

  /*
   Sample Interval = 100 ms
  */

  delay(100);
}

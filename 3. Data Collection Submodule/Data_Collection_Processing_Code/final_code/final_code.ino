#define NUM_COEFFICIENTS 363  // Number of filter coefficients

//Kaiser Window Filter Coefficients
float coefficients[NUM_COEFFICIENTS] = {0.00043367,0.00044996,0.00046656,0.00048346,0.00050066,0.00051817,0.00053598,0.0005541,0.00057253,0.00059125,0.00061028,0.00062961,0.00064924,0.00066916,0.00068939,0.00070991,0.00073073,0.00075185,0.00077325,0.00079495,0.00081693,0.00083921,0.00086176,0.0008846,0.00090772,0.00093112,0.0009548,0.00097875,0.001003,0.0010275,0.0010522,0.0010772,0.0011025,0.001128,0.0011538,0.0011798,0.0012061,0.0012326,0.0012594,0.0012864,0.0013136,0.0013411,0.0013687,0.0013966,0.0014247,0.001453,0.0014815,0.0015103,0.0015392,0.0015683,0.0015976,0.0016271,0.0016567,0.0016865,0.0017165,0.0017467,0.001777,0.0018074,0.001838,0.0018687,0.0018996,0.0019306,0.0019617,0.0019929,0.0020243,0.0020557,0.0020873,0.0021189,0.0021506,0.0021824,0.0022143,0.0022462,0.0022782,0.0023102,0.0023423,0.0023745,0.0024066,0.0024388,0.002471,0.0025032,0.0025354,0.0025677,0.0025999,0.0026321,0.0026642,0.0026964,0.0027285,0.0027605,0.0027925,0.0028245,0.0028564,0.0028882,0.0029199,0.0029515,0.0029831,0.0030145,0.0030459,0.0030771,0.0031082,0.0031392,0.00317,0.0032007,0.0032312,0.0032615,0.0032917,0.0033218,0.0033516,0.0033813,0.0034107,0.00344,0.003469,0.0034979,0.0035265,0.0035548,0.003583,0.0036108,0.0036385,0.0036659,0.003693,0.0037198,0.0037464,0.0037726,0.0037986,0.0038243,0.0038497,0.0038748,0.0038995,0.0039239,0.003948,0.0039718,0.0039952,0.0040183,0.004041,0.0040633,0.0040853,0.0041069,0.0041282,0.004149,0.0041695,0.0041896,0.0042093,0.0042285,0.0042474,0.0042659,0.0042839,0.0043015,0.0043187,0.0043354,0.0043518,0.0043676,0.0043831,0.0043981,0.0044126,0.0044267,0.0044403,0.0044534,0.0044661,0.0044783,0.0044901,0.0045013,0.0045121,0.0045224,0.0045322,0.0045416,0.0045504,0.0045588,0.0045666,0.004574,0.0045808,0.0045872,0.004593,0.0045984,0.0046032,0.0046076,0.0046114,0.0046147,0.0046175,0.0046198,0.0046216,0.0046229,0.0046237,0.0046239,0.0046237,0.0046229,0.0046216,0.0046198,0.0046175,0.0046147,0.0046114,0.0046076,0.0046032,0.0045984,0.004593,0.0045872,0.0045808,0.004574,0.0045666,0.0045588,0.0045504,0.0045416,0.0045322,0.0045224,0.0045121,0.0045013,0.0044901,0.0044783,0.0044661,0.0044534,0.0044403,0.0044267,0.0044126,0.0043981,0.0043831,0.0043676,0.0043518,0.0043354,0.0043187,0.0043015,0.0042839,0.0042659,0.0042474,0.0042285,0.0042093,0.0041896,0.0041695,0.004149,0.0041282,0.0041069,0.0040853,0.0040633,0.004041,0.0040183,0.0039952,0.0039718,0.003948,0.0039239,0.0038995,0.0038748,0.0038497,0.0038243,0.0037986,0.0037726,0.0037464,0.0037198,0.003693,0.0036659,0.0036385,0.0036108,0.003583,0.0035548,0.0035265,0.0034979,0.003469,0.00344,0.0034107,0.0033813,0.0033516,0.0033218,0.0032917,0.0032615,0.0032312,0.0032007,0.00317,0.0031392,0.0031082,0.0030771,0.0030459,0.0030145,0.0029831,0.0029515,0.0029199,0.0028882,0.0028564,0.0028245,0.0027925,0.0027605,0.0027285,0.0026964,0.0026642,0.0026321,0.0025999,0.0025677,0.0025354,0.0025032,0.002471,0.0024388,0.0024066,0.0023745,0.0023423,0.0023102,0.0022782,0.0022462,0.0022143,0.0021824,0.0021506,0.0021189,0.0020873,0.0020557,0.0020243,0.0019929,0.0019617,0.0019306,0.0018996,0.0018687,0.001838,0.0018074,0.001777,0.0017467,0.0017165,0.0016865,0.0016567,0.0016271,0.0015976,0.0015683,0.0015392,0.0015103,0.0014815,0.001453,0.0014247,0.0013966,0.0013687,0.0013411,0.0013136,0.0012864,0.0012594,0.0012326,0.0012061,0.0011798,0.0011538,0.001128,0.0011025,0.0010772,0.0010522,0.0010275,0.001003,0.00097875,0.0009548,0.00093112,0.00090772,0.0008846,0.00086176,0.00083921,0.00081693,0.00079495,0.00077325,0.00075185,0.00073073,0.00070991,0.00068939,0.00066916,0.00064924,0.00062961,0.00061028,0.00059125,0.00057253,0.0005541,0.00053598,0.00051817,0.00050066,0.00048346,0.00046656,0.00044996,0.00043367};
float inputBuffer[NUM_COEFFICIENTS];
int inputIndex = 0;

const int adcPin = 13; //ADC pin being used
float adcValue = 0.0; //variable to store ADC value
float prevWeight = 0.0; //variable to store previously recorded weight
float rawWeight = 0.0; //varaible to store raw weight, prior to zeroing
float weight = 0.0; //variable to store weight, subject to zeroing
float average = 0.0; //average ADC value after moving average filter applied
const float stabilityThreshold = 0.03; //percentage of variation allowed for input to be considered stabilised
const int bufferSize = 2000; //number of stabilised readings required for input to be considered stabilised
float buffer[bufferSize];
int bufferIndex = 0;
float offset = 0.0; //offset value introduced via zeroing

// Function to apply the Kaiser Window Filter
float kaiser_filter(float input) {
  // Add new input data to the buffer
  inputBuffer[inputIndex] = input;

  // Compute filtered output
  float output = 0;
  for (int i = 0; i < NUM_COEFFICIENTS; i++) {
    int index = (inputIndex + i) % NUM_COEFFICIENTS;
    output += coefficients[i] * inputBuffer[index];
  }

  // Update input buffer index
  inputIndex = (inputIndex + 1) % NUM_COEFFICIENTS;

  return output;
}

//function to determine whether inputs have stabilised and apply moving average filter
bool checkStability() {
    for (int i = 1; i < bufferSize; i++) {
        average = average + buffer[i]; //calculate total sum of inputs
        if (fabs(buffer[i] - buffer[i - 1]) >= stabilityThreshold * buffer[i - 1]) { 
            average = 0;                                                             
            return false; // Not stable                                                               
        }
    }
    average = average/bufferSize; //calculate average of all inputs
    return true; // Stable
}


void setup() {
  // Initialize input buffer for kaiser window
  for (int i = 0; i < NUM_COEFFICIENTS; i++) {
    inputBuffer[i] = 0;
  }

  Serial.begin(115200);
  delay(1000);
}

void loop() {
    adcValue = analogRead(adcPin);
    float filteredOutput = kaiser_filter(adcValue);
    
    // Update buffer to pass through checkStability
    buffer[bufferIndex] = filteredOutput;
    bufferIndex = (bufferIndex + 1) % bufferSize;
    
    //output average value of buffer if stability conditions are met
    if (bufferIndex == 0 && checkStability()) {
      rawWeight = 0.07405*average - 45.7; //linearising equation to convert ADC value to grams
      weight = rawWeight - offset; //apply offset introduced from zeroing

      //print variable (or send to server) if it differs from the previous reading
      if (fabs(weight - prevWeight) >= 0.1){
        Serial.println(weight, 1); 
        prevWeight = weight;
      }
    }
    
    //read zero command
    static char inputBuffer[10]; // Buffer to store incoming characters
    static int index = 0; // Index for the buffer
  
    // Check if there's data available to read from the serial monitor
    if (Serial.available() > 0) {
      // Read the incoming byte
      char input = Serial.read();
  
      // Check if the input is not a newline character
      if (input != '\n') {
        // Store the character in the buffer
        inputBuffer[index++] = input;
  
        // Check if the buffer is full
        if (index >= sizeof(inputBuffer)) {
          // Clear the buffer and reset the index
          memset(inputBuffer, 0, sizeof(inputBuffer));
          index = 0;
          Serial.println("Buffer overflow. Please enter 'zero' again.");
        }
      } else {
        // Null-terminate the buffer
        inputBuffer[index] = '\0';
  
        // Check if the input is 'zero'
        if (strcmp(inputBuffer, "zero") == 0) {
          Serial.println("Zeroing scale...");
          offset = rawWeight;
        } else {
          Serial.println("Invalid input. Please enter 'zero'.");
        }
  
        // Clear the buffer and reset the index
        memset(inputBuffer, 0, sizeof(inputBuffer));
        index = 0;
      }
    }
  }
}

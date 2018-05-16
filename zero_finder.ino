//move legs to actual zero position on robot, read new zero positions from serial monitor and put in leg structs


#define DXL_BUS_SERIAL1 1  //Dynamixel on Serial1(USART1)  <-OpenCM9.04
#define DXL_BUS_SERIAL2 2  //Dynamixel on Serial2(USART2)  <-LN101,BT210
#define DXL_BUS_SERIAL3 3  //Dynamixel on Serial3(USART3)  <-OpenCM 485EXP

Dynamixel Dxl(DXL_BUS_SERIAL1);

#define MOVING_SPEED 32
#define PRESENT_POS 37
#define GOAL_POSITION 30

int theta_dead = 60;
int theta_circle = 360;
int p;

float p_to_Theta(int P){
  return P * (theta_circle - theta_dead) / 1024.0 - 5.0 * (theta_circle) / 12.0; // (5 * theta circle / 12) offsets 0 to bottom
}

void setup() {
  // put your setup code here, to run once:
  Dxl.begin(3);
  /*
  Dxl.jointMode(1); //jointMode() is to use position mode
  Dxl.jointMode(2);
  Dxl.jointMode(3);
  Dxl.jointMode(4);
  Dxl.jointMode(5);
  Dxl.jointMode(6);
  */
}

void loop() {
  /*
  Dxl.writeWord(1, GOAL_POSITION, 512);
  Dxl.writeWord(2, GOAL_POSITION, 512);
  Dxl.writeWord(3, GOAL_POSITION, 512);
  Dxl.writeWord(4, GOAL_POSITION, 512);
  Dxl.writeWord(5, GOAL_POSITION, 512);
  Dxl.writeWord(6, GOAL_POSITION, 512);
  */
  for (int i = 1; i < 7; i++){  
    SerialUSB.print(i);
    SerialUSB.print(": ");
    SerialUSB.println(p_to_Theta(Dxl.readWord(i, PRESENT_POS)));
  }
  
}


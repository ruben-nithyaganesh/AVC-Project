class RobotMovement{
	public:
		void test();
		double setTurnLeft(double error,double vright);
		double setTurnRight(double error,double vleft);
		void robotStop();
	private:
		void calcTurnSpeed(double error, int turnDirection);
};
//RobotMovement::RobotMovement(){
//}

void RobotMovement::test(){
				std::cout<<"Robot movement is here"<<std::endl;
		}

double RobotMovement::setTurnLeft(double error,double vright){
				
				 return vright+error;
				//std::cout<<"vLeft = "<<wheelTurn.wheelLeft<<"vRight = "<<wheelTurn.wheelRight<<std::endl;
				//setMotors(wheelTurn.wheelLeft, wheelTurn.wheelRight);
		}
double RobotMovement::setTurnRight(double error,double vleft){
				
				  return vleft+error;
				//std::cout<<"vLeft = "<<wheelTurn.wheelLeft<<"vRight = "<<wheelTurn.wheelRight<<std::endl;
				//setMotors(wheelTurn.wheelLeft, wheelTurn.wheelRight);
		}
void RobotMovement::robotStop(){
		setMotors(0, 0);
}
/*
wheelSpeed RobotMovement::calcTurnSpeed(double error, int turnDirection){
				wheelSpeed wheelTurn;
				if(turnDirection == 0){ //0 means turning left{
						wheelTurn.wheelLeft = 0;
						wheelTurn.wheelRight = 1 * error;
				} 
				else if(turnDirection == 1){//1 means turning right{
						wheelTurn.wheelLeft = 1 * error;
						wheelTurn.wheelRight = 0;					
				
				
			}
			return wheelTurn;
		}*/

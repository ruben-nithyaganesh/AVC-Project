class RobotMovement{
	public:
		void test();
		void setTurn(double error, bool isLeft, bool isRight, bool isFront);
		void robotStop();
		void robotForward(double speed);
		void robot90Left();
		void robot90Right();
	private:
		wheelSpeed calcTurnSpeed(double error);
		wheelSpeed calcTurnSpeedWhiteless(bool isLeft, bool isRight, bool isFront);
		bool isTurn;
		
		
		double speed = 40; //max speed of each wheel
};

//Sets wheel speed
void RobotMovement::setTurn(double error, bool isLeft, bool isRight, bool isFront){
	wheelSpeed wheelTurn;
	if (error != error) {
		wheelTurn = calcTurnSpeedWhiteless(isLeft, isRight, isFront);
	} else {
		wheelTurn = calcTurnSpeed(error);
	}				//Get speeds for each wheel, pass values into wheelTurn struct
	std::cout<<"vLeft = "<<wheelTurn.wheelLeft<<" vRight = "<<wheelTurn.wheelRight<<std::endl;
	setMotors(wheelTurn.wheelLeft, wheelTurn.wheelRight); 	//Set speed for each wheel
}


//Stops the robot
void RobotMovement::robotStop(){ 
	setMotors(0, 0);
}

//Calculates speed of each wheel depending on error value
wheelSpeed RobotMovement::calcTurnSpeed(double error){ 
	wheelSpeed wheelTurn;
	if(error > 0){          // >0 means needs to turn right
		wheelTurn.wheelRight = speed  ;
		wheelTurn.wheelLeft = speed - (error*(0.2*(0.1*speed)));
	} 
	else if(error < 0){  // <0 means needs to turn left
		wheelTurn.wheelRight = speed + (error*(0.2*(0.1*speed)));
		wheelTurn.wheelLeft= speed;					
	}
				
	else if(error != 0){ //If there are no white pixels, turn on the spot
		wheelTurn.wheelRight = speed;
		wheelTurn.wheelLeft= 0;						  
	}
				
	else {
		wheelTurn.wheelRight = speed;
		wheelTurn.wheelLeft= speed;						   
	}

	return wheelTurn;
}

wheelSpeed RobotMovement::calcTurnSpeedWhiteless(bool isLeft, bool isRight, bool isFront) {
	wheelSpeed wheelTurn;
	if (isFront) {
		if (isLeft) {
			wheelTurn.wheelRight = -6.0;
			wheelTurn.wheelLeft = 6.0;
		} else if (isRight) {
			wheelTurn.wheelRight = 6.0;
			wheelTurn.wheelLeft = -6.0;
		} else if (isTurn){
			wheelTurn.wheelRight = -6.0;
			wheelTurn.wheelLeft = 6.0;
		} else {
			wheelTurn.wheelRight = 6.0;
			wheelTurn.wheelLeft = -6.0;
		}
	} else {
		wheelTurn.wheelRight = speed;
		wheelTurn.wheelLeft = speed;
	}
	
	return wheelTurn;
}

void RobotMovement::robot90Left() {
	setMotors(90, -90);
}

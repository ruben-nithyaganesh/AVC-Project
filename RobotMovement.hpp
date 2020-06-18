class RobotMovement{
	public:
		RobotMovement(int num);
		void test();
		void setTurn(double error, redPaths redPath1);
		void robotStop();
		void robotForward(double speed);
	private:
		wheelSpeed calcTurnSpeed(double error);
		wheelSpeed calcTurnSpeedWhiteless(redPaths redPath1);
		bool isTurn;
		bool isChallenge;
		
		double speed = 40; //max speed of each wheel
};

RobotMovement::RobotMovement(int num){
		isChallenge = (num == 0);
}

//Sets wheel speed
void RobotMovement::setTurn(double error, redPaths redPath1){
	wheelSpeed wheelTurn;
	if (error != error && isChallenge) {
		wheelTurn = calcTurnSpeedWhiteless(redPath1);
	} 
	else{
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
	return wheelTurn;
}

wheelSpeed RobotMovement::calcTurnSpeedWhiteless(redPaths redPaths1) {
	wheelSpeed wheelTurn;
	if (redPaths1.front) { //If there is red in front of robot, look to turn left or right
		if (redPaths1.left) {
			wheelTurn.wheelRight = -6.0;
			wheelTurn.wheelLeft = 6.0;
		} 
		else if (redPaths1.right) {
			wheelTurn.wheelRight = 6.0;
			wheelTurn.wheelLeft = -6.0;
		}
		else{
			wheelTurn.wheelRight = -6.0;
			wheelTurn.wheelLeft = 6.0;
		} 
	} 
	else{
		wheelTurn.wheelRight = speed;
		wheelTurn.wheelLeft = speed;
	}	
	return wheelTurn;
}

 

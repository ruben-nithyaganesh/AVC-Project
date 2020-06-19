class RobotMovement{
	public:
		RobotMovement(int num);
		void test();
		void setTurn(double error, Paths whitePaths,Paths redPaths);
		void robotStop();
		void robotForward(double speed);
	private:
		wheelSpeed calcTurnSpeed(double error, Paths whitePaths);
		wheelSpeed calcTurnSpeedRed(Paths redPaths);
		bool isTurn;
		bool isChallenge;
		
		double speed = 20; //max speed of each wheel
};

RobotMovement::RobotMovement(int num){
		isChallenge = (num == 0);
}

//Sets wheel speed
void RobotMovement::setTurn(double error, Paths whitePaths, Paths redPaths){
	wheelSpeed wheelTurn;
	if (error != error && isChallenge) { //If there are no white pixels and the maze is set to challenge, run code for navigating the challenge maze
		wheelTurn = calcTurnSpeedRed(redPaths);
	} 
	else{
		wheelTurn = calcTurnSpeed(error, whitePaths); //If the maze is not set to challenge, run calcTurnSpeed as normal, getting speeds for each wheel, pass values into wheelTurn struct
	}
	std::cout<<"vLeft = "<<wheelTurn.wheelLeft<<" vRight = "<<wheelTurn.wheelRight<<std::endl;
	setMotors(wheelTurn.wheelLeft, wheelTurn.wheelRight); 	//Set speed for each wheel
}


//Stops the robot
void RobotMovement::robotStop(){ 
	setMotors(0, 0);
}

//Calculates speed of each wheel depending on error value
wheelSpeed RobotMovement::calcTurnSpeed(double error, 	Paths whitePaths){ 
	wheelSpeed wheelTurn;
	if(whitePaths.left){
		error = 37;
	}		
	if(error > 0){          // >0 means needs to turn right
		wheelTurn.wheelRight = speed  ;
		wheelTurn.wheelLeft = speed - (error*(0.02*speed)); //speed of wheel is reduced by an amount depending on error and max speed
	} 
	else if(error < 0){  // <0 means needs to turn left
		wheelTurn.wheelRight = speed + (error*(0.02*speed));
		wheelTurn.wheelLeft= speed;					
	}
				
	else if(error != 0){ //If there are no white pixels, turn on the spot
		wheelTurn.wheelRight = speed;
		wheelTurn.wheelLeft= 0;						  
	}
	return wheelTurn;
}

wheelSpeed RobotMovement::calcTurnSpeedRed(Paths redPaths) {
	wheelSpeed wheelTurn;
	if (redPaths.front) { //If there is red in front of robot, look to turn left or right
		if (redPaths.left) { 	//If there is red to the left of the robot, turn to the right
			wheelTurn.wheelRight = -6.0;
			wheelTurn.wheelLeft = 6.0;
		} 
		else if (redPaths.right) { //If there is red to the right of the robot, turn to the left
			wheelTurn.wheelRight = 6.0;
			wheelTurn.wheelLeft = -6.0;
		}
		else{
			wheelTurn.wheelRight = -6.0; //If there is no red to either side of the robot, turn to the right
			wheelTurn.wheelLeft = 6.0;
		}
	} 
	else{ //If there is no red in front of the robot, go forward
		wheelTurn.wheelRight = speed;
		wheelTurn.wheelLeft = speed;
	}	
	return wheelTurn;
}

 

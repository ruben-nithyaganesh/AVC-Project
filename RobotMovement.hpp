class RobotMovement{
	public:
		void test();
		void setTurn(double error);
		void robotStop();
		void robotForward(double speed);
	private:
		wheelSpeed calcTurnSpeed(double error);
		
		double speed = 20; //max speed of each wheel
};

//Sets wheel speed
void RobotMovement::setTurn(double error){
				
	wheelSpeed wheelTurn = calcTurnSpeed(error);				//Get speeds for each wheel, pass values into wheelTurn struct
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
				
			  else{
						wheelTurn.wheelRight = speed;
						wheelTurn.wheelLeft= speed;						   
			   }

			return wheelTurn;
}


class RobotMovement{
	public:
		void setTurn(errors error);
		void robotStop();
	private:
		wheelSpeed calcTurnSpeed(errors error);
		double speed = 20; //max speed of each wheel
};

//Sets wheel speed
void RobotMovement::setTurn(errors error){
				
	wheelSpeed wheelTurn = calcTurnSpeed(error);				//Get speeds for each wheel, pass values into wheelTurn struct
	std::cout<<"vLeft = "<<wheelTurn.wheelLeft<<" vRight = "<<wheelTurn.wheelRight<<std::endl;
	setMotors(wheelTurn.wheelLeft, wheelTurn.wheelRight); 	//Set speed for each wheel
}


//Stops the robot
void RobotMovement::robotStop(){ 
		setMotors(0, 0);
}

//Calculates speed of each wheel depending on error value
wheelSpeed RobotMovement::calcTurnSpeed(errors error){ 
				wheelSpeed wheelTurn;
				errors error1 = error;
				
				if(error1.error > 0){          // >0 means needs to turn right
						wheelTurn.wheelRight = speed  ;
						wheelTurn.wheelLeft = speed - (error1.error*(0.02*speed));
				} 
			   else if(error1.error < 0){  // <0 means needs to turn left
						wheelTurn.wheelRight = speed + (error1.error*(0.02*speed));
						wheelTurn.wheelLeft= speed;					
				}
				
			  else if(error1.error != 0){ //If there are no white pixels, try to guide with red pixels
					if(error1.redError > 0){
							wheelTurn.wheelRight = speed;
							wheelTurn.wheelLeft = speed - (error1.redError*(0.02*speed));
					}
					else if(error1.redError < 0){
						wheelTurn.wheelRight = speed + (error1.redError*(0.02*speed));
						wheelTurn.wheelLeft= speed;							
					}
				    else if(error1.redError != 0){ //if no red or white, turn around
						wheelTurn.wheelRight = speed;
						wheelTurn.wheelLeft= 0;	
						
					}
					  
			  }
				
			  else{
						wheelTurn.wheelRight = speed;
						wheelTurn.wheelLeft = speed;						   
			   }

			return wheelTurn;
}


#include "robot.hpp"
#include "robotMovement.hpp"
#include "imageProcessor.hpp"


int main(){
	if (initClientRobot() !=0){
		std::cout<<" Error initializing robot"<<std::endl;
	}
	
	int i;
	//get the first line from config.txt in AVC_server, and look to see if the maze is set to challenge
	if(returnMazeType() == "mazeFile,challenge.txt"){
			i = 0;
	}
	else{
			i = 1;
	}
	//make instances of ImageProcessor and RobotMovement
	ImageProcessor image;
	RobotMovement robot(i); //i is passed in, representing whether or not the maze is set to challenge
	
    takePicture();
    SavePPMFile("i0.ppm",cameraView);
  
    while(1){
	//program loops forever, taking a picture, then calling setTurn in RobotMovement, passing in error and path values calculated with ImageProcessor
	  takePicture();
	  robot.setTurn(image.processor(cameraView), image.getWhitePaths(cameraView), image.getRedPaths(cameraView));     
      usleep(10000);
      
	} //while

} // main

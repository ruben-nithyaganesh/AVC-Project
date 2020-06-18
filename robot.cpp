#include "robot.hpp"
#include "robotMovement.hpp"
#include "imageProcessor.hpp"


int main(){
	if (initClientRobot() !=0){
		std::cout<<" Error initializing robot"<<std::endl;
				
	}
	
	std::string str = "";
	str = returnMazeType();
	std::cout<<"File: "<<str<<std::endl;
	int i;
	if(returnMazeType() == "mazeFile,challenge.txt"){
			i = 0;
	}
	else{
			i = 1;
	}
	ImageProcessor image;
	RobotMovement robot(i);
	
    takePicture();
    SavePPMFile("i0.ppm",cameraView);
  
    while(1){
	  takePicture();
	  robot.setTurn(image.processor(cameraView), image.getRedPaths(cameraView));     
      usleep(10000);
      
	} //while

} // main

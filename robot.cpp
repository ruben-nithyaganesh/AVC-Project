
#include "robot.hpp"
#include "robotMovement.hpp"
#include "imageProcessor.hpp"



int main(){
	if (initClientRobot() !=0){
		std::cout<<" Error initializing robot"<<std::endl;			
	}
	ImageProcessor image;
	RobotMovement robot;
	
    takePicture();
    SavePPMFile("i0.ppm",cameraView);
  
    while(1){
	  takePicture();
	  robot.setTurn(image.processor(cameraView));     
      usleep(10000);
      
	} //while

} // main

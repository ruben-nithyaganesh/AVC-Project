
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
	  std::cout<<"Red on left is: "<<image.returnLeftRed(cameraView)<<std::endl;
	  std::cout<<"Red on right is: "<<image.returnRightRed(cameraView)<<std::endl;
	  std::cout<<"Red on front is: "<<image.returnFrontRed(cameraView)<<std::endl;
	  robot.setTurn(image.processor(cameraView), image.returnLeftRed(cameraView), image.returnRightRed(cameraView), image.returnFrontRed(cameraView));     
      usleep(10000);
      
	} //while

} // main


#include "robot.hpp"
#include "imageProcessing.hpp"
#include <iostream>
#include "RobotMovement.hpp"
using namespace std;
	
int main(){
	if (initClientRobot() !=0){
		std::cout<<" Error initializing robot"<<std::endl;
}
    double vLeft = 50.0;
    double vRight = 50.0;
    takePicture();
    SavePPMFile("i0.ppm",cameraView);
    int h;
    while(1){
		double newVRigh=0,newVLeft=0;
		takePicture();
		imageProcessor a;
		RobotMovement turn;
		a.prossessor(cameraView);
		int error=a.error;
		std::cout<<"1 error ="<<a.error<<std::endl;
		if(error<0){
			turn.test();
			newVLeft=turn.setTurnRight(a.error*-1,vLeft);
			setMotors(newVLeft,vRight);
			setMotors(vLeft,vRight);
			std::cout<<" newVLeft="<<newVLeft<<"   vRight="<<vRight<<std::endl;
		}
		else if(error>0){
			newVRigh=turn.setTurnLeft(a.error,vRight);
			setMotors(vLeft,newVRigh);
			setMotors(vLeft,vRight);
			std::cout<<" vLeft="<<vLeft<<"   newVRigh"<<newVRigh<<std::endl;
		}
		else{
		setMotors(vLeft,vLeft);
		std::cout<<" vLeft="<<0<<"   vRight"<<0<<std::endl;
		
	    }
		
		//std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;
		usleep(10000);
  } 
   //while

} // main

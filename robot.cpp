#include "robot.hpp"
#include "imageProcessing.hpp"
#include "robotMovement.hpp"
#include <iostream>

using namespace std;
	
int main(){
	if (initClientRobot() !=0){
		std::cout<<" Error initializing robot"<<std::endl;
}
	double vInput;
    std::cout<<"Please enter a starting speed"<<std::endl;
    std::cin>>vInput;
    double vLeft = vInput;
    double vRight = vInput;
    takePicture();
    SavePPMFile("i0.ppm",cameraView);
    int h;
    while(1){
		takePicture();
		imageProcessor a;
		a.prossessor(cameraView, vLeft, vRight);
		setMotors(vLeft,vRight);
		std::cout<<"error equals: "<<a.error<<std::endl;
		robotMovement m;
		m.turnSet(a.error, vLeft, vRight);
		
		//setMotors(vLeft,vRight);
		//std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;
		usleep(10000);
		a.store1=0;
  } 
   //while

} // main

#include <iostream>

class imageProcessor{
	
	public:
	void prossessor(ImagePPM cameraview);
	void printvalues();
	imageProcessor();
	int store1;	
	int error;
};
imageProcessor::imageProcessor(){
	store1=0;	
	error=0;
		
}
void imageProcessor::prossessor(ImagePPM cameraview){
	
	for(int i=1;i<=150;i++){
		int pix=get_pixel(cameraview,50,i,1);
		if (store1==0){
			if(pix>250){
			store1=i;}		
		}
			
	}
	
 error=75-store1;
}

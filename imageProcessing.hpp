#include <iostream>

class imageProcessor{
	
	public:
	void prossessor(ImagePPM cameraview, int lMult, int rMult);
	void printvalues();
	imageProcessor();
	int store1;	
	int error;
	
	private:
	int safetyRow;
};
imageProcessor::imageProcessor(){
	store1=0;	
	error=0;
		
}
void imageProcessor::prossessor(ImagePPM cameraview, int lMult, int rMult){
	
	safetyRow = (lMult + rMult) / 2.0;
	for(int i=1;i<=150;i++){
		int pix=get_pixel(cameraview,100 - safetyRow,i,1);
		if (store1==0){
			if(pix>250){
			store1=i;}		
		}
			
	}
	if (store1 != 0){
		error=75-store1;
	} else {
		error = 0;
	}
}

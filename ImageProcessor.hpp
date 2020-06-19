class ImageProcessor{	
	public:
		double processor(ImagePPM cameraview);
		double getWhiteMidPoint(ImagePPM cameraview);
		bool detectColor(ImagePPM cameraView, double rowStart, double rowEnd, double colStart, double colEnd, int color);
		Paths getWhitePaths(ImagePPM cameraview);
		Paths getRedPaths(ImagePPM cameraview);
};

//Calculate and return error value (how far middle white pixel is from centre)
double ImageProcessor::processor(ImagePPM cameraview){
	double error = 75 - getWhiteMidPoint(cameraView);
	std::cout<<"error: "<<error<<std::endl;
	return error;
}

//Collects position of all white pixels in line, then finds the middle white pixel
double ImageProcessor::getWhiteMidPoint(ImagePPM cameraview){ 
	double totalWhite = 0;
	double whiteCount = 0;
	for(int i = 0; i < 150; i++){
		if(get_pixel(cameraview, 99, i, 3) > 250){ //loop scans the last row of the robot FOV, this is the row closest to the robot
			totalWhite = totalWhite + i;				
			whiteCount += 1;
		}
	}
		
	return totalWhite / whiteCount; //returns the middle index of all white pixels in the row
}	

//Detects if any color pixels are present in the PPM image from the specified rowStart and End, and columnStart and End
bool ImageProcessor::detectColor(ImagePPM cameraView, double rowStart, double rowEnd, double colStart, double colEnd, int color) {
	for (int i = rowStart; i < rowEnd; i++) {
		for (int x = colStart; x < colEnd; x++) {
			if (get_pixel(cameraView, i, x, color) > 250) {
				return true;
			}
		}
	}
	return false;
}

//Determines if white is present on the front, left and right of the robot FOV
Paths ImageProcessor::getWhitePaths(ImagePPM cameraview){
	Paths whitePaths;	
	whitePaths.left   = detectColor(cameraView, 98, 99, 0, 49, 3);
	whitePaths.front = detectColor(cameraView, 96, 97, 50, 99, 3);
	whitePaths.right = detectColor(cameraView, 98, 99, 100, 149, 3);
	//std::cout<<"White on left is: "<<whitePaths.left<<std::endl;
	//std::cout<<"White on right is: "<<whitePaths.right<<std::endl;
	//std::cout<<"White on front is: "<<whitePaths.front<<std::endl;
	return whitePaths;
}

//Determines if red is present on the front, left and right sides of the robot FOV
Paths ImageProcessor::getRedPaths(ImagePPM cameraview){
	Paths redPaths;
	redPaths.left = detectColor(cameraView, 69, 99, 0, 19, 0);
	redPaths.front = detectColor(cameraView, 59, 99, 19, 129, 0);	
	redPaths.right = detectColor(cameraView, 69, 99, 129, 149, 0);
	//std::cout<<"Red on left is: "<<redPaths.left<<std::endl;
	//std::cout<<"Red on right is: "<<redPaths.right<<std::endl;
	//std::cout<<"Red on front is: "<<redPaths.front<<std::endl;
	return redPaths;
}

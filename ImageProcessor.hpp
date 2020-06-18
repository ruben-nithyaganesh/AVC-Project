class ImageProcessor{	
	public:
		double processor(ImagePPM cameraview);
		double getWhiteMidPoint(ImagePPM cameraview);
		bool detectRed(ImagePPM cameraView, double rowStart, double rowEnd, double colStart, double colEnd);
		redPaths getRedPaths(ImagePPM cameraview);
	
	private:
		float red;
		float green;
		float redGreenTest;
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
		if(get_pixel(cameraview, 99, i, 3) > 250){
			totalWhite = totalWhite + i;
			whiteCount += 1;
		}
	}
		
	return totalWhite / whiteCount;
}	

//Detects if any red pixels are present in the PPM image from the specified rowStart and End, and columnStart and End
bool ImageProcessor::detectRed(ImagePPM cameraView, double rowStart, double rowEnd, double colStart, double colEnd) {
	double r;
	for (int i = rowStart; i < rowEnd; i++) {
		for (int x = colStart; x < colEnd; x++) {
			r= get_pixel(cameraView, i, x, 0);
			if (r > 250) {
				return true;
			}
		}
	}
	return false;
}

//Determines if red is present on the front, left and right sides of the robot FOV
redPaths ImageProcessor::getRedPaths(ImagePPM cameraview){
	redPaths redPath1;
	redPath1.front = detectRed(cameraView, 59, 99, 19, 129);
	redPath1.left = detectRed(cameraView, 69, 99, 0, 19);
	redPath1.right = detectRed(cameraView, 69, 99, 129, 149);
	std::cout<<"Red on left is: "<<redPath1.left<<std::endl;
	std::cout<<"Red on right is: "<<redPath1.right<<std::endl;
	std::cout<<"Red on front is: "<<redPath1.front<<std::endl;
	return redPath1;
}

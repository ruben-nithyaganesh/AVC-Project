class ImageProcessor{	
	public:
		double processor(ImagePPM cameraview);
		double getWhiteMidPoint(ImagePPM cameraview);
		bool returnLeftRed(ImagePPM cameraView);
		bool returnRightRed(ImagePPM cameraView);
		bool returnFrontRed(ImagePPM cameraView);
	
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

//Collects the red and green values for the 10th, to the 90th pixel on the left side of cameraView, and returns if a red pixel is present
bool ImageProcessor::returnLeftRed(ImagePPM cameraView) {
	float redVSGreen = 0.0f;
	for (int i = 0; i < 99; i++) {
		for (int x = 0; x < 29; x++) {
			red = (float)get_pixel(cameraView, i, x, 0);
			green = (float)get_pixel(cameraView, i, x, 1);
			redGreenTest = red / green;
			if (redGreenTest > redVSGreen) {
				redVSGreen = redGreenTest;
			}
		}
	}

	if (redVSGreen > 1.8) {
		return true;
	} else {
		return false;
	}
}

//Acts the same 
bool ImageProcessor::returnRightRed(ImagePPM cameraView) {
	float redVSGreen = 0.0f;
	for (int i = 0; i < 99; i++) {
		for (int x = 129; x < 149; x++) {
			red = (float)get_pixel(cameraView, i, x, 0);
			green = (float)get_pixel(cameraView, i, x, 1);
			redGreenTest = red / green;
			if (redGreenTest > redVSGreen) {
				redVSGreen = redGreenTest;
			}
		}
	}

	if (redVSGreen > 1.8) {
		return true;
	} else {
		return false;
	}
}

bool ImageProcessor::returnFrontRed(ImagePPM cameraView) {
	float redVSGreen = 0.0f;
	for (int i = 54; i < 55; i++) {
		for (int x = 24; x < 124; x++) {
			red = (float)get_pixel(cameraView, i, x, 0);
			green = (float)get_pixel(cameraView, i, x, 1);
			redGreenTest = red / green;
			if (redGreenTest > redVSGreen) {
				redVSGreen = redGreenTest;
			}
		}
	}

	if (redVSGreen > 1.8) {
		return true;
	} else {
		return false;
	}
}

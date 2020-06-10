class ImageProcessor{	
	public:
	double processor(ImagePPM cameraview);
	double getWhiteMidPoint(ImagePPM cameraview);	
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



class ImageProcessor{	
	public:
	double processor(ImagePPM cameraview);
	pathInfo getPathInfo(ImagePPM cameraview);	
	path returnPaths(int i, path paths,  ImagePPM cameraview);
};

//Calculate and return error value (how far middle white pixel is from centre)
double ImageProcessor::processor(ImagePPM cameraview){
	pathInfo pathInfo1 = getPathInfo(cameraView);
	
	double error = 75 - pathInfo1.error;
	if(pathInfo1.posPaths.left){
			error = 74;
	}
	else if(pathInfo1.posPaths.forward){
			error = 0;
	}
	else if(pathInfo1.posPaths.right){
			error = -74;
	}
	std::cout<<"computed error: "<<error<<std::endl;
	std::cout<<"error: "<<pathInfo1.error<<std::endl;
	return error;
}

//Collects position of all white pixels in line, then finds the middle white pixel
pathInfo ImageProcessor::getPathInfo(ImagePPM cameraview){ 
		pathInfo pathInfo1;
		
		path paths;
		paths.left = false;
		paths.right = false;		
		paths.forward = false;
		
		double totalWhite = 0;
		double whiteCount = 0;
		
		for(int i = 0; i < 150; i++){
			if(get_pixel(cameraview, 99, i, 3) > 250){
				totalWhite = totalWhite + i;
				whiteCount += 1;
				

				paths = returnPaths(i, paths, cameraview);								
		}
	}	
		pathInfo1.error =  totalWhite / whiteCount;
		pathInfo1.posPaths = paths;
		return pathInfo1;
}

//returns a path data struct. Returns true for left, right and forward if the current white pixel is on the left right or front of robot
path ImageProcessor::returnPaths(int i, path paths, ImagePPM cameraview){
		path path1 = paths;
		if(i <= 73){
			path1.left = true;
		}
	    if(i >= 77){
			path1.right = true;
		}
		if(i >= 74 && i <= 76 && (get_pixel(cameraview, 50, i, 3) > 250)){
				path1.forward = true;
		}
		return path1;
}

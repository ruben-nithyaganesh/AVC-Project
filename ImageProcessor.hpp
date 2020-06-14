class ImageProcessor{	
	public:
		errors processor(ImagePPM cameraview);
		pathInfo getPathInfo(ImagePPM cameraview);	
		double returnWhiteMidPoint(ImagePPM cameraview);
		double returnRedMidPoint(ImagePPM cameraview);
		path returnPaths(ImagePPM cameraview);	
		path returnRedPaths(ImagePPM cameraview);


};

//Calculate and return error value (how far middle white pixel is from centre)
errors ImageProcessor::processor(ImagePPM cameraview){
	errors error1;
	pathInfo pathInfo1 = getPathInfo(cameraView);
	
	error1.error = 75 - pathInfo1.midpoint;
	error1.redError = 20 - pathInfo1.redMidPoint;
	/*if(pathInfo1.posPaths.left){
			error1.error = 74;
	}
	else if(pathInfo1.posPaths.forward){
			error1.error = 0;
	}
	else if(pathInfo1.posPaths.right){
			error1.error = -74;
	} */
	std::cout<<"error: "<<error1.error<<std::endl;
	std::cout<<"redError: "<<error1.redError<<std::endl;
	return error1;
}

//Collects position of all white pixels in line, then finds the middle white pixel
pathInfo ImageProcessor::getPathInfo(ImagePPM cameraview){ 
		pathInfo pathInfo1;
		
	//	path paths;
		//paths.left, paths.right, paths.forward = false;
		
		//double totalWhite = 0;
		//double whiteCount = 0;
		
		//for(int i = 0; i < 150; i++){
			//if(get_pixel(cameraview, 99, i, 3) > 250){
				//totalWhite = totalWhite + i;
				//whiteCount += 1;
				

				//paths = returnPaths(i, paths, cameraview);								
			//}
	   // }	
		pathInfo1.midpoint =  returnWhiteMidPoint(cameraview);
		pathInfo1.posPaths = returnPaths(cameraview);
		pathInfo1.redMidPoint = returnRedMidPoint(cameraview);
		pathInfo1.redPaths = returnRedPaths(cameraview);
		
		return pathInfo1;
}

double ImageProcessor::returnWhiteMidPoint(ImagePPM cameraview){
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

//returns midpoint of red pixels in image
double ImageProcessor::returnRedMidPoint(ImagePPM cameraview){
		double totalRed = 0;
		double redCount = 0;
		for(int i = 0; i < 75 ; i++){
			if(get_pixel(cameraview, 99, i, 0) > 250){
				totalRed = totalRed + i;
				redCount += 1;							
		}
	}
	return totalRed / redCount;		
}

/*returns a path data struct. Returns true for left, right and forward if the current white pixel is on the left right or front of robot
path ImageProcessor::returnPaths1(int i, path paths, ImagePPM cameraview){
		path path1 = paths;
		if(i <= 20){
			path1.left = true;
		}
	    if(i >= 130){
			path1.right = true;
		}
		if(i >= 74 && i <= 76 && (get_pixel(cameraview, 50, i, 3) > 250)){
				path1.forward = true;
		}
		return path1;
} */

//ignore
path ImageProcessor::returnPaths(ImagePPM cameraview){ 
	path path1;
	path1.forward, path1.left, path1.right = false;
	for(int i = 0; i < 150; i++){
		if(get_pixel(cameraview, 0, i, 3) > 250){
			
			if(i <= 20){
				path1.left = true;
			}
			if(i >= 130){
				path1.right = true;
			}
			if(i >= 74 && i <= 76 && (get_pixel(cameraview, 50, i, 3) > 250)){
				path1.forward = true;
			}

		}

		
	}
	return path1;
}

//ignore
path ImageProcessor::returnRedPaths(ImagePPM cameraview){ 
	path redPaths;
	redPaths.forward, redPaths.left, redPaths.right = true;
	for(int i = 0; i < 50; i++){
		//ichecks if there is a red wall on the left side of camera
		if(get_pixel(cameraview, i, 0, 0) > 250){
				redPaths.left = false;
		}
		if(get_pixel(cameraview, i, 149, 0) > 250){
				redPaths.right = false;
		}
		if(get_pixel(cameraview, 50, 49+i, 0) > 250){
				redPaths.forward = false;
		}
		
	}
	return redPaths;
}

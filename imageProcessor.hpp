using namespace std;



class imageProcessor {
	private:
		int error, store;
		Pixel curPix;
	public:
		int isWhite(ImagePPM cameraInput);
	
};

int imageProcessor::isWhite(ImagePPM cameraInput) {
	for (int i = 0; i < 150; i++) {
		curPix = get_pixel(cameraInput, 80, i);
		
		if (store == 0) {
			if ((curPix.red > 240) && (curPix.green > 240) && (curPix.blue > 240)) {
				store = i;
				cout<<"store = "<<i<<endl;
			}
		}
	}
	
	error = 74 - store;
	cout<<"error = "<<error<endl;
	
	return error;
}

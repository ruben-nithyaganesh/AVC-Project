#include <iostream>

class robotMovement{
	public:
		void turnSet(int val, int left, int right);
	private:
		double offset;
};

void robotMovement::turnSet(int val, int left, int right) {
	offset = ((left + right) / 200.0) * val;
	setMotors(left - offset, right + offset);
	
}


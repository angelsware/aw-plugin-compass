#include <compass/aw_sensorfactory.h>
#include "aw_sensor_ios.h"

namespace Compass {
	ISensor* CSensorFactory::create() {
		return new CSensor_Ios();
	}

	void CSensorFactory::destroy(ISensor* sensor) {
		delete sensor;
	}
}

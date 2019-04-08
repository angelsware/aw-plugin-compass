#include <compass/aw_sensorfactory.h>
#include "aw_sensor_android.h"

namespace Compass {
	ISensor* CSensorFactory::create() {
		return new CSensor_Android();
	}

	void CSensorFactory::destroy(ISensor* sensor) {
		delete sensor;
	}
}

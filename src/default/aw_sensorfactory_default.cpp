#include <compass/aw_sensorfactory.h>
#include "aw_sensor_default.h"

namespace Compass {
	ISensor* CSensorFactory::create() {
		return new CSensor_Default();
	}

	void CSensorFactory::destroy(ISensor* sensor) {
		delete sensor;
	}
}

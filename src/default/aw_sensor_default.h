#ifndef __AW_COMPASS_SENSOR_DEFAULT_H__
#define __AW_COMPASS_SENSOR_DEFAULT_H__

#include <compass/aw_sensor.h>

namespace Compass {
	class CSensor_Default
		: public ISensor
	{
	public:
		void addListener(ISensorListener* listener) override {}
		void removeListener(ISensorListener* listener) override {}
		void clearAllListeners() override {}
		void onCreate() override {}
		void onResume() override {}
		void onStop() override {}
	};
}

#endif

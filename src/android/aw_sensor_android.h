#ifndef __AW_COMPASS_SENSOR_ANDROID_H__
#define __AW_COMPASS_SENSOR_ANDROID_H__

#include <compass/aw_sensor.h>

namespace Compass {
	class ISensorListener;

	class CSensor_Android
		: public ISensor
	{
	private:
		// ISensor
		void addListener(ISensorListener* listener) override;
		void removeListener(ISensorListener* listener) override;
		void clearAllListeners() override;
		void onCreate() override;
		void onResume() override;
		void onStop() override;
	};
}

#endif

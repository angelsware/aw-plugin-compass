#ifndef __AW_COMPASS_SENSOR_IOS_H__
#define __AW_COMPASS_SENSOR_IOS_H__

#include <compass/aw_sensor.h>

namespace Compass {
	class ISensorListener;

	class CSensor_Ios
		: public ISensor
	{
	public:
		CSensor_Ios();
		~CSensor_Ios();

	private:
		// ISensor
		void addListener(ISensorListener* listener) override;
		void removeListener(ISensorListener* listener) override;
		void clearAllListeners() override;
		void onCreate() override;
		void onResume() override;
		void onStop() override;

		void* mSensor;
	};
}

#endif

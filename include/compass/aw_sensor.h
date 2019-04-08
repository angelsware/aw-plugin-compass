#ifndef __AW_COMPASS_SENSOR_H__
#define __AW_COMPASS_SENSOR_H__

namespace Compass {
	class ISensorListener;

	class ISensor
	{
	public:
		virtual ~ISensor() {}

		virtual void addListener(ISensorListener* listener) = 0;
		virtual void removeListener(ISensorListener* listener) = 0;
		virtual void clearAllListeners() = 0;
		virtual void onCreate() = 0;
		virtual void onResume() = 0;
		virtual void onStop() = 0;
	};
}

#endif

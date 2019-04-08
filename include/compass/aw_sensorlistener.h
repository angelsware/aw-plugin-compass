#ifndef __AW_COMPASS_SENSOR_LISTENER_H__
#define __AW_COMPASS_SENSOR_LISTENER_H__

namespace Compass {
	class ISensorListener
	{
	public:
		virtual void onCompassSensorChanged(float azimuth, float pitch, float roll) = 0;
		virtual void onCompassSensorAccuracyChanged(int accuracy) = 0;

	protected:
		virtual ~ISensorListener() {}
	};
}

#endif

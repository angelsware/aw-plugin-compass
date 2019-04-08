#ifndef __AW_COMPASS_SENSOR_FACTORY_H__
#define __AW_COMPASS_SENSOR_FACTORY_H__

namespace Compass {
	class ISensor;

	class CSensorFactory
	{
	public:
		static ISensor* create();
		static void destroy(ISensor* sensor);
	};
}

#endif

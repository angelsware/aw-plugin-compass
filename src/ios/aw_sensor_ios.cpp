#include "aw_sensor_ios.h"

extern "C" {
    void* CompassSensor_create();
    void CompassSensor_destroy(void* ptr);
    void CompassSensor_onCreate(void* ptr);
    void CompassSensor_onResume(void* ptr);
    void CompassSensor_onStop(void* ptr);
	void CompassSensor_addListener(void* ptr, long long listener);
	void CompassSensor_removeListener(void* ptr, long long listener);
	void CompassSensor_clearAllListeners(void* ptr);
}

namespace Compass {
	CSensor_Ios::CSensor_Ios() {
		mSensor = CompassSensor_create();
	}

	CSensor_Ios::~CSensor_Ios() {
		CompassSensor_destroy(mSensor);
	}

	void CSensor_Ios::addListener(ISensorListener* listener) {
        CompassSensor_addListener(mSensor, reinterpret_cast<long long>(listener));
	}

	void CSensor_Ios::removeListener(ISensorListener* listener) {
        CompassSensor_removeListener(mSensor, reinterpret_cast<long long>(listener));
	}

	void CSensor_Ios::clearAllListeners() {
        CompassSensor_clearAllListeners(mSensor);
	}

	void CSensor_Ios::onCreate() {
        CompassSensor_onCreate(mSensor);
	}

	void CSensor_Ios::onResume() {
        CompassSensor_onResume(mSensor);
	}

	void CSensor_Ios::onStop() {
        CompassSensor_onStop(mSensor);
	}
}

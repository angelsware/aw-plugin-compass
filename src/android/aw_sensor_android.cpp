#include "aw_sensor_android.h"
#include <platform/android/aw_jnifunction.h>
#include <platform/android/aw_jni.h>

namespace Compass {
	void CSensor_Android::addListener(ISensorListener* listener) {
		if (jclass clazz = Platform::CJniFunction::getClass("com/angelsware/compass/Sensor")) {
			if (jmethodID method = Platform::CJniFunction::getMethod(clazz, "addListener", "(J)V")) {
				Platform::CJni::getEnv()->CallStaticVoidMethod(clazz, method, reinterpret_cast<jlong>(listener));
			}
		}
	}

	void CSensor_Android::removeListener(ISensorListener* listener) {
		if (jclass clazz = Platform::CJniFunction::getClass("com/angelsware/compass/Sensor")) {
			if (jmethodID method = Platform::CJniFunction::getMethod(clazz, "removeListener", "(J)V")) {
				Platform::CJni::getEnv()->CallStaticVoidMethod(clazz, method, reinterpret_cast<jlong>(listener));
			}
		}
	}

	void CSensor_Android::clearAllListeners() {
		if (jclass clazz = Platform::CJniFunction::getClass("com/angelsware/compass/Sensor")) {
			if (jmethodID method = Platform::CJniFunction::getMethod(clazz, "clearAllListeners", "()V")) {
				Platform::CJni::getEnv()->CallStaticVoidMethod(clazz, method);
			}
		}
	}

	void CSensor_Android::onCreate() {
		if (jclass clazz =  Platform::CJniFunction::getClass("com/angelsware/compass/Sensor")) {
			if (jmethodID method = Platform::CJniFunction::getMethod(clazz, "onCreate", "()V")) {
				Platform::CJni::getEnv()->CallStaticVoidMethod(clazz, method);
			}
		}
	}

	void CSensor_Android::onResume() {
		if (jclass clazz = Platform::CJniFunction::getClass("com/angelsware/engine/Compass")) {
			if (jmethodID method = Platform::CJniFunction::getMethod(clazz, "onResume", "()V")) {
				Platform::CJni::getEnv()->CallStaticVoidMethod(clazz, method);
			}
		}
	}

	void CSensor_Android::onStop() {
		if (jclass clazz = Platform::CJniFunction::getClass("com/angelsware/engine/Compass")) {
			if (jmethodID method = Platform::CJniFunction::getMethod(clazz, "onStop", "()V")) {
				Platform::CJni::getEnv()->CallStaticVoidMethod(clazz, method);
			}
		}
	}
}

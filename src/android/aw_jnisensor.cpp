#include "aw_jnisensor.h"
#include <compass/aw_sensorlistener.h>

JNIEXPORT void JNICALL Java_com_angelsware_engine_Sensor_onCompassSensorChanged(JNIEnv* env, jclass clazz, jfloat azimuth, jfloat pitch, jfloat roll, jlong listener) {
	if (Compass::ISensorListener* ptr = reinterpret_cast<Compass::ISensorListener*>(listener)) {
		ptr->onCompassSensorChanged(azimuth, pitch, roll);
	}
}

JNIEXPORT void JNICALL Java_com_angelsware_engine_Sensor_onCompassSensorAccuracyChanged(JNIEnv* env, jclass clazz, jint accuracy, jlong listener) {
	if (Compass::ISensorListener* ptr = reinterpret_cast<Compass::ISensorListener*>(listener)) {
		ptr->onCompassSensorAccuracyChanged(accuracy);
	}
}

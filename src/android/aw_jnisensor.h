#ifndef __AW_COMPASS_JNI_SENSOR_H__
#define __AW_COMPASS_JNI_SENSOR_H__

#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif
	JNIEXPORT void JNICALL Java_com_angelsware_engine_Sensor_onCompassSensorChanged(JNIEnv* env, jclass clazz, jfloat azimuth, jfloat pitch, jfloat roll, jlong listener);
	JNIEXPORT void JNICALL Java_com_angelsware_engine_Sensor_onCompassSensorAccuracyChanged(JNIEnv* env, jclass clazz, jint accuracy, jlong listener);
#ifdef __cplusplus
}
#endif

#endif

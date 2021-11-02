package com.angelsware.compass;

import android.content.Context;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;

import com.angelsware.engine.AppActivity;

import java.util.ArrayList;
import java.util.List;

public class Sensor {
	public static native void onCompassSensorChanged(float azimuth, float pitch, float roll, long listener);
	public static native void onCompassSensorAccuracyChanged(int accuracy, long listener);

	private static List<Long> sListeners = new ArrayList<>();

	private static SensorManager sSensorManager;
	private static android.hardware.Sensor sRotationVectorSensor;

	private static final SensorEventListener sSensorEventListener = new SensorEventListener() {
		@Override
		public void onSensorChanged(SensorEvent sensorEvent) {
			if (sensorEvent.sensor.getType() == android.hardware.Sensor.TYPE_ROTATION_VECTOR) {
				float[] rotationMatrix = new float[16];
				SensorManager.getRotationMatrixFromVector(rotationMatrix, sensorEvent.values);
				float[] orientationValues = new float[3];
				SensorManager.remapCoordinateSystem(rotationMatrix, SensorManager.AXIS_X, SensorManager.AXIS_Y, rotationMatrix);
				SensorManager.getOrientation(rotationMatrix, orientationValues);
				float azimuth = (float)Math.toDegrees(orientationValues[0]);
				float pitch = (float)Math.toDegrees(orientationValues[1]);
				float roll = (float)Math.toDegrees(orientationValues[2]);

				for (Long listener : sListeners) {
					onCompassSensorChanged(azimuth, pitch, roll, (long) listener);
				}
			}
		}

		@Override
		public void onAccuracyChanged(android.hardware.Sensor sensor, int accuracy) {
			if (sensor.getType() == android.hardware.Sensor.TYPE_ROTATION_VECTOR) {
				for (Long listener : sListeners) {
					onCompassSensorAccuracyChanged(accuracy, (long) listener);
				}
			}
		}
	};

	public static void addListener(long listener) {
		sListeners.add(listener);
	}

	public static void removeListener(long listener) {
		sListeners.remove(listener);
	}

	public static void clearAllListeners() {
		sListeners.clear();
	}

	public static void onCreate() {
		sSensorManager = (SensorManager)(AppActivity.getActivity().getSystemService(Context.SENSOR_SERVICE));
		if (sSensorManager != null) {
			sRotationVectorSensor = sSensorManager.getDefaultSensor(android.hardware.Sensor.TYPE_ROTATION_VECTOR);
		}
	}

	public static void onResume() {
		sSensorManager.registerListener(sSensorEventListener, sRotationVectorSensor, SensorManager.SENSOR_DELAY_GAME);
	}

	public static void onStop() {
		sSensorManager.unregisterListener(sSensorEventListener);
	}
}

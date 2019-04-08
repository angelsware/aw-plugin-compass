package com.angelsware.compass;

import java.util.List;
import java.util.ArrayList;
import java.util.Iterator;

import android.content.Context;
import android.hardware.SensorListener;
import android.hardware.SensorManager;

import com.angelsware.engine.AppActivity;

public class Sensor {
	public static native void onCompassSensorChanged(float azimuth, float pitch, float roll, long listener);
	public static native void onCompassSensorAccuracyChanged(int accuracy, long listener);

	private static List sListeners = new ArrayList();

	private static SensorManager sSensorManager;
	private static final SensorListener sListener = new SensorListener() {
		public void onSensorChanged(int sensor, float[] values) {
			if (sensor == SensorManager.SENSOR_ORIENTATION) {
				for (Iterator<Long> i = sListeners.iterator(); i.hasNext();) {
					Long listener = i.next();
					onCompassSensorChanged(values[0], values[1], values[2], (long)listener);
				}
			}
		}

		public void onAccuracyChanged(int sensor, int accuracy) {
			if (sensor == SensorManager.SENSOR_ORIENTATION) {
				for (Iterator<Long> i = sListeners.iterator(); i.hasNext();) {
					Long listener = i.next();
					onCompassSensorAccuracyChanged(accuracy, (long)listener);
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
	}

	public static void onResume() {
		sSensorManager.registerListener(sListener, SensorManager.SENSOR_ORIENTATION, SensorManager.SENSOR_DELAY_GAME);
	}

	public static void onStop() {
		sSensorManager.unregisterListener(sListener);
	}
}

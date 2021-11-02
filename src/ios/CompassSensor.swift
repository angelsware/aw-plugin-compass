import CoreLocation

class CompassSensor: NSObject, CLLocationManagerDelegate {
    private var listeners: Set<Int64> = Set()
    private var locationManager: CLLocationManager?
    private var requestingUpdates = false
    
    func addListener(listener: Int64) {
        listeners.insert(listener)
    }

    func removeListener(listener: Int64) {
        listeners.remove(listener)
    }

    func clearAllListeners() {
        listeners.removeAll()
    }

    func onCreate() {
        locationManager = CLLocationManager()
        locationManager?.requestWhenInUseAuthorization()
        locationManager?.distanceFilter = 1000
        locationManager?.desiredAccuracy = kCLLocationAccuracyBest
        locationManager?.delegate = self
    }

    func onResume() {
        locationManager?.startUpdatingHeading()
    }

    func onStop() {
        locationManager?.stopUpdatingHeading()
    }

    func locationManager(_ manager: CLLocationManager, didUpdateHeading newHeading: CLHeading) {
        // TODO: x and y is probably not correct.
        listeners.forEach { listener in
            CompassDelegate.onCompassSensorChanged(listener, azimuth: Float(newHeading.trueHeading), pitch: Float(newHeading.y * 2.0), roll: Float(newHeading.x * 2.0))
        }
    }
}

@_cdecl("CompassSensor_create")
func CompassSensor_create() -> UnsafeMutablePointer<CompassSensor> {
    let sensor = UnsafeMutablePointer<CompassSensor>.allocate(capacity: 1)
    sensor.initialize(to: CompassSensor())
    return sensor
}

@_cdecl("CompassSensor_destroy")
func CompassSensor_destroy(ptr: UnsafeMutablePointer<CompassSensor>) {
	ptr.deallocate()
}

@_cdecl("CompassSensor_onCreate")
func CompassSensor_onCreate(ptr: UnsafeMutablePointer<CompassSensor>) {
    ptr.pointee.onCreate()
}

@_cdecl("CompassSensor_onResume")
func CompassSensor_onResume(ptr: UnsafeMutablePointer<CompassSensor>) {
    ptr.pointee.onResume()
}

@_cdecl("CompassSensor_onStop")
func CompassSensor_onStop(ptr: UnsafeMutablePointer<CompassSensor>) {
    ptr.pointee.onStop()
}

@_cdecl("CompassSensor_addListener")
func CompassSensor_addListener(ptr: UnsafeMutablePointer<CompassSensor>, listener: Int64) {
    ptr.pointee.addListener(listener: listener)
}

@_cdecl("CompassSensor_removeListener")
func CompassSensor_removeListener(ptr: UnsafeMutablePointer<CompassSensor>, listener: Int64) {
    ptr.pointee.removeListener(listener: listener)
}

@_cdecl("CompassSensor_clearAllListeners")
func CompassSensor_clearAllListeners(ptr: UnsafeMutablePointer<CompassSensor>) {
    ptr.pointee.clearAllListeners()
}

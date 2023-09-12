import CoreLocation
import CoreMotion

class CompassSensor: NSObject, CLLocationManagerDelegate {
    private var listeners: Set<Int64> = Set()
    private var locationManager: CLLocationManager?
    private var motionManager: CMMotionManager?
    private var requestingUpdates = false
    private var timer: Timer?
    private var azimuth = 0.0
    
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

        motionManager = CMMotionManager()
        motionManager?.deviceMotionUpdateInterval = 1.0 / 50.0
        motionManager?.showsDeviceMovementDisplay = true
        motionManager?.startDeviceMotionUpdates(using: .xMagneticNorthZVertical)
        let s = self
        self.timer = Timer(fire: Date(), interval: (1.0 / 50.0), repeats: true, block: { (self) in
            if let data = s.motionManager?.deviceMotion {
                let x = data.attitude.pitch * 180.0 / Double.pi
                let y = data.attitude.roll * 180.0 / Double.pi
                let z = data.attitude.yaw * 180.0 / Double.pi
                s.listeners.forEach { listener in
                    CompassDelegate.onCompassSensorChanged(listener, azimuth: Float(s.azimuth), pitch: Float(-x), roll: Float(y))
                }
            }
        })

        RunLoop.current.add(self.timer!, forMode: RunLoop.Mode.defaultRunLoopMode)
    }

    func onResume() {
        locationManager?.startUpdatingHeading()
        motionManager?.startDeviceMotionUpdates(using: .xMagneticNorthZVertical)
    }

    func onStop() {
        locationManager?.stopUpdatingHeading()
        motionManager?.stopDeviceMotionUpdates()
    }

    func locationManager(_ manager: CLLocationManager, didUpdateHeading newHeading: CLHeading) {
        self.azimuth = newHeading.trueHeading
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

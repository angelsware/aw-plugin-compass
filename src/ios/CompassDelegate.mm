#import "CompassDelegate.h"
#import <compass/aw_sensorlistener.h>

@implementation CompassDelegate

+(void) onCompassSensorChanged:(int64_t) id azimuth:(float) azimuth pitch:(float) pitch roll:(float) roll {
    reinterpret_cast<Compass::ISensorListener*>(id)->onCompassSensorChanged(azimuth, pitch, roll);
}

+(void) onCompassSensorAccuracyChanged:(int64_t) id accuracy:(int) accuracy {
    reinterpret_cast<Compass::ISensorListener*>(id)->onCompassSensorAccuracyChanged(accuracy);
}

@end

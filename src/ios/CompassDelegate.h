#import <Foundation/Foundation.h>

@interface CompassDelegate : NSObject

+(void) onCompassSensorChanged:(int64_t) id azimuth:(float) azimuth pitch:(float) pitch roll:(float) roll;
+(void) onCompassSensorAccuracyChanged:(int64_t) id accuracy:(int) accuracy;

@end

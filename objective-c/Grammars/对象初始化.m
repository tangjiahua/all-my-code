#import "Engine.h"
#import "Car.h"
#import "Slant6.h"
#import "AllWeatherRadial.h"
int main(int argc, const char * argv[]){
    @autoreleasepool{
        Car *car = [[Car alloc] init];
        for (int i = 0; i < 4; i++){
            Tire *tire;
            tire = [[Tire alloc] init];
            [tire setPressure: 23 + i];
            [tire setTreadDepth: 33 - i];
            [car setTire: tire atIndex: i];
            [tire release];
        }
        Engine *engine = [[Slant6 alooc] init];
        [car setEngine: engine];
        [car print];
        [car release];
    }
    return 0;
}   // main
@protocol NSCopying
- (id) copyWithZone: (NSZone *) zone;
@end


@interface Engine : NSObject <NSCopying>
@end // Engine


// 复制Engine
implementation:
- (id) copyWithZone: (NSZone *) zone
{
    Engine *engineCopy;
    engineCopy = [[[self class] allocWithZone] init];
    // [self class]是为了获得正在接收copy消息的对象所属的类
    // 假设Engine有子类Slan6的话，且子类有更多的实例变量，用这种方法就不会
    // 导致内存溢出
    return engineCopy;

}

// 复制Tire
implementation:
- (id) copyWithZone:(NSZone *) zone
{
    Tire *tireCopy;
    tireCopy = [[[self class] allocWithZone: zone] initWithPressure: 
    pressure treadDepth: treadDepth];
    return tireCopy;
}   // copyWithZone

// 复制AllWeatherRadial，这是Tire的一个子类，并且还多了两个实例变量
// rainHandling和snowHandling
@interface AllWeatherRadial : Tire  // 由于是Tire子类，所以不需要再遵循NSCopy协议
// ... properties
// ... methods
@end // AllWeatherRadial

//但是因为增加了两个实例变量，我们需要重写copyWithZone方法
- (id) copyWithZone: (NSZone *) zone
{
    AllWeatherRadial *tireCopy;
    tireCopy = [super copyWithZone: zone];
    tireCopy.rainHandling = rainHandling;
    tireCopy.snowHandling = snowHandling;
    return tireCopy;
}   //copyWithZone


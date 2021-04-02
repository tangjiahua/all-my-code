#import <Foundation/Foundation.h>

int main() {
   /* my first program in Objective-C */
    @autoreleasepool {
        NSFileManager *manager;
        manager = [NSFileManager defaultManager];
        
        NSString *home;
        home = [@"~" stringByExpandingTildeInPath];
        
        NSMutableArray *files;
        files = [NSMutableArray arrayWithCapacity:42];
        
        for(NSString *string in [manager enumeratorAtPath:home]){
            if([[string pathExtension] isEqualToString:@"jpg"]){
                NSLog(@"%@", string);
            }
        }
        
        
    }
    
    
    
   return 0;
}

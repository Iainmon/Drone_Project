//
//  main.m
//  Drone Code Compiler (apple)
//
//  Created by Iain Moncrief on 8/16/17.
//  Copyright © 2017 Iain Moncrief. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <AppleScriptObjC/AppleScriptObjC.h>

int main(int argc, const char * argv[]) {
    [[NSBundle mainBundle] loadAppleScriptObjectiveCScripts];
    return NSApplicationMain(argc, argv);
}

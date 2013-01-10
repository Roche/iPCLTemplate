//
//  ___PROJECTNAMEASIDENTIFIER___AppDelegate.h
//  ___PROJECTNAME___
//
//  Created by ___FULLUSERNAME___ on ___DATE___.
//  Copyright ___ORGANIZATIONNAME___ ___YEAR___. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "RootViewController.h"
#import "MobileAppDelegate.h"
#import "UncaughtExceptionHandlerDelegate.h"

@interface ___PROJECTNAMEASIDENTIFIER___AppDelegate : MobileAppDelegate <UIApplicationDelegate, UncaughtExceptionHandlerDelegate> {
    UINavigationBar *navBar;
	UINavigationController *navController;
}

@property (nonatomic, retain) IBOutlet UINavigationBar *navBar;
@property (nonatomic, retain) IBOutlet UINavigationController *navController;

- (IBAction) infoClicked:(id) sender;
@end


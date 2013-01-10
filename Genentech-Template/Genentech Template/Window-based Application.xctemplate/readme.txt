Genentech iPhone Template is created to provide the following common functionalities

1) Common framework and skeleton for your project 
   By creating XCode project using Genentech iPhone App template, you will get a common framework long with pre-define app skeleton to save your development time.
   After creating a vanilla project using our framework, you will need to do the following task to make the project specific to your needs
	- Override performAppMainLogic in your appDelegate to add your application specific logic, 
	- Modify the generated info.plist file to set up the following values specific to your project needs
	   1) Bundle identifier - All Genentech iPhone application has to use com.gene.[DEPARTMENT_NAME].appName as the identifier
	   2) URL Types - Override with your own application specific URL scheme and identifier so that your app can be launched by other app 
	- Add your application specific Icon.png and Default.png file to Resources -> Images group. Your Icon file should not have any gloss effect.
    - go to the Build Phases setting for the target then remove libOmnitureAppMeasurement-iPhoneDevice.a and libOmnitureAppMeasurement-iPhoneSimulator.a from the "Link Binary With Libraries" list. They will get linked conditionally anyway due to other project settings. This removes a linker warning about incompatible library version (i.e simulator vs device build). 

2) Authentication
   Genentech iPhone Framework provides built-in authentication against Genentech directory service. Login screen is provided for user to provide their Unix ID and
   pasword
   Things to note:
   - If useStaticData in the Info.plist is unchecked, users will be required to login with there Unix ID and password when they use the application
	for the first time. Password will be cached in iPhone keychain so that subsequent usage of the app will not require user to login.
	 During testing, you can also check useStaticData in the Info.plist so that you can test the application without login with Unix ID and password.
  - If supportOffline in the Info.plist is checked, any subsequent logic will happen in the background. This gives the application the fastest loading time possible
  - A built-in LaunchView is provided to show user a loading image and waiting icon while authentication is being performed. To show a different background image,
    you can change the value of LAUNCH_BACKGROUND_IMAGE in GeneApp_Common.h under "Genentech Common Utils".
   - Built-in LoginView can use a custom navigation tintcolor, background color or background image. To specify those values according to your 
   application needs, you can modify DEFAULT_TINT_COLOR, DEFAULT_BACKGROUND_COLOR or DEFAULT_BACKGROUND_IMAGE accordingly in GeneApp_Common.h under "Genentech Common Utils". When both DEFAULT_BACKGROUND_IMAGE
   and DEFAULT_BACKGROUND_COLOR are specified, DEFAULT_BACKGROUND_IMAGE will be used.

3) Display application info and version #
   Genentech iPhone Framework provides a built-in view to display application name, a short description, version and copyright info about your application. To
   put in your application specific values, you will need to 
   - Modify appDesc, application bundle version in Info.plist
   - Modify APP_DISPLAY_TITLE in GeneApp_Common.h under "Genentech Common Utils" to specify your app name
   A default "Info" button is added to the navigation controller to showcase how to use the AboutViewController
   
4) Usage Analytics
   Genentech iPhone framework provides a built-in method to track your application's usage analytics. To use it, you can simply call the following code
   [UsageTracking pageViewed:[FunctionNameHere] section:[FunctionGroupNameHere]];

5) Configurable Application Logging
   Genentech iPhone framework provides an easy to way to adjust logging level throughout your application. To configure it, you can
   - Use LOG_MESSAGE method instead of NSLog method so that you can log message with a specified level
   - Update LOG_LEVEL in Info.plist to set minimum logging level. Valid values including DEBUG, INFO, WARN and ERROR. For example, when create production
     build, you will want to set the LOG_LEVEL to ERROR to reduce unnecessary debug logging for best performance on phone.
     
6) Server side logging
   Genentech iPhone framework provides a built in method to support server side logging on error. You should this method to report unexpected or unhandled exception from your application
   To use it, you can simply call the following code
   When called from main UI thread
   Use [LoggingUtils logError:[APP_NAME_WITH_NO_SPACE] function:[FUNCTION_NAME] errorMessage:[ERROR_MESSAGE]  data:[DATA_THAT_CAUESD_THE_ERROR]]; 
   
   When called from non-main thread (e.g. thread started by the code or from NSOperation)
   Use [LoggingUtils syncLogError:[APP_NAME_WITH_NO_SPACE] function:[FUNCTION_NAME] errorMessage:[ERROR_MESSAGE]  data:[DATA_THAT_CAUESD_THE_ERROR]];
   
   Genentech supports email notifications on error logged using this utility. Please contact the iPhone team if you need this error logging to automatically
   trigger an email to a distribution list

7) localization support
   If localization is needed for your app, you can add the strings that are displayed to end user in the built-in Localizable.strings file.
   You can call LocStr([STRING_KEY]) in your app to use the string value specified in the Localizable.strings file.

8) Genentech ObjectC Categories
   Genentech iPhone framework provides several useful ObjectC categories as specified below to provide enhanced functionalities on top of existing base objects
   - NSData+GenenUtil.h. This category implements base64 encoding and decoding on NSData
   - NSString+GenenUtil.h. This category implements quite a few useful functions on NSString, including trim, validate email or phone number, XML unescape a string or URL encoding a string
 
9) JSON Support
   JSON format is Genentech's preferred format for communication with server over HTTP. 
   Genentech iPhone framework provides an easy way to convert NSDictionary, NSArray or NSString to JSON.
   For example, you can import "NSDictionary+BSJSONAdditions.h", then call
   NSDictionary *jsonDict = [NSDictionary dictionaryWithJSONString:jsonStr]; to convert JSON object in String format to a NSDictionary object
   
10) Email from within the app
   Genentech iPhone framework provides a built-in EmailUtils that allows you send email from within your app. To use it, you will need
   1) Import EmailUtils.h in your ViewController and make it implement MFMailComposeViewControllerDelegate 
   2) In your ViewController, define - (void)mailComposeController:(MFMailComposeViewController*)controller didFinishWithResult:(MFMailComposeResult)result error:(NSError*)error;
      to perform tasks once email is sent or user cancelled operation 
	  Sample implementation of this method could be
	 - (void)mailComposeController:(MFMailComposeViewController*)controller didFinishWithResult:(MFMailComposeResult)result error:(NSError*)error 
		{	
			[self dismissModalViewControllerAnimated:YES];
		}			 		
   3) Call [EmailUtils sendEmail:[TO_EMAIL_ADDRESS] callBack:self]; in your code to start send email to the specific email address
   
   

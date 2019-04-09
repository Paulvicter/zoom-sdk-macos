//
//  ZoomSDKH323Helper.h
//  ZoomSDK
//
//  Created by TOTTI on 1/3/17.
//  Copyright © 2017 Zoom Video Communications,Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZoomSDKErrors.h"

/**
 * @brief H.323 device information.
 */
@interface H323DeviceInfo : NSObject
{
    NSString* _name;
    NSString* _ip;
    NSString* _e164num;
    H323DeviceType _type;
    EncryptType  _encryptType;
}

@property(nonatomic, retain)NSString* name;
@property(nonatomic, retain)NSString* ip;
@property(nonatomic, retain)NSString* e164num;
@property(nonatomic, assign)H323DeviceType type;
@property(nonatomic, assign)EncryptType encryptType;
@end

@protocol ZoomSDKH323HelperDelegate <NSObject>
@optional
/**
 * @brief Receive outgoing call status of H.323 device.
 * @param calloutStatus Notify user if the outgoing call status changes.
 *
 */
- (void) onCalloutStatusReceived:(H323CalloutStatus)calloutStatus;

/**
 * @brief Callback event of H.323 device pairing meeting.
 * @param pairResult Notify user if the paring status changes.
 * @param meetingNum The meeting number of the meeting.
 */
- (void) onPairCodeResult:(H323PairingResult)pairResult MeetingNumber:(long long)meetingNum;
@end


@interface ZoomSDKH323Helper : NSObject
{
    id<ZoomSDKH323HelperDelegate> _delegate;
}
@property (assign, nonatomic) id<ZoomSDKH323HelperDelegate> delegate;
/**
 * @brief Get the H.323 device address of the current meeting.
 * @return If the function succeeds, it will return the address. Otherwise failed.
 */
- (NSArray*)getH323DeviceAddress;

 /**
 * @brief Get the H.323 device password of the current meeting.
 * @return If the function succeeds, it will return the password. Otherwise failed.
 */
- (NSString*)getH323Password;

/**
 * @brief Send meeting paring code.
 * @param pairCode Pairing code of the specified meeting.
 * @param meetingNum Meeting number for pairing.
 * @return If the function succeeds, it will return ZoomSDKError_success. Otherwise failed. 
 */
- (ZoomSDKError)sendMeetingPairingCode:(NSString*)pairCode meetingNum:(long long)meetingNum;

/**
 * @brief This method is used to call out a H.323 device.
 * @param deviceInfo The information of H.323 device that you want to call out. 
 * @return If the function succeeds, it will return ZoomSDKError_success. Otherwise failed. 
 */
- (ZoomSDKError)calloutH323Device:(H323DeviceInfo*)deviceInfo;

/**
 * @brief Get the list of H.323 devices for the current meeting.
 * @return If the function succeeds, it will return the list, otherwise not.
 */
- (NSArray*)getRoomH323DeviceArray;

/**
 * @brief Cancel the latest operation of calling out H.323 device. 
 * @return If the function succeeds, it will return ZoomSDKError_success. Otherwise failed.
 */
- (ZoomSDKError)cancelCallOutH323;

@end
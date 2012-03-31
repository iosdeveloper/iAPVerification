//
//  iAPVerification.h
//
//  Created by Max Bäumle.
//  Copyright (c) 2011-2012 Max Bäumle. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKit.h>

typedef enum {
    iAPTransactionMissing, // paymentTransaction object missing
    iAPVerificationFailed,
    iAPConnectionFailed, // Server connection failed
} iAPErrorCode;

@interface iAPVerification : NSObject

+ (void)verifyPurchase:(SKPaymentTransaction *)paymentTransaction isSandbox:(BOOL)sandbox delegate:(id)delegate;
+ (void)verifyPurchase:(SKPaymentTransaction *)paymentTransaction serverUrl:(NSString *)urlString isSandbox:(BOOL)sandbox delegate:(id)delegate;

+ (BOOL)findBinaries; // Find binaries used for cracking on the device

@end

@protocol iAPVerificationDelegate <NSObject>

@optional

- (void)verificationFailed:(iAPErrorCode)errorCode error:(NSError *)error paymentTransaction:(SKPaymentTransaction *)paymentTransaction;
- (void)purchaseVerified:(NSDictionary *)dictionary; // Available keys: 'quantity', 'product_id', 'transaction_id', 'purchase_date', 'app_item_id', 'bid', 'bvrs'

/* DEPRECATED */
- (void)verificationFailed:(iAPErrorCode)errorCode error:(NSError *)error __attribute__((deprecated));

@end

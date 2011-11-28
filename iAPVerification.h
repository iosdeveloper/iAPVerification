//
//  iAPVerification.h
//  iap
//
//  Created by Max Bäumle.
//  Copyright (c) 2011 Max Bäumle. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKit.h>

typedef enum {
    iAPTransactionMissing, // paymentTransaction object missing
    iAPVerificationFailed,
    iAPConnectionFailed, // Server connection failed
} iAPErrorCode;

@interface iAPVerification : NSObject {
    id _delegate;
    NSMutableData *_receivedData;
}

- (id)init:(SKPaymentTransaction *)paymentTransaction isSandbox:(BOOL)sandbox delegate:(id)delegate;
+ (id)verifyPurchase:(SKPaymentTransaction *)paymentTransaction isSandbox:(BOOL)sandbox delegate:(id)delegate;

- (id)init:(SKPaymentTransaction *)paymentTransaction serverUrl:(NSString *)urlString isSandbox:(BOOL)sandbox delegate:(id)delegate;
+ (id)verifyPurchase:(SKPaymentTransaction *)paymentTransaction serverUrl:(NSString *)urlString isSandbox:(BOOL)sandbox delegate:(id)delegate;

@end

@protocol iAPVerificationDelegate <NSObject>

@optional

- (void)verificationFailed:(int)errorCode error:(NSError *)error;
- (void)purchaseVerified:(NSDictionary *)dictionary; // Available keys: 'quantity', 'product_id', 'transaction_id', 'purchase_date', 'app_item_id', 'bid', 'bvrs'

@end
//
//  iAPVerification.h
//  iap
//
//  Created by Max Bäumle.
//  Copyright (c) 2011 Max Bäumle. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKit.h>

typedef enum _iAPErrorCode {
    iAPTransactionMissing = 0, // paymentTransaction object missing
    iAPVerificationFailed = 1,
    iAPConnectionFailed = 2, // Server connection failed
} iAPErrorCode;

@interface iAPVerification : NSObject {
    id _delegate;
    NSMutableData *_receivedData;
}

- (id)init:(SKPaymentTransaction *)paymentTransaction isSandbox:(BOOL)sandbox delegate:(id)delegate;
+ (id)verifyPurchase:(SKPaymentTransaction *)paymentTransaction isSandbox:(BOOL)sandbox delegate:(id)delegate;

@end

@protocol iAPVerificationDelegate <NSObject>

@optional

- (void)verificationFailed:(int)errorCode error:(NSError *)error;
- (void)purchaseVerified:(NSDictionary *)dictionary; // Available keys: 'quantity', 'product_id', 'transaction_id', 'purchase_date', 'app_item_id', 'bid', 'bvrs'

@end
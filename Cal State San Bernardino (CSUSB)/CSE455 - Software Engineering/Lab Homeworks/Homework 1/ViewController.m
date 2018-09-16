//  James Small
//  Monday / Wednesday
//  CSE455
//
//  ViewController.m
//
//  Created by James Small on 1/8/14.
//  Copyright (c) 2014 James Small. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@property (weak, nonatomic) IBOutlet UILabel *textLabel;

@end

@implementation ViewController

- (IBAction)changeText:(id)sender {
    
    self.textLabel.text = [NSString stringWithFormat:@"James Small"];
    self.textLabel.textColor = [UIColor redColor];
    self.textLabel.font = [UIFont boldSystemFontOfSize:16];
    self.textLabel.font = [UIFont italicSystemFontOfSize:16];
}

@end

//
//  macosx_dialog.m
//  TuxPaint-Config
//
//  Created by Martin Fuhrer on 12/06/07.
//  Copyright 2007 __MyCompanyName__. All rights reserved.
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation; either version 2 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//  (See COPYING.txt)
//

#import "macosx_dialog.h"
#import <Cocoa/Cocoa.h>
#import <AppKit/NSOpenPanel.h>

// this object waits for the open dialog to go away
@interface ModalDelegate : NSObject
{
    BOOL isDismissed;
    BOOL isCancelled;
    NSString *path;
}
- (id)   init;
- (void) dealloc;
- (BOOL) wait;
- (NSString*) path;
- (void) reset;
@end

@implementation ModalDelegate

- (id) init
{
    self = [ super init ];
    [ self reset ];
    return self;
}

- (void) dealloc
{
    [path release];   
    [super dealloc];
}

- (BOOL) wait
{
    while (!isDismissed) {
        
        NSEvent *event;
        
        event = [ NSApp nextEventMatchingMask:NSAnyEventMask
                                    untilDate:[ NSDate distantFuture ]
                                       inMode: NSDefaultRunLoopMode dequeue:YES ];
        
        [ NSApp sendEvent:event ];
    }
    
    return isCancelled;
}

- (void) reset
{
    isDismissed = NO;
    isCancelled = NO;
    path = @"";
}

- (NSString*) path
{
    return path;   
}

- (void)openPanelDidEnd:(NSOpenPanel *)panel 
            returnCode:(int)returnCode contextInfo:(void *)contextInfo
{
    isDismissed = YES;
    if( returnCode == NSOKButton )
    {
        isCancelled = NO;
        [ path release ];
        path = [ [ panel filename ] retain ];
    }
    else
    {
        isCancelled = YES;
    }
}

@end


const char *choosePath(int files, int directories, const char* extension)
{
    NSApplicationLoad();  // initialize Cocoa
    
    NSString* dirPath = @"";
    ModalDelegate* delegate = [ [ ModalDelegate alloc ] init ];
    
    NSMutableArray* fileTypes = [ [ NSMutableArray alloc ] init ];
    if( extension != 0 )
    {
        [ fileTypes addObject:[ NSString stringWithCString:extension ] ];
    }
    
    NSOpenPanel* openPanel = [ NSOpenPanel openPanel ];
    
    [ openPanel setCanChooseFiles:(files != 0) ];
    [ openPanel setCanChooseDirectories:(directories != 0 ) ];
    
    // Display dialog as sheet (doesn't seem to work currently)
    /*
    [ openPanel beginSheetForDirectory:nil 
           file:nil
           types:fileTypes
           modalForWindow:[ NSApp mainWindow ] 
           modalDelegate:delegate
           didEndSelector:@selector(openPanelDidEnd: returnCode: contextInfo:) 
           contextInfo:nil ];
     
    [ delegate wait ];
    dirPath = [ delegate path ];
    */

    // Display dialog modally
    int result = [ openPanel runModalForDirectory:NSHomeDirectory() file:nil types:fileTypes ];
    if( result == NSOKButton )
        dirPath = [ openPanel filename ];
    
    [ delegate release ];
    [ fileTypes release ];
    
    const char* path = [ dirPath cString ];
    return path;
}

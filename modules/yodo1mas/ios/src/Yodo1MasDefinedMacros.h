//
//  Yodo1MasAvailabilityMacros.h
//  Yodo1MasCore
//
//  Created by Sunmeng on 2024/1/3.
//

#import <Foundation/Foundation.h>

#if defined(__has_attribute)
    #if __has_attribute(deprecated)
        #define MAS_DEPRECATED_MSG_ATTRIBUTE(s) __attribute__((deprecated(s)))
        #define MAS_DEPRECATED_ATTRIBUTE __attribute__((deprecated))
    #else
        #define MAS_DEPRECATED_MSG_ATTRIBUTE(s)
        #define MAS_DEPRECATED_ATTRIBUTE
    #endif

    #if __has_attribute(unavailable)
        #define MAS_UNAVAILABLE_MSG_ATTRIBUTE(s) __attribute__((unavailable(s)))
        #define MAS_UNAVAILABLE_ATTRIBUTE __attribute__((unavailable))
    #else
        #define MAS_UNAVAILABLE_MSG_ATTRIBUTE(s)
        #define MAS_UNAVAILABLE_ATTRIBUTE
    #endif

#else
    #define MAS_DEPRECATED_MSG_ATTRIBUTE(s)
    #define MAS_DEPRECATED_ATTRIBUTE

    #define MAS_UNAVAILABLE_MSG_ATTRIBUTE(s)
    #define MAS_UNAVAILABLE_ATTRIBUTE

#endif

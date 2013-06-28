//
//  behaviour.h
//  emptyExample
//
//  Created by Rahmat Hidayat on 2013/06/26.
//
//

#ifndef __emptyExample__behaviour__
#define __emptyExample__behaviour__

#include <iostream>
#include "particle.h"
#include "vector.h"

class Behaviour {
    public:
        static short GUID;
    
        Behaviour() {
            GUID++;
        };
    
        virtual void apply(Particle p, Vector dt, short index);
};

#endif /* defined(__emptyExample__behaviour__) */

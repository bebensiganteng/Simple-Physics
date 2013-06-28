//
//  edgeBounce.h
//  emptyExample
//
//  Created by Rahmat Hidayat on 2013/06/26.
//
//

#ifndef __emptyExample__edgeBounce__
#define __emptyExample__edgeBounce__

#include <iostream>
#include "behaviour.h"

class EdgeBounce:public Behaviour{
    public:
    
        Vector *min;
        Vector *max;
    
        void setMinMax(Vector &_min, Vector &_max) {
            min = &_min;
            max = &_max;
            
            //cout << "setMinMax:" << max->x << " " << max->y << endl;
        }
    
        void apply(Particle p, Vector dt, short index);

};

#endif /* defined(__emptyExample__edgeBounce__) */

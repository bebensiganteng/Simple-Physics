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
    
    void setMinMax(Vector &_min, Vector &_max);
    void apply(Particle p, Vector dt, short index);
    
private:
    
    Vector *min;
    Vector *max;
    

};

#endif /* defined(__emptyExample__edgeBounce__) */

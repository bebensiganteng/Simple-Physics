//
//  force.cpp
//  emptyExample
//
//  Created by Rahmat Hidayat on 2013/06/27.
//
//

#include "force.h"


void Force::apply(Particle p, Vector dt, short index) {
    p.acc->operator+=(g);
}
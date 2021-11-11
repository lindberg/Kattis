#ifndef OPTIMIZATION2OPT_H
#define OPTIMIZATION2OPT_H

#include "ProblemInstance.h"
#include <stack>

class Optimization2opt {
    public:
    void optimize(ProblemInstance *instance) {
        while (optimizationPass(instance));
    }

    bool optimizationPass(ProblemInstance *instance) {
        bool didSwap = false;
        for (int i = 0; i < instance->n; i++) {
            for (int j = 0; j < instance->n; j++) {
                if (i == j) {
                    continue;
                }
                Point *i1 = instance->points[i];
                Point *i2 = i1->nextPoint;
                Point *j1 = instance->points[j];
                Point *j2 = j1->nextPoint;
                if (i1 == j2 || j1 == i2) {
                    continue;
                }
                double currentDistance = i1->distance(i2) + j1->distance(j2);
                double potentialDistance = i1->distance(j1) + i2->distance(j2);
                
                if (potentialDistance < currentDistance) {
                    std::stack<Point*> toReverse;
                    toReverse.push(i2);
                    while (true) {
                        Point *next = toReverse.top()->nextPoint;
                        toReverse.push(next);
                        if(next == j1) {
                            break;
                        }
                    }
                    while(toReverse.size() > 1) {
                        Point *p = toReverse.top();
                        toReverse.pop();
                        p->nextPoint = toReverse.top();
                    }
                    i1->nextPoint = j1;
                    i2->nextPoint = j2;

                    didSwap = true;
                }
                
            }
        }
        return didSwap;
    }
};
#endif
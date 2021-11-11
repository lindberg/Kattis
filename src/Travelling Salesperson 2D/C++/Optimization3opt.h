#ifndef OPTIMIZATION3OPT_H
#define OPTIMIZATION3OPT_H

#include "ProblemInstance.h"
#include <stack>

class Optimization3opt {
    private:
    int iterations = 0;

    public:
    void optimize(ProblemInstance *instance) {
        while (optimizationPass(instance));
    }

    bool optimizationPass(ProblemInstance *instance) {
        bool didSwap = false;
        Point *x1 = instance->points[0];
        Point *x2;
        Point *y1;
        Point *y2;
        Point *z1;
        Point *z2;
        bool first = true;

        for(int i = 0; i < instance->n; i++) {
            x1 = instance->points[i];
            if (iterations > 30000000) break;
            first = false;
            y1 = x1->nextPoint->nextPoint;
            int ite_y = 0;
            for (int j = 0; y1 != x1; j++) {
                x2 = x1->nextPoint;
                y2 = y1->nextPoint;
                z1 = y2->nextPoint;
                bool is_break = false;
                for (int k = 0; k<=23 || k == 0; k++) {
                    z2 = z1->nextPoint;
                        
                    //if (ite_y >= 10) break;
                    ite_y++;
                    iterations++;

                    if (z1 == x1) {
                        is_break = true;
                        break;
                    }

                    double currentDistance = x1->distance(x2) + y1->distance(y2) + z1->distance(z2);
            
                    double case1Distance = x1->distance(z1) + y1->distance(y2) + x2->distance(z2)+0.01;
                    double case2Distance = x1->distance(x2) + y1->distance(z1) + y2->distance(z2)+0.01;
                    double case3Distance = x1->distance(y1) + x2->distance(y2) + z1->distance(z2)+0.01;
                    double case4Distance = x1->distance(y1) + x2->distance(z1) + y2->distance(z2)+0.01;
                    double case5Distance = x1->distance(z1) + y2->distance(x2) + y1->distance(z2)+0.01;
                    double case6Distance = x1->distance(y2) + z1->distance(y1) + x2->distance(z2)+0.01;
                    double case7Distance = x1->distance(y2) + z1->distance(x2) + y1->distance(z2)+0.01;
                    
                    
                    if (case1Distance < currentDistance) {
                        reverseSegment(x1, x2, z1, z2);
                        didSwap = true;
                    }
                    else if (case2Distance < currentDistance) {
                        reverseSegment(y1, y2, z1, z2);
                        didSwap = true;
                    }
                    else if (case3Distance < currentDistance) {
                        reverseSegment(x1, x2, y1, y2);
                        didSwap = true;
                    }
                    else if (case4Distance < currentDistance) {
                        reverseSegment(y1, y2, z1, z2);
                        reverseSegment(x1, x1->nextPoint, y1, y1->nextPoint);
                        didSwap = true;
                    }
                    else if (case5Distance < currentDistance) {
                        reverseSegment(x1, x2, y1, y2);
                        reverseSegment(x1, x1->nextPoint, z1, z1->nextPoint);
                        didSwap = true;
                    }
                    else if (case6Distance < currentDistance) {
                        reverseSegment(z1, z2, x1, x2);
                        reverseSegment(y1, y1->nextPoint, z1, z1->nextPoint);
                        didSwap = true;
                    }
                    else if (case7Distance < currentDistance) {
                        reverseSegment(z1, z2, x1, x2);
                        reverseSegment(x1, x1->nextPoint, y1, y1->nextPoint);
                        reverseSegment(y1, y1->nextPoint, z1, z1->nextPoint);
                        didSwap = true;
                        
                    }

                    
                    if (didSwap) {
                        break;
                        //return didSwap;
                    }
                    z1 = z1->nextPoint;
                }
                if(is_break) break;
                y1 = y1->nextPoint;
            }
            //if (didSwap) break;
            
            

            x1 = x1->nextPoint;
        }

        return didSwap;
    }

    bool reverseSegment(Point *x1, Point *x2, Point *y1, Point *y2) {
        std::stack<Point*> toReverse;
        toReverse.push(x2);
        while (true) {
            Point *next = toReverse.top()->nextPoint;
            toReverse.push(next);
            if(next == y1) {
                break;
            }
        }
        while(toReverse.size() > 1) {
            Point *p = toReverse.top();
            toReverse.pop();
            p->nextPoint = toReverse.top();
        }
        x1->nextPoint = y1;
        x2->nextPoint = y2;
        
        return true;
    }

};
#endif
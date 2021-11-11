#ifndef HEURISTICMST_H
#define HEURISTICMST_H

#include <float.h>
#include "ProblemInstance.h"

class HeuristicMST {
    public:
    void computeSolution(ProblemInstance *instance, int start ) {
        bool visited[instance->n] = {false};
        start = start%instance->n;
        int currentPointIndex = start;

        // Find greedy path (closest node everytime)
        for (int i = 0; i < instance->n; i++) {
            visited[currentPointIndex] = true;
            double bestCost = DBL_MAX;
            int bestIndex = start;
            for (int j = 0; j < instance->n; j++) {
                if (visited[j]) continue;


                double cost = instance->points[currentPointIndex]->distance(instance->points[j]);
                if (cost < bestCost) {
                    bestCost = cost;
                    bestIndex = j;
                }
                
            }

            if (bestIndex == -1) continue;
            instance->points[currentPointIndex]->nextPoint = instance->points[bestIndex];
            currentPointIndex = bestIndex;

        }
    }
};
#endif
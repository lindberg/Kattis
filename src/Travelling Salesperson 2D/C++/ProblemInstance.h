#ifndef PROBLEMINSTANCE_H
#define PROBLEMINSTANCE_H
#include "Point.h"

struct Tour {
    int indexes[1000];
    int n;

    Tour(int n) {
        this->n = n;
    }
};

class ProblemInstance {
    public:
    int n;
    Point *points[1000]; // n <= 1000

    ProblemInstance(int n, Point *points[]) {
        this->n = n;
        
        for (int i = 0; i < n; i++) {
            this->points[i] = points[i];
        }
        
    }

    long totalDistance() {
        
        long distance = 0;
        Point *first = points[0];
        Point *current = first;
        do {
            distance += current->distance(current->nextPoint);
            current = current->nextPoint;
        } while(*current != *first);
        
        
        return distance;
    }
    

    void printTour() {
        Point *first = this->points[0];
        Point *current = first;
        int i = 0;
        do {
            std::cout << current->index << "\n";
            current = current->nextPoint;
            i++;
        } while(current != first);
    }
    

    void tour(int t[]) {
        Point *first = this->points[0];
        Point *current = first;
        int i = 0;
        do {
            t[i] = current->index;
            current = current->nextPoint;
            i++;
        } while(current != first);
    }
    
};
#endif
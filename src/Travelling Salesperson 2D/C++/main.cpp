#include <iostream>
#include <algorithm>
#include "Point.h"
#include "ProblemInstance.h"
#include "HeuristicMST.h"
#include "Optimization2opt.h"
#include "Optimization3opt.h"

int main() {
    int n;
    std::cin >> n;

    Point *points[n];

    for (int i = 0; i < n; i++) {
        double x;
        double y;
        std::cin >> x;
        std::cin >> y;
        points[i] = new Point(x, y, i);
    }

    ProblemInstance instance = ProblemInstance(n, points);
    
    HeuristicMST heuristic;
    Optimization3opt optimization;
    
    int iterations = 50;

    heuristic.computeSolution(&instance, 0);
    optimization.optimize(&instance);

    
    int bestTour[instance.n];
    //System.out.println("test2");
    double step = n / (double)iterations;
    double bestDistance = instance.totalDistance();
    instance.tour(bestTour);


    
    for (int i = 1; i <= iterations; i++) {
        heuristic.computeSolution(&instance, (int)std::floor(i * step));
        optimization.optimize(&instance);
        double newDistance = instance.totalDistance();
        if (newDistance < bestDistance) {
            bestDistance = newDistance;
            instance.tour(bestTour);
            //std::cout << "test: \n";
        }
    }
    
    for (int i = 0; i < instance.n; i++) {
        std::cout << bestTour[i] << "\n";
    }

    //instance.printTour();

    return 0;
}
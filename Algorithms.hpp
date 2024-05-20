//214695108 shakedshvartz2004@gmail.com
#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP
#include <iostream>
#include <vector>
#include "Graph.hpp"

namespace ariel {
    class Algorithms {
    public:
        static bool isConnected(Graph g);
        static std::string shortestPath(Graph g, size_t src, size_t dest);
        static bool isContainsCycle(Graph g);
        static bool cycledfs(Graph g, size_t v, vector<int> color, vector<size_t> parent,size_t par);
        static std::string isBipartite(Graph g);
        static std::string negativeCycle(Graph g);
    };
}
#endif
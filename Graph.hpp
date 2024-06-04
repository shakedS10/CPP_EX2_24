//214695108 shakedshvartz2004@gmail.com

#ifndef GRAPH_HPP
#pragma once
#define GRAPH_HPP
#include <vector>
#include <iostream>
using namespace std;
namespace ariel {
    class Graph {
    protected:
        size_t n;
        std::vector<std::vector<int>> g;
        int edgecounter = 0;
        int graphtype; // 0 = directed, 1 = undirected

    public:
        Graph(){
            this->n = 0;
            this->edgecounter = 0;
            this->graphtype = 1;
            this->g = std::vector<std::vector<int>>();

        }
        void loadGraph(std::vector<std::vector<int>> graph);
        string printGraph();
        size_t getN();
        std::vector<std::vector<int>> getGraph();
        int getgraphtype(){
            return this->graphtype;
        }
        Graph operator+( Graph& other);
        Graph& operator+=( Graph& other);
        Graph operator+();
        Graph& operator++();
        Graph operator++(int);
        Graph operator-();
        Graph& operator-=( Graph& other);
        Graph operator-(  Graph& other);
        Graph& operator--( );
        Graph operator--(int);
        Graph operator*( Graph& other);
        Graph& operator*=( Graph& other);
        Graph& operator*=(int n);
        friend Graph operator*( int n, Graph& other);
        friend Graph operator*( Graph& other, int n); //both cases
         bool operator==(  Graph& other);
         bool operator!=(  Graph& other);
         bool operator>(  Graph& other);
         bool operator<(  Graph& other);
         bool operator>=(  Graph& other);
         bool operator<=(  Graph& other);
         friend ostream& operator<<(ostream& os,  Graph& g);
         Graph& operator/= (int n);




        

    };
    int gComperator(Graph& g1, Graph& g2);
}

#endif
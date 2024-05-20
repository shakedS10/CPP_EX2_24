//214695108 shakedshvartz2004@gmail.com
#include <iostream>
#include <vector>
#include "Graph.hpp"
using namespace std;
using namespace ariel;


        void Graph::loadGraph(std::vector<std::vector<int>> graph) {
            
            if(graph.size() == 0){
                throw std::invalid_argument("Graph is empty");
            }
            if (graph.size() != graph[0].size())
            {
                throw std::invalid_argument("Graph is not a square matrix");
            }
            this->edgecounter = 0;
            this->graphtype = 1;
            this->n = graph.size();
            for (size_t i = 0; i < n; i++)
            {
                for (size_t j = 0; j < n; j++)
                {
                    if (graph[i][j] != 0 )
                    {
                        if(i == j){
                            graph[i][j] = 0;
                        }
                        this->edgecounter++;
                        if (graph[i][j] != graph[j][i])
                        {
                            this->graphtype = 0;
                        }
                        
                        
                    }
                }
            }
            this->g = graph;
        
        }
        

        void Graph::printGraph() {
            std::cout << "Graph with " << n << " vertices and " << edgecounter << " edges." << std::endl;
        }

        size_t ariel::Graph::getN() {
            return this->n;
        }

        std::vector<std::vector<int>> ariel::Graph::getGraph() {
            return this->g;
        }


        Graph ariel::operator+( Graph& cur, Graph& other){
            if(cur.getN() != other.getN()){
                throw std::invalid_argument("Graphs are not the same size");
            }
            std::vector<std::vector<int>> nG=cur.getGraph();
            for (size_t i = 0; i < cur.getN(); i++)
            {
                for (size_t j = 0; j < cur.getN(); j++)
                {
                    nG[i][j] = 0;
                    nG[i][j] = (cur.getGraph()[i][j] + other.getGraph()[i][j]);
                }
            }
            Graph newg;
            newg.loadGraph(nG);
            return newg;
        }

        void ariel::operator+=( Graph& cur, Graph& other){
            if(cur.getN() != other.getN()){
                throw std::invalid_argument("Graphs are not the same size");
            }
            std::vector<std::vector<int>> nG=cur.getGraph();
            for (size_t i = 0; i < cur.getN(); i++)
            {
                for (size_t j = 0; j < cur.getN(); j++)
                {
                    nG[i][j] = 0;
                    nG[i][j] = (cur.getGraph()[i][j] + other.getGraph()[i][j]);
                }
            }
            cur.loadGraph(nG);
        }

        Graph ariel::operator+( Graph& cur){
            std::vector<std::vector<int>> nG=cur.getGraph();
            for (size_t i = 0; i < cur.getN(); i++)
            {
                for (size_t j = 0; j < cur.getN(); j++)
                {
                    nG[i][j] = 0;
                    nG[i][j] = (cur.getGraph()[i][j] + cur.getGraph()[i][j]);
                }
            }
            Graph newg;
            newg.loadGraph(nG);
            return newg;
        }

        void ariel::operator++( Graph& cur){
            std::vector<std::vector<int>> nG=cur.getGraph();
            for (size_t i = 0; i < cur.getN(); i++)
            {
                for (size_t j = 0; j < cur.getN(); j++)
                {
                    nG[i][j] = 0;
                    nG[i][j] = (cur.getGraph()[i][j] + 1);
                }
            }
            cur.loadGraph(nG);
        }

        Graph ariel::operator-( Graph& cur){
            std::vector<std::vector<int>> nG=cur.getGraph();
            for (size_t i = 0; i < cur.getN(); i++)
            {
                for (size_t j = 0; j < cur.getN(); j++)
                {
                    nG[i][j] = 0;
                    nG[i][j] = (cur.getGraph()[i][j] * -1);
                }
            }
            Graph newg;
            newg.loadGraph(nG);
            return newg;
        }

        void ariel::operator-=( Graph& cur, Graph& other){
            if(cur.getN() != other.getN()){
                throw std::invalid_argument("Graphs are not the same size");
            }
            std::vector<std::vector<int>> nG=cur.getGraph();
            for (size_t i = 0; i < cur.getN(); i++)
            {
                for (size_t j = 0; j < cur.getN(); j++)
                {
                    nG[i][j] = 0;
                    nG[i][j] = (cur.getGraph()[i][j] - other.getGraph()[i][j]);
                }
            }
            cur.loadGraph(nG);
        }

        Graph ariel::operator-( Graph& cur, Graph& other){
            if(cur.getN() != other.getN()){
                throw std::invalid_argument("Graphs are not the same size");
            }
            std::vector<std::vector<int>> nG=cur.getGraph();
            for (size_t i = 0; i < cur.getN(); i++)
            {
                for (size_t j = 0; j < cur.getN(); j++)
                {
                    nG[i][j] = 0;
                    nG[i][j] = (cur.getGraph()[i][j] - other.getGraph()[i][j]);
                }
            }
            Graph newg;
            newg.loadGraph(nG);
            return newg;
        }

        void ariel::operator--( Graph& cur){
            std::vector<std::vector<int>> nG=cur.getGraph();
            for (size_t i = 0; i < cur.getN(); i++)
            {
                for (size_t j = 0; j < cur.getN(); j++)
                {
                    nG[i][j] = 0;
                    nG[i][j] = (cur.getGraph()[i][j] - 1);
                }
            }
            cur.loadGraph(nG);
        }

        Graph ariel::operator*( Graph& cur, Graph& other){
            if(cur.getN() != other.getN()){
                throw std::invalid_argument("Graphs are not the same size");
            }
            std::vector<std::vector<int>> nG=cur.getGraph();
            for (size_t i = 0; i < cur.getN(); i++)
            {
                for (size_t j = 0; j < cur.getN(); j++)
                {
                    nG[i][j] = 0;
                    for (size_t k = 0; k < cur.getN(); k++)
                    {
                        nG[i][j] += cur.getGraph()[i][k] * other.getGraph()[k][j];
                    }
                }
            }
            Graph newg;
            newg.loadGraph(nG);
            return newg;
        }

        void ariel::operator*=( Graph& cur, Graph& other){
            if(cur.getN() != other.getN()){
                throw std::invalid_argument("Graphs are not the same size");
            }
            std::vector<std::vector<int>> nG=cur.getGraph();
            for (size_t i = 0; i < cur.getN(); i++)
            {
                for (size_t j = 0; j < cur.getN(); j++)
                {
                    for (size_t k = 0; k < cur.getN(); k++)
                    {
                        nG[i][j] = 0;
                        nG[i][j] += cur.getGraph()[i][k] * other.getGraph()[k][j];
                    }
                }
            }
            cur.loadGraph(nG);
        }

        void ariel::operator*=( Graph& cur,int n){
            std::vector<std::vector<int>> nG=cur.getGraph();
            for (size_t i = 0; i < cur.getN(); i++)
            {
                for (size_t j = 0; j < cur.getN(); j++)
                {
                    nG[i][j] = 0;
                    nG[i][j] = (cur.getGraph()[i][j] * n);
                }
            }
            cur.loadGraph(nG);
        }

        Graph ariel::operator*( Graph& cur,int n){
            std::vector<std::vector<int>> nG=cur.getGraph();
            for (size_t i = 0; i < cur.getN(); i++)
            {
                for (size_t j = 0; j < cur.getN(); j++)
                {
                    nG[i][j] = 0;
                    nG[i][j] = (cur.getGraph()[i][j] * n);
                }
            }
            Graph newg;
            newg.loadGraph(nG);
            return newg;
        }

        bool ariel::operator==( Graph& cur, Graph& other){
            if(cur.getN() != other.getN()){
                return false;
            }
            for (size_t i = 0; i < cur.getN(); i++)
            {
                for (size_t j = 0; j < cur.getN(); j++)
                {
                    if(cur.getGraph()[i][j] != other.getGraph()[i][j]){
                        return false;
                    }
                }
            }
            return true;
        }

        void ariel::operator/=( Graph& cur,int n){
            std::vector<std::vector<int>> nG=cur.getGraph();
            for (size_t i = 0; i < cur.getN(); i++)
            {
                for (size_t j = 0; j < cur.getN(); j++)
                {
                    nG[i][j] = 0;
                    nG[i][j] = (cur.getGraph()[i][j] / n);
                }
            }
            cur.loadGraph(nG);
        }

        bool ariel::operator!=( Graph& cur, Graph& other){
            if(cur.getN() != other.getN()){
                return true;
            }
            for (size_t i = 0; i < cur.getN(); i++)
            {
                for (size_t j = 0; j < cur.getN(); j++)
                {
                    if(cur.getGraph()[i][j] != other.getGraph()[i][j]){
                        return true;
                    }
                }
            }
            return false;
        }

        bool ariel::operator>( Graph& cur, Graph& other){
            if(cur.getN() != other.getN()){
                return false;
            }
            for (size_t i = 0; i < cur.getN(); i++)
            {
                for (size_t j = 0; j < cur.getN(); j++)
                {
                    if(cur.getGraph()[i][j] <= other.getGraph()[i][j]){
                        return false;
                    }
                }
            }
            return true;
        }

        bool ariel::operator<( Graph& cur, Graph& other){
            if(cur.getN() != other.getN()){
                return false;
            }
            for (size_t i = 0; i < cur.getN(); i++)
            {
                for (size_t j = 0; j < cur.getN(); j++)
                {
                    if(cur.getGraph()[i][j] >= other.getGraph()[i][j]){
                        return false;
                    }
                }
            }
            return true;
        }

        bool ariel::operator>=( Graph& cur, Graph& other){
            if(cur.getN() != other.getN()){
                return false;
            }
            for (size_t i = 0; i < cur.getN(); i++)
            {
                for (size_t j = 0; j < cur.getN(); j++)
                {
                    if(cur.getGraph()[i][j] < other.getGraph()[i][j]){
                        return false;
                    }
                }
            }
            return true;
        }
        
        bool ariel::operator<=( Graph& cur, Graph& other){
            if(cur.getN() != other.getN()){
                return false;
            }
            for (size_t i = 0; i < cur.getN(); i++)
            {
                for (size_t j = 0; j < cur.getN(); j++)
                {
                    if(cur.getGraph()[i][j] > other.getGraph()[i][j]){
                        return false;
                    }
                }
            }
            return true;
        }

        ostream& ariel::operator<<(ostream& os,  Graph& g){
            os << std::endl;
            for (size_t i = 0; i < g.getN(); i++)
            {
                os<<"[";
                for (size_t j = 0; j < g.getN(); j++)
                {
                    os << g.getGraph()[i][j] << " ";
                }
                os << "]";
                os << std::endl;
            }
            return os;
        }



  
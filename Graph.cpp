//214695108 shakedshvartz2004@gmail.com
#include <iostream>
#include <vector>
#include "Graph.hpp"
using namespace std;
namespace ariel{

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
        

        string Graph::printGraph() {
            string s = "";
            for (size_t i = 0; i < this->getN(); i++)
            {
                s +="[";
                s += to_string(this->getGraph()[i][0]);
                for (size_t j = 1; j < this->getN(); j++)
                {
                    s+=", ";
                    s += to_string(this->getGraph()[i][j]);
                }
                s += "]";
                s += '\n';
            }
            cout << s;
            return s;
        }

        size_t ariel::Graph::getN() {
            return this->n;
        }

        std::vector<std::vector<int>> ariel::Graph::getGraph() {
            return this->g;
        }


        Graph Graph::operator+(Graph& other){
            if(this->getN() != other.getN()){
                throw std::invalid_argument("Invalid graph size");
            }
            std::vector<std::vector<int>> nG = this->getGraph();
            for (size_t i = 0; i < this->getN(); i++)
            {
                for (size_t j = 0; j < this->getN(); j++)
                {
                    nG[i][j] = 0;
                    nG[i][j] = (this->getGraph()[i][j] + other.getGraph()[i][j]);
                }
            }
            Graph newg;
            newg.loadGraph(nG);
            return newg;
        }

        Graph& Graph::operator+=( Graph& other){
            if(this->getN() != other.getN()){
                throw std::invalid_argument("Invalid graph size");
            }
            std::vector<std::vector<int>> nG =this->getGraph();
            for (size_t i = 0; i < this->getN(); i++)
            {
                for (size_t j = 0; j < this->getN(); j++)
                {
                    nG[i][j] = 0;
                    nG[i][j] = (this->getGraph()[i][j] + other.getGraph()[i][j]);
                }
            }
            this->loadGraph(nG);
            return *this;
        }

        Graph Graph::operator+(){
            std::vector<std::vector<int>> nG=this->getGraph();
            Graph newg;
            newg.loadGraph(nG);
            return newg;
        }

        Graph& Graph::operator++(){
            std::vector<std::vector<int>> nG =this->getGraph();
            for (size_t i = 0; i < this->getN(); i++)
            {
                for (size_t j = 0; j < this->getN(); j++)
                {
                    nG[i][j] = 0;
                    if(this->getGraph()[i][j] != 0){
                        nG[i][j] = (this->getGraph()[i][j] + 1);
                    }
                }
            }
            this->loadGraph(nG);
            return *this;
        }

        Graph Graph::operator++(int){
            std::vector<std::vector<int>> nG =this->getGraph();
            for (size_t i = 0; i < this->getN(); i++)
            {
                for (size_t j = 0; j < this->getN(); j++)
                {
                    nG[i][j] = 0;
                    if(this->getGraph()[i][j] != 0){
                        nG[i][j] = (this->getGraph()[i][j] + 1);
                    }
                }
            }
            Graph newg;
            newg.loadGraph(nG);
            this->loadGraph(nG);
            return newg;
        }

        Graph Graph::operator-(){
            std::vector<std::vector<int>> nG =this->getGraph();
            for (size_t i = 0; i < this->getN(); i++)
            {
                for (size_t j = 0; j < this->getN(); j++)
                {
                    nG[i][j] = 0;
                    nG[i][j] = (this->getGraph()[i][j] * -1);
                }
            }
            Graph newg;
            newg.loadGraph(nG);
            return newg;
        }

        Graph& Graph::operator-=( Graph& other){
            if(this->getN() != other.getN()){
                throw std::invalid_argument("Invalid graph size");
            }
            std::vector<std::vector<int>> nG =this->getGraph();
            for (size_t i = 0; i < this->getN(); i++)
            {
                for (size_t j = 0; j < this->getN(); j++)
                {
                    nG[i][j] = 0;
                    nG[i][j] = (this->getGraph()[i][j] - other.getGraph()[i][j]);
                }
            }
            this->loadGraph(nG);
            return *this;
        }

        Graph Graph::operator-( Graph& other){
            if(this->getN() != other.getN()){
                throw std::invalid_argument("Invalid graph size");
            }
            std::vector<std::vector<int>> nG =this->getGraph();
            for (size_t i = 0; i < this->getN(); i++)
            {
                for (size_t j = 0; j < this->getN(); j++)
                {
                    nG[i][j] = 0;
                    nG[i][j] = (this->getGraph()[i][j] - other.getGraph()[i][j]);
                }
            }
            Graph newg;
            newg.loadGraph(nG);
            return newg;
        }

        Graph& Graph::operator--(){
            std::vector<std::vector<int>> nG =this->getGraph();
            for (size_t i = 0; i < this->getN(); i++)
            {
                for (size_t j = 0; j < this->getN(); j++)
                {
                    nG[i][j] = 0;
                    if(this->getGraph()[i][j] != 0){
                        nG[i][j] = (this->getGraph()[i][j] - 1);
                    }
                    
                }
            }
            this->loadGraph(nG);
            return *this;
        }

        Graph Graph::operator--(int){
            std::vector<std::vector<int>> nG =this->getGraph();
            for (size_t i = 0; i < this->getN(); i++)
            {
                for (size_t j = 0; j < this->getN(); j++)
                {
                    nG[i][j] = 0;
                    if(this->getGraph()[i][j] != 0){
                        nG[i][j] = (this->getGraph()[i][j] - 1);
                    }
                }
            }
            Graph newg;
            newg.loadGraph(nG);
            this->loadGraph(nG);
            return newg;
        }

        Graph Graph::operator*( Graph& other){
            if(this->getN() != other.getN()){
                throw std::invalid_argument("Invalid graph size");
            }
            size_t n = this->getN();
            std::vector<std::vector<int>> nG(n, std::vector<int>(n, 0));
            for (size_t i = 0; i < this->getN(); i++)
            {
                for (size_t j = 0; j < this->getN(); j++)
                {
                    for (size_t k = 0; k < this->getN(); k++)
                    {
                        nG[i][j] += this->getGraph()[i][k] * other.getGraph()[k][j];
                    }
                }
            }
            Graph newg;
            newg.loadGraph(nG);
            return newg;
        }

        Graph& Graph::operator*=( Graph& other){
            if(this->getN() != other.getN()){
                throw std::invalid_argument("Invalid graph size");
            }
            size_t n = this->getN();
            std::vector<std::vector<int>> nG(n, std::vector<int>(n, 0));
            for (size_t i = 0; i < this->getN(); i++)
            {
                for (size_t j = 0; j < this->getN(); j++)
                {
                    for (size_t k = 0; k < this->getN(); k++)
                    {
                        nG[i][j] += this->getGraph()[i][k] * other.getGraph()[k][j];
                    }
                }
            }
            this->loadGraph(nG);
            return *this;
        }

        Graph& Graph::operator*=(int n){
            std::vector<std::vector<int>> nG =this->getGraph();
            for (size_t i = 0; i < this->getN(); i++)
            {
                for (size_t j = 0; j < this->getN(); j++)
                {
                    nG[i][j] = 0;
                    nG[i][j] = (this->getGraph()[i][j] * n);
                }
            }
            this->loadGraph(nG);
            return *this;
        }

        Graph operator*(int n, Graph& other){
            std::vector<std::vector<int>> nG =other.getGraph();
            for (size_t i = 0; i < other.getN(); i++)
            {
                for (size_t j = 0; j < other.getN(); j++)
                {
                    nG[i][j] = 0;
                    nG[i][j] = (other.getGraph()[i][j] * n);
                }
            }
            Graph newg;
            newg.loadGraph(nG);
            return newg;
        }

        Graph operator*( Graph& other, int n){
            std::vector<std::vector<int>> nG =other.getGraph();
            for (size_t i = 0; i < other.getN(); i++)
            {
                for (size_t j = 0; j < other.getN(); j++)
                {
                    nG[i][j] = 0;
                    nG[i][j] = (other.getGraph()[i][j] * n);
                }
            }
            Graph newg;
            newg.loadGraph(nG);
            return newg;
        }


        int gComperator(Graph& g1, Graph& g2){
            int checkcontain = 1;
            bool checkequal = true;
            if(g1.getN()==g2.getN()){
                for (size_t i = 0; i < g1.getN(); i++)
                {
                    for (size_t j = 0; j < g1.getN(); j++)
                    {
                        if(g1.getGraph()[i][j] != g2.getGraph()[i][j]){
                            checkequal = false;
                        }
                    }
                }
                if(checkequal){
                    return 0;
                }
            }
            else if(g1.getN()>g2.getN()){
                for(size_t i = 0 ;i< g1.getN()- g2.getN();i++){
                    for(size_t j = 0 ;j< g2.getN();j++){
                        for (size_t i = 0; i < g2.getN(); i++)
                        {
                            if(g1.getGraph()[i][j] != g2.getGraph()[i][j]){
                                checkcontain = 0;
                            }
                        }
                        
                    }
                }
                if(checkcontain == 1){
                    return 1;
                }
            }
            else{
                checkcontain = -1;
                for(size_t i = 0 ;i< g2.getN()- g1.getN();i++){
                    for(size_t j = 0 ;j< g1.getN();j++){
                        for (size_t i = 0; i < g1.getN(); i++)
                        {
                            if(g1.getGraph()[i][j] != g2.getGraph()[i][j]){
                                checkcontain = 0;
                            }
                        }
                        
                    }
                }
                if(checkcontain == -1){
                    return -1;
                }
            }   
            int g1vertices = 0;
            int g2vertices = 0;
            for(size_t i = 0 ;i< g1.getN();i++){
                for(size_t j = 0 ;j< g1.getN();j++){
                    if(g1.getGraph()[i][j] != 0){
                        g1vertices++;
                    }
                }
            }
            for(size_t i = 0 ;i< g2.getN();i++){
                for(size_t j = 0 ;j< g2.getN();j++){
                    if(g2.getGraph()[i][j] != 0){
                        g2vertices++;
                    }
                }
            }
            if(g1vertices>g2vertices){
                return 1;
            }
            else if(g1vertices<g2vertices){
                return -1;
            }
            return 0;
        

            
        }


        bool Graph::operator==( Graph& other){
            if(gComperator(*this, other) == 0){
                return true;
            }
            return false;
        }

        bool Graph::operator!=( Graph& other){
            if(gComperator(*this, other) != 0){
                return true;
            }
            return false;
        }

        bool Graph::operator>( Graph& other){
            if(gComperator(*this, other) == 1){
                return true;
            }
            return false;
        }

        bool Graph::operator<( Graph& other){
            if(gComperator(*this, other) == -1){
                return true;
            }
            return false;
        }

        bool Graph::operator>=( Graph& other){
           if(gComperator(*this, other) == 1 || gComperator(*this, other) == 0){
                return true;
            }
            return false;
        }

        bool Graph::operator<=( Graph& other){
            if(gComperator(*this, other) == -1 || gComperator(*this, other) == 0){
                return true;
            }
            return false;
        }

        ostream& operator<<(ostream& os, Graph& g){
            for (size_t i = 0; i < g.getN(); i++)
            {
                os << "[ ";
                for (size_t j = 0; j < g.getN(); j++)
                {
                    os << g.getGraph()[i][j] << " ";
                }
                os << "]";
                os << std::endl;
            }
            return os;
        }

        Graph& Graph::operator/=(int n){
            if(n == 0){
                throw std::invalid_argument("Can't divide by 0");
            }
            std::vector<std::vector<int>> nG =this->getGraph();
            for (size_t i = 0; i < this->getN(); i++)
            {
                for (size_t j = 0; j < this->getN(); j++)
                {
                    nG[i][j] = 0;
                    nG[i][j] = (this->getGraph()[i][j] / n);
                }
            }
            this->loadGraph(nG);
            return *this;
        }
        


}



  
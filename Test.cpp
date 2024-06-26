//214695108 shakedshvartz2004@gmail.com
#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test graph addition")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 + g2;
    vector<vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    CHECK(g3.printGraph() == "[0, 2, 1]\n[2, 0, 3]\n[1, 3, 0]\n");
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    ariel::Graph g4;
    g4.loadGraph(graph2);
    CHECK_THROWS(g1 + g4);
    vector<vector<int>> graph3 = {
        {0,0,0},
        {0,0,0},
        {0,0,0}};
    ariel::Graph g5;
    g5.loadGraph(graph3);
    g5+=g1;
    CHECK(g5.printGraph() == g1.printGraph());
    g1 = +g1;
    CHECK(g5.printGraph() == g1.printGraph());
    ariel::Graph g6;
    g6.loadGraph(graph3);
    ++g6;
    CHECK(g6.printGraph() == g6.printGraph());
    ++g4;
    CHECK(g4.printGraph() =="[0, 2, 0, 0, 2]\n[2, 0, 2, 0, 0]\n[0, 2, 0, 2, 0]\n[0, 0, 2, 0, 2]\n[2, 0, 0, 2, 0]\n");
    g4++;
    CHECK(g4.printGraph()== "[0, 3, 0, 0, 3]\n[3, 0, 3, 0, 0]\n[0, 3, 0, 3, 0]\n[0, 0, 3, 0, 3]\n[3, 0, 0, 3, 0]\n");

}
TEST_CASE("Test graph subtraction")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g2 - g1;
    vector<vector<int>> expectedGraph = {
        {0, 0, 1},
        {0, 0, 1},
        {1, 1, 0}};
    CHECK(g3.printGraph() == "[0, 0, 1]\n[0, 0, 1]\n[1, 1, 0]\n");
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    ariel::Graph g4;
    g4.loadGraph(graph2);
    CHECK_THROWS(g1 - g4);
    vector<vector<int>> graph3 = {
        {0,0,0},
        {0,0,0},
        {0,0,0}};
    ariel::Graph g5;
    g5.loadGraph(graph3);
    g5-=g1;
    g1 = -g1;
    CHECK(g5.printGraph() == g1.printGraph());
    g4--;
    CHECK(g4.printGraph() == "[0, 0, 0, 0, 0]\n[0, 0, 0, 0, 0]\n[0, 0, 0, 0, 0]\n[0, 0, 0, 0, 0]\n[0, 0, 0, 0, 0]\n");
    ariel::Graph g6;
    g6.loadGraph(graph2);
    --g6;
    CHECK(g4.printGraph() == "[0, 0, 0, 0, 0]\n[0, 0, 0, 0, 0]\n[0, 0, 0, 0, 0]\n[0, 0, 0, 0, 0]\n[0, 0, 0, 0, 0]\n");

}

TEST_CASE("Test graph multiplication")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g4 = g1 * g2;
    vector<vector<int>> expectedGraph = {
        {0, 0, 2},
        {1, 0, 1},
        {1, 0, 0}};
    CHECK(g4.printGraph() == "[0, 0, 2]\n[1, 0, 1]\n[1, 0, 0]\n");
    vector<vector<int>> graph3 = {
        {0,0,0},
        {0,0,0},
        {0,0,0}};
    ariel::Graph g5;
    g5.loadGraph(graph3);
    g1*=g5;
    CHECK(g1.printGraph() == g5.printGraph());
}

TEST_CASE("division by integer")
{


    ariel::Graph g2;
    vector<vector<int>> expectedGraph = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    g2.loadGraph(expectedGraph);
    g2/= 2;
    CHECK(g2.printGraph() == "[0, 0, 0]\n[0, 0, 0]\n[0, 0, 0]\n");
    ariel::Graph g3;
    vector<vector<int>> expectedGraph2 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g3.loadGraph(expectedGraph2);
    CHECK_THROWS(g3/=0);
    g3/=2;
    CHECK(g3.printGraph() == "[0, 0, 0]\n[0, 0, 0]\n[0, 0, 0]\n");
    ariel::Graph g4;
    vector<vector<int>> expectedGraph3 = {
        {0, 6, 6},
        {6, 0, 6},
        {6, 6, 0}};
    g4.loadGraph(expectedGraph3);
    g4/=3;
    CHECK(g4.printGraph() == "[0, 2, 2]\n[2, 0, 2]\n[2, 2, 0]\n");
}

TEST_CASE("Invalid operations")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1, 1},
        {1, 0, 2, 1},
        {1, 2, 0, 1},
        {1, 1, 1, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g5;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph2);
    CHECK_THROWS(g5 * g1);
    CHECK_THROWS(g1 * g2);

    // Addition of two graphs with different dimensions
    ariel::Graph g6;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g6.loadGraph(graph3);
    CHECK_THROWS(g1 + g6);
}

TEST_CASE("boolen operations")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);

    ariel::Graph g3 = g1 + g2;
    ariel::Graph g4 = g1 * g2;
    ariel::Graph g5 = g1 + g2;
    ariel::Graph g6 = g1 * g2;
    CHECK(g3 == g5);
    CHECK(g4 == g6);
    CHECK(g3 != g4);
    CHECK(g3 > g4);
    CHECK(g4 < g3);
    CHECK(g3 >= g4);
    CHECK(g4 <= g3);
    CHECK((g4>g3) == false);
    CHECK((g3<g4) == false);
    CHECK((g4>=g3) == false);
    CHECK((g3<=g4) == false);
    CHECK(g3==g3);
}

TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);

    vector<vector<int>> graph3 = {
        {0, 0, 2, -5}, 
        {0, 0, 0, 0}, 
        {0, 1, 0, 0}, 
        {0, 2, 0, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isConnected(g) == false);

    vector<vector<int>> graph4 = {
        {0, 0, 2, -5}, 
        {1, 0, 1, 1}, 
        {0, 1, 0, 0}, 
        {0, 2, 0, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    vector<vector<int>> graph5 = {
        {0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::isConnected(g) == false);

}

TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");

    vector<vector<int>> graph3 = {
        {0, 0, 2, -5}, 
        {0, 0, 0, 0}, 
        {0, 1, 0, 0}, 
        {0, 2, 0, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "0->3");

    vector<vector<int>> graph4 = {
        {0, 0, 2, -5}, 
        {1, 0, 1, 1}, 
        {0, 1, 0, 0}, 
        {0, 2, 0, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "Negative cycle detected 3->1->0");
    
    vector<vector<int>> graph5 = {
        {0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");
}
TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);

    vector<vector<int>> graph3 = {
        {0, 0, 2, -5}, 
        {0, 0, 0, 0}, 
        {0, 1, 0, 0}, 
        {0, 2, 0, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);

    vector<vector<int>> graph4 = {
        {0, 0, 2, -5}, 
        {1, 0, 1, 1}, 
        {0, 1, 0, 0}, 
        {0, 2, 0, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
    
    vector<vector<int>> graph5 = {
        {0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);
    
}
TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}");

    vector<vector<int>> graph4 = {
        {0, 0, 2, -5}, 
        {1, 0, 1, 1}, 
        {0, 1, 0, 0}, 
        {0, 2, 0, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    vector<vector<int>> graph5 = {
        {0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}");
}

TEST_CASE("Negative cycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 0, 2, -5}, 
        {0, 0, 0, 0}, 
        {0, 1, 0, 0}, 
        {0, 2, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::negativeCycle(g) == "-1");

    vector<vector<int>> graph2 = {
        {0, 0, 2, -5}, 
        {1, 0, 1, 1}, 
        {0, 1, 0, 0}, 
        {0, 2, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::negativeCycle(g) == "3->1->0");
}

TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));

    vector<vector<int>> graph2 = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},};
    CHECK_THROWS(g.loadGraph(graph2));
}
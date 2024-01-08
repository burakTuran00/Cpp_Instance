#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Graph {
    unordered_map<int, unordered_set<int>> adjList;

public:
    void addEdge(int u, int v) {
        adjList[u].insert(v);
        adjList[v].insert(u);
    }

    unordered_map<int, string> graphColor(const vector<string> &colors) {
        unordered_map<int, string> nodeColors;

        for (auto it = adjList.begin(); it != adjList.end(); ++it) {
            int node = it->first;
            unordered_set<string> usedColors;

            for (int neighbor : adjList[node]) {
                if (nodeColors.find(neighbor) != nodeColors.end()) {
                    usedColors.insert(nodeColors[neighbor]);
                }
            }

            for (const string &color : colors) {
                if (usedColors.find(color) == usedColors.end()) {
                    nodeColors[node] = color;
                    break;
                }
            }
        }

        return nodeColors;
    }

    void printColoredNodes(const unordered_map<int, string> &coloredNodes) {
        if (coloredNodes.empty()) {
            cout << "List is empty" << endl;
        } else {
            cout << "{";
            for (const auto &pair : coloredNodes) {
                cout << pair.first << ":\"" << pair.second << "\",";
            }
            cout << "}" << endl;
        }
    }
};

int main() {
    Graph graph;
    graph.addEdge(0, 1);
    graph.addEdge(0, 3);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 5);
    graph.addEdge(3, 6);
    graph.addEdge(4, 5);
    graph.addEdge(4, 6);
    graph.addEdge(4, 7);
    graph.addEdge(4, 8);
    graph.addEdge(5, 8);
    graph.addEdge(7, 8);

    vector<string> colors = {"blue", "red", "green"};

    unordered_map<int, string> coloredNodes = graph.graphColor(colors);

    if (!coloredNodes.empty()) {
        graph.printColoredNodes(coloredNodes);
    } else {
        cout << "No valid coloring found." << endl;
    }

    return 0;
}

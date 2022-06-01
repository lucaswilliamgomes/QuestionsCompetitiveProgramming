#include <bits/stdc++.h>

using namespace std;


// Clique.cpp
// graph is a class member and is of type Graph
vector<Vertex> Coloring::findMaxClique() const noexcept {
    auto maxCliqueSize = 0;
    vector<Vertex> maxClique;
    vector<Vertex> tmpClique;

    VertexIt vertex, v_end;
    for (tie(vertex, v_end) = boost::vertices(graph); vertex != v_end; ++vertex) {
        if (boost::degree(*vertex, graph) >= maxCliqueSize) {
            tmpClique = findMaxCliqueWithVertex(*vertex, maxCliqueSize);

            if (tmpClique.size() >= 2 && static_cast<int>(tmpClique.size()) > maxCliqueSize) {
                maxClique = move(tmpClique);
                maxCliqueSize = static_cast<int>(maxClique.size());
            } else if (tmpClique.size() == maxClique.size()) {
                if (calculateDegreeSum(tmpClique) > calculateDegreeSum(maxClique)) {
                    maxClique = move(tmpClique);
                }
            }
        }
    }

    return maxClique;
}

inline int Coloring::calculateDegreeSum(const vector<Vertex> &clique) const noexcept {
    return accumulate(clique.begin(), clique.end(), 0, [this](int accumulator, const Vertex vertex) {
        return accumulator + boost::degree(vertex, graph);
    });
}

vector<Vertex> Coloring::findMaxCliqueWithVertex(const Vertex vertex, const int maxCliqueSize) const noexcept {
    vector<Vertex> clique;
    clique.reserve(maxCliqueSize);
    clique.emplace_back(vertex);

    vector<Vertex> candidateNeighbors;
    candidateNeighbors.reserve(maxCliqueSize);

    AdjacentIt adjVertex, adjVertEnd;
    for (tie(adjVertex, adjVertEnd) = boost::adjacent_vertices(vertex, graph); adjVertex != adjVertEnd; ++adjVertex) {
        candidateNeighbors.emplace_back(*adjVertex);
    }

    vector<Vertex> tmp;
    tmp.reserve(maxCliqueSize);

    while (!candidateNeighbors.empty()) {
        const auto highestDegNeighborIt = max_element(candidateNeighbors.begin(), candidateNeighbors.end(), [this](const Vertex &lhs, const Vertex &rhs) {
            return boost::degree(lhs,graph) < boost::degree(rhs,graph); 
        });

        const auto highestDegVert = *highestDegNeighborIt;
        clique.emplace_back(highestDegVert);

        for (tie(adjVertex, adjVertEnd) = boost::adjacent_vertices(highestDegVert, graph_); adjVertex != adjVertEnd; ++adjVertex) {
            if (find(candidateNeighbors.begin(), candidateNeighbors.end(), *adjVertex) != candidateNeighbors.end()) {
                tmp.emplace_back(*adjVertex);
            }
        }
        candidateNeighbors = move(tmp);
    }
    return clique;
}
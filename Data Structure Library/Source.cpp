#include "Graphlib.h"

//Hàm khởi tạo đồ thị vô hướng không trọng số
template<typename T>
Graph<T>::Graph(int vertices) : V(vertices)
{
    adjList.resize(V);
}

//Hàm hủy
template<typename T>
Graph<T>::~Graph() {}

//Thêm cạnh
template<typename T>
void Graph<T>::addEdge(T v, T w) {
    adjList[v].push_back(w);
    adjList[w].push_back(v);
}
//Hiển thị đỉnh của đồ thị
template<typename T>
void Graph<T>::displayVertex(T v) {
    cout << "Dinh " << v << ": ";
    for (const auto& neighbor : adjList[v]) {
        cout << "(" << v << ", " << neighbor << ") ";
    }
    cout << "\n";
}
//In ra đồ thị
template<typename T>
void Graph<T>::printGraph() {
    for (int i = 0; i < V; ++i) {
        displayVertex(i);
    }
}
//Kiểm tra sự tồn tại của một đỉnh
template<typename T>
bool Graph<T>::hasVertex(T v) {
    return (v >= 0 && v < V);
}
//Kiểm tra sự tồn tại của một cạnh
template<typename T>
bool Graph<T>::hasEdge(T v, T w) {
    if (hasVertex(v) && hasVertex(w)) {
        for (const auto& neighbor : adjList[v]) {
            if (neighbor == w) {
                return true;
            }
        }
    }
    return false;
}
//Xóa một đỉnh
template<typename T>
void Graph<T>::removeVertex(T v) {
    if (hasVertex(v)) {
        adjList.erase(adjList.begin() + v);

        for (auto& neighbors : adjList) {
            neighbors.erase(remove(neighbors.begin(), neighbors.end(), v), neighbors.end());
        }

        --V;
    }
}
//Xóa một cạnh
template<typename T>
void Graph<T>::removeEdge(T v, T w) {
    if (hasVertex(v) && hasVertex(w)) {
        adjList[v].erase(remove(adjList[v].begin(), adjList[v].end(), w), adjList[v].end());
        adjList[w].erase(remove(adjList[w].begin(), adjList[w].end(), v), adjList[w].end());
    }
}

template class Graph<int>;
template class Graph<double>;
template class Graph<long>;
template class Graph<float>;





//Hàm khởi tạo đồ thị có hướng không trọng số
template<typename T>
DirectedGraph<T>::DirectedGraph(int vertices) : V(vertices) {
    adjList.resize(V);
}
//Hàm hủy
template<typename T>
DirectedGraph<T>::~DirectedGraph() {}

//Thêm cạnh
template<typename T>
void DirectedGraph<T>::addEdge(T v, T w) {
    adjList[v].push_back(w);
}
//Hiển thị đỉnh của đồ thị
template<typename T>
void DirectedGraph<T>::displayVertex(T v) {
    std::cout << "Dinh " << v << ": ";
    for (const auto& neighbor : adjList[v]) {
        cout << "(" << v << ", " << neighbor << ") ";
    }
    cout << "\n";
}
//In ra đồ thị
template<typename T>
void DirectedGraph<T>::printGraph() {
    for (int i = 0; i < V; ++i) {
        displayVertex(i);
    }
}
//Kiểm tra sự tồn tại của một đỉnh
template<typename T>
bool DirectedGraph<T>::hasVertex(T v) {
    return (v >= 0 && v < V);
}
//Kiểm tra sự tồn tại của một cạnh
template<typename T>
bool DirectedGraph<T>::hasEdge(T v, T w) {
    if (hasVertex(v) && hasVertex(w)) {
        for (const auto& neighbor : adjList[v]) {
            if (neighbor == w) {
                return true;
            }
        }
    }
    return false;
}
//Xóa một đỉnh
template<typename T>
void DirectedGraph<T>::removeVertex(T v) {
    if (hasVertex(v)) {
        adjList.erase(adjList.begin() + v);

        for (auto& neighbors : adjList) {
            neighbors.erase(remove(neighbors.begin(), neighbors.end(), v), neighbors.end());
        }

        --V;
    }
}
//Xóa một cạnh
template<typename T>
void DirectedGraph<T>::removeEdge(T v, T w) {
    if (hasVertex(v) && hasVertex(w)) {
        adjList[v].erase(remove(adjList[v].begin(), adjList[v].end(), w), adjList[v].end());
    }
}
template class DirectedGraph<int>;
template class DirectedGraph<double>;
template class DirectedGraph<long>;
template class DirectedGraph<float>;


//Hàm khởi tạo đồ thị vô hướng có trọng số
template<typename T>
WeightedGraph<T>::WeightedGraph(int vertices) : V(vertices) {
    adjList.resize(V);
}
//Hàm hủy
template<typename T>
WeightedGraph<T>::~WeightedGraph() {}
//Thêm cạnh
template<typename T>
void WeightedGraph<T>::addEdge(T v, T w, T weight) {
    adjList[v].push_back(make_pair(w, weight));
    adjList[w].push_back(make_pair(v, weight));
}
//Kiểm tra sự tồn tại của một đỉnh
template<typename T>
bool WeightedGraph<T>::hasVertex(T v) {
    return (v >= 0 && v < V);
}
//Kiểm tra sự tồn tại của một cạnh
template<typename T>
bool WeightedGraph<T>::hasEdge(T v, T w) {
    if (hasVertex(v) && hasVertex(w)) {
        for (const auto& neighbor : adjList[v]) {
            if (neighbor.first == w) {
                return true;
            }
        }
    }
    return false;
}
//Xóa một đỉnh
template<typename T>
void WeightedGraph<T>::removeVertex(T v) {
    if (hasVertex(v)) {
        adjList.erase(adjList.begin() + v);

        for (auto& neighbors : adjList) {
            neighbors.erase(remove_if(neighbors.begin(), neighbors.end(), [v](const auto& pair) {
                return pair.first == v;
                }), neighbors.end());
        }

        --V;
    }
}
//Xóa một cạnh
template<typename T>
void WeightedGraph<T>::removeEdge(T v, T w) {
    if (hasVertex(v) && hasVertex(w)) {
        adjList[v].erase(remove_if(adjList[v].begin(), adjList[v].end(), [w](const auto& pair) {
            return pair.first == w;
            }), adjList[v].end());

        adjList[w].erase(remove_if(adjList[w].begin(), adjList[w].end(), [v](const auto& pair) {
            return pair.first == v;
            }), adjList[w].end());
    }
}
//Hiển thị đỉnh của đồ thị
template<typename T>
void WeightedGraph<T>::displayVertex(T v) {
    std::cout << "Dinh " << v << ": ";
    for (const auto& neighbor : adjList[v]) {
        cout << "(" << v << ", " << neighbor.first << ", " << neighbor.second << ") ";
    }
    cout << "\n";
}
//In ra đồ thị
template<typename T>
void WeightedGraph<T>::printGraph() {
    for (int i = 0; i < V; ++i) {
        displayVertex(i);
    }
}
template class WeightedGraph<int>;
template class WeightedGraph<long>;
template class WeightedGraph<float>;
template class WeightedGraph<double>;

//Hàm khởi tạo đồ thị có hướng có trọng số
template<typename T>
WeightedDirectedGraph<T>::WeightedDirectedGraph(int vertices) : V(vertices) {
    adjList.resize(V);
}
//Hàm hủy
template<typename T>
WeightedDirectedGraph<T>::~WeightedDirectedGraph() {}
//Thêm cạnh
template<typename T>
void WeightedDirectedGraph<T>::addEdge(T v, T w, T weight) {
    adjList[v].push_back(std::make_pair(w, weight));
}
//Kiểm tra sự tồn tại của một đỉnh
template<typename T>
bool WeightedDirectedGraph<T>::hasVertex(T v) {
    return (v >= 0 && v < V);
}
//Kiểm tra sự tồn tại của một cạnh
template<typename T>
bool WeightedDirectedGraph<T>::hasEdge(T v, T w) {
    if (hasVertex(v) && hasVertex(w)) {
        for (const auto& neighbor : adjList[v]) {
            if (neighbor.first == w) {
                return true;
            }
        }
    }
    return false;
}
//Xóa một đỉnh
template<typename T>
void WeightedDirectedGraph<T>::removeVertex(T v) {
    if (hasVertex(v)) {
        adjList.erase(adjList.begin() + v);

        for (auto& neighbors : adjList) {
            neighbors.erase(remove_if(neighbors.begin(), neighbors.end(), [v](const auto& pair) {
                return pair.first == v;
                }), neighbors.end());
        }

        --V;
    }
}
//Xóa một cạnh
template<typename T>
void WeightedDirectedGraph<T>::removeEdge(T v, T w) {
    if (hasVertex(v) && hasVertex(w)) {
        adjList[v].erase(remove_if(adjList[v].begin(), adjList[v].end(), [w](const auto& pair) {
            return pair.first == w;
            }), adjList[v].end());
    }
}
//Hiển thị đỉnh của đồ thị
template<typename T>
void WeightedDirectedGraph<T>::displayVertex(T v) {
    std::cout << "Dinh " << v << ": ";
    for (const auto& neighbor : adjList[v]) {
        cout << "(" << v << ", " << neighbor.first << ", " << neighbor.second << ") ";
    }
    cout << "\n";
}
//In ra đồ thị
template<typename T>
void WeightedDirectedGraph<T>::printGraph() {
    for (int i = 0; i < V; ++i) {
        displayVertex(i);
    }
}
template class WeightedDirectedGraph<int>;
template class WeightedDirectedGraph<double>;
template class WeightedDirectedGraph<float>;
template class WeightedDirectedGraph<long>;
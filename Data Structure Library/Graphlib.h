#pragma once
#ifndef Graphlib_h
#define Graphlib_h
#include <iostream>
#include <vector>

using namespace std;
template<typename T>
class Graph // Đồ thị vô hướng không có trọng số
{
private:
    int V; // Số đỉnh
    std::vector<std::vector<T>> adjList; // Danh sách kề

public:
    Graph(int vertices);        //Hàm khởi tạo đồ thị vô hướng không trọng số
    ~Graph();                   //Hàm hủy
    void addEdge(T v, T w);     //Thêm cạnh
    void displayVertex(T v);    //Hiển thị đỉnh của đồ thị
    void printGraph();          //In ra đồ thị
    bool hasVertex(T v);        //Kiểm tra sự tồn tại của một đỉnh
    bool hasEdge(T v, T w);     //Kiểm tra sự tồn tại của một cạnh
    void removeVertex(T v);     //Xóa một đỉnh
    void removeEdge(T v, T w);  //Xóa một cạnh
};

template<typename T>
class DirectedGraph {
private:
    int V; // Số đỉnh
    std::vector<std::vector<T>> adjList; //Danh sách kề

public:
    DirectedGraph(int vertices);    //Hàm khởi tạo đồ thị có hướng không trọng số
    ~DirectedGraph();               //Hàm hủy
    void addEdge(T v, T w);         //Thêm cạnh
    void displayVertex(T v);        //Hiển thị đỉnh của đồ thị
    void printGraph();              //In ra đồ thị  
    bool hasVertex(T v);            //Kiểm tra sự tồn tại của một đỉnh
    bool hasEdge(T v, T w);         //Kiểm tra sự tồn tại của một cạnh
    void removeVertex(T v);         //Xóa một đỉnh
    void removeEdge(T v, T w);      //Xóa một cạnh
};

template<typename T>
class WeightedGraph {
private:
    int V; // Số đỉnh
    std::vector<std::vector<std::pair<T, T>>> adjList;

public:
    WeightedGraph(int vertices);            //Hàm khởi tạo đồ thị vô hướng có trọng số
    ~WeightedGraph();                       //Hàm hủy
    void addEdge(T v, T w, T weight);       //Thêm cạnh
    bool hasVertex(T v);                    //Kiểm tra sự tồn tại của một đỉnh
    bool hasEdge(T v, T w);                 //Kiểm tra sự tồn tại của một cạnh
    void removeVertex(T v);                 //Xóa một đỉnh
    void removeEdge(T v, T w);              //Xóa một cạnh
    void displayVertex(T v);                //Hiển thị đỉnh của đồ thị
    void printGraph();                      //In ra đồ thị 
};


template<typename T>
class WeightedDirectedGraph {
private:
    int V; // Số đỉnh
    std::vector<std::vector<std::pair<T, T>>> adjList; // Danh sách kề và trọng số

public:
    WeightedDirectedGraph(int vertices);    //Hàm khởi tạo đồ thị có hướng có trọng số
    ~WeightedDirectedGraph();               //Hàm hủy
    void addEdge(T v, T w, T weight);       //Thêm cạnh
    bool hasVertex(T v);                    //Kiểm tra sự tồn tại của một đỉnh   
    bool hasEdge(T v, T w);                 //Kiểm tra sự tồn tại của một cạnh
    void removeVertex(T v);                 //Xóa một đỉnh
    void removeEdge(T v, T w);              //Xóa một cạnh
    void displayVertex(T v);                //Hiển thị đỉnh của đồ thị
    void printGraph();                      //In ra đồ thị
    //vector<T> ShortestPath(T startVertex);// Tìm đường đi ngắn nhất từ một đỉnh
};
#endif
#include <iostream>
#include "stacklib.h"
#include "queueLib.h"
#include "LinkedListlib.h"
#include "Treelib.h"
#include "Graphlib.h"
void teststack() {
    // Tạo một đối tượng Stack
    Stack stack(5);

    // Thêm các phần tử vào Stack
    stack.Push(10);
    stack.Push(20);
    stack.Push(30);
    stack.Push(40);
    stack.Push(50);

    // In ra Stack ban đầu
    std::cout << "Stack ban dau: ";
    stack.PrintStack();

    // Chuyển đổi Stack thành một mảng
    int* arr = stack.ToArray();
    std::cout << "Mang chua cac phan tu trong Stack: ";
    for (int i = 0; i < stack.Size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    delete[] arr;



    // Kiểm tra xem Stack đã đầy chưa
    if (stack.IsFull()) {
        std::cout << "Stack da day" << std::endl;
    }
    else {
        std::cout << "Stack chua day" << std::endl;
    }

    // Thay đổi sức chứa của Stack
    stack.Resize(10);
    std::cout << "Stack sau khi thay doi suc chua: ";
    stack.PrintStack();

    // Lấy tất cả các phần tử trong Stack
    int* allElements = stack.GetAllElements();
    std::cout << "Tat ca cac phan tu trong Stack: ";
    for (int i = 0; i < stack.Size(); i++) {
        std::cout << allElements[i] << " ";
    }
    std::cout << std::endl;
    delete[] allElements;

    // Xóa một phần tử trong Stack dựa trên chỉ số
    stack.RemoveByIndex(2);
    std::cout << "Stack sau khi xoa phan tu theo chi so: ";
    stack.PrintStack();

    // Đảo ngược thứ tự các phần tử trong Stack
    stack.Reverse();
    std::cout << "Stack sau khi dao nguoc: ";
    stack.PrintStack();

    // Kiểm tra xem Stack có đối xứng không
    if (stack.IsSymmetric()) {
        std::cout << "Stack doi xung" << std::endl;
    }
    else {
        std::cout << "Stack khong doi xung" << std::endl;
    }

}
void testqueue() {
    QueueLib<int> intQueue;

    // Thêm phần tử vào hàng đợi
    intQueue.enqueue(5);
    intQueue.enqueue(10);
    intQueue.enqueue(15);

    //Hiển thị hàng đợi
    std::cout << "Hang doi hien tai la: ";
    intQueue.display();

    //Đảo hàng đợi
    std::cout << "Hang doi sau khi dao nguoc  la: ";
    intQueue.reverse();
    intQueue.display();

    // Hiển thị phần tử đầu tiên của hàng đợi
    std::cout << "Phan tu dau tien cua hang doi: " << intQueue.front() << std::endl;

    // Xóa phần tử đầu tiên khỏi hàng đợi
    intQueue.dequeue();

    // Hiển thị phần tử đầu tiên sau khi xóa
    std::cout << "Phan tu dau tien cua hang doi (sau khi xoa): " << intQueue.front() << std::endl;

    // Kiểm tra xem hàng đợi có trống không
    if (intQueue.empty()) {
        std::cout << "hang doi rong." << std::endl;
    }
    else {
        std::cout << "Hang doi khong rong." << std::endl;
    }

    // Hiển thị kích thước của hàng đợi
    std::cout << "Kich thuoc hang doi:  " << intQueue.size() << std::endl;
}
void testLinkedList() {
    LinkedList myList;

    // Tạo danh sách liên kết
    myList.CreateList();

    // Thêm các phần tử vào danh sách
    Node* node1 = myList.CreateNode(10);
    Node* node2 = myList.CreateNode(20);
    Node* node3 = myList.CreateNode(30);
    Node* node4 = myList.CreateNode(40);

    myList.AddHead(node1);
    myList.AddTail(node2);
    myList.InsertAfterQ(node3, node1);
    myList.InsertBeforeP(node4, node2);

    // Xuất danh sách
    std::cout << "Danh sach lien ket ban dau: ";
    if (myList.Length() > 0) {
        myList.PrintList();
    }
    else {
        std::cout << "Danh sach rong." << std::endl;
    }

    // Xóa phần tử đầu danh sách
    int removedData;
   if (myList.RemoveHead(removedData) == 0) {
        std::cout << "Danh sach sau khi xoa phan tu dau: ";
        myList.PrintList();
    } 

    // Xóa phần tử cuối danh sách
    if (myList.RemoveTail(removedData) == 0) {
        std::cout << "Danh sach sau khi xoa phan tu cuoi: ";
        myList.PrintList();
    }

    // Đảo ngược danh sách
    myList.ReverseList();
    std::cout << "Danh sach sau khi dao nguoc: ";
    myList.PrintList();

    // Lấy phần tử tại một chỉ mục cụ thể
    Node* retrievedNode = myList.GetNode(1);
    if (retrievedNode != nullptr) {
        std::cout << "Phan tu tai chi muc 1: " << retrievedNode->data << std::endl;
    }

    // Tìm kiếm một Node có dữ liệu cho trước
    Node* searchedNode = myList.Search(20);
    if (searchedNode != nullptr) {
        std::cout << "Tim thay Node co du lieu 20" << std::endl;
    }

    // Độ dài của danh sách
    int length = myList.Length();
    std::cout << "Do dai cua danh sach: " << length << std::endl;

    // Hủy bỏ danh sách
    myList.DestroyList();
    std::cout << "Danh sach da duoc huy bo." << std::endl;
}
void testTree() {
    // Khởi tạo cây nhị phân tìm kiếm
    BST myTree;

    // Thêm node vào cây
    cout << "Them node vao cay" << endl;
    myTree.AddLeaf(myTree.root, 10);
    myTree.AddLeaf(myTree.root, 5);
    myTree.AddLeaf(myTree.root, 15);
    myTree.AddLeaf(myTree.root, 3);
    myTree.AddLeaf(myTree.root, 7);
    myTree.AddLeaf(myTree.root, 12);
    myTree.AddLeaf(myTree.root, 17);

    // Duyệt cây theo thứ tự Inorder
    cout << "Duyet theo Inorder: ";
    myTree.InorderTraversal(myTree.root);
    cout << endl;

    // Duyệt cây theo thứ tự Preorder
    cout << "Duyet theo Preorder: ";
    myTree.PreorderTraversal(myTree.root);
    cout << endl;

    // Duyệt cây theo thứ tự Postorder
    cout << "Duyet theo Postorder: ";
    myTree.PostorderTraversal(myTree.root);
    cout << endl;

    // Tìm node có giá trị là 7
    int keyToFind = 7;
    BST::node* foundNode = myTree.ReturnNode(myTree.root, keyToFind);
    if (foundNode != NULL)
    {
        cout << "Node " << keyToFind << " Duoc tim thay" << endl;
    }
    else
    {
        cout << "Node " << keyToFind << " khong duoc tim thay" << endl;
    }

    // In giá trị của node gốc
    cout << "Node goc: " << myTree.ReturnRootKey() << endl;

    // In các node con của node có giá trị là 5
    int keyToPrintChildren = 5;
    cout << "Cac node con cua " << keyToPrintChildren << ":" << endl;
    myTree.PrintChildren(keyToPrintChildren);

    // In giá trị của node nhỏ nhất và lớn nhất trong cây
    cout << "Node nho nhat: " << myTree.FindSmallest(myTree.root) << endl;
    cout << "Node lon nhat: " << myTree.FindBiggest(myTree.root) << endl;

    // Xóa node có giá trị là 10
    int keyToRemove = 10;
    cout << "Xoa node " << keyToRemove << endl;
    myTree.RemoveNode(myTree.root, keyToRemove);

    // Duyệt cây Inorder sau khi xóa
    cout << "Duyet theo thu tu Inorder sau khi xoa: ";
    myTree.InorderTraversal(myTree.root);
    cout << endl;

    // In chiều cao của cây
    cout << "Chieu cao cua cay: " << myTree.TreeHeight(myTree.root) << endl;
}
void testGraph(){
    //Tạo đồ thị vô hướng không trọng số
    Graph<int> graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    cout << "Do thi vo huong khong trong so:\n";
    graph.printGraph();
    if (graph.hasVertex(2))
        cout << "Dinh 2 co ton tai " << endl;
    else
        cout << "Dinh 2  khong ton tai " << endl;;

    if (graph.hasEdge(1, 3))
        cout << "Canh (1, 3) co ton tai " << endl;
    else
        cout << "Canh (1, 3) khong co ton tai " << endl;

    graph.removeVertex(2);// xóa đỉnh 2
    graph.removeEdge(1, 3);//xóa cạnh (1,3)

    std::cout << "Do thi sau khi xoa dinh 2 and canh (1, 3):\n";
    graph.printGraph();


    // Tạo đồ thị có hướng không trọng số
    DirectedGraph<double> directedGraph(4);
    directedGraph.addEdge(0, 1);
    directedGraph.addEdge(1, 2);
    directedGraph.addEdge(2, 3);
    directedGraph.addEdge(3, 0);

    std::cout << "\nDo thi co huong khong trong so:\n";
    directedGraph.printGraph();

    if (directedGraph.hasVertex(3))
        cout << "Dinh 3 co ton tai " << endl;
    else
        cout << "Dinh 3 khong ton tai" << endl;;

    if (directedGraph.hasEdge(0, 3))
        cout << "Canh (0, 3) khong ton tai " << endl;
    else
        cout << "Canh (0, 3) khong ton tai " << endl;

    directedGraph.removeVertex(1);
    directedGraph.removeEdge(3, 0);

    std::cout << "Do thi sau khi xoa dinh 1 va canh (3, 0):\n";
    directedGraph.printGraph();


    // Tạo đồ thị vô hướng có trọng số
    WeightedGraph<long> weightedGraph(4);
    weightedGraph.addEdge(0, 1, 5);
    weightedGraph.addEdge(1, 2, 10);
    weightedGraph.addEdge(1, 3, 10);

    cout << "\nDo thi vo huong co trong so:\n";
    weightedGraph.printGraph();
    if (weightedGraph.hasVertex(1))
        cout << "Dinh 1 co ton tai " << endl;
    else
        cout << "Dinh 1 khong ton tai " << endl;

    if (weightedGraph.hasEdge(1, 2))
        cout << "Canh (1, 2) co ton tai" << endl;
    else
        cout << "Canh (1, 2) co ton tai" << endl;

    weightedGraph.removeVertex(0);
    weightedGraph.removeEdge(1, 2);

    cout << "Do thi sau khi xoa dinh 0 and va canh (1, 2):\n";
    weightedGraph.printGraph();


    // Đồ thị có hướng có trọng số
    WeightedDirectedGraph<float> weightedDirectedGraph(4);
    weightedDirectedGraph.addEdge(0, 1, 2.5);
    weightedDirectedGraph.addEdge(1, 2, 3.7);
    weightedDirectedGraph.addEdge(2, 3, 4.2);
    weightedDirectedGraph.addEdge(3, 0, 1.8);

    cout << "\nDo thi co huong co trong so:\n";
    weightedDirectedGraph.printGraph();

    if (weightedDirectedGraph.hasVertex(5))
        cout << "Dinh 5 co ton tai " << endl;
    else
        cout << "Dinh 5 khong co ton tai " << endl;


    if (weightedDirectedGraph.hasEdge(3, 1))
        cout << "Canh (3,1) co ton tai " << endl;
    else
        cout << "Canh (3,1) khong co ton tai " << endl;

    weightedDirectedGraph.removeVertex(1);
    weightedDirectedGraph.removeEdge(3, 0);

    cout << "Do thi sau khi xoa dinh 1 and canh (3, 0):\n";
    weightedDirectedGraph.printGraph();
    //weightedDirectedGraph.ShortestPath(0);

}
int main() {
    //teststack();
    //testqueue();
    //testLinkedList();
    //testTree();
    testGraph();
    return 0;
}
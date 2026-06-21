#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int v) : value(v), left(nullptr), right(nullptr) {}
};

Node* buildBalanced(const std::vector<int>& values, int start, int end) {
    if (start > end) return nullptr;
    int mid = (start + end) / 2;
    Node* node = new Node(values[mid]);
    node->left  = buildBalanced(values, start, mid - 1);
    node->right = buildBalanced(values, mid + 1, end);
    return node;
}

void inorder(Node* node, std::vector<int>& result) {
    if (!node) return;
    inorder(node->left, result);
    result.push_back(node->value);
    inorder(node->right, result);
}

void printTree(Node* node, int level = 0, const std::string& prefix = "Корень: ") {
    if (!node) return;
    std::cout << std::string(level * 4, ' ') << prefix << node->value << '\n';
    if (node->left || node->right) {
        if (node->left)
            printTree(node->left,  level + 1, "Л: ");
        else
            std::cout << std::string((level + 1) * 4, ' ') << "Л: None\n";
        if (node->right)
            printTree(node->right, level + 1, "П: ");
        else
            std::cout << std::string((level + 1) * 4, ' ') << "П: None\n";
    }
}

void freeTree(Node* node) {
    if (!node) return;
    freeTree(node->left);
    freeTree(node->right);
    delete node;
}

int main() {
    // Ручной ввод числа вершин
    int n;
    std::cout << "Введите число вершин (1–10): ";
    std::cin >> n;
    n = std::max(1, std::min(10, n));

    std::vector<int> values(n);
    for (int i = 0; i < n; ++i) values[i] = i + 1;

    // Вариант чтения из файла:
    // #include <fstream>
    // std::ifstream fin("input.txt");
    // int n;
    // fin >> n;
    // n = std::max(1, std::min(10, n));
    // std::vector<int> values(n);
    // for (int i = 0; i < n; ++i) values[i] = i + 1;

    Node* root = buildBalanced(values, 0, n - 1);
    printTree(root);

    std::vector<int> result;
    inorder(root, result);
    std::cout << "Обход in-order: ";
    for (int v : result) std::cout << v << ' ';
    std::cout << '\n';

    freeTree(root);
    return 0;
}
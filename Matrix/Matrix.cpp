#include "Matrix.h"
#include <exception>
using namespace std;

// complexitate: Theta(1)

Matrix::Matrix(int nrLines, int nrCols) {
    root = nullptr;
    lines = nrLines;
    cols = nrCols;
}

// complexitate: Theta(1)

Matrix::Node::Node(int l, int c, TElem v) {
    line = l;
    col = c;
    info = v;
    left = nullptr;
    right = nullptr;
}

// complexitate: Theta(1)

int Matrix::nrLines() const {
    return lines;
}

// complexitate: Theta(1)

int Matrix::nrColumns() const {
    return  cols;
}

// best case: Theta(1) -> pozitie invalida sau elem cautat se afla pe radacina arborelui
// average case: O(n)
// worst case: Theta(n) -> elem cautat se afla in ultimul nod drept de pe pt dr a arborelui
// general complexity: O(n)

TElem Matrix::element(int i, int j) const {
    if (i < 0 || i >= lines || j < 0 || j >= cols) {
        throw exception();
    }
    Node* current = root;
    while (current != nullptr) {
        if (current->line == i && current->col == j) {
            return current->info;
        } else if (i < current->line || (i == current->line && j < current->col)) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return NULL_TELEM;
}

// best case: Theta(1) -> pozitie invalida sau elem cautat se afla pe radacina arborelui
// average case: O(n)
// worst case: -> Thata(n) -> nu gasim nodul si trebuie sa creem unul nou
// general complexity: O(n)

TElem Matrix::modify(int i, int j, TElem e) {
    if (i < 0 || i >= lines || j < 0 || j >= cols) {
        throw exception();
    }
    Node* current = root;
    Node* parent = nullptr;
    while (current != nullptr) {
        if (current->line == i && current->col == j) {
            TElem oldValue = current->info;
            current->info = e;
            return oldValue;
        } else if (i < current->line || (i == current->line && j < current->col)) {
            parent = current;
            current = current->left;
        } else {
            parent = current;
            current = current->right;
        }
    }
    if (e != NULL_TELEM) {
        Node* newNode = new Node(i, j, e);
        if (parent == nullptr) {
            root = newNode;
        } else if (i < parent->line || (i == parent->line && j < parent->col)) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
    }
    return NULL_TELEM;
}

// complexitate: Theta(1)

Matrix::~Matrix() {
    delete root;
}

// complexitate: Theta(1)

Matrix::Node::~Node() {
    delete left;
    delete right;
}

// complexitate: Theta(1)
// pre: other
// post: false (matricile nu au aceleasi dimensiuni)
// post: false (matricile nu sunt egale)
// post: true (matricile sunt egale)

bool Matrix::operator==(Matrix &other) {
    // verificam daca matricile au acelasi dimensiuni
    if (lines != other.lines && cols != other.cols)
        return false;
    // verificam recursiv daca arborii matricilor sunt egali
    return is_equal(root, other.root);
}

// complexitate: Theta(1)
// pre: first, second
// post: true (ambele matrici sunt nule)
// post: true (matricile sunt egale)
// post: false (doar una din matrici este nula)
// post: false (matricile nu sunt egale)

bool Matrix::is_equal(Matrix::Node *first, Matrix::Node *second) {
    if (first == nullptr && second == nullptr)
        return true;
    else if (first == nullptr || second == nullptr)
        return false;
    // daca linia si coloana sunt egale
    bool position = (first->line == second->line) && (first->col == second->col);
    // daca valorile sunt egale
    bool value = (first->info == second->info);
    // daca subarborii stangi sunt egali
    bool left = is_equal(first->left, second->left);
    // daca subarborii drepti sunt egali
    bool right = is_equal(first->right, second->right);
    return position && value && left && right;
}

// pseudocod is_equal:

// function is_equal(first, second):
//      if (node1 = nil and node2 = nil)
//          return true
//      if (first = nil or second = nil)
//          return false
//      bool position <- ((first_line = second_line) and (first_col = second_col))
//      bool value <- (first_info = second_info)
//      bool right <- is_equal(first_right, second_right)
//      bool left <- is_equal(first_left, second_left)
//      return (position and value and left and right)

// pseudocod operator:

// function operator==(other):
//      if (lines != other_lines and cols != other_cols)
//          return false
//      return is_equal(root, other_root)
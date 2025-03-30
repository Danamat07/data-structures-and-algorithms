#pragma once

//DO NOT CHANGE THIS PART
typedef int TElem;
#define NULL_TELEM 0

// ADT Matrix – repräsentiert als schwachbesetzte Matrix (sparse) mit Tupeln der Form
// (Zeile, Spalte, Wert) (Wert ≠ 0), wobei die Tupel in lexikographischen Reihenfolge nach
// (Zeile, Spalte) in einem BST mit einer verketteten Repräsentierung mit dynamischer
// Allokation gespeichert werden.


class Matrix {

private:
    struct Node {
        TElem info;
        int line;
        int col;
        Node* left;
        Node* right;
        Node(int l, int c, TElem v);
        ~Node();
    };
    Node* root;
    int lines;
    int cols;

public:
    //constructor
    Matrix(int nrLines, int nrCols);

    //returns the number of lines
    int nrLines() const;

    //returns the number of columns
    int nrColumns() const;

    //returns the element from line i and column j (indexing starts from 0)
    //throws exception if (i,j) is not a valid position in the Matrix
    TElem element(int i, int j) const;

    //modifies the value from line i and column j
    //returns the previous value from the position
    //throws exception if (i,j) is not a valid position in the Matrix
    TElem modify(int i, int j, TElem e);

    // destructor
    ~Matrix();

    bool operator==(Matrix& other);
    bool is_equal(Node* first, Node* second);

};
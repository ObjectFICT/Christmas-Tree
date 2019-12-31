#pragma once

#include <iostream>
#include <windows.h>

using namespace std;

class christmasTree{
    private:
    //THIS IS CHRISTMAS TRE)))
    string Tree;
    //The height and width of the largest block of Christmas tree
    int heightTree, widthTree;

    public: 

    christmasTree(int heightTree);

    void buildBlockTree(double sizeFactor, int color);

    void buildStemTree();

    void buildTree(int color);
    
    void setColor(int text, int background);

    void doTree(int NumberOfFlickeringCycles);
};
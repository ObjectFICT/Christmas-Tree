#include "christmasTree.h"

christmasTree::christmasTree(int heightTree)
{
    this->heightTree = heightTree;
    this->widthTree = heightTree * 2;
}

void christmasTree::buildBlockTree(double sizeFactor, int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int left{heightTree}, right{heightTree};
    
    for (size_t i = 0; i < (int)(heightTree / sizeFactor); i++)
    {
        for (size_t j = 0; j < widthTree; j++)
        {
            if(j < left ||  j > right)
            {
                Tree = Tree + " ";
                
                cout << " ";
            } else {
                if(i % 2 == 0)
                {
                    setColor(2, 0);
                    printf("^");

                    Tree = Tree + '^';
                } else {
                    setColor(color, 0);
                    printf("*");

                    Tree = Tree + '*';
                }
            }
        }

        left--;
        right++;

        cout << endl;

        Tree = Tree + "\n";
    }
}

void christmasTree::buildStemTree()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    setColor(8, 0);
    
    for(size_t i = 0; i < heightTree / 2; i++)
    {
        for (size_t j = 0; j < widthTree; j++)
        {
            if(j > 2*widthTree/3 ||  j < widthTree/3)
            {
                cout << " ";
            } else {
                cout << "^";
            }
        }
        cout << endl;
    }
}

void christmasTree::buildTree(int color)
{
    buildBlockTree(2, color);
    buildBlockTree(1.3,color);
    buildBlockTree(1, color);

    buildStemTree();
}

void christmasTree::setColor(int text, int background)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void christmasTree::doTree(int NumberOfFlickeringCycles)
{
    while (NumberOfFlickeringCycles > 0)
    {
        system("cls");
        buildTree(3);
        Sleep(1000);

        system("cls");
        buildTree(4);
        Sleep(1000);

        system("cls");
        buildTree(6);
        Sleep(1000);

        NumberOfFlickeringCycles--;
    }
}
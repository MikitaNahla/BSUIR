#include <iostream>
#include <Windows.h>
#include <cstdio>
#include <io.h>
#include <string>
#include <vector>

using namespace std;

struct Tree
{
    int value = 0;
    string line;
    Tree* left = NULL;
    Tree* right = NULL;
};

struct Mass
{
    int info;
    string str;
};

Tree* List(int num, string st)
{
    Tree* temp = new Tree;
    temp->value = num;
    temp->line = st;
    temp->left = temp->right = NULL;
    return temp;
}

void Add_List(Tree* root, int num, string st)
{
    Tree* prev = NULL, * temp;
    bool ch = true;
    temp = root;
    while (temp && ch)
    {
        prev = temp;
        if (num == temp->value)
        {
            ch = false;
            cout << "Вы ввели повторяющийся ключ! " << endl;
        }
        else
        {
            if (num < temp->value)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right; 
            }
        }
    }
    if (ch)
    {
        temp = List(num, st);
        if (num < prev->value)
        {
            prev->left = temp;
        }
        else
        {
            prev->right = temp;
        }
    }
}

void Add_Info(Tree* root,  int quan)
{
    int num;
    string info;
    for (int i = 0; i < quan; i++)
    {
        cout << "Input number of list: ";
        cin >> num;
        cout << "Input line of list: ";
        info = "";
        while (info == "")
        {
            getline(cin, info);
        }
        Add_List(root, num, info);
    }
}

void View_Tree(Tree* root, int level)
{
    string str;
    if (root != NULL)
    {
        View_Tree(root->right, level + 1);
        for (int i = 0; i < level; i++)
        {
            str = str + "\t";
        }
        cout << str << root->value << " " << root->line << endl;
        View_Tree(root->left, level + 1);
    }
}

void Direct_Bypass(Tree* root)
{
    if (root)
    {
        cout << root->value << " " << root->line << endl;
        Direct_Bypass(root->left);
        Direct_Bypass(root->right);
    }
}

void Reverse_Bypass(Tree* root)
{
    if (root) 
    {
        Reverse_Bypass(root->left);
        Reverse_Bypass(root->right);
        cout << root->value << " " << root->line << endl;
    }
}

void Min_To_Max_Bypass(Tree* root)
{
    if (root)
    {
        Direct_Bypass(root->left);
        cout << root->value << " " << root->line << endl;
        Direct_Bypass(root->right);
    }
}

void Find_Info(Tree* root, int key)
{
    if (key > (root->value))
    {
        if (root->right != NULL)
        {
            Find_Info(root->right, key);
        }
        else
        {
            cout << "Information by your key is not found" << endl;
            return;
        }
    }
    if (key < (root->value))
    {
        if (root->right != NULL)
        {
            Find_Info(root->left, key);
        }
        else
        {
            cout << "Information by your key is not found" << endl;
            return;
        }
        
    }
    if (key == root->value)
    {
        cout << "Information by your key is: " << root->value << " " << root->line << endl;
    }
}

void Delete_Tree(Tree* root)
{
    if (root != NULL)
    {
        Delete_Tree(root->left);
        Delete_Tree(root->right);
        delete root;
    }
}

double Sum(Tree* root)
{
    double mean = 0;
    if (root)
    {
        mean += root->value;
        mean += Sum(root->left);
        mean += Sum(root->right);
    }
    return mean;
}

void Close_Mean_Str(Tree* root, double mean, int close_value, string line1)
{
    if (mean > (root->value))
    {
        if (root->right != NULL )
        {
            if (fabs(root->value - mean) < fabs(close_value - mean))
            {
                close_value = root->value;
                line1 = root->line;
            }
            Close_Mean_Str(root->right, mean, close_value, line1);
        }
        else
        {
            if (fabs(root->value - mean) < fabs(close_value - mean))
            {
                close_value = root->value;
                line1 = root->line;
            }
            cout << "The node in close meaning is " << close_value << " " << line1 << endl;
        }
    }
    if (mean < (root->value) )
    {
        if (root->left != NULL)
        {
            if (fabs(root->value - mean) < fabs(close_value - mean))
            {
                close_value = root->value;
                line1 = root->line;
            }
            Close_Mean_Str(root->left, mean, close_value, line1);
        }
        else
        {
            if (fabs(root->value - mean) < fabs(close_value - mean))
            {
                close_value = root->value;
                line1 = root->line;
            }
            cout << "The node in close meaning is " << close_value << " " << line1 << endl;
        }
    }
    if (mean == root->value)
    {
        cout << "Information by your key is: " << root->value << " " << root->line << endl;
        return;
    }
}

void Personal_Task(Tree* root, int quantity)
{
    double mean = 0;
    double r = Sum(root);
    mean = r / quantity;
    cout << "Mean: " << mean << endl;
    Close_Mean_Str(root, mean, root->value, root->line);
}

Tree* Delete_Node(Tree* root, int key)
{
    Tree* Delete_N, * Par_N, * R, * Par_R;                      
    Delete_N = root;                                            
    Par_N = NULL;                                               
    while (Delete_N != NULL && Delete_N->value != key)          
    {
        Par_N = Delete_N;                                       
        if (Delete_N->value > key)
        {
            Delete_N = Delete_N->left;                          
        }
        else
        {
            Delete_N = Delete_N->right;
        }
    }
    if (Delete_N == NULL)                                       
    {
        cout << "This key isn't exist";
        return root;
    }
    if (Delete_N->right == NULL)                                  
    {
        R = Delete_N->left;
    }
    else                                                        
    {
        if (Delete_N->left == NULL)                               
        {
            R = Delete_N->right;
        }
        else                                                
        {
            Par_R = Delete_N;                                   
            R = Delete_N->left;                                 
            while (R->right != NULL)                        
            {
                Par_R = R;                                      
                R = R->right;                                   
            }
            if (Par_R == Delete_N)                              
            {
                R->right = Delete_N->right;
            }
            else                                                       
            {
                R->right = Delete_N->right;
                Par_R->right = R->left;
                R->left = Delete_N->left;
            }
        }
    }
    if (Delete_N == root)                                                  
    {
        root = R;
    }
    else                                                    
    {
        if (Delete_N->value < Par_N->value)                     
        {
            Par_N->left = R;
        }
        else
        {                                                       
            Par_N->right = R;
        }
    }
    delete Delete_N;
    return root;                                                
}

void QuickSort(Mass *arr, int begin, int end)
{
    int left = begin;
    int right = end;
    int middle = (left + right) / 2;
    do
    {
        while (arr[middle].info > arr[left].info)
        {
            left++;
        }
        while (arr[middle].info < arr[right].info)
        {
            right--;
        }
        if (left <= right)
        {
            int Temp = arr[left].info;
            arr[left].info = arr[right].info;
            arr[right].info = Temp;
            left++;
            right--;
        }
    } while (left <= right);
    if (begin < right)
    {
        QuickSort(arr, begin, right);
    }
    if (end > left)
    {
        QuickSort(arr, left, end);
    }
}

int Add_Element(Tree* root, Mass* arr, int i)
{
    if (root)
    {
        arr[i].info = root->value;
        arr[i].str = root->line;
        i++;
        i = Add_Element(root->left, arr, i);
        i = Add_Element(root->right, arr, i);
    }
    return i;
}

void Make_Blns(Tree** p, int n, int k, Mass* arr)
{
    if (n == k)
    {
        *p = NULL;
        return;
    }
    else
    {
        int m = (n + k) / 2;
        *p = new Tree;
        (*p)->value = arr[m].info;
        (*p)->line = arr[m].str;
        Make_Blns(&(*p)->left, n, m, arr);
        Make_Blns(&(*p)->right, m + 1, k, arr);
    }
}

Tree* Balance_Tree(Tree* root, int quantity)
{
    Mass* arr;
    arr = new Mass[quantity];
    Add_Element(root, arr, 0);
    QuickSort(arr, 0, quantity - 1);
    Delete_Tree(root);
    Tree* Tr = NULL;
    Tr = new Tree[quantity];
    Make_Blns(&Tr, 0, quantity, arr);
    delete[]arr;
    return Tr;
}

int Menu()
{
    system("cls");
    int r;
    cout << "(1)Create Tree" << endl;                   //
    cout << "(2)Add info in Tree" << endl;              //
    cout << "(3)View tree" << endl;                     //
    cout << "(4)Balance Tree" << endl;
    cout << "(5)Find information by key" << endl;       //
    cout << "(6)Delete information by key" << endl;     //    
    cout << "(7)Print information" << endl;             //
    cout << "(8)Delete Tree" << endl;                   //
    cout << "(9)Personal Task" << endl;                 //
    cout << "(0)Exit the program" << endl;              //
    cin >> r;
    return r;
}

int Menu_Print()
{
    system("cls");
    int r;
    cout << "(1)Direct bypass" << endl;
    cout << "(2)Reverse bypass" << endl;
    cout << "(3)In ascending order of number" << endl;
    cout << "(0)Exit the print menu" << endl;
    cin >> r;
    return r;
}

int main()
{
    int quan, num;
    string info;
    Tree* Tr = NULL;
    while (true)
    {
        switch (Menu())
        {

        case 1:
            system("cls");
            if (Tr != NULL)
            {
                Delete_Tree(Tr);
            }
            cout << "Input quantity of nodes: ";
            cin >> quan;
            Tr = new Tree[quan];
            for (int i = 0; i < quan; i++)
            {
                cout << "Input number of list: ";
                cin >> num;
                cout << "Input line of list: ";
                info = "";
                while (info == "")
                {
                    getline(cin, info);
                }
                if (i == 0)
                {
                    Tr = List(num, info);
                }
                else
                {
                    Add_List(Tr, num, info);
                }
            }
            break;
        case 2:
            system("cls");
            if (Tr == NULL)
            {
                cout << "Create Tree Before!" << endl;
                system("pause");
                break;
            }
            cout << "Input quantity of additive nodes: ";
            cin >> quan;
            Add_Info(Tr, quan);
            break;
        case 3:
            system("cls");
            if (Tr == NULL)
            {
                cout << "Create Tree Before!" << endl;
                system("pause");
                break;
            }
            View_Tree(Tr, 0);
            system("pause");
            break;
        case 4:
            system("cls");
            if (Tr == NULL)
            {
                cout << "Create Tree Before!" << endl;
                system("pause");
                break;
            }
            Tr = Balance_Tree(Tr, quan);
            system("pause");
            break;
        case 5:
            system("cls");
            if (Tr == NULL)
            {
                cout << "Create Tree Before!" << endl;
                system("pause");
                break;
            }
            int e;
            cout << "Input key: ";
            cin >> e;
            Find_Info(Tr, e);
            system("pause");
            break;
        case 6:
            system("cls");
            if (Tr == NULL)
            {
                cout << "Create Tree Before!" << endl;
                system("pause");
                break;
            }
            int r;
            cout << "Input key: " ;
            cin >> r;
            Tr = Delete_Node(Tr, r);
            break;
        case 7:
            system("cls");
            if (Tr == NULL)
            {
                cout << "Create Tree Before!" << endl;
                system("pause");
                break;
            }
            bool a;
            a = true;
            while (a)
            {
                switch (Menu_Print())
                {
                case 1:
                    system("cls");
                    Direct_Bypass(Tr);
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    Reverse_Bypass(Tr);
                    system("pause");
                    break;
                case 3:
                    system("cls");
                    Min_To_Max_Bypass(Tr);
                    system("pause");
                    break;
                case 0:
                    system("cls");
                    a = false;
                    cout << "...Exiting the print menu..." << endl;
                    system("pause");
                    break;
                }
            }
            break;
        case 8:
            system("cls");
            if (Tr == NULL)
            {
                cout << "Create Tree Before!" << endl;
                system("pause");
                break;
            }
            Delete_Tree(Tr);
            Tr = NULL;
            break;
        case 9:
            system("cls");
            if (Tr == NULL)
            {
                cout << "Create Tree Before!" << endl;
                system("pause");
                break;
            }
            Personal_Task(Tr, quan);
            system("pause");
            break;

        case 0:
            system("cls");
            Delete_Tree(Tr);
            cout << "...Exiting the program...";
            return 0;
            break;
        }
    }
}
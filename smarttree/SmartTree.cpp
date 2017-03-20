//
// Created by radek on 14.03.17.
//

#include <iostream>
#include <vector>
#include "SmartTree.h"
using namespace std;
namespace datastructures {
    struct SmartTree;
std::unique_ptr<SmartTree> CreateLeaf(int value)
{
    SmartTree leaf;
    unique_ptr<SmartTree> wsk(new SmartTree);
    wsk->parent= nullptr;
    wsk->left=nullptr;
    wsk->right= nullptr;
    wsk->value=value;
    return wsk;
}

unique_ptr<SmartTree> InsertLeftChild(unique_ptr<SmartTree>tree, unique_ptr<SmartTree> left_subtree)
{
    if(tree!= nullptr) tree->left=move(left_subtree);
    //tree->left->parent=move(tree->left);
    return tree;
}
    unique_ptr<SmartTree>InsertRightChild(unique_ptr<SmartTree>tree, unique_ptr<SmartTree> right_subtree)
{
    if(tree!= nullptr) tree->right=move(right_subtree);
    return tree;
}

void PrintTreeInOrder(const unique_ptr<SmartTree>&unique_ptr, ostream *out)
{
    if(unique_ptr== nullptr) return;
    PrintTreeInOrder(unique_ptr->left, out);
    for (int i = 0; i <to_string(unique_ptr->value).size() ; i++) {
        (*out).put(to_string(unique_ptr->value)[i]);
    }
    (*out).put(',');
    (*out).put(' ');
    PrintTreeInOrder(unique_ptr->right, out);






    /*out->operator<<(unique_ptr->value);

    if(unique_ptr->left!= nullptr)
    {

        PrintTreeInOrder(unique_ptr->left,out);
    }
    if(unique_ptr->right!= nullptr)
    {

        PrintTreeInOrder(unique_ptr->right, out);
    }*/

}
    int i=1;
string DumpTree(const unique_ptr<SmartTree>&tree)
{
    string res;
    res+="[" + to_string(tree->value)+" ";


    if (tree->left)
    {

        res+=DumpTree(tree->left);
        res+=" ";

    }
    else res+="[none] ";
    if (tree->right)
    {

      //  i++;
        res+=DumpTree(tree->right);
        res+="]";
    }
    else res+="[none]]";
   // cout<<res;
    //if (i%2==1) res+=" ";
    return res;
}


unique_ptr<SmartTree> RestoreTree(const string &tree)
{
    vector<string> tab1;
    vector<string> tabright;
    vector<string> tableft;
    string tmp;
    int nowright,stop,il=0,ip;
    unique_ptr<SmartTree> rtree;
    unique_ptr<SmartTree> mrtree;
for (int i=0;i<tree.size()-1;i++)
{
    if ((int(tree[i])>=48 and int(tree[i])<=57) or int(tree[i])==45)
    {
        tmp+=tree[i];
    } else {
        if (tmp != "") tab1.push_back(tmp);
        tmp.clear();
    }

}
    for (int i = 0; i <tab1.size() ; i++) {
        if (tree.find("] ["+tab1[i])<=tree.size()) tabright.push_back(tab1[i]);

    }

    for (int k=0,i = 0; i <tab1.size() ; i++) {

        if (tab1[i]!=tabright[k]) tableft.push_back(tab1[i]);
        else k++;
    }


}}
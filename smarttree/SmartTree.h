//
// Created by radek on 14.03.17.
//

#ifndef JIMP_EXERCISES_SMARTTREE_H
#define JIMP_EXERCISES_SMARTTREE_H
#include <ostream>
#include <string>
#include <memory>
#include <map>
using namespace std;
namespace datastructures {
    struct SmartTree {
        unique_ptr<SmartTree> parent;
        unique_ptr<SmartTree> left;
       unique_ptr<SmartTree> right;
        int value;

    };

    unique_ptr<SmartTree> CreateLeaf(int value);

    unique_ptr<SmartTree> InsertLeftChild(unique_ptr<SmartTree> tree, unique_ptr<SmartTree> left_subtree);

    std::unique_ptr<SmartTree> InsertRightChild(unique_ptr<SmartTree> tree, unique_ptr<SmartTree> right_subtree);

    void PrintTreeInOrder(const unique_ptr<SmartTree> &unique_ptr, ostream *out);

    string DumpTree(const unique_ptr<SmartTree> &tree);

    std::unique_ptr<SmartTree> RestoreTree(const std::string &tree);
};
#endif //JIMP_EXERCISES_SMARTTREE_H

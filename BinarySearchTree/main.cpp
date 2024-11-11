#include <iostream>
#include "Bst.hpp"


bool testInsert()
{
    Bst<int> tree;

    if (!tree.insert(10)) return false;
    if (!tree.insert(5)) return false;
    if (!tree.insert(20)) return false;
    if (tree.insert(10)) return false; // Duplicate insert should return false

    if (tree.getSize() != 3) return false; // Only 3 unique elements inserted
    if (!tree.contains(10)) return false;
    if (!tree.contains(5)) return false;
    if (!tree.contains(20)) return false;
    if (tree.contains(15)) return false;

    return true;
}

bool testContains()
{
    Bst<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(20);

    if (!tree.contains(10)) return false;
    if (!tree.contains(5)) return false;
    if (!tree.contains(20)) return false;
    if (tree.contains(15)) return false; // 15 is not in the tree

    return true;
}

bool testRemove()
{
    Bst<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(20);

    if (!tree.remove(5)) return false; // 5 should be removed
    if (tree.contains(5)) return false; // 5 should no longer be in the tree
    if (tree.getSize() != 2) return false;

    if (!tree.remove(10)) return false; // 10 should be removed
    if (tree.contains(10)) return false; // 10 should no longer be in the tree
    if (tree.getSize() != 1) return false;

    if (!tree.remove(20)) return false; // 20 should be removed
    if (tree.contains(20)) return false; // 20 should no longer be in the tree
    if (!tree.isEmpty()) return false; // Tree should be empty now

    return true;
}

bool testCustomComparator()
{
    // Bst with a custom comparator for descending order
    auto comp = [](int a, int b) { return a > b; };
    Bst<int, decltype(comp)> tree(comp);

    tree.insert(10);
    tree.insert(5);
    tree.insert(20);

    if (!tree.contains(10)) return false;
    if (!tree.contains(5)) return false;
    if (!tree.contains(20)) return false;

    // Testing the order through structure traversal (in this case, assumed order check)
    if (tree.getSize() != 3) return false;
    return true;
}

bool testTreeSort()
{
    std::vector<int> v = { 9,8,3,1,2,4,5,7,6, 0 };
    treeSort(v);
    for (int i = 0; i < v.size(); i++)
    {
        if (i != v.at(i))
            return false;
    }
    return true;
}

int main()
{
    std::cout << "Test Insert: " << (testInsert() ? "Passed" : "Failed") << std::endl;
    std::cout << "Test Contains: " << (testContains() ? "Passed" : "Failed") << std::endl;
    std::cout << "Test Remove: " << (testRemove() ? "Passed" : "Failed") << std::endl;
    std::cout << "Test Custom Comparator: " << (testCustomComparator() ? "Passed" : "Failed") << std::endl;
    std::cout << "Test Tree sort: " << (testTreeSort() ? "Passed" : "Failed") << std::endl;

   

    return 0;
}

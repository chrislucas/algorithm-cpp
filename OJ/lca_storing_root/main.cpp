#include <iostream>
#include <vector>

using namespace std;

/*
http://www.tutorialspoint.com/cplusplus/cpp_constructor_destructor.htm
http://www.geeksforgeeks.org/find-lca-in-binary-tree-using-rmq/
http://www.geeksforgeeks.org/lowest-common-ancestor-in-a-binary-tree-set-2-using-parent-pointer/
https://www.topcoder.com/community/data-science/data-science-tutorials/range-minimum-query-and-lowest-common-ancestor/
*/
class Node {
    public:
        int key;
        Node *lf, *ri;
        Node();
};

Node::Node(void) {

}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

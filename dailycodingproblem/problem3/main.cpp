#include <iostream>
#include <cassert>
#include <string>
#include <sstream>
#include <memory>

using namespace std;

class Node
{
  public:
    Node(string val, Node *left = nullptr, Node *right = nullptr)
    {
        this->val = val;
        this->left = left;
        this->right = right;
    }

    ~Node()
    {
        // cout << "deleting " << this->val << endl;
        if (this->left != nullptr)
            delete this->left;
        if (this->right != nullptr)
            delete this->right;
    }

    string Serialize();

  public:
    string val;
    Node *left;
    Node *right;
};

string serialize(Node *node)
{
    if (node == nullptr)
        return "";

    return node->Serialize();
}

static Node *deserialize(stringstream &ss);
unique_ptr<Node> deserialize(string s)
{
    auto ss = stringstream(s);
    return unique_ptr<Node>(deserialize(ss));
}

int main()
{
    auto pNode = new Node("root", new Node("left", new Node("left.left")), new Node("right"));

    auto s = serialize(pNode);
    cout << s << endl;

    assert(deserialize(serialize(pNode))->left->left->val == "left.left");
    cout << "PASSED!" << endl;

    delete pNode;

    return 0;
}

string Node::Serialize()
{
    stringstream ss;
    ss << this->val.length() << " " << this->val << " ";

    if (this->left != nullptr)
        ss << this->left->Serialize();
    else
        ss << -1 << " ";

    if (this->right != nullptr)
        ss << this->right->Serialize();
    else
        ss << -1 << " ";

    return ss.str();
}

static Node *deserialize(stringstream &ss)
{
    int count = -1;
    ss >> count;
    ss.get();

    if (!ss.good() || count == -1)
        return nullptr;

    char *temp = new char[count + 1];
    ss.read(temp, count);
    ss.get();
    string val = temp;
    delete[] temp;

    if (!ss.good())
        return nullptr;

    Node *node = new Node(val, deserialize(ss), deserialize(ss));
    return node;
}

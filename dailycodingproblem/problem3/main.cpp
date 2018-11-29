#include <iostream>
#include <cassert>
#include <string>
#include <sstream>

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
Node *deserialize(string s)
{
    auto ss = stringstream(s);
    return deserialize(ss);
}

int main()
{
    auto pNode = new Node("root", new Node("left", new Node("left.left")), new Node("right"));

    auto s = serialize(pNode);
    cout << s << endl;

    auto s2 = serialize(deserialize(s));
    cout << s2 << endl;

    assert(deserialize(serialize(pNode))->left->left->val == "left.left");
    cout << "PASSED!" << endl;

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

    if (!ss.good())
        return nullptr;

    Node *node = new Node(temp, deserialize(ss), deserialize(ss));
    return node;
}

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node
{
    char value;
    int count; // count is increased if there is a word at that position
    vector<Node *> next;

    Node(char a = '@')
    {
        this->value = a;
        this->count = 0;
        this->next = vector<Node *>('z' - 'a' + 1, nullptr);
    }

    ~Node()
    {
        for (int i = 0; i < this->next.size(); ++i)
        {
            if (this->next[i] != nullptr)
            {
                delete this->next[i];
                this->next[i] = nullptr;
            }
        }
    }

    void Retrieve(vector<string> &v, string prefix)
    {
        string data = prefix + this->value;
        for (int i = 0; i < this->count; ++i)
        {
            v.push_back(data);
        }

        for (int i = 0; i < this->next.size(); ++i)
        {
            if (this->next[i] != nullptr)
            {
                this->next[i]->Retrieve(v, data);
            }
        }
    }
};

class DictionaryTree
{
  public:
    DictionaryTree() = default;
    ~DictionaryTree() = default;
    void AddWords(const vector<string> &v);
    vector<string> Query(const string &q);

  private:
    void AddWord(const string &s);

  private:
    Node root;
};

int main()
{
    DictionaryTree t;
    t.AddWords({"dog", "deer", "deal", "deer", "de", "ede"});
    auto v = t.Query("de");
    cout << "Found " << v.size() << " word(s): ";
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << ", ";
    }
    cout << endl;
    return 0;
}

void DictionaryTree::AddWord(const string &s)
{
    Node *temp = &this->root;
    for (int i = 0; i < s.length(); ++i)
    {
        int index = s[i] - 'a';
        if (temp && temp->next[index] == nullptr)
        {
            temp->next[index] = new Node(s[i]);
        }
        temp = temp->next[index];
    }
    temp->count++;
}

void DictionaryTree::AddWords(const vector<string> &v)
{
    for (auto &s : v)
    {
        this->AddWord(s);
    }
}

vector<string> DictionaryTree::Query(const string &q)
{
    vector<string> v;
    // find location of q
    Node *temp = &this->root;
    bool found = true;
    for (int i = 0; i < q.length(); ++i)
    {
        int index = q[i] - 'a';
        if (temp->next[index] == nullptr)
        {
            found = false;
            break;
        }
        temp = temp->next[index];
    }

    if (found)
    {
        string prefix = q.length() > 0 ? q.substr(0, q.length() - 1) : q;
        temp->Retrieve(v, prefix);
    }

    return v;
}

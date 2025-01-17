#include <bits/stdc++.h>

using namespace std;

template <typename T> class aho_corasick {
public:
  template <typename U> class aho_node {
    friend class aho_corasick;
    aho_node<U>* parent;
    aho_node<U>* fall;
    unordered_map<T, aho_node<U>*> f;
    int memo = -1;
    aho_node() {}
    aho_node(aho_node<U>* parent, aho_node<U>* fall)
        : parent(parent), fall(fall) {}

  public:
    aho_node<U>* next_output = nullptr;
    bool ending = false;
  };
  using node = aho_node<T>;

private:
  node* root = new node();
  vector<node*> to_reset;

  int get_output_count(node* n) {
    if(!n)
      return 0;
    if(n->memo != -1)
      return n->memo;
    to_reset.push_back(n);
    return n->memo = n->ending + get_output_count(n->next_output);
  }

public:
  node* insert(const vector<T>& s) {
    node* curr = root;
    for(T c : s) {
      node* next = curr->f[c];
      if(!next)
        next = curr->f[c] = new node(curr, root);
      curr = next;
    }
    curr->ending = true;
    return curr;
  }

  void setup() {
    queue<pair<T, node*>> q;
    q.push({T(), root});
    root->parent = root;
    root->fall = nullptr;
    root->memo = 0;
    while(!q.empty()) {
      auto front = q.front();
      q.pop();
      T c = front.first;
      node* n = front.second;
      for(auto& p : n->f)
        q.push(p);
      if(n->parent != root) {
        node* curr = n->parent->fall;
        while(curr && !curr->f.count(c))
          curr = curr->fall;
        if(curr) {
          n->fall = curr->f[c];
          n->next_output = n->fall->ending ? n->fall : n->fall->next_output;
        }
      }
    }
  }

  void reset_memo() {
    for(node* n : to_reset)
      n->memo = -1;
    to_reset.clear();
  }

  pair<int, node*> query(const vector<T>& s) {
    int res = 0;
    node* curr = root;
    for(T c : s) {
      while(curr && !curr->f.count(c))
        curr = curr->fall;
      curr = curr ? curr->f[c] : root;
      res += get_output_count(curr);
    }
    return {res, curr};
  }
};

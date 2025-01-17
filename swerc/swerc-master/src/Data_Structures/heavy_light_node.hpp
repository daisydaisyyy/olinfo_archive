
template <typename T, long long nullvalue, T merge(T, T)>
class heavy_light_decompositor {
  struct segment_tree {
    static constexpr int left(int i) { return i * 2 + 1; }
    static constexpr int right(int i) { return i * 2 + 2; }
    static constexpr int root(int i) { return (i - 1) / 2; }

    vector<T> v, u;

    void update_node(int i) { v[i] = merge(v[left(i)], v[right(i)]); }

    void lazyupdate(size_t i) {
      v[i] += u[i];
      if(i < v.size() / 2) {
        u[right(i)] += u[i] / 2;
        u[left(i)] += u[i] / 2;
      }
      u[i] = 0;
    }

    void build(const vector<T>& source) {
      int l;
      for(l = 1; 1 << l < (int)source.size(); l++)
        ;
      v.resize((1 << (l + 1)) - 1, nullvalue);
      u.resize(v.size(), 0);
      for(size_t i = 0; i < source.size(); i++)
        v[i + v.size() / 2] = source[i];
      for(int i = v.size() / 2 - 1; i >= 0; i--)
        v[i] = merge(v[left(i)], v[right(i)]);
    }

    int a, b;
    T query_(int i, int l, int r) {
      lazyupdate(i);
      if(l >= a && r <= b)
        return v[i];
      if(r < a || l > b)
        return nullvalue;
      int m = (l + r) / 2;
      return merge(query_(left(i), l, m), query_(right(i), m + 1, r));
    }

    T query(int qa, int qb) {
      if(qa > qb)
        return nullvalue;
      a = qa;
      b = qb;
      return query_(0, 0, v.size() / 2);
    }

    T off;
    void update_query(int i, int l, int r) {
      lazyupdate(i);
      if(l >= a && r <= b) {
        int x = off * (r - l + 1);
        v[i] += x;
        if(l != r) {
          u[left(i)] += x / 2;
          u[right(i)] += x / 2;
        }
        return;
      }
      if(r < a || l > b)
        return;
      int m = (l + r) / 2;
      update_query(left(i), l, m);
      update_query(right(i), m + 1, r);
      update_node(i);
    }

    void range_add(int qa, int qb, T k) {
      a = qa, b = qb, off = k;
      update_query(0, 0, v.size() / 2);
    }
  };

  struct node;

  struct edge {
    node* to;
    T w;
  };

  struct chain : segment_tree {
    node* up;
    int level;
    vector<T> source;
    void build() { segment_tree::build(source); }
    chain(node* up, int level) : up(up), level(level) {}
  };

  struct node {
    chain* ch;
    int index;
    vector<edge> e;
    int size = 1;
    int size_dfs(node* from) {
      for(edge& x : e)
        if(x.to != from)
          size += x.to->size_dfs(this);
      return size;
    }

    edge* get_heavy(node* from) {
      edge* best = 0;
      for(edge& x : e)
        if(x.to != from)
          if(best == 0 || x.to->size > best->to->size)
            best = &x;
      return best;
    }

    void build_chain(node* from, chain* c) {
      index = c->source.size() - 1; // this is the last in the segment tree
      ch = c;
      if(size == 1)
        return c->build();
      edge* h = get_heavy(from);
      c->source.push_back(h->w);
      h->to->build_chain(this, c);
      for(edge& x : e)
        if(&x != h && x.to != from) {
          chain* next = new chain(this, c->level + 1);
          next->source.push_back(x.w);
          x.to->build_chain(this, next);
        }
    }
  };

  struct hld : vector<node> {
    T query(int qa, int qb) {
      node* a = this->data() + qa;
      node* b = this->data() + qb;
      T ans = 0;
      if(a->ch->level < b->ch->level)
        swap(a, b);
      while(a->ch->level > b->ch->level) {
        ans = merge(ans, a->ch->query(0, a->index));
        a = a->ch->up;
      }
      while(a->ch != b->ch) {
        ans = merge(merge(ans, a->ch->query(0, a->index)),
                    b->ch->query(0, b->index));
        a = a->ch->up;
        b = b->ch->up;
      }
      if(a->index > b->index)
        swap(a, b);
      ans = merge(ans, a->ch->query(a->index + 1, b->index));
      return ans;
    }
    void update_path(int qa, int qb, T k) {
      node* a = this->data() + qa;
      node* b = this->data() + qb;
      if(a->ch->level < b->ch->level)
        swap(a, b);
      while(a->ch->level > b->ch->level) {
        a->ch->range_add(0, a->index, k);
        a = a->ch->up;
      }
      while(a->ch != b->ch) {
        a->ch->range_add(0, a->index, k);
        b->ch->range_add(0, b->index, k);
        a = a->ch->up;
        b = b->ch->up;
      }
      if(a->index > b->index)
        swap(a, b);
      a->ch->range_add(a->index + 1, b->index, k);
    }
    void setup() {
      this->front().size_dfs(nullptr);
      chain* c = new chain(0, 0);
      c->source.push_back(0);
      this->front().build_chain(0, c);
    }
  };
  hld g;

public:
  heavy_light_decompositor(vector<tuple<int, int, T>> tree) {
    g.resize(tree.size() + 1);
    for(auto t : tree) {
      int a, b;
      T c;
      tie(a, b, c) = t;
      g[a].e.push_back({&g[b], c});
      g[b].e.push_back({&g[a], c});
    }
    g.setup();
  }
  T query(int a, int b) { return g.query(a, b); }
  void update(int a, int b, T k) { g.update_path(a, b, k); }
};
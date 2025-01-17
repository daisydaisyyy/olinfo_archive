template <typename Iter>
static void insertion_sort(Iter from, Iter to) {
  for(auto i = from + 1; i < to; ++i) {
    auto temp = *i;
    auto j = i - 1;
    while(j >= from && *j > temp) {
      *(j + 1) = *j;
      --j;
    }
    *(j + 1) = temp;
  }
}

template <typename T, typename Iter>
static size_t partition(Iter from, Iter to, T pivot) {
  auto i = from, pos = from;
  for(auto j = from; j < to; ++j) {
    if(*j <= pivot) {
      swap(*(i++), *j);
      if(*j == pivot)
        pos = i - 1;
    }
  }
  swap(*pos, *(--i));
  return i - from;
}

template <typename T, typename Iter>
T introselect(Iter from, Iter to, size_t nth) {
  if(to - from <= 1)
    return *from;

  vector<T> medians;
  for(size_t i = 0; i < size_t(to - from); i += 5) {
    size_t next_i = min(size_t(to - from), i + 5);
    insertion_sort(from + i, from + next_i);
    medians.push_back(*(from + (i + next_i) / 2));
  }

  auto x = introselect<T>(medians.begin(), medians.end(),
                          medians.size() / 2);
  size_t cut = partition(from, to, x);

  if(nth == cut)
    return *(from + cut);
  else if(nth < cut)
    return introselect<T>(from, from + cut, nth);
  else
    return introselect<T>(from + cut + 1, to,
                          nth - cut - 1);
}

#ifndef FONTFACTORYHASHSPECIALIZATION_HXX
#define FONTFACTORYHASHSPECIALIZATION_HXX

namespace combine {
  template<typename T>
  void
  hash_combine(std::size_t &seed, T const &key) {
    std::hash<T> hasher;
    seed ^= hasher(key) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
  }

}

namespace std {

  template<typename T1, typename T2>
  struct hash<std::pair<T1, T2>> {
    std::size_t operator()(std::pair<T1, T2> const &p) const {
      std::size_t seed(0);
      combine::hash_combine(seed, p.first);
      combine::hash_combine(seed, p.second);
      return seed;
    }
  };
}


#endif // FONTFACTORYHASHSPECIALIZATION_HXX

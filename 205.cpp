/*
Даны две строки s и t. Определите, изоморфны ли они.
Две строки s и t изоморфны, если символы в s можно заменить, чтобы получить t.
Все вхождения символа должны быть заменены другим символом с сохранением порядка символов. Никакие два символа не могут сопоставляться одному и тому же символу, но символ может сопоставляться сам с собой.
*/

bool is_isomorphic(std::string s, std::string t) {
  if (s.size() != t.size()) 
    return false;

  std::unordered_map<char, char> map_s, map_t;

  for (int i = 0; i < s.size(); ++i) 
  {
      char a = s[i], b = t[i];

      // s -> t
      if (map_s.count(a) && map_s[a] != b)
        return false;
      
      // t -> s
      if (map_t.count(b) && map_t[b] != a)
        return false;

      map_s[a] = b;
      map_t[b] = a;
  }
  
  return true;
}

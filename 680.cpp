// Учитывая строку s, верните true, если s может быть 
// палиндромом после удаления из нее не более одного символа.

bool is_palidrome(const string& s, int left, int right) {
    while (left < right) 
    {
        if (s[left] != s[right])
            return false;
      
        ++left;
        --right;
    }
  
    return true;
}

bool valid_palidrome(string s) {
    int i = 0, j = s.size() - 1;
    
    while (i < j) 
    {
      // Проверяем, можно ли пропустить один символ с каждой стороны
      if (s[i] != s[j])
          return is_palidrome(s, i + 1, j) || is_palidrome(s, i, j - 1);
      ++i;
      --j;
    }
  
    return true; 
}

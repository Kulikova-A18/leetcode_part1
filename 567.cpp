/*
Учитывая две строки s1 и s2, верните true, если s2 содержит 
Перестановка s1 или false в противном случае.
Другими словами, верните true, если одна из перестановок s1 является подстрокой s2.
*/

bool checkInclusion(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    if (n > m) 
      return false;

    vector<int> cnt1(26, 0), cnt2(26, 0);
    
    // частота символов в s1 и в первой части s2
    for (int i = 0; i < n; ++i) 
    {
        cnt1[s1[i] - 'a']++;
        cnt2[s2[i] - 'a']++;
    }

    // совпадают ли частоты ?
    if (cnt1 == cnt2) return true;

    // сдвиг окна по s2
    for (int i = n; i < m; ++i) 
    {
        cnt2[s2[i] - 'a']++;           // + новый символ
        cnt2[s2[i - n] - 'a']--;       // - старый символ

        if (cnt1 == cnt2) 
          return true; // совпадают ли ?
    }

    return false;
}

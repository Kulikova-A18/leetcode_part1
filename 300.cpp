// Учитывая целочисленный массив nums, верните длину самого длинного, строго увеличивающегося последовательность

int len_list(std::vector<int>& nums) {
  if (nums.empty()) 
    return 0;

  std::vector<int> lis;
  
  for (const int& num : nums) 
  {
    auto it = std::lower_bound(lis.begin(), lis.end(), num);
    
    if (it == lis.end()) 
        lis.push_back(num);
    else 
        *it = num;
    }
  }
  
  return lis.size();
}

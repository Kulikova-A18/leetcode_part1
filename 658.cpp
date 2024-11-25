/*
Учитывая отсортированный массив целых чисел arr, два целых числа k и x, верните k ближайших к x целых чисел в массиве. Результат также следует отсортировать по возрастанию.
Целое число a ближе к x, чем целое число b, если:
|а - х| < |b - x|, или
|а - х| == |б - х| и а < б
*/

vector<int> find_close_element(vector<int>& arr, int k, int x) {
    auto it = lower_bound(arr.begin(), arr.end(), x);
  
    int left_part = it - arr.begin() - 1;
    int right_part = it - arr.begin();

    vector<int> ans;
    while (k--) 
    {
        if (left_part < 0)                                                ans.push_back(arr[right_part++]);
        else if (right_part >= arr.size())                                ans.push_back(arr[left_part--]);
        else if (abs(arr[left_part] - x) <= abs(arr[right_part] - x))     ans.push_back(arr[left_part--]);
        else                                                              ans.push_back(arr[right_part++]);
    }

    sort(ans.begin(), ans.end());
    return ans;
}

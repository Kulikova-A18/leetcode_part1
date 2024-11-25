/*
Учитывая массив интервалов, где интервалы[i] = [starti, endi], 
объедините все перекрывающиеся интервалы и верните массив непересекающихся 
интервалов, охватывающих все интервалы во входных данных.
*/

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty()) 
      return {};

    sort(intervals.begin(), intervals.end()); // Сортируем интервалы по началу
    
    vector<vector<int>> merged;
    merged.push_back(intervals[0]); // Добавляем первый интервал

    for (int i = 1; i < intervals.size(); ++i) 
    {
        // Если текущий интервал пересекается с последним в merged
        if (merged.back()[1] >= intervals[i][0]) 
        {
            merged.back()[1] = max(merged.back()[1], intervals[i][1]); // Сливаем интервалы
        } else 
        {
            merged.push_back(intervals[i]); // Если нет пересечения, добавляем новый интервал
        }
    }
    
    return merged;
}

// Учитывая двоичный массив nums, вам следует удалить из него один элемент.
// Возвращает размер самого длинного непустого подмассива, содержащего только 1 в результирующем массиве. Верните 0, если такого подмассива нет.

int longest_sub_array(vector<int>& nums) {
    int max_len = 0;
    int current_len = 0;
    int previous_zero_index = -1;
    int zero_count = 0;

    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == 1) 
        {
            current_len++;
        }
        else 
        {
            zero_count++;
            if (zero_count > 1) {
                max_len = max(max_len, current_len);
                while (zero_count > 1) {
                    if (nums[i - current_len] == 0) {
                        zero_count--;
                    }
                    current_len--;
                }
            }
            current_len++;
        }
    }

    return max(max_len, current_len);
}

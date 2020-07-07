/*
 * Как в этой задаче использовать динамику я не придумал.
 *
 * Идея - операция прибавления числа ко всем элементам вектора
 * кроме одного тождественна вычитанию того же числа из этого
 * элемента. Далее, за одну операцию мы приближаем к равенству 
 * всех элементов только один элемент. Пусть С - нужное одинаковое 
 * количество шоколадок. Тогда искомое количество операций равно:
 * 
 * min (sum(num_op(arr[i]->C)))
 *
 * Количество операций для приведения одного элемента к С считается за O(1).
 * Нужное С лежит в диапазоне от минимального элемента arr
 * до (arr - 5). Больший диапазон не имеет смысла в силу цикличности.
 *
*/

int ops_number(int num) {
    int ret = num / 5;
    num %= 5;
    ret += num / 2;
    num %= 2;
    ret += num;

    return ret;
}

// Complete the equal function below.
int equal(vector<int> arr) {
    int min_value = *min_element(begin(arr), end(arr));

    int result = numeric_limits<int>::max();
    for (int value = min_value; value > min_value - 5; --value) {
        int ops = 0;
        for (auto elem : arr) {
            ops += ops_number(elem - value);
        }
        result = min(result, ops);
    }

    return result;
}

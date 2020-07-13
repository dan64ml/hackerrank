/*
 * Брутфорс дает сложность O(n^3), неинтересно.
 * Используем частичные суммы: S(i) = sum(arr[n]) n = [0,i].
 * Очевидно, что сумма подмассива S(l,r) = S(r) - S(l - 1). Нам надо для
 * каждого r найти l, для которого такая сумма максимальна. Очевидно это
 * справедливо для минимального S(l) в диапазоне от 0 до r - 1. Это дает 
 * сложность O(n) по времени и по памяти.
 * 
 * Вторая часть вообще делается за один проход: суммируем положительные 
 * элементы и одновременно ищем максимальный отрицательный. На случай если
 * массив не содержит положительных значение. O(n).
 *
*/

// Complete the maxSubarray function below.
vector<int> maxSubarray(vector<int> arr) {
    int max_subarr = numeric_limits<int>::min();
    vector<int> subsum(arr.size() + 1, 0);
    for (int i = 0; i < arr.size(); ++i) {
        subsum[i + 1] = subsum[i] + arr[i];
    }

    int min_subsum = 0;
    for (int r = 1; r < subsum.size(); ++r) {
        max_subarr = max(max_subarr, subsum[r] - min_subsum);
        min_subsum = min(min_subsum, subsum[r]);
    }

    int max_subseq = 0;
    int max_negative = numeric_limits<int>::min();
    for (auto elem : arr) {
        max_subseq += (elem > 0 ) ? elem : 0;
        if (elem < 0) {
            max_negative = max(max_negative, elem);
        }
    }
    max_subseq = (max_subseq == 0) ? max_negative : max_subseq;

    return {max_subarr, max_subseq};
}

# 15-compareSearches
# result 1 image
![Compare Search {result 1 image}](https://github.com/user-attachments/assets/7db004cc-a68a-48ca-b976-6c482c7a4b99)
# result 2 image
![compare Search {result 2 image}](https://github.com/user-attachments/assets/9229c499-1fa7-4b78-a938-f9b9fcd31488)
# result 3 image
![compare Search {result 3 image}](https://github.com/user-attachments/assets/f3b1a2a7-1123-4f74-9a9d-bde30f38cd77)

# 순차탐색, 퀵정렬, 이진탐색의 비교
비교 결과 요약

A (순차 탐색의 평균 비교 횟수):
순차 탐색은 배열을 처음부터 끝까지 탐색하므로, 최악의 경우 배열 크기(SIZE)에 비례하는 비교 횟수를 소모합니다.
평균적으로 약 SIZE/2에 해당하는 비교가 발생합니다.

B (퀵 정렬의 비교 횟수):
퀵 정렬은 분할 정복 방식을 사용하여 효율적으로 배열을 정렬합니다.
평균 시간 복잡도는 𝑂(𝑛log𝑛)으로, 순차 탐색에 비해 정렬 자체의 비교 횟수는 더 낮은 편입니다.

C (이진 탐색의 평균 비교 횟수):
이진 탐색은 배열이 정렬되어 있어야만 사용할 수 있으며, 탐색 과정에서 배열의 탐색 범위를 절반씩 줄입니다.
평균 시간 복잡도는 𝑂(log𝑛)으로, 순차 탐색보다 훨씬 적은 비교 횟수를 소모합니다.

# A, B, C에 대해서 퀵 정렬후의 이진탐색에서 순차탐색보다 적게 비교하는 이유를 설명
1. 퀵 정렬로 배열을 정렬:
퀵 정렬 과정에서 𝑂(𝑛log𝑛)의 비교 횟수가 발생하지만, 정렬이 한 번만 수행되므로 이후 탐색 작업에서는 영향을 미치지 않습니다.
2. 이진 탐색의 효율성:
정렬된 배열에서 이진 탐색은 단일 탐색당 𝑂(log𝑛)의 비교 횟수를 소모합니다. 이는 배열을 처음부터 끝까지 탐색하는 𝑂(𝑛)의 순차 탐색과 비교할 때, 큰 성능 차이를 보입니다.
100회의 탐색에서도 100×logn만큼의 비교 횟수로 작업을 수행할 수 있습니다.
3. 순차 탐색과의 비교:
순차 탐색은 배열이 정렬되지 않은 상태에서도 작동하지만, 각 탐색당 𝑂(𝑛)의 비교가 필요합니다. 이는 데이터 크기 증가에 따라 비교 횟수가 급격히 증가함을 의미합니다.

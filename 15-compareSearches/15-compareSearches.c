#include <stdio.h>  
#include <stdlib.h> 
#include <time.h>   /
#define SIZE 1000   // 배열 크기를 1000으로 정의
#define SWAP(x, y, temp) ((temp) = (x), (x) = (y), (y) = (temp)) // 두 값을 교환하는 매크로

// 전역 변수: 비교 횟수를 저장
int compareCount = 0;

// 배열의 일부를 출력하는 함수
void printArray(int* array) {
    printf("Array Sorting Result:\n");
    for (int i = 0; i < 20; i++) // 배열의 처음 20개 값 출력
        printf("%3d ", array[i]);
    printf("\n");
    for (int i = SIZE - 20; i < SIZE; i++) // 배열의 마지막 20개 값 출력
        printf("%3d ", array[i]);
    printf("\n");
}

// 랜덤한 값으로 배열을 채우는 함수
void generateRandomArray(int data[]) {
    for (int i = 0; i < SIZE; i++) {
        data[i] = rand() % 1000; // 0부터 999 사이의 랜덤 값을 생성하여 배열에 저장
    }
}

// 이진 탐색 함수: 정렬된 배열에서 `key`를 찾음
int search_binary2(int array[], int key, int low, int high) {
    int middle;
    while (low <= high) {
        middle = (low + high) / 2; // 중간 인덱스를 계산
        compareCount++;           // 비교 횟수 증가
        if (key == array[middle]) // 값이 발견되면 인덱스 반환
            return middle;
        else if (key > array[middle]) // 탐색 범위를 오른쪽 절반으로 좁힘
            low = middle + 1;
        else                          // 탐색 범위를 왼쪽 절반으로 좁힘
            high = middle - 1;
    }
    return -1; // 값을 찾지 못하면 -1 반환
}

// 선형 탐색 함수: 배열에서 `key`를 찾음
int seq_search(int array[], int key) {
    for (int i = 0; i < SIZE; i++) {
        compareCount++; // 비교 횟수 증가
        if (array[i] == key) // 값이 발견되면 인덱스 반환
            return i;
    }
    return -1; // 값을 찾지 못하면 -1 반환
}

// Quick Sort의 파티션 함수: 피벗을 기준으로 배열을 분할
int partition(int list[], int left, int right) {
    int pivot, temp;
    int low, high;

    low = left;          // 왼쪽 포인터 초기화
    high = right + 1;    // 오른쪽 포인터 초기화
    pivot = list[left];  // 왼쪽 첫 번째 값을 피벗으로 선택
    do {
        do {
            low++;                     // 왼쪽 포인터 이동
            compareCount++;            // 비교 횟수 증가
        } while (low <= right && list[low] < pivot); // 피벗보다 큰 값을 찾을 때까지 이동
        do {
            high--;                    // 오른쪽 포인터 이동
            compareCount++;            // 비교 횟수 증가
        } while (high >= left && list[high] > pivot); // 피벗보다 작은 값을 찾을 때까지 이동
        if (low < high) {              // low와 high가 교차하지 않았다면 값 교환
            SWAP(list[low], list[high], temp);
        }
    } while (low < high);              // low와 high가 교차할 때까지 반복

    SWAP(list[left], list[high], temp); // 피벗 값을 적절한 위치로 이동
    return high;                        // 피벗의 최종 위치 반환
}

// Quick Sort를 수행하는 함수 (재귀 호출 사용)
void doQuickSort(int list[], int left, int right) {
    if (left < right) { // 배열의 크기가 1보다 큰 경우에만 실행
        int q = partition(list, left, right); // 배열을 분할
        doQuickSort(list, left, q - 1);       // 왼쪽 부분 정렬
        doQuickSort(list, q + 1, right);      // 오른쪽 부분 정렬
    }
}

// Quick Sort를 실행하고 비교 횟수를 계산하는 함수
void getQuickSortCompareCount(int array[]) {
    compareCount = 0;                     // 비교 횟수 초기화
    doQuickSort(array, 0, SIZE - 1);      // Quick Sort 실행
}

// 선형 탐색의 평균 비교 횟수를 계산하는 함수
double getAverageLinearSearchCompareCount(int array[]) {
    int totalCompareCount = 0; // 총 비교 횟수
    for (int i = 0; i < 100; i++) { // 100번 반복
        int target = array[rand() % SIZE]; // 배열에서 랜덤한 값을 선택
        compareCount = 0;                  // 비교 횟수 초기화
        seq_search(array, target);         // 선형 탐색 실행
        totalCompareCount += compareCount; // 비교 횟수 누적
    }
    return (double)totalCompareCount / 100; // 평균 비교 횟수 반환
}

// 이진 탐색의 평균 비교 횟수를 계산하는 함수
double getAverageBinarySearchCompareCount(int array[]) {
    int totalCompareCount = 0; // 총 비교 횟수
    for (int i = 0; i < 100; i++) { // 100번 반복
        int target = array[rand() % SIZE]; // 배열에서 랜덤한 값을 선택
        compareCount = 0;                  // 비교 횟수 초기화
        search_binary2(array, target, 0, SIZE - 1); // 이진 탐색 실행
        totalCompareCount += compareCount; // 비교 횟수 누적
    }
    return (double)totalCompareCount / 100; // 평균 비교 횟수 반환
}

// 메인 함수: 프로그램 실행 시작점
int main(int argc, char* argv[]) {
    srand((unsigned int)time(NULL)); // 랜덤 시드 초기화

    int array[SIZE]; // 배열 선언

    generateRandomArray(array); // 배열에 랜덤 값 생성

    // 선형 탐색의 평균 비교 횟수 출력
    printf("Average Linear Search Compare Count: %.2f\n",
        getAverageLinearSearchCompareCount(array));

    // Quick Sort를 수행하고 비교 횟수 출력
    getQuickSortCompareCount(array);
    printf("Quick Sort Compare Count: %d\n", compareCount);

    // 이진 탐색의 평균 비교 횟수 출력
    printf("Average Binary Search Compare Count: %.2f\n\n",
        getAverageBinarySearchCompareCount(array));

    // 정렬된 배열의 일부 출력
    printArray(array);

    return 0; // 프로그램 종료
}

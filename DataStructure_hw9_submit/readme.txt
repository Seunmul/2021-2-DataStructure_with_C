1)
search.c를 main.c로 두고
search_heap.h를 같이 컴파일 하시면 됩니다.

테스트 파일은 test.txt이고
MAXDATA 변경-> 각 배열의 크기를 조정 할 수 있습니다.
binary search의 정렬은 heapSort를 이용했고 정렬 후 binary search를 구현하였습니다.
157줄의 주석을 제거하면 내림차순으로 출력되는데 이는 끝에서부터 내림차순으로 출력됨을 의미합니다. 
그러니까 실제로는 앞에서 부터 오름차순으로 정렬됨을 확인 할 수 있습니다.

hashed search 에서 HASH 함수는 :  MAXDATA-((int)key%MAXDATA)-1;
Collision 처리는 Linked List 방식입니다.  113줄의 주석을 제거하면 key입력에 따른 HASH함수  값을 알 수 있습니다.
132줄의 주석을 제거하면 현재 키의 입력에 따라 해당 위치에 데이터 유무를 확인 가능합니다.

2) sort.c 를 컴파일 하시면 됩니다. 테스트 파일은 test2.txt 입니다.
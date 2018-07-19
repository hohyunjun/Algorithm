## Queue 기초
    한쪽 끝에서만 자료를 넣고 다른 한쪽 끝에서만 뺄 수 있는 자료구조
    먼저 넣은 것이 먼저 나오기 때문에 First In First Out(FIFO) 라고도 한다.
    push : 큐에 자료를 넣는 연산
    pop : 큐에서 자료를 빼는 연산
    front : 큐의 가장 앞에 있는 자료를 보는 연산
    back : 큐의 가장 뒤에 있는 자료를 보는 연산
    empty : 큐가 비어있는지 아닌지를 보는 연산
    size : 큐에 저장되어있는 자료의 개수를 알아보는 연산

## Queue 활용
    큐는 C++의 경우에는 STL의 queue 사용
    queue의 begin은 첫번째 자료의 인덱스
    queue의 end는 마지막 data + 1
    queue의 push 시에, queue[end] = val; end += 1;
    queue의 pop은 queue[begin] = 0; begin += 1;
    queue의 size는 end-begin;
    queue의 empty는 end==begin인지를 체크한다.

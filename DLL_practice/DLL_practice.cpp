#include <iostream>
#include "linklist.h"
#include "CompleteBST.h"


int main()
{
    //DoubleLinkedList list;

    //cout << "초기 리스트 상태: ";
    //list.display();

    //// 1. 앞쪽에 데이터 삽입 (A, B, C)
    //cout << "\n앞쪽에 데이터 삽입 (A, B, C)\n";
    //list.insertHead("A");
    //list.insertHead("B");
    //list.insertHead("C");
    //list.display();

    //// 2. 뒤쪽에 데이터 삽입 (D, E)
    //cout << "\n뒤쪽에 데이터 삽입 (D, E)\n";
    //list.insertTail("D");
    //list.insertTail("E");
    //list.display();

    //// 3. 노드 'B' 뒤에 'X' 삽입
    //cout << "\n노드 'B' 뒤에 'X' 삽입\n";
    //Node* nodeB = list.find("B");
    //if (nodeB) list.insert("X", nodeB);
    //list.display();

    //// 4. 'X' 노드 뒤에 'Y' 삽입
    //cout << "\n노드 'X' 뒤에 'Y' 삽입\n";
    //Node* nodeX = list.find("X");
    //if (nodeX) list.insert("Y", nodeX);
    //list.display();

    //// 5. 중간 노드 삭제: 'X' 삭제
    //cout << "\n노드 'X' 삭제\n";
    //list.remove("X");
    //list.display();

    //// 6. 앞쪽 데이터 삭제
    //cout << "\n앞쪽 데이터 삭제\n";
    //list.removeHead();
    //list.display();

    //// 7. 뒤쪽 데이터 삭제
    //cout << "\n뒤쪽 데이터 삭제\n";
    //list.removeTail();
    //list.display();

    //// 8. 리스트가 비어있는지 확인
    //cout << "\n리스트가 비어있는지 확인\n";
    //if (list.isEmpty()) {
    //    cout << "리스트가 비어 있습니다.\n";
    //}
    //else {
    //    cout << "리스트에 데이터가 존재합니다.\n";
    //}

    //// 9. 리스트가 비어 있을 때 노드 삽입
    //cout << "\n리스트가 비어 있을 때 'Z' 삽입\n";
    //list.insertHead("Z");
    //list.display();

    //// 10. 삭제 후 빈 리스트 상태 확인
    //cout << "\n모든 노드 삭제 후 상태 확인\n";
    //list.removeHead();
    //list.removeHead();
    //list.removeHead();
    //list.removeHead();  // 빈 리스트에서 삭제 시도
    //list.display();

    //// 11. 데이터 삽입 후 앞뒤 순서 확인
    //cout << "\n앞에 'A', 뒤에 'B' 삽입 후 앞뒤 순서 확인\n";
    //list.insertHead("A");
    //list.insertTail("B");
    //list.display();

    //// 12. 'A'와 'B' 위치 확인
    //cout << "\n'B' 앞에 위치한 노드: " << list.content(list.front(list.find("B"))) << "\n";
    //cout << "'A' 뒤에 위치한 노드: " << list.content(list.back(list.find("A"))) << "\n";

    //// 13. 리스트 상태 확인
    //cout << "\n현재 리스트 상태: ";
    //list.display();


    CompleteBST tree;

    // 🌱 노드 삽입 테스트
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "트리 삽입 후:" << endl;
    tree.print();

    int target = 40;
    int idx = tree.search(target);
    if (idx != -1) cout << target << "은(는) 인덱스 " << idx << "에 있습니다." << endl;
    else cout << target << "을(를) 찾을 수 없습니다." << endl;

    tree.remove(30);
    cout << "30 삭제 후:" << endl;
    tree.print();

    tree.remove(50);
    cout << "50 삭제 후:" << endl;
    tree.print();


    return 0;
}


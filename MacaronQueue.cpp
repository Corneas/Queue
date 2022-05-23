#include<iostream>
#include<queue>
#include<time.h>
using namespace std;

#define ODER_TERM 15 // 고객의 주문 간격: 초 단위

#define CHEEZE     0        // 상수: 치즈마카롱
#define MILK      1        // 상수: 우유마카롱
#define CHOCO     2        // 상수: 초코마카롱

#define CHE_TERM    12       // 준비 시간(sec): 치즈
#define MILK_TERM    15       // 준비 시간(sec): 우유
#define CHOCO_TERM    24       // 준비 시간(sec): 초코

int main()
{
    int makeProc = 0; // 마카롱 제작 진행 상황
    int cheOrder = 0, milkOrder = 0, chocoOrder = 0;
    int sec;

    queue<int> q;

    srand(time(NULL));

    for (sec = 0; sec < 3600; sec++) // 1시간 동안 진행
    {
        if (sec % ODER_TERM == 0) // 15초 마다 주문을 받음
        {
            switch (rand() % 3) // 3 메뉴 중 랜덤을 주문됨
            {
            case CHEEZE:
                q.push(CHE_TERM);
                cheOrder++;
                break;

            case MILK:
                q.push(MILK_TERM);
                milkOrder++;
                break;

            case CHOCO:
                q.push(CHOCO_TERM);
                chocoOrder++;
                break;
            }
        }

        if (makeProc <= 0 && !q.empty()) {
            makeProc = q.front();
            q.pop();
        }
        makeProc--;
    }

    cout << "Simulation Report!!" << endl;
    cout << "[Order Count]" << endl;
    cout << "CHEEZE : " << cheOrder << endl;
    cout << "MILK : " << milkOrder << endl;
    cout << "CHOCOr: " << chocoOrder << endl;
    cout << "※ Waiting room size: " << q.size() << endl;


    return 0;
}
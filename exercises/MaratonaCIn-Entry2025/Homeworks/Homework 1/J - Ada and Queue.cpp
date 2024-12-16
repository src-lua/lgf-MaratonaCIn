#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    deque<int> toDo, reverse_toDo;
    int len, x;
    string action;
    int isReverse = 0;

    cin >> len;

    for (int i = 0; i < len; i++)
    {
        cin >> action;
        if (isReverse == 0) {
            if (action == "push_back") {
                cin >> x;
                toDo.push_back(x);
            }

            else if (action == "toFront") {
                cin >> x;
                toDo.push_front(x);
            }

            else if (action == "back") { 
                if (toDo.empty() == false) {
                    cout << toDo.back() << "\n";
                    toDo.pop_back();
                }
                else cout << "No job for Ada?" << "\n";
            }

            else if (action == "front") { 
                if (toDo.empty() == false) {
                    cout << toDo.front() << "\n";
                    toDo.pop_front();
                }
                else cout << "No job for Ada?" << "\n";
            }
            
            else if (action == "reverse") {
                isReverse = 1;
            }
        }
        
        else if (isReverse == 1) {
            if (action == "push_back") {
                cin >> x;
                toDo.push_front(x);
            }

            else if (action == "toFront") {
                cin >> x;
                toDo.push_back(x);
            }

            else if (action == "back") { 
                if (toDo.empty() == false) {
                    cout << toDo.front() << "\n";
                    toDo.pop_front();
                }
                else cout << "No job for Ada?" << "\n";
            }

            else if (action == "front") { 
                if (toDo.empty() == false) {
                    cout << toDo.back() << "\n";
                    toDo.pop_back();
                }
                else cout << "No job for Ada?" << "\n";
            }
            
            else if (action == "reverse") {
                isReverse = 0;
            }
        }
    }
    
    return 0;
}
#include <sstream>
#include <iostream>
#include <string>
#include <stack>

using namespace std;


bool checkString(string s)
// Pre: cert
// Post: retorna true si la string donada es una sequencia correcta de paretesis o claus, false en cas contrari
{
    bool cor = true;
    for (int x=0; x < (int) s.size(); x++){
        for (int y=0; y < (int) s.size(); y++){
             if (x == '[')
            {
            cor = false;
                cout << "e";
            }
        }
    }
    return cor;
}


int main() {
    string s;
    stack <string> stringStack;
    while (cin>>s) {
        stringStack.push(s);
    }


    while (not stringStack.empty()){
        cout << stringStack.top();
        bool correcte = true;


        if (correcte == true)
            cout << " is correct";
        else
            cout << " is incorrect";

        cout << endl;

        stringStack.pop();

    }
}

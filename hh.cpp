class Solution {
public:
    int push(int arr[], int value, int & top, int MAX){
        if(top>=MAX){
            cout << "Stack Overflow";
            return -1;
        }
        arr[++(top)] = value;
        return top;
    }

    int pop(int arr[], int & top){
        if(top < 0){
            cout << "Nothing To Pop";
            return -1;
        }
        return arr[top--];
    }

    int checkParenthesis(char paren){
    switch (paren) {
        case '(':
        return 1;
        case '{':
        return 2;
        case '[':
        return 3;
        case ')':
        return -1;
        case '}':
        return -2;
        case ']':
        return -3;
    }
    return -1;
    }

    bool isValid(string s) {
        int MAX = 10000;
        int top = -1;
        int st[MAX];
        string testPar = s;
        int sLen = testPar.size();
        int flag = 0;
        for(int i = 0; i < sLen; i++){
            int b = checkParenthesis(testPar[i]);
            if(top < 0){
            if (b < 0) {
                flag = 1;
                break;
            }
            push(st, b, top, MAX);
            }

            else if(b> 0)
            push(st, b, top, MAX);

            else if(b < 0 && !(b+ st[top]))
            pop(st, top);

            else{
            flag = 1;
            break;
            }
        }
        if(top == -1 && !flag)
            return true;
        else
            return false;

    }
};
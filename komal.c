class Solution {
private:
  int MAX = 101;
  int top = -1;

public:
  void push(int value, int &top, int st[]) {
    if (top >= MAX) {
      return;
    }
    st[++top] = value;
  }
  int pop(int st[], int &top) {
    if (top < 0) {
      return -1;
    }
    return st[top--];
  }
  string removeOuterParentheses(string s) {
    int st[MAX];
    int l = s.size();
    string decomposed = "";
    int sumParen = 0;
    for (int i = 0; i < l; i++) {
      if (sumParen == 0 && s[i] == '(')
        sumParen++;
      else if (sumParen == 1 && s[i] == ')')
        sumParen--;
      else {
        if (s[i] == '(')
          sumParen++;
        else if (s[i] == ')')
          sumParen--;
        decomposed += s[i];
      }
    }
    // for (int i = 0; i < l; i++) {
    //   if (top == -1 && s[i] == '(')
    //     push(0, top, st);
    //   else if (top == 0 && s[i] == ')')
    //     pop(st, top);
    //   else if (s[i] == '(') {
    //     push(0, top, st);
    //     decomposed += s[i];
    //   } else {
    //     pop(st, top);
    //     decomposed += s[i];
    //   }
    // }
    return decomposed;
  }
};

#include<iostream>
#include<stack>
int prec(char a);
using namespace std;
int main()
{
    stack<char> st;
    string s="a+b/c-d";
    string ans="";
    int n=s.length();
    int top;
    for(int i =0;i<n;i++)
    {
        if(s[i]>='a' && s[i]<='z')
        {
            ans+=s[i];
        }
        else{
            if(st.empty())
            {
                st.push(s[i]);
            }
            else
            {
                if(prec (s[i])>prec(st.top()))
                {
                    st.push(s[i]);
                }
                else
                {
                    while((!st.empty()) && prec (s[i])<=prec(st.top()))
                    {
                        ans+=st.top();
                        st.pop();
                       
                    }
                    st.push(s[i]);
                }

            }
            
        }
    }
    cout<<"solution is: "<<ans<<endl;
    return 0;
}
int prec(char a)
{
    switch(a)
    {
        case'-':
            return 1;
        case'+':
            return 1;
        case'*':
            return 2;
        case'/':
            return 2;
        case '%': 
            return 3;
      
        default:
            return 0;
    }
}
void brackets(char *s)
{
    int i = 0;
    while (s[i] != '\0')
    {

        if (s[i] == '(')
        {
            s[i] = ')';
        }
        else if (s[i] == ')')
        {
            s[i] = '(';
        }
        i++;
    }
}
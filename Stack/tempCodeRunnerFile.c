void reversechar(char *s)
{
    int length = strlen(s);
    int i = 0;
    int j = length - 1;
    while (i < j)
    {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
    
}
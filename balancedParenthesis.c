#include <stdio.h>
#define Max 500

int getline2(char out[]);
int balanceParenthesis(char string[], int length);

char string[Max];
int len = 0;

int main()
{
    while((len = getline2(string)) != 0)
    {
        balanceParenthesis(string, len);
        printf("%s\n", string);
    }

    return 0;
}

//get line, return length
int getline2(char out[])
{
    int c = 0;
    int i = 0;

    while( (c = getchar()) != '\n')
    {
        out[i] = c;
        i++;
    }
    out[i] = '\0';

    return i;
}

int balanceParenthesis(char in[],int length)
{
    int i = 0;
    int parenCount = 0;
    int ticked = 0;
    int balanced = 0;
    int LOCK = 0;

    while((i < length))
    {   
        if(in[i] == '(')
        {
            parenCount++;
            ticked = 1;
        }

        if((in[i] == ')') && (ticked == 1))
        {
            parenCount--;
        }

        //permanently unbalanced case bc ')' was first
        if((in[i] == ')') && (ticked == 0))
        {
            parenCount--;
            balanced = 0;
            LOCK = 1;
            i = length;
        }

        if((parenCount ==0) && (ticked ==1) && (LOCK ==0))
        {
            balanced = 1;
            ticked = 0;
        }
        else
            balanced = 0;

        i++;
    }

    if(balanced == 1)
        printf("Parenthesis are balanced!\n");

    else
        printf("Parenthesis are not balanced\n");

    return 0;

}

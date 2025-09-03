%{
    int vowelCount     = 0;
    int consonantCount = 0;
%}

%%
[aeiouAEIOU] { vowelCount++; }
[a-zA-Z]     { consonantCount++; }
\n           { return 0; }
%%

int yywrap(){}
int main()
{
    printf("Enter the string of vowels and consonants: ");
    yylex();
    printf("Number of vowels are:  %d\n", vowelCount);
    printf("Number of consonants are:  %d\n", consonantCount);
    return 0;
}
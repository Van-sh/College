%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char *s);
%}

%token NUMBER

%%
start:
    NUMBER {
        if ($1 % 2 == 0)
            printf("%d is Even\n", $1);
        else
            printf("%d is Odd\n", $1);
    }
    ;
%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    printf("Enter a number: ");
    yyparse();
    return 0;
}

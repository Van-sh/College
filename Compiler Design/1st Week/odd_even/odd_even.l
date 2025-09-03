%{
#include "odd_even.tab.h"
#include<stdlib.h>
%}

%%
[0-9]+     { yylval = atoi(yytext); return NUMBER; }
\n         { return 0; }
.          ; /* Ignore other characters */
%%

int yywrap() {
    return 1;
}

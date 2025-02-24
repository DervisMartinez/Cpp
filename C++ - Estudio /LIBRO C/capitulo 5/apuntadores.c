#include <stdio.h>
#include <ctype.h>

int getch(void);

void ungetch(int c);

/*getint: obtiene el siguiente entero de la entrada y lo asigna a *pn */
int getint(int *pn){
    int c ,sign ;

    while (isspace(c = getch())); /*ignora los espacios en blanco*/
    if(!isdigit(c) && c != EOF && c!= '+' && c != '-' ){
            ungetch(c); // no es un numero
            return 0;
    };
    sign = (c =='-')? - 1 : 1;
    if(c == '+' || c == '-'){
        c = getch();
        if(!isdigit(c)){
            ungetc(c);
            ungetch(sign == -1 ? '-' : '+');
            return 0 ; //  no es un valido
        };
    };
    for(*pn = 0 ; isdigit(c); c = getch()){
        *pn = 10 * *pn + (c - '0');
    };
    *pn *= sign ;
    if(c != EOF){'-'
        ungetch(c);
        return c ; //devuelve el ultimo caracter leido (o EOF)
    };
};


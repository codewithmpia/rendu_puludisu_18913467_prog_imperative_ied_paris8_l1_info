int main(int k) // k utlisée comme locale
{ list L = nil ;
    for (k = 'a' ; k < 'i' ; k++)
        L = cons(k, L) ;
    putlist(L) ;
    return 0 ; }

list cons(int car, list L)
{ list new = malloc(sizeof(node)) ;
    if (! new) usage("cons : manque de RAM") ; // enfin, un peu de sérieux !
    new -> car = car ;
    new -> cdr = L ;
    return new ; }

void putlist(list L)
    { if (! L) return ; // nil : fin de liste
        printf("%c ", L -> car) ;
    putlist(L -> cdr) ; }
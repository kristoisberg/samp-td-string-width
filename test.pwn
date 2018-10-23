#include "td-string-width.inc"


main() {
    printf("%i", GetTextDrawCharacterWidth('!', 2));
    
    printf("%i", GetTextDrawStringWidth("!!!", 2));
    printf("%i", GetTextDrawStringWidth("!!!!!!", 2));
    printf("%i", GetTextDrawStringWidth("!!!~n~!!!", 2));

    printf("%i", GetTextDrawStringWidth("!!!~!!!", 2));
    printf("%i", GetTextDrawStringWidth("Error: unmatched tilde", 2));

    new temp[5];

    temp[0] = 1;
    printf("%i", GetTextDrawStringWidth(temp, 3)); // 9

    temp[1] = '!';
    printf("%i", GetTextDrawStringWidth(temp, 3)); // 255 + 10 = 265

    temp[1] = EOS;
    strcat(temp, "~n~");
    printf("%i", GetTextDrawStringWidth(temp, 3)); // 9

    printf("%i", GetTextDrawLineWidth("!!!", 2));
    printf("%i", GetTextDrawLineWidth("!!!!!!", 2));

    return 1;
}
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
    printf("%i %i", GetTextDrawStringWidth(temp, 3), GetTextDrawStringWidth_s(str_new(temp), 3)); // 9

    temp[1] = '!';
    printf("%i %i", GetTextDrawStringWidth(temp, 3), GetTextDrawStringWidth_s(str_new(temp), 3)); // 255 + 10 = 265

    temp[1] = EOS;
    strcat(temp, "~n~");
    printf("%i %i", GetTextDrawStringWidth(temp, 3), GetTextDrawStringWidth_s(str_new(temp), 3)); // 9

    printf("%i %i", GetTextDrawLineWidth("!!!", 2), GetTextDrawLineWidth_s(str_new_static("!!!"), 2));
    printf("%i %i", GetTextDrawLineWidth("!!!!!!", 2)), GetTextDrawLineWidth_s(str_new_static("!!!!!!"), 2);

    printf("%i %i", GetTextDrawLineCount("aaaa"), GetTextDrawLineCount_s(str_new_static("aaaa")));
    printf("%i %i", GetTextDrawLineCount("aaaa~n~aaaa"), GetTextDrawLineCount_s(str_new_static("aaaa~n~aaaa")));
    printf("%i %i", GetTextDrawLineCount("aaaa~n~aaaa~n~aaaa"), GetTextDrawLineCount_s(str_new_static("aaaa~n~aaaa~n~aaaa")));

    SplitTest("a a a a a a a a a a a a a a a");
    SplitTest("asd asd asd asd asd asd asd");
    SplitTest("wat is going on asd asd asd");
    SplitTest("now watch me whip, now watch me nae nae");
    SplitTest("now watch me whip,~n~now watch me nae nae");
    SplitTest("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa aaa aaa");
    return 1;
}


SplitTest(const string[]) {
    new buffer[128];
    strcat(buffer, string);

    SplitTextDrawString(buffer, 100.0, 1.0, 0);
    printf("%s %i %i", buffer, GetTextDrawStringWidth(buffer, 0), GetTextDrawLineCount(buffer));

    new String:string2 = str_new(string);
    SplitTextDrawString_s(string2, 100.0, 1.0, 0);
    str_get(string2, buffer);
    printf("%s %i %i", buffer, GetTextDrawStringWidth_s(string2, 0), GetTextDrawLineCount_s(string2));
}

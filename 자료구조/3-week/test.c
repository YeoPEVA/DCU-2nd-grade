int check_matching(const char *in)
{
    StackType s;
    char ch, open_ch;
    int i, n = strlen(in); // n= 문자열의 길이
    init_stack(&s); // 스택의 초기화
    for (i = 0; i < n; i++) {
        ch = in[i]; // ch = 다음 문자
        switch (ch) {
            case '(': case '[': case '{':
                push(&s, ch);
                break;
            case ')': case ']': case '}':
                if (is_empty(&s)) return 0;
                else{
                    open_ch = pop(&s);
                    if ((open_ch == '(' && ch != ')') || (open_ch == '[' && ch != ']') || (open_ch == '{' && ch != '}')) {
                        return 0;
                    }
                }
                break;

        }
    }
}

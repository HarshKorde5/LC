bool isValid(char *s) 
{

    // Use beginning of input s as storage for our stack
    // So s will be mutated, but stack never grows faster than we increment through s
    // Stack is empty when stack_top == s
    // And stack_top - s equals the number of items in the stack
    char *stack_top = s;

    for (char *p=s; *p; p++) 
        switch(*p)
        {                
            case '(': 
                *stack_top++ = ')';
            continue; // push matching chars onto stack
            case '{': 
                *stack_top++ = '}';
            continue;
            case '[': 
                *stack_top++ = ']';
            continue;
            default:
                
                // Fail if stack is empty before end of input, to handle "())" 
                if (0 == stack_top-s)
                    return false;
                
                // Pop expected matching char from stack
                char expected_ch = *--stack_top;
                
                // Fail if current char does not match expected char, to handle "[(])"
                if (*p != expected_ch) 
                    return false;
        }
    
    // Success if we finish with an empty stack
    return 0 == stack_top-s;
    
}
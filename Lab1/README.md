# Lexical Analyzer

This project implements a **Lexical Analyzer** that separates text based on special characters and spaces according to specified rules. It processes input files and generates outputs where tokens are neatly organized.

---

## Rules
1. **Special Characters**:  
   - Each special character is printed on a separate line.
2. **Spaces**:  
   - All spaces are removed from the input.
3. **Keywords and Variables**:  
   - Preserved and printed as written, without any modifications.

---

## How It Works
1. The input is read line by line.
2. Spaces are removed entirely.
3. Special characters are identified and separated into individual lines.
4. Keywords and variables are preserved and output exactly as written.

---

## Example

### Input (`test/input.md`):
```markdown
int x = 10; // This is a variable
if (x > 5) {
  printf("Hello, World!");
}

### Output:
int
x
=
10
;
//
This
is
a
variable
if
(
x
>
5
)
{
printf
(
"Hello, World!"
)
}

## README

This script is a simple bash script that performs two different tasks: grading and basic calculator operations.

## Grading

The script allows you to enter a numerical grade and it will output the corresponding letter grade. Here's how it works:

1. The user is prompted to enter a grade value.
2. The script uses a `case` statement to evaluate the entered grade value and execute the corresponding code block based on the conditions specified.
3. The following grading criteria are used:
   - If the grade is exactly 100, it prints "A+ grade".
   - If the grade is in the range of 90-99, it prints "A grade".
   - If the grade is in the range of 0-59, it prints "D grade".
   - If the grade is in the range of 60-69, it prints "C grade".
   - If the grade is in the range of 70-79, it prints "B grade".
   - If the grade is in the range of 80-89, it prints "B+ grade".
   - If none of the above conditions are met, it prints "Wrong input".

## Calculator

The script also includes a simple calculator functionality. Here's how it works:

1. The user is prompted to enter two numbers.
2. The user is then asked to choose an operation to perform on the two numbers: addition, subtraction, multiplication, or division.
3. The script uses a `case` statement to evaluate the chosen operation and execute the corresponding code block based on the conditions specified.
4. The result of the operation is calculated and stored in the `result` variable.
5. Finally, the script displays the calculated result to the user.

Please note that this script assumes valid input from the user and doesn't handle any potential errors or edge cases.

To run the script, simply execute it in a bash environment or shell and follow the prompts and instructions provided.

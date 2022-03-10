# Interpreter-BrainFuck
## Description 
---
Program interprets file with extention .bf.  
You can give a name to file or path of program. 
For example: 

> ++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++
> .>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.
> ------.--------.>+.>.  

This brainfuck code show "Hello World!".

## A little help about language
---
Brainfuck have 8 commands:  

| Command | Doing | Analog |
|:-:|---|---|
| \> | Increment data pointer | `i++` |
| < | Decrement data pointer  | `i--` |
| + | Increment the byte in the pointer | `arr[i]++` | 
| - | Decrement the byte in the pointer | `arr[i]--` |
| . | Output from the byte in the pointer | `cout >> arr[i]` |
| , | Accept one byte of input, storing its value in the byte at the pointer. | `cin << arr[i]` |
| [ | If the byte in pointer equal zero, then instead of moving the instruction pointer forward to the next command, jump it forward to the command after the matching `]`| `while (arr[i]) {` |
| ] | If the byte at the data pointer is nonzero, then instead of moving the instruction pointer forward to the next command, jump it back to the command after the matching `[` command. | `}` |

The language is fully Turing complete.
## How use
---
You have a several way to use executable file:  
### 1. Easy way
1. Run .exe file  
2. Program show "Enter file name or path: "
3. Enter that
4. If file is correct, you see result

### 2. Command line way
1. Enter in command line "...\Interpreter.exe [name or path file]
2. You see result  
   
P.S. this way can be used for automatic run code in VS Code.

## Test

Repository has [`Bf/test.bf`](./Bf/test.bf) file with brainfuck code showing "*Hello World!*"

## Settings
---
Repository has [`Settings.txt`](./Settings.txt) file for easy setup default path to file and limited working time. 


Default path lets you enter only file name.  
In *Settings.txt* **DefaultPath** contains path to directory with your *.bf* file.  
Default: `..Bf/`

If working time will exceed **TimeOut** defined in *Setting.txt* program close and put out error. This is to avoid code doesn\`t work well or doesn\`t work as you think.  
Default: `5` seconds
#	Minishell [kbeceren - aabda]


This minishell uses GNU readline. It was tested with version 8.1 and might not work on earlier versions. To install it on schools' Mac, install homebrew, and then readline.
```
rm -rf $HOME/.brew && git clone --depth=1 https://github.com/Homebrew/brew $HOME/.brew && echo 'export PATH=$HOME/.brew/bin:$PATH' >> $HOME/.zshrc && source $HOME/.zshrc && brew update brew install readline
```
Then, export header and lib files to compilation and linking flags.
```
export CFLAGS="-I/Users/$USER/.brew/opt/readline/include"
export LFLAGS="-L/Users/$USER/.brew/opt/readline/lib"
```
Compile and run

make
./minishell

The function readline () prints a prompt and then reads and returns a single line of text from the user. The line readline returns is allocated with malloc (); you should free () the line when you are done with it. The declaration for readline in ANSI C is

```char *readline (char *prompt);```

So, one might say

```char *line = readline ("Enter a line: ");```

in order to read a line of text from the user. The line returned has the final newline removed, so only the text remains.
If readline encounters an EOF while reading the line, and the line is empty at that point, then (char *)NULL is returned. Otherwise, the line is ended just as if a newline had been typed.

If you want the user to be able to get at the line later, (with C-p for example), you must call add_history () to save the line away in a history list of such lines.

```add_history (line);```

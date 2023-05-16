Simple shell is a unix like command line interpreter. This program reads commands from the user, tokenizes them, and executes the commands using "execve" system call.

	Tasks:
	1. Write a UNIX command line interpreter.
		Your Shell should:

			Display a prompt and wait for the user to type a command. A command line always ends with a new line.
			The prompt is displayed again each time a command has been executed.
			The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
			The command lines are made only of one word. No arguments will be passed to programs.
			If an executable cannot be found, print an error message and display the prompt again.
			Handle errors.
			You have to handle the “end of file” condition (Ctrl+D)
	2. Handle command lines with arguments.
	3. Handle the PATH.
	4. Implement the exit built-in, that exits the shell.
	5. Implement the env built-in, that prints the current environment.


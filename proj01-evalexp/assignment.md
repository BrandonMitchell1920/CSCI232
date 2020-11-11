# Project: Evaluating Algebraic Expressions
## F20 CSCI 232 Data Structures and Algorithms
### Assigned: 2020-10-26; Due Date: 2020-11-16 (Midnight)

## Project Summary:

> ### Abstract: 
> Based on Chapter~6, Problems 6 \& 7; write a program that accepts an infix algebraic expression, converts it to a postfix expression, and then evaluates the postfix expression. 
> ### Objectives: 
> 1. Work with Stack ADT, Node ADT
> 1. Managed (Smart) Pointers
> 1. Conversion from Infix to Postfix
> 1. Evaluating algebraic expressions using a Stack ADT
> 1. Reading values from standard input
> 1. Parsing strings
> 
> ### Grading: 
> 45 pts are available for this project
> ### Course Outcomes: 
>  R1, R3, R9, R10 - See Course Syllabus for Explanations

### Project Description

Whereas humans are most familiar and comfortable working with algebraic expressions in their _infix_ notation, the algebraic rules of associativity, commutativity, and operator precedence can make it a challenge for an algorithmic approach to evaluate such expressions, especially when such automated means (typically) do not have the advantage of "seeing" the expression in its entirety, rather process the expression a small number of characters (typically, 1 character) at a time. 

Consider the following: 

|Infix Express | Postfix Expression|
|--------------|-------------------|
|((a+b)-c*(d/e))+f | a b + c d e / * - f + |
|a + b * c + d | a b c * + d + |
|(a+b) * (c+d) | a b + c d + * |
|a * b + c * d | a b * c d * + |
|a + b + c + d | a b + c + d + |

Evaluating the expression on the right hand side become an extremely algorithmic process requiring only a STACK ADT to perform the evaluation, and a few rules. 

The conversion from Infix to Postfix notation, likewise can be performed with a larger set of rules, but also only requires a STACK ADT. 

Conversion from Infix to Postfix (algorithmic example for your consideration): 

	// assume string infix contains a valid infix algebraic expression
	// assume string postfix is empty at the start

	// create an empty stack to defer operators as they are encountered (if needed)
	StackInterface<token>* opStack = new LinkedStack<token>();

	// Assume TokenList is a custom class that is iterable
	// elements can contain operators, single lowercase english alphabet characters, 
	// and open or close parenthesis, signed integers, and decimal numerical values
	TokenList<token>* tokenLst = new TokeList<token>(infix);

	// iterate over all the tokens in the token list
	for (auto token : tokenList)
	{
		if (operandP(token))
		{
			// append token to postfix string
			postfix.append(token);

			// process next token
			continue;
		} // end if

		if (token == '('))
		{
			// push open parenthesis onto the opstack
			opStack.push(token);

			// process next token
			continue;
		} // end if 

		if (token == ')')
		{
			Token top;

			while ( (top = opStack.peek()) != '(' )
			{
				if (operatorP(top))
				{
					// append operator to postfix string
					postfix.append(top);

					// remove operator from stack
					opStack.pop();
				} // end if
			} // end while

			// remote the '(' at top of stack
			opStack.pop();

			// process next token
			continue;
		} // end if

		if (operatorP(token))
		{
			Token top;

			// so long as stack is not empty, 
			// top of stack is not an open '(',
			// and the prec of the top >= prec of token
			while (!opStack.isEmpty() && 
			       (top = opStack.peek()) &&
				   top != '(' &&
				   prec(top) >= prc(token))
			{
				// append operator to postfix string
				postfix.append(top);

				// remove operator from the stack
				opStack.pop();
			} // end while

			// push the token on the stack
			opStack.push(token);

			// process next token
			continue;
		} // end if
	} // end of for loop

	// write to postfix any remaining 
	// operators on the stack 
	while (!opStack.isEmpty())
	{
		Token top = opStack.peek();
		postfix.append(top);
		opStack.pop();
	} // end while


Based on Chapter~6, Problems 6 & 7; write a program that accepts an infix algebraic expression, converts it to a postfix expression, and then evaluates the postfix expression. Prompt the user for the values of the variable operands and evaluate the expression. The program should prompt and produce output similar to:

	Enter the infix expression: a + b * (c - d) + e / f
	Enter the values for the operands in a + b * (c - d) + e / f:
	a: 1.5
	b: 2
	c: 3
	d: 4
	e: 5
	f: 6
	The postfix expression is: abcd-*+ef/+
	The value of the expression is: 0.333333

You have been provided the `Node` and `LinkedStack` classes, as well as the `PrecondViolatedExcep` custom exception class. You must implement the `Postfix` class which must at least implement the methods `getInfix()`, `getPostfix()`, `getResult()`, `postfixFromInfix`, and `eval` as shown in the provided header and implementation files. 

_Lab Environment_

The course lab and project environment is a Linux virtual machine. The machine name is `lumen.cs.mtech.edu`. You may access this virtual machine using any available `ssh` (secure shell) client software. On Microsoft Windows-10, you can open a command window and use the built-in `ssh` client software:

Press the `Windows Key` and type `cmd` and then hit `enter`

in the command window, you should then type,

`ssh pcurtiss@lumen.cs.mtech.edu`

and hit `enter`, where `pcurtiss` is replaced with your own username. Your username is first part of your email address, stripped of any trailing numbers. 

You will then be challenged for your password, which you will not see as you type, for the sake of privacy. Your password is whatever you changed it to in `CSCI136` or your student ID if your password has been reset by your instructor. 

Once you have successfully logged in, you will be presented with your Linux prompt. The default prompt from the system will look something similar to the following: 

`pcurtiss@lumen: ~$`

_Forking Today's Lab Repository_

Open a web browser on your workstation and enter [https://gitlab.cs.mtech.edu](https://gitlab.cs.mtech.edu) into the location field, then login to `GitLab` using the credentials you selected upon initial account setup.

On the top menu bar of your account page you should see a `Projects` pull-down menu toward the left. `Left-click` on this pull-down menu and select `Your Projects` to see a list of projects to which you have access, as well as your own projects - projects in your own `GitLab` account. One of these projects should look something like the following:

```
Data Structures and Algorithms / F20 CSCI232 / Proj01-EvalExp
```

This project, to which you have access, is in the course (Data Structures and Algorithms) repository for this term's (F20 CSCI232) offering. In order to be able to modify and work with the files in this repository you must get a copy of this project into your own account on `GitLab`. Making a remote copy from one account on `GitLab` to another account on `GitLab` is called `forking`. 

To fork today's lab repository, `left-click` on the the course project shown above. This will show you a summary of the project, with some of the files shown in a details list, but at the top, to the right of the project name, you should see a few buttons - [A bell icon], [A star icon], and a [Fork] button. `Left-click` on the `fork` button and then select your account as the destination account into which to place the `forked` copy of the project repository - it will take a few minutes for the fork to complete. 

Once completed, you will notice that you are placed in the project contents, but at the top left, the path now looks like,

```
jqpublic / Proj01-EvalExp
```

or similar, with our username in the path. This indicates the remote repository has been copied into your account. 

The next step is to add your instructor (and any TAs) as members to this project so they can see the project contents, review the project, and provide a grade for your work. The menu on the left should have a `Members` item. `Left-click` the `Members` menu item on the left and you should be presented with a form. Make sure the `Invite Members` tab at the top is selected and then enter your instructor's (and any TA's) name or email in the `GitLab member or Email address` form field. When you have added the instructor (and any TAs) to this field, `left-click` on the `Choose a role permission` and select `Developer` from the options; you should leave the `Access expiration date` blank. Then `left-click` the `invite` button to add them as members to the project. 

Lastly, `left-click` on the `Project Overview` item in the left menu to display the project information. To the right should be a `blue` button labeled `clone`. `left-click` this button and select the `copy url clipboard` icon to the right of the `ssh` url item to copy the url to the workstation's clipboard. 

_Obtaining Project Files_

Now you are ready to copy the remote project repository for today's lab from your account on the `GitLab` server to your account on `lumen.cs.mtech.edu`. 

Switch back to the Linux window and type the following: 

```
cd ~/CSCI232/Projects
git clone git@gitlab.cs.mtech.edu:pcurtiss/f20/Proj01-EvalExp.git
```

where the specific url is from you pasting the `ssh url` into the window that you copied in your lab step from working with the `GitLab` server - the one shown above is just an example. When you hit `enter` you will be challenged for the passphrase you used when you created your `ssh` key. Enter this passphrase and hit `enter`. Git will now clone (or copy) the remote project repository from your account on `GitLab` to a local repository in your account on `lumen.cs.mtech.edu` and link the two repositories, such that as you make changes to your local repository, you can `push` these changes back to the remote repository as needed, to update the shared (with your instructor and any TAs) repository on the `GitLab` server. 

Once the `clone` has completed, you should have a new (sub)directory in your `~/CSCI232/Projects` directory named `Proj01-EvalExp`, which you can see by using the `ls` command. 

_Completing the Lab Activities_

As you work through the specific activities for this Lab, you will be asked questions, or to provide information from the environment. This information should be collected in a lab report in a file named `report.pdf` that you should include in the `Proj01-EvalExp` directory. You may make this file in Microsoft Word and then save a copy in PDF format and upload (using `scp`) to your project folder. If you are unsure how to do this, ask the instructor or a TA. 

Please perform the following activities to complete this lab assignment: 

1. Once cloned, execute the `make` command to build the project, and then execute the resulting executable`./driver` to make sure the project builds and runs correctly. 

1. Review and understand the provided code. Make sure you understand the syntax associated with the header and implementation files, with using templates, and with building the project - using the `make` command. 

1. Implement the Postfix Class by implementing the methods required. You should feel free to add any additional methods you think you need to complete the project tasks.

1. Operands may be literal numbers, including decimal numbers, or single letter variables from the lower-case English alphabet - `[a - z]` (inclusive).

1. The allowed operators are `+, -, *, /, ^`, where `a^b` is `a` times itself, `b` times.

1. Store your infix and postfix expression using strings (use the C++ string class).

1. Test your program on actual algebraic expressions.  

1. You should handle invalid expressions for where operands are either not single lower-case English letters, literal numeric values (integer or decimal numbers), or valid operators (see above).

1. If the expression is invalid (unbalanced parentheses, missing operators, etc), then print an error message.

1. If the expression uses a variable operand multiple times only prompt the user once for that operand.  For example, if the expression `c+b*c` is entered, only prompt the user one time for `c`. 

1. Allow embedded spaces in the infix string.
	
1. Include the final output of executing the `driver` in your lab report. 

99. Submit your finished project

    ```
    git add .  
    git commit -m 'please grade'  
    git push  
    ```

_Editing Your Lab Project Files_

You may edit your program files either locally, on the Linux system, or remotely, using any number of remote file system schemes. The method selected varies widely depending on your preference. 

To edit locally, on the Linux system, you should use either `nano` or `vim`. Both of these are powerful editors for working with different source code files. To edit a file with nano, you would type, 

```
nano driver.cpp
``` 

for example. You can follow the commands at the bottom of the `nano` window to manipulate the file. I have also included a cheat-sheet for `vim` if you would prefer to use that editor. 

If you are interested in remote editing your files, please see the instructor, a course TA, or a Museum Lab TA for assistance. 

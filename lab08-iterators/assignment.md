# Assignment: C++ Iterators and Algorithms
## F20 CSCI 232 Data Structures and Algorithms
### Assigned: 2020-10-21; Due Date: 2020-10-29 (Midnight); Reference: CPPI-7

### Project Description

Understand how to create an iterator class for any C++ class and implement the required methods - `begin()` and `end()` in the class that is _iterable_. Explore the built-in algorithms available for classes that are iterable. 

---

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
Data Structures and Algorithms / F20 CSCI232 / Lab08 Iterators
```

This project, to which you have access, is in the course (Data Structures and Algorithms) repository for this term's (F20 CSCI232) offering. In order to be able to modify and work with the files in this repository you must get a copy of this project into your own account on `GitLab`. Making a remote copy from one account on `GitLab` to another account on `GitLab` is called `forking`. 

To fork today's lab repository, `left-click` on the the course project shown above. This will show you a summary of the project, with some of the files shown in a details list, but at the top, to the right of the project name, you should see a few buttons - [A bell icon], [A star icon], and a [Fork] button. `Left-click` on the `fork` button and then select your account as the destination account into which to place the `forked` copy of the project repository - it will take a few minutes for the fork to complete. 

Once completed, you will notice that you are placed in the project contents, but at the top left, the path now looks like,

```
jqpublic / Lab08 Iterators
```

or similar, with our username in the path. This indicates the remote repository has been copied into your account. 

The next step is to add your instructor (and any TAs) as members to this project so they can see the project contents, review the project, and provide a grade for your work. The menu on the left should have a `Members` item. `Left-click` the `Members` menu item on the left and you should be presented with a form. Make sure the `Invite Members` tab at the top is selected and then enter your instructor's (and any TA's) name or email in the `GitLab member or Email address` form field. When you have added the instructor (and any TAs) to this field, `left-click` on the `Choose a role permission` and select `Developer` from the options; you should leave the `Access expiration date` blank. Then `left-click` the `invite` button to add them as members to the project. 

Lastly, `left-click` on the `Project Overview` item in the left menu to display the project information. To the right should be a `blue` button labeled `clone`. `left-click` this button and select the `copy url clipboard` icon to the right of the `ssh` url item to copy the url to the workstation's clipboard. 

_Obtaining Project Files_

Now you are ready to copy the remote project repository for today's lab from your account on the `GitLab` server to your account on `lumen.cs.mtech.edu`. 

Switch back to the Linux window and type the following: 

```
cd ~/CSCI232/Labs
git clone git@gitlab.cs.mtech.edu:pcurtiss/f20/Lab08-Iterators.git
```

where the specific url is from you pasting the `ssh url` into the window that you copied in your lab step from working with the `GitLab` server - the one shown above is just an example. When you hit `enter` you will be challenged for the passphrase you used when you created your `ssh` key. Enter this passphrase and hit `enter`. Git will now clone (or copy) the remote project repository from your account on `GitLab` to a local repository in your account on `lumen.cs.mtech.edu` and link the two repositories, such that as you make changes to your local repository, you can `push` these changes back to the remote repository as needed, to update the shared (with your instructor and any TAs) repository on the `GitLab` server. 

Once the `clone` has completed, you should have a new (sub)directory in your `~/CSCI232/Labs` directory named `Lab08-Iterators`, which you can see by using the `ls` command. 

_Completing the Lab Activities_

As you work through the specific activities for this Lab, you will be asked questions, or to provide information from the environment. This information should be collected in a lab report in a file named `report.pdf` that you should include in the `Lab08-Iterators` directory. You may make this file in Microsoft Word and then save a copy in PDF format and upload (using `scp`) to your project folder. If you are unsure how to do this, ask the instructor or a TA. 

Please perform the following activities to complete this lab assignment: 

1. Once cloned, execute the `make` command to build the project, and then execute the resulting executable`./driver` to make sure the project builds and runs correctly. 

1. Review and understand the provided code. Make sure you understand the syntax associated with the header and implementation files, with using templates, and with building the project - using the `make` command. 

1. Modify the `Node Class` so that it **friends** the `LinkedListwIterator` class giving access to private instance variables and methods, and such that no other derived class from `LinkedListwIterator` or any client has access to any instance variable or _any_ methods of the class `Node`.

1. The holidays are around the corner - if you haven't noticed - and you will need to be making some lists for your gift giving. To help, I have created a test file that contains entries such as,  
	
	```
	1 Robert XBox360 Gaming Console  
	1 Harold Dress Shirt  
	0 Marge Coal  
	0 Seth Twigs
	0 Billy Smelly Socks  
	1 Richard Craftsman Tool Set  
	...  
	0 Bobby Desiccated Rodent  
	1 Maud Pots and Pans Set  
	0 Hap Broken Automatic Ice Maker Components  
	```
	
	Where the first field, a _0_ (naughty) or a _1_ (nice), indicates list the entry belongs to; the second field is a single string (without whitespace) and is the name of the "friend"; and the rest of the line is the "gift" you intend to wrap and present to the "friend". More than one person may receive the same gift, on either list.

1. Write a driver program that creates a _naughty_, a _nice_, and a _gifts_ list, reads in the lines of the `giftlist.txt` file, and places the entry from this file on the correct list.

1. You will need to create a `struct {};` to hold the "friend" and "gift" data so that the struct can be added to the list.

1. Create a function that displays a list entry from either list.	
1. Iterate over the lists using the `for_each()` C++ function and display the list entries for the _naughty_ and _nice_ lists; use the `distance()` function to show the relative location of the person on the respective list.

1. Finally, iterate over the _gifts_ list, presenting a shopping list structure that lists in the first column, the gift string, and the second column, the number of occurrences of that item that need to be purchased - use a C++ iterator-based function to get this data. 
	
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

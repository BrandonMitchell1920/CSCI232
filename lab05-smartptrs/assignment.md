# Assignment: Automated (Smart) Pointers in C++
## F20 CSCI 232 Data Structures and Algorithms
### Assigned: 2020-09-23; Due Date: 2020-10-07 (Midnight); Reference: CPPI-4

### Project Description 

This lab pertains to the CPP Interlude-04 in your course textbook and deals with a linked list implementation of the _LIST ADT_, from Chapter-9. We will go over the implementation of the _LIST ADT_ once we complete the _STACK ADT_. The _LIST ADT_ UML specification is as follows:

> +isEmpty(): boolean  
> +getLength(): integer  
> +insert(newPosition: integer, newEntry: ItemType): boolean  
> +remove(position: integer): boolean  
> +clear(): void  
> +getEntry(position: integer): ItemType  
> +replace(position: integer, newEntry: ItemType): ItemType

The _List ADT_ is a positional container; the elements belonging to the container are not sorted in any particular way, but are ordered based on their position upon insertion. The behaviors of this ADT are stright forward enough, with the exception of the _replace()_ behavior. This behavior will replace the element at position _position_within the _LIST ADT_ container with the _newEntry_ contents, and return the _oldEntry_ that was overwritten. Refert to the table in your course textbook on pages 256-257 for a detailed explanation of these behaviors. 

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
Data Structures and Algorithms / F20 CSCI232 / Lab05 SmartPtrs
```

This project, to which you have access, is in the course (Data Structures and Algorithms) repository for this term's (F20 CSCI232) offering. In order to be able to modify and work with the files in this repository you must get a copy of this project into your own account on `GitLab`. Making a remote copy from one account on `GitLab` to another account on `GitLab` is called `forking`. 

To fork today's lab repository, `left-click` on the the course project shown above. This will show you a summary of the project, with some of the files shown in a details list, but at the top, to the right of the project name, you should see a few buttons - [A bell icon], [A star icon], and a [Fork] button. `Left-click` on the `fork` button and then select your account as the destination account into which to place the `forked` copy of the project repository - it will take a few minutes for the fork to complete. 

Once completed, you will notice that you are placed in the project contents, but at the top left, the path now looks like,

```
jqpublic / Lab05 SmartPtrs
```

or similar, with our username in the path. This indicates the remote repository has been copied into your account. 

The next step is to add your instructor (and any TAs) as members to this project so they can see the project contents, review the project, and provide a grade for your work. The menu on the left should have a `Members` item. `Left-click` the `Members` menu item on the left and you should be presented with a form. Make sure the `Invite Members` tab at the top is selected and then enter your instructor's (and any TA's) name or email in the `GitLab member or Email address` form field. When you have added the instructor (and any TAs) to this field, `left-click` on the `Choose a role permission` and select `Developer` from the options; you should leave the `Access expiration date` blank. Then `left-click` the `invite` button to add them as members to the project. 

Lastly, `left-click` on the `Project Overview` item in the left menu to display the project information. To the right should be a `blue` button labeled `clone`. `left-click` this button and select the `copy url clipboard` icon to the right of the `ssh` url item to copy the url to the workstation's clipboard. 

_Obtaining Project Files_

Now you are ready to copy the remote project repository for today's lab from your account on the `GitLab` server to your account on `lumen.cs.mtech.edu`. 

Switch back to the Linux window and type the following: 

```
cd ~/CSCI232/Labs
git clone git@gitlab.cs.mtech.edu:pcurtiss/f20/Lab05-SmartPtrs.git
```

where the specific url is from you pasting the `ssh url` into the window that you copied in your lab step from working with the `GitLab` server - the one shown above is just an example. When you hit `enter` you will be challenged for the passphrase you used when you created your `ssh` key. Enter this passphrase and hit `enter`. Git will now clone (or copy) the remote project repository from your account on `GitLab` to a local repository in your account on `lumen.cs.mtech.edu` and link the two repositories, such that as you make changes to your local repository, you can `push` these changes back to the remote repository as needed, to update the shared (with your instructor and any TAs) repository on the `GitLab` server. 

Once the `clone` has completed, you should have a new (sub)directory in your `~/CSCI232/Labs` directory named `Lab05-SmartPtrs`, which you can see by using the `ls` command. 

_Completing the Lab Activities_

As you work through the specific activities for this Lab, you will be asked questions, or to provide information from the environment. This information should be collected in a lab report in a file named `report.pdf` that you should include in the `Lab05-SmartPtrs` directory. You may make this file in Microsoft Word and then save a copy in PDF format and upload (using `scp`) to your project folder. If you are unsure how to do this, ask the instructor or a TA. 

Please perform the following activities to complete this lab assignment: 

1. Once cloned, execute the `make` command to build the project, and then execute the resulting executable by executing `./driver` to make sure the project builds and executes correctly. 

1. Review and understand the provided code. Make sure you understand the syntax associated with the header and implementation files, with using templates, and with building the project - using the `make` command. 

1. Add a method 
> +swap(aList: List, i: integer, j: integer): boolean

   that interchanges the items currently in positions _i_ and _j_ of the _listaList_. Deﬁne the method in terms of the _LIST ADT_ operations, so that it is independent of any particular implementation. Take appropriate action if there is no item in the list at either of the two positions.

1. Modify the driver program to make use of the _swap()_ method you implemented to reverse the order of the items in a list and display the list contents.

1. Add a method 
> contains(entry: ItemType): boolean

   that returns _true_ if the _entry_ is contained in the _LIST ADT_, and _false_ otherwise. Use Smart Pointers to implement the method.

1. Write a complete set of _Axioms_ to test the _contains()_ method behavior and include in your lab report. 

1. Modify the _driver_ program and implement a test for the _contains()_ method that corresponds with the Axioms you developed. Make sure to only use **Smart Pointers** in your implementation of the test(s). 

1. Build and test your program using the `./driver` executable that gets built. Capture the output in a
file `report.txt` and keep this file in the root of your lab directory.

14. Submit your finished project

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
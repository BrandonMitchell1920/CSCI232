# Assignment: Environment Setup and Bag ADT
## F20 CSCI 232 Data Structures and Algorithms
### Assigned: 2020-08-19; Due Date: 2020-08-27 (Midnight); Reference: 1.5, 3.2

_Lab Environment_

The course lab and project environment is a Linux virtual machine. The machine name is `lumen.cs.mtech.edu`. You may access this virual machine using any available `ssh` (secure shell) client software. One Microsoft Windows-10, you can open a command window and use the built-in `ssh` client software:

Press the `Windows Key` and type `cmd` and then hit `enter`

in the command window, you should then type,

`ssh pcurtiss@lumen.cs.mtech.edu`

and it `enter`, where `pcurtiss` is replaced with your username. Your username is first part of your email address, stripped of any trailing numbers. 

You will then be challenged for your password, which you will not see as you type the characters of your password for the sake of privacy. Your password is whatever you changed it to in `CSCI136` or your student ID if your password has been reset by your instructor. 

Once you have successfully logged in, you will be presented with your Linux prompt. The default prompt from the system will look something similar to the following: 

`pcurtiss@lumen: ~$`

Once logged into `lumen`, please execute the following commands:

```
mkdir -p ~/CSCI232/Labs
mkdir -p ~/CSCI232/Projects
```

The tilde character "`~`" is shorthand for your home directory path (`/home/students/jqpublic`, for example). The `mkdir` command creates directories within the filesystem. The `-p` command line option to the `mkdir` command instructs the command to create any intermediate (sub)directories in the path provided to the command (if needed). Therefore, the first command will create the directory `CSCI232` and then create the subdirectory `Labs` inside of the `CSCI232` directory. The second command will not make the `CSCI232` directory, as it was already created in the previous step, but will create a subdirectory `Projects` in the `CSCI232` directory. 

All of the lab assignments should be placed in the `~/CSCI232/Labs` directory, while all of the project assignments should be placed in the `~/CSCI232/Projects` directory. You may see the contents of any directory by using the `ls` command:

```
ls ~/CSCI232
Labs Projects
```

_Git Global Configuration_

`git` is a powerful set of tools for managing source code in a collaborative environment. The broad area in which `git` falls is that of *source control management* (SCM). You will use `git` to retrieve and submit your labs and projects in this, any many other CS Courses here at Montana Tech. The system works by maintaining *repositories* that contain the files you wish the system to manage. Within a repository, the `git` system creates *commit sets* containing only the differences between different commit sets. It stores these commit sets in a highly efficient manner, and can apply them *forward* or *backward* to generate the different *versions* of the files that comprise your repository. 

Repositories can be either *local* or *remote*. It is the remote repositories that are typically *shared* between different software developers working on a project. The remote repository represents the collaborative work of all the independent developers who have contributed to the software project. For your CS Courses in which you will use the `git` SCM, your remote repositories will be managed by the CS Department's GitLAB server.

In order to work with the `git` SCM system, you must first provide it just a few global configuration parameters, and then you must secure your communications between your lumen - which is managing your local repository - and `gitlab.cs.mtech.edu` - which is managing your remote repository. 

To configure the global settings for the `git` SCM system on `lumen.cs.mtech.edu`, execute the following: 

```
git config --global user.name "Phillip Curtiss"
git config --global user.email pcurtiss@mtech.edu
git config --global push.default matching
git config --global core.editor nano
git config --list
user.name=Phillip Curtiss
user.email=pcurtiss@mtech.edu
push.default=matching
core.editor=nano
```

Communication between the Linux environment and the `gitlab.cs.mtech.edu` server can be secured if you use `ssh` keys to encrypt the exchanged information. In order to do this, both the Linux environment (private `ssh` key) and the `GitLab` server (public `ssh` key) must have parts of the same `ssh` key. The first step is to generate an `ssh` key pair in the Linux environment that you wish to use with `GitLab`:

```
ssh-keygen -t rsa
Generating public/private rsa key pair. 
Enter file in which to save the key (/home/faculty/pcurtiss/.ssh/id_rsa):
Created directory '/home/faculty/pcurtiss/.ssh'.
Enter passphrase (empty for no passphrase):
Enter same passphrase again:
Your identification has been saved in /home/faculty/pcurtiss/.ssh/id_rsa.
Your public key has been saved in /home/faculty/pcurtiss/.ssh/id_rsa.pub.
...
```

_Configuring Your GitLab Account_

You must now configure your `GitLab` environment with your public `ssh` key and then `fork` today's lab project into your own account - creating a remote repository for today's lab. Then, you will `clone` the remote repository on the Linux system to create the local repository in which you will do your work. When completed, you will them `push` the commit sets in your local repository back to the remote repository where your instructor and/or TAs will review and grade your work. 

Open a web browser on your local workstation and navigate to the following url [https://gitlab.cs.mtech.edu](https://gitlab.cs.mtech.edu). Sign-in to your `GitLab` account using the credentials you configured from the *invite* you were sent by the system - you may also need to acknowledge the *terms and conditions* of use of the server. 

Once logged into the `GitLab` server, you  will notice a menu bar (with a blue background) at the very top of the browser's content area. To the far right of the menu bar will be an icon that is a pull-down menu. `Left-click` on this icon to open the pull-down menu and then select the `settings` option from the menu.

On the menu to the left you should see an `SSH Keys` item, `left-click` that menu item. This will show you all of the `ssh` keys you have associated with your `GitLab` account. Now, go back to your `lumen.cs.mtech.edu` terminal window and type following command:

```
cat ~/.ssh/id_rsa.pub
...
```

and you will see on the terminal window the contents of the `id_rsa.pub` file. Highlight and copy to the clipboard the contents shown in the terminal window from this file - and only this file. Then, go back to the browser window and past the clipboard contents into the `Key` window, and then `left-click` the `Add Key` button to add this public `ssh` key to your `GitLab` account.

_Forking Today's Lab Repository_

On the top menu bar you should see a `Projects` pull-down menu toward the left. `Left-click` on this pull-down menu and select `Your Projects` to see a list of projects to which you have access, as well as your own projects - projects in your own `GitLab` account. One of these projects should look something like the following:

```
Data Structures and Algorithms / F20 CSCI232 / Lab01 BagADT
```

This project, to which you have access, is in the course (Data Structures and Algorithms) repository for this term's (F20 CSCI232) offering. In order to be able to modify and work with the files in this repository you must get a copy of this project into your own account on `GitLab`. Making a remote copy from one account on `GitLab` to another account on `GitLab` is called `forking`. 

To fork today's lab repository, `left-click` on the the course project shown above. This will show you a summary of the project, with some of the files shown in a details list, but at the top, to the right of the project name, you should see a few buttons - [A bell icon], [A star icon], and a [Fork] button. `Left-click` on the `fork` button and then select your account as the destination account into which to place the `forked` copy of the project repository - it will take a few minutes for the fork to complete. 

Once completed, you will notice that you are placed in the project contents, but at the top left, the path now looks like,

```
jqpublic / Lab01 BagADT 
```

or similar, with our username in the path. This indicates the remote repository has been copied into your account. 

The next step is to add your instructor (and any TAs) as members to this project so they can see the project contents, review the project, and provide a grade for your work. The menu on the left should have a `Members` item. `Left-click` the `Members` menu item on the left and you should be presented with a form. Make sure the `Invite Members` tab at the top is selected and then enter your instructor's (and any TA's) name or email in the `GitLab member or Email address` form field. When you have added the instructor (and any TAs) to this field, `left-click` on the `Choose a role permission` and select `Developer` from the options; you should leave the `Access expiration date` blank. Then `left-click` the `invite` button to add them as members to the project. 

Lastly, `left-click` on the `Project Overview` item in the left menu to display the project information. To the right should be a `blue` button labeled `clone`. `left-click` this button and select the `copy url clipboard` icon to the right of the `ssh` url item to copy the url to the workstation's clipboard. 

_Obtaining Project Files_

Now you are ready to copy the remote project repository for today's lab from your account on the `GitLab` server to your account on `lumen.cs.mtech.edu`. 

Switch back to the Linux window and type the following: 

```
cd ~/CSCI232/Labs
git clone git@gitlab.cs.mtech.edu:pcurtiss/f20/Lab01-BagADT.git
```

where the specific url is from you pasting the `ssh url` into the window that you copied in your lab step from working with the `GitLab` server - the one shown above is just an example. When you hit `enter` you will be challenged for the passphrase you used when you created your `ssh` key. Enter this passphrase and hit `enter`. Git will now clone (or copy) the remote project repository from your account on `GitLab` to a local repository in your account on `lumen.cs.mtech.edu` and link the two repositories, such that as you make changes to your local repository, you can `push` these changes back to the remote repository as needed, to update the shared (with your instructor and any TAs) repositor on the `GitLab` server. 

Once the `clone` is completed, you should have a new (sub)directory in your `~/CSCI232/Labs` directory named `Lab01-Bag`, which you can see by using the `ls` command. 

_Completing the Bag ADT_

As you work through the specific activities for this Lab, you will be asked questions, or to provide information from the environment. This information should be collected in a lab report in a file named `report.pdf` that is included in the `Lab01-Bag` directory. You may make this file in word and then store a PDF and upload (using `scp`) to your `lumen.cs.mtech.edu` account. If you are unsure how to do this, ask the instructor or a TA. 

Please perform the following activities in the completion of the lab assignment: 

1. Follow the instructions in class for establishing your account on the CS Dept GitLab server. Make sure to add your instructor and any TAs as a developer member to your project. 
1. Clone the lab project from the GitLab server - instructions provided in class. 
1. List the files in your lab (sub)directory and include the output in your lab report. 
1. Build an executable from the lab source code files using the provided `Makefile` and issuing the `make` command at the Linux prompt. List the contents of your lab (sub)directory and include the output in your lab report. 
1. Execute the program built by the make process - so this by issuing the command 
```
./driver
```
Explain in your lab report what happens when you execute the program. 

6. Review and understand the source code in the `*.h` and `*.cpp` files in your lab project. Make sure you understand the syntax associated with creating the header files (`*.h`), with the implementation files (`*.cpp`), with using templates, and with building the project - using the `Makefile`. 
6. Once you have a good understanding of the project files, proceed to look at the `driver.cpp` file in which there are comments for you to replace with your own code, based on the commented instructions. Write the required code to implement the behavior requested. 
6. Once finished with your code modifications, you may build the project using the `make` command and then execute your program using the `./driver` command. What is the output of your program? Include this in your lab report. 

_Editing Your Lab Project Files_

You may edit your program files either locally, on the Linux system, or remotely, using any number of remote file system schemes. The method selected varies widely depending on your preference. 

To edit locally, on the Linux system, you should use either `nano` or `vim`. Both of these are powerful editors for working with different source code files. To edit a file with nano, you would type, 

```
nano driver.cpp
``` 

for example. You can follow the commands at the bottom of the `nano` window to manipulate the file. I have also included a cheat-sheet for `vim` if you would prefer to use that editor. 

If you are interested in remote editing your files, please see the instructor, a course TA, or a Museum Lab TA for assistance. 
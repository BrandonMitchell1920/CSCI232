# Assignment: Operator Overloading in C++
## F20 CSCI 232 Data Structures and Algorithms
### Assigned: 2020-10-14; Due Date: 2020-10-26 (Midnight); Reference: CPPI-6

### Project Description

A _regular polygon_ is a polygon that is equangular - all angles are equal in measure - and equilateral - all sides have the same length. A side of a regular polygon may be represented by two (2) points in the 2D plane. You may represent such a point with a class: 

|Coord2D|
|-------|
|- x-coord: double|
|- y-coord: double|
|+ getX(): double|
|+ setX(newCoord: double): void|
|+ getY(): double|
|+ setY(newCoord: double): void|

You are to create a regular polygon class that relates to the `Coord2D` and the `LinkedList` classes with either an _is-a_, _as-a_, or _has-a_ relationship - you may decide whichever makes the most sense for your design. Your regular polygon class must provide at least two (2) constructors: 

* a default constructor taking no parameters and creating an empty regular polygon
* a constructor taking a single parameter, a `LinkedList` of `Coord2D` elements

Your regular polygon **must** - **at all times** - maintain a regular polygon comprised of `Coord2D` instances contained in its `LinkedList` instance. The parameterized constructor must ensure the `Coord2D` points contained in the parameter's `LinkedList` form a  regular polygon, and if not, must throw a custom exception class instance indicating the parameter `LinkedList` does not consist of a regular polygon. 

As collections of `Coord2D` are added to or removed from instances of the regular polygon class, the resulting points much be moved in the 2D plane to ensure the `LinkedList` continues to form a regular polygon. This is most easily done by,

* firstly,  modifying the radius of the regular polygon (if needed) to include the most distance resulting point in the `LinkedList` from the center of the regular polygon, and 
* secondly, iterating over the `Coord2D` points in the `LinkedList`, modifying their radius to set them on the circle invident with the most distance point in the list, and then equally spacing them around this circle. 

The regular polygon behaviors you must implement are documented below in the specific lab activities. 

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
Data Structures and Algorithms / F20 CSCI232 / Lab07 Overload
```

This project, to which you have access, is in the course (Data Structures and Algorithms) repository for this term's (F20 CSCI232) offering. In order to be able to modify and work with the files in this repository you must get a copy of this project into your own account on `GitLab`. Making a remote copy from one account on `GitLab` to another account on `GitLab` is called `forking`. 

To fork today's lab repository, `left-click` on the the course project shown above. This will show you a summary of the project, with some of the files shown in a details list, but at the top, to the right of the project name, you should see a few buttons - [A bell icon], [A star icon], and a [Fork] button. `Left-click` on the `fork` button and then select your account as the destination account into which to place the `forked` copy of the project repository - it will take a few minutes for the fork to complete. 

Once completed, you will notice that you are placed in the project contents, but at the top left, the path now looks like,

```
jqpublic / Lab07 Overload
```

or similar, with our username in the path. This indicates the remote repository has been copied into your account. 

The next step is to add your instructor (and any TAs) as members to this project so they can see the project contents, review the project, and provide a grade for your work. The menu on the left should have a `Members` item. `Left-click` the `Members` menu item on the left and you should be presented with a form. Make sure the `Invite Members` tab at the top is selected and then enter your instructor's (and any TA's) name or email in the `GitLab member or Email address` form field. When you have added the instructor (and any TAs) to this field, `left-click` on the `Choose a role permission` and select `Developer` from the options; you should leave the `Access expiration date` blank. Then `left-click` the `invite` button to add them as members to the project. 

Lastly, `left-click` on the `Project Overview` item in the left menu to display the project information. To the right should be a `blue` button labeled `clone`. `left-click` this button and select the `copy url clipboard` icon to the right of the `ssh` url item to copy the url to the workstation's clipboard. 

_Obtaining Project Files_

Now you are ready to copy the remote project repository for today's lab from your account on the `GitLab` server to your account on `lumen.cs.mtech.edu`. 

Switch back to the Linux window and type the following: 

```
cd ~/CSCI232/Labs
git clone git@gitlab.cs.mtech.edu:pcurtiss/f20/Lab07-Overload.git
```

where the specific url is from you pasting the `ssh url` into the window that you copied in your lab step from working with the `GitLab` server - the one shown above is just an example. When you hit `enter` you will be challenged for the passphrase you used when you created your `ssh` key. Enter this passphrase and hit `enter`. Git will now clone (or copy) the remote project repository from your account on `GitLab` to a local repository in your account on `lumen.cs.mtech.edu` and link the two repositories, such that as you make changes to your local repository, you can `push` these changes back to the remote repository as needed, to update the shared (with your instructor and any TAs) repository on the `GitLab` server. 

Once the `clone` has completed, you should have a new (sub)directory in your `~/CSCI232/Labs` directory named `Lab07-Overload`, which you can see by using the `ls` command. 

_Completing the Lab Activities_

As you work through the specific activities for this Lab, you will be asked questions, or to provide information from the environment. This information should be collected in a lab report in a file named `report.pdf` that you should include in the `Lab07-Overload` directory. You may make this file in Microsoft Word and then save a copy in PDF format and upload (using `scp`) to your project folder. If you are unsure how to do this, ask the instructor or a TA. 

Please perform the following activities to complete this lab assignment: 

1. Once cloned, execute the `make` command to build the project, and then execute the resulting executable`./driver` to make sure the project builds and runs correctly. 

1. Review and understand the provided code. Make sure you understand the syntax associated with the header and implementation files, with using templates, and with building the project - using the `make` command. 

1. Create the class `Coord2D` according to the UML provided above. 

1. Create the class `RegularPolygon` relating to the `Coord2D` and `LinkedList` classes; you get to decide the nature of these relationships - _is-a_, _as-a_, or _has-a_. 

1. The `RegularPolygon` class must have a non-parameterized default constructor that creates and empty instance of the class - an instance with an empty `LinkedList`.

1. The `RegularPolygon` class must have a parameterized constructor taking a single parameter - a (smart) pointer to a `LinkedList` instance containing `Coord2D` elements. This constructor must check to make sure the `Coord2D` points contained in the `LinkedList` comprise a regular polygon in the 2D plane, and if they do not, must throw an appropriate instance of a custom exception class you need to write. 

1. The `RegularPolygon` class should have an `add(const shared_ptr<LinkedList<Coord2D> > pointList): bool`  
	method whereby each `Coord2D` element in the list is added to the regular polygon, possibly resulting in a change in the _radius_ of the regular polygon and the _position_ of the exisitng `Coord2D` points already comprising the regular polygon to ensure the instance preserves its _equiangular_ and _equlateral_ properties. 
	
1. The `RegularPolygon` class should have a  
	`remove(const shared_ptr<LinkedList<Coord2D> > pointList): bool`  
	method whereby each `Coord2D` element in the list is removed from the regular polygon, possibly resulting in a change in the _radius_ of the regular polygon and the _position_ of the remainng `Coord2D` points already comprising the regular polygon to ensure the instance preserves its _equiangular_ and _equilateral_ properties. 
	
1. The `RegularPolygon` class should have a  
	`perimeter(): double`  
	method, returning the calculated perimeter of the regular polygon instance. 
	
1. The `RegularPolygon` class should have an  
	`area(): double`  
	method, returning the area of the regular polygon. You are free to calculate the area of the regular polygon through any rational means, but you might consider using the formula,  
	`A = (hp)/2`  
	where _A_ is the area of the regular polygon, _h_ is the _apothem_ - a line from the center of a side of the regular polygon to its center, and _p_ is the perimeter of the regular polygon. 
	
1. The `RegularPolygon` class must provide an _overload_ of the `operator+`, allowing two `RegularPolygon` instances to be added together, resulting in the sum of the _areas_ of the two regular polygons. 

1. The `RegularPolygon` must provide an _overload_ method for the `operator<<` by providing a `friend method` to the `ostream` class to output the list of `Coord2D` points comprising the `RegularPolygon` instance. 

1. You must provide a UML diagram for your design representing the relationship between all calsses - `RegularPolygon`, `LinkedList`, `Coord2D`, `Node`, `ExceptionClass` - and showing all data memebers and method members for each class, as well as any prototype(s) - representing class templates - needed. 

1. Modify the provided driver file to create at least two `RegularPolygon` instances and test all the methods. 

1. Capture the output from your tests into your lab report document and include in the top level folder for your lab.

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

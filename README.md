![Untitled](https://user-images.githubusercontent.com/90519370/172729154-3dafe4b1-f713-4580-a7b0-a6a3499dd33e.png)

# The Blue Programming Language, A powerful, V E R Y Easy to use language, that compiles to haxe's cpp target.
A compiled, dynamically typed, object oriented programming language. 
Coming in at only 24 keywords, this is an easy to use language with unseen compiler speed.

## Blue has no trailing semicolons, and is extremely powerful thanks to it's backwards compatibility with most haxe libraries.

# Installing dependencies

## Installing the Blue compiler
Extract the .zip binary you downloaded in the "release" section of the repository, drop the new extracted folder into your computer's C: drive.
Now, press WIN + S on your keyboard, and search up "Edit the system environment variables", click on the result named what you just searched up,
and go to the "Advanced" section in the menu that pops up. Under "Startup and recovery", click on "Evironment Variables". First, edit the user variables,
under the "User variables for (user)" find the "Path" variable, click on it, and click 'New' on the array of buttons on the left hand side of the menu.
After clicking 'new', type in 'C:\Blue1', click 'OK'. And see if blue works by opening a command terminal and typing 'blue', You know the installation was successful if Blue attempts to compile the current directory you are in.

## Installing Haxe
Blue will NOT work without the haxe language installed, to do so, go to https://haxe.org/download/ and download the LATEST VERSION of haxe.
Follow the installation instructions and do not attempt to compile your project folder until haxe, hxcpp (Disussed in "Installing hxcpp"), and a C++ compiler (Discussed in "Installing a C++ compiler") are successfully installed on your computer.

## Installing hxcpp
When haxe is installed on your computer, you get access to the haxelib library manager, and Blue makes use of this feature. Open a command line terminal, and type "haxelib install hxcpp", when it is installed successfully, you can continue to the next step.

## Installing a C++ compiler
To finish things off, we need a C++ compiler, to finally compile the outputted C++ code into an executable file.
I personally recommend the GNU Gcc compiler, as it is a very stable, reputable piece of software. You can download it here: https://gcc.gnu.org/ 
Follow a GNU Gcc compiler installation tutorial and when it is installed successfully, you can continue to the next step.

## Finishing up
That's it! When absolutely all of these steps are complete, go into the folder containing your .BL source files, open a command line terminal IN THAT FOLDER, and type "blue", and execute the command. Depending on whether your code has errors, your program should be compiled into an executable file, ready to run.

# Compiling the source code
Compiling the blue compiler is pretty simple; Read "Installing dependencies" steps 2 - 3, and then, open a command line terminal inside the source code's folder, then, type "haxe -cp src --main blue.Blue --cpp bin", and execute the command. This should build the blue compiler if all the required dependencies are installed.

# A taste of blue's syntax
```
*** Dynamically Typed Variables ***
a = 1
b = [2, 3]

*** Main function, where the code starts executing ***
main method()
getNumber(1)
end

method getNumber(num)
*** Print the number that was passed in ***
print(num)
*** Return the number, and stop the function" ***
return num
*** Exit the program after the number has been printed ***
Sys/exit(0)
end
```

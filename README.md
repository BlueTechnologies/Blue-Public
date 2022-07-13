![BLogo](https://user-images.githubusercontent.com/90519370/172873820-f01d13f3-6bd1-4d24-b79b-1c548f024ae9.png)

# The Blue Programming Language, A powerful, V E R Y Easy to use language, that can compile to ten of your favourite languages.
A compiled, dynamically typed, object oriented programming language. 
Coming in at only 30 keywords, this is an easy to use language with unseen compiler speed.

## Blue has no trailing semicolons, and is extremely powerful thanks to it's small, compact, file size. It was written in only 2500 lines of Haxe code.

# Installing dependencies

## Installing the Blue compiler
Extract the .zip binary you downloaded in the "release" section of the repository, drop the new extracted folder into your computer's C: drive.
Now, press WIN + S on your keyboard, and search up "Edit the system environment variables", click on the result named what you just searched up,
and go to the "Advanced" section in the menu that pops up. Under "Startup and recovery", click on "Evironment Variables". First, edit the user variables,
under the "User variables for (user)" find the "Path" variable, click on it, and click 'New' on the array of buttons on the left hand side of the menu.
After clicking 'new', type in 'C:\Blue1', click 'OK'. And see if blue works by opening a command terminal and typing 'blue', You know the installation was successful if Blue attempts to compile the current directory you are in.

## Installing a target compiler
To use Blue, you need a compiler for the language you are targetting, these are almost always found on the language's vendor's website.

## Finishing up
That's it! When absolutely all of these steps are complete, go into the folder containing your .BL source files, open a command line terminal IN THAT FOLDER, and type "blue 'source-code-folder' 'target'", and execute the command. Depending on whether your code has errors, your program should be compiled into an executable file, ready to run.

# Compiling the source code
Compiling the blue compiler is pretty simple; Read "Installing dependencies" steps 2 - 3, and then, open a command line terminal inside the source code's folder, then, type "haxe build.hxml", and execute the command. This should build the blue compiler if all the required dependencies are installed.

# A taste of Blue's syntax
```
*** Dynamically Typed Variables ***
a = 1
b = [2, 3]

*** Main function, where the code starts executing ***
main method()
getNumber(1)
end

@Static
method getNumber(num)
*** Print the number that was passed in ***
print(num)
*** Return the number, and stop the function" ***
return num
*** Exit the program after the number has been printed ***
Sys/exit(0)
end
```

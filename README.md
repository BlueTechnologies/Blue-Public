![BLogo](https://user-images.githubusercontent.com/90519370/172873820-f01d13f3-6bd1-4d24-b79b-1c548f024ae9.png)

# The Blue Programming Language, A powerful, V E R Y Easy to use language, that can compile to eight of your favourite languages.
A compiled, dynamically typed, object oriented programming language. 
Coming in at only 30 keywords, this is an easy to use language with unseen compiler speed.

## Blu is extremely powerful thanks to it's small, compact, file size. It was written in only 3000 lines of Haxe code.

# Installing dependencies

## Installing the Blue compiler
You can use the windows installer provided in the "releases" section of the repository to fully automatically install the Blue compiler on your system.

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

method getNumber(num)
*** Print the number that was passed in ***
print(num)
*** Return the number, and stop the function" ***
return num
*** Exit the program after the number has been printed ***
exit(0)
end

*** Main function, where the code starts executing ***
main method()
getNumber(1)
end
```

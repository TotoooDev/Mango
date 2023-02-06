# Mango

Mango is a terrible finite state machine designer that I am creating to help me taking notes in my Language Theory classes.

It is not finished yet (and probably never will) but if you want to take a look at it you can build it from source (maybe one day I will package and distribute it but I'm not hopeful)

# Building from source

## For Window users

1. Clone the repository, and run `GenerateProjects.bat`. This will create a solution file for Visual Studio 2022.
2. Open the solution, and build it. Make sure to build in Distribution mode (although it should not make a big difference).
3. Copy the DLLs from the `Libs\Windows` directory to the binaries contained in the `bin\Distribution-windows-x86_64\Mango` directory. Maybe one day I will be motivated enough to make this a post-build task but today is not that day :(
4. ???
5. Profit

## For Linuwux users

1. You'll need to install `GLFW3` first (the way to install it will depend on you distribution)
2. Clone the repository and run `GenerateProjects.sh`. This will create all the Makefiles necessary.
3. Run `make`
4. ???
5. Profit
# Desktop window

For any operation system and for any video mode the application must create a window first.
After creation of window the application will be able to receive signals and commands from the operation system amd communicate with graphical subsystem.

Every operation system or graphical desktop environment (like GNOME or KDE for Linux) has its own API to create a window and communicate with operation system. It's a complex code and not always needed for developers who only want to create multimedia application like games or media players.

Because of its complexity exist a lot of libraries and frameworks to hide system specific details from the end-users (in this case from developers of multimedia applications) and provide the only one API for all operation systems.

Most popular libraries:

* [Simple DirectMedia Layer or SDL](https://libsdl.org)
* [Graphics Library Framework or GLFW](https://www.glfw.org)

In all tutorials applications will use [GLFW](https://www.glfw.org) just because in this case it's simpler and allow to concentrate on graphical part better comparing to SDL.

# Renderer
just a simple c++ renderer

## dependencies
- ninja
- clang
- glfw
- glm

## State
this project is still in developement and might get a release in the next months or so
![Markdown Logo](https://img.shields.io/badge/state-development-red)
![Markdown Logo](https://img.shields.io/badge/build-unstable-red)
![Markdown Logo](https://tokei.rs/b1/github/iluvpy/Renderer)

## Compilation

### arch 
	`sudo pacman clang glfw ninja glm`
### debian
	`sudo apt install clang ninja libglfw3-dev libglm-dev`

### Windows
compile glad by running the Makefile in glad/ <br>
then create a directory called `obj` in `Renderer/` and place the `glad.o` file in `obj/` <br>
after that run `ninja` in the terminal and everything should just compile.
this should then generate a `Renderer.lib` file and a `client` file.
the `client` file can be run to see what the renderer can do ie render text, draw things on screen.
the `Renderer.lib` file can be used for static linking


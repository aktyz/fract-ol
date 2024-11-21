# How to see the fractals?

1. Clone the repositiory to your Linux machine.
2. Enter into the project folder
3. run `make` in the project folder
4. run `./fractol mandelbrot` or `./fractol julia <r> <i>` in the terminal

TODOs:
- [x] update Makefile to compile all fractol files together with two libraries: libft and minilibx-linux
- [x] run to check if the main is working as expected
- [x] code fractal_init() function
- [x] code fractal_render() function
- [x] implement ft_malloc_error()
- [x] implement events_init(fractal)
- [x] implement data_init(fractal)
- [x] Julia set
- [x] norminette!!!!
- [x] valgrind!!!!
- [x] Are wrong parameters correctly handled???

# Ideas for improvement
- [ ] Learn error handling in C
- [ ] improve LIBFT atodbl()
- [ ] switch ft_fractol_atodbl() to libft ft_atodbl()
- [ ] add Zoom on mouse pointer
- [ ] add another set of fractals <3

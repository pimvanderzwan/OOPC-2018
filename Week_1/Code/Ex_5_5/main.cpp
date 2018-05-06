// example:
// using a line that requires its window

#include <iostream>

#include "window.hpp"
#include "line.hpp"
#include "filled_rectangle.hpp"

int main(int argc, char **argv) {
	window w(128, 64, 2);
	line diagonal_line(w, 5, 5, 30, 40);
	diagonal_line.print();

	Filled_rectangle rect(w, 40, 40, 45, 45);
	rect.draw();

	return 0;
}

#include "Convertor.hpp"

int main(int argc, char **argv)
{
	if (argc != 2) {
		eprintln("Invalid argument count! (Need 1)");
		return 0;
	}

	try {
		Convertor conv(argv[1]);

		conv.printTypes();
	} catch (std::exception &e) {
		eprintln(e.what());
	}
}
#include "Rain.h"

int main()
{
	std::cout << "Hello World\n";

	std::srand(static_cast<unsigned>(time(NULL)));

	Rain rain;

	while (rain.running())
	{
		rain.Update();

		rain.Render();
	}
	return 0;
}
#include "Engine.h"
#include <windows.h>
/**
    last error is:
    SAAT MENDELET CIRCLE MAKA ERROR ;-; (FIX!)

    feature left:
    sound effect (SFX)
    and finishing.

    project statue done: 100%

*/

int main()
{
    int width = 0,height = 0;

    types:
    char type;
    std::cout << "Use Default configuration or manual? (d/m): ";
    std::cin >> type;

    if(type == 'd' || type == 'D') {width = 500; height = 500;}
    else if(type == 'm' || type == 'M') {
        std::cout << "Width = "; std::cin >> width;
        std::cout << "Height = "; std::cin >> height;
    } else {
        std::cerr << "\nError, please choose the correct answer!\n";
        system("pause");
        system("cls");
        goto types;
    }

    FreeConsole(); /// Menyembunyikan Console.

    srand(time(NULL));

    std::string title_game = "Click The Balls";


    Engine engine(width,height, title_game);

    engine.run();


    return 0;
}

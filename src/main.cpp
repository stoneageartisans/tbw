#include "application.h"

using namespace std;

int main()
{
    Application* app = new Application();
    
    app->run();
    
    delete app;
    
    return 0;
}


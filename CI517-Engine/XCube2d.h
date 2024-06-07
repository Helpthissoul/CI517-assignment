#include <stdio.h>
#include <string>
#include <vector>
#include <memory>
#include "GraphicsEngine.h"
#include "EventEngine.h"

const int _ENGINE_VERSION_MAJOR = 0;
const int _ENGINE_VERSION_MINOR = 1;

class XCube2Engine {
private:
    static std::shared_ptr<XCube2Engine> instance;
    std::shared_ptr<GraphicsEngine> gfxInstance;
    std::shared_ptr<EventEngine> eventInstance;


    XCube2Engine();
public:

    static std::shared_ptr<XCube2Engine> getInstance();
    
    ~XCube2Engine();

    std::shared_ptr<GraphicsEngine> getGraphicsEngine() { return gfxInstance; }
    std::shared_ptr<EventEngine> getEventEngine() { return eventInstance; }


    static void quit();


};

typedef XCube2Engine XEngine;



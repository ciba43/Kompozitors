#include <iostream>
#include <wayland-server-core.h>

// I don't know why this is needed
#define WLR_USE_UNSTABLE

// This is an ugly hack that's here because that code uses C functionality that is not in C++
extern "C"
{
#define static
#include <wlr/backend.h>
#include <wlr/render/wlr_renderer.h>
#undef static
}

#include <wlr/util/log.h>
#include <xkbcommon/xkbcommon.h>

int main(int argc, char** argv)
{
    std::cout << "Hello World" << std::endl;
    return 0;
}
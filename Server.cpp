#include "Server.h"

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

bool Server::init() {
    m_wayland_display = wl_display_create();
    if (!m_wayland_display) {
        std::cout << "Error: Failed to create a Wayland display object" << std::endl;
        return false;
    }

    m_wayland_event_loop = wl_display_get_event_loop(m_wayland_display);
    if (!m_wayland_event_loop) {
        std::cout << "Error: Failed to get the Wayland event loop" << std::endl;
        wl_display_destroy(m_wayland_display);
        return false;
    }

    m_wlroots_backend = wlr_backend_autocreate(m_wayland_display);
    if (!m_wlroots_backend) {
        std::cout << "Error: Failed to autocreate Wlroots backend" << std::endl;
        wl_display_destroy(m_wayland_display);
        return false;
    }

    if (!wlr_backend_start(m_wlroots_backend)) {
        std::cout << "Error: Failed to failed to start Wlroots backend" << std::endl;
        wl_display_destroy(m_wayland_display);
        return false;
    }

    return true;
}

void Server::run() {
    wl_display_run(m_wayland_display);
    wl_display_destroy(m_wayland_display);
}

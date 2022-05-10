
struct wl_display;
struct wl_event_loop;
struct wlr_backend;

class Server {
public:
    Server() {}

    bool init();

    void run();
private:
    wl_display* m_wayland_display;
    wl_event_loop* m_wayland_event_loop;
    wlr_backend* m_wlroots_backend;
};

project('Kompozitors', 'cpp')

wlroots_dep = dependency('wlroots')
wayland_server_dep = dependency('wayland-server')

sources = [
    'Main.cpp',
    'Server.cpp'
]

executable ('Kompozitors', sources, dependencies : [wlroots_dep, wayland_server_dep])
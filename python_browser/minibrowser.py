#!/usr/bin/env python
# -*- coding: utf-8 -*-

import gtk
import webkit

def entry_activated_cb(entry, embed):
    embed.load_uri(entry.get_text())

# Widgets and signals
window = gtk.Window()
window.set_default_size(800, 600)
window.set_title("Mini browser written in Python")
embed = webkit.WebView(); # WebKit embed
entry = gtk.Entry()
entry.connect('activate', entry_activated_cb, embed)
scroller = gtk.ScrolledWindow()
scroller.add(embed)

# Pack everything up and show
vbox = gtk.VBox(False, 5)
vbox.pack_start(entry, False, False)
vbox.pack_start(scroller)
window.add(vbox)
window.show_all()

# Load a default URI and run
embed.load_uri("http://www.webkit.org")
gtk.main()

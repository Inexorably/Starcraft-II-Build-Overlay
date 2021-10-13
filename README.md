# Starcraft-II-Build-Overlay

Created in Qt 5. Beginnings of a build order overlay for Starcraft II, Legacy of the Void.  To run will require a window called "Starcraft II" to be running.  Uses windowAPI functions.

Edit as of 10/13/2021: over the years various people have contacted me about this program.  If this build overlay does not detect your client, it is because the window is not named "Starcraft II".  To fix this, you can download Qt 5 and change `target_window = FindWindowA("Starcraft II", 0);` in mainwindow.cpp to whatever your window is called.  I unfortunately haven't had time to play starcraft for a while, so you will need to make this change and recompile yourself.


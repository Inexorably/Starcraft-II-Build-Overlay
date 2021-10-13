# Starcraft-II-Build-Overlay

Created in Qt 5. Build order overlay for Starcraft II, Legacy of the Void.  To run will require a window called "Starcraft II" to be running.  Uses windowAPI functions.

![image](https://user-images.githubusercontent.com/16945020/137110069-0ced64c8-e2e1-447d-8d28-ee32cb4a948e.png)

See this reddit post for more sample screenshots and an example of the build .txt formatting:

https://www.reddit.com/r/starcraft/comments/4g2ir7/build_order_overlay/

Edit as of 10/13/2021: over the years various people have contacted me about this program.  If this build overlay does not detect your client, it is because the window is not named "Starcraft II".  To fix this, you can download Qt 5 and change `target_window = FindWindowA("Starcraft II", 0);` in mainwindow.cpp to whatever your window is called.  I unfortunately haven't had time to play starcraft for a while, so you will need to make this change and recompile yourself.


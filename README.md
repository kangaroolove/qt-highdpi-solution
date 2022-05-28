## Qt-HighDPI-Solution
This is a project which teaches you how to solve the high dpi problem in qt. Looking at the qt assistant, it tells us that using a attribute which called Qt:AA_EnableHighDpiScaling. However, I found that it didn't work well, so I tried to use other methods to achieve that. There are two methods you can use.

## Important
If your project combines with OpenGL, you need to be careful. In other words, If you just write the OpenGL in Qt, I think it's OK, and you dont't need to do anything special. Whereas, If you are using a OpenGL lib which was written by your colleagues, It means that you maybe need to handle the dpi by yourself to get a correct result, like correct OpenGL window size or position. Please do some tests to verify whether existing those problems.

## Method1
- Step1: Update your Qt version >= 6.3.
- Step2: You don't need to do extra action, just rebuild your project.

If you can't change the Qt version or you find that your project can't be compiled through, when you build your project with Qt6. Then you can use the following method. This method is based on Windows, but it doesn't matter whether your projects based on Linux or Mac. They are the same thought. This method is suitable for Qt5 version which supports QT_SCALE_FACTOR. It means that Qt version >= 5.6, if I remember correctly.
## Method2
- Step1: Calculate the scale factor
- Step2: Use QT_SCALE_FACTOR, and I find the application will scale the size correctly and the font is clear.

## In addition
To achieve better scaling display, we should use vectorgraph, like svg. Moreover, we should use AA_UseHighDpiPixmaps and QIcon to get a clear picture. I have done some tests in the code. There are some conclusions about combining svg.
### Conclusions
- If you use StyleSheet，you have to use image:url. On the other hand, border-image and background-image are error.
- You should use point size throughtout your application, when you are using font.
- You should use a QPixmap which is produced by QIcon, when you are using a painter to draw pixmaps or decorating buttons and so on.
## Result
![image](https://user-images.githubusercontent.com/16329871/170678289-9e9203e3-a5dc-4238-9f13-3969a4e0b122.png)


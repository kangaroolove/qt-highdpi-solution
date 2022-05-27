#include "mainwindow.h"
#include <windows.h>
#include <QApplication>
#include <QDebug>
#include <QScreen>
#include <WinUser.h>
#include <iostream>
#include <qpixmap.h>

double calculateScaleFactor()
{
    auto activeWindow = GetActiveWindow();
    HMONITOR monitor = MonitorFromWindow(activeWindow, MONITOR_DEFAULTTONEAREST);

    // Get the logical width and height of the monitor
    MONITORINFOEX monitorInfoEx;
    monitorInfoEx.cbSize = sizeof(monitorInfoEx);
    GetMonitorInfo(monitor, &monitorInfoEx);
    auto cxLogical = monitorInfoEx.rcMonitor.right - monitorInfoEx.rcMonitor.left;
    auto cyLogical = monitorInfoEx.rcMonitor.bottom - monitorInfoEx.rcMonitor.top;

    // Get the physical width and height of the monitor
    DEVMODE devMode;
    devMode.dmSize = sizeof(devMode);
    devMode.dmDriverExtra = 0;
    EnumDisplaySettings(monitorInfoEx.szDevice, ENUM_CURRENT_SETTINGS, &devMode);
    auto cxPhysical = devMode.dmPelsWidth;
    auto cyPhysical = devMode.dmPelsHeight;

    // Calculate the scaling factor
    double horizontalScale = ((double)cxPhysical / (double)cxLogical);
    double verticalScale = ((double)cyPhysical / (double)cyLogical);

    std::cout << "Horizonzal scaling: " << horizontalScale << "\n";
    std::cout << "Vertical scaling: " << verticalScale;

    return horizontalScale > verticalScale ? verticalScale : horizontalScale;
}


int main(int argc, char *argv[])
{
    double scaleFactor = calculateScaleFactor();
    // enable QIcon produces highdpi pixmap
    QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);

    qputenv("QT_SCALE_FACTOR", QByteArray::number(scaleFactor));

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

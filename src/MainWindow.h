#include <QtWidgets>

class MainWindow {
public:
    MainWindow(int width, int height, QString title);
    void show();

private:
    QWidget* window;
};
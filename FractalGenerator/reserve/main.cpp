#include "mainwindow.h"

int main(int argc, char*argv[])
{
    QApplication app(argc,argv);

    MainWindow window;

    window.setWindowIcon(QIcon("fractalsymb.ico"));
    window.setWindowTitle("Fractal Generator");
    window.resize(900, 900);
    window.show();

    return app.exec();
}

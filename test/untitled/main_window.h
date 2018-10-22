#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <cstdlib>
#include "generator.h"
#include "profile.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_selection_activated(const QString &arg1);

private:
    Ui::MainWindow *ui;
    Profile userProfile_;
};

#endif // MAIN_WINDOW_H

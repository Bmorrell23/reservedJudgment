#include "main_window.h"
#include "ui_main_window.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , userProfile_()
{
    ui->setupUi(this);
    ui->selection->addItem("");
    ui->selection->addItem("Movies");
    ui->selection->addItem("Restaurants");
    ui->selection->addItem("Games");
    ui->selection->addItem("Entertainment");

    ui->output->setText("Output");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_selection_activated(const QString &arg1)
{
    std::vector<QString> movieChoices         = {"Venom", "Goosebumps", "A Star is Born", "Charlotte's Web", "Smallfoot"};
    std::vector<QString> foodChoices          = {"Applebee's", "Jimmy John's", "Ramen Bowls", "Pizza Shuttle", "El Mezcal"};
    std::vector<QString> gameChoices          = {"League of Legends", "DOTA", "HALO 5", "Black Ops 4", "SuperMario Odyssey"};
    std::vector<QString> entertainmentChoices = {"The Bottleneck", "The Jayhawk Cafe", "Astro's Billiard Hall", "The Replay Lounge", "Brothers"};

    int index = rand() % 5;

    if(arg1 == "Movies")
        ui->output->setText(movieChoices[index]);
    else if(arg1 == "Restaurants")
        ui->output->setText(foodChoices[index]);
    else if(arg1 == "Games")
        ui->output->setText(gameChoices[index]);
    else
        ui->output->setText("Bottleneck");
}

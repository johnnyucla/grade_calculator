#include "grade_calculator.h"
#include "ui_grade_calculator.h"

grade_calculator::grade_calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::grade_calculator)
{
    ui->setupUi(this);

    QObject::connect(ui->hw1_sbox,SIGNAL(valueChanged(int)), this, SLOT(update_overall(int)));

    QObject::connect(ui->hw2_sbox,SIGNAL(valueChanged(int)), this, SLOT(update_overall(int)));

    QObject::connect(ui->hw3_sbox,SIGNAL(valueChanged(int)), this, SLOT(update_overall(int)));

    QObject::connect(ui->hw4_sbox,SIGNAL(valueChanged(int)),this, SLOT(update_overall(int)));

    QObject::connect(ui->hw5_sbox,SIGNAL(valueChanged(int)), this, SLOT(update_overall(int)));

    QObject::connect(ui->hw6_sbox,SIGNAL(valueChanged(int)), this, SLOT(update_overall(int)));

    QObject::connect(ui->hw7_sbox,SIGNAL(valueChanged(int)), this, SLOT(update_overall(int)));

    QObject::connect(ui->hw8_sbox,SIGNAL(valueChanged(int)), this, SLOT(update_overall(int)));

    QObject::connect(ui->m1_sbox,SIGNAL(valueChanged(int)), this, SLOT(update_overall(int)));

    QObject::connect(ui->m2_sbox,SIGNAL(valueChanged(int)), this, SLOT(update_overall(int)));

    QObject::connect(ui->final_sbox,SIGNAL(valueChanged(int)), this, SLOT(update_overall(int)));
}

grade_calculator::~grade_calculator()
{
    delete ui;
}

void grade_calculator::update_overall(int unused){
    double score;
    score = static_cast<double>(unused);

    double hw = (ui->hw1_sbox->value() + ui->hw2_sbox->value() + ui->hw3_sbox->value() + ui->hw4_sbox->value()
            + ui->hw5_sbox->value() + ui->hw6_sbox->value() +ui->hw7_sbox->value() + ui->hw8_sbox->value())/8;
    double m1 = ui->m1_sbox->value();
    double m2 = ui->m2_sbox->value();
    double final = ui->final_sbox->value();

    double max = m1;

    if (m2 > max)
    {
        max = m2;
        QString text(QString::number( hw*(0.20) + max*(.25) + final*(.55)));
        ui->label_score->setText(text);
    }

    else
    {
        QString text(QString::number( hw*(0.20) + m1*(.20) + m2*(.20) + final*(.40)));
        ui->label_score->setText(text);
    }

    return;
}

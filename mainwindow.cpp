#include "QLabel"
#include "QTime"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#define VISION_CHART_FONT   "sans-serif"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTime now = QTime::currentTime();
    qsrand(now.msec());

    this->setStyleSheet("background-color: white;");
    initChart();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseDoubleClickEvent( QMouseEvent * e )
{
    if ( e->button() == Qt::LeftButton ) {
        for (int i = 0; i < ui->gridLayout->count(); i++){
           ui->gridLayout->itemAt(i)->widget()->deleteLater();
        }
        initChart();
    }
}

void MainWindow::initChart() {
    QString letters="PEZOLCFTD";
    int fontSizes[]={160, 100, 70, 50, 40, 30, 25, 20, 16, 12, 10, 6};
    int index[50];
    int row = 0;
    for (int line = 0; line < 11; ++line) {
        QLabel *leftSpacer = new QLabel(this);
        ui->gridLayout->addWidget(leftSpacer, row,  0);

        QLabel *label = new QLabel(this);
        label->setAlignment(Qt::AlignCenter);
        QFont font(VISION_CHART_FONT, fontSizes[line], QFont::Bold);
        label->setFont(font);

        for (int j = 0; j < letters.length(); ++j)
            index[j] = j;
        for (int j = 0; j < letters.length() * 2; ++j) {
            int sel1 = qrand() % letters.length();
            int sel2 = qrand() % letters.length();
            int tmp = index[sel1];
            index[sel1]=index[sel2];
            index[sel2]=tmp;
        }
        int chars = line + 1;
        if (chars > 8)
            chars = 8;
        QString txt = "  ";
        for (int j = 0; j < chars; ++j) {
            txt += letters.mid(index[j], 1) + "  ";
        }
        label->setText(txt);
        ui->gridLayout->addWidget(label, row, 1);

        QLabel *rightSpacer = new QLabel(this);
        rightSpacer->setText(QString::number(line+1));
        rightSpacer->setStyleSheet("QLabel { font-size:10;}");
        ui->gridLayout->addWidget(rightSpacer, row++,  2);

        if (line == 5) {
            QLabel *separator = new QLabel(this);
            separator->setFixedHeight(10);
            separator->setText(" ");
            separator->setStyleSheet("QLabel { background-color : green;font-size:2;}");
            ui->gridLayout->addWidget(separator, row++, 1);
        }
    }
}

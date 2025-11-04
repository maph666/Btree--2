#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    connect(ui->pushButtonInsert, &QPushButton::clicked, this, &MainWindow::on_pushButtonInsert_clicked);
    connect(ui->pushButtonInOrder, &QPushButton::clicked, this, &MainWindow::on_pushButtonInOrder_clicked);
    connect(ui->pushButtonPreOrder, &QPushButton::clicked, this, &MainWindow::on_pushButtonPreOrder_clicked);
    connect(ui->pushButtonPostOrder, &QPushButton::clicked, this, &MainWindow::on_pushButtonPostOrder_clicked);
    connect(ui->pushButtonSearch, &QPushButton::clicked, this, &MainWindow::on_pushButtonSearch_clicked);
    // Insertar valores de ejemplo
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButtonInsert_clicked() {
    bool ok;
    int value = ui->lineEditValue->text().toInt(&ok);
    if (ok) {
        tree.insert(value);
        ui->lineEditValue->clear();
        update(); // Refresca la pantalla
    }
}
void MainWindow::on_pushButtonInOrder_clicked() {
    ui->listWidgetTraversal->clear();
    std::vector<int> values = tree.inOrderTraversal();
    for (int val : values) {
        ui->listWidgetTraversal->addItem(QString::number(val));
    }
}

void MainWindow::on_pushButtonPreOrder_clicked() {
    ui->listWidgetTraversal->clear();
    std::vector<int> values = tree.preOrderTraversal();
    for (int val : values) {
        ui->listWidgetTraversal->addItem(QString::number(val));
    }
}

void MainWindow::on_pushButtonPostOrder_clicked() {
    ui->listWidgetTraversal->clear();
    std::vector<int> values = tree.postOrderTraversal();
    for (int val : values) {
        ui->listWidgetTraversal->addItem(QString::number(val));
    }
}

void MainWindow::on_pushButtonSearch_clicked() {
    bool ok;
    int value = ui->lineEditSearch->text().toInt(&ok);
    if (ok) {
        bool found = tree.search(value);
        if (found) {
            ui->labelSearchResult->setText("✅ Valor encontrado en el árbol");
        } else {
            ui->labelSearchResult->setText("❌ Valor no encontrado");
        }
    } else {
        ui->labelSearchResult->setText("⚠️ Ingresa un número válido");
    }
}


void MainWindow::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    drawTree(painter, tree.getRoot(), width() / 2, 50, 100);
}

void MainWindow::drawTree(QPainter& painter, Node* node, int x, int y, int offset) {
    if (!node) return;

    painter.drawEllipse(x - 15, y - 15, 30, 30);
    painter.drawText(x - 10, y + 5, QString::number(node->value));

    if (node->left) {
        painter.drawLine(x, y, x - offset, y + 50);
        drawTree(painter, node->left, x - offset, y + 50, offset / 2);
    }
    if (node->right) {
        painter.drawLine(x, y, x + offset, y + 50);
        drawTree(painter, node->right, x + offset, y + 50, offset / 2);
    }
}

void MainWindow::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{

}


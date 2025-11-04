#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include "binarytree.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::MainWindow *ui;
    BinaryTree tree;
    void drawTree(QPainter& painter, Node* node, int x, int y, int offset);

private slots:
    void on_pushButtonInsert_clicked();
    void on_pushButtonInOrder_clicked();  // ← Nuevo slot
    void on_pushButtonPreOrder_clicked();     // ← nuevo
    void on_pushButtonPostOrder_clicked();    // ← nuevo
    void on_pushButtonSearch_clicked();
    void on_pushButtonDelete_clicked();



};

#endif // MAINWINDOW_H

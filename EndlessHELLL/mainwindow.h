#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
private:
    Q_OBJECT
    int pages = 10;
    int counter;
    QString text[10] = {"Приходит парень к девушке, только познакомились.", "А парню срать так хочется, что слезы из глаз.",
                        "Она его оставила в комнате, а сама пошла чай делать.", "В комнате здоровенная собака сидит, но вроде смирная.",
                        "Думает — выхода нет — придется на собаку свалить.", "Снимает брюки, серит прям на ковер.",
                        "Заходит девушка с подносом. Принюхивается.", "— Сереженька, тебе не кажется что здесь неприятно пахнет?",
                        "— Еще как кажется — это собака твоя, падла, насрала!", "— Ты что дебил? Она же плюшевая."
                       };
    Ui::MainWindow *ui;

private slots:
    void turnPage();
    void prevPage();
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_H

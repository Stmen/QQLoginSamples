#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "qtoolbarex.h"

class LoginMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit LoginMainWindow(QWidget *parent = nullptr);
protected:
    void init(QWidget *widget);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void startWork();
private:
    QRectGradientWidget *m_pLiveWidget;
    QPoint m_lastPos;
    QLiveWorkThread *m_pThreadOfLive;
    QPushButton *m_loginBt;
signals:
public slots:
    void closeLoginFrame();
};

#endif // MAINWINDOW_H

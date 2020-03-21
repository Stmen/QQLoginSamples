#ifndef QTOOLBAREX_H
#define QTOOLBAREX_H

#include <QThread>
#include <QWidget>

class QPushButton;

class QToolBarEx : public QWidget
{
    Q_OBJECT
public:
    QToolBarEx(QWidget *parent = nullptr, QWidget *mainFrame=nullptr);
protected:
    QPushButton *m_closeBt;
    QPushButton *m_minBt;
    QPushButton *m_setBt;
};


class QRectGradientWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QRectGradientWidget(QWidget *parent = nullptr);
    void setGradientPos(int key);
    int getGradientPos();
protected:
    void paintEvent(QPaintEvent *event);
private:
    double m_GradientPos;
    int m_flag;
public slots:
    void LiveGradientWork();
};

class QLiveWorkThread : public QThread
{
    Q_OBJECT
public:
    explicit QLiveWorkThread(QObject *parent = nullptr);
    void setWidget(QWidget *widget);
protected:
    void run();
private:
    QWidget *m_pLiveWidget;
signals:
    void change();
};

class QCircleWidget : public QWidget
{
    Q_OBJECT
public:
    QCircleWidget(QWidget *parent = nullptr, QString imagePath = "");
protected:
    QString m_imageString;
    void paintEvent(QPaintEvent *);
};

#endif // QTOOLBAREX_H

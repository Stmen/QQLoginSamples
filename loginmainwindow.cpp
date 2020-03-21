#include "loginmainwindow.h"
#include "qqlineedit.h"
#include "qtoolbarex.h"

#include <QCheckBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QMouseEvent>
#include <qapplication.h>
#include <qpushbutton.h>

LoginMainWindow::LoginMainWindow(QWidget *parent) : QMainWindow(parent)
{
    QWidget *loginWidget = new QWidget(this);

    m_pLiveWidget = new QRectGradientWidget;
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(m_pLiveWidget);
    loginWidget->setLayout(layout);
    layout->setMargin(0);

    QToolBarEx *toolBar = new QToolBarEx(loginWidget , this);
    toolBar->setGeometry(0,0,430,toolBar->height());

    init(loginWidget);
}

void LoginMainWindow::init(QWidget *widget)
{
    setCentralWidget(widget);
    setContentsMargins(0,0,0,0);
    setWindowFlags(Qt::Window|Qt::FramelessWindowHint
                   |Qt::WindowSystemMenuHint
                   |Qt::WindowMinimizeButtonHint
                   |Qt::WindowMaximizeButtonHint);
    setMinimumSize(430,330);
    QPalette palette(this->palette());
    palette.setColor(QPalette::Background, Qt::white);
    setPalette(palette);


    QCircleWidget *circle = new QCircleWidget(widget);
    circle->setGeometry(165,100,100,100);

    QLabel *qqFont = new QLabel(this);
    QFont font("Microsoft YaHei", 15, QFont::DemiBold);
    qqFont->setFont(font);
    qqFont->setText("QQ");
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::white);
    qqFont->setPalette(pa);
    qqFont->setGeometry(45,10,50,30);


    QPixmap qqImage(":/LoginFrame/Res/whiteQQ.png");
    QLabel *qqIcon = new QLabel(this);
    qqIcon->resize(30,30);
    qqImage = qqImage.scaled(qqIcon->width(),qqIcon->height(),Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    qqIcon->setPixmap(qqImage);
    qqIcon->setGeometry(10,10,30,30);


    QQLineEdit *userEdit = new QQLineEdit(this);
    userEdit->setGeometry(110,190,230,30);

    QQLineEdit *passwdEdit = new QQLineEdit(this);
    passwdEdit->setGeometry(110,220,230,30);
    passwdEdit->setImage(":/LoginFrame/Res/passwd.png",LabelImage);
    passwdEdit->setImage(":/LoginFrame/Res/keyboard.png",BtImage);
    passwdEdit->setPlaceholderText("密码");

    QWidget *checkWidget = new QWidget(this);
    QPalette checkPa;
    checkPa.setColor(QPalette::WindowText,Qt::gray);
    QCheckBox *autoLogin = new QCheckBox("自动登录");
    QCheckBox *remeberPas = new QCheckBox("记住密码");
    QLabel *findPass = new QLabel("找回密码");
    QHBoxLayout *layout = new QHBoxLayout;
    autoLogin->setPalette(checkPa);
    remeberPas->setPalette(checkPa);
    findPass->setPalette(checkPa);
    layout->addWidget(autoLogin);
    layout->addStretch();
    layout->addWidget(remeberPas);
    layout->addStretch();
    layout->addWidget(findPass);
    layout->setMargin(0);
    checkWidget->setLayout(layout);
    checkWidget->setGeometry(110,250,230,30);

    m_loginBt = new QPushButton("登录",this);
    m_loginBt->setGeometry(110,280,230,35);
    m_loginBt->setStyleSheet("QPushButton{border:1px solid rgba(0,0,0,0);border-radius:5px;background:#00BFFF;"
                             "font:normal 15px 'Microsoft YaHei';color:rgb(255,255,255,255);};");

    QLabel *registBt = new QLabel(this);
    registBt->setText("注册账号");
    registBt->setPalette(checkPa);
    registBt->setGeometry(15,300,60,30);

    QPixmap btImage(":/LoginFrame/Res/qrCode.png");
    btImage = btImage.scaled(60,60,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPushButton *qrCode = new QPushButton(this);
    qrCode->setAutoFillBackground(true);
    qrCode->setIcon(btImage);
    qrCode->setIconSize(QSize(30,30));
    qrCode->setFlat(true);
    qrCode->setBackgroundRole(QPalette::NoRole);
    qrCode->setGeometry(390,290,30,30);

    startWork();

}

void LoginMainWindow::mousePressEvent(QMouseEvent *event)
{
    m_lastPos = event->globalPos();
}

void LoginMainWindow::mouseMoveEvent(QMouseEvent *event)
{
    this->move(this->x() + (event->globalX() - m_lastPos.x()),
                  this->y() + (event->globalY() - m_lastPos.y()));
       m_lastPos = event->globalPos();
}

void LoginMainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    m_lastPos = event->globalPos();
}

void LoginMainWindow::startWork()
{
    m_pThreadOfLive =new QLiveWorkThread();
    m_pThreadOfLive->setWidget(m_pLiveWidget);
    m_pThreadOfLive->start();

    connect(m_pThreadOfLive,SIGNAL(change()),m_pLiveWidget, SLOT(LiveGradientWork()), Qt::BlockingQueuedConnection);
}

void LoginMainWindow::closeLoginFrame()
{
    QApplication* app;
    app->quit();
}

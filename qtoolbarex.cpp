#include "qtoolbarex.h"
#include "loginmainwindow.h"

#include <QHBoxLayout>
#include <QPainter>
#include <QPushButton>

QToolBarEx::QToolBarEx(QWidget *parent, QWidget *mainFrame):QWidget(parent)
{

    QHBoxLayout *layout = new QHBoxLayout();
    layout->setMargin(0);
    m_closeBt = new QPushButton();
    m_closeBt->setAutoFillBackground(true);
    QPixmap closeIcon(":/LoginFrame/Res/close.png");
    m_closeBt->setIcon(closeIcon);
    m_closeBt->setFlat(true);
    m_closeBt->setBackgroundRole(QPalette::NoRole);

    m_minBt = new QPushButton();
    m_minBt->setAutoFillBackground(true);
    QPixmap minIcon(":/LoginFrame/Res/min.png");
    m_minBt->setIcon(minIcon);
    m_minBt->setFlat(true);
    m_minBt->setBackgroundRole(QPalette::NoRole);

    m_setBt = new QPushButton();
    m_setBt->setAutoFillBackground(true);
    QPixmap setIcon(":/LoginFrame/Res/set.png");
    m_setBt->setIcon(setIcon);
    m_setBt->setFlat(true);
    m_setBt->setBackgroundRole(QPalette::NoRole);

    layout->addStretch(1);
    layout->addWidget(m_setBt);
    layout->addWidget(m_minBt);
    layout->addWidget(m_closeBt);

    setLayout(layout);
    setAutoFillBackground(true);


    QPalette palette;
    palette.setColor(QPalette::Background , QColor(51,204,255));
    setPalette(palette);

    LoginMainWindow *main = dynamic_cast<LoginMainWindow *>(mainFrame);
    connect(m_closeBt,SIGNAL(pressed()),main, SLOT(closeLoginFrame()));

}


QRectGradientWidget::QRectGradientWidget(QWidget *parent): QWidget(parent)
{
    m_GradientPos = 1.0;
    m_flag = 0;
}

void QRectGradientWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    // 反走样
    painter.setRenderHint(QPainter::Antialiasing, true);

    // 设置渐变色
    QLinearGradient linear(QPointF(0, 0), QPointF(0, 150));
    linear.setColorAt(0, QColor(51,204,255));
    linear.setColorAt(0.2, QColor(51,204,255));
    linear.setColorAt(m_GradientPos, QColor(131,111,255));
    linear.setColorAt(1, QColor(131,111,255));

    // 设置显示模式
    linear.setSpread(QGradient::PadSpread);

    // 设置画笔颜色、宽度
    painter.setPen(Qt::NoPen);

    // 设置画刷填充
    painter.setBrush(linear);

    // 绘制椭圆
    painter.drawRect(QRect(0, 0, 430, 150));
}

void QRectGradientWidget::LiveGradientWork()
{
    if(!m_flag)
        m_GradientPos = m_GradientPos - 0.001;
    else
        m_GradientPos = m_GradientPos + 0.001;
    if(m_GradientPos <= 0.4)
        m_flag = 1;
    else if(m_GradientPos == 1)
        m_flag = 0;
    repaint();
}


void QLiveWorkThread::run()
{
    while(true)
    {
        QThread::msleep(10);
        emit change();
    }
}

QLiveWorkThread::QLiveWorkThread(QObject *parent) : QThread(parent)
{

}

void QLiveWorkThread::setWidget(QWidget *widget)
{
    m_pLiveWidget = widget;
}

QCircleWidget::QCircleWidget(QWidget *parent, QString imagePath): QWidget(parent)
{
    if(imagePath == "")
        m_imageString = ":/LoginFrame/Res/qq.png";
    else
        m_imageString = imagePath;
}

void QCircleWidget::paintEvent(QPaintEvent *)
{
    QPainter paint(this);
    QPen pen;
    pen.setColor(Qt::white);
    pen.setWidth(2);
    paint.setRenderHint(QPainter::Antialiasing, true);
    paint.setPen(pen);
    paint.setBrush(Qt::darkGray);
    paint.drawEllipse(QRectF(20,20,70,70));
    paint.drawPixmap(QRectF(27,26,55,55),QPixmap(m_imageString),QRectF());
}

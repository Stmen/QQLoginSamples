#include "qqlineedit.h"

#include <QHBoxLayout>
#include <QPushButton>
#include <qlabel.h>

QQLineEdit::QQLineEdit(QWidget *parent) : QLineEdit(parent)
{

    m_labelImage = new QLabel;
    m_editExBt = new QPushButton;

    QPixmap labelImage(":/LoginFrame/Res/grayqq.png");

    m_labelImage->resize(15,15);
    labelImage = labelImage.scaled(m_labelImage->width(),m_labelImage->height(),Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    m_labelImage->setPixmap(labelImage);

    QPixmap btImage(":/LoginFrame/Res/downPush.png");

    m_editExBt->setAutoFillBackground(true);
    m_editExBt->setIcon(btImage);
    m_editExBt->setFlat(true);
    m_editExBt->setBackgroundRole(QPalette::NoRole);

    int x = this->width()-m_editExBt->width();
    QMargins myMargins = this->textMargins();
    setTextMargins(m_labelImage->width(),myMargins.top(),x,myMargins.bottom());

    QHBoxLayout *layout = new QHBoxLayout;
    layout->setMargin(0);
    layout->addWidget(m_labelImage);
    layout->addStretch();
    layout->addWidget(m_editExBt);
    setLayout(layout);

    setAutoFillBackground(true);

    setPlaceholderText("QQ号码/手机/邮箱");
    setFont(QFont("Cursive",10,QFont::Thin));
    setStyleSheet("QLineEdit{border:1px solid rgb(0,0,0);"
                  "border-left-color:rgba(0,0,0,0);"
                  "border-top-color:rgba(0,0,0,0);"
                  "border-right-color:rgba(0,0,0,0);"
                  "focus{ background-color: red; }}");
}

void QQLineEdit::setImage(QString path, int index)
{
    QPixmap Image(path);
    switch (index)
    {
    case 1:
        m_labelImage->resize(15,15);
        Image = Image.scaled(m_labelImage->width(),m_labelImage->height(),Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        m_labelImage->setPixmap(Image);
        break;
    case 2:
        m_editExBt->setAutoFillBackground(true);
        m_editExBt->setIcon(Image);
        m_editExBt->setFlat(true);
        m_editExBt->setBackgroundRole(QPalette::NoRole);
        break;
    default:
        return;

    }
}

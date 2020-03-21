#ifndef QQLINEEDIT_H
#define QQLINEEDIT_H

#define LabelImage 1
#define BtImage 2

#include <QLineEdit>

class QLabel;
class QPushButton;

class QQLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    QQLineEdit(QWidget *parent = nullptr);
    void setImage(QString path , int index);
private:
    QLabel *m_labelImage;
    QPushButton *m_editExBt;
};

#endif // QQLINEEDIT_H

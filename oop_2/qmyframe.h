#ifndef QMYFRAME_H
#define QMYFRAME_H
#include <QFrame>

class QMyFrame : public QFrame
{
    Q_OBJECT
public:
    QMyFrame(QWidget *pwgt=0);
protected:
    //нажатие на кнопку мыши
    virtual void mousePressEvent  (QMouseEvent* pe);
    //отпускание кнопки мыши
    virtual void mouseReleaseEvent(QMouseEvent* pe);
    //перемещение мыши
    virtual void mouseMoveEvent   (QMouseEvent* pe);
    //вывод о состоянии события мыши
    void    dumpEvent     (QMouseEvent* pe, const QString& strMessage);
    //информация о клавишах-модификаторах
    QString modifiersInfo (QMouseEvent* pe);
    //информацию о кнопках мыши
    QString buttonsInfo   (QMouseEvent* pe);
signals:
    void mouseUp(QPoint pos);
    void mouseDown(QPoint pos);
};

#endif // QMYFRAME_H

#include "qmyframe.h"
#include <QLayout>
#include <QMouseEvent>
#include <QMessageBox>

QMyFrame::QMyFrame(QWidget* pwgt) : QFrame(pwgt) {}

void QMyFrame::mousePressEvent(QMouseEvent* pe)
{
    //dumpEvent(pe, "Нажаты кнопки мыши");
    emit mouseDown(pe->pos());
}

void QMyFrame::mouseReleaseEvent(QMouseEvent* pe)
{
    //dumpEvent(pe, "Кнопка мыши отпущена");
    emit mouseUp(pe->pos());
}

void QMyFrame::mouseMoveEvent(QMouseEvent* pe)
{
    //dumpEvent(pe, "Указатель мыши перемещается");

}

void QMyFrame::dumpEvent(QMouseEvent* pe, const QString& strMsg)
{
    QMessageBox::information(this, "Warning", strMsg
            + "\n buttons()=" + buttonsInfo(pe)
            + "\n x()=" + QString::number(pe->x())
            + "\n y()=" + QString::number(pe->y())
            + "\n globalX()=" + QString::number(pe->globalX())
            + "\n globalY()=" + QString::number(pe->globalY())
            + "\n modifiers()=" + modifiersInfo(pe));
}

QString QMyFrame::modifiersInfo(QMouseEvent* pe)
{
    QString strModifiers;

    if(pe->modifiers() & Qt::ShiftModifier) {
        strModifiers += "Shift";
    }
    if(pe->modifiers() & Qt::ControlModifier) {
        strModifiers += "Control";
    }
    if(pe->modifiers() & Qt::AltModifier) {
        strModifiers += "Alt";
    }
    return strModifiers;
}

QString QMyFrame::buttonsInfo(QMouseEvent* pe)
{
    QString strButtons;

    if(pe->buttons() & Qt::LeftButton) {
        strButtons += "Left ";
    }
    if(pe->buttons() & Qt::RightButton) {
        strButtons += "Right ";
    }
    return strButtons;
}

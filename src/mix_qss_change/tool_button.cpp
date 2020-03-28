#include "tool_button.h"

ToolButton::ToolButton(QWidget* parent)
    : QToolButton(parent) {
    //�����ı���ɫ
    QPalette text_palette = palette();
    text_palette.setColor(QPalette::ButtonText, QColor(230, 230, 230));
    setPalette(text_palette);

    //�����ı�����
    QFont& text_font = const_cast<QFont&>(font());
    text_font.setWeight(QFont::Bold);

    setToolButtonStyle(Qt::ToolButtonTextUnderIcon);



    //���ô�С
    setFixedSize(48 + 25, 48 + 25);
    setAutoRaise(true);
    setObjectName("transparentToolButton");

    mouse_over = false;
    mouse_press = false;
}

ToolButton::~ToolButton() {

}

void ToolButton::enterEvent(QEvent*) {
    mouse_over = true;
}

void ToolButton::leaveEvent(QEvent*) {
    mouse_over = false;
}

void ToolButton::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        emit clicked();
    }
}

void ToolButton::setMousePress(bool mouse_press) {
    this->mouse_press = mouse_press;
    update();
}

void ToolButton::set_picture(QString path) {
    //����ͼ��
    QPixmap pixmap(path);
    pixmap.scaledToHeight(100);
    pixmap.scaledToWidth(160);
    setIcon(pixmap);
    setIconSize(pixmap.size());
}

void ToolButton::paintEvent(QPaintEvent* event) {
    if (mouse_over) {
        //��������Ƶ���ť�ϵİ�ťЧ��
        painterInfo(0, 100, 150);
    } else {
        if (mouse_press) {
            painterInfo(0, 100, 150);
        }
    }

    QToolButton::paintEvent(event);
}

void ToolButton::painterInfo(int top_color, int middle_color, int bottom_color) {
    QPainter painter(this);
    QPen pen(Qt::NoBrush, 1);
    painter.setPen(pen);
    QLinearGradient linear(rect().topLeft(), rect().bottomLeft());
    linear.setColorAt(0, QColor(230, 230, 230, top_color));
    linear.setColorAt(0.5, QColor(230, 230, 230, middle_color));
    linear.setColorAt(1, QColor(230, 230, 230, bottom_color));
    painter.setBrush(linear);
    painter.drawRect(rect());
}

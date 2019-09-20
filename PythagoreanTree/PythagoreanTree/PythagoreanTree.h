#ifndef PYTHAGOREANTREE_H
#define PYTHAGOREANTREE_H

#include <QtWidgets/QWidget>
#include <qtimer.h>
#include <qmutex.h>
#include "ui_pythagoreantree.h"




class PTRect {
public:
    QPointF points_[4];
    float  len_;
    QPointF pt_rotate(QPointF& src, QPointF ref, double alpha) {

        auto temp = src - ref;
        QPointF dest;
        dest.rx() = temp.x() * cos(alpha) - temp.y() * sin(alpha);
        dest.ry() = temp.x() * sin(alpha) + temp.y() * cos(alpha);
        dest += ref;
        return dest;
    }
    void scaled(float scale) {
        auto vec1 = points_[1] - points_[0];
        auto vec2 = points_[2] - points_[1];
        auto vec3 = points_[3] - points_[0];
        points_[1] = points_[0] + vec1 * scale;
        points_[2] = points_[1] + vec2 * scale;
        points_[3] = points_[0] + vec3 * scale;
        len_ *= scale;
    }

    void rotate(float angle) {
        points_[1] = pt_rotate(points_[1], points_[0], angle);
        points_[2] = pt_rotate(points_[2], points_[0], angle);
        points_[3] = pt_rotate(points_[3], points_[0], angle);
    }

    void move(QPointF move_vec) {
        for (int i = 0; i < 4; i++) {
            points_[i] += move_vec;
        }
    }
};

class PythagoreanTree : public QWidget {
    Q_OBJECT

public:
    PythagoreanTree(QWidget* parent = 0);
    ~PythagoreanTree();

    virtual void paintEvent(QPaintEvent*);
    void make_tree(PTRect rc, int);
private slots:
    void st_timer();
private:
    Ui::PythagoreanTreeClass ui;

    QMap<int, PTRect> rects_;
    QMutex mutex_;
    QTimer timer_;
    int     level_ = 15;
    double degree_ = 30;
    int     show_level_ = 0;
    bool    add_ = true;
};

#endif // PYTHAGOREANTREE_H

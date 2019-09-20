#include "pythagoreantree.h"
#include <math.h>
#include <QPainter>

const double PI = 3.1415926;
const double A2D = 180.0 / PI;

PythagoreanTree::PythagoreanTree(QWidget* parent)
    : QWidget(parent) {
    ui.setupUi(this);
    connect(&timer_, &QTimer::timeout, this, &PythagoreanTree::st_timer);

    showFullScreen();
    PTRect first;
    first.points_[0] = QPointF(860, 0);
    first.points_[1] = QPointF(860, 200);
    first.points_[2] = QPointF(1060, 200);
    first.points_[3] = QPointF(1060, 0);
    first.len_ = 200;
    rects_.insertMulti(0,first);
    make_tree(first, level_);
	timer_.start(200);
}

PythagoreanTree::~PythagoreanTree() {

}

void PythagoreanTree::paintEvent(QPaintEvent*) {
    QPainter pa(this);

    mutex_.lock();
    int h = this->height();
//     for (auto rc : rects_) {
//         for (int i = 1; i <= 4; i++) {
//             auto p1 = rc.points_[i - 1];
//             auto p2 = rc.points_[i % 4];
//             auto p1 = rc.points_[i - 1];
//             p2.ry() = h - p2.ry();
//             pa.drawLine(p1, p2);
//         }
//     }

	auto draw_rc = [&](PTRect& rc, QColor clr)
	{
		pa.setBrush(clr);
		pa.setPen(clr);
		QPolygonF pyn;
		for (int i = 0; i < 4;i++)
		{
			auto p1 = rc.points_[i];
			p1.ry() = h - p1.ry();
			pyn.append(p1);
		}
		pa.drawPolygon(pyn);
	};

	for ( int i = 0; i < show_level_;i++)
	{
		auto rcs = rects_.values(i);
		for (auto rc:rcs)
		{
			draw_rc(rc, i >= level_-5 ? Qt::green : QColor(227,138,0));
		}
	}
    mutex_.unlock();
}
void PythagoreanTree::st_timer() {
	if (add_)
	{
		show_level_++;
		if (show_level_ == level_)
		{
			add_ = false;
		}
	}
	else
	{
		show_level_--;
		if (show_level_ == 0)
		{
			add_ = true;
		}

	}
	update();
}

void make_sub(PTRect rc, PTRect& lhs, PTRect& rhs, double deg) {
    PTRect rc1, rc2;
    rc1 = rc;
    rc2 = rc;
    float left_len = rc.len_ * std::cos(deg / A2D);
    float right_len = rc.len_ * std::sin(deg / A2D);
    rc1.scaled(left_len / rc.len_);
    rc2.scaled(right_len / rc.len_);

    //Æ½ÒÆ
    rc1.move(rc.points_[1] - rc.points_[0]);
    rc2.move(rc.points_[2] - rc.points_[0]);
    //Ðý×ª
    rc1.rotate(deg / A2D);
    rc2.rotate(deg / A2D);
    lhs = rc1;
    rhs = rc2;
}

void format_right(PTRect& rc) {
    auto temp = rc.points_[0];
    for (int i = 0; i < 3; i++) {
        rc.points_[i] = rc.points_[i + 1];
    }
    rc.points_[3] = temp;
}

void PythagoreanTree::make_tree(PTRect rc, int level) {
    if (--level == 0)
        return;

    PTRect rc1, rc2;
    make_sub(rc, rc1, rc2, degree_);
    mutex_.lock();
    rects_.insertMulti(level_-level,rc1);
    rects_.insertMulti(level_-level,rc2);
    mutex_.unlock();
    make_tree(rc1, level);
    format_right(rc2);

    make_tree(rc2, level);
}
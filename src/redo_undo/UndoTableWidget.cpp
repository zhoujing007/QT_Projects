#include "UndoTableWidget.h"
#include <QKeyEvent>
#include <QDebug>
#include <QShortcut>
#pragma execution_character_set("utf-8")
UndoTableWidget::UndoTableWidget(QWidget* parent)
    : QTableWidget(parent) {

    createActions();
    //初始时保存第一份undostack数据
    undo_stack_.clear();
    connect(this, SIGNAL(itemChanged(QTableWidgetItem*)), this, SLOT(slotUpdate(QTableWidgetItem*)));
}


UndoTableWidget::~UndoTableWidget() {
}


QVariantList UndoTableWidget::data_record() {
    QVariantList params_list;
    for (int column = 0; column < this->columnCount(); column++) {
        QVariantMap params;
        for (int row = 0; row < this->rowCount(); row++) {
            QString cur_str;
            if (this->item(column, row) == NULL || (this->item(column, row) && this->item(column, row)->text() == "")) {
                cur_str = "";
            } else {
                cur_str = this->item(column, row)->text();
            }
            params[QString::number(row)] = cur_str;
        }
        params_list.append(params);
    }
    undo_stack_ << params_list;
    return params_list;
}

void UndoTableWidget::undo_opera() {
    if (undo_stack_.isEmpty()) {
        return;
    } else {
        //第一次撤销时保存当前所有数据作为当前数据
        is_redo_undo_opt_ = true;
        auto undo_top = undo_stack_.pop();
        redo_stack_.append(undo_top);
        /// cur_table_data = undo_stack_.pop();
        if (undo_stack_.empty()) {
            updta_table(QVariantList());
        } else {
            updta_table(undo_stack_.top());
        }
        is_redo_undo_opt_ = false;
    }
}

void UndoTableWidget::redo_opera() {
    if (redo_stack_.isEmpty()) {
        return;
    } else {
        is_redo_undo_opt_ = true;
        auto redo_top = redo_stack_.pop();
        undo_stack_.append(redo_top);
        /// cur_table_data = undo_stack_.pop();
        if (undo_stack_.empty()) {
            updta_table(QVariantList());
        } else {
            updta_table(undo_stack_.top());
        }
        is_redo_undo_opt_ = false;
    }
}

void UndoTableWidget::updta_table(QVariantList cur_data_list) {
    int count = this->rowCount();
    for (int i = 0; i < count; i++) {
        this->removeRow(0);
    }

    auto add_item = [&](int row, int col, QString text) {
        QTableWidgetItem* item = new QTableWidgetItem();
        //item->setFlags(item->flags() & ~Qt::ItemIsEditable);
        item->setText(text);
        item->setTextAlignment(Qt::AlignCenter);
        this->setItem(row, col, item);
    };

    for (int i = 0; i < cur_data_list.size(); i++) {
        QVariantMap ques_list = cur_data_list[i].toMap();
        this->insertRow(i);
        this->setRowHeight(i, 40);
        for (int j = 0; j < ques_list.size(); j++) {
            add_item(i, j, ques_list[QString::number(j)].toString());
        }
    }
}

void UndoTableWidget::createActions() {
    // this->setContextMenuPolicy(Qt::CustomContextMenu);
    table_menu_ = new QMenu(this);
    item_undo = table_menu_->addAction(tr("撤销(&Z)"));
    connect(item_undo, &QAction::triggered, this, &UndoTableWidget::undo_opera);
    //item_undo->setShortcut(Qt::CTRL + Qt::Key_Z);

    item_redo = table_menu_->addAction(tr("恢复(&Y)"));
    connect(item_redo, &QAction::triggered, this, &UndoTableWidget::redo_opera);
    //item_redo->setShortcut(Qt::CTRL + Qt::Key_Y);

    QShortcut* key_undo = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z), this);
    connect(key_undo, &QShortcut::activated, [&]() {
        undo_opera();
    });
    QShortcut* key_redo = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Y), this);
    connect(key_redo, &QShortcut::activated, [&]() {
        redo_opera();
    });
    //this->installEventFilter(this);

    //右键菜单展开和关闭
    QObject::connect(this, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showtablerightMenu(QPoint)));

}

void UndoTableWidget::showtablerightMenu(QPoint point) {
    if (undo_stack_.isEmpty()) {
        item_undo->setEnabled(false);
    } else {
        item_undo->setEnabled(true);
    }
    if (redo_stack_.isEmpty()) {
        item_redo->setEnabled(false);
    } else {
        item_redo->setEnabled(true);
    }
    QPoint pos = this->viewport()->mapToGlobal(point);
    auto item_pos = this->viewport()->mapToParent(point);
    //QTableWidgetItem* item = this->itemAt(item_pos);
    //if (item)
    {
        table_menu_->exec(pos);
    }
}

int get_stack(QStack <int>& s, int position) {
    int top_num = s.top();
    s.pop();
    if (s.size() == position)
        return top_num;
    else {
        int result = get_stack(s, position);
        s.push(top_num);
        return result;
    }
}

void UndoTableWidget::slotUpdate(QTableWidgetItem* item) {
    QStack<int >a;
    a.push(4);
    a.push(3);
    a.push(2);
    a.push(1);
    int n = 0;
    int b = get_stack(a, n);

    auto sig_sender = sender();
    if (!is_redo_undo_opt_) {
        data_record();
        redo_stack_.clear();
    } else {
    }
}


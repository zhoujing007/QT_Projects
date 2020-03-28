#pragma once
#include <QTableWidget>
#include <QtWidgets/QWidget>
#include <QStack>
#include <QMenu>

class UndoTableWidget :  public QTableWidget {
    Q_OBJECT
public:
    UndoTableWidget(QWidget* parent);
    ~UndoTableWidget();
    QVariantList data_record();
private:

    QStack <QVariantList> undo_stack_;
    QStack <QVariantList> redo_stack_;
    QMenu* table_menu_;

    bool first_opera_ = false;
    QVariantList cur_table_data;
    bool is_redo_undo_opt_ = false;
    QAction* item_undo;
    QAction* item_redo;


private:

    void undo_opera();
    void redo_opera();

    void updta_table(QVariantList cur_data);

    void createActions();

    //键盘事件

private slots:
    /*
    * @brief:   showtablerightMenu：右键菜单响应函数
    * @param:   QPoint point
    * @return:  void
    */
    void showtablerightMenu(QPoint point);

    void slotUpdate(QTableWidgetItem* item);



};


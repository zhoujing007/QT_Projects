#ifndef QUESTIONLISTDELEGATE_H
#define QUESTIONLISTDELEGATE_H

#include <QStyledItemDelegate>
#include <QItemDelegate>
#include <QModelIndex>
#include <QPainter>
#include <QWidget>


class questionlistdelegate : public QItemDelegate
{
    Q_OBJECT

public:
    questionlistdelegate(QObject *parent = nullptr);
    ~questionlistdelegate();

    void paint(QPainter *painter, const QStyleOptionViewItem &option,
                    const QModelIndex &index) const;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                                        const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                                    const QModelIndex &index) const;

private:

};

#endif // QUESTIONLISTDELEGATE_H

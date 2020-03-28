#include "questionlistdelegate.h"
#include <QComboBox>

questionlistdelegate::questionlistdelegate(QObject* parent)
    : QItemDelegate(parent) {

}

questionlistdelegate::~questionlistdelegate() {

}
void questionlistdelegate::paint(QPainter* painter, const QStyleOptionViewItem& option,
                                 const QModelIndex& index) const {
    QItemDelegate::paint(painter, option, index);
}

QSize questionlistdelegate::sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const {
    return QItemDelegate::sizeHint(option, index);
}

QWidget* questionlistdelegate::createEditor(QWidget* parent, const QStyleOptionViewItem& option,
        const QModelIndex& index) const {


    if (index.isValid() && index.column() == 1) {
        QComboBox* editor = new QComboBox(parent);
        editor->setEditable(true);
        //editor->installEventFilter(const_cast<Delegate *>(this));
        return editor;
    } else {
        return QItemDelegate::createEditor(parent, option, index);
    }
}

void questionlistdelegate::setEditorData(QWidget* editor, const QModelIndex& index) const {
    if (index.isValid() && index.column() == 1) {
        QString value = index.model()->data(index, Qt::DisplayRole).toString();
        QComboBox* combox = static_cast<QComboBox*>(editor);
        combox->addItem("+");
        combox->addItem("+2");
        combox->addItem("+3");
        combox->addItem("+4");
        combox->setCurrentText(value);
    } else {
        QItemDelegate::setEditorData(editor, index);
    }
}

void questionlistdelegate::setModelData(QWidget* editor, QAbstractItemModel* model,
                                        const QModelIndex& index) const {
    if (index.isValid() && index.column() == 1) {
        QComboBox* combox = static_cast<QComboBox*>(editor);
        model->setData(index, combox->currentText());
    } else {
        QItemDelegate::setModelData(editor, model, index);
    }
}

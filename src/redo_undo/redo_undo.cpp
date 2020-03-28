#include "redo_undo.h"
#include "questionlistdelegate.h"

redo_undo::redo_undo(QWidget* parent)
    : QWidget(parent) {
    ui.setupUi(this);
    m_document = new QString;
    m_stack = new QUndoStack(this);
    ui.tableWidget->setItemDelegateForColumn(1, new questionlistdelegate());//Ìí¼ÓQCombox´úÀí
}

void redo_undo::save_data() {
    //ui.tableWidget->undo_record();
}

